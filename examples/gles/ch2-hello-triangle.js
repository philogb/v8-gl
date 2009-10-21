// an object we'll use to store shaders, textures, etc. on as we create them
var userData = { };

function loadShader(shaderType, shaderSource) {
    // Create the shader object
    var shader = Gles.createShader(shaderType);
    if (shader == 0) return 0;

    // Load the shader source
    Gles.shaderSource(shader, shaderSource);

    // Compile the shader
    Gles.compileShader(shader);

    // Check the compile status
    var compiled = Gles.getShaderiv(shader, Gles.COMPILE_STATUS);
    if (!compiled) {
  		// Something went wrong during compilation; get the error
  		var error = Gles.getShaderInfoLog(shader);
  		Gles.deleteShader(shader);
  		return 0;
    }

    return shader;
}

function init() {
    // put our shader source in variables
    var vertexShaderSource = 
	"attribute vec4 vPosition;     \n" +
	"void main()                   \n" +
	"{                             \n" +
	"  gl_Position = vPosition;    \n" +
	"} ";
    var fragmentShaderSource =
	"/*precision mediump float;*/  \n" +
	"void main()                   \n" +
	"{                             \n" +
	"  gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0); \n" +
	"} ";
    
    // create our shaders
    var vertexShader = loadShader(Gles.VERTEX_SHADER, vertexShaderSource);
    var fragmentShader = loadShader(Gles.FRAGMENT_SHADER, fragmentShaderSource);
    
    if (!vertexShader || !fragmentShader)
	return false;

    // Create the program object
    var programObject = Gles.createProgram();
    if (programObject == 0)
      return false;

    // Attach our two shaders to the program
    Gles.attachShader (programObject, vertexShader);
    Gles.attachShader (programObject, fragmentShader);

    // Bind "vPosition" to attribute 0
    Gles.bindAttribLocation (programObject, 0, "vPosition");
    
    // Link the program
    Gles.linkProgram (programObject);

    // Check the link status
    var linked = Gles.getProgramiv (programObject, Gles.LINK_STATUS);
    if (!linked) {
		// something went wrong with the link
		var error = Gles.getProgramInfoLog (programObject);
	
		Gles.deleteProgram(programObject);
		Gles.deleteProgram(fragmentShader);
		Gles.deleteProgram(vertexShader);
	
		return false;
    }

    userData.programObject = programObject;

    // set up the clear color to clear to transparent black
    Gles.clearColor (0, 0, 0, 0);

	//Set drawing callback
	Glut.displayFunc(draw);
    
    return true;
}

// Actually draw the triangle, using the program created in init()
function draw() {
	var vertices = [  0.0,  0.5,  0.0,
				     -0.5, -0.5,  0.0,
				      0.5, -0.5,  0.0  ];

    // Set up the viewport
    Gles.viewport(0, 0, 800, 600);

    // Clear the color buffer
    Gles.clear(Gles.COLOR_BUFFER_BIT);

    // Use the program object we created in init()
    Gles.useProgram(userData.programObject);

    // Load the vertex data
    Gles.vertexAttribPointer(0, 3, Gles.FLOAT, false, 0, vertices);
    Gles.enableVertexAttribArray(0);

    // Do the draw, as triangles
    Gles.drawArrays(Gles.TRIANGLES, 0, 3);
    
    // Finally do the swap to display what we just drew
    Glut.swapBuffers();
}

function main() {
	//Initialize Glut
	Glut.init();
	Glut.initDisplayMode(Glut.DOUBLE | Glut.RGB | Glut.DEPTH);
	Glut.initWindowSize(800, 600);
	//Create the window
	Glut.createWindow("OpenGL ES on V8!  \\(^_^)/");
	
    if (!init())
	return;
    
    Glut.mainLoop();
}

main();