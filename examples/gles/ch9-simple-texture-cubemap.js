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
    var textureId = Gles.genTextures(1)[0];

    // Bind the texture object
    Gles.bindTexture(Gles.TEXTURE_CUBE_MAP, textureId);

    // Load each cube face
    Gles.texImage2D(Gles.TEXTURE_CUBE_MAP_POSITIVE_X, 0, Gles.RGB, 1, 1, 0, Gles.RGB, Gles.UNSIGNED_BYTE, [ 255, 0, 0 ]);
    Gles.texImage2D(Gles.TEXTURE_CUBE_MAP_NEGATIVE_X, 0, Gles.RGB, 1, 1, 0, Gles.RGB, Gles.UNSIGNED_BYTE, [ 0, 255, 0 ]);
    Gles.texImage2D(Gles.TEXTURE_CUBE_MAP_POSITIVE_Y, 0, Gles.RGB, 1, 1, 0, Gles.RGB, Gles.UNSIGNED_BYTE, [ 0, 0, 255 ]);
    Gles.texImage2D(Gles.TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, Gles.RGB, 1, 1, 0, Gles.RGB, Gles.UNSIGNED_BYTE, [ 255, 255, 0 ]);
    Gles.texImage2D(Gles.TEXTURE_CUBE_MAP_POSITIVE_Z, 0, Gles.RGB, 1, 1, 0, Gles.RGB, Gles.UNSIGNED_BYTE, [ 255, 0, 255 ]);
    Gles.texImage2D(Gles.TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, Gles.RGB, 1, 1, 0, Gles.RGB, Gles.UNSIGNED_BYTE, [ 255, 255, 255 ]);

    // set up filtering modes
    Gles.texParameteri(Gles.TEXTURE_CUBE_MAP, Gles.TEXTURE_MIN_FILTER, Gles.NEAREST);
    Gles.texParameteri(Gles.TEXTURE_CUBE_MAP, Gles.TEXTURE_MAG_FILTER, Gles.NEAREST);

    return textureId;
}

function init()
{
    // Create the linked program object
    userData.programObject = getProgram("shaders/ch9-vshader.sl",
    		                                "shaders/ch9-fshader.sl");
    if (userData.programObject == 0)
      return false;

    // Get the attribute locations
    userData.positionLoc = Gles.getAttribLocation(userData.programObject, "a_position");
    userData.normalLoc = Gles.getAttribLocation(userData.programObject, "a_normal");

    // Get the sampler location
    userData.samplerLoc = Gles.getUniformLocation(userData.programObject, "s_texture");

    // Load the texture
    userData.textureId = createSimpleTextureCube();

    // Create a sphere object
    userData.obj = esGenSphere(20, 0.75);

    // set up the clear color to clear to transparent black
    Gles.clearColor (0, 0, 0, 0);

    Glut.displayFunc(draw);
    return true;
}

//
// Draw the sphere we created in init()
//
function draw()
{
    // set up the viewport
    Gles.viewport (0, 0, 800, 600);

    // clear
    Gles.clear (Gles.COLOR_BUFFER_BIT);
    
    Gles.cullFace(Gles.BACK);

    Gles.enable(Gles.CULL_FACE);
    // use the program
    Gles.useProgram (userData.programObject);

    // load the vertex positions
    Gles.vertexAttribPointer (userData.positionLoc, 3, Gles.FLOAT, false, 0, userData.obj.vertices);

    // load the texture coordinates
    Gles.vertexAttribPointer (userData.normalLoc, 3, Gles.FLOAT, false, 0, userData.obj.normals);

    Gles.enableVertexAttribArray (userData.positionLoc);
    Gles.enableVertexAttribArray (userData.normalLoc);

    // bind the texture
    Gles.activeTexture(Gles.TEXTURE0);
    Gles.bindTexture(Gles.TEXTURE_CUBE_MAP, userData.textureId);

    // and set the sampler to texture unit 0
    Gles.uniform1i(userData.samplerLoc, 0);

    // and finally do the draw
    Gles.drawElements(Gles.TRIANGLES, userData.obj.indices.length, Gles.UNSIGNED_SHORT, userData.obj.indices);

    // swap buffers to display
    Glut.swapBuffers();
}

function main()
{
	//Initialize Glut
	Glut.init();
	Glut.initDisplayMode(Glut.DOUBLE | Glut.RGB | Glut.DEPTH);
	Glut.initWindowSize(800, 600);
	//Create the window
	Glut.createWindow("v8-gl Textures");

    if (!init())
	return;
    
    Glut.mainLoop();

}

main();
