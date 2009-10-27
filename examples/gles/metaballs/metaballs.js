/*
  File: metaballs.js
  
  Description:
  
  Creates a Metaballs class similar to what's defined in the sprite-o-mat example.
  
  <http://www.pouet.net/prod.php?which=30222>
  
  Dependencies:
  
  core.js
  
  Author: 
  
  Nicolas Garcia Belmonte
  
  Copyright: 
  
  Copyright 2009 by Nicolas Garcia Belmonte.
  
  Homepage: 
  
  <http://blog.thejit.org>
  
  License: 
  
  MIT License
 */

var Config = {
    gridDim: 64,
    shift1: 6,
    shift2: 12,
    ballCount: 128,
    
    GP_TYPE_META: 0x1,
    GP_TYPE_BORDER: 0x2,
    GP_TYPE_TEXT: 0x4
};

var MetaBalls = new Class({
  balls: null,
  grid: null,
  
  initialize: function(grid) {
    this.grid = grid;
    var count = Config.ballCount;
    var b = this.balls = new Array(count);
    for(var i=0; i < count; i++) {
      //add metaobject
      b.push({
        'pos': { 'x':0, 'y':0, 'z':0 },
        'a': 0,
        'b': 0
      });
    }
  },
  
  update: function(from, to) {
    var balls = this.balls;
    var dim = Config.gridDim;
    var points = this.grid.points;
    var shift1 = Config.shift1, shift2 = Config.shift2;
    var meta = Config.GP_TYPE_META;
    
    while (from < num) {
      var ballsFrom = balls[from];
      var influenceRange = 1 + (ballsFrom.b >> 0);
      var pos = ballsFrom.pos;
      var posx = (pos.x >> 0);
      var posy = (pos.y >> 0);
      var posz = (pos.z >> 0);   
      for (var z = posz-influenceRange; z < posz+influenceRange; ++z) {
        if (z < 0 || z >= dim)
          continue;

        for (var y = posy-influenceRange; y < posy+influenceRange; ++y) {
          if (y < 0 || y >= dim)
            continue;

          for (var x = posx-influenceRange; x < posx+influenceRange; ++x) {
            if (x < 0 || x >= dim)
              continue;

            var dist = {
                'x': pos.x - x,
                'y': pos.y - y,
                'z': pos.z - z
            };
            var dist2 = dist.x * dist.x + dist.y * dist.y + dist.z * dist.z;
            var range2 = ballsFrom.b * ballsFrom.b;

            if (range2 > dist2) {
              var gp = points[(z<<shift2) + (y<<shift1) + x];
              gp.value += ballsFrom.a * 
                (1.0f - 
                0.4444444f * dist2 * dist2 * dist2 / (range2 * range2 * range2) + 
                1.8888888f * dist2 * dist2 / (range2 * range2) - 
                2.4444444f * dist2 / range2);
              
              gp.flags |= meta;
            }
          }
        }
      }
      ++from;
    }
  }
});

var MetaGrid = new Class({
  points: null, 
  
  dim: null,
  dimSq: null,
  dimCb: null,
  
  initialize: function() {
    var count = Config.gridDim;
    this.dim = count;
    this.dimSq = count * count;
    this.dimCb = count * count * count;
    
    var p = this.points = new Array(count);
    for(var i=0; i < count; i++) {
      //add gridpoint
      p.push({
        'value': 0,
        'flags': 0
      });
    }
  },
  
  move: function(fac) {
    var movecount = this.dimCb;
    var dimSq = this.dimSq;
    var points = this.points;
    
    while (movecount--) {
      if (((movecount >> 12) & 0x3f) > 0) {
        var p = points[movecount];
        var pdiff = points[movecount - dimSq];
        
        p.value = fac * pdiff.value;
        p.flags = pdiff.flags;
      } else {
        points[movecount].value = 0;
      }
    } 
  }

});

function rgba(redval, greenval, blueval, alphaval) {
  return ((alphaval << 24) | (redval << 16) | (greenval << 8) | blueval); 
}

function gridColor(gp) {
  var maxval = 2.0 * gp.value - 1.0;
  
  if (maxval > 1.0)
    maxval = 1.0;
  
  var metacolor = rgba(196, 64 + ((192.0 * (1.0 - maxval)) >> 0), 0, 0);
  
  if (gp.flags & Config.GP_TYPE_META) {
    if (gp.flags & Config.GP_TYPE_BORDER)
      return {
        'color': ((metacolor & 0xfefefefe) >> 1) + rgba(0, 64, 92, 0),
        'maxval': maxval
      };
    else
      return {
        'color': metacolor,
        'maxval': maxval
      };
  } else {
    if (gp.flags & Config.GP_TYPE_BORDER)
      return {
        'color': rgba(0, 128, 196, 0),
        'maxval': maxval
      };
    else
      return {
        'color': rgba(128, 228, 128, 0),
        'maxval': maxval
      };
  }
}
