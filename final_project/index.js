const express = require("express");
const app = express();

var temp = "";

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
    let process = pro.execFile('sudo', ['./lab2', LED, power]);
    process.stdout.on('data', (data) => {
        console.log(`stdout: ${data}`);
    });
    process.stderr.on('data', (data) => {
        console.log(`stderr: ${data}`);
    });
}

function LEDshine_semaphore(LED, times){
    let pro = require("child_process");
    let process = pro.execFile('sudo', ['./semaphore', LED, times]);
    process.stdout.on('data', (data) => {
        console.log(`stdout: ${data}`);
    });
    process.stderr.on('data', (data) => {
        console.log(`stderr: ${data}`);
    });
}
function LEDshine_mutex(LED, times){
    let pro = require("child_process");
    let process = pro.execFile('sudo', ['./mutex', LED, times]);
    process.stdout.on('data', (data) => {
        console.log(`stdout: ${data}`);
    });
    process.stderr.on('data', (data) => {
        console.log(`stderr: ${data}`);
    });
}
// function sendmail(mode){
//     let child_process = require("child_process");

//     let process = child_process.execFile('sudo', ['python3','emaila.py',mode]);
//     process.stdout.on('data', function(data)  {
//         console.log(`stdout: ${data}`);
//     });
//     process.stderr.on('data', (data) => {
//         console.log(`stderr: ${data}`);
//     });
// }

app.post("/control",(req,res) => {
    var get_data = req.body;
    if(get_data["shine"] == -1){
        LEDshine("LED1", get_data["LED1"]);
        LEDshine("LED2", get_data["LED2"]);
    }
    // else if (get_data["shine"] == -2){
    //     sendmail(get_data["detect"]);
    // }
    else{
        if(get_data["mode"] == "sema"){
            LEDshine_semaphore(10,get_data["shine"]);
        }
        else if (get_data["mode"] == "mutex"){
            LEDshine_mutex(10,get_data["shine"]);
        }
        // for(var i = 0; i < get_data["shine"] * 2; i++){
        //     if(i % 2 == 0){
        //         LEDshine("LED1", "on");
        //         LEDshine("LED2", "off");
        //     }else{
        //         LEDshine("LED1", "off");
        //         LEDshine("LED2", "on");
        //     }
        //     let ChildProcess_ExecSync = require('child_process').execSync;
        //     ChildProcess_ExecSync('sleep ' + 1);
        // }
    }
})


async function adc_value(){
    let child_process = await require("child_process");

    let process = await child_process.execFile('sudo', ['python3','lab5.py']);
    await process.stdout.on('data', function(data)  {
    	temp = data;
    });
    await process.stderr.on('data', (data) => {
        console.log(`stderr: ${data}`);
    });
}

app.get("/get",async(req,res) => {
    await adc_value();
    console.log(temp);
    res.set('Content-Type', 'appication/json');
    res.status(200).json({adc_value: temp}); 
 })

const PORT = process.env.PORT || 8080;
app.listen(PORT, () => {
    console.log("Server is running!!");
})
