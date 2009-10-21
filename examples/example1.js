//Initializes 3D rendering
function initRendering() {
	Gl.enable(Gl.DEPTH_TEST)
	  .enable(Gl.COLOR_MATERIAL);
}

//Called when the window is resized
function handleResize(w, h) {
	Gl.viewport(0, 0, w, h)
	  .matrixMode(Gl.PROJECTION)
	  .loadIdentity();

	Glu.perspective(45.0, w / h, 1.0, 200.0);
}

//Draws the 3D scene
function drawScene() {
	Gl.clear(Gl.COLOR_BUFFER_BIT | Gl.DEPTH_BUFFER_BIT)
	  .matrixMode(Gl.MODELVIEW)
	  .loadIdentity()

	  .begin(Gl.QUADS)
	
	   //Trapezoid
	  .vertex3f(-0.7, -1.5, -5.0)
	  .vertex3f(0.7, -1.5, -5.0)
	  .vertex3f(0.4, -0.5, -5.0)
	  .vertex3f(-0.4, -0.5, -5.0)
	
	  .end() 
	
	  .begin(Gl.TRIANGLES)
	
	//Pentagon
	  .vertex3f(0.5, 0.5, -5.0)
	  .vertex3f(1.5, 0.5, -5.0)
	  .vertex3f(0.5, 1.0, -5.0)
	
	  .vertex3f(0.5, 1.0, -5.0)
	  .vertex3f(1.5, 0.5, -5.0)
	  .vertex3f(1.5, 1.0, -5.0)
	
	  .vertex3f(0.5, 1.0, -5.0)
	  .vertex3f(1.5, 1.0, -5.0)
	  .vertex3f(1.0, 1.5, -5.0)
	
	//Triangle
	  .vertex3f(-0.5, 0.5, -5.0)
	  .vertex3f(-1.0, 1.5, -5.0)
	  .vertex3f(-1.5, 0.5, -5.0)
	
	  .end();

	Glut.swapBuffers();
}

function main() {
	//Initialize Glut
	Glut.init();
	Glut.initDisplayMode(Glut.DOUBLE | Glut.RGB | Glut.DEPTH);
	Glut.initWindowSize(400, 400);
	
	//Create the window
	Glut.createWindow("OpenGL on V8 baby!");
	initRendering(); //Initialize rendering
	
	//Set handler functions for drawing, keypresses, and window resizes
	Glut.displayFunc(drawScene);
	Glut.reshapeFunc(handleResize);
	
	Glut.mainLoop(); //Start the main loop.
}

main();
