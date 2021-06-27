//Data storing into localstorage
function validateForm() {

    let data = localStorage.getItem('details') ? JSON.parse(localStorage.getItem('details')) : [];;
    let formData = {
        "name": document.getElementById("name").value,
        "email": document.getElementById("email").value,
        "password": document.getElementById("pass1").value,
        "confirmpassword": document.getElementById("pass2").value
    }
    data.push(formData);
    if (localStorage) {
        localStorage.setItem("details", JSON.stringify(data));
    }
}
//Check if password is matching
function verifyPassword(input) {
    if (input.value != document.getElementById("pass1").value) {
        input.setCustomValidity("Password Must be Matching");
    } else {
        input.setCustomValidity("");
    }
}
//check already registered users
function emailExist(value) {
    let existemail = JSON.parse(localStorage.getItem("details"));

    let emailid = existemail.map((email, i, existemail) => {
        return existemail[i].email;
    });

    let getexistemail = emailid.filter((email) => {
        if (email == value.value) {
            value.setCustomValidity('email exist. try something else');

        } else {
            value.setCustomValidity("");
        }
    });
}
//Handling bubbling
const form = document.getElementById("registerForm");
form.addEventListener("submit", function(e) {
    e.preventDefault();
    form.reset();
    alert("Registration Confirmed!");
});

//Download function
function download(filename, text) {
    var element = document.createElement('a');
    element.setAttribute('href', 'data:text/plain;charset=utf-8,' + encodeURIComponent(text));
    element.setAttribute('download', filename);
  
    element.style.display = 'none';
    document.body.appendChild(element);
  
    element.click();
  
    document.body.removeChild(element);
  }

//login here
function loginUser() {

    let loginEmail = document.getElementById("email").value;
    let loginPass = document.getElementById("pass").value;
    let matchEmail = JSON.parse(localStorage.getItem("details"));
    let emailArray = [];
    let passArray = [];
    let result = matchEmail.map((email, i, matchEmail) => {

        emailArray.push(matchEmail[i].email);
        passArray.push(matchEmail[i].password);
    });

    if (emailArray.indexOf(loginEmail) > -1 && passArray.indexOf(loginPass) > -1) {
        alert("Thank you for your cooperation!");
        download("FishApplication.zip","Etc..");
        window.location = "../index.html";
    } else {
        alert("Incorrect Data!");
    }

}
const loginForm = document.getElementById("logIn");
loginForm.addEventListener("submit", function(e) {
    e.preventDefault();
});