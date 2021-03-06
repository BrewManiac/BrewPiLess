const char data_setup_htm[] PROGMEM =
R"END(
<html>
<head>
<meta http-equiv="content-type" content="text/html; charset=utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>BrewPi Setup</title>
<meta name="apple-mobile-web-app-title" content="BrewPi Setup">
<meta name="apple-mobile-web-app-capable" content="yes">
<script type="text/javascript" src="bwf.js"></script>
</head>
<style>button{color:#1d5987;background:#dfeffc;font-weight:bold;border-top-right-radius:5px;border-top-left-radius:5px;border-bottom-right-radius:5px;border-bottom-left-radius:5px}.corner-top{border-top-right-radius:5px;border-top-left-radius:5px}.corner-bottom{border-bottom-right-radius:5px;border-bottom-left-radius:5px}.navbar{margin:0;padding:.2em .2em 0;border:1px solid #4297d7;background:#5c9ccc;color:#fff;height:2em;display:block;position:relative}.bar-title{margin-right:160px;font-weight:bold}.device-container{border:1px solid;padding:5px}.device-setting-container{padding:5px;width:150px;float:left;color:#555}.device-titleNapply{float:left;padding:5px}.setting-name{font-weight:bold;display:block}.device-detail{float:left}.device-title{display:block;white-space:nowrap;float:left;clear:both;font-size:1.2em;color:#306fa9}#installed-device,#detected-device{font-weight:bold;font-size:18px;padding:.5em}.modal{display:none;position:fixed;z-index:1;padding-top:100px;left:0;top:0;width:100%;height:100%;overflow:auto;background-color:#000;background-color:rgba(0,0,0,0.4)}.modal-content{background-color:#fefefe;margin:auto;padding:20px;border:1px solid #888;width:80%}</style>
<script>/*<![CDATA[*/var BackupFile="/device.cfg";var devices={add:function(a,f){var g=document.createElement("div");g.innerHTML="<div class='device-container'>	<table>	<tr><td ROWSPAN=2>	<div class='device-title'></div><br><button>apply</button></td>	<td><div class='device-setting-container'><span class='setting-name'>Device slot</span>		<select class='slot-select'>		<option value='-1'>Unassigned</option>		<option value='0'>0</option>		<option value='1'>1</option>		<option value='2'>2</option>		<option value='3'>3</option>		<option value='4'>4</option>		<option value='5'>5</option>		<option value='6'>6</option>		<option value='7'>7</option>		<option value='8'>8</option>		<option value='9'>9</option>		<option value='10'>10</option>		<option value='11'>11</option>		<option value='12'>12</option>		<option value='13'>13</option>		<option value='14'>14</option>		<option value='15'>15</option>		</select></div></td>		<td><div class='device-setting-container'>		<span class='setting-name'>Hardware Type</span>		<span class='setting-value device-type'></span>		</div></td>		<td><div class='device-setting-container device-address-container'>		<span class='setting-name'>Address</span>		<span class='setting-value device-address'></span>		</div>		<div class='device-setting-container device-pintype-container'>		<span class='setting-name'>Pin type</span>		<select class='setting-value device-pintype'>		<option value=0>Not Inverted</option>		<option value=1>Inverted</option>		</select>		</div></td></tr>		<tr><td><div class='device-setting-container'>		<span class='setting-name'>Controller PIN</span>		<span class='setting-value device-pin'></span>		</div></td>		<td><div class='device-setting-container'>		<span class='setting-name'>Value</span>		<span class='setting-value device-value'></span>		</div></td>		<td><div class='device-setting-container'>		<span class='setting-name'>Function</span>		<select class='setting-value device-function'></select>		</div></td>	</tr></table></div>";if(f.h==2){g.querySelector("div.device-pintype-container").style.display="none";g.querySelector("select.device-function").innerHTML="<option value=0>None</option><option value=5>Chamber Temp</option><option value=6>Room Temp</option><option value=9>Beer Temp</option>";g.querySelector("span.device-type").innerHTML="Sensor";g.querySelector("span.device-address").innerHTML=f.a;g.querySelector("span.device-value").innerHTML=(typeof f.v==="undefined")?"-":f.v}else{g.querySelector("div.device-address-container").style.display="none";g.querySelector("select.device-function").innerHTML="<option value=0>None</option><option value=1>Chamber Door</option><option value=2>Chamber Heater</option><option value=3>Chamber Cooler</option><option value=4>Chamber Light</option><option value=7>Chamber Fan</option>";g.querySelector("span.device-type").innerHTML="None";g.querySelector("select.device-pintype").value=f.x;g.querySelector("span.device-value").innerHTML=(typeof f.v==="undefined")?"-":((f.v)?"active":"inactive")}g.querySelector("select.slot-select").value=f.i;var c={0:"D3",1:"D10",2:"D4",3:"D9",4:"D2",5:"D1",12:"D6",13:"D7",14:"D5",15:"D8",16:"D0",17:"A0"};g.querySelector("span.device-pin").innerHTML=c[f.p];g.querySelector("select.device-function").value=f.f;g.querySelector("div.device-title").innerHTML="Device "+a;g.querySelector("button").onclick=function(){device_apply(a)};g.hardwaretype=f.h;g.pinnumber=f.p;var b=(f.i<0)?"detected-list":"installed-list";var e=document.getElementById(b);e.appendChild(g);e.appendChild(document.createElement("br"))}};var installed_list=[];var available_list=[];function cmdfrom(b){var a;if(b<installed_list.length){a=installed_list[b]}else{a=available_list[b-installed_list.length]}var d=document.querySelectorAll("div.device-container")[b];var c={};c.i=d.querySelector("select.slot-select").value;c.c=1;c.f=d.querySelector("select.device-function").value;if(c.f>=9&&c.f<=15){c.b=1}else{c.b=0}c.h=a.h;c.p=a.p;if(c.h==2){c.a=a.a}else{c.x=d.querySelector("select.device-pintype").value}return c}function device_apply(a){blockscreen("Updating....");var b=cmdfrom(a);var c="U"+JSON.stringify(b);console.log(c);BWF.on("U",function(d){unblockscreen()});BWF.send(c)}function backup(){if(installed_list.length==0){alert("No installed devices!");return}var c=[];for(var a=0;a<installed_list.length;a++){var f=installed_list[a];var e={i:f.i,c:f.c,b:f.b,f:f.f,h:f.h,p:f.p};if(f.h==2){e.a=f.a}else{e.x=f.x}c.push(e)}var b=JSON.stringify(c);console.log(b);BWF.save(BackupFile,b,function(){alert("done")},function(d){alert("error saving:"+d)})}function restore(){blockscreen("restoring...");BWF.load(BackupFile,function(c){var b=JSON.parse(c);var a=0;BWF.on("U",function(d){if(++a>=b.length){BWF.on("U",null);unblockscreen();return}BWF.send("U"+JSON.stringify(b[a]))});BWF.send("U"+JSON.stringify(b[a]))},function(a){alert("error load:"+a);unblockscreen()})}function list(){blockscreen("Retrieving...");installed_list=[];available_list=[];document.getElementById("detected-list").innerHTML="";document.getElementById("installed-list").innerHTML="";BWF.send("d{r:1}");BWF.send("h{u:-1,v:1}")}function erase(){BWF.send("E")}function listGot(){document.getElementById("detected-list").innerHTML="";document.getElementById("installed-list").innerHTML="";var a=0;for(var b=0;b<installed_list.length;b++){devices.add(a++,installed_list[b])}for(var b=0;b<available_list.length;b++){devices.add(a++,available_list[b])}unblockscreen()}function init(){BWF.init({error:function(a){alert("error communication between server")},handlers:{d:function(a){installed_list=a},h:function(a){available_list=a;listGot()}}})}function blockscreen(a){document.getElementById("blockscreencontent").innerHTML=a;document.getElementById("blockscreen").style.display="block"}function unblockscreen(){document.getElementById("blockscreen").style.display="none"};/*]]>*/</script>
<body onload=init()>
<div class="navbar corner-top corner-bottom">
<span class="bar-title">Device List</span>
<button onclick=backup()>Backup</button>
<button onclick=restore()>Restore</button>
<button onclick=erase()>Erase EEPROM</button>
<button onclick=list()>Refresh Device List</button>
</div>
<div id="device-list">
<div id="installed-device">Installed Device</div>
<div id="installed-list"></div>
<div id="detected-device">Detected Device</div>
<div id="detected-list"></div>
</div>
<div id="blockscreen" class="modal">
<div id="blockscreencontent" class="modal-content">
</div>
</div>
</body>
</html>
)END";


















































