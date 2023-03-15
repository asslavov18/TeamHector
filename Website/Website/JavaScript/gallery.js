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

function myFunction() {
    var fishtypes = ["bluediscuss", "yellowdiscuss", "royalgamma", "blackmolly", "kissinggourami", "purpletang", "yellowtang", "chromisblue", "anthias", "clownfish"];
    var fishcolor = ["yellow", "purple", "blue", "orange", "black", "colorful"];
    var fishwater = ["saltwater", "salt", "fresh", "freshwater"];
    var deafaultbg = "white";
    var checker = false;
    var finder = document.getElementById("gallerySearch").value;
    finder = finder.split(" ").join("");
    var finder = finder.toLowerCase();

    for (var i = 0; i < 10; i++) {
        if (finder == fishtypes[i]) {
            for (var j = 0; j < 10; j++) {
                document.getElementById(fishtypes[j]).style.backgroundColor = deafaultbg;
            }
            document.getElementById(fishtypes[i]).style.backgroundColor = 'red';
            checker = true;
        }
    }

    for (var i = 0; i < 6; i++) {
        if (finder == fishcolor[i]) {
            for (var j = 0; j < 10; j++) {
                document.getElementById(fishtypes[j]).style.backgroundColor = 'white';
            }
            if (i == 0) {
                document.getElementById("yellowdiscuss").style.backgroundColor = fishcolor[i];
                document.getElementById("yellowtang").style.backgroundColor = fishcolor[i];
            }
            if (i == 1) {
                document.getElementById("royalgamma").style.backgroundColor = fishcolor[i];
                document.getElementById("purpletang").style.backgroundColor = fishcolor[i];
            }
            if (i == 2) {
                document.getElementById("bluediscuss").style.backgroundColor = fishcolor[i];
                document.getElementById("chromisblue").style.backgroundColor = fishcolor[i];
            }
            if (i == 3) {
                document.getElementById("kissinggourami").style.backgroundColor = fishcolor[i];
                document.getElementById("clownfish").style.backgroundColor = fishcolor[i];
            }
            if (i == 4) {
                document.getElementById("blackmolly").style.backgroundColor = fishcolor[i];
            }
            if (i == 5) {
                document.getElementById("anthias").style.backgroundColor = 'pink';
            }
            checker = true;
        }
    }


    if (finder == fishwater[2] || finder == fishwater[3]) {
        for (var j = 0; j < 10; j++) {
            document.getElementById(fishtypes[j]).style.backgroundColor = deafaultbg;
        }
        for (var i = 0; i < 5; i++) {
            document.getElementById(fishtypes[i]).style.backgroundColor = 'blue';
        }
        checker = true;
    }

    if (finder == fishwater[0] || finder == fishwater[1]) {
        for (var j = 0; j < 10; j++) {
            document.getElementById(fishtypes[j]).style.backgroundColor = deafaultbg;
        }
        for (var i = 5; i < 10; i++) {
            document.getElementById(fishtypes[i]).style.backgroundColor = 'blue';
        }
        checker = true;
    }



    if (checker == false) {
        for (var j = 0; j < 10; j++) {
            document.getElementById(fishtypes[j]).style.backgroundColor = 'white';
        }
    }

}