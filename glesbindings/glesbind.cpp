
#include "glesbind.h"

#if defined(V8_GL_USE_GLEW)
#include "GL/glew.h"
#include "glew_desktop_shim.h"
#elif defined(__APPLE__)
#include <OpenGL/OpenGL.h>
#else
#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
// If we're running on desktop OpenGL, some ES 2.0 constants don't exist, or
// are under a name with EXT in them, etc.
#include "gles_desktop_shim.h"
#endif

using namespace v8;


Persistent<Object> GlesFactory::self_;
Persistent<Context> GlesFactory::gles_persistent_context;
// glGenBuffers uses an output parameter to return an array of ints.
Handle<Value> GLESglGenBuffersCallback(const Arguments& args) {
  if (args.Length() != 1)
	return v8::Undefined();

  HandleScope handle_scope;
  GLsizei num_buffers = args[0]->Int32Value();

  GLuint* buffers = new GLuint[num_buffers];
  glGenBuffers(num_buffers, buffers);

  // TODO(deanm): There should be a way to initialize the array faster.
  Local<Array> res = Array::New(num_buffers);
  for (int i = 0; i < num_buffers; ++i) {
    res->Set(Integer::New(i), Integer::New(buffers[i]));
  }

  delete[] buffers;

  return handle_scope.Close(res);
}


Handle<Value> GLESglGenRenderbuffersCallback(const Arguments& args) {
	  if (args.Length() != 1)
		return v8::Undefined();

	  HandleScope handle_scope;
	  GLsizei num_buffers = args[0]->Int32Value();

	  GLuint* buffers = new GLuint[num_buffers];
	  glGenRenderbuffers(num_buffers, buffers);

	  // TODO(deanm): There should be a way to initialize the array faster.
	  Local<Array> res = Array::New(num_buffers);
	  for (int i = 0; i < num_buffers; ++i) {
	    res->Set(Integer::New(i), Integer::New(buffers[i]));
	  }

	  delete[] buffers;

	  return handle_scope.Close(res);
}


Handle<Value> GLESglGenFramebuffersCallback(const Arguments& args) {
	  if (args.Length() != 1)
		return v8::Undefined();

	  HandleScope handle_scope;
	  GLsizei num_buffers = args[0]->Int32Value();

	  GLuint* buffers = new GLuint[num_buffers];
	  glGenFramebuffers(num_buffers, buffers);

	  // TODO(deanm): There should be a way to initialize the array faster.
	  Local<Array> res = Array::New(num_buffers);
	  for (int i = 0; i < num_buffers; ++i) {
	    res->Set(Integer::New(i), Integer::New(buffers[i]));
	  }

	  delete[] buffers;

	  return handle_scope.Close(res);
}

Handle<Value> GLESglGenTexturesCallback(const Arguments& args) {
  if (args.Length() != 1)
	return v8::Undefined();

  HandleScope handle_scope;
  GLsizei num_textures = args[0]->Int32Value();

  GLuint* textures = new GLuint[num_textures];
  glGenTextures(num_textures, textures);

  Local<Array> res = Array::New(num_textures);
  for (int i = 0; i < num_textures; ++i) {
    res->Set(Integer::New(i), Integer::New(textures[i]));
  }

  delete[] textures;

  return handle_scope.Close(res);
}


// glGetShaderiv uses an output parameter to return an int.
Handle<Value> GLESglGetShaderivCallback(const Arguments& args) {
  if (args.Length() < 2)
    return v8::Undefined();
  HandleScope handle_scope;
  unsigned int arg0 = args[0]->Uint32Value();
  int arg1 = args[1]->IntegerValue();

  int out;
  glGetShaderiv((GLuint) arg0, (GLenum) arg1, (GLint*)&out);
  v8::Local<v8::Value> val = v8::Integer::New(out);
  return handle_scope.Close(val);
}


// We expect to be called with a shader id and a single string.
Handle<Value> GLESglShaderSourceCallback(const Arguments& args) {
  if (args.Length() != 2)
    return v8::Undefined();

  HandleScope handle_scope;
  GLuint shader_id = args[0]->Uint32Value();
  // GLSL source is defined as an ASCII subset.
  v8::String::AsciiValue code_ascii(args[1]);
  if (!*code_ascii)
    return v8::Undefined();

  const char* code_str = *code_ascii;
  GLsizei code_len = code_ascii.length();
  glShaderSource(shader_id, 1, &code_str, &code_len);

  Handle<Object> res(GlesFactory::self_);
  return res;
}


Handle<Value> GLESglVertexAttribPointerCallback(const Arguments& args) {
  if (args.Length() != 6)
    return v8::Undefined();

  HandleScope handle_scope;

  unsigned int index = args[0]->Uint32Value();
  unsigned int size = args[1]->Uint32Value();
  unsigned int type = args[2]->Uint32Value();
  unsigned int normalized = args[3]->Uint32Value();
  int stride = args[4]->IntegerValue();
  void* ans;

  if(args[5]->IsArray()) {
	  Handle<Array> data = Handle<Array>::Cast(args[5]);
	  //I guess most of these types could be thrown away
	  switch(type) {
//		  case GL_BYTE:
//			  GLbyte* arg1 = new  GLbyte[data->Length()];
//			  for (unsigned j = 0; j < data->Length(); j++) {
//			      Handle<Value> arg(data->Get(Integer::New(j)));
//			      arg1[j] = (GLbyte)arg->IntegerValue();
//			  }
//			  ans = (void *)arg1;
//			  break;
//
//		  case GL_UNSIGNED_BYTE:
//			  GLubyte* arg1 = new  GLubyte[data->Length()];
//			  for (unsigned j = 0; j < data->Length(); j++) {
//			      Handle<Value> arg(data->Get(Integer::New(j)));
//			      arg1[j] = (GLubyte)arg->Uint32Value();
//			  }
//			  ans = (void *)arg1;
//			  break;

		  case GL_SHORT:
		  {
			  GLshort* arg1 = new  GLshort[data->Length()];
			  for (unsigned j = 0; j < data->Length(); j++) {
			      Handle<Value> arg(data->Get(Integer::New(j)));
			      arg1[j] = (GLshort)arg->IntegerValue();
			  }
			  ans = (void *)arg1;
		  }
		  break;
		  case GL_UNSIGNED_SHORT:
		  {
			  GLushort* arg1 = new  GLushort[data->Length()];
			  for (unsigned j = 0; j < data->Length(); j++) {
			      Handle<Value> arg(data->Get(Integer::New(j)));
			      arg1[j] = (GLushort)arg->Uint32Value();
			  }
			  ans = (void *)arg1;
		  }
		  break;

		  case GL_FLOAT:
		  {
			  GLfloat* arg1 = new  GLfloat[data->Length()];
			  for (unsigned j = 0; j < data->Length(); j++) {
			      Handle<Value> arg(data->Get(Integer::New(j)));
			      arg1[j] = (GLfloat)arg->NumberValue();
			  }
			  ans = (void *)arg1;
		  }
		  break;

//		  case GL_FIXED:
//		  {
//			  GLfixed* arg1 = new  GLfixed[data->Length()];
//			  for (unsigned j = 0; j < data->Length(); j++) {
//			      Handle<Value> arg(data->Get(Integer::New(j)));
//			      arg1[j] = (GLfixed)arg->IntegerValue();
//			  }
//			  ans = (void *)arg1;
//		  }
//		  break;

		  default: return v8::Undefined();
	  }
  } else {
	  ans = (void *)args[5]->IntegerValue();
  }

  glVertexAttribPointer((GLuint)index,
		  (GLint)size,
		  (GLenum)type,
		  (GLboolean)normalized,
		  (GLsizei)stride,
		  (const void*)ans);

  //should I delete[] ans?

  Handle<Object> res(GlesFactory::self_);
  return res;
}

Handle<Value> GLESglDrawElementsCallback(const Arguments& args) {
  if (args.Length() != 4)
    return v8::Undefined();

  HandleScope handle_scope;
  unsigned int mode  = args[0]->Uint32Value();
  int count = args[1]->IntegerValue();
  unsigned int type  = args[2]->Uint32Value();
  void* ans;

  if(args[3]->IsArray()) {
	  Handle<Array> data = Handle<Array>::Cast(args[3]);
	  switch(type) {
		  case GL_UNSIGNED_SHORT:
		  {
			  GLushort* arg1 = new  GLushort[data->Length()];
			  for (unsigned j = 0; j < data->Length(); j++) {
			      Handle<Value> arg(data->Get(Integer::New(j)));
			      arg1[j] = (GLushort)arg->Uint32Value();
			  }
			  ans = (void *)arg1;
		  }
		  break;

		  default: return v8::Undefined();
	  }
  } else {
	  ans = (void *)args[3]->IntegerValue();
  }

  glDrawElements((GLenum)mode,
		  (GLsizei)count,
		  (GLenum)type,
		  (const GLvoid*)ans);

  //should I delete[] ans?

  Handle<Object> res(GlesFactory::self_);
  return res;
}

//Accepts GL_UNSIGNED_SHORT and GL_FLOAT as types
//TODO(nico): deal with interleaved data
Handle<Value> GLESglBufferDataCallback(const Arguments& args) {
  if (args.Length() != 4 || !args[1]->IsArray())
    return v8::Undefined();

  unsigned int target  = args[0]->Uint32Value();
  unsigned int type = args[2]->Uint32Value();
  unsigned int usage  = args[3]->Uint32Value();
  Handle<Array> data = Handle<Array>::Cast(args[1]);
  unsigned int len = data->Length();

  if (type == GL_FLOAT) {
    GLfloat* arg1 = new GLfloat[len];
    for (unsigned j = 0; j < len; j++) {
        Handle<Value> arg(data->Get(Integer::New(j)));
        arg1[j] = (GLfloat)arg->NumberValue();
    }
    glBufferData((GLenum)target,
                 (GLsizeiptr)(len * sizeof(*arg1)),
                 (const void*)arg1,
                 (GLenum)usage);
    delete[] arg1;
  } else if (type == GL_UNSIGNED_SHORT) {
    GLushort* arg1 = new GLushort[len];
    for (unsigned j = 0; j < len; j++) {
      Handle<Value> arg(data->Get(Integer::New(j)));
      arg1[j] = (GLushort)arg->Uint32Value();
    }
    glBufferData((GLenum)target,
                 (GLsizeiptr)(len * sizeof(*arg1)),
                 (const void*)arg1,
                 (GLenum)usage);
    delete[] arg1;
  }

  Handle<Object> res(GlesFactory::self_);
  return res;
}


//Accepts GL_UNSIGNED_SHORT and GL_FLOAT as types
//TODO(nico): deal with interleaved data
Handle<Value> GLESglBufferSubDataCallback(const Arguments& args) {
  if (args.Length() != 4)
    return v8::Undefined();

  HandleScope handle_scope;
  unsigned int target  = args[0]->Uint32Value();
  unsigned int offset = args[1]->Uint32Value();
  unsigned int type  = args[3]->Uint32Value();

  void* ans;
  if(args[2]->IsArray()) {
	  Handle<Array> data = Handle<Array>::Cast(args[2]);
	  unsigned int len = data->Length();

	  switch(type) {
		  case GL_FLOAT:
		  {
			  GLfloat* arg1 = new  GLfloat[len];
			  for (unsigned j = 0; j < data->Length(); j++) {
			      Handle<Value> arg(data->Get(Integer::New(j)));
			      arg1[j] = (GLfloat)arg->NumberValue();
			  }
			  ans = (void *)arg1;
		  }
		  break;

		  case GL_UNSIGNED_SHORT:
		  {
			  GLushort* arg1 = new  GLushort[len];
			  for (unsigned j = 0; j < data->Length(); j++) {
			      Handle<Value> arg(data->Get(Integer::New(j)));
			      arg1[j] = (GLushort)arg->Uint32Value();
			  }
			  ans = (void *)arg1;
		  }
		  break;

		  default: return v8::Undefined();
	  }

	  glBufferSubData((GLenum)target,
			  (GLintptr)offset,
			  (GLsizeiptr)len,
			  (const void*)ans);

	  //should I delete[] ans?
  }

  Handle<Object> res(GlesFactory::self_);
  return res;
}

Handle<Value> GLESglReadPixelsCallback(const Arguments& args) {
  if (args.Length() != 6)
	return v8::Undefined();

  HandleScope handle_scope;
  int x = args[0]->IntegerValue();
  int y = args[1]->IntegerValue();
  unsigned width = args[2]->Uint32Value();
  unsigned height = args[3]->Uint32Value();
  unsigned format = args[4]->Uint32Value();
  unsigned type = args[5]->Uint32Value();

  //TODO(nico): should support other formats also
  if(format == GL_RGB && type == GL_UNSIGNED_BYTE) {
	  unsigned len = width * height * 3;
	  GLubyte *ans = new GLubyte[len];
	  glReadPixels((GLint)x,
			  (GLint)y,
			  (GLsizei)width,
			  (GLsizei)height,
			  (GLenum)format,
			  (GLenum)type, ans);

	  Local<Array> res = Array::New(len);
	  for (unsigned i = 0; i < len; ++i) {
	    res->Set(Integer::New(i), Integer::New(ans[i]));
	  }

	  delete[] ans;
	  return handle_scope.Close(res);
  }

  return v8::Undefined();
}

Handle<Value> GLESglGetActiveAttribCallback(const Arguments& args) {
  if (args.Length() != 2)
	return v8::Undefined();

  HandleScope handle_scope;

  unsigned program = args[0]->Uint32Value();
  unsigned index = args[1]->Uint32Value();

  char* name = new char[256];
  int length = 0;
  int size = 0;
  unsigned type = 0;

  glGetActiveAttrib((GLuint)program,
		  (GLuint)index,
		  (GLsizei)256,
		  (GLsizei*) &length,
		  (GLint*) &size,
		  (GLenum*)&type,
		  (GLchar*)name);

  // Create a template for the answer object that'll hold
  // type/size/name as properties
  Handle<ObjectTemplate> ans = ObjectTemplate::New();
  ans->Set(String::New("type"), Uint32::New(type));
  ans->Set(String::New("size"), Integer::New(size));
  ans->Set(String::New("name"), String::New(name));

  //TODO(nico): do I have to get into the active context here before I create an
  //instance of ans?
  Context::Scope context_scope(GlesFactory::gles_persistent_context);
  Handle<Object> res(ans->NewInstance());
  return res;
}

Handle<Value> GLESglGetActiveUniformCallback(const Arguments& args) {
  if (args.Length() != 2)
	return v8::Undefined();

  HandleScope handle_scope;

  unsigned program = args[0]->Uint32Value();
  unsigned index = args[1]->Uint32Value();

  char* name = new char[256];
  int length = 0;
  int size = 0;
  unsigned type = 0;

  glGetActiveUniform((GLuint)program,
		  (GLuint)index,
		  (GLsizei)256,
		  (GLsizei*) &length,
		  (GLint*) &size,
		  (GLenum*)&type,
		  (GLchar*)name);

  // Create a template for the answer object that'll hold
  // type/size/name as properties
  Handle<ObjectTemplate> ans = ObjectTemplate::New();
  ans->Set(String::New("type"), Uint32::New(type));
  ans->Set(String::New("size"), Integer::New(size));
  ans->Set(String::New("name"), String::New(name));

  //do I have to get into the active context before I create an
  //instance of ans?
  Context::Scope context_scope(GlesFactory::gles_persistent_context);
  Handle<Object> res(ans->NewInstance());
  return res;
}

Handle<Value> GLESglGetAttachedShadersCallback(const Arguments& args) {
  if (args.Length() != 1)
	return v8::Undefined();

  HandleScope handle_scope;
  unsigned program = args[0]->Uint32Value();

  int maxcount = 500;
  int count = 0;
  unsigned* shaders = new unsigned[maxcount];

  glGetAttachedShaders((GLuint)program,
		  (GLsizei)maxcount,
		  (GLsizei*)&count,
		  (GLuint*)shaders);

  Local<Array> res = Array::New(count);
  for (int i = 0; i < count; ++i) {
    res->Set(Integer::New(i), Uint32::New(shaders[i]));
  }

  delete[] shaders;

  return handle_scope.Close(res);
}

Handle<Value> GLESglGetBufferParameterivCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned target = args[0]->IntegerValue();
  unsigned pname = args[1]->IntegerValue();
  int ans = 0;
  //TODO(nico): does this return an array or just GLint?
  glGetBufferParameteriv((GLenum)target,
		  (GLenum)pname,
		  (GLint*)&ans);

  return handle_scope.Close(Integer::New(ans));
}

//GetBooleanv, GetIntegerv, GetString, GetFloatv, GetDoublev should map here.
Handle<Value> GLESglGetParameterCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned pname = args[0]->Uint32Value();


  switch(pname) {
  //return 1 int value
  case GL_ALPHA_TEST_FUNC:
  case GL_ACCUM_ALPHA_BITS:
  case GL_ACCUM_BLUE_BITS:
  case GL_ACCUM_GREEN_BITS:
  case GL_ACCUM_RED_BITS:
  case GL_ALPHA_BITS:
  case GL_ATTRIB_STACK_DEPTH:
  case GL_AUX_BUFFERS:
  case GL_BLEND_DST:
  case GL_BLEND_EQUATION_EXT:
  case GL_BLEND_SRC:
  case GL_BLUE_BITS:
  case GL_SUBPIXEL_BITS:
  case GL_CLIENT_ATTRIB_STACK_DEPTH:
  case GL_COLOR_ARRAY_SIZE:
  case GL_COLOR_ARRAY_STRIDE:
  case GL_COLOR_ARRAY_TYPE:
  case GL_COLOR_MATERIAL_FACE:
  case GL_COLOR_MATERIAL_PARAMETER:
  case GL_CULL_FACE_MODE:
  case GL_DEPTH_BITS:
  case GL_DEPTH_FUNC:
  case GL_DRAW_BUFFER:
  case GL_EDGE_FLAG_ARRAY_STRIDE:
  case GL_FOG_HINT:
  case GL_FOG_MODE:
  case GL_FRONT_FACE:
  case GL_GREEN_BITS:
  case GL_INDEX_ARRAY_STRIDE:
  case GL_INDEX_ARRAY_TYPE:
  case GL_INDEX_BITS:
  case GL_INDEX_WRITEMASK:
  case GL_LINE_SMOOTH_HINT:
  case GL_LINE_STIPPLE_PATTERN:
  case GL_LINE_STIPPLE_REPEAT:
  case GL_LIST_BASE:
  case GL_LIST_INDEX: //name of the display list
  case GL_LIST_MODE:
  case GL_LOGIC_OP_MODE:
  case GL_MAP1_GRID_SEGMENTS:
  case GL_MATRIX_MODE:
  case GL_MAX_CLIENT_ATTRIB_STACK_DEPTH:
  case GL_MAX_ATTRIB_STACK_DEPTH:
  case GL_MAX_CLIP_PLANES:
  case GL_MAX_EVAL_ORDER:
  case GL_MAX_LIGHTS:
  case GL_MAX_LIST_NESTING:
  case GL_MAX_MODELVIEW_STACK_DEPTH:
  case GL_MAX_NAME_STACK_DEPTH:
  case GL_MAX_PIXEL_MAP_TABLE:
  case GL_MAX_PROJECTION_STACK_DEPTH:
  case GL_MAX_TEXTURE_SIZE:
  case GL_MAX_TEXTURE_STACK_DEPTH:
  case GL_MODELVIEW_STACK_DEPTH:
  case GL_NAME_STACK_DEPTH:
  case GL_NORMAL_ARRAY_STRIDE:
  case GL_NORMAL_ARRAY_TYPE:
  case GL_PACK_ALIGNMENT:
  case GL_PACK_ROW_LENGTH:
  case GL_PACK_SKIP_PIXELS:
  case GL_PACK_SKIP_ROWS:
  case GL_PERSPECTIVE_CORRECTION_HINT:
  case GL_PIXEL_MAP_A_TO_A_SIZE:
  case GL_PIXEL_MAP_B_TO_B_SIZE:
  case GL_PIXEL_MAP_G_TO_G_SIZE:
  case GL_PIXEL_MAP_I_TO_A_SIZE:
  case GL_PIXEL_MAP_I_TO_B_SIZE:
  case GL_PIXEL_MAP_I_TO_G_SIZE:
  case GL_PIXEL_MAP_I_TO_I_SIZE:
  case GL_PIXEL_MAP_I_TO_R_SIZE:
  case GL_PIXEL_MAP_R_TO_R_SIZE:
  case GL_PIXEL_MAP_S_TO_S_SIZE:
  case GL_POINT_SMOOTH_HINT:
  case GL_POLYGON_SMOOTH_HINT:
  case GL_PROJECTION_STACK_DEPTH:
  case GL_RED_BITS:
  case GL_RENDER_MODE:
  case GL_SHADE_MODEL:
  case GL_STENCIL_BITS:
  case GL_STENCIL_CLEAR_VALUE:
  case GL_STENCIL_FAIL:
  case GL_STENCIL_FUNC:
  case GL_STENCIL_PASS_DEPTH_FAIL:
  case GL_STENCIL_PASS_DEPTH_PASS:
  case GL_STENCIL_REF:
  case GL_STENCIL_VALUE_MASK:
  case GL_STENCIL_WRITEMASK:
//  case GL_TEXTURE_1D_BINDING:
//  case GL_TEXTURE_2D_BINDING:
  case GL_TEXTURE_COORD_ARRAY_SIZE:
  case GL_TEXTURE_COORD_ARRAY_STRIDE:
  case GL_TEXTURE_COORD_ARRAY_TYPE:
  case GL_TEXTURE_STACK_DEPTH:
  case GL_UNPACK_ALIGNMENT:
  case GL_UNPACK_ROW_LENGTH:
  case GL_UNPACK_SKIP_PIXELS:
  case GL_UNPACK_SKIP_ROWS:
  case GL_VERTEX_ARRAY_SIZE:
  case GL_VERTEX_ARRAY_STRIDE:
  case GL_VERTEX_ARRAY_TYPE:
  {
	  int ans = 0;
	  glGetIntegerv((GLenum)pname, (GLint*)&ans);
	  return handle_scope.Close(Integer::New(ans));
  }
  //2 values int
  case GL_LINE_WIDTH_RANGE:
  case GL_MAP2_GRID_SEGMENTS:
  case GL_MAX_VIEWPORT_DIMS:
  case GL_POLYGON_MODE:
  {
	  int* ans = new int[2];
	  glGetIntegerv((GLenum)pname, ans);

	  Local<Array> res = Array::New(2);
	  for (int i = 0; i < 2; ++i) {
	    res->Set(Integer::New(i), Integer::New(ans[i]));
	  }

	  delete[] ans;

	  return handle_scope.Close(res);
  }
  //4 values int
  case GL_SCISSOR_BOX:
  case GL_VIEWPORT:
  {
	  int* ans = new int[4];
	  glGetIntegerv((GLenum)pname, ans);

	  Local<Array> res = Array::New(4);
	  for (int i = 0; i < 4; ++i) {
	    res->Set(Integer::New(i), Integer::New(ans[i]));
	  }

	  delete[] ans;

	  return handle_scope.Close(res);
  }

  //1 value boolean
  case GL_ALPHA_TEST:
  case GL_AUTO_NORMAL:
  case GL_BLEND:
  case GL_DEPTH_TEST:
//  case GL_CLIP_PLANEi:
  case GL_COLOR_ARRAY:
  case GL_COLOR_LOGIC_OP:
  case GL_COLOR_MATERIAL:
  case GL_CULL_FACE:
  case GL_CURRENT_RASTER_POSITION_VALID:
  case GL_DEPTH_WRITEMASK:
  case GL_DITHER:
  case GL_DOUBLEBUFFER:
  case GL_EDGE_FLAG:
  case GL_EDGE_FLAG_ARRAY:
  case GL_FOG:
  case GL_INDEX_ARRAY:
  case GL_INDEX_LOGIC_OP:
  case GL_INDEX_MODE:
//  case GL_LIGHTi:
  case GL_LIGHTING:
  case GL_LIGHT_MODEL_LOCAL_VIEWER:
  case GL_LIGHT_MODEL_TWO_SIDE:
  case GL_LINE_SMOOTH:
  case GL_LINE_STIPPLE:
  case GL_MAP1_COLOR_4:
  case GL_MAP1_INDEX:
  case GL_MAP1_NORMAL:
  case GL_MAP1_TEXTURE_COORD_1:
  case GL_MAP1_TEXTURE_COORD_2:
  case GL_MAP1_TEXTURE_COORD_3:
  case GL_MAP1_TEXTURE_COORD_4:
  case GL_MAP1_VERTEX_3:
  case GL_MAP1_VERTEX_4:
  case GL_MAP2_COLOR_4:
  case GL_MAP2_INDEX:
  case GL_MAP2_NORMAL:
  case GL_MAP2_TEXTURE_COORD_1:
  case GL_MAP2_TEXTURE_COORD_2:
  case GL_MAP2_TEXTURE_COORD_3:
  case GL_MAP2_TEXTURE_COORD_4:
  case GL_MAP2_VERTEX_3:
  case GL_MAP2_VERTEX_4:
  case GL_MAP_COLOR:
  case GL_MAP_STENCIL:
  case GL_NORMAL_ARRAY:
  case GL_NORMALIZE:
  case GL_PACK_LSB_FIRST:
  case GL_PACK_SWAP_BYTES:
  case GL_POINT_SMOOTH:
  case GL_POLYGON_OFFSET_FILL:
  case GL_POLYGON_OFFSET_LINE:
  case GL_POLYGON_OFFSET_POINT:
  case GL_POLYGON_SMOOTH:
  case GL_POLYGON_STIPPLE:
  case GL_READ_BUFFER:
  case GL_RGBA_MODE:
  case GL_SCISSOR_TEST:
  case GL_STENCIL_TEST:
  case GL_STEREO:
  case GL_TEXTURE_1D:
  case GL_TEXTURE_2D:
  case GL_TEXTURE_COORD_ARRAY:
  case GL_TEXTURE_GEN_Q:
  case GL_TEXTURE_GEN_R:
  case GL_TEXTURE_GEN_S:
  case GL_TEXTURE_GEN_T:
  case GL_UNPACK_LSB_FIRST:
  case GL_VERTEX_ARRAY:
  case GL_UNPACK_SWAP_BYTES:
  {
	  GLboolean ans = 0;
	  glGetBooleanv((GLenum)pname, &ans);
	  return handle_scope.Close(Boolean::New(ans != GL_FALSE));
  }

  //1 value float
  case GL_ALPHA_BIAS:
  case GL_ALPHA_SCALE:
  case GL_BLUE_BIAS:
  case GL_BLUE_SCALE:
  case GL_RED_BIAS:
  case GL_RED_SCALE:
  case GL_GREEN_BIAS:
  case GL_GREEN_SCALE:
  case GL_DEPTH_BIAS:
  case GL_DEPTH_SCALE:
  case GL_ALPHA_TEST_REF:
  case GL_ZOOM_X:
  case GL_ZOOM_Y:
  case GL_CURRENT_INDEX:
  case GL_CURRENT_RASTER_DISTANCE:
  case GL_CURRENT_RASTER_INDEX:
  case GL_DEPTH_CLEAR_VALUE:
  case GL_FOG_DENSITY:
  case GL_FOG_END:
  case GL_FOG_INDEX:
  case GL_FOG_START:
  case GL_INDEX_CLEAR_VALUE:
  case GL_INDEX_OFFSET:
  case GL_INDEX_SHIFT:
  case GL_LINE_WIDTH:
  case GL_LINE_WIDTH_GRANULARITY:
  case GL_POINT_SIZE:
  case GL_POINT_SIZE_GRANULARITY:
  {
	  float ans = 0.0f;
	  glGetFloatv((GLenum)pname, &ans);
	  return handle_scope.Close(Number::New(ans));
  }

  //4 values float
  case GL_BLEND_COLOR_EXT:
  case GL_ACCUM_CLEAR_VALUE:
  case GL_COLOR_CLEAR_VALUE:
  case GL_CURRENT_COLOR:
  case GL_CURRENT_RASTER_COLOR:
  case GL_CURRENT_RASTER_POSITION:
  case GL_CURRENT_RASTER_TEXTURE_COORDS:
  case GL_CURRENT_TEXTURE_COORDS:
  case GL_FOG_COLOR:
  case GL_LIGHT_MODEL_AMBIENT:
  case GL_MAP2_GRID_DOMAIN:
  case GL_POLYGON_OFFSET_FACTOR:
  case GL_POLYGON_OFFSET_UNITS:
  {
	  float* ans = new float[4];
	  glGetFloatv((GLenum)pname, ans);

	  Local<Array> res = Array::New(4);
	  for (int i = 0; i < 4; ++i) {
	    res->Set(Integer::New(i), Number::New(ans[i]));
	  }

	  delete[] ans;

	  return handle_scope.Close(res);
  }

   //3 values float
  case GL_CURRENT_NORMAL:
  {
	  float* ans = new float[3];
	  glGetFloatv((GLenum)pname, ans);

	  Local<Array> res = Array::New(3);
	  for (int i = 0; i < 3; ++i) {
	    res->Set(Integer::New(i), Number::New(ans[i]));
	  }

	  delete[] ans;

	  return handle_scope.Close(res);
  }

  //2 values float
  case GL_DEPTH_RANGE:
  case GL_MAP1_GRID_DOMAIN:
  case GL_POINT_SIZE_RANGE:
  {
	  float* ans = new float[2];
	  glGetFloatv((GLenum)pname, ans);

	  Local<Array> res = Array::New(2);
	  for (int i = 0; i < 2; ++i) {
	    res->Set(Integer::New(i), Number::New(ans[i]));
	  }

	  delete[] ans;

	  return handle_scope.Close(res);
  }

  //16 values float
  case GL_MODELVIEW_MATRIX:
  case GL_PROJECTION_MATRIX:
  case GL_TEXTURE_MATRIX:
  {
	  float* ans = new float[16];
	  glGetFloatv((GLenum)pname, ans);

	  Local<Array> res = Array::New(16);
	  for (int i = 0; i < 16; ++i) {
	    res->Set(Integer::New(i), Number::New(ans[i]));
	  }

	  delete[] ans;

	  return handle_scope.Close(res);
  }

  //4 values boolean
  case GL_COLOR_WRITEMASK:
  {
	  GLboolean* ans = new GLboolean[4];
	  glGetBooleanv((GLenum)pname, ans);

	  Local<Array> res = Array::New(4);
	  for (int i = 0; i < 4; ++i) {
	    res->Set(Integer::New(i), Boolean::New(ans[i] != GL_FALSE));
	  }

	  delete[] ans;

	  return handle_scope.Close(res);
  }

  }
  return v8::Undefined();
}


Handle<Value> GLESglGetProgramivCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() != 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned program = args[0]->Uint32Value();
  unsigned pname = args[1]->Uint32Value();
  int ans;

  //TODO(nico): I haven't seen any case where this function might return
  //an array.
  glGetProgramiv((GLuint)program, (GLenum)pname, (GLint*) &ans);

  return handle_scope.Close(Integer::New(ans));
}

Handle<Value> GLESglGetProgramInfoLogCallback(const Arguments& args) {

  if (args.Length() != 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned program = args[0]->Uint32Value();

  //query string length
  int len = 0;
  glGetProgramiv((GLuint)program, GL_INFO_LOG_LENGTH, &len);

  char* log = new char[len];
  glGetProgramInfoLog((GLuint)program, (GLsizei)len, NULL, log);

  return handle_scope.Close(String::New(log));
}

Handle<Value> GLESglGetTexParameterCallback(const Arguments& args) {

  if (args.Length() != 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned target = args[0]->Uint32Value();
  unsigned pname = args[1]->Uint32Value();

  switch(pname) {
  //1 int
  case GL_TEXTURE_MAG_FILTER:
  case GL_TEXTURE_MIN_FILTER:
  case GL_TEXTURE_WRAP_S:
  case GL_TEXTURE_WRAP_T:
  {
	  int ans = 0;
	  glTexParameteriv((GLenum)target, (GLenum)pname, (GLint*) &ans);
	  return handle_scope.Close(Integer::New(ans));
  }
	  //4 floats
  case GL_TEXTURE_BORDER_COLOR:
  {
	  float* ans = new float[4];
	  glTexParameterfv((GLenum)target, (GLenum)pname, (GLfloat*) ans);

	  Local<Array> res = Array::New(4);
	  for (int i = 0; i < 4; ++i) {
	    res->Set(Integer::New(i), Number::New(ans[i]));
	  }

	  delete[] ans;

	  return handle_scope.Close(res);
  }
	  //1 float
  case GL_TEXTURE_PRIORITY:
  {
	  float ans = 0;
	  glTexParameterfv((GLenum)target, (GLenum)pname, (GLfloat*) &ans);
	  return handle_scope.Close(Number::New(ans));
  }
	  //1 boolean
  case GL_TEXTURE_RESIDENT:
  {
	  int ans = 0;
	  glTexParameteriv((GLenum)target, (GLenum)pname, (GLint*) &ans);
	  return handle_scope.Close(Boolean::New(ans != GL_FALSE));
  }

  }
  return v8::Undefined();
}

Handle<Value> GLESglGetVertexAttribCallback(const Arguments& args) {

  if (args.Length() != 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned index = args[0]->Uint32Value();
  unsigned pname = args[1]->Uint32Value();

  switch(pname) {
  //1 int value
  case GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING:
  case GL_VERTEX_ATTRIB_ARRAY_SIZE:
  case GL_VERTEX_ATTRIB_ARRAY_STRIDE:
  case GL_VERTEX_ATTRIB_ARRAY_TYPE:
  {
	  GLint ans = 0;
	  glGetVertexAttribiv((GLuint)index, (GLenum)pname, &ans);
	  return handle_scope.Close(Integer::New(ans));
  }

  //1 boolean value
  case GL_VERTEX_ATTRIB_ARRAY_ENABLED:
  case GL_VERTEX_ATTRIB_ARRAY_NORMALIZED:
  {
	  GLint ans = 0;
	  glGetVertexAttribiv((GLuint)index, (GLenum)pname, &ans);
	  return handle_scope.Close(Boolean::New(ans != GL_FALSE));
  }

  //4 float values
  case GL_CURRENT_VERTEX_ATTRIB: //(?)
  {
	  GLfloat* ans = new GLfloat[4];
	  glGetVertexAttribfv((GLuint)index, (GLenum)pname, ans);

	  Local<Array> res = Array::New(4);
	  for (int i = 0; i < 4; ++i) {
	    res->Set(Integer::New(i), Integer::New(ans[i]));
	  }

	  delete[] ans;

	  return handle_scope.Close(res);
  }
  }

  return v8::Undefined();
}

Handle<Value> GLESglTexImage2DCallback(const Arguments& args) {

  if (args.Length() != 9) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned target = args[0]->Uint32Value();
  int level = args[1]->IntegerValue();
  int internal_format = args[2]->IntegerValue();
  int width = args[3]->IntegerValue();
  int height = args[4]->IntegerValue();
  int border = args[5]->IntegerValue();
  unsigned format = args[6]->Uint32Value();
  unsigned type = args[7]->Uint32Value();

  if(args[8]->IsArray()) {
	  Handle<Array> arr_handle = Handle<Array>::Cast(args[8]);

	  switch(type) {
	  case GL_UNSIGNED_BYTE:
	  {
		  GLubyte* pixels = new  GLubyte[arr_handle->Length()];
		  for (unsigned j = 0; j < arr_handle->Length(); j++) {
		      Handle<Value> arg(arr_handle->Get(Integer::New(j)));
		      GLubyte aux = (GLubyte)arg->Uint32Value();
		      pixels[j] = aux;
		  }
		  glTexImage2D((GLenum)target,
				  (GLint)level,
				  (GLenum)internal_format,
				  (GLsizei)width,
				  (GLsizei)height,
				  (GLint)border,
				  (GLenum)format,
				  (GLenum)type,
				  (const void*)pixels);

		  delete[] pixels;
	  }
	  break;

	  case GL_BYTE:
	  {
		  GLbyte* pixels = new  GLbyte[arr_handle->Length()];
		  for (unsigned j = 0; j < arr_handle->Length(); j++) {
		      Handle<Value> arg(arr_handle->Get(Integer::New(j)));
		      GLbyte aux = (GLbyte)arg->Uint32Value();
		      pixels[j] = aux;
		  }
		  glTexImage2D((GLenum)target,
				  (GLint)level,
				  (GLenum)internal_format,
				  (GLsizei)width,
				  (GLsizei)height,
				  (GLint)border,
				  (GLenum)format,
				  (GLenum)type,
				  (const void*)pixels);

		  delete[] pixels;
	  }
	  break;

	  case GL_BITMAP:
	  {
		  GLbitfield* pixels = new  GLbitfield[arr_handle->Length()];
		  for (unsigned j = 0; j < arr_handle->Length(); j++) {
		      Handle<Value> arg(arr_handle->Get(Integer::New(j)));
		      GLbitfield aux = (GLbitfield)arg->IntegerValue();
		      pixels[j] = aux;
		  }
		  glTexImage2D((GLenum)target,
				  (GLint)level,
				  (GLenum)internal_format,
				  (GLsizei)width,
				  (GLsizei)height,
				  (GLint)border,
				  (GLenum)format,
				  (GLenum)type,
				  (const void*)pixels);

		  delete[] pixels;
	  }
	  break;

	  case GL_UNSIGNED_SHORT:
	  {
		  GLushort* pixels = new  GLushort[arr_handle->Length()];
		  for (unsigned j = 0; j < arr_handle->Length(); j++) {
		      Handle<Value> arg(arr_handle->Get(Integer::New(j)));
		      GLushort aux = (GLushort)arg->Uint32Value();
		      pixels[j] = aux;
		  }
		  glTexImage2D((GLenum)target,
				  (GLint)level,
				  (GLenum)internal_format,
				  (GLsizei)width,
				  (GLsizei)height,
				  (GLint)border,
				  (GLenum)format,
				  (GLenum)type,
				  (const void*)pixels);

		  delete[] pixels;
	  }
	  break;

	  case GL_SHORT:
	  {
		  GLshort* pixels = new  GLshort[arr_handle->Length()];
		  for (unsigned j = 0; j < arr_handle->Length(); j++) {
		      Handle<Value> arg(arr_handle->Get(Integer::New(j)));
		      GLshort aux = (GLshort)arg->IntegerValue();
		      pixels[j] = aux;
		  }
		  glTexImage2D((GLenum)target,
				  (GLint)level,
				  (GLenum)internal_format,
				  (GLsizei)width,
				  (GLsizei)height,
				  (GLint)border,
				  (GLenum)format,
				  (GLenum)type,
				  (const void*)pixels);

		  delete[] pixels;
	  }
	  break;

	  case GL_UNSIGNED_INT:
	  {
		  GLuint* pixels = new  GLuint[arr_handle->Length()];
		  for (unsigned j = 0; j < arr_handle->Length(); j++) {
		      Handle<Value> arg(arr_handle->Get(Integer::New(j)));
		      GLuint aux = (GLuint)arg->Uint32Value();
		      pixels[j] = aux;
		  }
		  glTexImage2D((GLenum)target,
				  (GLint)level,
				  (GLenum)internal_format,
				  (GLsizei)width,
				  (GLsizei)height,
				  (GLint)border,
				  (GLenum)format,
				  (GLenum)type,
				  (const void*)pixels);

		  delete[] pixels;
	  }
	  break;

	  case GL_INT:
	  {
		  GLint* pixels = new  GLint[arr_handle->Length()];
		  for (unsigned j = 0; j < arr_handle->Length(); j++) {
		      Handle<Value> arg(arr_handle->Get(Integer::New(j)));
		      GLint aux = (GLint)arg->IntegerValue();
		      pixels[j] = aux;
		  }
		  glTexImage2D((GLenum)target,
				  (GLint)level,
				  (GLenum)internal_format,
				  (GLsizei)width,
				  (GLsizei)height,
				  (GLint)border,
				  (GLenum)format,
				  (GLenum)type,
				  (const void*)pixels);

		  delete[] pixels;
	  }
	  break;

	  case GL_FLOAT:
	  {
		  GLfloat* pixels = new  GLfloat[arr_handle->Length()];
		  for (unsigned j = 0; j < arr_handle->Length(); j++) {
		      Handle<Value> arg(arr_handle->Get(Integer::New(j)));
		      GLfloat aux = (GLfloat)arg->NumberValue();
		      pixels[j] = aux;
		  }
		  glTexImage2D((GLenum)target,
				  (GLint)level,
				  (GLenum)internal_format,
				  (GLsizei)width,
				  (GLsizei)height,
				  (GLint)border,
				  (GLenum)format,
				  (GLenum)type,
				  (const void*)pixels);

		  delete[] pixels;
	  }
	  break;
	  }
  }

  return v8::Undefined();
}



Handle<Value> GLESglTexSubImage2DCallback(const Arguments& args) {

  if (args.Length() != 9) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned target = args[0]->Uint32Value();
  int level = args[1]->IntegerValue();
  int xoffset = args[2]->IntegerValue();
  int yoffset = args[3]->IntegerValue();
  int width = args[4]->IntegerValue();
  int height = args[5]->IntegerValue();
  unsigned format = args[6]->Uint32Value();
  unsigned type = args[7]->Uint32Value();

  if(args[8]->IsArray()) {
	  Handle<Array> arr_handle = Handle<Array>::Cast(args[8]);

	  switch(type) {
	  case GL_UNSIGNED_BYTE:
	  {
		  GLubyte* pixels = new  GLubyte[arr_handle->Length()];
		  for (unsigned j = 0; j < arr_handle->Length(); j++) {
		      Handle<Value> arg(arr_handle->Get(Integer::New(j)));
		      GLubyte aux = (GLubyte)arg->Uint32Value();
		      pixels[j] = aux;
		  }
		  glTexSubImage2D((GLenum)target,
				  (GLint)level,
				  (GLint)xoffset,
				  (GLint)yoffset,
				  (GLsizei)width,
				  (GLsizei)height,
				  (GLenum)format,
				  (GLenum)type,
				  (const void*)pixels);

		  delete[] pixels;
	  }
	  break;

	  case GL_BYTE:
	  {
		  GLbyte* pixels = new  GLbyte[arr_handle->Length()];
		  for (unsigned j = 0; j < arr_handle->Length(); j++) {
		      Handle<Value> arg(arr_handle->Get(Integer::New(j)));
		      GLbyte aux = (GLbyte)arg->Uint32Value();
		      pixels[j] = aux;
		  }
		  glTexSubImage2D((GLenum)target,
				  (GLint)level,
				  (GLint)xoffset,
				  (GLint)yoffset,
				  (GLsizei)width,
				  (GLsizei)height,
				  (GLenum)format,
				  (GLenum)type,
				  (const void*)pixels);

		  delete[] pixels;
	  }
	  break;

	  case GL_BITMAP:
	  {
		  GLbitfield* pixels = new  GLbitfield[arr_handle->Length()];
		  for (unsigned j = 0; j < arr_handle->Length(); j++) {
		      Handle<Value> arg(arr_handle->Get(Integer::New(j)));
		      GLbitfield aux = (GLbitfield)arg->IntegerValue();
		      pixels[j] = aux;
		  }
		  glTexSubImage2D((GLenum)target,
				  (GLint)level,
				  (GLint)xoffset,
				  (GLint)yoffset,
				  (GLsizei)width,
				  (GLsizei)height,
				  (GLenum)format,
				  (GLenum)type,
				  (const void*)pixels);

		  delete[] pixels;
	  }
	  break;

	  case GL_UNSIGNED_SHORT:
	  {
		  GLushort* pixels = new  GLushort[arr_handle->Length()];
		  for (unsigned j = 0; j < arr_handle->Length(); j++) {
		      Handle<Value> arg(arr_handle->Get(Integer::New(j)));
		      GLushort aux = (GLushort)arg->Uint32Value();
		      pixels[j] = aux;
		  }
		  glTexSubImage2D((GLenum)target,
				  (GLint)level,
				  (GLint)xoffset,
				  (GLint)yoffset,
				  (GLsizei)width,
				  (GLsizei)height,
				  (GLenum)format,
				  (GLenum)type,
				  (const void*)pixels);

		  delete[] pixels;
	  }
	  break;

	  case GL_SHORT:
	  {
		  GLshort* pixels = new  GLshort[arr_handle->Length()];
		  for (unsigned j = 0; j < arr_handle->Length(); j++) {
		      Handle<Value> arg(arr_handle->Get(Integer::New(j)));
		      GLshort aux = (GLshort)arg->IntegerValue();
		      pixels[j] = aux;
		  }
		  glTexSubImage2D((GLenum)target,
				  (GLint)level,
				  (GLint)xoffset,
				  (GLint)yoffset,
				  (GLsizei)width,
				  (GLsizei)height,
				  (GLenum)format,
				  (GLenum)type,
				  (const void*)pixels);

		  delete[] pixels;
	  }
	  break;

	  case GL_UNSIGNED_INT:
	  {
		  GLuint* pixels = new  GLuint[arr_handle->Length()];
		  for (unsigned j = 0; j < arr_handle->Length(); j++) {
		      Handle<Value> arg(arr_handle->Get(Integer::New(j)));
		      GLuint aux = (GLuint)arg->Uint32Value();
		      pixels[j] = aux;
		  }
		  glTexSubImage2D((GLenum)target,
				  (GLint)level,
				  (GLint)xoffset,
				  (GLint)yoffset,
				  (GLsizei)width,
				  (GLsizei)height,
				  (GLenum)format,
				  (GLenum)type,
				  (const void*)pixels);

		  delete[] pixels;
	  }
	  break;

	  case GL_INT:
	  {
		  GLint* pixels = new  GLint[arr_handle->Length()];
		  for (unsigned j = 0; j < arr_handle->Length(); j++) {
		      Handle<Value> arg(arr_handle->Get(Integer::New(j)));
		      GLint aux = (GLint)arg->IntegerValue();
		      pixels[j] = aux;
		  }
		  glTexSubImage2D((GLenum)target,
				  (GLint)level,
				  (GLint)xoffset,
				  (GLint)yoffset,
				  (GLsizei)width,
				  (GLsizei)height,
				  (GLenum)format,
				  (GLenum)type,
				  (const void*)pixels);

		  delete[] pixels;
	  }
	  break;

	  case GL_FLOAT:
	  {
		  GLfloat* pixels = new  GLfloat[arr_handle->Length()];
		  for (unsigned j = 0; j < arr_handle->Length(); j++) {
		      Handle<Value> arg(arr_handle->Get(Integer::New(j)));
		      GLfloat aux = (GLfloat)arg->NumberValue();
		      pixels[j] = aux;
		  }
		  glTexSubImage2D((GLenum)target,
				  (GLint)level,
				  (GLint)xoffset,
				  (GLint)yoffset,
				  (GLsizei)width,
				  (GLsizei)height,
				  (GLenum)format,
				  (GLenum)type,
				  (const void*)pixels);

		  delete[] pixels;
	  }
	  break;
	  }
  }

  return v8::Undefined();
}


Handle<Value> GLESglGetRenderbufferParameterCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() != 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned target = args[0]->Uint32Value();
  unsigned pname = args[1]->Uint32Value();

  switch(pname) {
  //1 int value
  case GL_RENDERBUFFER_WIDTH:
  case GL_RENDERBUFFER_HEIGHT:
  case GL_RENDERBUFFER_INTERNAL_FORMAT:
  case GL_RENDERBUFFER_RED_SIZE:
  case GL_RENDERBUFFER_GREEN_SIZE:
  case GL_RENDERBUFFER_BLUE_SIZE:
  case GL_RENDERBUFFER_ALPHA_SIZE:
  case GL_RENDERBUFFER_DEPTH_SIZE:
  case  GL_RENDERBUFFER_STENCIL_SIZE:
  {
	  int ans = 0;
	  glGetRenderbufferParameteriv((GLenum)target, (GLenum)pname, (GLint*)&ans);
	  return handle_scope.Close(Integer::New(ans));
  }
  }

  return v8::Undefined();
}

Handle<Value> GLESglGetFramebufferAttachmentParameterCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() != 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned target = args[0]->Uint32Value();
  unsigned attachment = args[1]->Uint32Value();
  unsigned pname = args[2]->Uint32Value();

//  switch(pname) {
//  case FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE:
//  case FRAMEBUFFER_ATTACHMENT_OBJECT_NAME:
//  case FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL:
//  case FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE:
//  {
	  int ans = 0;
	  glGetFramebufferAttachmentParameteriv((GLenum)target,
			  (GLenum)attachment,
			  (GLenum)pname,
			  (GLint*)&ans);

	  return handle_scope.Close(Integer::New(ans));
//  }
//  }

  return v8::Undefined();
}

Handle<Value> GLESglGetShaderInfoLogCallback(const Arguments& args) {

  if (args.Length() != 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned shader = args[0]->Uint32Value();

  //query string length
  int len = 0;
  glGetShaderiv((GLuint)shader, GL_INFO_LOG_LENGTH, &len);

  char* log = new char[len];
  glGetShaderInfoLog((GLuint)shader, (GLsizei)len, NULL, log);

  return handle_scope.Close(String::New(log));
}

Handle<Value> GLESglGetShaderSourceCallback(const Arguments& args) {

  if (args.Length() != 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned shader = args[0]->Uint32Value();

  //query string length
  int len = 0;
  glGetShaderiv((GLuint)shader, GL_SHADER_SOURCE_LENGTH, &len);

  char* log = new char[len];
  glGetShaderSource((GLuint)shader, (GLsizei)len, NULL, log);

  return handle_scope.Close(String::New(log));
}


Handle<Value> GLESglActiveTextureCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  glActiveTexture((GLenum) arg0);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglAttachShaderCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  unsigned int arg1 = args[1]->Uint32Value();

  //make call
  glAttachShader((GLuint) arg0, (GLuint) arg1);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglBindAttribLocationCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  unsigned int arg1 = args[1]->Uint32Value();
  String::Utf8Value value2(args[2]);
  char* arg2 = *value2;

  //make call
  glBindAttribLocation((GLuint) arg0, (GLuint) arg1, (const char*) arg2);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglBindBufferCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  unsigned int arg1 = args[1]->Uint32Value();

  //make call
  glBindBuffer((GLenum) arg0, (GLuint) arg1);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglBindFramebufferCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  unsigned int arg1 = args[1]->Uint32Value();

  //make call
  glBindFramebuffer((GLenum) arg0, (GLuint) arg1);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglBindRenderbufferCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  unsigned int arg1 = args[1]->Uint32Value();

  //make call
  glBindRenderbuffer((GLenum) arg0, (GLuint) arg1);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglBindTextureCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  unsigned int arg1 = args[1]->Uint32Value();

  //make call
  glBindTexture((GLenum) arg0, (GLuint) arg1);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglBlendColorCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 4) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();
  double arg1 = args[1]->NumberValue();
  double arg2 = args[2]->NumberValue();
  double arg3 = args[3]->NumberValue();

  //make call
  glBlendColor((GLclampf) arg0, (GLclampf) arg1, (GLclampf) arg2, (GLclampf) arg3);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglBlendEquationCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  glBlendEquation((GLenum) arg0);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglBlendEquationSeparateCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  unsigned int arg1 = args[1]->Uint32Value();

  //make call
  glBlendEquationSeparate((GLenum) arg0, (GLenum) arg1);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglBlendFuncCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  unsigned int arg1 = args[1]->Uint32Value();

  //make call
  glBlendFunc((GLenum) arg0, (GLenum) arg1);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglBlendFuncSeparateCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 4) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  unsigned int arg1 = args[1]->Uint32Value();
  unsigned int arg2 = args[2]->Uint32Value();
  unsigned int arg3 = args[3]->Uint32Value();

  //make call
  glBlendFuncSeparate((GLenum) arg0, (GLenum) arg1, (GLenum) arg2, (GLenum) arg3);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglCheckFramebufferStatusCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  return Uint32::New(glCheckFramebufferStatus((GLenum) arg0));
}




Handle<Value> GLESglClearCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  glClear((GLbitfield) arg0);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglClearColorCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 4) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();
  double arg1 = args[1]->NumberValue();
  double arg2 = args[2]->NumberValue();
  double arg3 = args[3]->NumberValue();

  //make call
  glClearColor((GLclampf) arg0, (GLclampf) arg1, (GLclampf) arg2, (GLclampf) arg3);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglClearDepthfCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();

  //make call
  glClearDepthf((GLclampf) arg0);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglClearStencilCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  glClearStencil((GLint) arg0);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglColorMaskCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 4) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  unsigned int arg1 = args[1]->Uint32Value();
  unsigned int arg2 = args[2]->Uint32Value();
  unsigned int arg3 = args[3]->Uint32Value();

  //make call
  glColorMask((GLboolean) arg0, (GLboolean) arg1, (GLboolean) arg2, (GLboolean) arg3);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglCompileShaderCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  glCompileShader((GLuint) arg0);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglCopyTexImage2DCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 8) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  int arg1 = args[1]->IntegerValue();
  unsigned int arg2 = args[2]->Uint32Value();
  int arg3 = args[3]->IntegerValue();
  int arg4 = args[4]->IntegerValue();
  int arg5 = args[5]->IntegerValue();
  int arg6 = args[6]->IntegerValue();
  int arg7 = args[7]->IntegerValue();

  //make call
  glCopyTexImage2D((GLenum) arg0, (GLint) arg1, (GLenum) arg2, (GLint) arg3, (GLint) arg4, (GLsizei) arg5, (GLsizei) arg6, (GLint) arg7);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglCopyTexSubImage2DCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 8) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();
  int arg3 = args[3]->IntegerValue();
  int arg4 = args[4]->IntegerValue();
  int arg5 = args[5]->IntegerValue();
  int arg6 = args[6]->IntegerValue();
  int arg7 = args[7]->IntegerValue();

  //make call
  glCopyTexSubImage2D((GLenum) arg0, (GLint) arg1, (GLint) arg2, (GLint) arg3, (GLint) arg4, (GLint) arg5, (GLsizei) arg6, (GLsizei) arg7);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglCreateProgramCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 0) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

  //make call
  return Uint32::New(glCreateProgram());
}




Handle<Value> GLESglCreateShaderCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  return Uint32::New(glCreateShader((GLenum) arg0));
}




Handle<Value> GLESglCullFaceCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  glCullFace((GLenum) arg0);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglDeleteBuffersCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();


  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLuint* arg1 = new  GLuint[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLuint aux = ( GLuint)arg->Uint32Value();
      arg1[j] = aux;
  }


  //make call
  glDeleteBuffers((GLsizei) arg0, (const GLuint*) arg1);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglDeleteFramebuffersCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();


  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLuint* arg1 = new  GLuint[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLuint aux = ( GLuint)arg->Uint32Value();
      arg1[j] = aux;
  }


  //make call
  glDeleteFramebuffers((GLsizei) arg0, (const GLuint*) arg1);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglDeleteProgramCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  glDeleteProgram((GLuint) arg0);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglDeleteRenderbuffersCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();


  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLuint* arg1 = new  GLuint[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLuint aux = ( GLuint)arg->Uint32Value();
      arg1[j] = aux;
  }


  //make call
  glDeleteRenderbuffers((GLsizei) arg0, (const GLuint*) arg1);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglDeleteShaderCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  glDeleteShader((GLuint) arg0);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglDeleteTexturesCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();


  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLuint* arg1 = new  GLuint[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLuint aux = ( GLuint)arg->Uint32Value();
      arg1[j] = aux;
  }


  //make call
  glDeleteTextures((GLsizei) arg0, (const GLuint*) arg1);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglDepthFuncCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  glDepthFunc((GLenum) arg0);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglDepthMaskCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  glDepthMask((GLboolean) arg0);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglDepthRangefCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();
  double arg1 = args[1]->NumberValue();

  //make call
  glDepthRangef((GLclampf) arg0, (GLclampf) arg1);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglDetachShaderCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  unsigned int arg1 = args[1]->Uint32Value();

  //make call
  glDetachShader((GLuint) arg0, (GLuint) arg1);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglDisableCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  glDisable((GLenum) arg0);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglDisableVertexAttribArrayCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  glDisableVertexAttribArray((GLuint) arg0);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglDrawArraysCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();

  //make call
  glDrawArrays((GLenum) arg0, (GLint) arg1, (GLsizei) arg2);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglEnableCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  glEnable((GLenum) arg0);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglEnableVertexAttribArrayCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  glEnableVertexAttribArray((GLuint) arg0);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglFinishCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 0) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

  //make call
  glFinish();
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglFlushCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 0) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

  //make call
  glFlush();
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglFramebufferRenderbufferCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 4) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  unsigned int arg1 = args[1]->Uint32Value();
  unsigned int arg2 = args[2]->Uint32Value();
  unsigned int arg3 = args[3]->Uint32Value();

  //make call
  glFramebufferRenderbuffer((GLenum) arg0, (GLenum) arg1, (GLenum) arg2, (GLuint) arg3);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglFramebufferTexture2DCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 5) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  unsigned int arg1 = args[1]->Uint32Value();
  unsigned int arg2 = args[2]->Uint32Value();
  unsigned int arg3 = args[3]->Uint32Value();
  int arg4 = args[4]->IntegerValue();

  //make call
  glFramebufferTexture2D((GLenum) arg0, (GLenum) arg1, (GLenum) arg2, (GLuint) arg3, (GLint) arg4);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglFrontFaceCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  glFrontFace((GLenum) arg0);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglGenerateMipmapCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  glGenerateMipmap((GLenum) arg0);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglGetAttribLocationCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  String::Utf8Value value1(args[1]);
  char* arg1 = *value1;

  //make call
  return Integer::New(glGetAttribLocation((GLuint) arg0, (const char*) arg1));
}




Handle<Value> GLESglGetBooleanvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();


  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
  GLboolean* arg1 = new GLboolean[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
      GLboolean aux = (GLboolean)arg->Uint32Value();
      arg1[j] = aux;
  }


  //make call
  glGetBooleanv((GLenum) arg0, (GLboolean*) arg1);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglGetErrorCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 0) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

  //make call
  return Uint32::New(glGetError());
}




Handle<Value> GLESglGetFloatvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();


  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
  GLfloat* arg1 = new GLfloat[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
      GLfloat aux = (GLfloat)arg->NumberValue();
      arg1[j] = aux;
  }


  //make call
  glGetFloatv((GLenum) arg0, (GLfloat*) arg1);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglGetFramebufferAttachmentParameterivCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 4) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  unsigned int arg1 = args[1]->Uint32Value();
  unsigned int arg2 = args[2]->Uint32Value();


  Handle<Array> arrHandle3 = Handle<Array>::Cast(args[3]);
  GLint* arg3 = new GLint[arrHandle3->Length()];
  for (unsigned j = 0; j < arrHandle3->Length(); j++) {
      Handle<Value> arg(arrHandle3->Get(Integer::New(j)));
      GLint aux = (GLint)arg->IntegerValue();
      arg3[j] = aux;
  }


  //make call
  glGetFramebufferAttachmentParameteriv((GLenum) arg0, (GLenum) arg1, (GLenum) arg2, (GLint*) arg3);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglGetIntegervCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();


  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
  GLint* arg1 = new GLint[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
      GLint aux = (GLint)arg->IntegerValue();
      arg1[j] = aux;
  }


  //make call
  glGetIntegerv((GLenum) arg0, (GLint*) arg1);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglGetUniformivCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  int arg1 = args[1]->IntegerValue();


  Handle<Array> arrHandle2 = Handle<Array>::Cast(args[2]);
  GLint* arg2 = new GLint[arrHandle2->Length()];
  for (unsigned j = 0; j < arrHandle2->Length(); j++) {
      Handle<Value> arg(arrHandle2->Get(Integer::New(j)));
      GLint aux = (GLint)arg->IntegerValue();
      arg2[j] = aux;
  }


  //make call
  glGetUniformiv((GLuint) arg0, (GLint) arg1, (GLint*) arg2);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglGetUniformLocationCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  String::Utf8Value value1(args[1]);
  char* arg1 = *value1;

  //make call
  return Integer::New(glGetUniformLocation((GLuint) arg0, (const char*) arg1));
}




Handle<Value> GLESglHintCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  unsigned int arg1 = args[1]->Uint32Value();

  //make call
  glHint((GLenum) arg0, (GLenum) arg1);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglIsBufferCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  return Uint32::New(glIsBuffer((GLuint) arg0));
}




Handle<Value> GLESglIsEnabledCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  return Uint32::New(glIsEnabled((GLenum) arg0));
}




Handle<Value> GLESglIsFramebufferCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  return Uint32::New(glIsFramebuffer((GLuint) arg0));
}




Handle<Value> GLESglIsProgramCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  return Uint32::New(glIsProgram((GLuint) arg0));
}




Handle<Value> GLESglIsRenderbufferCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  return Uint32::New(glIsRenderbuffer((GLuint) arg0));
}




Handle<Value> GLESglIsShaderCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  return Uint32::New(glIsShader((GLuint) arg0));
}




Handle<Value> GLESglIsTextureCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  return Uint32::New(glIsTexture((GLuint) arg0));
}




Handle<Value> GLESglLineWidthCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();

  //make call
  glLineWidth((GLfloat) arg0);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglLinkProgramCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  glLinkProgram((GLuint) arg0);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglPixelStoreiCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  int arg1 = args[1]->IntegerValue();

  //make call
  glPixelStorei((GLenum) arg0, (GLint) arg1);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglPolygonOffsetCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();
  double arg1 = args[1]->NumberValue();

  //make call
  glPolygonOffset((GLfloat) arg0, (GLfloat) arg1);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglRenderbufferStorageCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 4) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  unsigned int arg1 = args[1]->Uint32Value();
  int arg2 = args[2]->IntegerValue();
  int arg3 = args[3]->IntegerValue();

  //make call
  glRenderbufferStorage((GLenum) arg0, (GLenum) arg1, (GLsizei) arg2, (GLsizei) arg3);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglSampleCoverageCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();
  unsigned int arg1 = args[1]->Uint32Value();

  //make call
  glSampleCoverage((GLclampf) arg0, (GLboolean) arg1);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglScissorCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 4) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();
  int arg3 = args[3]->IntegerValue();

  //make call
  glScissor((GLint) arg0, (GLint) arg1, (GLsizei) arg2, (GLsizei) arg3);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglStencilFuncCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  int arg1 = args[1]->IntegerValue();
  unsigned int arg2 = args[2]->Uint32Value();

  //make call
  glStencilFunc((GLenum) arg0, (GLint) arg1, (GLuint) arg2);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglStencilFuncSeparateCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 4) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  unsigned int arg1 = args[1]->Uint32Value();
  int arg2 = args[2]->IntegerValue();
  unsigned int arg3 = args[3]->Uint32Value();

  //make call
  glStencilFuncSeparate((GLenum) arg0, (GLenum) arg1, (GLint) arg2, (GLuint) arg3);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglStencilMaskCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  glStencilMask((GLuint) arg0);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglStencilMaskSeparateCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  unsigned int arg1 = args[1]->Uint32Value();

  //make call
  glStencilMaskSeparate((GLenum) arg0, (GLuint) arg1);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglStencilOpCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  unsigned int arg1 = args[1]->Uint32Value();
  unsigned int arg2 = args[2]->Uint32Value();

  //make call
  glStencilOp((GLenum) arg0, (GLenum) arg1, (GLenum) arg2);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglStencilOpSeparateCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 4) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  unsigned int arg1 = args[1]->Uint32Value();
  unsigned int arg2 = args[2]->Uint32Value();
  unsigned int arg3 = args[3]->Uint32Value();

  //make call
  glStencilOpSeparate((GLenum) arg0, (GLenum) arg1, (GLenum) arg2, (GLenum) arg3);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglTexParameterfCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  unsigned int arg1 = args[1]->Uint32Value();
  double arg2 = args[2]->NumberValue();

  //make call
  glTexParameterf((GLenum) arg0, (GLenum) arg1, (GLfloat) arg2);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglTexParameterfvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  unsigned int arg1 = args[1]->Uint32Value();


  Handle<Array> arrHandle2 = Handle<Array>::Cast(args[2]);
   GLfloat* arg2 = new  GLfloat[arrHandle2->Length()];
  for (unsigned j = 0; j < arrHandle2->Length(); j++) {
      Handle<Value> arg(arrHandle2->Get(Integer::New(j)));
       GLfloat aux = ( GLfloat)arg->NumberValue();
      arg2[j] = aux;
  }


  //make call
  glTexParameterfv((GLenum) arg0, (GLenum) arg1, (const GLfloat*) arg2);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglTexParameteriCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  unsigned int arg1 = args[1]->Uint32Value();
  int arg2 = args[2]->IntegerValue();

  //make call
  glTexParameteri((GLenum) arg0, (GLenum) arg1, (GLint) arg2);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglTexParameterivCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  unsigned int arg1 = args[1]->Uint32Value();


  Handle<Array> arrHandle2 = Handle<Array>::Cast(args[2]);
   GLint* arg2 = new  GLint[arrHandle2->Length()];
  for (unsigned j = 0; j < arrHandle2->Length(); j++) {
      Handle<Value> arg(arrHandle2->Get(Integer::New(j)));
       GLint aux = ( GLint)arg->IntegerValue();
      arg2[j] = aux;
  }


  //make call
  glTexParameteriv((GLenum) arg0, (GLenum) arg1, (const GLint*) arg2);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglUniform1fCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  double arg1 = args[1]->NumberValue();

  //make call
  glUniform1f((GLint) arg0, (GLfloat) arg1);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglUniform1fvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();


  Handle<Array> arrHandle2 = Handle<Array>::Cast(args[2]);
   GLfloat* arg2 = new  GLfloat[arrHandle2->Length()];
  for (unsigned j = 0; j < arrHandle2->Length(); j++) {
      Handle<Value> arg(arrHandle2->Get(Integer::New(j)));
       GLfloat aux = ( GLfloat)arg->NumberValue();
      arg2[j] = aux;
  }


  //make call
  glUniform1fv((GLint) arg0, (GLsizei) arg1, (const GLfloat*) arg2);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglUniform1iCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();

  //make call
  glUniform1i((GLint) arg0, (GLint) arg1);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglUniform1ivCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();


  Handle<Array> arrHandle2 = Handle<Array>::Cast(args[2]);
   GLint* arg2 = new  GLint[arrHandle2->Length()];
  for (unsigned j = 0; j < arrHandle2->Length(); j++) {
      Handle<Value> arg(arrHandle2->Get(Integer::New(j)));
       GLint aux = ( GLint)arg->IntegerValue();
      arg2[j] = aux;
  }


  //make call
  glUniform1iv((GLint) arg0, (GLsizei) arg1, (const GLint*) arg2);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglUniform2fCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  double arg1 = args[1]->NumberValue();
  double arg2 = args[2]->NumberValue();

  //make call
  glUniform2f((GLint) arg0, (GLfloat) arg1, (GLfloat) arg2);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglUniform2fvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();


  Handle<Array> arrHandle2 = Handle<Array>::Cast(args[2]);
   GLfloat* arg2 = new  GLfloat[arrHandle2->Length()];
  for (unsigned j = 0; j < arrHandle2->Length(); j++) {
      Handle<Value> arg(arrHandle2->Get(Integer::New(j)));
       GLfloat aux = ( GLfloat)arg->NumberValue();
      arg2[j] = aux;
  }


  //make call
  glUniform2fv((GLint) arg0, (GLsizei) arg1, (const GLfloat*) arg2);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglUniform2iCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();

  //make call
  glUniform2i((GLint) arg0, (GLint) arg1, (GLint) arg2);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglUniform2ivCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();


  Handle<Array> arrHandle2 = Handle<Array>::Cast(args[2]);
   GLint* arg2 = new  GLint[arrHandle2->Length()];
  for (unsigned j = 0; j < arrHandle2->Length(); j++) {
      Handle<Value> arg(arrHandle2->Get(Integer::New(j)));
       GLint aux = ( GLint)arg->IntegerValue();
      arg2[j] = aux;
  }


  //make call
  glUniform2iv((GLint) arg0, (GLsizei) arg1, (const GLint*) arg2);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglUniform3fCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 4) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  double arg1 = args[1]->NumberValue();
  double arg2 = args[2]->NumberValue();
  double arg3 = args[3]->NumberValue();

  //make call
  glUniform3f((GLint) arg0, (GLfloat) arg1, (GLfloat) arg2, (GLfloat) arg3);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglUniform3fvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();


  Handle<Array> arrHandle2 = Handle<Array>::Cast(args[2]);
   GLfloat* arg2 = new  GLfloat[arrHandle2->Length()];
  for (unsigned j = 0; j < arrHandle2->Length(); j++) {
      Handle<Value> arg(arrHandle2->Get(Integer::New(j)));
       GLfloat aux = ( GLfloat)arg->NumberValue();
      arg2[j] = aux;
  }


  //make call
  glUniform3fv((GLint) arg0, (GLsizei) arg1, (const GLfloat*) arg2);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglUniform3iCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 4) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();
  int arg3 = args[3]->IntegerValue();

  //make call
  glUniform3i((GLint) arg0, (GLint) arg1, (GLint) arg2, (GLint) arg3);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglUniform3ivCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();


  Handle<Array> arrHandle2 = Handle<Array>::Cast(args[2]);
   GLint* arg2 = new  GLint[arrHandle2->Length()];
  for (unsigned j = 0; j < arrHandle2->Length(); j++) {
      Handle<Value> arg(arrHandle2->Get(Integer::New(j)));
       GLint aux = ( GLint)arg->IntegerValue();
      arg2[j] = aux;
  }


  //make call
  glUniform3iv((GLint) arg0, (GLsizei) arg1, (const GLint*) arg2);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglUniform4fCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 5) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  double arg1 = args[1]->NumberValue();
  double arg2 = args[2]->NumberValue();
  double arg3 = args[3]->NumberValue();
  double arg4 = args[4]->NumberValue();

  //make call
  glUniform4f((GLint) arg0, (GLfloat) arg1, (GLfloat) arg2, (GLfloat) arg3, (GLfloat) arg4);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglUniform4fvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();


  Handle<Array> arrHandle2 = Handle<Array>::Cast(args[2]);
   GLfloat* arg2 = new  GLfloat[arrHandle2->Length()];
  for (unsigned j = 0; j < arrHandle2->Length(); j++) {
      Handle<Value> arg(arrHandle2->Get(Integer::New(j)));
       GLfloat aux = ( GLfloat)arg->NumberValue();
      arg2[j] = aux;
  }


  //make call
  glUniform4fv((GLint) arg0, (GLsizei) arg1, (const GLfloat*) arg2);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglUniform4iCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 5) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();
  int arg3 = args[3]->IntegerValue();
  int arg4 = args[4]->IntegerValue();

  //make call
  glUniform4i((GLint) arg0, (GLint) arg1, (GLint) arg2, (GLint) arg3, (GLint) arg4);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglUniform4ivCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();


  Handle<Array> arrHandle2 = Handle<Array>::Cast(args[2]);
   GLint* arg2 = new  GLint[arrHandle2->Length()];
  for (unsigned j = 0; j < arrHandle2->Length(); j++) {
      Handle<Value> arg(arrHandle2->Get(Integer::New(j)));
       GLint aux = ( GLint)arg->IntegerValue();
      arg2[j] = aux;
  }


  //make call
  glUniform4iv((GLint) arg0, (GLsizei) arg1, (const GLint*) arg2);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglUniformMatrix2fvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 4) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  unsigned int arg2 = args[2]->Uint32Value();


  Handle<Array> arrHandle3 = Handle<Array>::Cast(args[3]);
   GLfloat* arg3 = new  GLfloat[arrHandle3->Length()];
  for (unsigned j = 0; j < arrHandle3->Length(); j++) {
      Handle<Value> arg(arrHandle3->Get(Integer::New(j)));
       GLfloat aux = ( GLfloat)arg->NumberValue();
      arg3[j] = aux;
  }


  //make call
  glUniformMatrix2fv((GLint) arg0, (GLsizei) arg1, (GLboolean) arg2, (const GLfloat*) arg3);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglUniformMatrix3fvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 4) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  unsigned int arg2 = args[2]->Uint32Value();


  Handle<Array> arrHandle3 = Handle<Array>::Cast(args[3]);
   GLfloat* arg3 = new  GLfloat[arrHandle3->Length()];
  for (unsigned j = 0; j < arrHandle3->Length(); j++) {
      Handle<Value> arg(arrHandle3->Get(Integer::New(j)));
       GLfloat aux = ( GLfloat)arg->NumberValue();
      arg3[j] = aux;
  }


  //make call
  glUniformMatrix3fv((GLint) arg0, (GLsizei) arg1, (GLboolean) arg2, (const GLfloat*) arg3);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglUniformMatrix4fvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 4) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  unsigned int arg2 = args[2]->Uint32Value();


  Handle<Array> arrHandle3 = Handle<Array>::Cast(args[3]);
   GLfloat* arg3 = new  GLfloat[arrHandle3->Length()];
  for (unsigned j = 0; j < arrHandle3->Length(); j++) {
      Handle<Value> arg(arrHandle3->Get(Integer::New(j)));
       GLfloat aux = ( GLfloat)arg->NumberValue();
      arg3[j] = aux;
  }


  //make call
  glUniformMatrix4fv((GLint) arg0, (GLsizei) arg1, (GLboolean) arg2, (const GLfloat*) arg3);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglUseProgramCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  glUseProgram((GLuint) arg0);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglValidateProgramCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  glValidateProgram((GLuint) arg0);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglVertexAttrib1fCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  double arg1 = args[1]->NumberValue();

  //make call
  glVertexAttrib1f((GLuint) arg0, (GLfloat) arg1);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglVertexAttrib1fvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();


  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLfloat* arg1 = new  GLfloat[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLfloat aux = ( GLfloat)arg->NumberValue();
      arg1[j] = aux;
  }


  //make call
  glVertexAttrib1fv((GLuint) arg0, (const GLfloat*) arg1);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglVertexAttrib2fCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  double arg1 = args[1]->NumberValue();
  double arg2 = args[2]->NumberValue();

  //make call
  glVertexAttrib2f((GLuint) arg0, (GLfloat) arg1, (GLfloat) arg2);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglVertexAttrib2fvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();


  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLfloat* arg1 = new  GLfloat[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLfloat aux = ( GLfloat)arg->NumberValue();
      arg1[j] = aux;
  }


  //make call
  glVertexAttrib2fv((GLuint) arg0, (const GLfloat*) arg1);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglVertexAttrib3fCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 4) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  double arg1 = args[1]->NumberValue();
  double arg2 = args[2]->NumberValue();
  double arg3 = args[3]->NumberValue();

  //make call
  glVertexAttrib3f((GLuint) arg0, (GLfloat) arg1, (GLfloat) arg2, (GLfloat) arg3);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglVertexAttrib3fvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();


  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLfloat* arg1 = new  GLfloat[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLfloat aux = ( GLfloat)arg->NumberValue();
      arg1[j] = aux;
  }


  //make call
  glVertexAttrib3fv((GLuint) arg0, (const GLfloat*) arg1);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglVertexAttrib4fCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 5) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  double arg1 = args[1]->NumberValue();
  double arg2 = args[2]->NumberValue();
  double arg3 = args[3]->NumberValue();
  double arg4 = args[4]->NumberValue();

  //make call
  glVertexAttrib4f((GLuint) arg0, (GLfloat) arg1, (GLfloat) arg2, (GLfloat) arg3, (GLfloat) arg4);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglVertexAttrib4fvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();


  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLfloat* arg1 = new  GLfloat[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLfloat aux = ( GLfloat)arg->NumberValue();
      arg1[j] = aux;
  }


  //make call
  glVertexAttrib4fv((GLuint) arg0, (const GLfloat*) arg1);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglViewportCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 4) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();
  int arg3 = args[3]->IntegerValue();

  //make call
  glViewport((GLint) arg0, (GLint) arg1, (GLsizei) arg2, (GLsizei) arg3);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<ObjectTemplate> GlesFactory::createGles(void) {
      HandleScope handle_scope;

      Handle<ObjectTemplate> Gles = ObjectTemplate::New();
      
      Gles->SetInternalFieldCount(1);

     Gles->Set(String::NewSymbol("ES_VERSION_2_0"), Uint32::New(GL_ES_VERSION_2_0), ReadOnly);

     Gles->Set(String::NewSymbol("DEPTH_BUFFER_BIT"), Uint32::New(GL_DEPTH_BUFFER_BIT), ReadOnly);

     Gles->Set(String::NewSymbol("STENCIL_BUFFER_BIT"), Uint32::New(GL_STENCIL_BUFFER_BIT), ReadOnly);

     Gles->Set(String::NewSymbol("COLOR_BUFFER_BIT"), Uint32::New(GL_COLOR_BUFFER_BIT), ReadOnly);

     Gles->Set(String::NewSymbol("FALSE"), Uint32::New(GL_FALSE), ReadOnly);

     Gles->Set(String::NewSymbol("TRUE"), Uint32::New(GL_TRUE), ReadOnly);

     Gles->Set(String::NewSymbol("POINTS"), Uint32::New(GL_POINTS), ReadOnly);

     Gles->Set(String::NewSymbol("LINES"), Uint32::New(GL_LINES), ReadOnly);

     Gles->Set(String::NewSymbol("LINE_LOOP"), Uint32::New(GL_LINE_LOOP), ReadOnly);

     Gles->Set(String::NewSymbol("LINE_STRIP"), Uint32::New(GL_LINE_STRIP), ReadOnly);

     Gles->Set(String::NewSymbol("TRIANGLES"), Uint32::New(GL_TRIANGLES), ReadOnly);

     Gles->Set(String::NewSymbol("TRIANGLE_STRIP"), Uint32::New(GL_TRIANGLE_STRIP), ReadOnly);

     Gles->Set(String::NewSymbol("TRIANGLE_FAN"), Uint32::New(GL_TRIANGLE_FAN), ReadOnly);

     Gles->Set(String::NewSymbol("ZERO"), Uint32::New(GL_ZERO), ReadOnly);

     Gles->Set(String::NewSymbol("ONE"), Uint32::New(GL_ONE), ReadOnly);

     Gles->Set(String::NewSymbol("SRC_COLOR"), Uint32::New(GL_SRC_COLOR), ReadOnly);

     Gles->Set(String::NewSymbol("ONE_MINUS_SRC_COLOR"), Uint32::New(GL_ONE_MINUS_SRC_COLOR), ReadOnly);

     Gles->Set(String::NewSymbol("SRC_ALPHA"), Uint32::New(GL_SRC_ALPHA), ReadOnly);

     Gles->Set(String::NewSymbol("ONE_MINUS_SRC_ALPHA"), Uint32::New(GL_ONE_MINUS_SRC_ALPHA), ReadOnly);

     Gles->Set(String::NewSymbol("DST_ALPHA"), Uint32::New(GL_DST_ALPHA), ReadOnly);

     Gles->Set(String::NewSymbol("ONE_MINUS_DST_ALPHA"), Uint32::New(GL_ONE_MINUS_DST_ALPHA), ReadOnly);

     Gles->Set(String::NewSymbol("DST_COLOR"), Uint32::New(GL_DST_COLOR), ReadOnly);

     Gles->Set(String::NewSymbol("ONE_MINUS_DST_COLOR"), Uint32::New(GL_ONE_MINUS_DST_COLOR), ReadOnly);

     Gles->Set(String::NewSymbol("SRC_ALPHA_SATURATE"), Uint32::New(GL_SRC_ALPHA_SATURATE), ReadOnly);

     Gles->Set(String::NewSymbol("FUNC_ADD"), Uint32::New(GL_FUNC_ADD), ReadOnly);

     Gles->Set(String::NewSymbol("BLEND_EQUATION"), Uint32::New(GL_BLEND_EQUATION), ReadOnly);

     Gles->Set(String::NewSymbol("BLEND_EQUATION_RGB"), Uint32::New(GL_BLEND_EQUATION_RGB), ReadOnly);

     Gles->Set(String::NewSymbol("BLEND_EQUATION_ALPHA"), Uint32::New(GL_BLEND_EQUATION_ALPHA), ReadOnly);

     Gles->Set(String::NewSymbol("FUNC_SUBTRACT"), Uint32::New(GL_FUNC_SUBTRACT), ReadOnly);

     Gles->Set(String::NewSymbol("FUNC_REVERSE_SUBTRACT"), Uint32::New(GL_FUNC_REVERSE_SUBTRACT), ReadOnly);

     Gles->Set(String::NewSymbol("BLEND_DST_RGB"), Uint32::New(GL_BLEND_DST_RGB), ReadOnly);

     Gles->Set(String::NewSymbol("BLEND_SRC_RGB"), Uint32::New(GL_BLEND_SRC_RGB), ReadOnly);

     Gles->Set(String::NewSymbol("BLEND_DST_ALPHA"), Uint32::New(GL_BLEND_DST_ALPHA), ReadOnly);

     Gles->Set(String::NewSymbol("BLEND_SRC_ALPHA"), Uint32::New(GL_BLEND_SRC_ALPHA), ReadOnly);

     Gles->Set(String::NewSymbol("CONSTANT_COLOR"), Uint32::New(GL_CONSTANT_COLOR), ReadOnly);

     Gles->Set(String::NewSymbol("ONE_MINUS_CONSTANT_COLOR"), Uint32::New(GL_ONE_MINUS_CONSTANT_COLOR), ReadOnly);

     Gles->Set(String::NewSymbol("CONSTANT_ALPHA"), Uint32::New(GL_CONSTANT_ALPHA), ReadOnly);

     Gles->Set(String::NewSymbol("ONE_MINUS_CONSTANT_ALPHA"), Uint32::New(GL_ONE_MINUS_CONSTANT_ALPHA), ReadOnly);

     Gles->Set(String::NewSymbol("BLEND_COLOR"), Uint32::New(GL_BLEND_COLOR), ReadOnly);

     Gles->Set(String::NewSymbol("ARRAY_BUFFER"), Uint32::New(GL_ARRAY_BUFFER), ReadOnly);

     Gles->Set(String::NewSymbol("ELEMENT_ARRAY_BUFFER"), Uint32::New(GL_ELEMENT_ARRAY_BUFFER), ReadOnly);

     Gles->Set(String::NewSymbol("ARRAY_BUFFER_BINDING"), Uint32::New(GL_ARRAY_BUFFER_BINDING), ReadOnly);

     Gles->Set(String::NewSymbol("ELEMENT_ARRAY_BUFFER_BINDING"), Uint32::New(GL_ELEMENT_ARRAY_BUFFER_BINDING), ReadOnly);

     Gles->Set(String::NewSymbol("STREAM_DRAW"), Uint32::New(GL_STREAM_DRAW), ReadOnly);

     Gles->Set(String::NewSymbol("STATIC_DRAW"), Uint32::New(GL_STATIC_DRAW), ReadOnly);

     Gles->Set(String::NewSymbol("DYNAMIC_DRAW"), Uint32::New(GL_DYNAMIC_DRAW), ReadOnly);

     Gles->Set(String::NewSymbol("BUFFER_SIZE"), Uint32::New(GL_BUFFER_SIZE), ReadOnly);

     Gles->Set(String::NewSymbol("BUFFER_USAGE"), Uint32::New(GL_BUFFER_USAGE), ReadOnly);

     Gles->Set(String::NewSymbol("CURRENT_VERTEX_ATTRIB"), Uint32::New(GL_CURRENT_VERTEX_ATTRIB), ReadOnly);

     Gles->Set(String::NewSymbol("FRONT"), Uint32::New(GL_FRONT), ReadOnly);

     Gles->Set(String::NewSymbol("BACK"), Uint32::New(GL_BACK), ReadOnly);

     Gles->Set(String::NewSymbol("FRONT_AND_BACK"), Uint32::New(GL_FRONT_AND_BACK), ReadOnly);

     Gles->Set(String::NewSymbol("TEXTURE_2D"), Uint32::New(GL_TEXTURE_2D), ReadOnly);

     Gles->Set(String::NewSymbol("CULL_FACE"), Uint32::New(GL_CULL_FACE), ReadOnly);

     Gles->Set(String::NewSymbol("BLEND"), Uint32::New(GL_BLEND), ReadOnly);

     Gles->Set(String::NewSymbol("DITHER"), Uint32::New(GL_DITHER), ReadOnly);

     Gles->Set(String::NewSymbol("STENCIL_TEST"), Uint32::New(GL_STENCIL_TEST), ReadOnly);

     Gles->Set(String::NewSymbol("DEPTH_TEST"), Uint32::New(GL_DEPTH_TEST), ReadOnly);

     Gles->Set(String::NewSymbol("SCISSOR_TEST"), Uint32::New(GL_SCISSOR_TEST), ReadOnly);

     Gles->Set(String::NewSymbol("POLYGON_OFFSET_FILL"), Uint32::New(GL_POLYGON_OFFSET_FILL), ReadOnly);

     Gles->Set(String::NewSymbol("SAMPLE_ALPHA_TO_COVERAGE"), Uint32::New(GL_SAMPLE_ALPHA_TO_COVERAGE), ReadOnly);

     Gles->Set(String::NewSymbol("SAMPLE_COVERAGE"), Uint32::New(GL_SAMPLE_COVERAGE), ReadOnly);

     Gles->Set(String::NewSymbol("NO_ERROR"), Uint32::New(GL_NO_ERROR), ReadOnly);

     Gles->Set(String::NewSymbol("INVALID_ENUM"), Uint32::New(GL_INVALID_ENUM), ReadOnly);

     Gles->Set(String::NewSymbol("INVALID_VALUE"), Uint32::New(GL_INVALID_VALUE), ReadOnly);

     Gles->Set(String::NewSymbol("INVALID_OPERATION"), Uint32::New(GL_INVALID_OPERATION), ReadOnly);

     Gles->Set(String::NewSymbol("OUT_OF_MEMORY"), Uint32::New(GL_OUT_OF_MEMORY), ReadOnly);

     Gles->Set(String::NewSymbol("CW"), Uint32::New(GL_CW), ReadOnly);

     Gles->Set(String::NewSymbol("CCW"), Uint32::New(GL_CCW), ReadOnly);

     Gles->Set(String::NewSymbol("LINE_WIDTH"), Uint32::New(GL_LINE_WIDTH), ReadOnly);

     Gles->Set(String::NewSymbol("ALIASED_POINT_SIZE_RANGE"), Uint32::New(GL_ALIASED_POINT_SIZE_RANGE), ReadOnly);

     Gles->Set(String::NewSymbol("ALIASED_LINE_WIDTH_RANGE"), Uint32::New(GL_ALIASED_LINE_WIDTH_RANGE), ReadOnly);

     Gles->Set(String::NewSymbol("CULL_FACE_MODE"), Uint32::New(GL_CULL_FACE_MODE), ReadOnly);

     Gles->Set(String::NewSymbol("FRONT_FACE"), Uint32::New(GL_FRONT_FACE), ReadOnly);

     Gles->Set(String::NewSymbol("DEPTH_RANGE"), Uint32::New(GL_DEPTH_RANGE), ReadOnly);

     Gles->Set(String::NewSymbol("DEPTH_WRITEMASK"), Uint32::New(GL_DEPTH_WRITEMASK), ReadOnly);

     Gles->Set(String::NewSymbol("DEPTH_CLEAR_VALUE"), Uint32::New(GL_DEPTH_CLEAR_VALUE), ReadOnly);

     Gles->Set(String::NewSymbol("DEPTH_FUNC"), Uint32::New(GL_DEPTH_FUNC), ReadOnly);

     Gles->Set(String::NewSymbol("STENCIL_CLEAR_VALUE"), Uint32::New(GL_STENCIL_CLEAR_VALUE), ReadOnly);

     Gles->Set(String::NewSymbol("STENCIL_FUNC"), Uint32::New(GL_STENCIL_FUNC), ReadOnly);

     Gles->Set(String::NewSymbol("STENCIL_FAIL"), Uint32::New(GL_STENCIL_FAIL), ReadOnly);

     Gles->Set(String::NewSymbol("STENCIL_PASS_DEPTH_FAIL"), Uint32::New(GL_STENCIL_PASS_DEPTH_FAIL), ReadOnly);

     Gles->Set(String::NewSymbol("STENCIL_PASS_DEPTH_PASS"), Uint32::New(GL_STENCIL_PASS_DEPTH_PASS), ReadOnly);

     Gles->Set(String::NewSymbol("STENCIL_REF"), Uint32::New(GL_STENCIL_REF), ReadOnly);

     Gles->Set(String::NewSymbol("STENCIL_VALUE_MASK"), Uint32::New(GL_STENCIL_VALUE_MASK), ReadOnly);

     Gles->Set(String::NewSymbol("STENCIL_WRITEMASK"), Uint32::New(GL_STENCIL_WRITEMASK), ReadOnly);

     Gles->Set(String::NewSymbol("STENCIL_BACK_FUNC"), Uint32::New(GL_STENCIL_BACK_FUNC), ReadOnly);

     Gles->Set(String::NewSymbol("STENCIL_BACK_FAIL"), Uint32::New(GL_STENCIL_BACK_FAIL), ReadOnly);

     Gles->Set(String::NewSymbol("STENCIL_BACK_PASS_DEPTH_FAIL"), Uint32::New(GL_STENCIL_BACK_PASS_DEPTH_FAIL), ReadOnly);

     Gles->Set(String::NewSymbol("STENCIL_BACK_PASS_DEPTH_PASS"), Uint32::New(GL_STENCIL_BACK_PASS_DEPTH_PASS), ReadOnly);

     Gles->Set(String::NewSymbol("STENCIL_BACK_REF"), Uint32::New(GL_STENCIL_BACK_REF), ReadOnly);

     Gles->Set(String::NewSymbol("STENCIL_BACK_VALUE_MASK"), Uint32::New(GL_STENCIL_BACK_VALUE_MASK), ReadOnly);

     Gles->Set(String::NewSymbol("STENCIL_BACK_WRITEMASK"), Uint32::New(GL_STENCIL_BACK_WRITEMASK), ReadOnly);

     Gles->Set(String::NewSymbol("VIEWPORT"), Uint32::New(GL_VIEWPORT), ReadOnly);

     Gles->Set(String::NewSymbol("SCISSOR_BOX"), Uint32::New(GL_SCISSOR_BOX), ReadOnly);

     Gles->Set(String::NewSymbol("COLOR_CLEAR_VALUE"), Uint32::New(GL_COLOR_CLEAR_VALUE), ReadOnly);

     Gles->Set(String::NewSymbol("COLOR_WRITEMASK"), Uint32::New(GL_COLOR_WRITEMASK), ReadOnly);

     Gles->Set(String::NewSymbol("UNPACK_ALIGNMENT"), Uint32::New(GL_UNPACK_ALIGNMENT), ReadOnly);

     Gles->Set(String::NewSymbol("PACK_ALIGNMENT"), Uint32::New(GL_PACK_ALIGNMENT), ReadOnly);

     Gles->Set(String::NewSymbol("MAX_TEXTURE_SIZE"), Uint32::New(GL_MAX_TEXTURE_SIZE), ReadOnly);

     Gles->Set(String::NewSymbol("MAX_VIEWPORT_DIMS"), Uint32::New(GL_MAX_VIEWPORT_DIMS), ReadOnly);

     Gles->Set(String::NewSymbol("SUBPIXEL_BITS"), Uint32::New(GL_SUBPIXEL_BITS), ReadOnly);

     Gles->Set(String::NewSymbol("RED_BITS"), Uint32::New(GL_RED_BITS), ReadOnly);

     Gles->Set(String::NewSymbol("GREEN_BITS"), Uint32::New(GL_GREEN_BITS), ReadOnly);

     Gles->Set(String::NewSymbol("BLUE_BITS"), Uint32::New(GL_BLUE_BITS), ReadOnly);

     Gles->Set(String::NewSymbol("ALPHA_BITS"), Uint32::New(GL_ALPHA_BITS), ReadOnly);

     Gles->Set(String::NewSymbol("DEPTH_BITS"), Uint32::New(GL_DEPTH_BITS), ReadOnly);

     Gles->Set(String::NewSymbol("STENCIL_BITS"), Uint32::New(GL_STENCIL_BITS), ReadOnly);

     Gles->Set(String::NewSymbol("POLYGON_OFFSET_UNITS"), Uint32::New(GL_POLYGON_OFFSET_UNITS), ReadOnly);

     Gles->Set(String::NewSymbol("POLYGON_OFFSET_FACTOR"), Uint32::New(GL_POLYGON_OFFSET_FACTOR), ReadOnly);

     Gles->Set(String::NewSymbol("TEXTURE_BINDING_2D"), Uint32::New(GL_TEXTURE_BINDING_2D), ReadOnly);

     Gles->Set(String::NewSymbol("SAMPLE_BUFFERS"), Uint32::New(GL_SAMPLE_BUFFERS), ReadOnly);

     Gles->Set(String::NewSymbol("SAMPLES"), Uint32::New(GL_SAMPLES), ReadOnly);

     Gles->Set(String::NewSymbol("SAMPLE_COVERAGE_VALUE"), Uint32::New(GL_SAMPLE_COVERAGE_VALUE), ReadOnly);

     Gles->Set(String::NewSymbol("SAMPLE_COVERAGE_INVERT"), Uint32::New(GL_SAMPLE_COVERAGE_INVERT), ReadOnly);

     Gles->Set(String::NewSymbol("NUM_COMPRESSED_TEXTURE_FORMATS"), Uint32::New(GL_NUM_COMPRESSED_TEXTURE_FORMATS), ReadOnly);

     Gles->Set(String::NewSymbol("COMPRESSED_TEXTURE_FORMATS"), Uint32::New(GL_COMPRESSED_TEXTURE_FORMATS), ReadOnly);

     Gles->Set(String::NewSymbol("DONT_CARE"), Uint32::New(GL_DONT_CARE), ReadOnly);

     Gles->Set(String::NewSymbol("FASTEST"), Uint32::New(GL_FASTEST), ReadOnly);

     Gles->Set(String::NewSymbol("NICEST"), Uint32::New(GL_NICEST), ReadOnly);

     Gles->Set(String::NewSymbol("GENERATE_MIPMAP_HINT"), Uint32::New(GL_GENERATE_MIPMAP_HINT), ReadOnly);

     Gles->Set(String::NewSymbol("BYTE"), Uint32::New(GL_BYTE), ReadOnly);

     Gles->Set(String::NewSymbol("UNSIGNED_BYTE"), Uint32::New(GL_UNSIGNED_BYTE), ReadOnly);

     Gles->Set(String::NewSymbol("SHORT"), Uint32::New(GL_SHORT), ReadOnly);

     Gles->Set(String::NewSymbol("UNSIGNED_SHORT"), Uint32::New(GL_UNSIGNED_SHORT), ReadOnly);

     Gles->Set(String::NewSymbol("INT"), Uint32::New(GL_INT), ReadOnly);

     Gles->Set(String::NewSymbol("UNSIGNED_INT"), Uint32::New(GL_UNSIGNED_INT), ReadOnly);

     Gles->Set(String::NewSymbol("FLOAT"), Uint32::New(GL_FLOAT), ReadOnly);

     Gles->Set(String::NewSymbol("FIXED"), Uint32::New(GL_FIXED), ReadOnly);

     Gles->Set(String::NewSymbol("DEPTH_COMPONENT"), Uint32::New(GL_DEPTH_COMPONENT), ReadOnly);

     Gles->Set(String::NewSymbol("ALPHA"), Uint32::New(GL_ALPHA), ReadOnly);

     Gles->Set(String::NewSymbol("RGB"), Uint32::New(GL_RGB), ReadOnly);

     Gles->Set(String::NewSymbol("RGBA"), Uint32::New(GL_RGBA), ReadOnly);

     Gles->Set(String::NewSymbol("LUMINANCE"), Uint32::New(GL_LUMINANCE), ReadOnly);

     Gles->Set(String::NewSymbol("LUMINANCE_ALPHA"), Uint32::New(GL_LUMINANCE_ALPHA), ReadOnly);

     Gles->Set(String::NewSymbol("UNSIGNED_SHORT_4_4_4_4"), Uint32::New(GL_UNSIGNED_SHORT_4_4_4_4), ReadOnly);

     Gles->Set(String::NewSymbol("UNSIGNED_SHORT_5_5_5_1"), Uint32::New(GL_UNSIGNED_SHORT_5_5_5_1), ReadOnly);

     Gles->Set(String::NewSymbol("UNSIGNED_SHORT_5_6_5"), Uint32::New(GL_UNSIGNED_SHORT_5_6_5), ReadOnly);

     Gles->Set(String::NewSymbol("FRAGMENT_SHADER"), Uint32::New(GL_FRAGMENT_SHADER), ReadOnly);

     Gles->Set(String::NewSymbol("VERTEX_SHADER"), Uint32::New(GL_VERTEX_SHADER), ReadOnly);

     Gles->Set(String::NewSymbol("MAX_VERTEX_ATTRIBS"), Uint32::New(GL_MAX_VERTEX_ATTRIBS), ReadOnly);

     Gles->Set(String::NewSymbol("MAX_VERTEX_UNIFORM_VECTORS"), Uint32::New(GL_MAX_VERTEX_UNIFORM_VECTORS), ReadOnly);

     Gles->Set(String::NewSymbol("MAX_VARYING_VECTORS"), Uint32::New(GL_MAX_VARYING_VECTORS), ReadOnly);

     Gles->Set(String::NewSymbol("MAX_COMBINED_TEXTURE_IMAGE_UNITS"), Uint32::New(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS), ReadOnly);

     Gles->Set(String::NewSymbol("MAX_VERTEX_TEXTURE_IMAGE_UNITS"), Uint32::New(GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS), ReadOnly);

     Gles->Set(String::NewSymbol("MAX_TEXTURE_IMAGE_UNITS"), Uint32::New(GL_MAX_TEXTURE_IMAGE_UNITS), ReadOnly);

     Gles->Set(String::NewSymbol("MAX_FRAGMENT_UNIFORM_VECTORS"), Uint32::New(GL_MAX_FRAGMENT_UNIFORM_VECTORS), ReadOnly);

     Gles->Set(String::NewSymbol("SHADER_TYPE"), Uint32::New(GL_SHADER_TYPE), ReadOnly);

     Gles->Set(String::NewSymbol("DELETE_STATUS"), Uint32::New(GL_DELETE_STATUS), ReadOnly);

     Gles->Set(String::NewSymbol("LINK_STATUS"), Uint32::New(GL_LINK_STATUS), ReadOnly);

     Gles->Set(String::NewSymbol("VALIDATE_STATUS"), Uint32::New(GL_VALIDATE_STATUS), ReadOnly);

     Gles->Set(String::NewSymbol("ATTACHED_SHADERS"), Uint32::New(GL_ATTACHED_SHADERS), ReadOnly);

     Gles->Set(String::NewSymbol("ACTIVE_UNIFORMS"), Uint32::New(GL_ACTIVE_UNIFORMS), ReadOnly);

     Gles->Set(String::NewSymbol("ACTIVE_UNIFORM_MAX_LENGTH"), Uint32::New(GL_ACTIVE_UNIFORM_MAX_LENGTH), ReadOnly);

     Gles->Set(String::NewSymbol("ACTIVE_ATTRIBUTES"), Uint32::New(GL_ACTIVE_ATTRIBUTES), ReadOnly);

     Gles->Set(String::NewSymbol("ACTIVE_ATTRIBUTE_MAX_LENGTH"), Uint32::New(GL_ACTIVE_ATTRIBUTE_MAX_LENGTH), ReadOnly);

     Gles->Set(String::NewSymbol("SHADING_LANGUAGE_VERSION"), Uint32::New(GL_SHADING_LANGUAGE_VERSION), ReadOnly);

     Gles->Set(String::NewSymbol("CURRENT_PROGRAM"), Uint32::New(GL_CURRENT_PROGRAM), ReadOnly);

     Gles->Set(String::NewSymbol("NEVER"), Uint32::New(GL_NEVER), ReadOnly);

     Gles->Set(String::NewSymbol("LESS"), Uint32::New(GL_LESS), ReadOnly);

     Gles->Set(String::NewSymbol("EQUAL"), Uint32::New(GL_EQUAL), ReadOnly);

     Gles->Set(String::NewSymbol("LEQUAL"), Uint32::New(GL_LEQUAL), ReadOnly);

     Gles->Set(String::NewSymbol("GREATER"), Uint32::New(GL_GREATER), ReadOnly);

     Gles->Set(String::NewSymbol("NOTEQUAL"), Uint32::New(GL_NOTEQUAL), ReadOnly);

     Gles->Set(String::NewSymbol("GEQUAL"), Uint32::New(GL_GEQUAL), ReadOnly);

     Gles->Set(String::NewSymbol("ALWAYS"), Uint32::New(GL_ALWAYS), ReadOnly);

     Gles->Set(String::NewSymbol("KEEP"), Uint32::New(GL_KEEP), ReadOnly);

     Gles->Set(String::NewSymbol("REPLACE"), Uint32::New(GL_REPLACE), ReadOnly);

     Gles->Set(String::NewSymbol("INCR"), Uint32::New(GL_INCR), ReadOnly);

     Gles->Set(String::NewSymbol("DECR"), Uint32::New(GL_DECR), ReadOnly);

     Gles->Set(String::NewSymbol("INVERT"), Uint32::New(GL_INVERT), ReadOnly);

     Gles->Set(String::NewSymbol("INCR_WRAP"), Uint32::New(GL_INCR_WRAP), ReadOnly);

     Gles->Set(String::NewSymbol("DECR_WRAP"), Uint32::New(GL_DECR_WRAP), ReadOnly);

     Gles->Set(String::NewSymbol("VENDOR"), Uint32::New(GL_VENDOR), ReadOnly);

     Gles->Set(String::NewSymbol("RENDERER"), Uint32::New(GL_RENDERER), ReadOnly);

     Gles->Set(String::NewSymbol("VERSION"), Uint32::New(GL_VERSION), ReadOnly);

     Gles->Set(String::NewSymbol("EXTENSIONS"), Uint32::New(GL_EXTENSIONS), ReadOnly);

     Gles->Set(String::NewSymbol("NEAREST"), Uint32::New(GL_NEAREST), ReadOnly);

     Gles->Set(String::NewSymbol("LINEAR"), Uint32::New(GL_LINEAR), ReadOnly);

     Gles->Set(String::NewSymbol("NEAREST_MIPMAP_NEAREST"), Uint32::New(GL_NEAREST_MIPMAP_NEAREST), ReadOnly);

     Gles->Set(String::NewSymbol("LINEAR_MIPMAP_NEAREST"), Uint32::New(GL_LINEAR_MIPMAP_NEAREST), ReadOnly);

     Gles->Set(String::NewSymbol("NEAREST_MIPMAP_LINEAR"), Uint32::New(GL_NEAREST_MIPMAP_LINEAR), ReadOnly);

     Gles->Set(String::NewSymbol("LINEAR_MIPMAP_LINEAR"), Uint32::New(GL_LINEAR_MIPMAP_LINEAR), ReadOnly);

     Gles->Set(String::NewSymbol("TEXTURE_MAG_FILTER"), Uint32::New(GL_TEXTURE_MAG_FILTER), ReadOnly);

     Gles->Set(String::NewSymbol("TEXTURE_MIN_FILTER"), Uint32::New(GL_TEXTURE_MIN_FILTER), ReadOnly);

     Gles->Set(String::NewSymbol("TEXTURE_WRAP_S"), Uint32::New(GL_TEXTURE_WRAP_S), ReadOnly);

     Gles->Set(String::NewSymbol("TEXTURE_WRAP_T"), Uint32::New(GL_TEXTURE_WRAP_T), ReadOnly);

     Gles->Set(String::NewSymbol("TEXTURE"), Uint32::New(GL_TEXTURE), ReadOnly);

     Gles->Set(String::NewSymbol("TEXTURE_CUBE_MAP"), Uint32::New(GL_TEXTURE_CUBE_MAP), ReadOnly);

     Gles->Set(String::NewSymbol("TEXTURE_BINDING_CUBE_MAP"), Uint32::New(GL_TEXTURE_BINDING_CUBE_MAP), ReadOnly);

     Gles->Set(String::NewSymbol("TEXTURE_CUBE_MAP_POSITIVE_X"), Uint32::New(GL_TEXTURE_CUBE_MAP_POSITIVE_X), ReadOnly);

     Gles->Set(String::NewSymbol("TEXTURE_CUBE_MAP_NEGATIVE_X"), Uint32::New(GL_TEXTURE_CUBE_MAP_NEGATIVE_X), ReadOnly);

     Gles->Set(String::NewSymbol("TEXTURE_CUBE_MAP_POSITIVE_Y"), Uint32::New(GL_TEXTURE_CUBE_MAP_POSITIVE_Y), ReadOnly);

     Gles->Set(String::NewSymbol("TEXTURE_CUBE_MAP_NEGATIVE_Y"), Uint32::New(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y), ReadOnly);

     Gles->Set(String::NewSymbol("TEXTURE_CUBE_MAP_POSITIVE_Z"), Uint32::New(GL_TEXTURE_CUBE_MAP_POSITIVE_Z), ReadOnly);

     Gles->Set(String::NewSymbol("TEXTURE_CUBE_MAP_NEGATIVE_Z"), Uint32::New(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z), ReadOnly);

     Gles->Set(String::NewSymbol("MAX_CUBE_MAP_TEXTURE_SIZE"), Uint32::New(GL_MAX_CUBE_MAP_TEXTURE_SIZE), ReadOnly);

     Gles->Set(String::NewSymbol("TEXTURE0"), Uint32::New(GL_TEXTURE0), ReadOnly);

     Gles->Set(String::NewSymbol("TEXTURE1"), Uint32::New(GL_TEXTURE1), ReadOnly);

     Gles->Set(String::NewSymbol("TEXTURE2"), Uint32::New(GL_TEXTURE2), ReadOnly);

     Gles->Set(String::NewSymbol("TEXTURE3"), Uint32::New(GL_TEXTURE3), ReadOnly);

     Gles->Set(String::NewSymbol("TEXTURE4"), Uint32::New(GL_TEXTURE4), ReadOnly);

     Gles->Set(String::NewSymbol("TEXTURE5"), Uint32::New(GL_TEXTURE5), ReadOnly);

     Gles->Set(String::NewSymbol("TEXTURE6"), Uint32::New(GL_TEXTURE6), ReadOnly);

     Gles->Set(String::NewSymbol("TEXTURE7"), Uint32::New(GL_TEXTURE7), ReadOnly);

     Gles->Set(String::NewSymbol("TEXTURE8"), Uint32::New(GL_TEXTURE8), ReadOnly);

     Gles->Set(String::NewSymbol("TEXTURE9"), Uint32::New(GL_TEXTURE9), ReadOnly);

     Gles->Set(String::NewSymbol("TEXTURE10"), Uint32::New(GL_TEXTURE10), ReadOnly);

     Gles->Set(String::NewSymbol("TEXTURE11"), Uint32::New(GL_TEXTURE11), ReadOnly);

     Gles->Set(String::NewSymbol("TEXTURE12"), Uint32::New(GL_TEXTURE12), ReadOnly);

     Gles->Set(String::NewSymbol("TEXTURE13"), Uint32::New(GL_TEXTURE13), ReadOnly);

     Gles->Set(String::NewSymbol("TEXTURE14"), Uint32::New(GL_TEXTURE14), ReadOnly);

     Gles->Set(String::NewSymbol("TEXTURE15"), Uint32::New(GL_TEXTURE15), ReadOnly);

     Gles->Set(String::NewSymbol("TEXTURE16"), Uint32::New(GL_TEXTURE16), ReadOnly);

     Gles->Set(String::NewSymbol("TEXTURE17"), Uint32::New(GL_TEXTURE17), ReadOnly);

     Gles->Set(String::NewSymbol("TEXTURE18"), Uint32::New(GL_TEXTURE18), ReadOnly);

     Gles->Set(String::NewSymbol("TEXTURE19"), Uint32::New(GL_TEXTURE19), ReadOnly);

     Gles->Set(String::NewSymbol("TEXTURE20"), Uint32::New(GL_TEXTURE20), ReadOnly);

     Gles->Set(String::NewSymbol("TEXTURE21"), Uint32::New(GL_TEXTURE21), ReadOnly);

     Gles->Set(String::NewSymbol("TEXTURE22"), Uint32::New(GL_TEXTURE22), ReadOnly);

     Gles->Set(String::NewSymbol("TEXTURE23"), Uint32::New(GL_TEXTURE23), ReadOnly);

     Gles->Set(String::NewSymbol("TEXTURE24"), Uint32::New(GL_TEXTURE24), ReadOnly);

     Gles->Set(String::NewSymbol("TEXTURE25"), Uint32::New(GL_TEXTURE25), ReadOnly);

     Gles->Set(String::NewSymbol("TEXTURE26"), Uint32::New(GL_TEXTURE26), ReadOnly);

     Gles->Set(String::NewSymbol("TEXTURE27"), Uint32::New(GL_TEXTURE27), ReadOnly);

     Gles->Set(String::NewSymbol("TEXTURE28"), Uint32::New(GL_TEXTURE28), ReadOnly);

     Gles->Set(String::NewSymbol("TEXTURE29"), Uint32::New(GL_TEXTURE29), ReadOnly);

     Gles->Set(String::NewSymbol("TEXTURE30"), Uint32::New(GL_TEXTURE30), ReadOnly);

     Gles->Set(String::NewSymbol("TEXTURE31"), Uint32::New(GL_TEXTURE31), ReadOnly);

     Gles->Set(String::NewSymbol("ACTIVE_TEXTURE"), Uint32::New(GL_ACTIVE_TEXTURE), ReadOnly);

     Gles->Set(String::NewSymbol("REPEAT"), Uint32::New(GL_REPEAT), ReadOnly);

     Gles->Set(String::NewSymbol("CLAMP_TO_EDGE"), Uint32::New(GL_CLAMP_TO_EDGE), ReadOnly);

     Gles->Set(String::NewSymbol("MIRRORED_REPEAT"), Uint32::New(GL_MIRRORED_REPEAT), ReadOnly);

     Gles->Set(String::NewSymbol("FLOAT_VEC2"), Uint32::New(GL_FLOAT_VEC2), ReadOnly);

     Gles->Set(String::NewSymbol("FLOAT_VEC3"), Uint32::New(GL_FLOAT_VEC3), ReadOnly);

     Gles->Set(String::NewSymbol("FLOAT_VEC4"), Uint32::New(GL_FLOAT_VEC4), ReadOnly);

     Gles->Set(String::NewSymbol("INT_VEC2"), Uint32::New(GL_INT_VEC2), ReadOnly);

     Gles->Set(String::NewSymbol("INT_VEC3"), Uint32::New(GL_INT_VEC3), ReadOnly);

     Gles->Set(String::NewSymbol("INT_VEC4"), Uint32::New(GL_INT_VEC4), ReadOnly);

     Gles->Set(String::NewSymbol("BOOL"), Uint32::New(GL_BOOL), ReadOnly);

     Gles->Set(String::NewSymbol("BOOL_VEC2"), Uint32::New(GL_BOOL_VEC2), ReadOnly);

     Gles->Set(String::NewSymbol("BOOL_VEC3"), Uint32::New(GL_BOOL_VEC3), ReadOnly);

     Gles->Set(String::NewSymbol("BOOL_VEC4"), Uint32::New(GL_BOOL_VEC4), ReadOnly);

     Gles->Set(String::NewSymbol("FLOAT_MAT2"), Uint32::New(GL_FLOAT_MAT2), ReadOnly);

     Gles->Set(String::NewSymbol("FLOAT_MAT3"), Uint32::New(GL_FLOAT_MAT3), ReadOnly);

     Gles->Set(String::NewSymbol("FLOAT_MAT4"), Uint32::New(GL_FLOAT_MAT4), ReadOnly);

     Gles->Set(String::NewSymbol("SAMPLER_2D"), Uint32::New(GL_SAMPLER_2D), ReadOnly);

     Gles->Set(String::NewSymbol("SAMPLER_CUBE"), Uint32::New(GL_SAMPLER_CUBE), ReadOnly);

     Gles->Set(String::NewSymbol("VERTEX_ATTRIB_ARRAY_ENABLED"), Uint32::New(GL_VERTEX_ATTRIB_ARRAY_ENABLED), ReadOnly);

     Gles->Set(String::NewSymbol("VERTEX_ATTRIB_ARRAY_SIZE"), Uint32::New(GL_VERTEX_ATTRIB_ARRAY_SIZE), ReadOnly);

     Gles->Set(String::NewSymbol("VERTEX_ATTRIB_ARRAY_STRIDE"), Uint32::New(GL_VERTEX_ATTRIB_ARRAY_STRIDE), ReadOnly);

     Gles->Set(String::NewSymbol("VERTEX_ATTRIB_ARRAY_TYPE"), Uint32::New(GL_VERTEX_ATTRIB_ARRAY_TYPE), ReadOnly);

     Gles->Set(String::NewSymbol("VERTEX_ATTRIB_ARRAY_NORMALIZED"), Uint32::New(GL_VERTEX_ATTRIB_ARRAY_NORMALIZED), ReadOnly);

     Gles->Set(String::NewSymbol("VERTEX_ATTRIB_ARRAY_POINTER"), Uint32::New(GL_VERTEX_ATTRIB_ARRAY_POINTER), ReadOnly);

     Gles->Set(String::NewSymbol("VERTEX_ATTRIB_ARRAY_BUFFER_BINDING"), Uint32::New(GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING), ReadOnly);

     Gles->Set(String::NewSymbol("COMPILE_STATUS"), Uint32::New(GL_COMPILE_STATUS), ReadOnly);

     Gles->Set(String::NewSymbol("INFO_LOG_LENGTH"), Uint32::New(GL_INFO_LOG_LENGTH), ReadOnly);

     Gles->Set(String::NewSymbol("SHADER_SOURCE_LENGTH"), Uint32::New(GL_SHADER_SOURCE_LENGTH), ReadOnly);

     Gles->Set(String::NewSymbol("SHADER_COMPILER"), Uint32::New(GL_SHADER_COMPILER), ReadOnly);

     Gles->Set(String::NewSymbol("SHADER_BINARY_FORMATS"), Uint32::New(GL_SHADER_BINARY_FORMATS), ReadOnly);

     Gles->Set(String::NewSymbol("NUM_SHADER_BINARY_FORMATS"), Uint32::New(GL_NUM_SHADER_BINARY_FORMATS), ReadOnly);

     Gles->Set(String::NewSymbol("LOW_FLOAT"), Uint32::New(GL_LOW_FLOAT), ReadOnly);

     Gles->Set(String::NewSymbol("MEDIUM_FLOAT"), Uint32::New(GL_MEDIUM_FLOAT), ReadOnly);

     Gles->Set(String::NewSymbol("HIGH_FLOAT"), Uint32::New(GL_HIGH_FLOAT), ReadOnly);

     Gles->Set(String::NewSymbol("LOW_INT"), Uint32::New(GL_LOW_INT), ReadOnly);

     Gles->Set(String::NewSymbol("MEDIUM_INT"), Uint32::New(GL_MEDIUM_INT), ReadOnly);

     Gles->Set(String::NewSymbol("HIGH_INT"), Uint32::New(GL_HIGH_INT), ReadOnly);

     Gles->Set(String::NewSymbol("FRAMEBUFFER"), Uint32::New(GL_FRAMEBUFFER), ReadOnly);

     Gles->Set(String::NewSymbol("RENDERBUFFER"), Uint32::New(GL_RENDERBUFFER), ReadOnly);

     Gles->Set(String::NewSymbol("RGBA4"), Uint32::New(GL_RGBA4), ReadOnly);

     Gles->Set(String::NewSymbol("RGB5_A1"), Uint32::New(GL_RGB5_A1), ReadOnly);

     Gles->Set(String::NewSymbol("RGB565"), Uint32::New(GL_RGB565), ReadOnly);

     Gles->Set(String::NewSymbol("DEPTH_COMPONENT16"), Uint32::New(GL_DEPTH_COMPONENT16), ReadOnly);

     Gles->Set(String::NewSymbol("STENCIL_INDEX"), Uint32::New(GL_STENCIL_INDEX), ReadOnly);

     Gles->Set(String::NewSymbol("STENCIL_INDEX8"), Uint32::New(GL_STENCIL_INDEX8), ReadOnly);

     Gles->Set(String::NewSymbol("RENDERBUFFER_WIDTH"), Uint32::New(GL_RENDERBUFFER_WIDTH), ReadOnly);

     Gles->Set(String::NewSymbol("RENDERBUFFER_HEIGHT"), Uint32::New(GL_RENDERBUFFER_HEIGHT), ReadOnly);

     Gles->Set(String::NewSymbol("RENDERBUFFER_INTERNAL_FORMAT"), Uint32::New(GL_RENDERBUFFER_INTERNAL_FORMAT), ReadOnly);

     Gles->Set(String::NewSymbol("RENDERBUFFER_RED_SIZE"), Uint32::New(GL_RENDERBUFFER_RED_SIZE), ReadOnly);

     Gles->Set(String::NewSymbol("RENDERBUFFER_GREEN_SIZE"), Uint32::New(GL_RENDERBUFFER_GREEN_SIZE), ReadOnly);

     Gles->Set(String::NewSymbol("RENDERBUFFER_BLUE_SIZE"), Uint32::New(GL_RENDERBUFFER_BLUE_SIZE), ReadOnly);

     Gles->Set(String::NewSymbol("RENDERBUFFER_ALPHA_SIZE"), Uint32::New(GL_RENDERBUFFER_ALPHA_SIZE), ReadOnly);

     Gles->Set(String::NewSymbol("RENDERBUFFER_DEPTH_SIZE"), Uint32::New(GL_RENDERBUFFER_DEPTH_SIZE), ReadOnly);

     Gles->Set(String::NewSymbol("RENDERBUFFER_STENCIL_SIZE"), Uint32::New(GL_RENDERBUFFER_STENCIL_SIZE), ReadOnly);

     Gles->Set(String::NewSymbol("FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE"), Uint32::New(GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE), ReadOnly);

     Gles->Set(String::NewSymbol("FRAMEBUFFER_ATTACHMENT_OBJECT_NAME"), Uint32::New(GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME), ReadOnly);

     Gles->Set(String::NewSymbol("FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL"), Uint32::New(GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL), ReadOnly);

     Gles->Set(String::NewSymbol("FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE"), Uint32::New(GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE), ReadOnly);

     Gles->Set(String::NewSymbol("COLOR_ATTACHMENT0"), Uint32::New(GL_COLOR_ATTACHMENT0), ReadOnly);

     Gles->Set(String::NewSymbol("DEPTH_ATTACHMENT"), Uint32::New(GL_DEPTH_ATTACHMENT), ReadOnly);

     Gles->Set(String::NewSymbol("STENCIL_ATTACHMENT"), Uint32::New(GL_STENCIL_ATTACHMENT), ReadOnly);

     Gles->Set(String::NewSymbol("NONE"), Uint32::New(GL_NONE), ReadOnly);

     Gles->Set(String::NewSymbol("FRAMEBUFFER_COMPLETE"), Uint32::New(GL_FRAMEBUFFER_COMPLETE), ReadOnly);

     Gles->Set(String::NewSymbol("FRAMEBUFFER_INCOMPLETE_ATTACHMENT"), Uint32::New(GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT), ReadOnly);

     Gles->Set(String::NewSymbol("FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT"), Uint32::New(GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT), ReadOnly);

     Gles->Set(String::NewSymbol("FRAMEBUFFER_INCOMPLETE_DIMENSIONS"), Uint32::New(GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS), ReadOnly);

     Gles->Set(String::NewSymbol("FRAMEBUFFER_UNSUPPORTED"), Uint32::New(GL_FRAMEBUFFER_UNSUPPORTED), ReadOnly);

     Gles->Set(String::NewSymbol("FRAMEBUFFER_BINDING"), Uint32::New(GL_FRAMEBUFFER_BINDING), ReadOnly);

     Gles->Set(String::NewSymbol("RENDERBUFFER_BINDING"), Uint32::New(GL_RENDERBUFFER_BINDING), ReadOnly);

     Gles->Set(String::NewSymbol("MAX_RENDERBUFFER_SIZE"), Uint32::New(GL_MAX_RENDERBUFFER_SIZE), ReadOnly);

     Gles->Set(String::NewSymbol("ActiveTexture"), FunctionTemplate::New(GLESglActiveTextureCallback));

     Gles->Set(String::NewSymbol("AttachShader"), FunctionTemplate::New(GLESglAttachShaderCallback));

     Gles->Set(String::NewSymbol("BindAttribLocation"), FunctionTemplate::New(GLESglBindAttribLocationCallback));

     Gles->Set(String::NewSymbol("BindBuffer"), FunctionTemplate::New(GLESglBindBufferCallback));

     Gles->Set(String::NewSymbol("BindFramebuffer"), FunctionTemplate::New(GLESglBindFramebufferCallback));

     Gles->Set(String::NewSymbol("BindRenderbuffer"), FunctionTemplate::New(GLESglBindRenderbufferCallback));

     Gles->Set(String::NewSymbol("BindTexture"), FunctionTemplate::New(GLESglBindTextureCallback));

     Gles->Set(String::NewSymbol("BlendColor"), FunctionTemplate::New(GLESglBlendColorCallback));

     Gles->Set(String::NewSymbol("BlendEquation"), FunctionTemplate::New(GLESglBlendEquationCallback));

     Gles->Set(String::NewSymbol("BlendEquationSeparate"), FunctionTemplate::New(GLESglBlendEquationSeparateCallback));

     Gles->Set(String::NewSymbol("BlendFunc"), FunctionTemplate::New(GLESglBlendFuncCallback));

     Gles->Set(String::NewSymbol("BlendFuncSeparate"), FunctionTemplate::New(GLESglBlendFuncSeparateCallback));

     Gles->Set(String::NewSymbol("BufferData"), FunctionTemplate::New(GLESglBufferDataCallback));

     Gles->Set(String::NewSymbol("BufferSubData"), FunctionTemplate::New(GLESglBufferSubDataCallback));

     Gles->Set(String::NewSymbol("CheckFramebufferStatus"), FunctionTemplate::New(GLESglCheckFramebufferStatusCallback));

     Gles->Set(String::NewSymbol("Clear"), FunctionTemplate::New(GLESglClearCallback));

     Gles->Set(String::NewSymbol("ClearColor"), FunctionTemplate::New(GLESglClearColorCallback));

     Gles->Set(String::NewSymbol("ClearDepthf"), FunctionTemplate::New(GLESglClearDepthfCallback));

     Gles->Set(String::NewSymbol("ClearStencil"), FunctionTemplate::New(GLESglClearStencilCallback));

     Gles->Set(String::NewSymbol("ColorMask"), FunctionTemplate::New(GLESglColorMaskCallback));

     Gles->Set(String::NewSymbol("CompileShader"), FunctionTemplate::New(GLESglCompileShaderCallback));

     Gles->Set(String::NewSymbol("CopyTexImage2D"), FunctionTemplate::New(GLESglCopyTexImage2DCallback));

     Gles->Set(String::NewSymbol("CopyTexSubImage2D"), FunctionTemplate::New(GLESglCopyTexSubImage2DCallback));

     Gles->Set(String::NewSymbol("CreateProgram"), FunctionTemplate::New(GLESglCreateProgramCallback));

     Gles->Set(String::NewSymbol("CreateShader"), FunctionTemplate::New(GLESglCreateShaderCallback));

     Gles->Set(String::NewSymbol("CullFace"), FunctionTemplate::New(GLESglCullFaceCallback));

     Gles->Set(String::NewSymbol("DeleteBuffers"), FunctionTemplate::New(GLESglDeleteBuffersCallback));

     Gles->Set(String::NewSymbol("DeleteFramebuffers"), FunctionTemplate::New(GLESglDeleteFramebuffersCallback));

     Gles->Set(String::NewSymbol("DeleteProgram"), FunctionTemplate::New(GLESglDeleteProgramCallback));

     Gles->Set(String::NewSymbol("DeleteRenderbuffers"), FunctionTemplate::New(GLESglDeleteRenderbuffersCallback));

     Gles->Set(String::NewSymbol("DeleteShader"), FunctionTemplate::New(GLESglDeleteShaderCallback));

     Gles->Set(String::NewSymbol("DeleteTextures"), FunctionTemplate::New(GLESglDeleteTexturesCallback));

     Gles->Set(String::NewSymbol("DepthFunc"), FunctionTemplate::New(GLESglDepthFuncCallback));

     Gles->Set(String::NewSymbol("DepthMask"), FunctionTemplate::New(GLESglDepthMaskCallback));

     Gles->Set(String::NewSymbol("DepthRangef"), FunctionTemplate::New(GLESglDepthRangefCallback));

     Gles->Set(String::NewSymbol("DetachShader"), FunctionTemplate::New(GLESglDetachShaderCallback));

     Gles->Set(String::NewSymbol("Disable"), FunctionTemplate::New(GLESglDisableCallback));

     Gles->Set(String::NewSymbol("DisableVertexAttribArray"), FunctionTemplate::New(GLESglDisableVertexAttribArrayCallback));

     Gles->Set(String::NewSymbol("DrawArrays"), FunctionTemplate::New(GLESglDrawArraysCallback));

     Gles->Set(String::NewSymbol("DrawElements"), FunctionTemplate::New(GLESglDrawElementsCallback));

     Gles->Set(String::NewSymbol("Enable"), FunctionTemplate::New(GLESglEnableCallback));

     Gles->Set(String::NewSymbol("EnableVertexAttribArray"), FunctionTemplate::New(GLESglEnableVertexAttribArrayCallback));

     Gles->Set(String::NewSymbol("Finish"), FunctionTemplate::New(GLESglFinishCallback));

     Gles->Set(String::NewSymbol("Flush"), FunctionTemplate::New(GLESglFlushCallback));

     Gles->Set(String::NewSymbol("FramebufferRenderbuffer"), FunctionTemplate::New(GLESglFramebufferRenderbufferCallback));

     Gles->Set(String::NewSymbol("FramebufferTexture2D"), FunctionTemplate::New(GLESglFramebufferTexture2DCallback));

     Gles->Set(String::NewSymbol("FrontFace"), FunctionTemplate::New(GLESglFrontFaceCallback));

     Gles->Set(String::NewSymbol("GenBuffers"), FunctionTemplate::New(GLESglGenBuffersCallback));

     Gles->Set(String::NewSymbol("GenerateMipmap"), FunctionTemplate::New(GLESglGenerateMipmapCallback));

     Gles->Set(String::NewSymbol("GenFramebuffers"), FunctionTemplate::New(GLESglGenFramebuffersCallback));

     Gles->Set(String::NewSymbol("GenRenderbuffers"), FunctionTemplate::New(GLESglGenRenderbuffersCallback));

     Gles->Set(String::NewSymbol("GenTextures"), FunctionTemplate::New(GLESglGenTexturesCallback));

     Gles->Set(String::NewSymbol("GetActiveAttrib"), FunctionTemplate::New(GLESglGetActiveAttribCallback));

     Gles->Set(String::NewSymbol("GetActiveUniform"), FunctionTemplate::New(GLESglGetActiveUniformCallback));

     Gles->Set(String::NewSymbol("GetAttachedShaders"), FunctionTemplate::New(GLESglGetAttachedShadersCallback));

     Gles->Set(String::NewSymbol("GetAttribLocation"), FunctionTemplate::New(GLESglGetAttribLocationCallback));

     Gles->Set(String::NewSymbol("GetBooleanv"), FunctionTemplate::New(GLESglGetBooleanvCallback));

     Gles->Set(String::NewSymbol("GetBufferParameteriv"), FunctionTemplate::New(GLESglGetBufferParameterivCallback));

     Gles->Set(String::NewSymbol("GetError"), FunctionTemplate::New(GLESglGetErrorCallback));

     Gles->Set(String::NewSymbol("GetFloatv"), FunctionTemplate::New(GLESglGetFloatvCallback));

     Gles->Set(String::NewSymbol("GetFramebufferAttachmentParameteriv"), FunctionTemplate::New(GLESglGetFramebufferAttachmentParameterivCallback));

     Gles->Set(String::NewSymbol("GetIntegerv"), FunctionTemplate::New(GLESglGetIntegervCallback));

     Gles->Set(String::NewSymbol("GetProgramiv"), FunctionTemplate::New(GLESglGetProgramivCallback));

     Gles->Set(String::NewSymbol("GetProgramInfoLog"), FunctionTemplate::New(GLESglGetProgramInfoLogCallback));

     Gles->Set(String::NewSymbol("GetShaderiv"), FunctionTemplate::New(GLESglGetShaderivCallback));

     Gles->Set(String::NewSymbol("GetShaderInfoLog"), FunctionTemplate::New(GLESglGetShaderInfoLogCallback));

     Gles->Set(String::NewSymbol("GetShaderSource"), FunctionTemplate::New(GLESglGetShaderSourceCallback));

     Gles->Set(String::NewSymbol("GetUniformiv"), FunctionTemplate::New(GLESglGetUniformivCallback));

     Gles->Set(String::NewSymbol("GetUniformLocation"), FunctionTemplate::New(GLESglGetUniformLocationCallback));

     Gles->Set(String::NewSymbol("Hint"), FunctionTemplate::New(GLESglHintCallback));

     Gles->Set(String::NewSymbol("IsBuffer"), FunctionTemplate::New(GLESglIsBufferCallback));

     Gles->Set(String::NewSymbol("IsEnabled"), FunctionTemplate::New(GLESglIsEnabledCallback));

     Gles->Set(String::NewSymbol("IsFramebuffer"), FunctionTemplate::New(GLESglIsFramebufferCallback));

     Gles->Set(String::NewSymbol("IsProgram"), FunctionTemplate::New(GLESglIsProgramCallback));

     Gles->Set(String::NewSymbol("IsRenderbuffer"), FunctionTemplate::New(GLESglIsRenderbufferCallback));

     Gles->Set(String::NewSymbol("IsShader"), FunctionTemplate::New(GLESglIsShaderCallback));

     Gles->Set(String::NewSymbol("IsTexture"), FunctionTemplate::New(GLESglIsTextureCallback));

     Gles->Set(String::NewSymbol("LineWidth"), FunctionTemplate::New(GLESglLineWidthCallback));

     Gles->Set(String::NewSymbol("LinkProgram"), FunctionTemplate::New(GLESglLinkProgramCallback));

     Gles->Set(String::NewSymbol("PixelStorei"), FunctionTemplate::New(GLESglPixelStoreiCallback));

     Gles->Set(String::NewSymbol("PolygonOffset"), FunctionTemplate::New(GLESglPolygonOffsetCallback));

     Gles->Set(String::NewSymbol("ReadPixels"), FunctionTemplate::New(GLESglReadPixelsCallback));

     Gles->Set(String::NewSymbol("RenderbufferStorage"), FunctionTemplate::New(GLESglRenderbufferStorageCallback));

     Gles->Set(String::NewSymbol("SampleCoverage"), FunctionTemplate::New(GLESglSampleCoverageCallback));

     Gles->Set(String::NewSymbol("Scissor"), FunctionTemplate::New(GLESglScissorCallback));

     Gles->Set(String::NewSymbol("ShaderSource"), FunctionTemplate::New(GLESglShaderSourceCallback));

     Gles->Set(String::NewSymbol("StencilFunc"), FunctionTemplate::New(GLESglStencilFuncCallback));

     Gles->Set(String::NewSymbol("StencilFuncSeparate"), FunctionTemplate::New(GLESglStencilFuncSeparateCallback));

     Gles->Set(String::NewSymbol("StencilMask"), FunctionTemplate::New(GLESglStencilMaskCallback));

     Gles->Set(String::NewSymbol("StencilMaskSeparate"), FunctionTemplate::New(GLESglStencilMaskSeparateCallback));

     Gles->Set(String::NewSymbol("StencilOp"), FunctionTemplate::New(GLESglStencilOpCallback));

     Gles->Set(String::NewSymbol("StencilOpSeparate"), FunctionTemplate::New(GLESglStencilOpSeparateCallback));

     Gles->Set(String::NewSymbol("TexImage2D"), FunctionTemplate::New(GLESglTexImage2DCallback));

     Gles->Set(String::NewSymbol("TexParameterf"), FunctionTemplate::New(GLESglTexParameterfCallback));

     Gles->Set(String::NewSymbol("TexParameterfv"), FunctionTemplate::New(GLESglTexParameterfvCallback));

     Gles->Set(String::NewSymbol("TexParameteri"), FunctionTemplate::New(GLESglTexParameteriCallback));

     Gles->Set(String::NewSymbol("TexParameteriv"), FunctionTemplate::New(GLESglTexParameterivCallback));

     Gles->Set(String::NewSymbol("TexSubImage2D"), FunctionTemplate::New(GLESglTexSubImage2DCallback));

     Gles->Set(String::NewSymbol("Uniform1f"), FunctionTemplate::New(GLESglUniform1fCallback));

     Gles->Set(String::NewSymbol("Uniform1fv"), FunctionTemplate::New(GLESglUniform1fvCallback));

     Gles->Set(String::NewSymbol("Uniform1i"), FunctionTemplate::New(GLESglUniform1iCallback));

     Gles->Set(String::NewSymbol("Uniform1iv"), FunctionTemplate::New(GLESglUniform1ivCallback));

     Gles->Set(String::NewSymbol("Uniform2f"), FunctionTemplate::New(GLESglUniform2fCallback));

     Gles->Set(String::NewSymbol("Uniform2fv"), FunctionTemplate::New(GLESglUniform2fvCallback));

     Gles->Set(String::NewSymbol("Uniform2i"), FunctionTemplate::New(GLESglUniform2iCallback));

     Gles->Set(String::NewSymbol("Uniform2iv"), FunctionTemplate::New(GLESglUniform2ivCallback));

     Gles->Set(String::NewSymbol("Uniform3f"), FunctionTemplate::New(GLESglUniform3fCallback));

     Gles->Set(String::NewSymbol("Uniform3fv"), FunctionTemplate::New(GLESglUniform3fvCallback));

     Gles->Set(String::NewSymbol("Uniform3i"), FunctionTemplate::New(GLESglUniform3iCallback));

     Gles->Set(String::NewSymbol("Uniform3iv"), FunctionTemplate::New(GLESglUniform3ivCallback));

     Gles->Set(String::NewSymbol("Uniform4f"), FunctionTemplate::New(GLESglUniform4fCallback));

     Gles->Set(String::NewSymbol("Uniform4fv"), FunctionTemplate::New(GLESglUniform4fvCallback));

     Gles->Set(String::NewSymbol("Uniform4i"), FunctionTemplate::New(GLESglUniform4iCallback));

     Gles->Set(String::NewSymbol("Uniform4iv"), FunctionTemplate::New(GLESglUniform4ivCallback));

     Gles->Set(String::NewSymbol("UniformMatrix2fv"), FunctionTemplate::New(GLESglUniformMatrix2fvCallback));

     Gles->Set(String::NewSymbol("UniformMatrix3fv"), FunctionTemplate::New(GLESglUniformMatrix3fvCallback));

     Gles->Set(String::NewSymbol("UniformMatrix4fv"), FunctionTemplate::New(GLESglUniformMatrix4fvCallback));

     Gles->Set(String::NewSymbol("UseProgram"), FunctionTemplate::New(GLESglUseProgramCallback));

     Gles->Set(String::NewSymbol("ValidateProgram"), FunctionTemplate::New(GLESglValidateProgramCallback));

     Gles->Set(String::NewSymbol("VertexAttrib1f"), FunctionTemplate::New(GLESglVertexAttrib1fCallback));

     Gles->Set(String::NewSymbol("VertexAttrib1fv"), FunctionTemplate::New(GLESglVertexAttrib1fvCallback));

     Gles->Set(String::NewSymbol("VertexAttrib2f"), FunctionTemplate::New(GLESglVertexAttrib2fCallback));

     Gles->Set(String::NewSymbol("VertexAttrib2fv"), FunctionTemplate::New(GLESglVertexAttrib2fvCallback));

     Gles->Set(String::NewSymbol("VertexAttrib3f"), FunctionTemplate::New(GLESglVertexAttrib3fCallback));

     Gles->Set(String::NewSymbol("VertexAttrib3fv"), FunctionTemplate::New(GLESglVertexAttrib3fvCallback));

     Gles->Set(String::NewSymbol("VertexAttrib4f"), FunctionTemplate::New(GLESglVertexAttrib4fCallback));

     Gles->Set(String::NewSymbol("VertexAttrib4fv"), FunctionTemplate::New(GLESglVertexAttrib4fvCallback));

     Gles->Set(String::NewSymbol("VertexAttribPointer"), FunctionTemplate::New(GLESglVertexAttribPointerCallback));

     Gles->Set(String::NewSymbol("Viewport"), FunctionTemplate::New(GLESglViewportCallback));

     Gles->Set(String::NewSymbol("GetParameter"), FunctionTemplate::New(GLESglGetParameterCallback));

     Gles->Set(String::NewSymbol("GetTexParameter"), FunctionTemplate::New(GLESglGetTexParameterCallback));

     Gles->Set(String::NewSymbol("GetVertexAttrib"), FunctionTemplate::New(GLESglGetVertexAttribCallback));

     Gles->Set(String::NewSymbol("GetRenderbufferParameter"), FunctionTemplate::New(GLESglGetRenderbufferParameterCallback));


      // Again, return the result through the current handle scope.
      return handle_scope.Close(Gles);
}    
