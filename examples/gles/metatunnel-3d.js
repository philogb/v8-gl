// This is a hacked up version of vlad's port of FRequency's metatunnel.
//   http://people.mozilla.com/~vladimir/misc/metatunnel-3d.html
load("shaderutil.js");

var w = 740, h = 480;

//Initialize Glut
Glut.Init();
Glut.InitDisplayMode(Glut.DOUBLE | Glut.RGB | Glut.DEPTH);
Glut.InitWindowSize(w, h);

//Create the window
Glut.CreateWindow("OpenGL on V8 baby!");

//Make a program with the following shaders
var p = getProgram("shaders/m3d-vshader.sl", 
                  Gles.VERTEX_SHADER, 
                  "shaders/m3d-fshader.sl", 
                  Gles.FRAGMENT_SHADER);

if (p == 0)
  return false;

Gles.UseProgram(p);

// Store our attrib data in a VBO.
var buffers = Gles.GenBuffers(1);
Gles.BindBuffer(Gles.ARRAY_BUFFER, buffers[0]);
Gles.BufferData(Gles.ARRAY_BUFFER, [ -1, 1, 1, 1, -1, -1, 1, -1], Gles.FLOAT, Gles.STATIC_DRAW);

Gles.VertexAttribPointer(0, 2, Gles.FLOAT, false, 0, 0);
Gles.EnableVertexAttribArray(0);

function draw() {
  Gles.Viewport(0, 0, w, h);
  var n = Date.now();
  var r = n & 0xff;
  var g = (n>>8) & 0xff;
  var b = (n>>16) & 0xff;
  Gles.Uniform4fv(0, 1, [r/255.0, g/255.0, b/255.0, 1.0]);
  Gles.DrawArrays(Gles.TRIANGLE_STRIP, 0, 4);

  Glut.SwapBuffers();
}

Glut.DisplayFunc(draw);

//Set timeout callback
Glut.TimerFunc(25, function() {
  Glut.PostRedisplay();
  Glut.TimerFunc(25, arguments.callee, 0);
}, 0);

Glut.MainLoop();
