//load common code.
load("common.js");

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