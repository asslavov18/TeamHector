function showMore() {
    var x = "Available yet";
    document.getElementById("cardtext").innerHTML = x;
    document.getElementById("cardtext").style.color = "green";
}

function showLess() {
    var y = "Add freshwater or saltwater fishes";
    document.getElementById("cardtext").style.color = "grey";
    document.getElementById("cardtext").innerHTML = y;
}

function showMore2() {
    var x = "Non available yet";
    document.getElementById("cardtext2").innerHTML = x;
    document.getElementById("cardtext2").style.color = "red"
}

function showLess2() {
    var y = "Huge, Big, Average and Small";
    document.getElementById("cardtext2").style.color = "grey";
    document.getElementById("cardtext2").innerHTML = y;
}

function showMore3() {
    var x = "Non available yet";
    document.getElementById("cardtext3").innerHTML = x;
    document.getElementById("cardtext3").style.color = "red";
}

function showLess3() {
    var y = "Administrator can make fish data indelible";
    document.getElementById("cardtext3").style.color = "grey";
    document.getElementById("cardtext3").style.decoration = "underline";
    document.getElementById("cardtext3").innerHTML = y;
}