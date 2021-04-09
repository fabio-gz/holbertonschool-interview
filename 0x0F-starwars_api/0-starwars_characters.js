#!/usr/bin/node
const request = require('request');
const id = process.argv[2];

const sw = {
    url: 'https://swapi-api.hbtn.io/api/films/' + `${id}` + '/',
    headers: {
      'User-Agent': 'request'
    }
};

retrieve();

function retrieve() {
    request(sw, async (err, response, body) => {
      if (!err) {
        for (const c of JSON.parse(body).characters) {
          await chars(c);
        }
      } else {
        console.log(err);
      }
    });
}

function chars (people) {
  return new Promise((resolve, reject) => {
    request(people, (err, response, body) => {
      if (!err) {
        console.log(JSON.parse(body).name);
        resolve();
      } else {
        reject(err);
      }
    });
  });
}
