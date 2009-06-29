#include "glesbind.h"

Persistent<Object> GlesFactory::self_;



Handle<Value> GLESglActiveTextureCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

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
  int arg0 = args[0]->IntegerValue();
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
  int arg0 = args[0]->IntegerValue();
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
  int arg0 = args[0]->IntegerValue();
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
  int arg0 = args[0]->IntegerValue();
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
  int arg0 = args[0]->IntegerValue();

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
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();

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
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();

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
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();
  int arg3 = args[3]->IntegerValue();

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
  int arg0 = args[0]->IntegerValue();

  //make call
  return Integer::New(glCheckFramebufferStatus((GLenum) arg0));
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
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();
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
  int arg0 = args[0]->IntegerValue();
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
  int arg0 = args[0]->IntegerValue();

  //make call
  return Uint32::New(glCreateShader((GLenum) arg0));
}




Handle<Value> GLESglCullFaceCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

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
  int arg0 = args[0]->IntegerValue();

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
  int arg0 = args[0]->IntegerValue();

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
  int arg0 = args[0]->IntegerValue();
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
  int arg0 = args[0]->IntegerValue();

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
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();
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
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();
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
  int arg0 = args[0]->IntegerValue();

  //make call
  glFrontFace((GLenum) arg0);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglGenBuffersCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();


  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
  GLuint* arg1 = new GLuint[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
      GLuint aux = (GLuint)arg->Uint32Value();
      arg1[j] = aux;
  }


  //make call
  glGenBuffers((GLsizei) arg0, (GLuint*) arg1);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglGenerateMipmapCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  glGenerateMipmap((GLenum) arg0);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglGenFramebuffersCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();


  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
  GLuint* arg1 = new GLuint[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
      GLuint aux = (GLuint)arg->Uint32Value();
      arg1[j] = aux;
  }


  //make call
  glGenFramebuffers((GLsizei) arg0, (GLuint*) arg1);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglGenRenderbuffersCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();


  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
  GLuint* arg1 = new GLuint[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
      GLuint aux = (GLuint)arg->Uint32Value();
      arg1[j] = aux;
  }


  //make call
  glGenRenderbuffers((GLsizei) arg0, (GLuint*) arg1);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglGenTexturesCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();


  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
  GLuint* arg1 = new GLuint[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
      GLuint aux = (GLuint)arg->Uint32Value();
      arg1[j] = aux;
  }


  //make call
  glGenTextures((GLsizei) arg0, (GLuint*) arg1);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglGetActiveAttribCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 7) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  unsigned int arg1 = args[1]->Uint32Value();
  int arg2 = args[2]->IntegerValue();


  Handle<Array> arrHandle3 = Handle<Array>::Cast(args[3]);
  GLsizei* arg3 = new GLsizei[arrHandle3->Length()];
  for (unsigned j = 0; j < arrHandle3->Length(); j++) {
      Handle<Value> arg(arrHandle3->Get(Integer::New(j)));
      GLsizei aux = (GLsizei)arg->IntegerValue();
      arg3[j] = aux;
  }



  Handle<Array> arrHandle4 = Handle<Array>::Cast(args[4]);
  GLint* arg4 = new GLint[arrHandle4->Length()];
  for (unsigned j = 0; j < arrHandle4->Length(); j++) {
      Handle<Value> arg(arrHandle4->Get(Integer::New(j)));
      GLint aux = (GLint)arg->IntegerValue();
      arg4[j] = aux;
  }



  Handle<Array> arrHandle5 = Handle<Array>::Cast(args[5]);
  GLenum* arg5 = new GLenum[arrHandle5->Length()];
  for (unsigned j = 0; j < arrHandle5->Length(); j++) {
      Handle<Value> arg(arrHandle5->Get(Integer::New(j)));
      GLenum aux = (GLenum)arg->IntegerValue();
      arg5[j] = aux;
  }

  String::Utf8Value value6(args[6]);
  char* arg6 = *value6;

  //make call
  glGetActiveAttrib((GLuint) arg0, (GLuint) arg1, (GLsizei) arg2, (GLsizei*) arg3, (GLint*) arg4, (GLenum*) arg5, (char*) arg6);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglGetActiveUniformCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 7) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  unsigned int arg1 = args[1]->Uint32Value();
  int arg2 = args[2]->IntegerValue();


  Handle<Array> arrHandle3 = Handle<Array>::Cast(args[3]);
  GLsizei* arg3 = new GLsizei[arrHandle3->Length()];
  for (unsigned j = 0; j < arrHandle3->Length(); j++) {
      Handle<Value> arg(arrHandle3->Get(Integer::New(j)));
      GLsizei aux = (GLsizei)arg->IntegerValue();
      arg3[j] = aux;
  }



  Handle<Array> arrHandle4 = Handle<Array>::Cast(args[4]);
  GLint* arg4 = new GLint[arrHandle4->Length()];
  for (unsigned j = 0; j < arrHandle4->Length(); j++) {
      Handle<Value> arg(arrHandle4->Get(Integer::New(j)));
      GLint aux = (GLint)arg->IntegerValue();
      arg4[j] = aux;
  }



  Handle<Array> arrHandle5 = Handle<Array>::Cast(args[5]);
  GLenum* arg5 = new GLenum[arrHandle5->Length()];
  for (unsigned j = 0; j < arrHandle5->Length(); j++) {
      Handle<Value> arg(arrHandle5->Get(Integer::New(j)));
      GLenum aux = (GLenum)arg->IntegerValue();
      arg5[j] = aux;
  }

  String::Utf8Value value6(args[6]);
  char* arg6 = *value6;

  //make call
  glGetActiveUniform((GLuint) arg0, (GLuint) arg1, (GLsizei) arg2, (GLsizei*) arg3, (GLint*) arg4, (GLenum*) arg5, (char*) arg6);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglGetAttachedShadersCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 4) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  int arg1 = args[1]->IntegerValue();


  Handle<Array> arrHandle2 = Handle<Array>::Cast(args[2]);
  GLsizei* arg2 = new GLsizei[arrHandle2->Length()];
  for (unsigned j = 0; j < arrHandle2->Length(); j++) {
      Handle<Value> arg(arrHandle2->Get(Integer::New(j)));
      GLsizei aux = (GLsizei)arg->IntegerValue();
      arg2[j] = aux;
  }



  Handle<Array> arrHandle3 = Handle<Array>::Cast(args[3]);
  GLuint* arg3 = new GLuint[arrHandle3->Length()];
  for (unsigned j = 0; j < arrHandle3->Length(); j++) {
      Handle<Value> arg(arrHandle3->Get(Integer::New(j)));
      GLuint aux = (GLuint)arg->Uint32Value();
      arg3[j] = aux;
  }


  //make call
  glGetAttachedShaders((GLuint) arg0, (GLsizei) arg1, (GLsizei*) arg2, (GLuint*) arg3);
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
  int arg0 = args[0]->IntegerValue();


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




Handle<Value> GLESglGetBufferParameterivCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();


  Handle<Array> arrHandle2 = Handle<Array>::Cast(args[2]);
  GLint* arg2 = new GLint[arrHandle2->Length()];
  for (unsigned j = 0; j < arrHandle2->Length(); j++) {
      Handle<Value> arg(arrHandle2->Get(Integer::New(j)));
      GLint aux = (GLint)arg->IntegerValue();
      arg2[j] = aux;
  }


  //make call
  glGetBufferParameteriv((GLenum) arg0, (GLenum) arg1, (GLint*) arg2);
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
  return Integer::New(glGetError());
}




Handle<Value> GLESglGetFloatvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();


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
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();


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
  int arg0 = args[0]->IntegerValue();


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




Handle<Value> GLESglGetProgramivCallback(const Arguments& args) {
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
  glGetProgramiv((GLuint) arg0, (GLenum) arg1, (GLint*) arg2);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglGetProgramInfoLogCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 4) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  int arg1 = args[1]->IntegerValue();


  Handle<Array> arrHandle2 = Handle<Array>::Cast(args[2]);
  GLsizei* arg2 = new GLsizei[arrHandle2->Length()];
  for (unsigned j = 0; j < arrHandle2->Length(); j++) {
      Handle<Value> arg(arrHandle2->Get(Integer::New(j)));
      GLsizei aux = (GLsizei)arg->IntegerValue();
      arg2[j] = aux;
  }

  String::Utf8Value value3(args[3]);
  char* arg3 = *value3;

  //make call
  glGetProgramInfoLog((GLuint) arg0, (GLsizei) arg1, (GLsizei*) arg2, (char*) arg3);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglGetRenderbufferParameterivCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();


  Handle<Array> arrHandle2 = Handle<Array>::Cast(args[2]);
  GLint* arg2 = new GLint[arrHandle2->Length()];
  for (unsigned j = 0; j < arrHandle2->Length(); j++) {
      Handle<Value> arg(arrHandle2->Get(Integer::New(j)));
      GLint aux = (GLint)arg->IntegerValue();
      arg2[j] = aux;
  }


  //make call
  glGetRenderbufferParameteriv((GLenum) arg0, (GLenum) arg1, (GLint*) arg2);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglGetShaderivCallback(const Arguments& args) {
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
  glGetShaderiv((GLuint) arg0, (GLenum) arg1, (GLint*) arg2);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglGetShaderInfoLogCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 4) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  int arg1 = args[1]->IntegerValue();


  Handle<Array> arrHandle2 = Handle<Array>::Cast(args[2]);
  GLsizei* arg2 = new GLsizei[arrHandle2->Length()];
  for (unsigned j = 0; j < arrHandle2->Length(); j++) {
      Handle<Value> arg(arrHandle2->Get(Integer::New(j)));
      GLsizei aux = (GLsizei)arg->IntegerValue();
      arg2[j] = aux;
  }

  String::Utf8Value value3(args[3]);
  char* arg3 = *value3;

  //make call
  glGetShaderInfoLog((GLuint) arg0, (GLsizei) arg1, (GLsizei*) arg2, (char*) arg3);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglGetShaderSourceCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 4) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  int arg1 = args[1]->IntegerValue();


  Handle<Array> arrHandle2 = Handle<Array>::Cast(args[2]);
  GLsizei* arg2 = new GLsizei[arrHandle2->Length()];
  for (unsigned j = 0; j < arrHandle2->Length(); j++) {
      Handle<Value> arg(arrHandle2->Get(Integer::New(j)));
      GLsizei aux = (GLsizei)arg->IntegerValue();
      arg2[j] = aux;
  }

  String::Utf8Value value3(args[3]);
  char* arg3 = *value3;

  //make call
  glGetShaderSource((GLuint) arg0, (GLsizei) arg1, (GLsizei*) arg2, (char*) arg3);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglGetTexParameterfvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();


  Handle<Array> arrHandle2 = Handle<Array>::Cast(args[2]);
  GLfloat* arg2 = new GLfloat[arrHandle2->Length()];
  for (unsigned j = 0; j < arrHandle2->Length(); j++) {
      Handle<Value> arg(arrHandle2->Get(Integer::New(j)));
      GLfloat aux = (GLfloat)arg->NumberValue();
      arg2[j] = aux;
  }


  //make call
  glGetTexParameterfv((GLenum) arg0, (GLenum) arg1, (GLfloat*) arg2);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglGetTexParameterivCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();


  Handle<Array> arrHandle2 = Handle<Array>::Cast(args[2]);
  GLint* arg2 = new GLint[arrHandle2->Length()];
  for (unsigned j = 0; j < arrHandle2->Length(); j++) {
      Handle<Value> arg(arrHandle2->Get(Integer::New(j)));
      GLint aux = (GLint)arg->IntegerValue();
      arg2[j] = aux;
  }


  //make call
  glGetTexParameteriv((GLenum) arg0, (GLenum) arg1, (GLint*) arg2);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglGetUniformfvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  int arg1 = args[1]->IntegerValue();


  Handle<Array> arrHandle2 = Handle<Array>::Cast(args[2]);
  GLfloat* arg2 = new GLfloat[arrHandle2->Length()];
  for (unsigned j = 0; j < arrHandle2->Length(); j++) {
      Handle<Value> arg(arrHandle2->Get(Integer::New(j)));
      GLfloat aux = (GLfloat)arg->NumberValue();
      arg2[j] = aux;
  }


  //make call
  glGetUniformfv((GLuint) arg0, (GLint) arg1, (GLfloat*) arg2);
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




Handle<Value> GLESglGetVertexAttribfvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  int arg1 = args[1]->IntegerValue();


  Handle<Array> arrHandle2 = Handle<Array>::Cast(args[2]);
  GLfloat* arg2 = new GLfloat[arrHandle2->Length()];
  for (unsigned j = 0; j < arrHandle2->Length(); j++) {
      Handle<Value> arg(arrHandle2->Get(Integer::New(j)));
      GLfloat aux = (GLfloat)arg->NumberValue();
      arg2[j] = aux;
  }


  //make call
  glGetVertexAttribfv((GLuint) arg0, (GLenum) arg1, (GLfloat*) arg2);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglGetVertexAttribivCallback(const Arguments& args) {
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
  glGetVertexAttribiv((GLuint) arg0, (GLenum) arg1, (GLint*) arg2);
  Handle<Object> res(GlesFactory::self_);
  return res;
}




Handle<Value> GLESglHintCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();

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
  int arg0 = args[0]->IntegerValue();

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
  int arg0 = args[0]->IntegerValue();
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
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
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



Handle<Value> GLESglStencilFuncCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
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
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
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
  int arg0 = args[0]->IntegerValue();
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
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();

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
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();
  int arg3 = args[3]->IntegerValue();

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
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
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
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
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

      Handle<ObjectTemplate> Gl = ObjectTemplate::New();
      
      Gl->SetInternalFieldCount(1);

     Gl->Set(String::NewSymbol("ES_VERSION_2_0"), Uint32::New(GL_ES_VERSION_2_0), ReadOnly);

     Gl->Set(String::NewSymbol("DEPTH_BUFFER_BIT"), Uint32::New(GL_DEPTH_BUFFER_BIT), ReadOnly);

     Gl->Set(String::NewSymbol("STENCIL_BUFFER_BIT"), Uint32::New(GL_STENCIL_BUFFER_BIT), ReadOnly);

     Gl->Set(String::NewSymbol("COLOR_BUFFER_BIT"), Uint32::New(GL_COLOR_BUFFER_BIT), ReadOnly);

     Gl->Set(String::NewSymbol("FALSE"), Uint32::New(GL_FALSE), ReadOnly);

     Gl->Set(String::NewSymbol("TRUE"), Uint32::New(GL_TRUE), ReadOnly);

     Gl->Set(String::NewSymbol("POINTS"), Uint32::New(GL_POINTS), ReadOnly);

     Gl->Set(String::NewSymbol("LINES"), Uint32::New(GL_LINES), ReadOnly);

     Gl->Set(String::NewSymbol("LINE_LOOP"), Uint32::New(GL_LINE_LOOP), ReadOnly);

     Gl->Set(String::NewSymbol("LINE_STRIP"), Uint32::New(GL_LINE_STRIP), ReadOnly);

     Gl->Set(String::NewSymbol("TRIANGLES"), Uint32::New(GL_TRIANGLES), ReadOnly);

     Gl->Set(String::NewSymbol("TRIANGLE_STRIP"), Uint32::New(GL_TRIANGLE_STRIP), ReadOnly);

     Gl->Set(String::NewSymbol("TRIANGLE_FAN"), Uint32::New(GL_TRIANGLE_FAN), ReadOnly);

     Gl->Set(String::NewSymbol("ZERO"), Uint32::New(GL_ZERO), ReadOnly);

     Gl->Set(String::NewSymbol("ONE"), Uint32::New(GL_ONE), ReadOnly);

     Gl->Set(String::NewSymbol("SRC_COLOR"), Uint32::New(GL_SRC_COLOR), ReadOnly);

     Gl->Set(String::NewSymbol("ONE_MINUS_SRC_COLOR"), Uint32::New(GL_ONE_MINUS_SRC_COLOR), ReadOnly);

     Gl->Set(String::NewSymbol("SRC_ALPHA"), Uint32::New(GL_SRC_ALPHA), ReadOnly);

     Gl->Set(String::NewSymbol("ONE_MINUS_SRC_ALPHA"), Uint32::New(GL_ONE_MINUS_SRC_ALPHA), ReadOnly);

     Gl->Set(String::NewSymbol("DST_ALPHA"), Uint32::New(GL_DST_ALPHA), ReadOnly);

     Gl->Set(String::NewSymbol("ONE_MINUS_DST_ALPHA"), Uint32::New(GL_ONE_MINUS_DST_ALPHA), ReadOnly);

     Gl->Set(String::NewSymbol("DST_COLOR"), Uint32::New(GL_DST_COLOR), ReadOnly);

     Gl->Set(String::NewSymbol("ONE_MINUS_DST_COLOR"), Uint32::New(GL_ONE_MINUS_DST_COLOR), ReadOnly);

     Gl->Set(String::NewSymbol("SRC_ALPHA_SATURATE"), Uint32::New(GL_SRC_ALPHA_SATURATE), ReadOnly);

     Gl->Set(String::NewSymbol("FUNC_ADD"), Uint32::New(GL_FUNC_ADD), ReadOnly);

     Gl->Set(String::NewSymbol("FUNC_SUBTRACT"), Uint32::New(GL_FUNC_SUBTRACT), ReadOnly);

     Gl->Set(String::NewSymbol("FUNC_REVERSE_SUBTRACT"), Uint32::New(GL_FUNC_REVERSE_SUBTRACT), ReadOnly);

     Gl->Set(String::NewSymbol("BLEND_DST_RGB"), Uint32::New(GL_BLEND_DST_RGB), ReadOnly);

     Gl->Set(String::NewSymbol("BLEND_SRC_RGB"), Uint32::New(GL_BLEND_SRC_RGB), ReadOnly);

     Gl->Set(String::NewSymbol("BLEND_DST_ALPHA"), Uint32::New(GL_BLEND_DST_ALPHA), ReadOnly);

     Gl->Set(String::NewSymbol("BLEND_SRC_ALPHA"), Uint32::New(GL_BLEND_SRC_ALPHA), ReadOnly);

     Gl->Set(String::NewSymbol("CONSTANT_COLOR"), Uint32::New(GL_CONSTANT_COLOR), ReadOnly);

     Gl->Set(String::NewSymbol("ONE_MINUS_CONSTANT_COLOR"), Uint32::New(GL_ONE_MINUS_CONSTANT_COLOR), ReadOnly);

     Gl->Set(String::NewSymbol("CONSTANT_ALPHA"), Uint32::New(GL_CONSTANT_ALPHA), ReadOnly);

     Gl->Set(String::NewSymbol("ONE_MINUS_CONSTANT_ALPHA"), Uint32::New(GL_ONE_MINUS_CONSTANT_ALPHA), ReadOnly);

     Gl->Set(String::NewSymbol("BLEND_COLOR"), Uint32::New(GL_BLEND_COLOR), ReadOnly);

     Gl->Set(String::NewSymbol("ARRAY_BUFFER"), Uint32::New(GL_ARRAY_BUFFER), ReadOnly);

     Gl->Set(String::NewSymbol("ELEMENT_ARRAY_BUFFER"), Uint32::New(GL_ELEMENT_ARRAY_BUFFER), ReadOnly);

     Gl->Set(String::NewSymbol("ARRAY_BUFFER_BINDING"), Uint32::New(GL_ARRAY_BUFFER_BINDING), ReadOnly);

     Gl->Set(String::NewSymbol("ELEMENT_ARRAY_BUFFER_BINDING"), Uint32::New(GL_ELEMENT_ARRAY_BUFFER_BINDING), ReadOnly);

     Gl->Set(String::NewSymbol("STREAM_DRAW"), Uint32::New(GL_STREAM_DRAW), ReadOnly);

     Gl->Set(String::NewSymbol("DYNAMIC_DRAW"), Uint32::New(GL_DYNAMIC_DRAW), ReadOnly);

     Gl->Set(String::NewSymbol("BUFFER_SIZE"), Uint32::New(GL_BUFFER_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("BUFFER_USAGE"), Uint32::New(GL_BUFFER_USAGE), ReadOnly);

     Gl->Set(String::NewSymbol("CURRENT_VERTEX_ATTRIB"), Uint32::New(GL_CURRENT_VERTEX_ATTRIB), ReadOnly);

     Gl->Set(String::NewSymbol("FRONT"), Uint32::New(GL_FRONT), ReadOnly);

     Gl->Set(String::NewSymbol("BACK"), Uint32::New(GL_BACK), ReadOnly);

     Gl->Set(String::NewSymbol("FRONT_AND_BACK"), Uint32::New(GL_FRONT_AND_BACK), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_2D"), Uint32::New(GL_TEXTURE_2D), ReadOnly);

     Gl->Set(String::NewSymbol("CULL_FACE"), Uint32::New(GL_CULL_FACE), ReadOnly);

     Gl->Set(String::NewSymbol("BLEND"), Uint32::New(GL_BLEND), ReadOnly);

     Gl->Set(String::NewSymbol("DITHER"), Uint32::New(GL_DITHER), ReadOnly);

     Gl->Set(String::NewSymbol("STENCIL_TEST"), Uint32::New(GL_STENCIL_TEST), ReadOnly);

     Gl->Set(String::NewSymbol("DEPTH_TEST"), Uint32::New(GL_DEPTH_TEST), ReadOnly);

     Gl->Set(String::NewSymbol("SCISSOR_TEST"), Uint32::New(GL_SCISSOR_TEST), ReadOnly);

     Gl->Set(String::NewSymbol("POLYGON_OFFSET_FILL"), Uint32::New(GL_POLYGON_OFFSET_FILL), ReadOnly);

     Gl->Set(String::NewSymbol("SAMPLE_ALPHA_TO_COVERAGE"), Uint32::New(GL_SAMPLE_ALPHA_TO_COVERAGE), ReadOnly);

     Gl->Set(String::NewSymbol("SAMPLE_COVERAGE"), Uint32::New(GL_SAMPLE_COVERAGE), ReadOnly);

     Gl->Set(String::NewSymbol("NO_ERROR"), Uint32::New(GL_NO_ERROR), ReadOnly);

     Gl->Set(String::NewSymbol("INVALID_ENUM"), Uint32::New(GL_INVALID_ENUM), ReadOnly);

     Gl->Set(String::NewSymbol("INVALID_VALUE"), Uint32::New(GL_INVALID_VALUE), ReadOnly);

     Gl->Set(String::NewSymbol("OUT_OF_MEMORY"), Uint32::New(GL_OUT_OF_MEMORY), ReadOnly);

     Gl->Set(String::NewSymbol("CW"), Uint32::New(GL_CW), ReadOnly);

     Gl->Set(String::NewSymbol("CCW"), Uint32::New(GL_CCW), ReadOnly);

     Gl->Set(String::NewSymbol("LINE_WIDTH"), Uint32::New(GL_LINE_WIDTH), ReadOnly);

     Gl->Set(String::NewSymbol("ALIASED_POINT_SIZE_RANGE"), Uint32::New(GL_ALIASED_POINT_SIZE_RANGE), ReadOnly);

     Gl->Set(String::NewSymbol("ALIASED_LINE_WIDTH_RANGE"), Uint32::New(GL_ALIASED_LINE_WIDTH_RANGE), ReadOnly);

     Gl->Set(String::NewSymbol("CULL_FACE_MODE"), Uint32::New(GL_CULL_FACE_MODE), ReadOnly);

     Gl->Set(String::NewSymbol("FRONT_FACE"), Uint32::New(GL_FRONT_FACE), ReadOnly);

     Gl->Set(String::NewSymbol("DEPTH_RANGE"), Uint32::New(GL_DEPTH_RANGE), ReadOnly);

     Gl->Set(String::NewSymbol("DEPTH_WRITEMASK"), Uint32::New(GL_DEPTH_WRITEMASK), ReadOnly);

     Gl->Set(String::NewSymbol("DEPTH_CLEAR_VALUE"), Uint32::New(GL_DEPTH_CLEAR_VALUE), ReadOnly);

     Gl->Set(String::NewSymbol("DEPTH_FUNC"), Uint32::New(GL_DEPTH_FUNC), ReadOnly);

     Gl->Set(String::NewSymbol("STENCIL_CLEAR_VALUE"), Uint32::New(GL_STENCIL_CLEAR_VALUE), ReadOnly);

     Gl->Set(String::NewSymbol("STENCIL_FUNC"), Uint32::New(GL_STENCIL_FUNC), ReadOnly);

     Gl->Set(String::NewSymbol("STENCIL_FAIL"), Uint32::New(GL_STENCIL_FAIL), ReadOnly);

     Gl->Set(String::NewSymbol("STENCIL_PASS_DEPTH_FAIL"), Uint32::New(GL_STENCIL_PASS_DEPTH_FAIL), ReadOnly);

     Gl->Set(String::NewSymbol("STENCIL_PASS_DEPTH_PASS"), Uint32::New(GL_STENCIL_PASS_DEPTH_PASS), ReadOnly);

     Gl->Set(String::NewSymbol("STENCIL_REF"), Uint32::New(GL_STENCIL_REF), ReadOnly);

     Gl->Set(String::NewSymbol("STENCIL_VALUE_MASK"), Uint32::New(GL_STENCIL_VALUE_MASK), ReadOnly);

     Gl->Set(String::NewSymbol("STENCIL_WRITEMASK"), Uint32::New(GL_STENCIL_WRITEMASK), ReadOnly);

     Gl->Set(String::NewSymbol("STENCIL_BACK_FUNC"), Uint32::New(GL_STENCIL_BACK_FUNC), ReadOnly);

     Gl->Set(String::NewSymbol("STENCIL_BACK_FAIL"), Uint32::New(GL_STENCIL_BACK_FAIL), ReadOnly);

     Gl->Set(String::NewSymbol("STENCIL_BACK_PASS_DEPTH_FAIL"), Uint32::New(GL_STENCIL_BACK_PASS_DEPTH_FAIL), ReadOnly);

     Gl->Set(String::NewSymbol("STENCIL_BACK_PASS_DEPTH_PASS"), Uint32::New(GL_STENCIL_BACK_PASS_DEPTH_PASS), ReadOnly);

     Gl->Set(String::NewSymbol("STENCIL_BACK_REF"), Uint32::New(GL_STENCIL_BACK_REF), ReadOnly);

     Gl->Set(String::NewSymbol("STENCIL_BACK_VALUE_MASK"), Uint32::New(GL_STENCIL_BACK_VALUE_MASK), ReadOnly);

     Gl->Set(String::NewSymbol("STENCIL_BACK_WRITEMASK"), Uint32::New(GL_STENCIL_BACK_WRITEMASK), ReadOnly);

     Gl->Set(String::NewSymbol("VIEWPORT"), Uint32::New(GL_VIEWPORT), ReadOnly);

     Gl->Set(String::NewSymbol("SCISSOR_BOX"), Uint32::New(GL_SCISSOR_BOX), ReadOnly);

     Gl->Set(String::NewSymbol("COLOR_CLEAR_VALUE"), Uint32::New(GL_COLOR_CLEAR_VALUE), ReadOnly);

     Gl->Set(String::NewSymbol("COLOR_WRITEMASK"), Uint32::New(GL_COLOR_WRITEMASK), ReadOnly);

     Gl->Set(String::NewSymbol("UNPACK_ALIGNMENT"), Uint32::New(GL_UNPACK_ALIGNMENT), ReadOnly);

     Gl->Set(String::NewSymbol("PACK_ALIGNMENT"), Uint32::New(GL_PACK_ALIGNMENT), ReadOnly);

     Gl->Set(String::NewSymbol("MAX_TEXTURE_SIZE"), Uint32::New(GL_MAX_TEXTURE_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("MAX_VIEWPORT_DIMS"), Uint32::New(GL_MAX_VIEWPORT_DIMS), ReadOnly);

     Gl->Set(String::NewSymbol("SUBPIXEL_BITS"), Uint32::New(GL_SUBPIXEL_BITS), ReadOnly);

     Gl->Set(String::NewSymbol("RED_BITS"), Uint32::New(GL_RED_BITS), ReadOnly);

     Gl->Set(String::NewSymbol("GREEN_BITS"), Uint32::New(GL_GREEN_BITS), ReadOnly);

     Gl->Set(String::NewSymbol("BLUE_BITS"), Uint32::New(GL_BLUE_BITS), ReadOnly);

     Gl->Set(String::NewSymbol("ALPHA_BITS"), Uint32::New(GL_ALPHA_BITS), ReadOnly);

     Gl->Set(String::NewSymbol("DEPTH_BITS"), Uint32::New(GL_DEPTH_BITS), ReadOnly);

     Gl->Set(String::NewSymbol("STENCIL_BITS"), Uint32::New(GL_STENCIL_BITS), ReadOnly);

     Gl->Set(String::NewSymbol("POLYGON_OFFSET_UNITS"), Uint32::New(GL_POLYGON_OFFSET_UNITS), ReadOnly);

     Gl->Set(String::NewSymbol("POLYGON_OFFSET_FACTOR"), Uint32::New(GL_POLYGON_OFFSET_FACTOR), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_BINDING_2D"), Uint32::New(GL_TEXTURE_BINDING_2D), ReadOnly);

     Gl->Set(String::NewSymbol("SAMPLE_BUFFERS"), Uint32::New(GL_SAMPLE_BUFFERS), ReadOnly);

     Gl->Set(String::NewSymbol("SAMPLES"), Uint32::New(GL_SAMPLES), ReadOnly);

     Gl->Set(String::NewSymbol("SAMPLE_COVERAGE_VALUE"), Uint32::New(GL_SAMPLE_COVERAGE_VALUE), ReadOnly);

     Gl->Set(String::NewSymbol("SAMPLE_COVERAGE_INVERT"), Uint32::New(GL_SAMPLE_COVERAGE_INVERT), ReadOnly);

     Gl->Set(String::NewSymbol("NUM_COMPRESSED_TEXTURE_FORMATS"), Uint32::New(GL_NUM_COMPRESSED_TEXTURE_FORMATS), ReadOnly);

     Gl->Set(String::NewSymbol("COMPRESSED_TEXTURE_FORMATS"), Uint32::New(GL_COMPRESSED_TEXTURE_FORMATS), ReadOnly);

     Gl->Set(String::NewSymbol("DONT_CARE"), Uint32::New(GL_DONT_CARE), ReadOnly);

     Gl->Set(String::NewSymbol("FASTEST"), Uint32::New(GL_FASTEST), ReadOnly);

     Gl->Set(String::NewSymbol("NICEST"), Uint32::New(GL_NICEST), ReadOnly);

     Gl->Set(String::NewSymbol("GENERATE_MIPMAP_HINT"), Uint32::New(GL_GENERATE_MIPMAP_HINT), ReadOnly);

     Gl->Set(String::NewSymbol("BYTE"), Uint32::New(GL_BYTE), ReadOnly);

     Gl->Set(String::NewSymbol("UNSIGNED_BYTE"), Uint32::New(GL_UNSIGNED_BYTE), ReadOnly);

     Gl->Set(String::NewSymbol("SHORT"), Uint32::New(GL_SHORT), ReadOnly);

     Gl->Set(String::NewSymbol("UNSIGNED_SHORT"), Uint32::New(GL_UNSIGNED_SHORT), ReadOnly);

     Gl->Set(String::NewSymbol("INT"), Uint32::New(GL_INT), ReadOnly);

     Gl->Set(String::NewSymbol("UNSIGNED_INT"), Uint32::New(GL_UNSIGNED_INT), ReadOnly);

     Gl->Set(String::NewSymbol("FLOAT"), Uint32::New(GL_FLOAT), ReadOnly);

     Gl->Set(String::NewSymbol("FIXED"), Uint32::New(GL_FIXED), ReadOnly);

     Gl->Set(String::NewSymbol("DEPTH_COMPONENT"), Uint32::New(GL_DEPTH_COMPONENT), ReadOnly);

     Gl->Set(String::NewSymbol("ALPHA"), Uint32::New(GL_ALPHA), ReadOnly);

     Gl->Set(String::NewSymbol("RGB"), Uint32::New(GL_RGB), ReadOnly);

     Gl->Set(String::NewSymbol("RGBA"), Uint32::New(GL_RGBA), ReadOnly);

     Gl->Set(String::NewSymbol("LUMINANCE"), Uint32::New(GL_LUMINANCE), ReadOnly);

     Gl->Set(String::NewSymbol("LUMINANCE_ALPHA"), Uint32::New(GL_LUMINANCE_ALPHA), ReadOnly);

     Gl->Set(String::NewSymbol("UNSIGNED_SHORT_4_4_4_4"), Uint32::New(GL_UNSIGNED_SHORT_4_4_4_4), ReadOnly);

     Gl->Set(String::NewSymbol("UNSIGNED_SHORT_5_5_5_1"), Uint32::New(GL_UNSIGNED_SHORT_5_5_5_1), ReadOnly);

     Gl->Set(String::NewSymbol("UNSIGNED_SHORT_5_6_5"), Uint32::New(GL_UNSIGNED_SHORT_5_6_5), ReadOnly);

     Gl->Set(String::NewSymbol("FRAGMENT_SHADER"), Uint32::New(GL_FRAGMENT_SHADER), ReadOnly);

     Gl->Set(String::NewSymbol("VERTEX_SHADER"), Uint32::New(GL_VERTEX_SHADER), ReadOnly);

     Gl->Set(String::NewSymbol("MAX_VERTEX_ATTRIBS"), Uint32::New(GL_MAX_VERTEX_ATTRIBS), ReadOnly);

     Gl->Set(String::NewSymbol("MAX_VERTEX_UNIFORM_VECTORS"), Uint32::New(GL_MAX_VERTEX_UNIFORM_VECTORS), ReadOnly);

     Gl->Set(String::NewSymbol("MAX_VARYING_VECTORS"), Uint32::New(GL_MAX_VARYING_VECTORS), ReadOnly);

     Gl->Set(String::NewSymbol("MAX_COMBINED_TEXTURE_IMAGE_UNITS"), Uint32::New(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS), ReadOnly);

     Gl->Set(String::NewSymbol("MAX_VERTEX_TEXTURE_IMAGE_UNITS"), Uint32::New(GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS), ReadOnly);

     Gl->Set(String::NewSymbol("MAX_TEXTURE_IMAGE_UNITS"), Uint32::New(GL_MAX_TEXTURE_IMAGE_UNITS), ReadOnly);

     Gl->Set(String::NewSymbol("MAX_FRAGMENT_UNIFORM_VECTORS"), Uint32::New(GL_MAX_FRAGMENT_UNIFORM_VECTORS), ReadOnly);

     Gl->Set(String::NewSymbol("SHADER_TYPE"), Uint32::New(GL_SHADER_TYPE), ReadOnly);

     Gl->Set(String::NewSymbol("DELETE_STATUS"), Uint32::New(GL_DELETE_STATUS), ReadOnly);

     Gl->Set(String::NewSymbol("LINK_STATUS"), Uint32::New(GL_LINK_STATUS), ReadOnly);

     Gl->Set(String::NewSymbol("VALIDATE_STATUS"), Uint32::New(GL_VALIDATE_STATUS), ReadOnly);

     Gl->Set(String::NewSymbol("ATTACHED_SHADERS"), Uint32::New(GL_ATTACHED_SHADERS), ReadOnly);

     Gl->Set(String::NewSymbol("ACTIVE_UNIFORMS"), Uint32::New(GL_ACTIVE_UNIFORMS), ReadOnly);

     Gl->Set(String::NewSymbol("ACTIVE_UNIFORM_MAX_LENGTH"), Uint32::New(GL_ACTIVE_UNIFORM_MAX_LENGTH), ReadOnly);

     Gl->Set(String::NewSymbol("ACTIVE_ATTRIBUTES"), Uint32::New(GL_ACTIVE_ATTRIBUTES), ReadOnly);

     Gl->Set(String::NewSymbol("ACTIVE_ATTRIBUTE_MAX_LENGTH"), Uint32::New(GL_ACTIVE_ATTRIBUTE_MAX_LENGTH), ReadOnly);

     Gl->Set(String::NewSymbol("SHADING_LANGUAGE_VERSION"), Uint32::New(GL_SHADING_LANGUAGE_VERSION), ReadOnly);

     Gl->Set(String::NewSymbol("CURRENT_PROGRAM"), Uint32::New(GL_CURRENT_PROGRAM), ReadOnly);

     Gl->Set(String::NewSymbol("NEVER"), Uint32::New(GL_NEVER), ReadOnly);

     Gl->Set(String::NewSymbol("LESS"), Uint32::New(GL_LESS), ReadOnly);

     Gl->Set(String::NewSymbol("EQUAL"), Uint32::New(GL_EQUAL), ReadOnly);

     Gl->Set(String::NewSymbol("LEQUAL"), Uint32::New(GL_LEQUAL), ReadOnly);

     Gl->Set(String::NewSymbol("GREATER"), Uint32::New(GL_GREATER), ReadOnly);

     Gl->Set(String::NewSymbol("NOTEQUAL"), Uint32::New(GL_NOTEQUAL), ReadOnly);

     Gl->Set(String::NewSymbol("GEQUAL"), Uint32::New(GL_GEQUAL), ReadOnly);

     Gl->Set(String::NewSymbol("ALWAYS"), Uint32::New(GL_ALWAYS), ReadOnly);

     Gl->Set(String::NewSymbol("KEEP"), Uint32::New(GL_KEEP), ReadOnly);

     Gl->Set(String::NewSymbol("REPLACE"), Uint32::New(GL_REPLACE), ReadOnly);

     Gl->Set(String::NewSymbol("INCR"), Uint32::New(GL_INCR), ReadOnly);

     Gl->Set(String::NewSymbol("DECR"), Uint32::New(GL_DECR), ReadOnly);

     Gl->Set(String::NewSymbol("INVERT"), Uint32::New(GL_INVERT), ReadOnly);

     Gl->Set(String::NewSymbol("INCR_WRAP"), Uint32::New(GL_INCR_WRAP), ReadOnly);

     Gl->Set(String::NewSymbol("DECR_WRAP"), Uint32::New(GL_DECR_WRAP), ReadOnly);

     Gl->Set(String::NewSymbol("VENDOR"), Uint32::New(GL_VENDOR), ReadOnly);

     Gl->Set(String::NewSymbol("RENDERER"), Uint32::New(GL_RENDERER), ReadOnly);

     Gl->Set(String::NewSymbol("VERSION"), Uint32::New(GL_VERSION), ReadOnly);

     Gl->Set(String::NewSymbol("EXTENSIONS"), Uint32::New(GL_EXTENSIONS), ReadOnly);

     Gl->Set(String::NewSymbol("NEAREST"), Uint32::New(GL_NEAREST), ReadOnly);

     Gl->Set(String::NewSymbol("LINEAR"), Uint32::New(GL_LINEAR), ReadOnly);

     Gl->Set(String::NewSymbol("NEAREST_MIPMAP_NEAREST"), Uint32::New(GL_NEAREST_MIPMAP_NEAREST), ReadOnly);

     Gl->Set(String::NewSymbol("LINEAR_MIPMAP_NEAREST"), Uint32::New(GL_LINEAR_MIPMAP_NEAREST), ReadOnly);

     Gl->Set(String::NewSymbol("NEAREST_MIPMAP_LINEAR"), Uint32::New(GL_NEAREST_MIPMAP_LINEAR), ReadOnly);

     Gl->Set(String::NewSymbol("LINEAR_MIPMAP_LINEAR"), Uint32::New(GL_LINEAR_MIPMAP_LINEAR), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_MAG_FILTER"), Uint32::New(GL_TEXTURE_MAG_FILTER), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_MIN_FILTER"), Uint32::New(GL_TEXTURE_MIN_FILTER), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_WRAP_S"), Uint32::New(GL_TEXTURE_WRAP_S), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_WRAP_T"), Uint32::New(GL_TEXTURE_WRAP_T), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE"), Uint32::New(GL_TEXTURE), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_CUBE_MAP"), Uint32::New(GL_TEXTURE_CUBE_MAP), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_BINDING_CUBE_MAP"), Uint32::New(GL_TEXTURE_BINDING_CUBE_MAP), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_CUBE_MAP_POSITIVE_X"), Uint32::New(GL_TEXTURE_CUBE_MAP_POSITIVE_X), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_CUBE_MAP_POSITIVE_Y"), Uint32::New(GL_TEXTURE_CUBE_MAP_POSITIVE_Y), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_CUBE_MAP_POSITIVE_Z"), Uint32::New(GL_TEXTURE_CUBE_MAP_POSITIVE_Z), ReadOnly);

     Gl->Set(String::NewSymbol("MAX_CUBE_MAP_TEXTURE_SIZE"), Uint32::New(GL_MAX_CUBE_MAP_TEXTURE_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE0"), Uint32::New(GL_TEXTURE0), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE1"), Uint32::New(GL_TEXTURE1), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE2"), Uint32::New(GL_TEXTURE2), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE3"), Uint32::New(GL_TEXTURE3), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE4"), Uint32::New(GL_TEXTURE4), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE5"), Uint32::New(GL_TEXTURE5), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE6"), Uint32::New(GL_TEXTURE6), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE7"), Uint32::New(GL_TEXTURE7), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE8"), Uint32::New(GL_TEXTURE8), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE9"), Uint32::New(GL_TEXTURE9), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE10"), Uint32::New(GL_TEXTURE10), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE11"), Uint32::New(GL_TEXTURE11), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE12"), Uint32::New(GL_TEXTURE12), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE13"), Uint32::New(GL_TEXTURE13), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE14"), Uint32::New(GL_TEXTURE14), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE15"), Uint32::New(GL_TEXTURE15), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE16"), Uint32::New(GL_TEXTURE16), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE17"), Uint32::New(GL_TEXTURE17), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE18"), Uint32::New(GL_TEXTURE18), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE19"), Uint32::New(GL_TEXTURE19), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE20"), Uint32::New(GL_TEXTURE20), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE21"), Uint32::New(GL_TEXTURE21), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE22"), Uint32::New(GL_TEXTURE22), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE23"), Uint32::New(GL_TEXTURE23), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE24"), Uint32::New(GL_TEXTURE24), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE25"), Uint32::New(GL_TEXTURE25), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE26"), Uint32::New(GL_TEXTURE26), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE27"), Uint32::New(GL_TEXTURE27), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE28"), Uint32::New(GL_TEXTURE28), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE29"), Uint32::New(GL_TEXTURE29), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE30"), Uint32::New(GL_TEXTURE30), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE31"), Uint32::New(GL_TEXTURE31), ReadOnly);

     Gl->Set(String::NewSymbol("ACTIVE_TEXTURE"), Uint32::New(GL_ACTIVE_TEXTURE), ReadOnly);

     Gl->Set(String::NewSymbol("REPEAT"), Uint32::New(GL_REPEAT), ReadOnly);

     Gl->Set(String::NewSymbol("CLAMP_TO_EDGE"), Uint32::New(GL_CLAMP_TO_EDGE), ReadOnly);

     Gl->Set(String::NewSymbol("MIRRORED_REPEAT"), Uint32::New(GL_MIRRORED_REPEAT), ReadOnly);

     Gl->Set(String::NewSymbol("FLOAT_VEC2"), Uint32::New(GL_FLOAT_VEC2), ReadOnly);

     Gl->Set(String::NewSymbol("FLOAT_VEC3"), Uint32::New(GL_FLOAT_VEC3), ReadOnly);

     Gl->Set(String::NewSymbol("FLOAT_VEC4"), Uint32::New(GL_FLOAT_VEC4), ReadOnly);

     Gl->Set(String::NewSymbol("INT_VEC2"), Uint32::New(GL_INT_VEC2), ReadOnly);

     Gl->Set(String::NewSymbol("INT_VEC3"), Uint32::New(GL_INT_VEC3), ReadOnly);

     Gl->Set(String::NewSymbol("INT_VEC4"), Uint32::New(GL_INT_VEC4), ReadOnly);

     Gl->Set(String::NewSymbol("BOOL"), Uint32::New(GL_BOOL), ReadOnly);

     Gl->Set(String::NewSymbol("BOOL_VEC2"), Uint32::New(GL_BOOL_VEC2), ReadOnly);

     Gl->Set(String::NewSymbol("BOOL_VEC3"), Uint32::New(GL_BOOL_VEC3), ReadOnly);

     Gl->Set(String::NewSymbol("BOOL_VEC4"), Uint32::New(GL_BOOL_VEC4), ReadOnly);

     Gl->Set(String::NewSymbol("FLOAT_MAT2"), Uint32::New(GL_FLOAT_MAT2), ReadOnly);

     Gl->Set(String::NewSymbol("FLOAT_MAT3"), Uint32::New(GL_FLOAT_MAT3), ReadOnly);

     Gl->Set(String::NewSymbol("FLOAT_MAT4"), Uint32::New(GL_FLOAT_MAT4), ReadOnly);

     Gl->Set(String::NewSymbol("SAMPLER_2D"), Uint32::New(GL_SAMPLER_2D), ReadOnly);

     Gl->Set(String::NewSymbol("SAMPLER_CUBE"), Uint32::New(GL_SAMPLER_CUBE), ReadOnly);

     Gl->Set(String::NewSymbol("VERTEX_ATTRIB_ARRAY_ENABLED"), Uint32::New(GL_VERTEX_ATTRIB_ARRAY_ENABLED), ReadOnly);

     Gl->Set(String::NewSymbol("VERTEX_ATTRIB_ARRAY_SIZE"), Uint32::New(GL_VERTEX_ATTRIB_ARRAY_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("VERTEX_ATTRIB_ARRAY_STRIDE"), Uint32::New(GL_VERTEX_ATTRIB_ARRAY_STRIDE), ReadOnly);

     Gl->Set(String::NewSymbol("VERTEX_ATTRIB_ARRAY_TYPE"), Uint32::New(GL_VERTEX_ATTRIB_ARRAY_TYPE), ReadOnly);

     Gl->Set(String::NewSymbol("VERTEX_ATTRIB_ARRAY_NORMALIZED"), Uint32::New(GL_VERTEX_ATTRIB_ARRAY_NORMALIZED), ReadOnly);

     Gl->Set(String::NewSymbol("VERTEX_ATTRIB_ARRAY_POINTER"), Uint32::New(GL_VERTEX_ATTRIB_ARRAY_POINTER), ReadOnly);

     Gl->Set(String::NewSymbol("VERTEX_ATTRIB_ARRAY_BUFFER_BINDING"), Uint32::New(GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING), ReadOnly);

     Gl->Set(String::NewSymbol("COMPILE_STATUS"), Uint32::New(GL_COMPILE_STATUS), ReadOnly);

     Gl->Set(String::NewSymbol("INFO_LOG_LENGTH"), Uint32::New(GL_INFO_LOG_LENGTH), ReadOnly);

     Gl->Set(String::NewSymbol("SHADER_SOURCE_LENGTH"), Uint32::New(GL_SHADER_SOURCE_LENGTH), ReadOnly);

     Gl->Set(String::NewSymbol("SHADER_COMPILER"), Uint32::New(GL_SHADER_COMPILER), ReadOnly);

     Gl->Set(String::NewSymbol("SHADER_BINARY_FORMATS"), Uint32::New(GL_SHADER_BINARY_FORMATS), ReadOnly);

     Gl->Set(String::NewSymbol("NUM_SHADER_BINARY_FORMATS"), Uint32::New(GL_NUM_SHADER_BINARY_FORMATS), ReadOnly);

     Gl->Set(String::NewSymbol("LOW_FLOAT"), Uint32::New(GL_LOW_FLOAT), ReadOnly);

     Gl->Set(String::NewSymbol("MEDIUM_FLOAT"), Uint32::New(GL_MEDIUM_FLOAT), ReadOnly);

     Gl->Set(String::NewSymbol("HIGH_FLOAT"), Uint32::New(GL_HIGH_FLOAT), ReadOnly);

     Gl->Set(String::NewSymbol("LOW_INT"), Uint32::New(GL_LOW_INT), ReadOnly);

     Gl->Set(String::NewSymbol("MEDIUM_INT"), Uint32::New(GL_MEDIUM_INT), ReadOnly);

     Gl->Set(String::NewSymbol("HIGH_INT"), Uint32::New(GL_HIGH_INT), ReadOnly);

     Gl->Set(String::NewSymbol("FRAMEBUFFER"), Uint32::New(GL_FRAMEBUFFER), ReadOnly);

     Gl->Set(String::NewSymbol("RENDERBUFFER"), Uint32::New(GL_RENDERBUFFER), ReadOnly);

     Gl->Set(String::NewSymbol("RGBA4"), Uint32::New(GL_RGBA4), ReadOnly);

     Gl->Set(String::NewSymbol("RGB5_A1"), Uint32::New(GL_RGB5_A1), ReadOnly);

     Gl->Set(String::NewSymbol("RGB565"), Uint32::New(GL_RGB565), ReadOnly);

     Gl->Set(String::NewSymbol("DEPTH_COMPONENT16"), Uint32::New(GL_DEPTH_COMPONENT16), ReadOnly);

     Gl->Set(String::NewSymbol("STENCIL_INDEX"), Uint32::New(GL_STENCIL_INDEX), ReadOnly);

     Gl->Set(String::NewSymbol("STENCIL_INDEX8"), Uint32::New(GL_STENCIL_INDEX8), ReadOnly);

     Gl->Set(String::NewSymbol("RENDERBUFFER_WIDTH"), Uint32::New(GL_RENDERBUFFER_WIDTH), ReadOnly);

     Gl->Set(String::NewSymbol("RENDERBUFFER_HEIGHT"), Uint32::New(GL_RENDERBUFFER_HEIGHT), ReadOnly);

     Gl->Set(String::NewSymbol("RENDERBUFFER_INTERNAL_FORMAT"), Uint32::New(GL_RENDERBUFFER_INTERNAL_FORMAT), ReadOnly);

     Gl->Set(String::NewSymbol("RENDERBUFFER_RED_SIZE"), Uint32::New(GL_RENDERBUFFER_RED_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("RENDERBUFFER_GREEN_SIZE"), Uint32::New(GL_RENDERBUFFER_GREEN_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("RENDERBUFFER_BLUE_SIZE"), Uint32::New(GL_RENDERBUFFER_BLUE_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("RENDERBUFFER_ALPHA_SIZE"), Uint32::New(GL_RENDERBUFFER_ALPHA_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("RENDERBUFFER_DEPTH_SIZE"), Uint32::New(GL_RENDERBUFFER_DEPTH_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("RENDERBUFFER_STENCIL_SIZE"), Uint32::New(GL_RENDERBUFFER_STENCIL_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE"), Uint32::New(GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE), ReadOnly);

     Gl->Set(String::NewSymbol("FRAMEBUFFER_ATTACHMENT_OBJECT_NAME"), Uint32::New(GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME), ReadOnly);

     Gl->Set(String::NewSymbol("FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL"), Uint32::New(GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL), ReadOnly);

     Gl->Set(String::NewSymbol("FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE"), Uint32::New(GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE), ReadOnly);

     Gl->Set(String::NewSymbol("COLOR_ATTACHMENT0"), Uint32::New(GL_COLOR_ATTACHMENT0), ReadOnly);

     Gl->Set(String::NewSymbol("DEPTH_ATTACHMENT"), Uint32::New(GL_DEPTH_ATTACHMENT), ReadOnly);

     Gl->Set(String::NewSymbol("STENCIL_ATTACHMENT"), Uint32::New(GL_STENCIL_ATTACHMENT), ReadOnly);

     Gl->Set(String::NewSymbol("NONE"), Uint32::New(GL_NONE), ReadOnly);

     Gl->Set(String::NewSymbol("FRAMEBUFFER_COMPLETE"), Uint32::New(GL_FRAMEBUFFER_COMPLETE), ReadOnly);

     Gl->Set(String::NewSymbol("FRAMEBUFFER_INCOMPLETE_ATTACHMENT"), Uint32::New(GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT), ReadOnly);

     Gl->Set(String::NewSymbol("FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT"), Uint32::New(GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT), ReadOnly);

     Gl->Set(String::NewSymbol("FRAMEBUFFER_INCOMPLETE_DIMENSIONS"), Uint32::New(GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS), ReadOnly);

     Gl->Set(String::NewSymbol("FRAMEBUFFER_UNSUPPORTED"), Uint32::New(GL_FRAMEBUFFER_UNSUPPORTED), ReadOnly);

     Gl->Set(String::NewSymbol("FRAMEBUFFER_BINDING"), Uint32::New(GL_FRAMEBUFFER_BINDING), ReadOnly);

     Gl->Set(String::NewSymbol("RENDERBUFFER_BINDING"), Uint32::New(GL_RENDERBUFFER_BINDING), ReadOnly);

     Gl->Set(String::NewSymbol("MAX_RENDERBUFFER_SIZE"), Uint32::New(GL_MAX_RENDERBUFFER_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("ActiveTexture"), FunctionTemplate::New(GLESglActiveTextureCallback));

     Gl->Set(String::NewSymbol("AttachShader"), FunctionTemplate::New(GLESglAttachShaderCallback));

     Gl->Set(String::NewSymbol("BindAttribLocation"), FunctionTemplate::New(GLESglBindAttribLocationCallback));

     Gl->Set(String::NewSymbol("BindBuffer"), FunctionTemplate::New(GLESglBindBufferCallback));

     Gl->Set(String::NewSymbol("BindFramebuffer"), FunctionTemplate::New(GLESglBindFramebufferCallback));

     Gl->Set(String::NewSymbol("BindRenderbuffer"), FunctionTemplate::New(GLESglBindRenderbufferCallback));

     Gl->Set(String::NewSymbol("BindTexture"), FunctionTemplate::New(GLESglBindTextureCallback));

     Gl->Set(String::NewSymbol("BlendColor"), FunctionTemplate::New(GLESglBlendColorCallback));

     Gl->Set(String::NewSymbol("BlendEquation"), FunctionTemplate::New(GLESglBlendEquationCallback));

     Gl->Set(String::NewSymbol("BlendEquationSeparate"), FunctionTemplate::New(GLESglBlendEquationSeparateCallback));

     Gl->Set(String::NewSymbol("BlendFunc"), FunctionTemplate::New(GLESglBlendFuncCallback));

     Gl->Set(String::NewSymbol("BlendFuncSeparate"), FunctionTemplate::New(GLESglBlendFuncSeparateCallback));

     Gl->Set(String::NewSymbol("CheckFramebufferStatus"), FunctionTemplate::New(GLESglCheckFramebufferStatusCallback));

     Gl->Set(String::NewSymbol("Clear"), FunctionTemplate::New(GLESglClearCallback));

     Gl->Set(String::NewSymbol("ClearColor"), FunctionTemplate::New(GLESglClearColorCallback));

     Gl->Set(String::NewSymbol("ClearDepthf"), FunctionTemplate::New(GLESglClearDepthfCallback));

     Gl->Set(String::NewSymbol("ClearStencil"), FunctionTemplate::New(GLESglClearStencilCallback));

     Gl->Set(String::NewSymbol("ColorMask"), FunctionTemplate::New(GLESglColorMaskCallback));

     Gl->Set(String::NewSymbol("CompileShader"), FunctionTemplate::New(GLESglCompileShaderCallback));

     Gl->Set(String::NewSymbol("CopyTexImage2D"), FunctionTemplate::New(GLESglCopyTexImage2DCallback));

     Gl->Set(String::NewSymbol("CopyTexSubImage2D"), FunctionTemplate::New(GLESglCopyTexSubImage2DCallback));

     Gl->Set(String::NewSymbol("CreateProgram"), FunctionTemplate::New(GLESglCreateProgramCallback));

     Gl->Set(String::NewSymbol("CreateShader"), FunctionTemplate::New(GLESglCreateShaderCallback));

     Gl->Set(String::NewSymbol("CullFace"), FunctionTemplate::New(GLESglCullFaceCallback));

     Gl->Set(String::NewSymbol("DeleteBuffers"), FunctionTemplate::New(GLESglDeleteBuffersCallback));

     Gl->Set(String::NewSymbol("DeleteFramebuffers"), FunctionTemplate::New(GLESglDeleteFramebuffersCallback));

     Gl->Set(String::NewSymbol("DeleteProgram"), FunctionTemplate::New(GLESglDeleteProgramCallback));

     Gl->Set(String::NewSymbol("DeleteRenderbuffers"), FunctionTemplate::New(GLESglDeleteRenderbuffersCallback));

     Gl->Set(String::NewSymbol("DeleteShader"), FunctionTemplate::New(GLESglDeleteShaderCallback));

     Gl->Set(String::NewSymbol("DeleteTextures"), FunctionTemplate::New(GLESglDeleteTexturesCallback));

     Gl->Set(String::NewSymbol("DepthFunc"), FunctionTemplate::New(GLESglDepthFuncCallback));

     Gl->Set(String::NewSymbol("DepthMask"), FunctionTemplate::New(GLESglDepthMaskCallback));

     Gl->Set(String::NewSymbol("DepthRangef"), FunctionTemplate::New(GLESglDepthRangefCallback));

     Gl->Set(String::NewSymbol("DetachShader"), FunctionTemplate::New(GLESglDetachShaderCallback));

     Gl->Set(String::NewSymbol("Disable"), FunctionTemplate::New(GLESglDisableCallback));

     Gl->Set(String::NewSymbol("DisableVertexAttribArray"), FunctionTemplate::New(GLESglDisableVertexAttribArrayCallback));

     Gl->Set(String::NewSymbol("DrawArrays"), FunctionTemplate::New(GLESglDrawArraysCallback));

     Gl->Set(String::NewSymbol("Enable"), FunctionTemplate::New(GLESglEnableCallback));

     Gl->Set(String::NewSymbol("EnableVertexAttribArray"), FunctionTemplate::New(GLESglEnableVertexAttribArrayCallback));

     Gl->Set(String::NewSymbol("Finish"), FunctionTemplate::New(GLESglFinishCallback));

     Gl->Set(String::NewSymbol("Flush"), FunctionTemplate::New(GLESglFlushCallback));

     Gl->Set(String::NewSymbol("FramebufferRenderbuffer"), FunctionTemplate::New(GLESglFramebufferRenderbufferCallback));

     Gl->Set(String::NewSymbol("FramebufferTexture2D"), FunctionTemplate::New(GLESglFramebufferTexture2DCallback));

     Gl->Set(String::NewSymbol("FrontFace"), FunctionTemplate::New(GLESglFrontFaceCallback));

     Gl->Set(String::NewSymbol("GenBuffers"), FunctionTemplate::New(GLESglGenBuffersCallback));

     Gl->Set(String::NewSymbol("GenerateMipmap"), FunctionTemplate::New(GLESglGenerateMipmapCallback));

     Gl->Set(String::NewSymbol("GenFramebuffers"), FunctionTemplate::New(GLESglGenFramebuffersCallback));

     Gl->Set(String::NewSymbol("GenRenderbuffers"), FunctionTemplate::New(GLESglGenRenderbuffersCallback));

     Gl->Set(String::NewSymbol("GenTextures"), FunctionTemplate::New(GLESglGenTexturesCallback));

     Gl->Set(String::NewSymbol("GetActiveAttrib"), FunctionTemplate::New(GLESglGetActiveAttribCallback));

     Gl->Set(String::NewSymbol("GetActiveUniform"), FunctionTemplate::New(GLESglGetActiveUniformCallback));

     Gl->Set(String::NewSymbol("GetAttachedShaders"), FunctionTemplate::New(GLESglGetAttachedShadersCallback));

     Gl->Set(String::NewSymbol("GetAttribLocation"), FunctionTemplate::New(GLESglGetAttribLocationCallback));

     Gl->Set(String::NewSymbol("GetBooleanv"), FunctionTemplate::New(GLESglGetBooleanvCallback));

     Gl->Set(String::NewSymbol("GetBufferParameteriv"), FunctionTemplate::New(GLESglGetBufferParameterivCallback));

     Gl->Set(String::NewSymbol("GetError"), FunctionTemplate::New(GLESglGetErrorCallback));

     Gl->Set(String::NewSymbol("GetFloatv"), FunctionTemplate::New(GLESglGetFloatvCallback));

     Gl->Set(String::NewSymbol("GetFramebufferAttachmentParameteriv"), FunctionTemplate::New(GLESglGetFramebufferAttachmentParameterivCallback));

     Gl->Set(String::NewSymbol("GetIntegerv"), FunctionTemplate::New(GLESglGetIntegervCallback));

     Gl->Set(String::NewSymbol("GetProgramiv"), FunctionTemplate::New(GLESglGetProgramivCallback));

     Gl->Set(String::NewSymbol("GetProgramInfoLog"), FunctionTemplate::New(GLESglGetProgramInfoLogCallback));

     Gl->Set(String::NewSymbol("GetRenderbufferParameteriv"), FunctionTemplate::New(GLESglGetRenderbufferParameterivCallback));

     Gl->Set(String::NewSymbol("GetShaderiv"), FunctionTemplate::New(GLESglGetShaderivCallback));

     Gl->Set(String::NewSymbol("GetShaderInfoLog"), FunctionTemplate::New(GLESglGetShaderInfoLogCallback));

     Gl->Set(String::NewSymbol("GetShaderSource"), FunctionTemplate::New(GLESglGetShaderSourceCallback));

     Gl->Set(String::NewSymbol("GetTexParameterfv"), FunctionTemplate::New(GLESglGetTexParameterfvCallback));

     Gl->Set(String::NewSymbol("GetTexParameteriv"), FunctionTemplate::New(GLESglGetTexParameterivCallback));

     Gl->Set(String::NewSymbol("GetUniformfv"), FunctionTemplate::New(GLESglGetUniformfvCallback));

     Gl->Set(String::NewSymbol("GetUniformiv"), FunctionTemplate::New(GLESglGetUniformivCallback));

     Gl->Set(String::NewSymbol("GetUniformLocation"), FunctionTemplate::New(GLESglGetUniformLocationCallback));

     Gl->Set(String::NewSymbol("GetVertexAttribfv"), FunctionTemplate::New(GLESglGetVertexAttribfvCallback));

     Gl->Set(String::NewSymbol("GetVertexAttribiv"), FunctionTemplate::New(GLESglGetVertexAttribivCallback));

     Gl->Set(String::NewSymbol("Hint"), FunctionTemplate::New(GLESglHintCallback));

     Gl->Set(String::NewSymbol("IsBuffer"), FunctionTemplate::New(GLESglIsBufferCallback));

     Gl->Set(String::NewSymbol("IsEnabled"), FunctionTemplate::New(GLESglIsEnabledCallback));

     Gl->Set(String::NewSymbol("IsFramebuffer"), FunctionTemplate::New(GLESglIsFramebufferCallback));

     Gl->Set(String::NewSymbol("IsProgram"), FunctionTemplate::New(GLESglIsProgramCallback));

     Gl->Set(String::NewSymbol("IsRenderbuffer"), FunctionTemplate::New(GLESglIsRenderbufferCallback));

     Gl->Set(String::NewSymbol("IsShader"), FunctionTemplate::New(GLESglIsShaderCallback));

     Gl->Set(String::NewSymbol("IsTexture"), FunctionTemplate::New(GLESglIsTextureCallback));

     Gl->Set(String::NewSymbol("LineWidth"), FunctionTemplate::New(GLESglLineWidthCallback));

     Gl->Set(String::NewSymbol("LinkProgram"), FunctionTemplate::New(GLESglLinkProgramCallback));

     Gl->Set(String::NewSymbol("PixelStorei"), FunctionTemplate::New(GLESglPixelStoreiCallback));

     Gl->Set(String::NewSymbol("PolygonOffset"), FunctionTemplate::New(GLESglPolygonOffsetCallback));

     Gl->Set(String::NewSymbol("RenderbufferStorage"), FunctionTemplate::New(GLESglRenderbufferStorageCallback));

     Gl->Set(String::NewSymbol("SampleCoverage"), FunctionTemplate::New(GLESglSampleCoverageCallback));

     Gl->Set(String::NewSymbol("Scissor"), FunctionTemplate::New(GLESglScissorCallback));

     Gl->Set(String::NewSymbol("ShaderSource"), FunctionTemplate::New(GLESglShaderSourceCallback));

     Gl->Set(String::NewSymbol("StencilFunc"), FunctionTemplate::New(GLESglStencilFuncCallback));

     Gl->Set(String::NewSymbol("StencilFuncSeparate"), FunctionTemplate::New(GLESglStencilFuncSeparateCallback));

     Gl->Set(String::NewSymbol("StencilMask"), FunctionTemplate::New(GLESglStencilMaskCallback));

     Gl->Set(String::NewSymbol("StencilMaskSeparate"), FunctionTemplate::New(GLESglStencilMaskSeparateCallback));

     Gl->Set(String::NewSymbol("StencilOp"), FunctionTemplate::New(GLESglStencilOpCallback));

     Gl->Set(String::NewSymbol("StencilOpSeparate"), FunctionTemplate::New(GLESglStencilOpSeparateCallback));

     Gl->Set(String::NewSymbol("TexParameterf"), FunctionTemplate::New(GLESglTexParameterfCallback));

     Gl->Set(String::NewSymbol("TexParameterfv"), FunctionTemplate::New(GLESglTexParameterfvCallback));

     Gl->Set(String::NewSymbol("TexParameteri"), FunctionTemplate::New(GLESglTexParameteriCallback));

     Gl->Set(String::NewSymbol("TexParameteriv"), FunctionTemplate::New(GLESglTexParameterivCallback));

     Gl->Set(String::NewSymbol("Uniform1f"), FunctionTemplate::New(GLESglUniform1fCallback));

     Gl->Set(String::NewSymbol("Uniform1fv"), FunctionTemplate::New(GLESglUniform1fvCallback));

     Gl->Set(String::NewSymbol("Uniform1i"), FunctionTemplate::New(GLESglUniform1iCallback));

     Gl->Set(String::NewSymbol("Uniform1iv"), FunctionTemplate::New(GLESglUniform1ivCallback));

     Gl->Set(String::NewSymbol("Uniform2f"), FunctionTemplate::New(GLESglUniform2fCallback));

     Gl->Set(String::NewSymbol("Uniform2fv"), FunctionTemplate::New(GLESglUniform2fvCallback));

     Gl->Set(String::NewSymbol("Uniform2i"), FunctionTemplate::New(GLESglUniform2iCallback));

     Gl->Set(String::NewSymbol("Uniform2iv"), FunctionTemplate::New(GLESglUniform2ivCallback));

     Gl->Set(String::NewSymbol("Uniform3f"), FunctionTemplate::New(GLESglUniform3fCallback));

     Gl->Set(String::NewSymbol("Uniform3fv"), FunctionTemplate::New(GLESglUniform3fvCallback));

     Gl->Set(String::NewSymbol("Uniform3i"), FunctionTemplate::New(GLESglUniform3iCallback));

     Gl->Set(String::NewSymbol("Uniform3iv"), FunctionTemplate::New(GLESglUniform3ivCallback));

     Gl->Set(String::NewSymbol("Uniform4f"), FunctionTemplate::New(GLESglUniform4fCallback));

     Gl->Set(String::NewSymbol("Uniform4fv"), FunctionTemplate::New(GLESglUniform4fvCallback));

     Gl->Set(String::NewSymbol("Uniform4i"), FunctionTemplate::New(GLESglUniform4iCallback));

     Gl->Set(String::NewSymbol("Uniform4iv"), FunctionTemplate::New(GLESglUniform4ivCallback));

     Gl->Set(String::NewSymbol("UniformMatrix2fv"), FunctionTemplate::New(GLESglUniformMatrix2fvCallback));

     Gl->Set(String::NewSymbol("UniformMatrix3fv"), FunctionTemplate::New(GLESglUniformMatrix3fvCallback));

     Gl->Set(String::NewSymbol("UniformMatrix4fv"), FunctionTemplate::New(GLESglUniformMatrix4fvCallback));

     Gl->Set(String::NewSymbol("UseProgram"), FunctionTemplate::New(GLESglUseProgramCallback));

     Gl->Set(String::NewSymbol("ValidateProgram"), FunctionTemplate::New(GLESglValidateProgramCallback));

     Gl->Set(String::NewSymbol("VertexAttrib1f"), FunctionTemplate::New(GLESglVertexAttrib1fCallback));

     Gl->Set(String::NewSymbol("VertexAttrib1fv"), FunctionTemplate::New(GLESglVertexAttrib1fvCallback));

     Gl->Set(String::NewSymbol("VertexAttrib2f"), FunctionTemplate::New(GLESglVertexAttrib2fCallback));

     Gl->Set(String::NewSymbol("VertexAttrib2fv"), FunctionTemplate::New(GLESglVertexAttrib2fvCallback));

     Gl->Set(String::NewSymbol("VertexAttrib3f"), FunctionTemplate::New(GLESglVertexAttrib3fCallback));

     Gl->Set(String::NewSymbol("VertexAttrib3fv"), FunctionTemplate::New(GLESglVertexAttrib3fvCallback));

     Gl->Set(String::NewSymbol("VertexAttrib4f"), FunctionTemplate::New(GLESglVertexAttrib4fCallback));

     Gl->Set(String::NewSymbol("VertexAttrib4fv"), FunctionTemplate::New(GLESglVertexAttrib4fvCallback));

     Gl->Set(String::NewSymbol("Viewport"), FunctionTemplate::New(GLESglViewportCallback));


      // Again, return the result through the current handle scope.
      return handle_scope.Close(Gl);
}    
