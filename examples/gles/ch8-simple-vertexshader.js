//load common code.
load("common.js", "shaderutil.js");

//start custom code.
var angle = 0;

// an object we'll use to store shaders, textures, etc. on as we create them
var userData = {};

function init() {
	userData.programObject = getProgram("shaders/ch8-simple-vertexshader.vs", 
	                                    "shaders/ch8-simple-vertexshader.fs");
	
	if(userData.programObject == 0) return false;
	
	userData.positionLoc = Gles.getAttribLocation(userData.programObject, "a_position");
	userData.mvpLoc = Gles.getUniformLocation(userData.programObject, "u_mvpMatrix");
	userData.obj = esGenCube(1.0);
	Gles.clearColor(0, 0, 0, 0);
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
    modelview.rotate(angle, 1, 1, 1);

    userData.mvpMatrix = modelview.multiply(persp);
}


// Update MVP matrix based on time; deltaTime is in seconds
function update() {
	angle += 2.0;
	if (angle > 360) angle -= 360;
	updateObjects();
  Glut.postRedisplay();
	Glut.timerFunc(25, update, 0);
}

// Actually draw the triangle, using the program created in init()
function draw() {
    // Set up the viewport
    Gles.viewport(0, 0, 800, 600);

    // Clear the color buffer
    Gles.clear(Gles.COLOR_BUFFER_BIT);

    // Use the program object we created in init()
    Gles.useProgram(userData.programObject);

    // Load the vertex data
    Gles.vertexAttribPointer(userData.positionLoc, 3, Gles.FLOAT, false, 0, userData.obj.vertices);
    Gles.enableVertexAttribArray(userData.positionLoc);

    // Load the MVP matrix
    Gles.uniformMatrix4fv(userData.mvpLoc, userData.mvpMatrix.elements.length, Gles.FALSE, userData.mvpMatrix.elements);

    // Draw the cube
    //Gles.drawArrays(Gles.TRIANGLE_FAN, 0, userData.obj.vertices.length);
    Gles.drawElements(Gles.TRIANGLES, userData.obj.indices.length, Gles.UNSIGNED_SHORT, userData.obj.indices);

    // Finally do the swap to display what we just drew
    Glut.swapBuffers();
}

function main() {
	//Initialize Glut
	Glut.init();
	Glut.initDisplayMode(Glut.DOUBLE | Glut.RGB | Glut.DEPTH);
	Glut.initWindowSize(800, 600);
	//Create the window
	Glut.createWindow("OpenGL ES on V8!  (^_^)/");
	
    if (!init())
      return;
    
    updateObjects();
	//Set drawing callback
	Glut.displayFunc(draw);
	//Set resize window callback
	Glut.reshapeFunc(function(w, h) {
		Gles.viewport(0, 0, w, h);
		Gl.matrixMode(Gl.PROJECTION);
		Gl.loadIdentity();
		Glu.perspective(45.0, w / h, 1.0, 200.0);
	});

	Glut.timerFunc(25, update, 0);
	//Start the main loop.
	Glut.mainLoop();
}

main();