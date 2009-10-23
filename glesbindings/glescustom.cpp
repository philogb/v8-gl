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

  char name[256];
  int length = 0;
  int size = 0;
  unsigned type = 0;

  glGetActiveAttrib((GLuint)program,
		  (GLuint)index,
		  (GLsizei)sizeof(name),
		  (GLsizei*)&length,
		  (GLint*)&size,
		  (GLenum*)&type,
		  (GLchar*)name);

  Handle<Object> ans = Object::New();
  ans->Set(String::New("type"), Uint32::New(type));
  ans->Set(String::New("size"), Integer::New(size));
  ans->Set(String::New("name"), String::New(name, length));
  return ans;
}

Handle<Value> GLESglGetActiveUniformCallback(const Arguments& args) {
  if (args.Length() != 2)
	return v8::Undefined();

  HandleScope handle_scope;

  unsigned program = args[0]->Uint32Value();
  unsigned index = args[1]->Uint32Value();

  char name[256];
  int length = 0;
  int size = 0;
  unsigned type = 0;

  glGetActiveUniform((GLuint)program,
		  (GLuint)index,
		  (GLsizei)sizeof(name),
		  (GLsizei*)&length,
		  (GLint*)&size,
		  (GLenum*)&type,
		  (GLchar*)name);

  // Create a template for the answer object that'll hold
  // type/size/name as properties
  Handle<Object> ans = Object::New();
  ans->Set(String::New("type"), Uint32::New(type));
  ans->Set(String::New("size"), Integer::New(size));
  ans->Set(String::New("name"), String::New(name));
  return ans;
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

	  if( type == GL_UNSIGNED_BYTE ) {
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
	  } else if( type == GL_BYTE ) {
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

	  } else if( type == GL_BITMAP ) {
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

	  } else if( type == GL_UNSIGNED_SHORT ) {
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

	  } else if( type == GL_SHORT ) {
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

	  } else if( type == GL_UNSIGNED_INT ) {
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

	  } else if( type == GL_INT ) {
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

	  } else if( type == GL_FLOAT ) {
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
  }

  return v8::Undefined();
}

Handle<Value> GLESglTexImage2DFileCallback(const Arguments& args) {

  if (args.Length() != 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  String::Utf8Value value(args[0]);
  char* filepath_str = *value;

  char* filename = V8GLUtils::getRealPath(filepath_str);

  //take care of relative/absolute paths.
  Image* img = loadPNG(filename);

  glTexImage2D(GL_TEXTURE_2D,  // target
		  0,		  // level
		  GL_RGB,	  // interal format
		  img->width, img->height, // width, height
		  0,		  // border
		  GL_RGB,	  // format
		  GL_UNSIGNED_BYTE, // type
		  (const void*)img->pixels);

  delete[] filename;

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

// We expect to be called with a shader id and a single string.
Handle<Value> GLESglShaderSourceFileCallback(const Arguments& args) {
  if (args.Length() != 2)
    return v8::Undefined();

  HandleScope handle_scope;
  GLuint shader_id = args[0]->Uint32Value();
  // GLSL source is defined as an ASCII subset.
  v8::String::AsciiValue filepath_ascii(args[1]);
  if (!*filepath_ascii)
    return v8::Undefined();

  char* filepath_str = *filepath_ascii;
  char* filename = V8GLUtils::getRealPath(filepath_str);

  std::ifstream in_file(filename);

  if(!in_file.is_open()) return v8::Undefined();

  std::string line, full_text = "";
  while (! in_file.eof() ) {
    std::getline (in_file, line);
    full_text += line + "\n";
  }

  char* ans = new char[full_text.length() +1];
  strcpy(ans, full_text.c_str());

  GLsizei code_len = full_text.length();
  glShaderSource(shader_id, 1, (const GLchar**) &ans, &code_len);

  delete[] ans;
  delete[] filename;

  Handle<Object> res(GlesFactory::self_);
  return res;
}

