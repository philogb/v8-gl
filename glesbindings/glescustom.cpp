// glGenBuffers uses an output parameter to return an array of ints.
Handle<Value> GLESglGenBuffersCallback(const Arguments& args) {
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
