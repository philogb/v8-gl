//Initializes 3D rendering
function initRendering() {
	Gl.Enable(Gl.DEPTH_TEST)
	  .Enable(Gl.COLOR_MATERIAL);
}

//Called when the window is resized
function handleResize(w, h) {
	Gl.Viewport(0, 0, w, h)
	  .MatrixMode(Gl.PROJECTION)
	  .LoadIdentity();

	Glu.Perspective(45.0, w / h, 1.0, 200.0);
}

//Draws the 3D scene
function drawScene() {
	Gl.Clear(Gl.COLOR_BUFFER_BIT | Gl.DEPTH_BUFFER_BIT)
	  .MatrixMode(Gl.MODELVIEW)
	  .LoadIdentity()

	  .Begin(Gl.QUADS)
	
	   //Trapezoid
	  .Vertex3f(-0.7, -1.5, -5.0)
	  .Vertex3f(0.7, -1.5, -5.0)
	  .Vertex3f(0.4, -0.5, -5.0)
	  .Vertex3f(-0.4, -0.5, -5.0)
	
	  .End() 
	
	  .Begin(Gl.TRIANGLES)
	
	//Pentagon
	  .Vertex3f(0.5, 0.5, -5.0)
	  .Vertex3f(1.5, 0.5, -5.0)
	  .Vertex3f(0.5, 1.0, -5.0)
	
	  .Vertex3f(0.5, 1.0, -5.0)
	  .Vertex3f(1.5, 0.5, -5.0)
	  .Vertex3f(1.5, 1.0, -5.0)
	
	  .Vertex3f(0.5, 1.0, -5.0)
	  .Vertex3f(1.5, 1.0, -5.0)
	  .Vertex3f(1.0, 1.5, -5.0)
	
	//Triangle
	  .Vertex3f(-0.5, 0.5, -5.0)
	  .Vertex3f(-1.0, 1.5, -5.0)
	  .Vertex3f(-1.5, 0.5, -5.0)
	
	  .End();

	Glut.SwapBuffers();
}

function main() {
	//Initialize Glut
	Glut.Init();
	Glut.InitDisplayMode(Glut.DOUBLE | Glut.RGB | Glut.DEPTH);
	Glut.InitWindowSize(400, 400);
	
	//Create the window
	Glut.CreateWindow("OpenGL on V8 baby!");
	initRendering(); //Initialize rendering
	
	//Set handler functions for drawing, keypresses, and window resizes
	Glut.DisplayFunc(drawScene);
	Glut.ReshapeFunc(handleResize);
	
	Glut.MainLoop(); //Start the main loop.
}

main();
