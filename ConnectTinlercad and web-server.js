const elm = document.querySelector('.js-code_panel__serial__text');
let s0 ='';
setInterval( function(){ 
  let rws = elm.innerText.split('\r\n'); 
  var s = rws[rws.length - 2]; 
  if(s!=s0 && s>'1 ') {console.log(s); s0 = s;
  fetch('http://kckc/index.php?xx=' + s)
  } 
 } ,100);