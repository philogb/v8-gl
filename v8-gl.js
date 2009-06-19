//Initializes 3D rendering
function initRendering() {
	//Makes 3D drawing work when something is in front of something else
	Gl.Enable(Gl.DEPTH_TEST);
}

//Called when the window is resized
function handleResize(w, h) {
	//Tell OpenGL how to convert from coordinates to pixel values
	Gl.Viewport(0, 0, w, h);
	
	Gl.MatrixMode(Gl.PROJECTION); //Switch to setting the camera perspective
	
	//Set the camera perspective
	Gl.LoadIdentity(); //Reset the camera
	Glu.Perspective(45.0,                  //The camera anGle
				   w / h, //The width-to-height ratio
				   1.0,                   //The near z clipping coordinate
				   200.0);                //The far z clipping coordinate
}

//Draws the 3D scene
function drawScene() {
	//Clear information from last draw
	Gl.Clear(Gl.COLOR_BUFFER_BIT | Gl.DEPTH_BUFFER_BIT);
	
	Gl.MatrixMode(Gl.MODELVIEW); //Switch to the drawing perspective
	Gl.LoadIdentity(); //Reset the drawing perspective
	
	Gl.Begin(Gl.QUADS); //Begin quadrilateral coordinates
	
	//Trapezoid
	Gl.Vertex3f(-0.7, -1.5, -5.0);
	Gl.Vertex3f(0.7, -1.5, -5.0);
	Gl.Vertex3f(0.4, -0.5, -5.0);
	Gl.Vertex3f(-0.4, -0.5, -5.0);
	
	Gl.End(); //End quadrilateral coordinates
	
	Gl.Begin(Gl.TRIANGLES); //Begin trianGle coordinates
	
	//Pentagon
	Gl.Vertex3f(0.5, 0.5, -5.0);
	Gl.Vertex3f(1.5, 0.5, -5.0);
	Gl.Vertex3f(0.5, 1.0, -5.0);
	
	Gl.Vertex3f(0.5, 1.0, -5.0);
	Gl.Vertex3f(1.5, 0.5, -5.0);
	Gl.Vertex3f(1.5, 1.0, -5.0);
	
	Gl.Vertex3f(0.5, 1.0, -5.0);
	Gl.Vertex3f(1.5, 1.0, -5.0);
	Gl.Vertex3f(1.0, 1.5, -5.0);
	
	//TrianGle
	Gl.Vertex3f(-0.5, 0.5, -5.0);
	Gl.Vertex3f(-1.0, 1.5, -5.0);
	Gl.Vertex3f(-1.5, 0.5, -5.0);
	
	Gl.End(); //End trianGle coordinates
	
	Glut.SwapBuffers(); //Send the 3D scene to the screen
}

function main() {
	//Initialize GLUT
	Glut.Init();
	Glut.InitDisplayMode(Glut.DOUBLE | Glut.RGB | Glut.DEPTH);
	Glut.InitWindowSize(400, 400); //Set the window size
	
	//Create the window
	Glut.CreateWindow("Basic Shapes - JavaScript on V8 baby!");
	initRendering(); //Initialize rendering
	
	//Set handler functions for drawing, keypresses, and window resizes
	Glut.DisplayFunc(drawScene);
	Glut.KeyboardFunc(handleKeypress);
	Glut.ReshapeFunc(handleResize);
	
	Glut.MainLoop(); //Start the main loop.  GlutMainLoop doesn't return.
}

main();
