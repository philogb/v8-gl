//load libraries
load("common.js", "shaderutil.js");

// an object we'll use to store shaders, textures, etc. on as we create them
var userData = { };

//
// Create a simple cubemap texture
//
function createSimpleTextureCube()
{
    // Generate a texture object.  genTextures always returns
    // an array, and we're only interested in the first element
    var textureId = Gles.GenTextures(1)[0];

    // Bind the texture object
    Gles.BindTexture(Gles.TEXTURE_CUBE_MAP, textureId);

    // Load each cube face
    Gles.TexImage2D(Gles.TEXTURE_CUBE_MAP_POSITIVE_X, 0, Gles.RGB, 1, 1, 0, Gles.RGB, Gles.UNSIGNED_BYTE, [ 255, 0, 0 ]);
    Gles.TexImage2D(Gles.TEXTURE_CUBE_MAP_NEGATIVE_X, 0, Gles.RGB, 1, 1, 0, Gles.RGB, Gles.UNSIGNED_BYTE, [ 0, 255, 0 ]);
    Gles.TexImage2D(Gles.TEXTURE_CUBE_MAP_POSITIVE_Y, 0, Gles.RGB, 1, 1, 0, Gles.RGB, Gles.UNSIGNED_BYTE, [ 0, 0, 255 ]);
    Gles.TexImage2D(Gles.TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, Gles.RGB, 1, 1, 0, Gles.RGB, Gles.UNSIGNED_BYTE, [ 255, 255, 0 ]);
    Gles.TexImage2D(Gles.TEXTURE_CUBE_MAP_POSITIVE_Z, 0, Gles.RGB, 1, 1, 0, Gles.RGB, Gles.UNSIGNED_BYTE, [ 255, 0, 255 ]);
    Gles.TexImage2D(Gles.TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, Gles.RGB, 1, 1, 0, Gles.RGB, Gles.UNSIGNED_BYTE, [ 255, 255, 255 ]);

    // set up filtering modes
    Gles.TexParameteri(Gles.TEXTURE_CUBE_MAP, Gles.TEXTURE_MIN_FILTER, Gles.NEAREST);
    Gles.TexParameteri(Gles.TEXTURE_CUBE_MAP, Gles.TEXTURE_MAG_FILTER, Gles.NEAREST);

    return textureId;
}

function init()
{
    // Create the linked program object
    userData.programObject = getProgram("shaders/ch9-vshader.sl", Gles.VERTEX_SHADER, 
    		"shaders/ch9-fshader.sl", Gles.FRAGMENT_SHADER);
    if (userData.programObject == 0)
	return false;

    // Get the attribute locations
    userData.positionLoc = Gles.GetAttribLocation(userData.programObject, "a_position");
    userData.normalLoc = Gles.GetAttribLocation(userData.programObject, "a_normal");

    // Get the sampler location
    userData.samplerLoc = Gles.GetUniformLocation(userData.programObject, "s_texture");

    // Load the texture
    userData.textureId = createSimpleTextureCube();

    // Create a sphere object
    userData.obj = esGenSphere(20, 0.75);

    // set up the clear color to clear to transparent black
    Gles.ClearColor (0, 0, 0, 0);

    Glut.DisplayFunc(draw);
    return true;
}

//
// Draw the sphere we created in init()
//
function draw()
{
    // set up the viewport
    Gles.Viewport (0, 0, 800, 600);

    // clear
    Gles.Clear (Gles.COLOR_BUFFER_BIT);
    
    Gles.CullFace(Gles.BACK);

    Gles.Enable(Gles.CULL_FACE);
    // use the program
    Gles.UseProgram (userData.programObject);

    // load the vertex positions
    Gles.VertexAttribPointer (userData.positionLoc, 3, Gles.FLOAT, false, 0, userData.obj.vertices);

    // load the texture coordinates
    Gles.VertexAttribPointer (userData.normalLoc, 3, Gles.FLOAT, false, 0, userData.obj.normals);

    Gles.EnableVertexAttribArray (userData.positionLoc);
    Gles.EnableVertexAttribArray (userData.normalLoc);

    // bind the texture
    Gles.ActiveTexture(Gles.TEXTURE0);
    Gles.BindTexture(Gles.TEXTURE_CUBE_MAP, userData.textureId);

    // and set the sampler to texture unit 0
    Gles.Uniform1i(userData.samplerLoc, 0);

    // and finally do the draw
    Gles.DrawElements(Gles.TRIANGLES, userData.obj.indices.length, Gles.UNSIGNED_SHORT, userData.obj.indices);

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
