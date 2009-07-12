//adding matrix 4x4 library
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
// A simple 4x4 Matrix utility class
//

function Matrix4x4() {
  this.elements = Array(16);
  this.loadIdentity();
}

Matrix4x4.prototype = {
  scale: function (sx, sy, sz) {
    this.elements[0*4+0] *= sx;
    this.elements[0*4+1] *= sx;
    this.elements[0*4+2] *= sx;
    this.elements[0*4+3] *= sx;

    this.elements[1*4+0] *= sy;
    this.elements[1*4+1] *= sy;
    this.elements[1*4+2] *= sy;
    this.elements[1*4+3] *= sy;

    this.elements[2*4+0] *= sz;
    this.elements[2*4+1] *= sz;
    this.elements[2*4+2] *= sz;
    this.elements[2*4+3] *= sz;

    return this;
  },

  translate: function (tx, ty, tz) {
    this.elements[3*4+0] += this.elements[0*4+0] * tx + this.elements[1*4+0] * ty + this.elements[2*4+0] * tz;
    this.elements[3*4+1] += this.elements[0*4+1] * tx + this.elements[1*4+1] * ty + this.elements[2*4+1] * tz;
    this.elements[3*4+2] += this.elements[0*4+2] * tx + this.elements[1*4+2] * ty + this.elements[2*4+2] * tz;
    this.elements[3*4+3] += this.elements[0*4+3] * tx + this.elements[1*4+3] * ty + this.elements[2*4+3] * tz;

    return this;
  },

  rotate: function (angle, x, y, z) {
    var mag = Math.sqrt(x*x + y*y + z*z);
    var sinAngle = Math.sin(angle * Math.PI / 180.0);
    var cosAngle = Math.cos(angle * Math.PI / 180.0);

    if (mag > 0) {
      var xx, yy, zz, xy, yz, zx, xs, ys, zs;
      var oneMinusCos;
      var rotMat;

      x /= mag;
      y /= mag;
      z /= mag;

      xx = x * x;
      yy = y * y;
      zz = z * z;
      xy = x * y;
      yz = y * z;
      zx = z * x;
      xs = x * sinAngle;
      ys = y * sinAngle;
      zs = z * sinAngle;
      oneMinusCos = 1.0 - cosAngle;

      rotMat = new Matrix4x4();

      rotMat.elements[0*4+0] = (oneMinusCos * xx) + cosAngle;
      rotMat.elements[0*4+1] = (oneMinusCos * xy) - zs;
      rotMat.elements[0*4+2] = (oneMinusCos * zx) + ys;
      rotMat.elements[0*4+3] = 0.0;

      rotMat.elements[1*4+0] = (oneMinusCos * xy) + zs;
      rotMat.elements[1*4+1] = (oneMinusCos * yy) + cosAngle;
      rotMat.elements[1*4+2] = (oneMinusCos * yz) - xs;
      rotMat.elements[1*4+3] = 0.0;

      rotMat.elements[2*4+0] = (oneMinusCos * zx) - ys;
      rotMat.elements[2*4+1] = (oneMinusCos * yz) + xs;
      rotMat.elements[2*4+2] = (oneMinusCos * zz) + cosAngle;
      rotMat.elements[2*4+3] = 0.0;

      rotMat.elements[3*4+0] = 0.0;
      rotMat.elements[3*4+1] = 0.0;
      rotMat.elements[3*4+2] = 0.0;
      rotMat.elements[3*4+3] = 1.0;

      rotMat = rotMat.multiply(this);
      this.elements = rotMat.elements;
    }

    return this;
  },

  frustum: function (left, right, bottom, top, nearZ, farZ) {
    var deltaX = right - left;
    var deltaY = top - bottom;
    var deltaZ = farZ - nearZ;
    var frust;

    if ( (nearZ <= 0.0) || (farZ <= 0.0) ||
         (deltaX <= 0.0) || (deltaY <= 0.0) || (deltaZ <= 0.0) )
         return this;

    frust = new Matrix4x4();

    frust.elements[0*4+0] = 2.0 * nearZ / deltaX;
    frust.elements[0*4+1] = frust.elements[0*4+2] = frust.elements[0*4+3] = 0.0;

    frust.elements[1*4+1] = 2.0 * nearZ / deltaY;
    frust.elements[1*4+0] = frust.elements[1*4+2] = frust.elements[1*4+3] = 0.0;

    frust.elements[2*4+0] = (right + left) / deltaX;
    frust.elements[2*4+1] = (top + bottom) / deltaY;
    frust.elements[2*4+2] = -(nearZ + farZ) / deltaZ;
    frust.elements[2*4+3] = -1.0;

    frust.elements[3*4+2] = -2.0 * nearZ * farZ / deltaZ;
    frust.elements[3*4+0] = frust.elements[3*4+1] = frust.elements[3*4+3] = 0.0;

    frust = frust.multiply(this);
    this.elements = frust.elements;

    return this;
  },

  perspective: function (fovy, aspect, nearZ, farZ) {
    var frustumH = Math.tan(fovy / 360.0 * Math.PI) * nearZ;
    var frustumW = frustumH * aspect;

    return this.frustum(-frustumW, frustumW, -frustumH, frustumH, nearZ, farZ);
  },

  ortho: function (left, right, bottom, top, nearZ, farZ) {
    var deltaX = right - left;
    var deltaY = top - bottom;
    var deltaZ = farZ - nearZ;

    var ortho = new Matrix4x4();

    if ( (deltaX == 0.0) || (deltaY == 0.0) || (deltaZ == 0.0) )
        return this;

    ortho.elements[0*4+0] = 2.0 / deltaX;
    ortho.elements[3*4+0] = -(right + left) / deltaX;
    ortho.elements[1*4+1] = 2.0 / deltaY;
    ortho.elements[3*4+1] = -(top + bottom) / deltaY;
    ortho.elements[2*4+2] = -2.0 / deltaZ;
    ortho.elements[3*4+2] = -(nearZ + farZ) / deltaZ;

    ortho = ortho.multiply(this);
    this.elements = ortho.elements;

    return this;
  },

  multiply: function (right) {
    var tmp = new Matrix4x4();

    for (var i = 0; i < 4; i++) {
      tmp.elements[i*4+0] =
	(this.elements[i*4+0] * right.elements[0*4+0]) +
	(this.elements[i*4+1] * right.elements[1*4+0]) +
	(this.elements[i*4+2] * right.elements[2*4+0]) +
	(this.elements[i*4+3] * right.elements[3*4+0]) ;

      tmp.elements[i*4+1] =
	(this.elements[i*4+0] * right.elements[0*4+1]) +
	(this.elements[i*4+1] * right.elements[1*4+1]) +
	(this.elements[i*4+2] * right.elements[2*4+1]) +
	(this.elements[i*4+3] * right.elements[3*4+1]) ;

      tmp.elements[i*4+2] =
	(this.elements[i*4+0] * right.elements[0*4+2]) +
	(this.elements[i*4+1] * right.elements[1*4+2]) +
	(this.elements[i*4+2] * right.elements[2*4+2]) +
	(this.elements[i*4+3] * right.elements[3*4+2]) ;

      tmp.elements[i*4+3] =
	(this.elements[i*4+0] * right.elements[0*4+3]) +
	(this.elements[i*4+1] * right.elements[1*4+3]) +
	(this.elements[i*4+2] * right.elements[2*4+3]) +
	(this.elements[i*4+3] * right.elements[3*4+3]) ;
    }

    this.elements = tmp.elements;
    return this;
  },

  loadIdentity: function () {
    for (var i = 0; i < 16; i++)
      this.elements[i] = 0;
    this.elements[0*4+0] = 1.0;
    this.elements[1*4+1] = 1.0;
    this.elements[2*4+2] = 1.0;
    this.elements[3*4+3] = 1.0;
    return this;
  }
};

//adding a simple shape library
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
//end library code.


//start custom code.
var angle = 0;
var vertex_shader = "uniform mat4 u_mvpMatrix;\n"
					+ "attribute vec4 a_position;\n"
					+ "void main()\n"
					+ "{\n"
					+ "gl_Position = u_mvpMatrix * a_position;\n"
					+ "}\n";

var fragment_shader = "void main()\n"
					+ "{\n"
					+ "gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);\n"
					+ "}\n";

// an object we'll use to store shaders, textures, etc. on as we create them
var userData = {};

function loadShader(shaderType, shaderSource) {
    // Create the shader object
    var shader = Gles.CreateShader(shaderType);
    if (shader == 0) return 0;

    // Load the shader source
    Gles.ShaderSource(shader, shaderSource);

    // Compile the shader
    Gles.CompileShader(shader);

    // Check the compile status
    var compiled = Gles.GetShaderiv(shader, Gles.COMPILE_STATUS);
    if (!compiled) {
		// Something went wrong during compilation; get the error
		var error = Gles.GetShaderInfoLog(shader);
		Gles.DeleteShader(shader);
		return 0;
    }

    return shader;
}

// Convenience function to create a program from all the passed-in
function getProgram() {
    var shaders = [];

    // first load and compile all the passed-in shaders.
    for (var i = 0; i < arguments.length; i+=2) {
	    var type = arguments[i], source = arguments[i+1];
		var shader = loadShader(type, source);
		if (shader == 0)
		    return 0;
		shaders.push(shader);
    }

    // then do the program object creation
    var program = Gles.CreateProgram();
    if (program == 0)
	return 0;

    // attach all the shaders
    for (var i = 0; i < shaders.length; i++) {
	Gles.AttachShader(program, shaders[i]);
    }

    // link, and check for errors
    Gles.LinkProgram(program);

    var linked = Gles.GetProgramiv(program, Gles.LINK_STATUS);
    if (!linked) {
    	var error = Gles.GetProgramInfoLog(program);
    	return 0;
    }

    return program;
}

function init() {
	userData.programObject = getProgram(Gles.VERTEX_SHADER, vertex_shader, Gles.FRAGMENT_SHADER, fragment_shader);
	if(userData.programObject == 0) return false;
	
	userData.positionLoc = Gles.GetAttribLocation(userData.programObject, "a_position");
	userData.mvpLoc = Gles.GetUniformLocation(userData.programObject, "u_mvpMatrix");
	userData.obj = esGenCube(1.0);
	Gles.ClearColor(0, 0, 0, 0);
	return true;
}

function updateObjects() {
	// compute the window aspect ratio
    var aspect = 800 / 600;

    // Generate a perspective matrix with a 60 degree FOV
    var persp = new Matrix4x4();
    persp.perspective(60, aspect, 1.0, 20.0);

    // Create our modelview matrix
    var modelview = new Matrix4x4();

    // translate away from the viewer
    modelview.translate(0, 0, -2);

    // then rotating the cube
    modelview.rotate(angle, 1, 0, 1);

    userData.mvpMatrix = modelview.multiply(persp);
}


// Update MVP matrix based on time; deltaTime is in seconds
function update() {
	angle += 2.0;
	if (angle > 360) angle -= 360;
	updateObjects();
    Glut.PostRedisplay();
	Glut.TimerFunc(25, update, 0);
}

// Actually draw the triangle, using the program created in init()
function draw() {
    // Set up the viewport
    Gles.Viewport(0, 0, 800, 600);

    // Clear the color buffer
    Gles.Clear(Gles.COLOR_BUFFER_BIT);

    // Use the program object we created in init()
    Gles.UseProgram(userData.programObject);

    // Load the vertex data
    Gles.VertexAttribPointer(userData.positionLoc, 3, Gles.FLOAT, false, 0, userData.obj.vertices);
    Gles.EnableVertexAttribArray(userData.positionLoc);

    // Load the MVP matrix
    Gles.UniformMatrix4fv(userData.mvpLoc, userData.mvpMatrix.elements.length, Gles.FALSE, userData.mvpMatrix.elements);

    // Draw the cube
    Gles.DrawElements(Gles.TRIANGLES, userData.obj.indices.length, Gles.UNSIGNED_SHORT, userData.obj.indices);

    // Finally do the swap to display what we just drew
    Glut.SwapBuffers();
}

function main() {
	//Initialize Glut
	Glut.Init();
	Glut.InitDisplayMode(Glut.DOUBLE | Glut.RGB | Glut.DEPTH);
	Glut.InitWindowSize(800, 600);
	//Create the window
	Glut.CreateWindow("OpenGL ES on V8!  (^_^)/");
	
    if (!init())
	return;
    
    updateObjects();
	//Set drawing callback
	Glut.DisplayFunc(draw);
	//Set resize window callback
	Glut.ReshapeFunc(function(w, h) {
		Gles.Viewport(0, 0, w, h);
		Gl.MatrixMode(Gl.PROJECTION);
		Gl.LoadIdentity();
		Glu.Perspective(45.0, w / h, 1.0, 200.0);
	});

	Glut.TimerFunc(25, update, 0);
	//Start the main loop.
	Glut.MainLoop();
}

main();