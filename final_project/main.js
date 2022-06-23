var d = false;
var m;
var timeoutID = setTimeout(LongTime, 10000);
clearTimeout(timeoutID);
function LongTime() {
    console.log('時間長達10分鐘，轉為自動偵測!');
    document.getElementById("DETECT").checked = true;
    document.getElementById("NODETECT").checked = false;
    document.getElementById("ctrl").style.display = "none";
    document.getElementById("ctrl2").style.display = "none";
    document.getElementById("state").style.display = "block";
    document.getElementById("choose").style.display = "none";
    d = true;
    var templateParams = {
        MODE_CHINESE : "偵測模式",
        reason : "手動時間長達2分鐘，所以",
        MODE : "detect"
    };
    emailjs.send('service_40f0im5', 'template_15470e6', templateParams)
    .then(function(response) {
       console.log('SUCCESS!', response.status, response.text);
    }, function(error) {
       console.log('FAILED...', error);
    });
    // var send = {
    //     "detect" : m
    // }
    // fetch("/control",{
    //     body : JSON.stringify(send),
    //     cache : 'no-cache',
    //     credentials : 'same-origin',
    //     headers : {
    //         'user-agent': 'Mozilla/4.0 MDN Example',
    //         'content-type': 'application/json'
    //     },
    //     method : 'POST',
    //     mode : 'cors',
    //     redirect : 'follow',
    //     referrer : 'no-referrer'
    // }).then(response => response.json())
    clearTimeout(timeoutID);
}
function LED_state(){
    var LED = ["off","off"];
    var l = [];
    l[0] = document.getElementById('LED1').checked;
    l[1] = document.getElementById('LED2').checked;

    for (var i=0;i<2;i++){
        if (document.getElementById('on').checked){
            if (l[i]){
                LED[i] = "on";
            }
        }
        else{
            if(l[i]){
                LED[i] = "off";
            }
        }
    }
    document.getElementById("led_state").innerHTML = '';
    for (var i=0;i<2;i++){
        document.getElementById("led_state").innerHTML += "LED" + (i+1) + ":" + LED[i] + "<br>";
    }

    var send = {
        "LED1" : LED[0],
        "LED2" : LED[1],
        "shine" : -1
    }
    fetch("/control",{
        body : JSON.stringify(send),
        cache : 'no-cache',
        credentials : 'same-origin',
        headers : {
            'user-agent': 'Mozilla/4.0 MDN Example',
            'content-type': 'application/json'
        },
        method : 'POST',
        mode : 'cors',
        redirect : 'follow',
        referrer : 'no-referrer'
    }).then(response => response.json())
}

function shine(){
    var t = document.getElementById('sh').value;
    document.getElementById('shine_state').innerHTML = "Mode_Shine_Time:" + t;
    var send = {
        "shine" : t
    }
    fetch("/control",{
        body : JSON.stringify(send),
        cache : 'no-cache',
        credentials : 'same-origin',
        headers : {
            'user-agent': 'Mozilla/4.0 MDN Example',
            'content-type': 'application/json'
        },
        method : 'POST',
        mode : 'cors',
        redirect : 'follow',
        referrer : 'no-referrer'
    }).then(response => response.json())
}

function mutex(){
    var t = document.getElementById('sh').value;
    var send = {
        "shine" : t,
        "mode" : "mutex"
    }
    fetch("/control",{
        body : JSON.stringify(send),
        cache : 'no-cache',
        credentials : 'same-origin',
        headers : {
            'user-agent': 'Mozilla/4.0 MDN Example',
            'content-type': 'application/json'
        },
        method : 'POST',
        mode : 'cors',
        redirect : 'follow',
        referrer : 'no-referrer'
    }).then(response => response.json())
}
function sema(){
    var t = document.getElementById('sh').value;
    var send = {
        "shine" : t,
        "mode" : "sema"
    }
    fetch("/control",{
        body : JSON.stringify(send),
        cache : 'no-cache',
        credentials : 'same-origin',
        headers : {
            'user-agent': 'Mozilla/4.0 MDN Example',
            'content-type': 'application/json'
        },
        method : 'POST',
        mode : 'cors',
        redirect : 'follow',
        referrer : 'no-referrer'
    }).then(response => response.json())
}

function choose(){
    d = document.getElementById("DETECT").checked;
    var nd = document.getElementById("NODETECT").checked;
    if (d && !nd){
        document.getElementById("ctrl").style.display = "none";
        document.getElementById("ctrl2").style.display = "none";
        document.getElementById("state").style.display = "block";
        document.getElementById("choose").style.display = "none";
    }
    else if (!d && nd){
        document.getElementById("ctrl").style.display = "block";
        document.getElementById("ctrl2").style.display = "block";
        document.getElementById("choose").style.display = "none";
        document.getElementById("state").style.display = "none";
    }
    else if (!nd && !d){
        document.getElementById("choose").style.display = "block";
        document.getElementById("ctrl").style.display = "none";
        document.getElementById("ctrl2").style.display = "none";
        document.getElementById("state").style.display = "none";
    }
    else {
        document.getElementById("choose").style.display = "block";
        document.getElementById("ctrl").style.display = "none";
        document.getElementById("ctrl2").style.display = "none";
        document.getElementById("state").style.display = "none";
    }
    var mode_ch;
    var real_change = 0;
    if (d && !nd){
        clearTimeout(timeoutID);
        m = "detect";
        mode_ch = "偵測模式";
        real_change = 1;
    }
    else if (!d && nd){
        timeoutID = setTimeout(LongTime, 120000);
        m = "no_detect";
        mode_ch = "手動模式";
        real_change = 1;
    }
    var templateParams = {
        MODE_CHINESE : mode_ch,
        MODE : m
    };
    emailjs.send('service_40f0im5', 'template_15470e6', templateParams)
    .then(function(response) {
       console.log('SUCCESS!', response.status, response.text);
    }, function(error) {
       console.log('FAILED...', error);
    });
    // var send = {
    //     "shine" : -2,
    //     "detect" : m
    // }
    // fetch("/control",{
    //     body : JSON.stringify(send),
    //     cache : 'no-cache',
    //     credentials : 'same-origin',
    //     headers : {
    //         'user-agent': 'Mozilla/4.0 MDN Example',
    //         'content-type': 'application/json'
    //     },
    //     method : 'POST',
    //     mode : 'cors',
    //     redirect : 'follow',
    //     referrer : 'no-referrer'
    // }).then(response => response.json())
}
var adc_condition;
function data(){
    if(d){
        fetch("/get",{
        cache: 'no-cache', 
        credentials: 'same-origin',
        headers: {
          'user-agent': 'Mozilla/4.0 MDN Example',
        },
        method: 'GET', 
        mode: 'cors',
        redirect: 'follow',
        referrer: 'no-referrer',
      })
        .then(res => {
            return res.json();
        })
        .then(result => {
            document.getElementById("adc_value").innerHTML=`亮度 = ${result["adc_value"]}`
            adc_condition = `${result["adc_value"]}`;
        });
    }
}
function adc_scan(){
    console.log(adc_condition);
    if(adc_condition < 200){
        document.getElementById("adc_scan").innerHTML=`白天模式`
    }
    else if(adc_condition > 900){
        document.getElementById("adc_scan").innerHTML=`夜晚模式`        
    }
    else{
        document.getElementById("adc_scan").innerHTML=`傍晚模式`
    }
}
setInterval(adc_scan,250);
setInterval(data,500);