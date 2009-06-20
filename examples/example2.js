//Initializes 3D rendering
function initRendering() {
	Gl.Enable(Gl.DEPTH_TEST);
	Gl.Enable(Gl.COLOR_MATERIAL);
	Gl.Enable(Gl.LIGHTING);
	Gl.Enable(Gl.LIGHT0);
	Gl.Enable(Gl.NORMALIZE);
	Gl.Enable(Gl.COLOR_MATERIAL);
}

//Called when the window is resized
function handleResize(w, h) {
	Gl.Viewport(0, 0, w, h);
	Gl.MatrixMode(Gl.PROJECTION);
	//Set the camera perspective
	Gl.LoadIdentity(); 
	Glu.Perspective(45.0, w / h, 1.0, 200.0);
}

var _angle = 0;
function update(value) {
	_angle += 2.0;
	if (_angle > 360) _angle -= 360;
	Glut.PostRedisplay();
	Glut.TimerFunc(25, update, 0);
}

//Draws the 3D scene
function drawScene() {
	Gl.Clear(Gl.COLOR_BUFFER_BIT | Gl.DEPTH_BUFFER_BIT);

	Gl.MatrixMode(Gl.MODELVIEW); 
	Gl.LoadIdentity();
	Gl.Translatef(0.0, 0.0, -5.0);

	Gl.LightModelfv(Gl.LIGHT_MODEL_AMBIENT, [0.3, 0.3, 0.3, 1.0]);
	Gl.Lightfv(Gl.LIGHT0, Gl.DIFFUSE, [0.7, 0.7, 0.7, 1.0]);
	Gl.Lightfv(Gl.LIGHT0, Gl.POSITION, [5.0, 5.0, 5.0, 1.0]);
	
	Gl.Rotatef(_angle, 1.0, 1.0, 1.0);
	Gl.Color3f(0.5, 0.0, 0.8);
	Glut.SolidDodecahedron(2.0);
	
	Glut.SwapBuffers(); 
}

(function() {

	//Initialize GLUT
	Glut.Init();
	Glut.InitDisplayMode(Glut.DOUBLE | Glut.RGB | Glut.DEPTH);
	Glut.InitWindowSize(400, 400); //Set the window size
	
	//Create the window
	Glut.CreateWindow("Basic Shapes - JavaScript on V8 baby!");
	initRendering(); //Initialize rendering
	
	//Set handler functions for drawing, keypresses, and window resizes
	Glut.DisplayFunc(drawScene);
	Glut.ReshapeFunc(handleResize);
	Glut.TimerFunc(25, update, 0);
	
	//Start the main loop.
	Glut.MainLoop();

})();