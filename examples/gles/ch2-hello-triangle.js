// an object we'll use to store shaders, textures, etc. on as we create them
var userData = { };

function loadShader(shaderType, shaderSource) {
    // Create the shader object
    var shader = Gles.createShader(shaderType);
    
    if (shader == 0) return 0;

    // Load the shader source
    Gles.ShaderSource(shader, shaderSource);

    // Compile the shader
    Gles.CompileShader(shader);

    // Check the compile status
    var compiled = Gles.GetShaderParameter(shader, Gles.COMPILE_STATUS);
    if (!compiled) {
		// Something went wrong during compilation; get the error
		var error = Gles.GetShaderInfoLog(shader);
		Gles.DeleteShader(shader);
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
    var programObject = Gles.CreateProgram();
    if (programObject == 0)
	return false;

    // Attach our two shaders to the program
    Gles.AttachShader (programObject, vertexShader);
    Gles.AttachShader (programObject, fragmentShader);

    // Bind "vPosition" to attribute 0
    Gles.BindAttribLocation (programObject, 0, "vPosition");

    // Link the program
    Gles.LinkProgram (programObject);

    // Check the link status
    var linked = Gles.GetProgramParameter (programObject, Gles.LINK_STATUS);
    if (!linked) {
		// something went wrong with the link
		var error = Gles.GetProgramInfoLog (programObject);
	
		Gles.DeleteProgram(programObject);
		Gles.DeleteProgram(fragmentShader);
		Gles.DeleteProgram(vertexShader);
	
		return false;
    }

    userData.programObject = programObject;

    // set up the clear color to clear to transparent black
    Gles.ClearColor (0, 0, 0, 0);

	//Initialize Glut
	Glut.Init();
	Glut.InitDisplayMode(Glut.DOUBLE | Glut.RGB | Glut.DEPTH);
	Glut.InitWindowSize(800, 600);
	
	//Create the window
	Glut.CreateWindow("OpenGL ES on V8!  \(^_^)/");
    
    return true;
}

// Actually draw the triangle, using the program created in init()
function draw() {
    var vertices = [  0.0,  0.5,  0.0,
				     -0.5, -0.5,  0.0,
				      0.5, -0.5,  0.0  ];

    // Set up the viewport
    Gles.Viewport(0, 0, 800, 600);

    // Clear the color buffer
    Gles.Clear(Gles.COLOR_BUFFER_BIT);

    // Use the program object we created in init()
    Gles.UseProgram(userData.programObject);

    // Load the vertex data
    Gles.VertexAttribPointer(0, 3, Gles.FLOAT, false, 0, vertices);
    Gles.EnableVertexAttribArray(0);

    // Do the draw, as triangles
    Gles.DrawArrays(Gles.TRIANGLES, 0, 3);

    // Finally do the swap to display what we just drew
    Glut.SwapBuffers();
}

function main() 
{
    if (!init())
	return;

    // our scene is static, so we only need to draw once
    draw();
}