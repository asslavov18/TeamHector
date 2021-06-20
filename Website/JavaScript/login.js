function hideAndShowPass() {
        let view = document.getElementById("pass");
        if (view.type === "password") {
            view.type = "text";
            document.getElementById("view").src = "../IMG/unview.png";
        } else {
            view.type = "password";
            document.getElementById("view").src = "../IMG/view.png";
        }
}
