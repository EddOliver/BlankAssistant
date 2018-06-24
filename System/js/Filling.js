function fill()
{
var cama = ["", "Cama 2", "Baño 3","Regadera 3","Baño 13","Cama 23"];
var text = "";
var i;
for (i = 0; i < cama.length; i++)
{
text += cama[i] + "<br>";
}
return "Cama 2<br>Baño 3<br>Regadera 3<br>Baño 13<br>Cama 23<br>";
}

function Addvalue(var value) {
var cama = ["", "Cama 2", "Baño 3","Regadera 3","Baño 13","Cama 23"];
var text = "";
var i;
cama.push(value);
for (i = 0; i < cama.length; i++)
{
text += cama[i] + "<br>";
}
return text;
}
