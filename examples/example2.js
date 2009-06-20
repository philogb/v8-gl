//Add array iteration method
Array.prototype.each = function(f) {
	var len = this.length;
	for ( var i = 0; i < len; i++) f(this[i]);
};

//Initializes 3D rendering
function initRendering() {
	"DEPTH_TEST COLOR_MATERIAL LIGHTING LIGHT0 NORMALIZE COLOR_MATERIAL"
		.split(" ").each(function(elem) {
		Gl.Enable(Gl[elem]);
	});
}

//angle variable
var angle = 0;

//Draws the 3D scene
function drawScene() {
	//Set global color and drawing properties
	Gl.Clear(Gl.COLOR_BUFFER_BIT | Gl.DEPTH_BUFFER_BIT);
	Gl.MatrixMode(Gl.MODELVIEW); 
	Gl.LoadIdentity();
	Gl.Translatef(0.0, 0.0, -5.0);
	//Set diffuse and positioned lights
	Gl.LightModelfv(Gl.LIGHT_MODEL_AMBIENT, [0.3, 0.3, 0.3, 1.0]);
	Gl.Lightfv(Gl.LIGHT0, Gl.DIFFUSE, [0.4, 0.4, 0.4, 1.0]);
	Gl.Lightfv(Gl.LIGHT0, Gl.POSITION, [5.0, 5.0, 5.0, 1.0]);
	//Rotate and plot Icosahedron
	Gl.Rotatef(angle, 1.0, 1.0, 1.0);
	Gl.Color3f(0.5, 0.0, 0.8);
	Glut.SolidIcosahedron(2.5);
	//Render
	Glut.SwapBuffers(); 
}

(function() {
	//Initialize Glut
	Glut.Init();
	Glut.InitDisplayMode(Glut.DOUBLE | Glut.RGB | Glut.DEPTH);
	Glut.InitWindowSize(400, 400); //Set the window size
	//Create the window
	Glut.CreateWindow("OpenGL on V8 baby!");
	initRendering();
	//Set drawing callback
	Glut.DisplayFunc(drawScene);
	//Set resize window callback
	Glut.ReshapeFunc(function(w, h) {
		var gl = { 'Viewport': [0, 0, w, h], 'MatrixMode': [Gl.PROJECTION], 'LoadIdentity': [] };
		for (var i in gl) Gl[i].apply(this, gl[i]);
		Glu.Perspective(45.0, w / h, 1.0, 200.0);
	});
	//Set timeout callback
	Glut.TimerFunc(25, function() {
		angle += 2.0;
		if (angle > 360) angle -= 360;
		Glut.PostRedisplay();
		Glut.TimerFunc(25, arguments.callee, 0);
	}, 0);
	//Start the main loop.
	Glut.MainLoop();
})();
