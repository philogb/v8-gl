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
 Gles.PixelStorei(Gles.UNPACK_ALIGNMENT, 1);

 // Generate a texture object.  genTextures always returns
 // an array, and we're only interested in the first element
 textureId = Gles.GenTextures(1)[0];

 // Bind the texture object
 Gles.BindTexture(Gles.TEXTURE_2D, textureId);

 // Load the pixels into the texture object
 Gles.TexImage2D(Gles.TEXTURE_2D,  // target
		  0,		  // level
		  Gles.RGB,	  // interal format
		  2, 2,		  // width, height
		  0,		  // border
		  Gles.RGB,	  // format
		  Gles.UNSIGNED_BYTE, // type
		  pixels);	  // pixels array

 // set up filtering modes
 Gles.TexParameteri(Gles.TEXTURE_2D, Gles.TEXTURE_MIN_FILTER, Gles.NEAREST);
 Gles.TexParameteri(Gles.TEXTURE_2D, Gles.TEXTURE_MAG_FILTER, Gles.NEAREST);

 return textureId;
}


function init()
{
    // Create the linked program object
    userData.programObject = getProgram("shaders/ch9-texture2d-vshader.sl", Gles.VERTEX_SHADER, 
    		"shaders/ch9-texture2d-fshader.sl", Gles.FRAGMENT_SHADER);
    if (userData.programObject == 0)
	return false;

    // Get the attribute locations
    userData.positionLoc = Gles.GetAttribLocation(userData.programObject, "a_position");
    userData.texCoordLoc = Gles.GetAttribLocation(userData.programObject, "a_texCoord");

    // Get the sampler location
    userData.samplerLoc = Gles.GetUniformLocation(userData.programObject, "s_texture");

    // Load the texture
    userData.textureId = createSimpleTexture2D();

    // set up the clear color to clear to transparent black
    Gles.ClearColor (0, 0, 0, 0);

    Glut.DisplayFunc(draw);
    
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

     // bind the texture
     Gles.ActiveTexture(Gles.TEXTURE0);
     Gles.BindTexture(Gles.TEXTURE_2D, userData.textureId);

     // and set the sampler to texture unit 0
     Gles.Uniform1i(userData.samplerLoc, 0);

     // and finally do the draw
     Gles.DrawElements(Gles.TRIANGLES, indices.length, Gles.UNSIGNED_SHORT, indices);

    // swap buffers to display
    Glut.SwapBuffers();
}

function main() {
	//Initialize Glut
	Glut.Init();
	Glut.InitDisplayMode(Glut.DOUBLE | Glut.RGB | Glut.DEPTH);
	Glut.InitWindowSize(800, 600);
	//Create the window
	Glut.CreateWindow("v8-gl Texture2D");

    if (!init())
	return;
    
    Glut.MainLoop();
}

main();
