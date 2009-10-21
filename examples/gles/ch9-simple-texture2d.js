//load common code.
load("common.js", "shaderutil.js");

// an object we'll use to store shaders, textures, etc. on as we create them
var userData = { };

//
//Create a simple 2x2 texture image with four different colors
//
function createSimpleTexture2D()
{
 var textureId;

 // 2x2 Image, 3 bytes per pixel (RGB)
 var pixels = [
	255, 0, 0,   // Red
  0, 255, 0,   // Green
	0, 0, 255,   // Blue
	255, 255, 0  // Yellow
 ];

 // Use tightly packed data
 Gles.pixelStorei(Gles.UNPACK_ALIGNMENT, 1);

 // Generate a texture object.  genTextures always returns
 // an array, and we're only interested in the first element
 textureId = Gles.genTextures(1)[0];

 // Bind the texture object
 Gles.bindTexture(Gles.TEXTURE_2D, textureId);

 // Load the pixels into the texture object
 Gles.texImage2D(Gles.TEXTURE_2D,  // target
		  0,		  // level
		  Gles.RGB,	  // interal format
		  2, 2,		  // width, height
		  0,		  // border
		  Gles.RGB,	  // format
		  Gles.UNSIGNED_BYTE, // type
		  pixels);	  // pixels array

 // set up filtering modes
 Gles.texParameteri(Gles.TEXTURE_2D, Gles.TEXTURE_MIN_FILTER, Gles.NEAREST);
 Gles.texParameteri(Gles.TEXTURE_2D, Gles.TEXTURE_MAG_FILTER, Gles.NEAREST);

 return textureId;
}


function init()
{
    // Create the linked program object
    userData.programObject = getProgram("shaders/ch9-texture2d-vshader.sl", 
    		                                "shaders/ch9-texture2d-fshader.sl");
    if (userData.programObject == 0)
      return false;

    // Get the attribute locations
    userData.positionLoc = Gles.getAttribLocation(userData.programObject, "a_position");
    userData.texCoordLoc = Gles.getAttribLocation(userData.programObject, "a_texCoord");

    // Get the sampler location
    userData.samplerLoc = Gles.getUniformLocation(userData.programObject, "s_texture");

    // Load the texture
    userData.textureId = createSimpleTexture2D();

    // set up the clear color to clear to transparent black
    Gles.clearColor (0, 0, 0, 0);

    Glut.displayFunc(draw);
    
    return true;
}

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

     // bind the texture
     Gles.activeTexture(Gles.TEXTURE0);
     Gles.bindTexture(Gles.TEXTURE_2D, userData.textureId);

     // and set the sampler to texture unit 0
     Gles.uniform1i(userData.samplerLoc, 0);

     // and finally do the draw
     Gles.drawElements(Gles.TRIANGLES, indices.length, Gles.UNSIGNED_SHORT, indices);

    // swap buffers to display
    Glut.swapBuffers();
}

function main() {
	//Initialize Glut
	Glut.init();
	Glut.initDisplayMode(Glut.DOUBLE | Glut.RGB | Glut.DEPTH);
	Glut.initWindowSize(800, 600);
	//Create the window
	Glut.createWindow("v8-gl Texture2D");

  if (!init())
    return;
    
  Glut.mainLoop();
}

main();
