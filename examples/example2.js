//Add array iteration method
Array.prototype.each = function(f) {
	var len = this.length;
	for ( var i = 0; i < len; i++) f(this[i]);
};

//Initializes 3D rendering
function initRendering() {
	"DEPTH_TEST COLOR_MATERIAL LIGHTING LIGHT0 NORMALIZE COLOR_MATERIAL"
		.split(" ").each(function(elem) {
		Gl.enable(Gl[elem]);
	});
}

//angle variable
var angle = 0;

//Draws the 3D scene
function drawScene() {
	//Set global color and drawing properties
	Gl.clear(Gl.COLOR_BUFFER_BIT | Gl.DEPTH_BUFFER_BIT);
	Gl.matrixMode(Gl.MODELVIEW); 
	Gl.loadIdentity();
	Gl.translatef(0.0, 0.0, -5.0);
	//Set diffuse and positioned lights
	Gl.lightModelfv(Gl.LIGHT_MODEL_AMBIENT, [0.3, 0.3, 0.3, 1.0]);
	Gl.lightfv(Gl.LIGHT0, Gl.DIFFUSE, [0.4, 0.4, 0.4, 1.0]);
	Gl.lightfv(Gl.LIGHT0, Gl.POSITION, [5.0, 5.0, 5.0, 1.0]);
	//Rotate and plot Icosahedron
	Gl.rotatef(angle, 1.0, 1.0, 1.0);
	Gl.color3f(0.5, 0.0, 0.8);
	Glut.solidIcosahedron(2.5);
	//Render
	Glut.swapBuffers(); 
}

(function() {
	//Initialize Glut
	Glut.init();
	Glut.initDisplayMode(Glut.DOUBLE | Glut.RGB | Glut.DEPTH);
	Glut.initWindowSize(400, 400); //Set the window size
	//Create the window
	Glut.createWindow("OpenGL on V8 baby!");
	initRendering();
	//Set drawing callback
	Glut.displayFunc(drawScene);
	//Set resize window callback
	Glut.reshapeFunc(function(w, h) {
		Gl.viewport(0, 0, w, h);
		Gl.matrixMode(Gl.PROJECTION);
		Gl.loadIdentity();
		Glu.perspective(45.0, w / h, 1.0, 200.0);
	});
	//Set timeout callback
	Glut.timerFunc(25, function() {
		angle += 2.0;
		if (angle > 360) angle -= 360;
		Glut.postRedisplay();
		Glut.timerFunc(25, arguments.callee, 0);
	}, 0);
	//Start the main loop.
	Glut.mainLoop();
})();
