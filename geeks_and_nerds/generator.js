// This will generate a lot of duplicate entries, so
// need to pass the output through the uniq unix utility afterwards.
// After that, I passed it through shuf to scramble the dataset

var config = require("./setup.json");
var names = config.names;
var nerd = config.nerd;
var geek = config.geek;

function drawAssociations(name){


  // A consequence of this scheme is that a name can never
  // be associated with everything in a category (ie. no
  // way to have nerd.length nerd associations).

  var nNerdAssociations = Math.floor((Math.random() * nerd.length));
  var nGeekAssociations = Math.floor((Math.random() * geek.length));

  var nerdIndices = [];
  var geekIndices = [];
  var i;

    for(i = 0; i < nNerdAssociations; i++){
      nerdIndices.push(Math.floor((Math.random() * nerd.length)));
    }

    for(i = 0; i < nGeekAssociations; i++){
      geekIndices.push(Math.floor(Math.random() * geek.length));
    }

    nerdIndices.forEach(function(i) {
      console.log(name + " " + nerd[i]);
    });

    geekIndices.forEach(function(i) {
      console.log(name + " " + geek[i]);
    });
  }

  names.forEach(drawAssociations);
