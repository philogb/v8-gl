//load common code
load("common.js", "shaderutil.js");

// an object we'll use to store shaders, textures, etc. on as we create them
var userData = { };

//
// Create a 2D texture from the given HTML image
//
function textureFromImage(img)
{
    var textureId = Gles.genTextures(1)[0];

    Gles.bindTexture(Gles.TEXTURE_2D, textureId);

    // Load it.  The dimensions, format, etc. are all read from the image.
    Gles.texImage2DFile(img);

    // Set up filtering and wrap modes
    Gles.texParameteri(Gles.TEXTURE_2D, Gles.TEXTURE_MIN_FILTER, Gles.NEAREST);
    Gles.texParameteri(Gles.TEXTURE_2D, Gles.TEXTURE_MAG_FILTER, Gles.NEAREST);

    Gles.texParameteri(Gles.TEXTURE_2D, Gles.TEXTURE_WRAP_S, Gles.CLAMP_TO_EDGE);
    Gles.texParameteri(Gles.TEXTURE_2D, Gles.TEXTURE_WRAP_T, Gles.CLAMP_TO_EDGE);

    return textureId;
}


function init()
{

	// Create the linked program object
    userData.programObject = getProgram("shaders/ch10-vshader.sl", 
    		                                "shaders/ch10-fshader.sl");
    if (userData.programObject == 0)
      return false;

    // Get the attribute locations
    userData.positionLoc = Gles.getAttribLocation(userData.programObject, "a_position");
    userData.texCoordLoc = Gles.getAttribLocation(userData.programObject, "a_texCoord");

    // Get the sampler locations
    userData.baseMapLoc = Gles.getUniformLocation(userData.programObject, "s_baseMap");
    userData.lightMapLoc = Gles.getUniformLocation(userData.programObject, "s_lightMap");

    // Load the textures; the textures were loaded earlier in main()
    userData.baseMapTexId = textureFromImage("assets/basemap.png");
    userData.lightMapTexId = textureFromImage("assets/lightmap.png");

    // set up the clear color to clear to transparent black
    Gles.clearColor (0, 0, 0, 0);
    
    Glut.displayFunc(draw);
    
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
    Gles.viewport (0, 0, 800, 600);

    // clear
    Gles.clear (Gles.COLOR_BUFFER_BIT);

    // use the program
    Gles.useProgram (userData.programObject);

    // load the vertex positions
    Gles.vertexAttribPointer (userData.positionLoc, 3, Gles.FLOAT, false, 0, vVertices);

    // load the texture coordinates
    Gles.vertexAttribPointer (userData.texCoordLoc, 2, Gles.FLOAT, false, 0, vTexCoords);

    Gles.enableVertexAttribArray (userData.positionLoc);
    Gles.enableVertexAttribArray (userData.texCoordLoc);

    // bind the base map
    Gles.activeTexture(Gles.TEXTURE0);
    Gles.bindTexture(Gles.TEXTURE_2D, userData.baseMapTexId);

    // and set the base map sampler to texture unit 0
    Gles.uniform1i(userData.baseMapLoc, 0);

    // bind the light map
    Gles.activeTexture(Gles.TEXTURE1);
    Gles.bindTexture(Gles.TEXTURE_2D, userData.lightMapTexId);

    // and set the light map sampler to texture unit 1
    Gles.uniform1i(userData.lightMapLoc, 1);

    // and finally do the draw
    Gles.drawElements(Gles.TRIANGLES, indices.length, Gles.UNSIGNED_SHORT, indices);

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
