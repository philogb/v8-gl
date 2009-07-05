// glGenBuffers uses an output parameter to return an array of ints.
Handle<Value> GLESglGenBuffersCallback(const Arguments& args) {
  if (args.Length() != 1)
	return v8::Undefined();

  HandleScope handle_scope;
  GLsizei num_buffers = args[0]->Int32Value();

  GLuint* buffers = new GLuint[num_buffers];
  glGenBuffers(num_buffers, buffers);

  // TODO(deanm): There should be a way to initialize the array faster.
  v8::Local<v8::Array> res = v8::Array::New(num_buffers);
  for (int i = 0; i < num_buffers; ++i) {
    res->Set(v8::Integer::New(i), v8::Integer::New(buffers[i]));
  }

  delete[] buffers;

  return handle_scope.Close(res);
}


// glGetProgramiv uses an output parameter to return an int.
Handle<Value> GLESglGetProgramivCallback(const Arguments& args) {
  if (args.Length() < 2)
    return v8::Undefined();
  HandleScope handle_scope;
  unsigned int arg0 = args[0]->Uint32Value();
  int arg1 = args[1]->IntegerValue();

  int out;
  glGetProgramiv((GLuint) arg0, (GLenum) arg1, (GLint*)&out);
  v8::Local<v8::Value> val = v8::Integer::New(out);
  return handle_scope.Close(val);
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
			  GLshort* arg1 = new  GLshort[data->Length()];
			  for (unsigned j = 0; j < data->Length(); j++) {
			      Handle<Value> arg(data->Get(Integer::New(j)));
			      arg1[j] = (GLshort)arg->IntegerValue();
			  }
			  ans = (void *)arg1;
			  break;

		  case GL_UNSIGNED_SHORT:
			  GLushort* arg1 = new  GLushort[data->Length()];
			  for (unsigned j = 0; j < data->Length(); j++) {
			      Handle<Value> arg(data->Get(Integer::New(j)));
			      arg1[j] = (GLushort)arg->Uint32Value();
			  }
			  ans = (void *)arg1;
			  break;

		  case GL_FLOAT:
			  GLfloat* arg1 = new  GLfloat[data->Length()];
			  for (unsigned j = 0; j < data->Length(); j++) {
			      Handle<Value> arg(data->Get(Integer::New(j)));
			      arg1[j] = (GLfloat)arg->NumberValue();
			  }
			  ans = (void *)arg1;
			  break;

		  case GL_FIXED:
			  GLfixed* arg1 = new  GLfixed[data->Length()];
			  for (unsigned j = 0; j < data->Length(); j++) {
			      Handle<Value> arg(data->Get(Integer::New(j)));
			      arg1[j] = (GLfixed)arg->IntegerValue();
			  }
			  ans = (void *)arg1;
			  break;

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
			  GLushort* arg1 = new  GLushort[data->Length()];
			  for (unsigned j = 0; j < data->Length(); j++) {
			      Handle<Value> arg(data->Get(Integer::New(j)));
			      arg1[j] = (GLushort)arg->Uint32Value();
			  }
			  ans = (void *)arg1;
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
  if (args.Length() != 4)
    return v8::Undefined();

  HandleScope handle_scope;
  unsigned int target  = args[0]->Uint32Value();
  unsigned int type = args[2]->Uint32Value();
  unsigned int usage  = args[3]->Uint32Value();

  void* ans;
  if(args[1]->IsArray()) {
	  Handle<Array> data = Handle<Array>::Cast(args[1]);
	  unsigned int len = data->Length();

	  switch(type) {
		  case GL_FLOAT:
			  GLfloat* arg1 = new  GLfloat[len];
			  for (unsigned j = 0; j < len; j++) {
			      Handle<Value> arg(data->Get(Integer::New(j)));
			      arg1[j] = (GLfloat)arg->NumberValue();
			  }
			  ans = (void *)arg1;
			  break;

		  case GL_UNSIGNED_SHORT:
			  GLushort* arg1 = new  GLushort[len];
			  for (unsigned j = 0; j < len; j++) {
			      Handle<Value> arg(data->Get(Integer::New(j)));
			      arg1[j] = (GLushort)arg->Uint32Value();
			  }
			  ans = (void *)arg1;
			  break;

		  default: return v8::Undefined();
	  }

	  glBufferData((GLenum)target,
			  (GLsizeiptr)len,
			  (const void*) ans,
			  (GLenum)usage);

	  //should I delete[] ans?

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
			  GLfloat* arg1 = new  GLfloat[len];
			  for (unsigned j = 0; j < data->Length(); j++) {
			      Handle<Value> arg(data->Get(Integer::New(j)));
			      arg1[j] = (GLfloat)arg->NumberValue();
			  }
			  ans = (void *)arg1;
			  break;

		  case GL_UNSIGNED_SHORT:
			  GLushort* arg1 = new  GLushort[len];
			  for (unsigned j = 0; j < data->Length(); j++) {
			      Handle<Value> arg(data->Get(Integer::New(j)));
			      arg1[j] = (GLushort)arg->Uint32Value();
			  }
			  ans = (void *)arg1;
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

  //do I have to get into the active context here before I create an
  //instance of ans?
  //Context::Scope context_scope(context);
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
  //Context::Scope context_scope(context);
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
