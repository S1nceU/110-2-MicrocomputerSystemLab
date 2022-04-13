const express = require("express");
const app = express();

app.use(express.json());

app.get("/",(req,res)=>{
    const dir = __dirname;
    res.sendFile('./index.htm',{root: dir});
})
app.get("/main.js",(req,res) => {
    const dir = __dirname;
    res.sendFile('./main.js', {root: dir});
})

function LEDshine(LED, power){
    let pro = require("child_process");
    let process = pro.execFile('sudo', ['./tx2', LED, power]);
    process.stdout.on('data', (data) => {
        console.log(`stdout: ${data}`);
    });
    process.stderr.on('data', (data) => {
        console.log(`stderr: ${data}`);
    });
}

app.post("/control",(req,res) => {
    var get_data = req.body;
    if(get_data["shine"] == -1){
        LEDshine("LED1", get_data["LED1"]);
        LEDshine("LED2", get_data["LED2"]);
        LEDshine("LED3", get_data["LED3"]);
        LEDshine("LED4", get_data["LED4"]);
    }else{
        for(var i = 0; i < get_data["shine"] * 2; i++){
            if(i % 2 == 0){
                LEDshine("LED1", "1");
                LEDshine("LED2", "1");
                LEDshine("LED3", "0");
                LEDshine("LED4", "0");
            }else{
                LEDshine("LED1", "0");
                LEDshine("LED2", "0");
                LEDshine("LED3", "1");
                LEDshine("LED4", "1");
            }
            let ChildProcess_ExecSync = require('child_process').execSync;
            ChildProcess_ExecSync('sleep ' + 1);
        }
    }
    
})

const PORT = process.env.PORT || 8080;
app.listen(PORT, () => {
    console.log("Server is running!!");
})
