function check()
{
    if (document.getElementById("searcher").value.length==0)
    {
        alert("Please fill the empty field!");
    }
    else{
        document.getElementById("searchForm").action="https://www.google.com/search";
    }
}
