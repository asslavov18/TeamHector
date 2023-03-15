function hideAndShowPass() {
    let view=document.getElementById("pass1");
    if(view.type==="password")
    {
        document.getElementById("imgView1").src="../img/unview.png";
        view.type="text";
    }
    else{
        document.getElementById("imgView1").src="../img/view.png";
        view.type="password";
    }
}

function hideAndShowPassConfirm() {
    let view=document.getElementById("pass2");
    if (view.type === "password") {
        view.type = "text";
        document.getElementById("imgView2").src = "../img/unview.png";
    } else {
        view.type = "password";
        document.getElementById("imgView2").src = "../img/view.png";
    }
}