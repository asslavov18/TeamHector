function check() {
    if (document.getElementById("searcher").value.length == 0) {
        alert("Please fill the empty field!");
    } else {
        document.getElementById("searchForm").action = "https://www.google.com/search";
    }
}

function check() {
    if (document.getElementById("searcher").value.length == 0) {
        alert("Please fill the empty field!");
    } else if (changer == 1) {
        img.src = "../img/ydiscuss3.jpg";
        changer = 2;
    } else {
        document.getElementById("searchForm").action = "https://www.google.com/search";
    }
}

var img;
var changer = 0;

function changeYellowDiscuss() {
    img = document.getElementById("d1c1");
    if (changer == 0) {
        img.src = "../img/ydiscuss1.jpg";
        changer = 1;
    } else if (changer == 1) {
        img.src = "../img/ydiscuss3.jpg";
        changer = 2;
    } else {
        img.src = "../img/ydiscuss2.jpg";
        changer = 0;
    }


}

function changeBlueDiscuss() {
    img = document.getElementById("d1c2");
    if (changer == 0) {
        img.src = "../img/discuss2.jpg";
        changer = 1;
    } else if (changer == 1) {
        img.src = "../img/discuss3.jpg";
        changer = 2;
    } else {
        img.src = "../img/disscus1.jpg ";
        changer = 0;
    }

}

function changeKissingGourami() {
    img = document.getElementById("d1c3");
    if (changer == 0) {
        img.src = "../img/kiss2.jpg";
        changer = 1;
    } else if (changer == 1) {
        img.src = "../img/kiss3.jpg";
        changer = 2;
    } else {
        img.src = "../img/kiss1.jpg";
        changer = 0;
    }

}

function changeBlackMolly() {
    img = document.getElementById("d1c4");
    if (changer == 0) {
        img.src = "../img/bmolly2.jpg";
        changer = 1;
    } else if (changer == 1) {
        img.src = "../img/bmolly3.jpg";
        changer = 2;
    } else {
        img.src = "../img/bmolly1.jpg";
        changer = 0;
    }

}

function changeRoyalGammaPurple() {
    img = document.getElementById("d1c5");
    if (changer == 0) {
        img.src = "../img/rgp2.jpg";
        changer = 1;
    } else if (changer == 1) {
        img.src = "../img/rgp3.jpg";
        changer = 2;
    } else {
        img.src = "../img/rgp1.jpg";
        changer = 0;
    }

}

function changePurpleTang() {
    img = document.getElementById("d2c1");
    if (changer == 0) {
        img.src = "../img/ptang2.jpg";
        changer = 1;
    } else if (changer == 1) {
        img.src = "../img/ptang3.jpg";
        changer = 2;
    } else {
        img.src = "../img/ptang1.jpg";
        changer = 0;
    }

}

function changeChromisBlue() {
    img = document.getElementById("d2c2");
    if (changer == 0) {
        img.src = "../img/cbfish2.jpg";
        changer = 1;
    } else if (changer == 1) {
        img.src = "../img/cbfish3.jpg";
        changer = 2;
    } else {
        img.src = "../img/cbfish1.jpg";
        changer = 0;
    }


}

function changeYellowTang() {
    img = document.getElementById("d2c3");
    if (changer == 0) {
        img.src = "../img/tang2.jpg";
        changer = 1;
    } else if (changer == 1) {
        img.src = "../img/tang3.jpg";
        changer = 2;
    } else {
        img.src = "../img/tang1.jpg";
        changer = 0;
    }


}

function changeAnthiasColorful() {
    img = document.getElementById("d2c4");
    if (changer == 0) {
        img.src = "../img/anthias2.jpg";
        changer = 1;
    } else if (changer == 1) {
        img.src = "../img/anthias3.jpg";
        changer = 2;
    } else {
        img.src = "../img/anthias1.jpg";
        changer = 0;
    }

}

function changeClownFish() {
    img = document.getElementById("d2c5");
    if (changer == 0) {
        img.src = "../img/clown1.jpg";
        changer = 1;
    } else if (changer == 1) {
        img.src = "../img/clown3.jpg";
        changer = 2;
    } else {
        img.src = "../img/clown2.jpg";
        changer = 0;
    }

}