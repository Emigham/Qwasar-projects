import express from 'express';
const app = express();
const songs = [
{title: 'Ac-cent-tchu-ate the Positive'},
    {title: 'Accidents Will Happen'},
    {title: 'Adeste Fideles'},
    {title: 'Ad-Lib Blues'},
    {title: 'An Affair to Remember (Our Love Affair)'},
    {title: "After You've Gone"},
    {title: "Ain't She Sweet"},
    {title: "Ain't Cha Ever Comin' Back?"},
    {title: 'Air For English Horn'},
    {title: 'Alice Blue Gown'},
    {title: 'All Alone'},
    {title: 'All By Myself'},
    {title: 'All I Do Is Dream of You'},
    {title: 'Accidents Will Happen'},
    {title: 'Adeste Fideles'},
    {title: 'Ad-Lib Blues'},
    {title: 'An Affair to Remember (Our Love Affair)'},
    {title: "After You've Gone"},
    {title: "Ain't She Sweet"},
    {title: "Ain't Cha Ever Comin' Back?"},
]

const birthDate = {
    "date of birth" : 'December 12, 1915'
}

const birthCity = {
    "city of birth" : 'Hoboken, New Jersey'
}

const wives = 'Nancy Barbato, Ava Gardner, Mia Farrow, Barbara Marx';

const picture = 'https://en.wikipedia.org/wiki/Frank_Sinatra#/media/File:Frank_Sinatra2,_Pal_Joey.jpg';

const login = {
    login: 'admin',
    password: 'admin'
}

app.get('/', (req, res) => {
    const randomSong = Math.floor(Math.random() * 19) + 1;
    res.send(songs[randomSong]['title'])
});

app.get('/birth_date', (req, res) => res.send(birthDate['date of birth']));

app.get('/birth_city', (req, res) => res.send(birthCity['city of birth']));

app.get('/wives', (req, res) => {
    res.send(wives)
});

app.get('/picture', (req, res) => {
    res.send(picture)
});

app.get('/protected', (req, res) => {
    if (!req.headers.authorization){
        res.status(401).json({message: "Not authorized"});
    } else if (req.headers){
        req.headers.authorization = [{username: 'admin'}, {password: 'admin'}];
        var authHeader = req.headers.authorization;
        var username = authHeader[0].username
        var password = authHeader[1].password
    
        if(username == 'admin' && password =='admin'){
            res.send("Welcome, authenticated client")
        }
    }
});

app.listen(8080, () => {
    console.log('Execise app listening on port 8080!')
});