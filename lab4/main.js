function LED_state(){
    var LED = ["off","off","off","off"];
    var l = [];
    l[0] = document.getElementById('LED1').checked;
    l[1] = document.getElementById('LED2').checked;
    l[2] = document.getElementById('LED3').checked;
    l[3] = document.getElementById('LED4').checked;

    for (var i=1;i<4;i++){
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
    document.getElementById("state").innerHTML = '';
    for (var i=0;i<4;i++){
        document.getElementById("state").innerHTML += "LED" + (i+1) + ":" + LED[i] + "<br>";
    }

    var send = {
        "LED1" : LED[0],
        "LED2" : LED[1],
        "LED3" : LED[2],
        "LED4" : LED[3],
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