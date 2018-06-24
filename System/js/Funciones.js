function Combinada()
{
  return Promise.all([Sonido(),FuncionEmergencia()]);
}

function FuncionEmergencia()
{
var num = 15;
var n = num.toString();
alert("Cuarto "+ n +"\n¡¡Tiene una Emergencia!!");
}
function Sonido()
{
var audio = new Audio('success.mp3');
audio.play();
}
