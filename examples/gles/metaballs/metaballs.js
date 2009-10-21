/*
  File: metaballs.js
  
  Description:
  
  Creates a Metaballs class similar to what's defined in the sprite-o-mat example.
  
  <http://www.pouet.net/prod.php?which=30222>
  
  Dependencies:
  
  core.js, v3d.js
  
  Author: 
  
  Nicolas Garcia Belmonte
  
  Copyright: 
  
  Copyright 2009 by Nicolas Garcia Belmonte.
  
  Homepage: 
  
  <http://blog.thejit.org>
  
  License: 
  
  MIT License
 */

var MetaBalls = new Class({
  balls: null,
  
  initialize: function(count) {
    var b = this.balls = new Array(count);
    for(var i=0; i < count; i++) {
      //add metaobject
      b.push({
        'pos': new V3D,
        'a': 0,
        'b': 0
      });
    }
  }
});

var MetaGrid = new Class({
  points: null,
  
  initialize: function(count) {
    var p = this.points = new Array(count);
    for(var i=0; i < count; i++) {
      //add gridpoint
      p.push({
        'value': 0,
        'flags': 0
      });
    }
  } 
});
