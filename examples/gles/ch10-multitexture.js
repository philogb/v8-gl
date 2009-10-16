//load common code
load("common.js", "shaderutil.js");

// an object we'll use to store shaders, textures, etc. on as we create them
var userData = { };

//
// Create a 2D texture from the given HTML image
//
function textureFromImage(img)
{
    var textureId = Gles.GenTextures(1)[0];

    Gles.BindTexture(Gles.TEXTURE_2D, textureId);

    // Load it.  The dimensions, format, etc. are all read from the image.
    Gles.TexImage2DFile(img);

    // Set up filtering and wrap modes
    Gles.TexParameteri(Gles.TEXTURE_2D, Gles.TEXTURE_MIN_FILTER, Gles.NEAREST);
    Gles.TexParameteri(Gles.TEXTURE_2D, Gles.TEXTURE_MAG_FILTER, Gles.NEAREST);

    Gles.TexParameteri(Gles.TEXTURE_2D, Gles.TEXTURE_WRAP_S, Gles.CLAMP_TO_EDGE);
    Gles.TexParameteri(Gles.TEXTURE_2D, Gles.TEXTURE_WRAP_T, Gles.CLAMP_TO_EDGE);

    return textureId;
}


function init()
{

	// Create the linked program object
    userData.programObject = getProgram("shaders/ch10-vshader.sl", Gles.VERTEX_SHADER, 
    		"shaders/ch10-fshader.sl", Gles.FRAGMENT_SHADER);
    if (userData.programObject == 0)
	return false;

    // Get the attribute locations
    userData.positionLoc = Gles.GetAttribLocation(userData.programObject, "a_position");
    userData.texCoordLoc = Gles.GetAttribLocation(userData.programObject, "a_texCoord");

    // Get the sampler locations
    userData.baseMapLoc = Gles.GetUniformLocation(userData.programObject, "s_baseMap");
    userData.lightMapLoc = Gles.GetUniformLocation(userData.programObject, "s_lightMap");

    // Load the textures; the textures were loaded earlier in main()
    userData.baseMapTexId = textureFromImage("assets/basemap.png");
    userData.lightMapTexId = textureFromImage("assets/lightmap.png");

    // set up the clear color to clear to transparent black
    Gles.ClearColor (0, 0, 0, 0);
    
    Glut.DisplayFunc(draw);
    
    return true;
}

//
// Draw a rectangle using a pair of triangles and the program
// created in init()
//
function draw()
{
    var vVertices = [
        -0.5,  0.5, 0.0,  // Position 0
        -0.5, -0.5, 0.0,  // Position 1
         0.5, -0.5, 0.0,  // Position 2
         0.5,  0.5, 0.0   // Position 3
    ];

    var vTexCoords = [
        0.0,  0.0,        // TexCoord 0
        0.0,  1.0,        // TexCoord 1
        1.0,  1.0,        // TexCoord 2
        1.0,  0.0         // TexCoord 3
    ];

    var indices = [ 0, 1, 2, 0, 2, 3 ];

    // set up the viewport
    Gles.Viewport (0, 0, 800, 600);

    // clear
    Gles.Clear (Gles.COLOR_BUFFER_BIT);

    // use the program
    Gles.UseProgram (userData.programObject);

    // load the vertex positions
    Gles.VertexAttribPointer (userData.positionLoc, 3, Gles.FLOAT, false, 0, vVertices);

    // load the texture coordinates
    Gles.VertexAttribPointer (userData.texCoordLoc, 2, Gles.FLOAT, false, 0, vTexCoords);

    Gles.EnableVertexAttribArray (userData.positionLoc);
    Gles.EnableVertexAttribArray (userData.texCoordLoc);

    // bind the base map
    Gles.ActiveTexture(Gles.TEXTURE0);
    Gles.BindTexture(Gles.TEXTURE_2D, userData.baseMapTexId);

    // and set the base map sampler to texture unit 0
    Gles.Uniform1i(userData.baseMapLoc, 0);

    // bind the light map
    Gles.ActiveTexture(Gles.TEXTURE1);
    Gles.BindTexture(Gles.TEXTURE_2D, userData.lightMapTexId);

    // and set the light map sampler to texture unit 1
    Gles.Uniform1i(userData.lightMapLoc, 1);

    // and finally do the draw
    Gles.DrawElements(Gles.TRIANGLES, indices.length, Gles.UNSIGNED_SHORT, indices);

    // swap buffers to display
    Glut.SwapBuffers();
}

function main()
{
	//Initialize Glut
	Glut.Init();
	Glut.InitDisplayMode(Glut.DOUBLE | Glut.RGB | Glut.DEPTH);
	Glut.InitWindowSize(800, 600);
	//Create the window
	Glut.CreateWindow("v8-gl Textures");

	if (!init())
	    return;
    
    Glut.MainLoop();
}

main();
