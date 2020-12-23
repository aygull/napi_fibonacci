const express = require("express");
const fibonacci = require('../build/Release/testaddon.node');
// создаем объект приложения
const app = express();
let path = require('path');
app.use("/static", express.static(__dirname));
app.get("/", function(request, response){
    response.sendFile(path.join(__dirname, 'index.html'));
});

app.get('/fibonacci', (request, response) => {
    let value = 0;
    if (request.query.value) {
        value = +request.query.value;
        if (isNaN(value)) {
            value = 0;
        }
    }
    const number = fibonacci.get(value);
    response.send(number.toString());
});

// начинаем прослушивать подключения на 3000 порту
app.listen(3000);

