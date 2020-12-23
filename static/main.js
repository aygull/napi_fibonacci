let value = 0;

function myFunction() {
    let xhr = new XMLHttpRequest();
    const url = window.location;
    xhr.open('GET', url + `fibonacci?value=${value}`, false);
    xhr.send( null );

    value++;

    document.getElementById("demo").innerHTML = xhr.responseText;
}
