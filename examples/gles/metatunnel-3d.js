// This is a hacked up version of vlad's port of FRequency's metatunnel.
//   http://people.mozilla.com/~vladimir/misc/metatunnel-3d.html

var gl = Gles;

gl.getShaderParameter = gl.GetShaderiv;
gl.getProgramParameter = gl.GetProgramiv;

// Bind Gles.BlahBlah to Gles.blahBlah.
for (name in Gles) {
  var x = Gles[name];
  if (typeof x === 'function') {
    var lc = name[0].toLowerCase() + name.substr(1);
    Gles[lc] = x;
  }
}

w = 740; h = 480;

function draw() {
  gl.viewport(0, 0, w, h);
  gl.useProgram(p);

  // Store our attrib data in a VBO.
  //gl.bindBuffer(gl.GL_ARRAY_BUFFER, buffers[0]);
  //gl.bufferData(gl.GL_ARRAY_BUFFER, 

  gl.vertexAttribPointer(0, 3, gl.FLOAT, false, 0, [ -1, 1, 0, 1, 1, 0, -1, -1, 0, 1, -1, 0 ]);
  gl.enableVertexAttribArray(0);

   var n = Date.now();
    r = n & 0xff;
    g = (n>>8) & 0xff;
    b = (n>>16) & 0xff;
    gl.uniform4fv(0, 1, [r/255.0, g/255.0, b/255.0, 1.0]);
    gl.drawArrays(gl.TRIANGLE_STRIP, 0, 4);

    Glut.SwapBuffers();

}

//Initialize Glut
Glut.Init();
Glut.InitDisplayMode(Glut.DOUBLE | Glut.RGB | Glut.DEPTH);
Glut.InitWindowSize(w, h);

//Create the window
Glut.CreateWindow("OpenGL on V8 baby!");

 var fragment_shader_source = "\n"
+       "uniform vec4 in_color;\n"
+	"vec2 v=(gl_FragCoord.xy-vec2(400,300))/vec2(400,300);\n"
+	"float w=dot(in_color.xyz,vec3(1.0,256.0,65536.0))*.25;\n"
+	"const float s=0.4;\n"

+	"float obj(vec3 pos){\n"
+		"float final=1.0;\n"
+		"final*=distance(pos,vec3(cos(w)+sin(w*0.2),0.3,2.0+cos(w*0.5)*0.5));\n"
+		"final*=distance(pos,vec3(-cos(w*0.7),0.3,2.0+sin(w*0.5)));\n"
+		"final*=distance(pos,vec3(-sin(w*0.2)*0.5,sin(w),2.0));\n"
+		"final *=cos(pos.y)*cos(pos.x)-0.1-cos(pos.z*7.+w*7.)*cos(pos.x*3.)*cos(pos.y*4.)*0.1;\n"
+		"return final;\n"
+	"}\n"

+	"void main(){vec3 o=vec3(v.x,v.y*1.25,0.0);\n"
+		"vec3 d=vec3(v.x+cos(w)*.3,v.y,1.0)/64.0;\n"
+		"vec4 color=vec4(0.0);\n"
+		"float t=0.0;\n"
+		"for(int i=0;i<75;i++) {\n"
+			"if(obj(o+d*t)<s){\n"
+				"t-=5.0;\n"
+				"for(int j=0;j<5;j++){\n"
+					"if(obj(o+d*t)<s){\n"
+						"break;\n"
+					"}\n"
+					"t+=1.0;\n"
+				"}\n"
+				"vec3 e=vec3(0.01,.0,.0);\n"
+				"vec3 n=vec3(0.0);\n"
+				"n.x=obj(o+d*t)-obj(vec3(o+d*t+e.xyy));\n"
+				"n.y=obj(o+d*t)-obj(vec3(o+d*t+e.yxy));\n"
+				"n.z=obj(o+d*t)-obj(vec3(o+d*t+e.yyx));\n"
+				"n=normalize(n);\n"
+				"color+=max(dot(vec3(0.0,0.0,-0.5),n),0.0)+max(dot(vec3(0.0,-0.5,0.5),n),0.0)*0.5;break;\n"
+			"}\n"
+			"t+=5.0;\n"
+		"}\n"
+		"gl_FragColor=color+vec4(0.1,0.2,0.5,1.0)*(t*0.025);\n"
+	"}";

  var vertex_shader_source =
	"attribute vec4 pos; void main() { gl_Position = vec4(pos.x * float(" + w/2 + "), pos.y * float(" + h/2 + "), 0.0, 1.0); }";

  //var buffers = gl.genBuffers(1);

  var vs = gl.createShader(gl.VERTEX_SHADER);
  gl.shaderSource(vs, vertex_shader_source);
  gl.compileShader(vs);

  var fs = gl.createShader(gl.FRAGMENT_SHADER);
  gl.shaderSource(fs, fragment_shader_source);
  gl.compileShader(fs);
  if (gl.getShaderParameter(fs, gl.COMPILE_STATUS) != 1) {
    var error = gl.getShaderInfoLog(fs);
    return;
  }

  p = gl.createProgram();
  gl.attachShader(p, vs);
  gl.attachShader(p, fs);
  gl.linkProgram(p);

  var linked = gl.getProgramParameter(p, gl.LINK_STATUS);
  if (!linked) {
    var error = gl.getProgramInfoLog(p);
    return 0;
  }
  
  Glut.DisplayFunc(draw);
  //Set timeout callback
  Glut.TimerFunc(25, function() {
    Glut.PostRedisplay();
    Glut.TimerFunc(25, arguments.callee, 0);
  }, 0);

  Glut.MainLoop();
