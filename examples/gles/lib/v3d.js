/*
  File: v3d.js
  
  Description:
  
  3D Vector Class.
  
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
var V3D = new Class({
  x: null, y: null, z: null,
  
  initialize: function(x, y, z){
    this.x = x || 0;
    this.y = y || 0;
    this.z = z || 0;
  },
  
  copy: function(v){
    this.x = v.x;
    this.y = v.y;
    this.z = v.z;
    return this;
  },
  
  add: function(v){
    this.x += v.x;
    this.y += v.y;
    this.z += v.z;
    return this;
  },
  
  sub: function(v){
    this.x -= v.x;
    this.y -= v.y;
    this.z -= v.z;
    return this;
  },
  
  cross: function(v){
    var tx = this.x,
        ty = this.y,
        tz = this.z;
    
    this.x = ty * v.z - tz * v.y;
    this.y = tz * v.x - tx * v.z;
    this.z = tx * v.y - ty * v.x;
    return this;
  },
  
  scale: function(s){
    this.x *= s;
    this.y *= s;
    this.z *= s;
    return this;
  },
  
  distanceTo: function(v){
    return Math.sqrt(this.distanceToSq(v));
  },
  
  distanceToSq: function(v){
    var dx = this.x - v.x,
        dy = this.y - v.y,
        dz = this.z - v.z;
    
    return dx * dx + dy * dy + dz * dz;
  },
  
  length: function(){
    return Math.sqrt(this.lengthSq());
  },
  
  lengthSq: function(){
    return this.distanceToSq(V3D.KER);
  },
  
  negate: function(){
    this.x = -this.x;
    this.y = -this.y;
    this.z = -this.z;
    return this;
  },
  
  normalize: function(){
    var len = this.length(), ratio;
    if (len > 0)
      ratio = 1.0 / len;
    else
      ratio = 0;
      
    this.x *= ratio;
    this.y *= ratio;
    this.z *= ratio;
    return this;
  },
  
  dot: function(v){
    return this.x * v.x + this.y * v.y + this.z * v.z;
  },
  
  clone: function(){
    return new V3D(this.x, this.y, this.z);
  },
  
  toString: function(){
    return '(' + this.x + ', ' + this.y + ', ' + this.z + ')';
  }  
});

V3D.KER = new V3D;

V3D.add = function(a, b) {
  return new V3D( a.x + b.x, a.y + b.y, a.z + b.z );
};

V3D.sub = function(a, b) {
  return new V3D( a.x - b.x, a.y - b.y, a.z - b.z );
};   

V3D.scale = function(a, s) {
  return new V3D( a.x * s, a.y * s, a.z * s );
};

V3D.cross = function(a, b) {
  return new V3D( a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x );
};

V3D.dot = function(a, b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
};
