function togglePopup() {
    document.getElementById("popup-1").classList.toggle("active");
}

function hideAndShowPass() {
    let view=document.getElementById("pass");
    if(view.type==="password")
    {
        document.getElementById("imgView").src="../img/unview.png";
        view.type="text";
    }
    else{
        document.getElementById("imgView").src="../img/view.png";
        view.type="password";
    }
}