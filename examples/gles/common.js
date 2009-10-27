load("lib/matrix.js");

/*
 * Copyright (c) 2009, Mozilla Corp
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the <organization> nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY <copyright holder> ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL <copyright holder> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * Based on sample code from the OpenGL(R) ES 2.0 Programming Guide, which carriers
 * the following header:
 *
 * Book:      OpenGL(R) ES 2.0 Programming Guide
 * Authors:   Aaftab Munshi, Dan Ginsburg, Dave Shreiner
 * ISBN-10:   0321502795
 * ISBN-13:   9780321502797
 * Publisher: Addison-Wesley Professional
 * URLs:      http://safari.informit.com/9780321563835
 *            http://www.opengles-book.com
 */

//
// port of esShapes.c
//

function shallowCloneArray(ar) {
  var o = Array(ar.length);
  for (var i = 0; i < ar.length; i++) {
    o[i] = ar[i];
  }
  return o;
}

function shallowCloneArrayScaled(ar, scale) {
  var o = Array(ar.length);
  for (var i = 0; i < ar.length; i++) {
    o[i] = ar[i] * scale;
  }
  return o;
}

// make these accessible directly in the glboal scope,
// in case someone wants to use them without copying
var esCubeVertices = [
  -0.5, -0.5, -0.5,
  -0.5, -0.5,  0.5,
   0.5, -0.5,  0.5,
   0.5, -0.5, -0.5,
  -0.5,  0.5, -0.5,
  -0.5,  0.5,  0.5,
   0.5,  0.5,  0.5,
   0.5,  0.5, -0.5,
  -0.5, -0.5, -0.5,
  -0.5,  0.5, -0.5,
   0.5,  0.5, -0.5,
   0.5, -0.5, -0.5,
  -0.5, -0.5, 0.5,
  -0.5,  0.5, 0.5,
   0.5,  0.5, 0.5,
   0.5, -0.5, 0.5,
  -0.5, -0.5, -0.5,
  -0.5, -0.5,  0.5,
  -0.5,  0.5,  0.5,
  -0.5,  0.5, -0.5,
   0.5, -0.5, -0.5,
   0.5, -0.5,  0.5,
   0.5,  0.5,  0.5,
   0.5,  0.5, -0.5
];

var esCubeNormals = [
   0.0, -1.0, 0.0,
   0.0, -1.0, 0.0,
   0.0, -1.0, 0.0,
   0.0, -1.0, 0.0,
   0.0, 1.0, 0.0,
   0.0, 1.0, 0.0,
   0.0, 1.0, 0.0,
   0.0, 1.0, 0.0,
   0.0, 0.0, -1.0,
   0.0, 0.0, -1.0,
   0.0, 0.0, -1.0,
   0.0, 0.0, -1.0,
   0.0, 0.0, 1.0,
   0.0, 0.0, 1.0,
   0.0, 0.0, 1.0,
   0.0, 0.0, 1.0,
  -1.0, 0.0, 0.0,
  -1.0, 0.0, 0.0,
  -1.0, 0.0, 0.0,
  -1.0, 0.0, 0.0,
   1.0, 0.0, 0.0,
   1.0, 0.0, 0.0,
   1.0, 0.0, 0.0,
   1.0, 0.0, 0.0
];

var esCubeTexCoords = [
  0.0, 0.0,
  0.0, 1.0,
  1.0, 1.0,
  1.0, 0.0,
  1.0, 0.0,
  1.0, 1.0,
  0.0, 1.0,
  0.0, 0.0,
  0.0, 0.0,
  0.0, 1.0,
  1.0, 1.0,
  1.0, 0.0,
  0.0, 0.0,
  0.0, 1.0,
  1.0, 1.0,
  1.0, 0.0,
  0.0, 0.0,
  0.0, 1.0,
  1.0, 1.0,
  1.0, 0.0,
  0.0, 0.0,
  0.0, 1.0,
  1.0, 1.0,
  1.0, 0.0
];

var esCubeIndices = [
  0, 2, 1,
  0, 3, 2,
  4, 5, 6,
  4, 6, 7,
  8, 9, 10,
  8, 10, 11,
  12, 15, 14,
  12, 14, 13,
  16, 17, 18,
  16, 18, 19,
  20, 23, 22,
  20, 22, 21
];

// will return an object that has vertices, normals, texCoords, and indices members
function esGenCube (scale) {
  return {
    vertices: shallowCloneArrayScaled(esCubeVertices, scale),
    texCoords: shallowCloneArray(esCubeTexCoords),
    indices: shallowCloneArray(esCubeIndices),
    normals: shallowCloneArray(esCubeNormals)
  };
}

//
// generates coordinate information for a sphere
//

function esGenSphere (numSlices, radius) {
  var i, j;
  var numParallels = numSlices;
  var numVertices = (numParallels + 1) * (numSlices + 1);
  var numIndices = numParallels * numSlices * 6;
  var angleStep = (2 * Math.PI) / numSlices;

  var vertices = Array(3*numVertices);
  var normals = Array(3*numVertices);
  var texCoords = Array(2*numVertices);
  var indices = Array(numIndices);

  for (i = 0; i < numParallels+1; i++) {
    for (j = 0; j < numSlices+1; j++) {
      var vertex = (i * (numSlices+1) + j) * 3;

      vertices[vertex+0] = radius * Math.sin(angleStep * i) * Math.sin(angleStep * j);
      vertices[vertex+1] = radius * Math.cos(angleStep * i);
      vertices[vertex+2] = radius * Math.sin(angleStep * i) * Math.cos(angleStep * j);

      normals[vertex+0] = vertices[vertex+0] / radius;
      normals[vertex+1] = vertices[vertex+1] / radius;
      normals[vertex+2] = vertices[vertex+2] / radius;

      var texIndex = (i * (numSlices+1) + j) * 2;

      texCoords[texIndex+0] = j / numSlices;
      texCoords[texIndex+1] = (1 - i) / (numParallels - 1);
    }
  }

  var k = 0;
  for (i = 0; i < numParallels; i++) {
    for (j = 0; j < numSlices; j++) {
      indices[k++] = i * (numSlices + 1) + j;
      indices[k++] = (i + 1) * (numSlices + 1) + j;
      indices[k++] = (i + 1) * (numSlices + 1) + (j + 1);

      indices[k++] = i * (numSlices + 1) + j;
      indices[k++] = (i + 1) * (numSlices + 1) + (j + 1);
      indices[k++] = i * (numSlices + 1) + (j + 1);
    }
  }

  return {
    vertices: vertices,
    normals: normals,
    texCoords: texCoords,
    indices: indices
  };
}
