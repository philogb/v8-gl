// This is a hacked up version of vlad's port of FRequency's metatunnel.
//   http://people.mozilla.com/~vladimir/misc/metatunnel-3d.html
load("shaderutil.js");

var w = 740, h = 480;

//Initialize Glut
Glut.init();
Glut.initDisplayMode(Glut.DOUBLE | Glut.RGB | Glut.DEPTH);
Glut.initWindowSize(w, h);

//Create the window
Glut.createWindow("OpenGL on V8 baby!");

//Make a program with the following shaders
var p = getProgram("shaders/m3d-vshader.sl", 
                  "shaders/m3d-fshader.sl");

if (p == 0)
  return false;

Gles.useProgram(p);

// Store our attrib data in a VBO.
var buffers = Gles.genBuffers(1);
Gles.bindBuffer(Gles.ARRAY_BUFFER, buffers[0]);
Gles.bufferData(Gles.ARRAY_BUFFER, [ -1, 1, 1, 1, -1, -1, 1, -1], Gles.FLOAT, Gles.STATIC_DRAW);

Gles.vertexAttribPointer(0, 2, Gles.FLOAT, false, 0, 0);
Gles.enableVertexAttribArray(0);

function draw() {
  Gles.viewport(0, 0, w, h);
  var n = Date.now();
  var r = n & 0xff;
  var g = (n>>8) & 0xff;
  var b = (n>>16) & 0xff;
  Gles.uniform4fv(0, 1, [r/255.0, g/255.0, b/255.0, 1.0]);
  Gles.drawArrays(Gles.TRIANGLE_STRIP, 0, 4);

  Glut.swapBuffers();
}

Glut.displayFunc(draw);

//Set timeout callback
Glut.timerFunc(25, function() {
  Glut.postRedisplay();
  Glut.timerFunc(25, arguments.callee, 0);
}, 0);

Glut.mainLoop();
