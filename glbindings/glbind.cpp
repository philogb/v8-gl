
#include "glbind.h"

#if defined(V8_GL_USE_GLEW)
#include "GL/glew.h"
#elif defined(__APPLE__)
#include <OpenGL/OpenGL.h>
#else
#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#endif

using namespace v8;

Persistent<Object> GlFactory::self_;


Handle<Value> GLglAccumCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  double arg1 = args[1]->NumberValue();

  //make call
  glAccum((GLenum) arg0, (GLfloat) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglAlphaFuncCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  double arg1 = args[1]->NumberValue();

  //make call
  glAlphaFunc((GLenum) arg0, (GLclampf) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglAreTexturesResidentCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
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
    
    
    
  Handle<Array> arrHandle2 = Handle<Array>::Cast(args[2]);
  GLboolean* arg2 = new GLboolean[arrHandle2->Length()];
  for (unsigned j = 0; j < arrHandle2->Length(); j++) {
      Handle<Value> arg(arrHandle2->Get(Integer::New(j)));
      GLboolean aux = (GLboolean)arg->Uint32Value();
      arg2[j] = aux; 
  }
    
    
  //make call
  return Uint32::New(glAreTexturesResident((GLsizei) arg0, (const GLuint*) arg1, (GLboolean*) arg2));
}




Handle<Value> GLglArrayElementCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  glArrayElement((GLint) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglBeginCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  glBegin((GLenum) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglBindTextureCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  unsigned int arg1 = args[1]->Uint32Value();

  //make call
  glBindTexture((GLenum) arg0, (GLuint) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglBitmapCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 7) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  double arg2 = args[2]->NumberValue();
  double arg3 = args[3]->NumberValue();
  double arg4 = args[4]->NumberValue();
  double arg5 = args[5]->NumberValue();

    
  Handle<Array> arrHandle6 = Handle<Array>::Cast(args[6]);
   GLubyte* arg6 = new  GLubyte[arrHandle6->Length()];
  for (unsigned j = 0; j < arrHandle6->Length(); j++) {
      Handle<Value> arg(arrHandle6->Get(Integer::New(j)));
       GLubyte aux = ( GLubyte)arg->Uint32Value();
      arg6[j] = aux; 
  }
    
    
  //make call
  glBitmap((GLsizei) arg0, (GLsizei) arg1, (GLfloat) arg2, (GLfloat) arg3, (GLfloat) arg4, (GLfloat) arg5, (const GLubyte*) arg6);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglBlendColorCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglBlendEquationCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  glBlendEquation((GLenum) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglBlendEquationSeparateCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();

  //make call
  glBlendEquationSeparate((GLenum) arg0, (GLenum) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglBlendFuncCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();

  //make call
  glBlendFunc((GLenum) arg0, (GLenum) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglCallListCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  glCallList((GLuint) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglClearCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  glClear((GLbitfield) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglClearAccumCallback(const Arguments& args) {
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
  glClearAccum((GLfloat) arg0, (GLfloat) arg1, (GLfloat) arg2, (GLfloat) arg3);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglClearColorCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglClearDepthCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();

  //make call
  glClearDepth((GLclampd) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglClearIndexCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();

  //make call
  glClearIndex((GLfloat) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglClearStencilCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  glClearStencil((GLint) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglClipPlaneCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

    
  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLdouble* arg1 = new  GLdouble[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLdouble aux = ( GLdouble)arg->NumberValue();
      arg1[j] = aux; 
  }
    
    
  //make call
  glClipPlane((GLenum) arg0, (const GLdouble*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglColor3bCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();

  //make call
  glColor3b((GLbyte) arg0, (GLbyte) arg1, (GLbyte) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglColor3bvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLbyte* arg0 = new  GLbyte[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLbyte aux = ( GLbyte)arg->IntegerValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glColor3bv((const GLbyte*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglColor3dCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();
  double arg1 = args[1]->NumberValue();
  double arg2 = args[2]->NumberValue();

  //make call
  glColor3d((GLdouble) arg0, (GLdouble) arg1, (GLdouble) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglColor3dvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLdouble* arg0 = new  GLdouble[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLdouble aux = ( GLdouble)arg->NumberValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glColor3dv((const GLdouble*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglColor3fCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();
  double arg1 = args[1]->NumberValue();
  double arg2 = args[2]->NumberValue();

  //make call
  glColor3f((GLfloat) arg0, (GLfloat) arg1, (GLfloat) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglColor3fvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLfloat* arg0 = new  GLfloat[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLfloat aux = ( GLfloat)arg->NumberValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glColor3fv((const GLfloat*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglColor3iCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();

  //make call
  glColor3i((GLint) arg0, (GLint) arg1, (GLint) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglColor3ivCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLint* arg0 = new  GLint[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLint aux = ( GLint)arg->IntegerValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glColor3iv((const GLint*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglColor3sCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();

  //make call
  glColor3s((GLshort) arg0, (GLshort) arg1, (GLshort) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglColor3svCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLshort* arg0 = new  GLshort[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLshort aux = ( GLshort)arg->IntegerValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glColor3sv((const GLshort*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglColor3ubCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  unsigned int arg1 = args[1]->Uint32Value();
  unsigned int arg2 = args[2]->Uint32Value();

  //make call
  glColor3ub((GLubyte) arg0, (GLubyte) arg1, (GLubyte) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglColor3ubvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLubyte* arg0 = new  GLubyte[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLubyte aux = ( GLubyte)arg->Uint32Value();
      arg0[j] = aux; 
  }
    
    
  //make call
  glColor3ubv((const GLubyte*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglColor3uiCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  unsigned int arg1 = args[1]->Uint32Value();
  unsigned int arg2 = args[2]->Uint32Value();

  //make call
  glColor3ui((GLuint) arg0, (GLuint) arg1, (GLuint) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglColor3uivCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLuint* arg0 = new  GLuint[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLuint aux = ( GLuint)arg->Uint32Value();
      arg0[j] = aux; 
  }
    
    
  //make call
  glColor3uiv((const GLuint*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglColor3usCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  unsigned int arg1 = args[1]->Uint32Value();
  unsigned int arg2 = args[2]->Uint32Value();

  //make call
  glColor3us((GLushort) arg0, (GLushort) arg1, (GLushort) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglColor3usvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLushort* arg0 = new  GLushort[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLushort aux = ( GLushort)arg->Uint32Value();
      arg0[j] = aux; 
  }
    
    
  //make call
  glColor3usv((const GLushort*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglColor4bCallback(const Arguments& args) {
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
  glColor4b((GLbyte) arg0, (GLbyte) arg1, (GLbyte) arg2, (GLbyte) arg3);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglColor4bvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLbyte* arg0 = new  GLbyte[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLbyte aux = ( GLbyte)arg->IntegerValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glColor4bv((const GLbyte*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglColor4dCallback(const Arguments& args) {
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
  glColor4d((GLdouble) arg0, (GLdouble) arg1, (GLdouble) arg2, (GLdouble) arg3);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglColor4dvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLdouble* arg0 = new  GLdouble[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLdouble aux = ( GLdouble)arg->NumberValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glColor4dv((const GLdouble*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglColor4fCallback(const Arguments& args) {
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
  glColor4f((GLfloat) arg0, (GLfloat) arg1, (GLfloat) arg2, (GLfloat) arg3);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglColor4fvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLfloat* arg0 = new  GLfloat[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLfloat aux = ( GLfloat)arg->NumberValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glColor4fv((const GLfloat*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglColor4iCallback(const Arguments& args) {
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
  glColor4i((GLint) arg0, (GLint) arg1, (GLint) arg2, (GLint) arg3);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglColor4ivCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLint* arg0 = new  GLint[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLint aux = ( GLint)arg->IntegerValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glColor4iv((const GLint*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglColor4sCallback(const Arguments& args) {
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
  glColor4s((GLshort) arg0, (GLshort) arg1, (GLshort) arg2, (GLshort) arg3);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglColor4svCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLshort* arg0 = new  GLshort[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLshort aux = ( GLshort)arg->IntegerValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glColor4sv((const GLshort*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglColor4ubCallback(const Arguments& args) {
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
  glColor4ub((GLubyte) arg0, (GLubyte) arg1, (GLubyte) arg2, (GLubyte) arg3);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglColor4ubvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLubyte* arg0 = new  GLubyte[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLubyte aux = ( GLubyte)arg->Uint32Value();
      arg0[j] = aux; 
  }
    
    
  //make call
  glColor4ubv((const GLubyte*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglColor4uiCallback(const Arguments& args) {
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
  glColor4ui((GLuint) arg0, (GLuint) arg1, (GLuint) arg2, (GLuint) arg3);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglColor4uivCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLuint* arg0 = new  GLuint[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLuint aux = ( GLuint)arg->Uint32Value();
      arg0[j] = aux; 
  }
    
    
  //make call
  glColor4uiv((const GLuint*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglColor4usCallback(const Arguments& args) {
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
  glColor4us((GLushort) arg0, (GLushort) arg1, (GLushort) arg2, (GLushort) arg3);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglColor4usvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLushort* arg0 = new  GLushort[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLushort aux = ( GLushort)arg->Uint32Value();
      arg0[j] = aux; 
  }
    
    
  //make call
  glColor4usv((const GLushort*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglColorMaskCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglColorMaterialCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();

  //make call
  glColorMaterial((GLenum) arg0, (GLenum) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglColorTableParameterfvCallback(const Arguments& args) {
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
  glColorTableParameterfv((GLenum) arg0, (GLenum) arg1, (const GLfloat*) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglColorTableParameterivCallback(const Arguments& args) {
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
  glColorTableParameteriv((GLenum) arg0, (GLenum) arg1, (const GLint*) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglConvolutionParameterfCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  double arg2 = args[2]->NumberValue();

  //make call
  glConvolutionParameterf((GLenum) arg0, (GLenum) arg1, (GLfloat) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglConvolutionParameterfvCallback(const Arguments& args) {
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
  glConvolutionParameterfv((GLenum) arg0, (GLenum) arg1, (const GLfloat*) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglConvolutionParameteriCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();

  //make call
  glConvolutionParameteri((GLenum) arg0, (GLenum) arg1, (GLint) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglConvolutionParameterivCallback(const Arguments& args) {
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
  glConvolutionParameteriv((GLenum) arg0, (GLenum) arg1, (const GLint*) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglCopyColorSubTableCallback(const Arguments& args) {
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
  glCopyColorSubTable((GLenum) arg0, (GLsizei) arg1, (GLint) arg2, (GLint) arg3, (GLsizei) arg4);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglCopyColorTableCallback(const Arguments& args) {
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
  glCopyColorTable((GLenum) arg0, (GLenum) arg1, (GLint) arg2, (GLint) arg3, (GLsizei) arg4);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglCopyConvolutionFilter1DCallback(const Arguments& args) {
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
  glCopyConvolutionFilter1D((GLenum) arg0, (GLenum) arg1, (GLint) arg2, (GLint) arg3, (GLsizei) arg4);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglCopyConvolutionFilter2DCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 6) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();
  int arg3 = args[3]->IntegerValue();
  int arg4 = args[4]->IntegerValue();
  int arg5 = args[5]->IntegerValue();

  //make call
  glCopyConvolutionFilter2D((GLenum) arg0, (GLenum) arg1, (GLint) arg2, (GLint) arg3, (GLsizei) arg4, (GLsizei) arg5);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglCopyPixelsCallback(const Arguments& args) {
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
  glCopyPixels((GLint) arg0, (GLint) arg1, (GLsizei) arg2, (GLsizei) arg3, (GLenum) arg4);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglCopyTexImage1DCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 7) return v8::Undefined();
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

  //make call
  glCopyTexImage1D((GLenum) arg0, (GLint) arg1, (GLenum) arg2, (GLint) arg3, (GLint) arg4, (GLsizei) arg5, (GLint) arg6);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglCopyTexImage2DCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglCopyTexSubImage1DCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 6) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();
  int arg3 = args[3]->IntegerValue();
  int arg4 = args[4]->IntegerValue();
  int arg5 = args[5]->IntegerValue();

  //make call
  glCopyTexSubImage1D((GLenum) arg0, (GLint) arg1, (GLint) arg2, (GLint) arg3, (GLint) arg4, (GLsizei) arg5);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglCopyTexSubImage2DCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglCopyTexSubImage3DCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 9) return v8::Undefined();
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
  int arg8 = args[8]->IntegerValue();

  //make call
  glCopyTexSubImage3D((GLenum) arg0, (GLint) arg1, (GLint) arg2, (GLint) arg3, (GLint) arg4, (GLint) arg5, (GLint) arg6, (GLsizei) arg7, (GLsizei) arg8);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglCullFaceCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  glCullFace((GLenum) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglDeleteListsCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  int arg1 = args[1]->IntegerValue();

  //make call
  glDeleteLists((GLuint) arg0, (GLsizei) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglDeleteTexturesCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglDepthFuncCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  glDepthFunc((GLenum) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglDepthMaskCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  glDepthMask((GLboolean) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglDepthRangeCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();
  double arg1 = args[1]->NumberValue();

  //make call
  glDepthRange((GLclampd) arg0, (GLclampd) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglDisableCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  glDisable((GLenum) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglDisableClientStateCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  glDisableClientState((GLenum) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglDrawArraysCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglDrawBufferCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  glDrawBuffer((GLenum) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglEdgeFlagCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  glEdgeFlag((GLboolean) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglEdgeFlagvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLboolean* arg0 = new  GLboolean[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLboolean aux = ( GLboolean)arg->Uint32Value();
      arg0[j] = aux; 
  }
    
    
  //make call
  glEdgeFlagv((const GLboolean*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglEnableCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  glEnable((GLenum) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglEnableClientStateCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  glEnableClientState((GLenum) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglEndCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 0) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

  //make call
  glEnd();
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglEndListCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 0) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

  //make call
  glEndList();
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglEvalCoord1dCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();

  //make call
  glEvalCoord1d((GLdouble) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglEvalCoord1dvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLdouble* arg0 = new  GLdouble[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLdouble aux = ( GLdouble)arg->NumberValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glEvalCoord1dv((const GLdouble*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglEvalCoord1fCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();

  //make call
  glEvalCoord1f((GLfloat) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglEvalCoord1fvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLfloat* arg0 = new  GLfloat[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLfloat aux = ( GLfloat)arg->NumberValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glEvalCoord1fv((const GLfloat*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglEvalCoord2dCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();
  double arg1 = args[1]->NumberValue();

  //make call
  glEvalCoord2d((GLdouble) arg0, (GLdouble) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglEvalCoord2dvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLdouble* arg0 = new  GLdouble[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLdouble aux = ( GLdouble)arg->NumberValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glEvalCoord2dv((const GLdouble*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglEvalCoord2fCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();
  double arg1 = args[1]->NumberValue();

  //make call
  glEvalCoord2f((GLfloat) arg0, (GLfloat) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglEvalCoord2fvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLfloat* arg0 = new  GLfloat[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLfloat aux = ( GLfloat)arg->NumberValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glEvalCoord2fv((const GLfloat*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglEvalMesh1Callback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();

  //make call
  glEvalMesh1((GLenum) arg0, (GLint) arg1, (GLint) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglEvalMesh2Callback(const Arguments& args) {
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
  glEvalMesh2((GLenum) arg0, (GLint) arg1, (GLint) arg2, (GLint) arg3, (GLint) arg4);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglEvalPoint1Callback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  glEvalPoint1((GLint) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglEvalPoint2Callback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();

  //make call
  glEvalPoint2((GLint) arg0, (GLint) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglFeedbackBufferCallback(const Arguments& args) {
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
  glFeedbackBuffer((GLsizei) arg0, (GLenum) arg1, (GLfloat*) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglFinishCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 0) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

  //make call
  glFinish();
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglFlushCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 0) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

  //make call
  glFlush();
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglFogfCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  double arg1 = args[1]->NumberValue();

  //make call
  glFogf((GLenum) arg0, (GLfloat) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglFogfvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

    
  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLfloat* arg1 = new  GLfloat[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLfloat aux = ( GLfloat)arg->NumberValue();
      arg1[j] = aux; 
  }
    
    
  //make call
  glFogfv((GLenum) arg0, (const GLfloat*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglFogiCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();

  //make call
  glFogi((GLenum) arg0, (GLint) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglFogivCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

    
  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLint* arg1 = new  GLint[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLint aux = ( GLint)arg->IntegerValue();
      arg1[j] = aux; 
  }
    
    
  //make call
  glFogiv((GLenum) arg0, (const GLint*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglFrontFaceCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  glFrontFace((GLenum) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglFrustumCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 6) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();
  double arg1 = args[1]->NumberValue();
  double arg2 = args[2]->NumberValue();
  double arg3 = args[3]->NumberValue();
  double arg4 = args[4]->NumberValue();
  double arg5 = args[5]->NumberValue();

  //make call
  glFrustum((GLdouble) arg0, (GLdouble) arg1, (GLdouble) arg2, (GLdouble) arg3, (GLdouble) arg4, (GLdouble) arg5);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglGenListsCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  return Uint32::New(glGenLists((GLsizei) arg0));
}




Handle<Value> GLglGenTexturesCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglGetBooleanvCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglGetClipPlaneCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

    
  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
  GLdouble* arg1 = new GLdouble[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
      GLdouble aux = (GLdouble)arg->NumberValue();
      arg1[j] = aux; 
  }
    
    
  //make call
  glGetClipPlane((GLenum) arg0, (GLdouble*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglGetColorTableParameterfvCallback(const Arguments& args) {
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
  glGetColorTableParameterfv((GLenum) arg0, (GLenum) arg1, (GLfloat*) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglGetColorTableParameterivCallback(const Arguments& args) {
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
  glGetColorTableParameteriv((GLenum) arg0, (GLenum) arg1, (GLint*) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglGetConvolutionParameterfvCallback(const Arguments& args) {
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
  glGetConvolutionParameterfv((GLenum) arg0, (GLenum) arg1, (GLfloat*) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglGetConvolutionParameterivCallback(const Arguments& args) {
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
  glGetConvolutionParameteriv((GLenum) arg0, (GLenum) arg1, (GLint*) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglGetDoublevCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

    
  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
  GLdouble* arg1 = new GLdouble[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
      GLdouble aux = (GLdouble)arg->NumberValue();
      arg1[j] = aux; 
  }
    
    
  //make call
  glGetDoublev((GLenum) arg0, (GLdouble*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglGetErrorCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 0) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

  //make call
  return Integer::New(glGetError());
}




Handle<Value> GLglGetFloatvCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglGetHistogramParameterfvCallback(const Arguments& args) {
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
  glGetHistogramParameterfv((GLenum) arg0, (GLenum) arg1, (GLfloat*) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglGetHistogramParameterivCallback(const Arguments& args) {
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
  glGetHistogramParameteriv((GLenum) arg0, (GLenum) arg1, (GLint*) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglGetIntegervCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglGetLightfvCallback(const Arguments& args) {
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
  glGetLightfv((GLenum) arg0, (GLenum) arg1, (GLfloat*) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglGetLightivCallback(const Arguments& args) {
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
  glGetLightiv((GLenum) arg0, (GLenum) arg1, (GLint*) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglGetMapdvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();

    
  Handle<Array> arrHandle2 = Handle<Array>::Cast(args[2]);
  GLdouble* arg2 = new GLdouble[arrHandle2->Length()];
  for (unsigned j = 0; j < arrHandle2->Length(); j++) {
      Handle<Value> arg(arrHandle2->Get(Integer::New(j)));
      GLdouble aux = (GLdouble)arg->NumberValue();
      arg2[j] = aux; 
  }
    
    
  //make call
  glGetMapdv((GLenum) arg0, (GLenum) arg1, (GLdouble*) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglGetMapfvCallback(const Arguments& args) {
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
  glGetMapfv((GLenum) arg0, (GLenum) arg1, (GLfloat*) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglGetMapivCallback(const Arguments& args) {
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
  glGetMapiv((GLenum) arg0, (GLenum) arg1, (GLint*) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglGetMaterialfvCallback(const Arguments& args) {
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
  glGetMaterialfv((GLenum) arg0, (GLenum) arg1, (GLfloat*) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglGetMaterialivCallback(const Arguments& args) {
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
  glGetMaterialiv((GLenum) arg0, (GLenum) arg1, (GLint*) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglGetMinmaxParameterfvCallback(const Arguments& args) {
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
  glGetMinmaxParameterfv((GLenum) arg0, (GLenum) arg1, (GLfloat*) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglGetMinmaxParameterivCallback(const Arguments& args) {
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
  glGetMinmaxParameteriv((GLenum) arg0, (GLenum) arg1, (GLint*) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglGetPixelMapfvCallback(const Arguments& args) {
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
  glGetPixelMapfv((GLenum) arg0, (GLfloat*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglGetPixelMapuivCallback(const Arguments& args) {
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
  glGetPixelMapuiv((GLenum) arg0, (GLuint*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglGetPixelMapusvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

    
  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
  GLushort* arg1 = new GLushort[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
      GLushort aux = (GLushort)arg->Uint32Value();
      arg1[j] = aux; 
  }
    
    
  //make call
  glGetPixelMapusv((GLenum) arg0, (GLushort*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglGetPolygonStippleCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
  GLubyte* arg0 = new GLubyte[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
      GLubyte aux = (GLubyte)arg->Uint32Value();
      arg0[j] = aux; 
  }
    
    
  //make call
  glGetPolygonStipple((GLubyte*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglGetTexEnvfvCallback(const Arguments& args) {
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
  glGetTexEnvfv((GLenum) arg0, (GLenum) arg1, (GLfloat*) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglGetTexEnvivCallback(const Arguments& args) {
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
  glGetTexEnviv((GLenum) arg0, (GLenum) arg1, (GLint*) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglGetTexGendvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();

    
  Handle<Array> arrHandle2 = Handle<Array>::Cast(args[2]);
  GLdouble* arg2 = new GLdouble[arrHandle2->Length()];
  for (unsigned j = 0; j < arrHandle2->Length(); j++) {
      Handle<Value> arg(arrHandle2->Get(Integer::New(j)));
      GLdouble aux = (GLdouble)arg->NumberValue();
      arg2[j] = aux; 
  }
    
    
  //make call
  glGetTexGendv((GLenum) arg0, (GLenum) arg1, (GLdouble*) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglGetTexGenfvCallback(const Arguments& args) {
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
  glGetTexGenfv((GLenum) arg0, (GLenum) arg1, (GLfloat*) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglGetTexGenivCallback(const Arguments& args) {
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
  glGetTexGeniv((GLenum) arg0, (GLenum) arg1, (GLint*) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglGetTexLevelParameterfvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 4) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();

    
  Handle<Array> arrHandle3 = Handle<Array>::Cast(args[3]);
  GLfloat* arg3 = new GLfloat[arrHandle3->Length()];
  for (unsigned j = 0; j < arrHandle3->Length(); j++) {
      Handle<Value> arg(arrHandle3->Get(Integer::New(j)));
      GLfloat aux = (GLfloat)arg->NumberValue();
      arg3[j] = aux; 
  }
    
    
  //make call
  glGetTexLevelParameterfv((GLenum) arg0, (GLint) arg1, (GLenum) arg2, (GLfloat*) arg3);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglGetTexLevelParameterivCallback(const Arguments& args) {
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
  glGetTexLevelParameteriv((GLenum) arg0, (GLint) arg1, (GLenum) arg2, (GLint*) arg3);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglGetTexParameterfvCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglGetTexParameterivCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglHintCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();

  //make call
  glHint((GLenum) arg0, (GLenum) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglHistogramCallback(const Arguments& args) {
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
  glHistogram((GLenum) arg0, (GLsizei) arg1, (GLenum) arg2, (GLboolean) arg3);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglIndexMaskCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  glIndexMask((GLuint) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglIndexdCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();

  //make call
  glIndexd((GLdouble) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglIndexdvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLdouble* arg0 = new  GLdouble[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLdouble aux = ( GLdouble)arg->NumberValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glIndexdv((const GLdouble*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglIndexfCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();

  //make call
  glIndexf((GLfloat) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglIndexfvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLfloat* arg0 = new  GLfloat[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLfloat aux = ( GLfloat)arg->NumberValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glIndexfv((const GLfloat*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglIndexiCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  glIndexi((GLint) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglIndexivCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLint* arg0 = new  GLint[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLint aux = ( GLint)arg->IntegerValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glIndexiv((const GLint*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglIndexsCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  glIndexs((GLshort) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglIndexsvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLshort* arg0 = new  GLshort[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLshort aux = ( GLshort)arg->IntegerValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glIndexsv((const GLshort*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglIndexubCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  glIndexub((GLubyte) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglIndexubvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLubyte* arg0 = new  GLubyte[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLubyte aux = ( GLubyte)arg->Uint32Value();
      arg0[j] = aux; 
  }
    
    
  //make call
  glIndexubv((const GLubyte*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglInitNamesCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 0) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

  //make call
  glInitNames();
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglIsEnabledCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  return Uint32::New(glIsEnabled((GLenum) arg0));
}




Handle<Value> GLglIsListCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  return Uint32::New(glIsList((GLuint) arg0));
}




Handle<Value> GLglIsTextureCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  return Uint32::New(glIsTexture((GLuint) arg0));
}




Handle<Value> GLglLightModelfCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  double arg1 = args[1]->NumberValue();

  //make call
  glLightModelf((GLenum) arg0, (GLfloat) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglLightModelfvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

    
  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLfloat* arg1 = new  GLfloat[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLfloat aux = ( GLfloat)arg->NumberValue();
      arg1[j] = aux; 
  }
    
    
  //make call
  glLightModelfv((GLenum) arg0, (const GLfloat*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglLightModeliCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();

  //make call
  glLightModeli((GLenum) arg0, (GLint) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglLightModelivCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

    
  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLint* arg1 = new  GLint[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLint aux = ( GLint)arg->IntegerValue();
      arg1[j] = aux; 
  }
    
    
  //make call
  glLightModeliv((GLenum) arg0, (const GLint*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglLightfCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  double arg2 = args[2]->NumberValue();

  //make call
  glLightf((GLenum) arg0, (GLenum) arg1, (GLfloat) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglLightfvCallback(const Arguments& args) {
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
  glLightfv((GLenum) arg0, (GLenum) arg1, (const GLfloat*) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglLightiCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();

  //make call
  glLighti((GLenum) arg0, (GLenum) arg1, (GLint) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglLightivCallback(const Arguments& args) {
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
  glLightiv((GLenum) arg0, (GLenum) arg1, (const GLint*) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglLineStippleCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  unsigned int arg1 = args[1]->Uint32Value();

  //make call
  glLineStipple((GLint) arg0, (GLushort) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglLineWidthCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();

  //make call
  glLineWidth((GLfloat) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglListBaseCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  glListBase((GLuint) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglLoadIdentityCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 0) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

  //make call
  glLoadIdentity();
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglLoadMatrixdCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLdouble* arg0 = new  GLdouble[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLdouble aux = ( GLdouble)arg->NumberValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glLoadMatrixd((const GLdouble*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglLoadMatrixfCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLfloat* arg0 = new  GLfloat[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLfloat aux = ( GLfloat)arg->NumberValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glLoadMatrixf((const GLfloat*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglLoadNameCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  glLoadName((GLuint) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglLogicOpCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  glLogicOp((GLenum) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMap1dCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 6) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  double arg1 = args[1]->NumberValue();
  double arg2 = args[2]->NumberValue();
  int arg3 = args[3]->IntegerValue();
  int arg4 = args[4]->IntegerValue();

    
  Handle<Array> arrHandle5 = Handle<Array>::Cast(args[5]);
   GLdouble* arg5 = new  GLdouble[arrHandle5->Length()];
  for (unsigned j = 0; j < arrHandle5->Length(); j++) {
      Handle<Value> arg(arrHandle5->Get(Integer::New(j)));
       GLdouble aux = ( GLdouble)arg->NumberValue();
      arg5[j] = aux; 
  }
    
    
  //make call
  glMap1d((GLenum) arg0, (GLdouble) arg1, (GLdouble) arg2, (GLint) arg3, (GLint) arg4, (const GLdouble*) arg5);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMap1fCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 6) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  double arg1 = args[1]->NumberValue();
  double arg2 = args[2]->NumberValue();
  int arg3 = args[3]->IntegerValue();
  int arg4 = args[4]->IntegerValue();

    
  Handle<Array> arrHandle5 = Handle<Array>::Cast(args[5]);
   GLfloat* arg5 = new  GLfloat[arrHandle5->Length()];
  for (unsigned j = 0; j < arrHandle5->Length(); j++) {
      Handle<Value> arg(arrHandle5->Get(Integer::New(j)));
       GLfloat aux = ( GLfloat)arg->NumberValue();
      arg5[j] = aux; 
  }
    
    
  //make call
  glMap1f((GLenum) arg0, (GLfloat) arg1, (GLfloat) arg2, (GLint) arg3, (GLint) arg4, (const GLfloat*) arg5);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMap2dCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 10) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  double arg1 = args[1]->NumberValue();
  double arg2 = args[2]->NumberValue();
  int arg3 = args[3]->IntegerValue();
  int arg4 = args[4]->IntegerValue();
  double arg5 = args[5]->NumberValue();
  double arg6 = args[6]->NumberValue();
  int arg7 = args[7]->IntegerValue();
  int arg8 = args[8]->IntegerValue();

    
  Handle<Array> arrHandle9 = Handle<Array>::Cast(args[9]);
   GLdouble* arg9 = new  GLdouble[arrHandle9->Length()];
  for (unsigned j = 0; j < arrHandle9->Length(); j++) {
      Handle<Value> arg(arrHandle9->Get(Integer::New(j)));
       GLdouble aux = ( GLdouble)arg->NumberValue();
      arg9[j] = aux; 
  }
    
    
  //make call
  glMap2d((GLenum) arg0, (GLdouble) arg1, (GLdouble) arg2, (GLint) arg3, (GLint) arg4, (GLdouble) arg5, (GLdouble) arg6, (GLint) arg7, (GLint) arg8, (const GLdouble*) arg9);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMap2fCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 10) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  double arg1 = args[1]->NumberValue();
  double arg2 = args[2]->NumberValue();
  int arg3 = args[3]->IntegerValue();
  int arg4 = args[4]->IntegerValue();
  double arg5 = args[5]->NumberValue();
  double arg6 = args[6]->NumberValue();
  int arg7 = args[7]->IntegerValue();
  int arg8 = args[8]->IntegerValue();

    
  Handle<Array> arrHandle9 = Handle<Array>::Cast(args[9]);
   GLfloat* arg9 = new  GLfloat[arrHandle9->Length()];
  for (unsigned j = 0; j < arrHandle9->Length(); j++) {
      Handle<Value> arg(arrHandle9->Get(Integer::New(j)));
       GLfloat aux = ( GLfloat)arg->NumberValue();
      arg9[j] = aux; 
  }
    
    
  //make call
  glMap2f((GLenum) arg0, (GLfloat) arg1, (GLfloat) arg2, (GLint) arg3, (GLint) arg4, (GLfloat) arg5, (GLfloat) arg6, (GLint) arg7, (GLint) arg8, (const GLfloat*) arg9);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMapGrid1dCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  double arg1 = args[1]->NumberValue();
  double arg2 = args[2]->NumberValue();

  //make call
  glMapGrid1d((GLint) arg0, (GLdouble) arg1, (GLdouble) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMapGrid1fCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  double arg1 = args[1]->NumberValue();
  double arg2 = args[2]->NumberValue();

  //make call
  glMapGrid1f((GLint) arg0, (GLfloat) arg1, (GLfloat) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMapGrid2dCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 6) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  double arg1 = args[1]->NumberValue();
  double arg2 = args[2]->NumberValue();
  int arg3 = args[3]->IntegerValue();
  double arg4 = args[4]->NumberValue();
  double arg5 = args[5]->NumberValue();

  //make call
  glMapGrid2d((GLint) arg0, (GLdouble) arg1, (GLdouble) arg2, (GLint) arg3, (GLdouble) arg4, (GLdouble) arg5);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMapGrid2fCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 6) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  double arg1 = args[1]->NumberValue();
  double arg2 = args[2]->NumberValue();
  int arg3 = args[3]->IntegerValue();
  double arg4 = args[4]->NumberValue();
  double arg5 = args[5]->NumberValue();

  //make call
  glMapGrid2f((GLint) arg0, (GLfloat) arg1, (GLfloat) arg2, (GLint) arg3, (GLfloat) arg4, (GLfloat) arg5);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMaterialfCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  double arg2 = args[2]->NumberValue();

  //make call
  glMaterialf((GLenum) arg0, (GLenum) arg1, (GLfloat) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMaterialfvCallback(const Arguments& args) {
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
  glMaterialfv((GLenum) arg0, (GLenum) arg1, (const GLfloat*) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMaterialiCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();

  //make call
  glMateriali((GLenum) arg0, (GLenum) arg1, (GLint) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMaterialivCallback(const Arguments& args) {
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
  glMaterialiv((GLenum) arg0, (GLenum) arg1, (const GLint*) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMatrixModeCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  glMatrixMode((GLenum) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMinmaxCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  unsigned int arg2 = args[2]->Uint32Value();

  //make call
  glMinmax((GLenum) arg0, (GLenum) arg1, (GLboolean) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMultMatrixdCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLdouble* arg0 = new  GLdouble[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLdouble aux = ( GLdouble)arg->NumberValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glMultMatrixd((const GLdouble*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMultMatrixfCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLfloat* arg0 = new  GLfloat[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLfloat aux = ( GLfloat)arg->NumberValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glMultMatrixf((const GLfloat*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglNewListCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  int arg1 = args[1]->IntegerValue();

  //make call
  glNewList((GLuint) arg0, (GLenum) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglNormal3bCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();

  //make call
  glNormal3b((GLbyte) arg0, (GLbyte) arg1, (GLbyte) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglNormal3bvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLbyte* arg0 = new  GLbyte[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLbyte aux = ( GLbyte)arg->IntegerValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glNormal3bv((const GLbyte*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglNormal3dCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();
  double arg1 = args[1]->NumberValue();
  double arg2 = args[2]->NumberValue();

  //make call
  glNormal3d((GLdouble) arg0, (GLdouble) arg1, (GLdouble) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglNormal3dvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLdouble* arg0 = new  GLdouble[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLdouble aux = ( GLdouble)arg->NumberValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glNormal3dv((const GLdouble*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglNormal3fCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();
  double arg1 = args[1]->NumberValue();
  double arg2 = args[2]->NumberValue();

  //make call
  glNormal3f((GLfloat) arg0, (GLfloat) arg1, (GLfloat) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglNormal3fvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLfloat* arg0 = new  GLfloat[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLfloat aux = ( GLfloat)arg->NumberValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glNormal3fv((const GLfloat*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglNormal3iCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();

  //make call
  glNormal3i((GLint) arg0, (GLint) arg1, (GLint) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglNormal3ivCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLint* arg0 = new  GLint[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLint aux = ( GLint)arg->IntegerValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glNormal3iv((const GLint*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglNormal3sCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();

  //make call
  glNormal3s((GLshort) arg0, (GLshort) arg1, (GLshort) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglNormal3svCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLshort* arg0 = new  GLshort[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLshort aux = ( GLshort)arg->IntegerValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glNormal3sv((const GLshort*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglOrthoCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 6) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();
  double arg1 = args[1]->NumberValue();
  double arg2 = args[2]->NumberValue();
  double arg3 = args[3]->NumberValue();
  double arg4 = args[4]->NumberValue();
  double arg5 = args[5]->NumberValue();

  //make call
  glOrtho((GLdouble) arg0, (GLdouble) arg1, (GLdouble) arg2, (GLdouble) arg3, (GLdouble) arg4, (GLdouble) arg5);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglPassThroughCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();

  //make call
  glPassThrough((GLfloat) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglPixelMapfvCallback(const Arguments& args) {
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
  glPixelMapfv((GLenum) arg0, (GLint) arg1, (const GLfloat*) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglPixelMapuivCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();

    
  Handle<Array> arrHandle2 = Handle<Array>::Cast(args[2]);
   GLuint* arg2 = new  GLuint[arrHandle2->Length()];
  for (unsigned j = 0; j < arrHandle2->Length(); j++) {
      Handle<Value> arg(arrHandle2->Get(Integer::New(j)));
       GLuint aux = ( GLuint)arg->Uint32Value();
      arg2[j] = aux; 
  }
    
    
  //make call
  glPixelMapuiv((GLenum) arg0, (GLint) arg1, (const GLuint*) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglPixelMapusvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();

    
  Handle<Array> arrHandle2 = Handle<Array>::Cast(args[2]);
   GLushort* arg2 = new  GLushort[arrHandle2->Length()];
  for (unsigned j = 0; j < arrHandle2->Length(); j++) {
      Handle<Value> arg(arrHandle2->Get(Integer::New(j)));
       GLushort aux = ( GLushort)arg->Uint32Value();
      arg2[j] = aux; 
  }
    
    
  //make call
  glPixelMapusv((GLenum) arg0, (GLint) arg1, (const GLushort*) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglPixelStorefCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  double arg1 = args[1]->NumberValue();

  //make call
  glPixelStoref((GLenum) arg0, (GLfloat) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglPixelStoreiCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();

  //make call
  glPixelStorei((GLenum) arg0, (GLint) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglPixelTransferfCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  double arg1 = args[1]->NumberValue();

  //make call
  glPixelTransferf((GLenum) arg0, (GLfloat) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglPixelTransferiCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();

  //make call
  glPixelTransferi((GLenum) arg0, (GLint) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglPixelZoomCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();
  double arg1 = args[1]->NumberValue();

  //make call
  glPixelZoom((GLfloat) arg0, (GLfloat) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglPointSizeCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();

  //make call
  glPointSize((GLfloat) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglPolygonModeCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();

  //make call
  glPolygonMode((GLenum) arg0, (GLenum) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglPolygonOffsetCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();
  double arg1 = args[1]->NumberValue();

  //make call
  glPolygonOffset((GLfloat) arg0, (GLfloat) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglPolygonStippleCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLubyte* arg0 = new  GLubyte[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLubyte aux = ( GLubyte)arg->Uint32Value();
      arg0[j] = aux; 
  }
    
    
  //make call
  glPolygonStipple((const GLubyte*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglPopAttribCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 0) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

  //make call
  glPopAttrib();
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglPopClientAttribCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 0) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

  //make call
  glPopClientAttrib();
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglPopMatrixCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 0) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

  //make call
  glPopMatrix();
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglPopNameCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 0) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

  //make call
  glPopName();
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglPrioritizeTexturesCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
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
    
    
    
  Handle<Array> arrHandle2 = Handle<Array>::Cast(args[2]);
   GLclampf* arg2 = new  GLclampf[arrHandle2->Length()];
  for (unsigned j = 0; j < arrHandle2->Length(); j++) {
      Handle<Value> arg(arrHandle2->Get(Integer::New(j)));
       GLclampf aux = ( GLclampf)arg->NumberValue();
      arg2[j] = aux; 
  }
    
    
  //make call
  glPrioritizeTextures((GLsizei) arg0, (const GLuint*) arg1, (const GLclampf*) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglPushAttribCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  glPushAttrib((GLbitfield) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglPushClientAttribCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  glPushClientAttrib((GLbitfield) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglPushMatrixCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 0) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

  //make call
  glPushMatrix();
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglPushNameCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  glPushName((GLuint) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglRasterPos2dCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();
  double arg1 = args[1]->NumberValue();

  //make call
  glRasterPos2d((GLdouble) arg0, (GLdouble) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglRasterPos2dvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLdouble* arg0 = new  GLdouble[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLdouble aux = ( GLdouble)arg->NumberValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glRasterPos2dv((const GLdouble*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglRasterPos2fCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();
  double arg1 = args[1]->NumberValue();

  //make call
  glRasterPos2f((GLfloat) arg0, (GLfloat) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglRasterPos2fvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLfloat* arg0 = new  GLfloat[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLfloat aux = ( GLfloat)arg->NumberValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glRasterPos2fv((const GLfloat*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglRasterPos2iCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();

  //make call
  glRasterPos2i((GLint) arg0, (GLint) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglRasterPos2ivCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLint* arg0 = new  GLint[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLint aux = ( GLint)arg->IntegerValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glRasterPos2iv((const GLint*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglRasterPos2sCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();

  //make call
  glRasterPos2s((GLshort) arg0, (GLshort) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglRasterPos2svCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLshort* arg0 = new  GLshort[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLshort aux = ( GLshort)arg->IntegerValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glRasterPos2sv((const GLshort*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglRasterPos3dCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();
  double arg1 = args[1]->NumberValue();
  double arg2 = args[2]->NumberValue();

  //make call
  glRasterPos3d((GLdouble) arg0, (GLdouble) arg1, (GLdouble) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglRasterPos3dvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLdouble* arg0 = new  GLdouble[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLdouble aux = ( GLdouble)arg->NumberValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glRasterPos3dv((const GLdouble*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglRasterPos3fCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();
  double arg1 = args[1]->NumberValue();
  double arg2 = args[2]->NumberValue();

  //make call
  glRasterPos3f((GLfloat) arg0, (GLfloat) arg1, (GLfloat) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglRasterPos3fvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLfloat* arg0 = new  GLfloat[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLfloat aux = ( GLfloat)arg->NumberValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glRasterPos3fv((const GLfloat*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglRasterPos3iCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();

  //make call
  glRasterPos3i((GLint) arg0, (GLint) arg1, (GLint) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglRasterPos3ivCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLint* arg0 = new  GLint[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLint aux = ( GLint)arg->IntegerValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glRasterPos3iv((const GLint*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglRasterPos3sCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();

  //make call
  glRasterPos3s((GLshort) arg0, (GLshort) arg1, (GLshort) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglRasterPos3svCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLshort* arg0 = new  GLshort[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLshort aux = ( GLshort)arg->IntegerValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glRasterPos3sv((const GLshort*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglRasterPos4dCallback(const Arguments& args) {
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
  glRasterPos4d((GLdouble) arg0, (GLdouble) arg1, (GLdouble) arg2, (GLdouble) arg3);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglRasterPos4dvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLdouble* arg0 = new  GLdouble[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLdouble aux = ( GLdouble)arg->NumberValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glRasterPos4dv((const GLdouble*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglRasterPos4fCallback(const Arguments& args) {
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
  glRasterPos4f((GLfloat) arg0, (GLfloat) arg1, (GLfloat) arg2, (GLfloat) arg3);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglRasterPos4fvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLfloat* arg0 = new  GLfloat[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLfloat aux = ( GLfloat)arg->NumberValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glRasterPos4fv((const GLfloat*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglRasterPos4iCallback(const Arguments& args) {
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
  glRasterPos4i((GLint) arg0, (GLint) arg1, (GLint) arg2, (GLint) arg3);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglRasterPos4ivCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLint* arg0 = new  GLint[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLint aux = ( GLint)arg->IntegerValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glRasterPos4iv((const GLint*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglRasterPos4sCallback(const Arguments& args) {
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
  glRasterPos4s((GLshort) arg0, (GLshort) arg1, (GLshort) arg2, (GLshort) arg3);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglRasterPos4svCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLshort* arg0 = new  GLshort[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLshort aux = ( GLshort)arg->IntegerValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glRasterPos4sv((const GLshort*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglReadBufferCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  glReadBuffer((GLenum) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglRectdCallback(const Arguments& args) {
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
  glRectd((GLdouble) arg0, (GLdouble) arg1, (GLdouble) arg2, (GLdouble) arg3);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglRectdvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLdouble* arg0 = new  GLdouble[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLdouble aux = ( GLdouble)arg->NumberValue();
      arg0[j] = aux; 
  }
    
    
    
  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLdouble* arg1 = new  GLdouble[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLdouble aux = ( GLdouble)arg->NumberValue();
      arg1[j] = aux; 
  }
    
    
  //make call
  glRectdv((const GLdouble*) arg0, (const GLdouble*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglRectfCallback(const Arguments& args) {
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
  glRectf((GLfloat) arg0, (GLfloat) arg1, (GLfloat) arg2, (GLfloat) arg3);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglRectfvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLfloat* arg0 = new  GLfloat[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLfloat aux = ( GLfloat)arg->NumberValue();
      arg0[j] = aux; 
  }
    
    
    
  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLfloat* arg1 = new  GLfloat[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLfloat aux = ( GLfloat)arg->NumberValue();
      arg1[j] = aux; 
  }
    
    
  //make call
  glRectfv((const GLfloat*) arg0, (const GLfloat*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglRectiCallback(const Arguments& args) {
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
  glRecti((GLint) arg0, (GLint) arg1, (GLint) arg2, (GLint) arg3);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglRectivCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLint* arg0 = new  GLint[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLint aux = ( GLint)arg->IntegerValue();
      arg0[j] = aux; 
  }
    
    
    
  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLint* arg1 = new  GLint[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLint aux = ( GLint)arg->IntegerValue();
      arg1[j] = aux; 
  }
    
    
  //make call
  glRectiv((const GLint*) arg0, (const GLint*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglRectsCallback(const Arguments& args) {
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
  glRects((GLshort) arg0, (GLshort) arg1, (GLshort) arg2, (GLshort) arg3);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglRectsvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLshort* arg0 = new  GLshort[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLshort aux = ( GLshort)arg->IntegerValue();
      arg0[j] = aux; 
  }
    
    
    
  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLshort* arg1 = new  GLshort[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLshort aux = ( GLshort)arg->IntegerValue();
      arg1[j] = aux; 
  }
    
    
  //make call
  glRectsv((const GLshort*) arg0, (const GLshort*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglRenderModeCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  return Integer::New(glRenderMode((GLenum) arg0));
}




Handle<Value> GLglResetHistogramCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  glResetHistogram((GLenum) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglResetMinmaxCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  glResetMinmax((GLenum) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglRotatedCallback(const Arguments& args) {
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
  glRotated((GLdouble) arg0, (GLdouble) arg1, (GLdouble) arg2, (GLdouble) arg3);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglRotatefCallback(const Arguments& args) {
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
  glRotatef((GLfloat) arg0, (GLfloat) arg1, (GLfloat) arg2, (GLfloat) arg3);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglScaledCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();
  double arg1 = args[1]->NumberValue();
  double arg2 = args[2]->NumberValue();

  //make call
  glScaled((GLdouble) arg0, (GLdouble) arg1, (GLdouble) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglScalefCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();
  double arg1 = args[1]->NumberValue();
  double arg2 = args[2]->NumberValue();

  //make call
  glScalef((GLfloat) arg0, (GLfloat) arg1, (GLfloat) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglScissorCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglSelectBufferCallback(const Arguments& args) {
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
  glSelectBuffer((GLsizei) arg0, (GLuint*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglShadeModelCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  glShadeModel((GLenum) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglStencilFuncCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglStencilMaskCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  glStencilMask((GLuint) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglStencilOpCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglTexCoord1dCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();

  //make call
  glTexCoord1d((GLdouble) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglTexCoord1dvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLdouble* arg0 = new  GLdouble[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLdouble aux = ( GLdouble)arg->NumberValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glTexCoord1dv((const GLdouble*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglTexCoord1fCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();

  //make call
  glTexCoord1f((GLfloat) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglTexCoord1fvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLfloat* arg0 = new  GLfloat[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLfloat aux = ( GLfloat)arg->NumberValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glTexCoord1fv((const GLfloat*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglTexCoord1iCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  glTexCoord1i((GLint) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglTexCoord1ivCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLint* arg0 = new  GLint[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLint aux = ( GLint)arg->IntegerValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glTexCoord1iv((const GLint*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglTexCoord1sCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  glTexCoord1s((GLshort) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglTexCoord1svCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLshort* arg0 = new  GLshort[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLshort aux = ( GLshort)arg->IntegerValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glTexCoord1sv((const GLshort*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglTexCoord2dCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();
  double arg1 = args[1]->NumberValue();

  //make call
  glTexCoord2d((GLdouble) arg0, (GLdouble) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglTexCoord2dvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLdouble* arg0 = new  GLdouble[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLdouble aux = ( GLdouble)arg->NumberValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glTexCoord2dv((const GLdouble*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglTexCoord2fCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();
  double arg1 = args[1]->NumberValue();

  //make call
  glTexCoord2f((GLfloat) arg0, (GLfloat) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglTexCoord2fvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLfloat* arg0 = new  GLfloat[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLfloat aux = ( GLfloat)arg->NumberValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glTexCoord2fv((const GLfloat*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglTexCoord2iCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();

  //make call
  glTexCoord2i((GLint) arg0, (GLint) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglTexCoord2ivCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLint* arg0 = new  GLint[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLint aux = ( GLint)arg->IntegerValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glTexCoord2iv((const GLint*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglTexCoord2sCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();

  //make call
  glTexCoord2s((GLshort) arg0, (GLshort) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglTexCoord2svCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLshort* arg0 = new  GLshort[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLshort aux = ( GLshort)arg->IntegerValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glTexCoord2sv((const GLshort*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglTexCoord3dCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();
  double arg1 = args[1]->NumberValue();
  double arg2 = args[2]->NumberValue();

  //make call
  glTexCoord3d((GLdouble) arg0, (GLdouble) arg1, (GLdouble) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglTexCoord3dvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLdouble* arg0 = new  GLdouble[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLdouble aux = ( GLdouble)arg->NumberValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glTexCoord3dv((const GLdouble*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglTexCoord3fCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();
  double arg1 = args[1]->NumberValue();
  double arg2 = args[2]->NumberValue();

  //make call
  glTexCoord3f((GLfloat) arg0, (GLfloat) arg1, (GLfloat) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglTexCoord3fvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLfloat* arg0 = new  GLfloat[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLfloat aux = ( GLfloat)arg->NumberValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glTexCoord3fv((const GLfloat*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglTexCoord3iCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();

  //make call
  glTexCoord3i((GLint) arg0, (GLint) arg1, (GLint) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglTexCoord3ivCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLint* arg0 = new  GLint[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLint aux = ( GLint)arg->IntegerValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glTexCoord3iv((const GLint*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglTexCoord3sCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();

  //make call
  glTexCoord3s((GLshort) arg0, (GLshort) arg1, (GLshort) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglTexCoord3svCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLshort* arg0 = new  GLshort[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLshort aux = ( GLshort)arg->IntegerValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glTexCoord3sv((const GLshort*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglTexCoord4dCallback(const Arguments& args) {
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
  glTexCoord4d((GLdouble) arg0, (GLdouble) arg1, (GLdouble) arg2, (GLdouble) arg3);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglTexCoord4dvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLdouble* arg0 = new  GLdouble[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLdouble aux = ( GLdouble)arg->NumberValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glTexCoord4dv((const GLdouble*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglTexCoord4fCallback(const Arguments& args) {
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
  glTexCoord4f((GLfloat) arg0, (GLfloat) arg1, (GLfloat) arg2, (GLfloat) arg3);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglTexCoord4fvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLfloat* arg0 = new  GLfloat[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLfloat aux = ( GLfloat)arg->NumberValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glTexCoord4fv((const GLfloat*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglTexCoord4iCallback(const Arguments& args) {
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
  glTexCoord4i((GLint) arg0, (GLint) arg1, (GLint) arg2, (GLint) arg3);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglTexCoord4ivCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLint* arg0 = new  GLint[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLint aux = ( GLint)arg->IntegerValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glTexCoord4iv((const GLint*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglTexCoord4sCallback(const Arguments& args) {
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
  glTexCoord4s((GLshort) arg0, (GLshort) arg1, (GLshort) arg2, (GLshort) arg3);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglTexCoord4svCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLshort* arg0 = new  GLshort[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLshort aux = ( GLshort)arg->IntegerValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glTexCoord4sv((const GLshort*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglTexEnvfCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  double arg2 = args[2]->NumberValue();

  //make call
  glTexEnvf((GLenum) arg0, (GLenum) arg1, (GLfloat) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglTexEnvfvCallback(const Arguments& args) {
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
  glTexEnvfv((GLenum) arg0, (GLenum) arg1, (const GLfloat*) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglTexEnviCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();

  //make call
  glTexEnvi((GLenum) arg0, (GLenum) arg1, (GLint) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglTexEnvivCallback(const Arguments& args) {
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
  glTexEnviv((GLenum) arg0, (GLenum) arg1, (const GLint*) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglTexGendCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  double arg2 = args[2]->NumberValue();

  //make call
  glTexGend((GLenum) arg0, (GLenum) arg1, (GLdouble) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglTexGendvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();

    
  Handle<Array> arrHandle2 = Handle<Array>::Cast(args[2]);
   GLdouble* arg2 = new  GLdouble[arrHandle2->Length()];
  for (unsigned j = 0; j < arrHandle2->Length(); j++) {
      Handle<Value> arg(arrHandle2->Get(Integer::New(j)));
       GLdouble aux = ( GLdouble)arg->NumberValue();
      arg2[j] = aux; 
  }
    
    
  //make call
  glTexGendv((GLenum) arg0, (GLenum) arg1, (const GLdouble*) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglTexGenfCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  double arg2 = args[2]->NumberValue();

  //make call
  glTexGenf((GLenum) arg0, (GLenum) arg1, (GLfloat) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglTexGenfvCallback(const Arguments& args) {
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
  glTexGenfv((GLenum) arg0, (GLenum) arg1, (const GLfloat*) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglTexGeniCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();

  //make call
  glTexGeni((GLenum) arg0, (GLenum) arg1, (GLint) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglTexGenivCallback(const Arguments& args) {
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
  glTexGeniv((GLenum) arg0, (GLenum) arg1, (const GLint*) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglTexParameterfCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglTexParameterfvCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglTexParameteriCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglTexParameterivCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglTranslatedCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();
  double arg1 = args[1]->NumberValue();
  double arg2 = args[2]->NumberValue();

  //make call
  glTranslated((GLdouble) arg0, (GLdouble) arg1, (GLdouble) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglTranslatefCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();
  double arg1 = args[1]->NumberValue();
  double arg2 = args[2]->NumberValue();

  //make call
  glTranslatef((GLfloat) arg0, (GLfloat) arg1, (GLfloat) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertex2dCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();
  double arg1 = args[1]->NumberValue();

  //make call
  glVertex2d((GLdouble) arg0, (GLdouble) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertex2dvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLdouble* arg0 = new  GLdouble[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLdouble aux = ( GLdouble)arg->NumberValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glVertex2dv((const GLdouble*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertex2fCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();
  double arg1 = args[1]->NumberValue();

  //make call
  glVertex2f((GLfloat) arg0, (GLfloat) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertex2fvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLfloat* arg0 = new  GLfloat[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLfloat aux = ( GLfloat)arg->NumberValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glVertex2fv((const GLfloat*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertex2iCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();

  //make call
  glVertex2i((GLint) arg0, (GLint) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertex2ivCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLint* arg0 = new  GLint[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLint aux = ( GLint)arg->IntegerValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glVertex2iv((const GLint*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertex2sCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();

  //make call
  glVertex2s((GLshort) arg0, (GLshort) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertex2svCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLshort* arg0 = new  GLshort[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLshort aux = ( GLshort)arg->IntegerValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glVertex2sv((const GLshort*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertex3dCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();
  double arg1 = args[1]->NumberValue();
  double arg2 = args[2]->NumberValue();

  //make call
  glVertex3d((GLdouble) arg0, (GLdouble) arg1, (GLdouble) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertex3dvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLdouble* arg0 = new  GLdouble[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLdouble aux = ( GLdouble)arg->NumberValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glVertex3dv((const GLdouble*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertex3fCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();
  double arg1 = args[1]->NumberValue();
  double arg2 = args[2]->NumberValue();

  //make call
  glVertex3f((GLfloat) arg0, (GLfloat) arg1, (GLfloat) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertex3fvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLfloat* arg0 = new  GLfloat[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLfloat aux = ( GLfloat)arg->NumberValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glVertex3fv((const GLfloat*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertex3iCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();

  //make call
  glVertex3i((GLint) arg0, (GLint) arg1, (GLint) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertex3ivCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLint* arg0 = new  GLint[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLint aux = ( GLint)arg->IntegerValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glVertex3iv((const GLint*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertex3sCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();

  //make call
  glVertex3s((GLshort) arg0, (GLshort) arg1, (GLshort) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertex3svCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLshort* arg0 = new  GLshort[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLshort aux = ( GLshort)arg->IntegerValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glVertex3sv((const GLshort*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertex4dCallback(const Arguments& args) {
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
  glVertex4d((GLdouble) arg0, (GLdouble) arg1, (GLdouble) arg2, (GLdouble) arg3);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertex4dvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLdouble* arg0 = new  GLdouble[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLdouble aux = ( GLdouble)arg->NumberValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glVertex4dv((const GLdouble*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertex4fCallback(const Arguments& args) {
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
  glVertex4f((GLfloat) arg0, (GLfloat) arg1, (GLfloat) arg2, (GLfloat) arg3);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertex4fvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLfloat* arg0 = new  GLfloat[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLfloat aux = ( GLfloat)arg->NumberValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glVertex4fv((const GLfloat*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertex4iCallback(const Arguments& args) {
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
  glVertex4i((GLint) arg0, (GLint) arg1, (GLint) arg2, (GLint) arg3);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertex4ivCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLint* arg0 = new  GLint[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLint aux = ( GLint)arg->IntegerValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glVertex4iv((const GLint*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertex4sCallback(const Arguments& args) {
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
  glVertex4s((GLshort) arg0, (GLshort) arg1, (GLshort) arg2, (GLshort) arg3);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertex4svCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLshort* arg0 = new  GLshort[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLshort aux = ( GLshort)arg->IntegerValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glVertex4sv((const GLshort*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglViewportCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglSampleCoverageCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();
  unsigned int arg1 = args[1]->Uint32Value();

  //make call
  glSampleCoverage((GLclampf) arg0, (GLboolean) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglLoadTransposeMatrixfCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLfloat* arg0 = new  GLfloat[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLfloat aux = ( GLfloat)arg->NumberValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glLoadTransposeMatrixf((const GLfloat*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglLoadTransposeMatrixdCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLdouble* arg0 = new  GLdouble[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLdouble aux = ( GLdouble)arg->NumberValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glLoadTransposeMatrixd((const GLdouble*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMultTransposeMatrixfCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLfloat* arg0 = new  GLfloat[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLfloat aux = ( GLfloat)arg->NumberValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glMultTransposeMatrixf((const GLfloat*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMultTransposeMatrixdCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLdouble* arg0 = new  GLdouble[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLdouble aux = ( GLdouble)arg->NumberValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glMultTransposeMatrixd((const GLdouble*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglActiveTextureCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  glActiveTexture((GLenum) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglClientActiveTextureCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  glClientActiveTexture((GLenum) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMultiTexCoord1dCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  double arg1 = args[1]->NumberValue();

  //make call
  glMultiTexCoord1d((GLenum) arg0, (GLdouble) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMultiTexCoord1dvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

    
  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLdouble* arg1 = new  GLdouble[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLdouble aux = ( GLdouble)arg->NumberValue();
      arg1[j] = aux; 
  }
    
    
  //make call
  glMultiTexCoord1dv((GLenum) arg0, (const GLdouble*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMultiTexCoord1fCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  double arg1 = args[1]->NumberValue();

  //make call
  glMultiTexCoord1f((GLenum) arg0, (GLfloat) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMultiTexCoord1fvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

    
  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLfloat* arg1 = new  GLfloat[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLfloat aux = ( GLfloat)arg->NumberValue();
      arg1[j] = aux; 
  }
    
    
  //make call
  glMultiTexCoord1fv((GLenum) arg0, (const GLfloat*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMultiTexCoord1iCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();

  //make call
  glMultiTexCoord1i((GLenum) arg0, (GLint) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMultiTexCoord1ivCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

    
  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLint* arg1 = new  GLint[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLint aux = ( GLint)arg->IntegerValue();
      arg1[j] = aux; 
  }
    
    
  //make call
  glMultiTexCoord1iv((GLenum) arg0, (const GLint*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMultiTexCoord1sCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();

  //make call
  glMultiTexCoord1s((GLenum) arg0, (GLshort) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMultiTexCoord1svCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

    
  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLshort* arg1 = new  GLshort[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLshort aux = ( GLshort)arg->IntegerValue();
      arg1[j] = aux; 
  }
    
    
  //make call
  glMultiTexCoord1sv((GLenum) arg0, (const GLshort*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMultiTexCoord2dCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  double arg1 = args[1]->NumberValue();
  double arg2 = args[2]->NumberValue();

  //make call
  glMultiTexCoord2d((GLenum) arg0, (GLdouble) arg1, (GLdouble) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMultiTexCoord2dvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

    
  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLdouble* arg1 = new  GLdouble[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLdouble aux = ( GLdouble)arg->NumberValue();
      arg1[j] = aux; 
  }
    
    
  //make call
  glMultiTexCoord2dv((GLenum) arg0, (const GLdouble*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMultiTexCoord2fCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  double arg1 = args[1]->NumberValue();
  double arg2 = args[2]->NumberValue();

  //make call
  glMultiTexCoord2f((GLenum) arg0, (GLfloat) arg1, (GLfloat) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMultiTexCoord2fvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

    
  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLfloat* arg1 = new  GLfloat[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLfloat aux = ( GLfloat)arg->NumberValue();
      arg1[j] = aux; 
  }
    
    
  //make call
  glMultiTexCoord2fv((GLenum) arg0, (const GLfloat*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMultiTexCoord2iCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();

  //make call
  glMultiTexCoord2i((GLenum) arg0, (GLint) arg1, (GLint) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMultiTexCoord2ivCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

    
  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLint* arg1 = new  GLint[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLint aux = ( GLint)arg->IntegerValue();
      arg1[j] = aux; 
  }
    
    
  //make call
  glMultiTexCoord2iv((GLenum) arg0, (const GLint*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMultiTexCoord2sCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();

  //make call
  glMultiTexCoord2s((GLenum) arg0, (GLshort) arg1, (GLshort) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMultiTexCoord2svCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

    
  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLshort* arg1 = new  GLshort[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLshort aux = ( GLshort)arg->IntegerValue();
      arg1[j] = aux; 
  }
    
    
  //make call
  glMultiTexCoord2sv((GLenum) arg0, (const GLshort*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMultiTexCoord3dCallback(const Arguments& args) {
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
  glMultiTexCoord3d((GLenum) arg0, (GLdouble) arg1, (GLdouble) arg2, (GLdouble) arg3);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMultiTexCoord3dvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

    
  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLdouble* arg1 = new  GLdouble[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLdouble aux = ( GLdouble)arg->NumberValue();
      arg1[j] = aux; 
  }
    
    
  //make call
  glMultiTexCoord3dv((GLenum) arg0, (const GLdouble*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMultiTexCoord3fCallback(const Arguments& args) {
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
  glMultiTexCoord3f((GLenum) arg0, (GLfloat) arg1, (GLfloat) arg2, (GLfloat) arg3);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMultiTexCoord3fvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

    
  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLfloat* arg1 = new  GLfloat[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLfloat aux = ( GLfloat)arg->NumberValue();
      arg1[j] = aux; 
  }
    
    
  //make call
  glMultiTexCoord3fv((GLenum) arg0, (const GLfloat*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMultiTexCoord3iCallback(const Arguments& args) {
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
  glMultiTexCoord3i((GLenum) arg0, (GLint) arg1, (GLint) arg2, (GLint) arg3);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMultiTexCoord3ivCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

    
  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLint* arg1 = new  GLint[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLint aux = ( GLint)arg->IntegerValue();
      arg1[j] = aux; 
  }
    
    
  //make call
  glMultiTexCoord3iv((GLenum) arg0, (const GLint*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMultiTexCoord3sCallback(const Arguments& args) {
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
  glMultiTexCoord3s((GLenum) arg0, (GLshort) arg1, (GLshort) arg2, (GLshort) arg3);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMultiTexCoord3svCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

    
  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLshort* arg1 = new  GLshort[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLshort aux = ( GLshort)arg->IntegerValue();
      arg1[j] = aux; 
  }
    
    
  //make call
  glMultiTexCoord3sv((GLenum) arg0, (const GLshort*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMultiTexCoord4dCallback(const Arguments& args) {
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
  glMultiTexCoord4d((GLenum) arg0, (GLdouble) arg1, (GLdouble) arg2, (GLdouble) arg3, (GLdouble) arg4);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMultiTexCoord4dvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

    
  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLdouble* arg1 = new  GLdouble[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLdouble aux = ( GLdouble)arg->NumberValue();
      arg1[j] = aux; 
  }
    
    
  //make call
  glMultiTexCoord4dv((GLenum) arg0, (const GLdouble*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMultiTexCoord4fCallback(const Arguments& args) {
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
  glMultiTexCoord4f((GLenum) arg0, (GLfloat) arg1, (GLfloat) arg2, (GLfloat) arg3, (GLfloat) arg4);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMultiTexCoord4fvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

    
  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLfloat* arg1 = new  GLfloat[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLfloat aux = ( GLfloat)arg->NumberValue();
      arg1[j] = aux; 
  }
    
    
  //make call
  glMultiTexCoord4fv((GLenum) arg0, (const GLfloat*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMultiTexCoord4ivCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

    
  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLint* arg1 = new  GLint[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLint aux = ( GLint)arg->IntegerValue();
      arg1[j] = aux; 
  }
    
    
  //make call
  glMultiTexCoord4iv((GLenum) arg0, (const GLint*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMultiTexCoord4sCallback(const Arguments& args) {
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
  glMultiTexCoord4s((GLenum) arg0, (GLshort) arg1, (GLshort) arg2, (GLshort) arg3, (GLshort) arg4);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMultiTexCoord4svCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

    
  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLshort* arg1 = new  GLshort[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLshort aux = ( GLshort)arg->IntegerValue();
      arg1[j] = aux; 
  }
    
    
  //make call
  glMultiTexCoord4sv((GLenum) arg0, (const GLshort*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglFogCoordfCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();

  //make call
  glFogCoordf((GLfloat) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglFogCoordfvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLfloat* arg0 = new  GLfloat[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLfloat aux = ( GLfloat)arg->NumberValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glFogCoordfv((const GLfloat*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglFogCoorddCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();

  //make call
  glFogCoordd((GLdouble) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglSecondaryColor3bCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();

  //make call
  glSecondaryColor3b((GLbyte) arg0, (GLbyte) arg1, (GLbyte) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglSecondaryColor3bvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLbyte* arg0 = new  GLbyte[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLbyte aux = ( GLbyte)arg->IntegerValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glSecondaryColor3bv((const GLbyte*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglSecondaryColor3dCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();
  double arg1 = args[1]->NumberValue();
  double arg2 = args[2]->NumberValue();

  //make call
  glSecondaryColor3d((GLdouble) arg0, (GLdouble) arg1, (GLdouble) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglSecondaryColor3dvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLdouble* arg0 = new  GLdouble[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLdouble aux = ( GLdouble)arg->NumberValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glSecondaryColor3dv((const GLdouble*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglSecondaryColor3fCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();
  double arg1 = args[1]->NumberValue();
  double arg2 = args[2]->NumberValue();

  //make call
  glSecondaryColor3f((GLfloat) arg0, (GLfloat) arg1, (GLfloat) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglSecondaryColor3fvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLfloat* arg0 = new  GLfloat[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLfloat aux = ( GLfloat)arg->NumberValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glSecondaryColor3fv((const GLfloat*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglSecondaryColor3iCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();

  //make call
  glSecondaryColor3i((GLint) arg0, (GLint) arg1, (GLint) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglSecondaryColor3ivCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLint* arg0 = new  GLint[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLint aux = ( GLint)arg->IntegerValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glSecondaryColor3iv((const GLint*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglSecondaryColor3sCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();

  //make call
  glSecondaryColor3s((GLshort) arg0, (GLshort) arg1, (GLshort) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglSecondaryColor3svCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLshort* arg0 = new  GLshort[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLshort aux = ( GLshort)arg->IntegerValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glSecondaryColor3sv((const GLshort*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglSecondaryColor3ubCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  unsigned int arg1 = args[1]->Uint32Value();
  unsigned int arg2 = args[2]->Uint32Value();

  //make call
  glSecondaryColor3ub((GLubyte) arg0, (GLubyte) arg1, (GLubyte) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglSecondaryColor3ubvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLubyte* arg0 = new  GLubyte[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLubyte aux = ( GLubyte)arg->Uint32Value();
      arg0[j] = aux; 
  }
    
    
  //make call
  glSecondaryColor3ubv((const GLubyte*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglSecondaryColor3uiCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  unsigned int arg1 = args[1]->Uint32Value();
  unsigned int arg2 = args[2]->Uint32Value();

  //make call
  glSecondaryColor3ui((GLuint) arg0, (GLuint) arg1, (GLuint) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglSecondaryColor3uivCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLuint* arg0 = new  GLuint[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLuint aux = ( GLuint)arg->Uint32Value();
      arg0[j] = aux; 
  }
    
    
  //make call
  glSecondaryColor3uiv((const GLuint*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglSecondaryColor3usCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  unsigned int arg1 = args[1]->Uint32Value();
  unsigned int arg2 = args[2]->Uint32Value();

  //make call
  glSecondaryColor3us((GLushort) arg0, (GLushort) arg1, (GLushort) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglSecondaryColor3usvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLushort* arg0 = new  GLushort[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLushort aux = ( GLushort)arg->Uint32Value();
      arg0[j] = aux; 
  }
    
    
  //make call
  glSecondaryColor3usv((const GLushort*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglPointParameterfCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  double arg1 = args[1]->NumberValue();

  //make call
  glPointParameterf((GLenum) arg0, (GLfloat) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglPointParameterfvCallback(const Arguments& args) {
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
  glPointParameterfv((GLenum) arg0, (GLfloat*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglPointParameteriCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();

  //make call
  glPointParameteri((GLenum) arg0, (GLint) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglPointParameterivCallback(const Arguments& args) {
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
  glPointParameteriv((GLenum) arg0, (GLint*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglBlendFuncSeparateCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglMultiDrawArraysCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 4) return v8::Undefined();
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
    
    
    
  Handle<Array> arrHandle2 = Handle<Array>::Cast(args[2]);
  GLsizei* arg2 = new GLsizei[arrHandle2->Length()];
  for (unsigned j = 0; j < arrHandle2->Length(); j++) {
      Handle<Value> arg(arrHandle2->Get(Integer::New(j)));
      GLsizei aux = (GLsizei)arg->IntegerValue();
      arg2[j] = aux; 
  }
    
      int arg3 = args[3]->IntegerValue();

  //make call
  glMultiDrawArrays((GLenum) arg0, (GLint*) arg1, (GLsizei*) arg2, (GLsizei) arg3);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglWindowPos2dCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();
  double arg1 = args[1]->NumberValue();

  //make call
  glWindowPos2d((GLdouble) arg0, (GLdouble) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglWindowPos2dvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLdouble* arg0 = new  GLdouble[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLdouble aux = ( GLdouble)arg->NumberValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glWindowPos2dv((const GLdouble*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglWindowPos2fCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();
  double arg1 = args[1]->NumberValue();

  //make call
  glWindowPos2f((GLfloat) arg0, (GLfloat) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglWindowPos2fvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLfloat* arg0 = new  GLfloat[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLfloat aux = ( GLfloat)arg->NumberValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glWindowPos2fv((const GLfloat*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglWindowPos2iCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();

  //make call
  glWindowPos2i((GLint) arg0, (GLint) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglWindowPos2ivCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLint* arg0 = new  GLint[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLint aux = ( GLint)arg->IntegerValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glWindowPos2iv((const GLint*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglWindowPos2sCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();

  //make call
  glWindowPos2s((GLshort) arg0, (GLshort) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglWindowPos2svCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLshort* arg0 = new  GLshort[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLshort aux = ( GLshort)arg->IntegerValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glWindowPos2sv((const GLshort*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglWindowPos3dCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();
  double arg1 = args[1]->NumberValue();
  double arg2 = args[2]->NumberValue();

  //make call
  glWindowPos3d((GLdouble) arg0, (GLdouble) arg1, (GLdouble) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglWindowPos3dvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLdouble* arg0 = new  GLdouble[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLdouble aux = ( GLdouble)arg->NumberValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glWindowPos3dv((const GLdouble*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglWindowPos3fCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  double arg0 = args[0]->NumberValue();
  double arg1 = args[1]->NumberValue();
  double arg2 = args[2]->NumberValue();

  //make call
  glWindowPos3f((GLfloat) arg0, (GLfloat) arg1, (GLfloat) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglWindowPos3fvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLfloat* arg0 = new  GLfloat[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLfloat aux = ( GLfloat)arg->NumberValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glWindowPos3fv((const GLfloat*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglWindowPos3iCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();

  //make call
  glWindowPos3i((GLint) arg0, (GLint) arg1, (GLint) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglWindowPos3ivCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLint* arg0 = new  GLint[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLint aux = ( GLint)arg->IntegerValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glWindowPos3iv((const GLint*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglWindowPos3sCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();

  //make call
  glWindowPos3s((GLshort) arg0, (GLshort) arg1, (GLshort) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglWindowPos3svCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

    
  Handle<Array> arrHandle0 = Handle<Array>::Cast(args[0]);
   GLshort* arg0 = new  GLshort[arrHandle0->Length()];
  for (unsigned j = 0; j < arrHandle0->Length(); j++) {
      Handle<Value> arg(arrHandle0->Get(Integer::New(j)));
       GLshort aux = ( GLshort)arg->IntegerValue();
      arg0[j] = aux; 
  }
    
    
  //make call
  glWindowPos3sv((const GLshort*) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglGenQueriesCallback(const Arguments& args) {
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
  glGenQueries((GLsizei) arg0, (GLuint*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglDeleteQueriesCallback(const Arguments& args) {
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
  glDeleteQueries((GLsizei) arg0, (const GLuint*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglIsQueryCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  return Uint32::New(glIsQuery((GLuint) arg0));
}




Handle<Value> GLglBeginQueryCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  unsigned int arg1 = args[1]->Uint32Value();

  //make call
  glBeginQuery((GLenum) arg0, (GLuint) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglEndQueryCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  glEndQuery((GLenum) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglGetQueryivCallback(const Arguments& args) {
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
  glGetQueryiv((GLenum) arg0, (GLenum) arg1, (GLint*) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglGetQueryObjectivCallback(const Arguments& args) {
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
  glGetQueryObjectiv((GLuint) arg0, (GLenum) arg1, (GLint*) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglGetQueryObjectuivCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  int arg1 = args[1]->IntegerValue();

    
  Handle<Array> arrHandle2 = Handle<Array>::Cast(args[2]);
  GLuint* arg2 = new GLuint[arrHandle2->Length()];
  for (unsigned j = 0; j < arrHandle2->Length(); j++) {
      Handle<Value> arg(arrHandle2->Get(Integer::New(j)));
      GLuint aux = (GLuint)arg->Uint32Value();
      arg2[j] = aux; 
  }
    
    
  //make call
  glGetQueryObjectuiv((GLuint) arg0, (GLenum) arg1, (GLuint*) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglBindBufferCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  unsigned int arg1 = args[1]->Uint32Value();

  //make call
  glBindBuffer((GLenum) arg0, (GLuint) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglDeleteBuffersCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglGenBuffersCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglIsBufferCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  return Uint32::New(glIsBuffer((GLuint) arg0));
}




Handle<Value> GLglUnmapBufferCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  return Uint32::New(glUnmapBuffer((GLenum) arg0));
}




Handle<Value> GLglGetBufferParameterivCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglDrawBuffersCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

    
  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLenum* arg1 = new  GLenum[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLenum aux = ( GLenum)arg->IntegerValue();
      arg1[j] = aux; 
  }
    
    
  //make call
  glDrawBuffers((GLsizei) arg0, (const GLenum*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertexAttrib1dCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  double arg1 = args[1]->NumberValue();

  //make call
  glVertexAttrib1d((GLuint) arg0, (GLdouble) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertexAttrib1dvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

    
  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLdouble* arg1 = new  GLdouble[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLdouble aux = ( GLdouble)arg->NumberValue();
      arg1[j] = aux; 
  }
    
    
  //make call
  glVertexAttrib1dv((GLuint) arg0, (const GLdouble*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertexAttrib1fCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  double arg1 = args[1]->NumberValue();

  //make call
  glVertexAttrib1f((GLuint) arg0, (GLfloat) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertexAttrib1fvCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertexAttrib1sCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  int arg1 = args[1]->IntegerValue();

  //make call
  glVertexAttrib1s((GLuint) arg0, (GLshort) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertexAttrib1svCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

    
  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLshort* arg1 = new  GLshort[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLshort aux = ( GLshort)arg->IntegerValue();
      arg1[j] = aux; 
  }
    
    
  //make call
  glVertexAttrib1sv((GLuint) arg0, (const GLshort*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertexAttrib2dCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  double arg1 = args[1]->NumberValue();
  double arg2 = args[2]->NumberValue();

  //make call
  glVertexAttrib2d((GLuint) arg0, (GLdouble) arg1, (GLdouble) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertexAttrib2dvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

    
  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLdouble* arg1 = new  GLdouble[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLdouble aux = ( GLdouble)arg->NumberValue();
      arg1[j] = aux; 
  }
    
    
  //make call
  glVertexAttrib2dv((GLuint) arg0, (const GLdouble*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertexAttrib2fCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertexAttrib2fvCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertexAttrib2sCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();

  //make call
  glVertexAttrib2s((GLuint) arg0, (GLshort) arg1, (GLshort) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertexAttrib2svCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

    
  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLshort* arg1 = new  GLshort[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLshort aux = ( GLshort)arg->IntegerValue();
      arg1[j] = aux; 
  }
    
    
  //make call
  glVertexAttrib2sv((GLuint) arg0, (const GLshort*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertexAttrib3dCallback(const Arguments& args) {
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
  glVertexAttrib3d((GLuint) arg0, (GLdouble) arg1, (GLdouble) arg2, (GLdouble) arg3);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertexAttrib3dvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

    
  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLdouble* arg1 = new  GLdouble[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLdouble aux = ( GLdouble)arg->NumberValue();
      arg1[j] = aux; 
  }
    
    
  //make call
  glVertexAttrib3dv((GLuint) arg0, (const GLdouble*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertexAttrib3fCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertexAttrib3fvCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertexAttrib3sCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 4) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();
  int arg3 = args[3]->IntegerValue();

  //make call
  glVertexAttrib3s((GLuint) arg0, (GLshort) arg1, (GLshort) arg2, (GLshort) arg3);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertexAttrib3svCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

    
  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLshort* arg1 = new  GLshort[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLshort aux = ( GLshort)arg->IntegerValue();
      arg1[j] = aux; 
  }
    
    
  //make call
  glVertexAttrib3sv((GLuint) arg0, (const GLshort*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertexAttrib4NbvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

    
  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLbyte* arg1 = new  GLbyte[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLbyte aux = ( GLbyte)arg->IntegerValue();
      arg1[j] = aux; 
  }
    
    
  //make call
  glVertexAttrib4Nbv((GLuint) arg0, (const GLbyte*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertexAttrib4NivCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

    
  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLint* arg1 = new  GLint[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLint aux = ( GLint)arg->IntegerValue();
      arg1[j] = aux; 
  }
    
    
  //make call
  glVertexAttrib4Niv((GLuint) arg0, (const GLint*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertexAttrib4NsvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

    
  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLshort* arg1 = new  GLshort[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLshort aux = ( GLshort)arg->IntegerValue();
      arg1[j] = aux; 
  }
    
    
  //make call
  glVertexAttrib4Nsv((GLuint) arg0, (const GLshort*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertexAttrib4NubCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 5) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  unsigned int arg1 = args[1]->Uint32Value();
  unsigned int arg2 = args[2]->Uint32Value();
  unsigned int arg3 = args[3]->Uint32Value();
  unsigned int arg4 = args[4]->Uint32Value();

  //make call
  glVertexAttrib4Nub((GLuint) arg0, (GLubyte) arg1, (GLubyte) arg2, (GLubyte) arg3, (GLubyte) arg4);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertexAttrib4NubvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

    
  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLubyte* arg1 = new  GLubyte[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLubyte aux = ( GLubyte)arg->Uint32Value();
      arg1[j] = aux; 
  }
    
    
  //make call
  glVertexAttrib4Nubv((GLuint) arg0, (const GLubyte*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertexAttrib4NuivCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

    
  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLuint* arg1 = new  GLuint[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLuint aux = ( GLuint)arg->Uint32Value();
      arg1[j] = aux; 
  }
    
    
  //make call
  glVertexAttrib4Nuiv((GLuint) arg0, (const GLuint*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertexAttrib4NusvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

    
  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLushort* arg1 = new  GLushort[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLushort aux = ( GLushort)arg->Uint32Value();
      arg1[j] = aux; 
  }
    
    
  //make call
  glVertexAttrib4Nusv((GLuint) arg0, (const GLushort*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertexAttrib4bvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

    
  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLbyte* arg1 = new  GLbyte[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLbyte aux = ( GLbyte)arg->IntegerValue();
      arg1[j] = aux; 
  }
    
    
  //make call
  glVertexAttrib4bv((GLuint) arg0, (const GLbyte*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertexAttrib4dCallback(const Arguments& args) {
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
  glVertexAttrib4d((GLuint) arg0, (GLdouble) arg1, (GLdouble) arg2, (GLdouble) arg3, (GLdouble) arg4);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertexAttrib4dvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

    
  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLdouble* arg1 = new  GLdouble[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLdouble aux = ( GLdouble)arg->NumberValue();
      arg1[j] = aux; 
  }
    
    
  //make call
  glVertexAttrib4dv((GLuint) arg0, (const GLdouble*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertexAttrib4fCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertexAttrib4fvCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertexAttrib4ivCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

    
  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLint* arg1 = new  GLint[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLint aux = ( GLint)arg->IntegerValue();
      arg1[j] = aux; 
  }
    
    
  //make call
  glVertexAttrib4iv((GLuint) arg0, (const GLint*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertexAttrib4sCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 5) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  int arg1 = args[1]->IntegerValue();
  int arg2 = args[2]->IntegerValue();
  int arg3 = args[3]->IntegerValue();
  int arg4 = args[4]->IntegerValue();

  //make call
  glVertexAttrib4s((GLuint) arg0, (GLshort) arg1, (GLshort) arg2, (GLshort) arg3, (GLshort) arg4);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertexAttrib4svCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

    
  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLshort* arg1 = new  GLshort[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLshort aux = ( GLshort)arg->IntegerValue();
      arg1[j] = aux; 
  }
    
    
  //make call
  glVertexAttrib4sv((GLuint) arg0, (const GLshort*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertexAttrib4ubvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

    
  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLubyte* arg1 = new  GLubyte[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLubyte aux = ( GLubyte)arg->Uint32Value();
      arg1[j] = aux; 
  }
    
    
  //make call
  glVertexAttrib4ubv((GLuint) arg0, (const GLubyte*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertexAttrib4uivCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

    
  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLuint* arg1 = new  GLuint[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLuint aux = ( GLuint)arg->Uint32Value();
      arg1[j] = aux; 
  }
    
    
  //make call
  glVertexAttrib4uiv((GLuint) arg0, (const GLuint*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglVertexAttrib4usvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

    
  Handle<Array> arrHandle1 = Handle<Array>::Cast(args[1]);
   GLushort* arg1 = new  GLushort[arrHandle1->Length()];
  for (unsigned j = 0; j < arrHandle1->Length(); j++) {
      Handle<Value> arg(arrHandle1->Get(Integer::New(j)));
       GLushort aux = ( GLushort)arg->Uint32Value();
      arg1[j] = aux; 
  }
    
    
  //make call
  glVertexAttrib4usv((GLuint) arg0, (const GLushort*) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglEnableVertexAttribArrayCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  glEnableVertexAttribArray((GLuint) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglDisableVertexAttribArrayCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  glDisableVertexAttribArray((GLuint) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglGetVertexAttribdvCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 3) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  int arg1 = args[1]->IntegerValue();

    
  Handle<Array> arrHandle2 = Handle<Array>::Cast(args[2]);
  GLdouble* arg2 = new GLdouble[arrHandle2->Length()];
  for (unsigned j = 0; j < arrHandle2->Length(); j++) {
      Handle<Value> arg(arrHandle2->Get(Integer::New(j)));
      GLdouble aux = (GLdouble)arg->NumberValue();
      arg2[j] = aux; 
  }
    
    
  //make call
  glGetVertexAttribdv((GLuint) arg0, (GLenum) arg1, (GLdouble*) arg2);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglGetVertexAttribfvCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglGetVertexAttribivCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglDeleteShaderCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  glDeleteShader((GLuint) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglDetachShaderCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  unsigned int arg1 = args[1]->Uint32Value();

  //make call
  glDetachShader((GLuint) arg0, (GLuint) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglCreateShaderCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();

  //make call
  return Uint32::New(glCreateShader((GLenum) arg0));
}




Handle<Value> GLglCompileShaderCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  glCompileShader((GLuint) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglCreateProgramCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 0) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments

  //make call
  return Uint32::New(glCreateProgram());
}




Handle<Value> GLglAttachShaderCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();
  unsigned int arg1 = args[1]->Uint32Value();

  //make call
  glAttachShader((GLuint) arg0, (GLuint) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglLinkProgramCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  glLinkProgram((GLuint) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglUseProgramCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  glUseProgram((GLuint) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglDeleteProgramCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  glDeleteProgram((GLuint) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglValidateProgramCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  glValidateProgram((GLuint) arg0);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglUniform1fCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  double arg1 = args[1]->NumberValue();

  //make call
  glUniform1f((GLint) arg0, (GLfloat) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglUniform2fCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglUniform3fCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglUniform4fCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglUniform1iCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  int arg1 = args[1]->IntegerValue();

  //make call
  glUniform1i((GLint) arg0, (GLint) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglUniform2iCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglUniform3iCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglUniform4iCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglUniform1fvCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglUniform2fvCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglUniform3fvCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglUniform4fvCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglUniform1ivCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglUniform2ivCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglUniform3ivCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglUniform4ivCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglUniformMatrix2fvCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglUniformMatrix3fvCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglUniformMatrix4fvCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglIsShaderCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  return Uint32::New(glIsShader((GLuint) arg0));
}




Handle<Value> GLglIsProgramCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  unsigned int arg0 = args[0]->Uint32Value();

  //make call
  return Uint32::New(glIsProgram((GLuint) arg0));
}




Handle<Value> GLglGetShaderivCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglGetProgramivCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglGetAttachedShadersCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglGetUniformfvCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglGetUniformivCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglStencilFuncSeparateCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglStencilOpSeparateCallback(const Arguments& args) {
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
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglStencilMaskSeparateCallback(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 2) return v8::Undefined();
  //define handle scope
  HandleScope handle_scope;
  //get arguments
  int arg0 = args[0]->IntegerValue();
  unsigned int arg1 = args[1]->Uint32Value();

  //make call
  glStencilMaskSeparate((GLenum) arg0, (GLuint) arg1);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglUniformMatrix2x3fvCallback(const Arguments& args) {
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
  glUniformMatrix2x3fv((GLint) arg0, (GLsizei) arg1, (GLboolean) arg2, (const GLfloat*) arg3);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglUniformMatrix3x2fvCallback(const Arguments& args) {
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
  glUniformMatrix3x2fv((GLint) arg0, (GLsizei) arg1, (GLboolean) arg2, (const GLfloat*) arg3);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglUniformMatrix2x4fvCallback(const Arguments& args) {
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
  glUniformMatrix2x4fv((GLint) arg0, (GLsizei) arg1, (GLboolean) arg2, (const GLfloat*) arg3);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglUniformMatrix4x2fvCallback(const Arguments& args) {
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
  glUniformMatrix4x2fv((GLint) arg0, (GLsizei) arg1, (GLboolean) arg2, (const GLfloat*) arg3);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglUniformMatrix3x4fvCallback(const Arguments& args) {
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
  glUniformMatrix3x4fv((GLint) arg0, (GLsizei) arg1, (GLboolean) arg2, (const GLfloat*) arg3);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<Value> GLglUniformMatrix4x3fvCallback(const Arguments& args) {
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
  glUniformMatrix4x3fv((GLint) arg0, (GLsizei) arg1, (GLboolean) arg2, (const GLfloat*) arg3);
  Handle<Object> res(GlFactory::self_);
  return res;
}




Handle<ObjectTemplate> GlFactory::createGl(void) {
      HandleScope handle_scope;

      Handle<ObjectTemplate> Gl = ObjectTemplate::New();
      
      Gl->SetInternalFieldCount(1);

     Gl->Set(String::NewSymbol("LOGIC_OP"), Uint32::New(GL_LOGIC_OP), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_COMPONENTS"), Uint32::New(GL_TEXTURE_COMPONENTS), ReadOnly);

     Gl->Set(String::NewSymbol("VERSION_1_1"), Uint32::New(GL_VERSION_1_1), ReadOnly);

     Gl->Set(String::NewSymbol("VERSION_1_2"), Uint32::New(GL_VERSION_1_2), ReadOnly);

     Gl->Set(String::NewSymbol("VERSION_1_3"), Uint32::New(GL_VERSION_1_3), ReadOnly);

     Gl->Set(String::NewSymbol("VERSION_1_4"), Uint32::New(GL_VERSION_1_4), ReadOnly);

     Gl->Set(String::NewSymbol("VERSION_1_5"), Uint32::New(GL_VERSION_1_5), ReadOnly);

     Gl->Set(String::NewSymbol("VERSION_2_0"), Uint32::New(GL_VERSION_2_0), ReadOnly);

     Gl->Set(String::NewSymbol("VERSION_2_1"), Uint32::New(GL_VERSION_2_1), ReadOnly);

     Gl->Set(String::NewSymbol("ACCUM"), Uint32::New(GL_ACCUM), ReadOnly);

     Gl->Set(String::NewSymbol("LOAD"), Uint32::New(GL_LOAD), ReadOnly);

     Gl->Set(String::NewSymbol("RETURN"), Uint32::New(GL_RETURN), ReadOnly);

     Gl->Set(String::NewSymbol("MULT"), Uint32::New(GL_MULT), ReadOnly);

     Gl->Set(String::NewSymbol("ADD"), Uint32::New(GL_ADD), ReadOnly);

     Gl->Set(String::NewSymbol("NEVER"), Uint32::New(GL_NEVER), ReadOnly);

     Gl->Set(String::NewSymbol("LESS"), Uint32::New(GL_LESS), ReadOnly);

     Gl->Set(String::NewSymbol("EQUAL"), Uint32::New(GL_EQUAL), ReadOnly);

     Gl->Set(String::NewSymbol("LEQUAL"), Uint32::New(GL_LEQUAL), ReadOnly);

     Gl->Set(String::NewSymbol("GREATER"), Uint32::New(GL_GREATER), ReadOnly);

     Gl->Set(String::NewSymbol("NOTEQUAL"), Uint32::New(GL_NOTEQUAL), ReadOnly);

     Gl->Set(String::NewSymbol("GEQUAL"), Uint32::New(GL_GEQUAL), ReadOnly);

     Gl->Set(String::NewSymbol("ALWAYS"), Uint32::New(GL_ALWAYS), ReadOnly);

     Gl->Set(String::NewSymbol("CURRENT_BIT"), Uint32::New(GL_CURRENT_BIT), ReadOnly);

     Gl->Set(String::NewSymbol("POINT_BIT"), Uint32::New(GL_POINT_BIT), ReadOnly);

     Gl->Set(String::NewSymbol("LINE_BIT"), Uint32::New(GL_LINE_BIT), ReadOnly);

     Gl->Set(String::NewSymbol("POLYGON_BIT"), Uint32::New(GL_POLYGON_BIT), ReadOnly);

     Gl->Set(String::NewSymbol("POLYGON_STIPPLE_BIT"), Uint32::New(GL_POLYGON_STIPPLE_BIT), ReadOnly);

     Gl->Set(String::NewSymbol("PIXEL_MODE_BIT"), Uint32::New(GL_PIXEL_MODE_BIT), ReadOnly);

     Gl->Set(String::NewSymbol("LIGHTING_BIT"), Uint32::New(GL_LIGHTING_BIT), ReadOnly);

     Gl->Set(String::NewSymbol("FOG_BIT"), Uint32::New(GL_FOG_BIT), ReadOnly);

     Gl->Set(String::NewSymbol("DEPTH_BUFFER_BIT"), Uint32::New(GL_DEPTH_BUFFER_BIT), ReadOnly);

     Gl->Set(String::NewSymbol("ACCUM_BUFFER_BIT"), Uint32::New(GL_ACCUM_BUFFER_BIT), ReadOnly);

     Gl->Set(String::NewSymbol("STENCIL_BUFFER_BIT"), Uint32::New(GL_STENCIL_BUFFER_BIT), ReadOnly);

     Gl->Set(String::NewSymbol("VIEWPORT_BIT"), Uint32::New(GL_VIEWPORT_BIT), ReadOnly);

     Gl->Set(String::NewSymbol("TRANSFORM_BIT"), Uint32::New(GL_TRANSFORM_BIT), ReadOnly);

     Gl->Set(String::NewSymbol("ENABLE_BIT"), Uint32::New(GL_ENABLE_BIT), ReadOnly);

     Gl->Set(String::NewSymbol("COLOR_BUFFER_BIT"), Uint32::New(GL_COLOR_BUFFER_BIT), ReadOnly);

     Gl->Set(String::NewSymbol("HINT_BIT"), Uint32::New(GL_HINT_BIT), ReadOnly);

     Gl->Set(String::NewSymbol("EVAL_BIT"), Uint32::New(GL_EVAL_BIT), ReadOnly);

     Gl->Set(String::NewSymbol("LIST_BIT"), Uint32::New(GL_LIST_BIT), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_BIT"), Uint32::New(GL_TEXTURE_BIT), ReadOnly);

     Gl->Set(String::NewSymbol("SCISSOR_BIT"), Uint32::New(GL_SCISSOR_BIT), ReadOnly);

     Gl->Set(String::NewSymbol("ALL_ATTRIB_BITS"), Uint32::New(GL_ALL_ATTRIB_BITS), ReadOnly);

     Gl->Set(String::NewSymbol("POINTS"), Uint32::New(GL_POINTS), ReadOnly);

     Gl->Set(String::NewSymbol("LINES"), Uint32::New(GL_LINES), ReadOnly);

     Gl->Set(String::NewSymbol("LINE_LOOP"), Uint32::New(GL_LINE_LOOP), ReadOnly);

     Gl->Set(String::NewSymbol("LINE_STRIP"), Uint32::New(GL_LINE_STRIP), ReadOnly);

     Gl->Set(String::NewSymbol("TRIANGLES"), Uint32::New(GL_TRIANGLES), ReadOnly);

     Gl->Set(String::NewSymbol("TRIANGLE_STRIP"), Uint32::New(GL_TRIANGLE_STRIP), ReadOnly);

     Gl->Set(String::NewSymbol("TRIANGLE_FAN"), Uint32::New(GL_TRIANGLE_FAN), ReadOnly);

     Gl->Set(String::NewSymbol("QUADS"), Uint32::New(GL_QUADS), ReadOnly);

     Gl->Set(String::NewSymbol("QUAD_STRIP"), Uint32::New(GL_QUAD_STRIP), ReadOnly);

     Gl->Set(String::NewSymbol("POLYGON"), Uint32::New(GL_POLYGON), ReadOnly);

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

     Gl->Set(String::NewSymbol("TRUE"), Uint32::New(GL_TRUE), ReadOnly);

     Gl->Set(String::NewSymbol("FALSE"), Uint32::New(GL_FALSE), ReadOnly);

     Gl->Set(String::NewSymbol("CLIP_PLANE0"), Uint32::New(GL_CLIP_PLANE0), ReadOnly);

     Gl->Set(String::NewSymbol("CLIP_PLANE1"), Uint32::New(GL_CLIP_PLANE1), ReadOnly);

     Gl->Set(String::NewSymbol("CLIP_PLANE2"), Uint32::New(GL_CLIP_PLANE2), ReadOnly);

     Gl->Set(String::NewSymbol("CLIP_PLANE3"), Uint32::New(GL_CLIP_PLANE3), ReadOnly);

     Gl->Set(String::NewSymbol("CLIP_PLANE4"), Uint32::New(GL_CLIP_PLANE4), ReadOnly);

     Gl->Set(String::NewSymbol("CLIP_PLANE5"), Uint32::New(GL_CLIP_PLANE5), ReadOnly);

     Gl->Set(String::NewSymbol("BYTE"), Uint32::New(GL_BYTE), ReadOnly);

     Gl->Set(String::NewSymbol("UNSIGNED_BYTE"), Uint32::New(GL_UNSIGNED_BYTE), ReadOnly);

     Gl->Set(String::NewSymbol("SHORT"), Uint32::New(GL_SHORT), ReadOnly);

     Gl->Set(String::NewSymbol("UNSIGNED_SHORT"), Uint32::New(GL_UNSIGNED_SHORT), ReadOnly);

     Gl->Set(String::NewSymbol("INT"), Uint32::New(GL_INT), ReadOnly);

     Gl->Set(String::NewSymbol("UNSIGNED_INT"), Uint32::New(GL_UNSIGNED_INT), ReadOnly);

     Gl->Set(String::NewSymbol("FLOAT"), Uint32::New(GL_FLOAT), ReadOnly);

     Gl->Set(String::NewSymbol("2_BYTES"), Uint32::New(GL_2_BYTES), ReadOnly);

     Gl->Set(String::NewSymbol("3_BYTES"), Uint32::New(GL_3_BYTES), ReadOnly);

     Gl->Set(String::NewSymbol("4_BYTES"), Uint32::New(GL_4_BYTES), ReadOnly);

     Gl->Set(String::NewSymbol("DOUBLE"), Uint32::New(GL_DOUBLE), ReadOnly);

     Gl->Set(String::NewSymbol("NONE"), Uint32::New(GL_NONE), ReadOnly);

     Gl->Set(String::NewSymbol("FRONT_LEFT"), Uint32::New(GL_FRONT_LEFT), ReadOnly);

     Gl->Set(String::NewSymbol("FRONT_RIGHT"), Uint32::New(GL_FRONT_RIGHT), ReadOnly);

     Gl->Set(String::NewSymbol("BACK_LEFT"), Uint32::New(GL_BACK_LEFT), ReadOnly);

     Gl->Set(String::NewSymbol("BACK_RIGHT"), Uint32::New(GL_BACK_RIGHT), ReadOnly);

     Gl->Set(String::NewSymbol("FRONT"), Uint32::New(GL_FRONT), ReadOnly);

     Gl->Set(String::NewSymbol("BACK"), Uint32::New(GL_BACK), ReadOnly);

     Gl->Set(String::NewSymbol("LEFT"), Uint32::New(GL_LEFT), ReadOnly);

     Gl->Set(String::NewSymbol("RIGHT"), Uint32::New(GL_RIGHT), ReadOnly);

     Gl->Set(String::NewSymbol("FRONT_AND_BACK"), Uint32::New(GL_FRONT_AND_BACK), ReadOnly);

     Gl->Set(String::NewSymbol("AUX0"), Uint32::New(GL_AUX0), ReadOnly);

     Gl->Set(String::NewSymbol("AUX1"), Uint32::New(GL_AUX1), ReadOnly);

     Gl->Set(String::NewSymbol("AUX2"), Uint32::New(GL_AUX2), ReadOnly);

     Gl->Set(String::NewSymbol("AUX3"), Uint32::New(GL_AUX3), ReadOnly);

     Gl->Set(String::NewSymbol("NO_ERROR"), Uint32::New(GL_NO_ERROR), ReadOnly);

     Gl->Set(String::NewSymbol("INVALID_ENUM"), Uint32::New(GL_INVALID_ENUM), ReadOnly);

     Gl->Set(String::NewSymbol("INVALID_VALUE"), Uint32::New(GL_INVALID_VALUE), ReadOnly);

     Gl->Set(String::NewSymbol("STACK_OVERFLOW"), Uint32::New(GL_STACK_OVERFLOW), ReadOnly);

     Gl->Set(String::NewSymbol("STACK_UNDERFLOW"), Uint32::New(GL_STACK_UNDERFLOW), ReadOnly);

     Gl->Set(String::NewSymbol("OUT_OF_MEMORY"), Uint32::New(GL_OUT_OF_MEMORY), ReadOnly);

     Gl->Set(String::NewSymbol("2D"), Uint32::New(GL_2D), ReadOnly);

     Gl->Set(String::NewSymbol("3D"), Uint32::New(GL_3D), ReadOnly);

     Gl->Set(String::NewSymbol("3D_COLOR"), Uint32::New(GL_3D_COLOR), ReadOnly);

     Gl->Set(String::NewSymbol("3D_COLOR_TEXTURE"), Uint32::New(GL_3D_COLOR_TEXTURE), ReadOnly);

     Gl->Set(String::NewSymbol("4D_COLOR_TEXTURE"), Uint32::New(GL_4D_COLOR_TEXTURE), ReadOnly);

     Gl->Set(String::NewSymbol("PASS_THROUGH_TOKEN"), Uint32::New(GL_PASS_THROUGH_TOKEN), ReadOnly);

     Gl->Set(String::NewSymbol("POINT_TOKEN"), Uint32::New(GL_POINT_TOKEN), ReadOnly);

     Gl->Set(String::NewSymbol("LINE_TOKEN"), Uint32::New(GL_LINE_TOKEN), ReadOnly);

     Gl->Set(String::NewSymbol("POLYGON_TOKEN"), Uint32::New(GL_POLYGON_TOKEN), ReadOnly);

     Gl->Set(String::NewSymbol("BITMAP_TOKEN"), Uint32::New(GL_BITMAP_TOKEN), ReadOnly);

     Gl->Set(String::NewSymbol("DRAW_PIXEL_TOKEN"), Uint32::New(GL_DRAW_PIXEL_TOKEN), ReadOnly);

     Gl->Set(String::NewSymbol("COPY_PIXEL_TOKEN"), Uint32::New(GL_COPY_PIXEL_TOKEN), ReadOnly);

     Gl->Set(String::NewSymbol("LINE_RESET_TOKEN"), Uint32::New(GL_LINE_RESET_TOKEN), ReadOnly);

     Gl->Set(String::NewSymbol("EXP"), Uint32::New(GL_EXP), ReadOnly);

     Gl->Set(String::NewSymbol("EXP2"), Uint32::New(GL_EXP2), ReadOnly);

     Gl->Set(String::NewSymbol("CW"), Uint32::New(GL_CW), ReadOnly);

     Gl->Set(String::NewSymbol("CCW"), Uint32::New(GL_CCW), ReadOnly);

     Gl->Set(String::NewSymbol("COEFF"), Uint32::New(GL_COEFF), ReadOnly);

     Gl->Set(String::NewSymbol("ORDER"), Uint32::New(GL_ORDER), ReadOnly);

     Gl->Set(String::NewSymbol("DOMAIN"), Uint32::New(GL_DOMAIN), ReadOnly);

     Gl->Set(String::NewSymbol("CURRENT_COLOR"), Uint32::New(GL_CURRENT_COLOR), ReadOnly);

     Gl->Set(String::NewSymbol("CURRENT_INDEX"), Uint32::New(GL_CURRENT_INDEX), ReadOnly);

     Gl->Set(String::NewSymbol("CURRENT_NORMAL"), Uint32::New(GL_CURRENT_NORMAL), ReadOnly);

     Gl->Set(String::NewSymbol("CURRENT_TEXTURE_COORDS"), Uint32::New(GL_CURRENT_TEXTURE_COORDS), ReadOnly);

     Gl->Set(String::NewSymbol("CURRENT_RASTER_COLOR"), Uint32::New(GL_CURRENT_RASTER_COLOR), ReadOnly);

     Gl->Set(String::NewSymbol("CURRENT_RASTER_INDEX"), Uint32::New(GL_CURRENT_RASTER_INDEX), ReadOnly);

     Gl->Set(String::NewSymbol("CURRENT_RASTER_TEXTURE_COORDS"), Uint32::New(GL_CURRENT_RASTER_TEXTURE_COORDS), ReadOnly);

     Gl->Set(String::NewSymbol("CURRENT_RASTER_POSITION"), Uint32::New(GL_CURRENT_RASTER_POSITION), ReadOnly);

     Gl->Set(String::NewSymbol("CURRENT_RASTER_POSITION_VALID"), Uint32::New(GL_CURRENT_RASTER_POSITION_VALID), ReadOnly);

     Gl->Set(String::NewSymbol("CURRENT_RASTER_DISTANCE"), Uint32::New(GL_CURRENT_RASTER_DISTANCE), ReadOnly);

     Gl->Set(String::NewSymbol("POINT_SMOOTH"), Uint32::New(GL_POINT_SMOOTH), ReadOnly);

     Gl->Set(String::NewSymbol("POINT_SIZE"), Uint32::New(GL_POINT_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("POINT_SIZE_RANGE"), Uint32::New(GL_POINT_SIZE_RANGE), ReadOnly);

     Gl->Set(String::NewSymbol("POINT_SIZE_GRANULARITY"), Uint32::New(GL_POINT_SIZE_GRANULARITY), ReadOnly);

     Gl->Set(String::NewSymbol("LINE_SMOOTH"), Uint32::New(GL_LINE_SMOOTH), ReadOnly);

     Gl->Set(String::NewSymbol("LINE_WIDTH"), Uint32::New(GL_LINE_WIDTH), ReadOnly);

     Gl->Set(String::NewSymbol("LINE_WIDTH_RANGE"), Uint32::New(GL_LINE_WIDTH_RANGE), ReadOnly);

     Gl->Set(String::NewSymbol("LINE_WIDTH_GRANULARITY"), Uint32::New(GL_LINE_WIDTH_GRANULARITY), ReadOnly);

     Gl->Set(String::NewSymbol("LINE_STIPPLE"), Uint32::New(GL_LINE_STIPPLE), ReadOnly);

     Gl->Set(String::NewSymbol("LINE_STIPPLE_PATTERN"), Uint32::New(GL_LINE_STIPPLE_PATTERN), ReadOnly);

     Gl->Set(String::NewSymbol("LINE_STIPPLE_REPEAT"), Uint32::New(GL_LINE_STIPPLE_REPEAT), ReadOnly);

     Gl->Set(String::NewSymbol("LIST_MODE"), Uint32::New(GL_LIST_MODE), ReadOnly);

     Gl->Set(String::NewSymbol("MAX_LIST_NESTING"), Uint32::New(GL_MAX_LIST_NESTING), ReadOnly);

     Gl->Set(String::NewSymbol("LIST_BASE"), Uint32::New(GL_LIST_BASE), ReadOnly);

     Gl->Set(String::NewSymbol("LIST_INDEX"), Uint32::New(GL_LIST_INDEX), ReadOnly);

     Gl->Set(String::NewSymbol("POLYGON_MODE"), Uint32::New(GL_POLYGON_MODE), ReadOnly);

     Gl->Set(String::NewSymbol("POLYGON_SMOOTH"), Uint32::New(GL_POLYGON_SMOOTH), ReadOnly);

     Gl->Set(String::NewSymbol("POLYGON_STIPPLE"), Uint32::New(GL_POLYGON_STIPPLE), ReadOnly);

     Gl->Set(String::NewSymbol("EDGE_FLAG"), Uint32::New(GL_EDGE_FLAG), ReadOnly);

     Gl->Set(String::NewSymbol("CULL_FACE"), Uint32::New(GL_CULL_FACE), ReadOnly);

     Gl->Set(String::NewSymbol("CULL_FACE_MODE"), Uint32::New(GL_CULL_FACE_MODE), ReadOnly);

     Gl->Set(String::NewSymbol("FRONT_FACE"), Uint32::New(GL_FRONT_FACE), ReadOnly);

     Gl->Set(String::NewSymbol("LIGHTING"), Uint32::New(GL_LIGHTING), ReadOnly);

     Gl->Set(String::NewSymbol("LIGHT_MODEL_LOCAL_VIEWER"), Uint32::New(GL_LIGHT_MODEL_LOCAL_VIEWER), ReadOnly);

     Gl->Set(String::NewSymbol("LIGHT_MODEL_TWO_SIDE"), Uint32::New(GL_LIGHT_MODEL_TWO_SIDE), ReadOnly);

     Gl->Set(String::NewSymbol("LIGHT_MODEL_AMBIENT"), Uint32::New(GL_LIGHT_MODEL_AMBIENT), ReadOnly);

     Gl->Set(String::NewSymbol("SHADE_MODEL"), Uint32::New(GL_SHADE_MODEL), ReadOnly);

     Gl->Set(String::NewSymbol("COLOR_MATERIAL_FACE"), Uint32::New(GL_COLOR_MATERIAL_FACE), ReadOnly);

     Gl->Set(String::NewSymbol("COLOR_MATERIAL_PARAMETER"), Uint32::New(GL_COLOR_MATERIAL_PARAMETER), ReadOnly);

     Gl->Set(String::NewSymbol("COLOR_MATERIAL"), Uint32::New(GL_COLOR_MATERIAL), ReadOnly);

     Gl->Set(String::NewSymbol("FOG"), Uint32::New(GL_FOG), ReadOnly);

     Gl->Set(String::NewSymbol("FOG_INDEX"), Uint32::New(GL_FOG_INDEX), ReadOnly);

     Gl->Set(String::NewSymbol("FOG_DENSITY"), Uint32::New(GL_FOG_DENSITY), ReadOnly);

     Gl->Set(String::NewSymbol("FOG_START"), Uint32::New(GL_FOG_START), ReadOnly);

     Gl->Set(String::NewSymbol("FOG_END"), Uint32::New(GL_FOG_END), ReadOnly);

     Gl->Set(String::NewSymbol("FOG_MODE"), Uint32::New(GL_FOG_MODE), ReadOnly);

     Gl->Set(String::NewSymbol("FOG_COLOR"), Uint32::New(GL_FOG_COLOR), ReadOnly);

     Gl->Set(String::NewSymbol("DEPTH_RANGE"), Uint32::New(GL_DEPTH_RANGE), ReadOnly);

     Gl->Set(String::NewSymbol("DEPTH_TEST"), Uint32::New(GL_DEPTH_TEST), ReadOnly);

     Gl->Set(String::NewSymbol("DEPTH_WRITEMASK"), Uint32::New(GL_DEPTH_WRITEMASK), ReadOnly);

     Gl->Set(String::NewSymbol("DEPTH_CLEAR_VALUE"), Uint32::New(GL_DEPTH_CLEAR_VALUE), ReadOnly);

     Gl->Set(String::NewSymbol("DEPTH_FUNC"), Uint32::New(GL_DEPTH_FUNC), ReadOnly);

     Gl->Set(String::NewSymbol("ACCUM_CLEAR_VALUE"), Uint32::New(GL_ACCUM_CLEAR_VALUE), ReadOnly);

     Gl->Set(String::NewSymbol("STENCIL_TEST"), Uint32::New(GL_STENCIL_TEST), ReadOnly);

     Gl->Set(String::NewSymbol("STENCIL_CLEAR_VALUE"), Uint32::New(GL_STENCIL_CLEAR_VALUE), ReadOnly);

     Gl->Set(String::NewSymbol("STENCIL_FUNC"), Uint32::New(GL_STENCIL_FUNC), ReadOnly);

     Gl->Set(String::NewSymbol("STENCIL_VALUE_MASK"), Uint32::New(GL_STENCIL_VALUE_MASK), ReadOnly);

     Gl->Set(String::NewSymbol("STENCIL_FAIL"), Uint32::New(GL_STENCIL_FAIL), ReadOnly);

     Gl->Set(String::NewSymbol("STENCIL_PASS_DEPTH_FAIL"), Uint32::New(GL_STENCIL_PASS_DEPTH_FAIL), ReadOnly);

     Gl->Set(String::NewSymbol("STENCIL_PASS_DEPTH_PASS"), Uint32::New(GL_STENCIL_PASS_DEPTH_PASS), ReadOnly);

     Gl->Set(String::NewSymbol("STENCIL_REF"), Uint32::New(GL_STENCIL_REF), ReadOnly);

     Gl->Set(String::NewSymbol("STENCIL_WRITEMASK"), Uint32::New(GL_STENCIL_WRITEMASK), ReadOnly);

     Gl->Set(String::NewSymbol("MATRIX_MODE"), Uint32::New(GL_MATRIX_MODE), ReadOnly);

     Gl->Set(String::NewSymbol("NORMALIZE"), Uint32::New(GL_NORMALIZE), ReadOnly);

     Gl->Set(String::NewSymbol("VIEWPORT"), Uint32::New(GL_VIEWPORT), ReadOnly);

     Gl->Set(String::NewSymbol("MODELVIEW_STACK_DEPTH"), Uint32::New(GL_MODELVIEW_STACK_DEPTH), ReadOnly);

     Gl->Set(String::NewSymbol("PROJECTION_STACK_DEPTH"), Uint32::New(GL_PROJECTION_STACK_DEPTH), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_STACK_DEPTH"), Uint32::New(GL_TEXTURE_STACK_DEPTH), ReadOnly);

     Gl->Set(String::NewSymbol("MODELVIEW_MATRIX"), Uint32::New(GL_MODELVIEW_MATRIX), ReadOnly);

     Gl->Set(String::NewSymbol("PROJECTION_MATRIX"), Uint32::New(GL_PROJECTION_MATRIX), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_MATRIX"), Uint32::New(GL_TEXTURE_MATRIX), ReadOnly);

     Gl->Set(String::NewSymbol("ATTRIB_STACK_DEPTH"), Uint32::New(GL_ATTRIB_STACK_DEPTH), ReadOnly);

     Gl->Set(String::NewSymbol("CLIENT_ATTRIB_STACK_DEPTH"), Uint32::New(GL_CLIENT_ATTRIB_STACK_DEPTH), ReadOnly);

     Gl->Set(String::NewSymbol("ALPHA_TEST"), Uint32::New(GL_ALPHA_TEST), ReadOnly);

     Gl->Set(String::NewSymbol("ALPHA_TEST_FUNC"), Uint32::New(GL_ALPHA_TEST_FUNC), ReadOnly);

     Gl->Set(String::NewSymbol("ALPHA_TEST_REF"), Uint32::New(GL_ALPHA_TEST_REF), ReadOnly);

     Gl->Set(String::NewSymbol("DITHER"), Uint32::New(GL_DITHER), ReadOnly);

     Gl->Set(String::NewSymbol("BLEND_DST"), Uint32::New(GL_BLEND_DST), ReadOnly);

     Gl->Set(String::NewSymbol("BLEND_SRC"), Uint32::New(GL_BLEND_SRC), ReadOnly);

     Gl->Set(String::NewSymbol("BLEND"), Uint32::New(GL_BLEND), ReadOnly);

     Gl->Set(String::NewSymbol("LOGIC_OP_MODE"), Uint32::New(GL_LOGIC_OP_MODE), ReadOnly);

     Gl->Set(String::NewSymbol("INDEX_LOGIC_OP"), Uint32::New(GL_INDEX_LOGIC_OP), ReadOnly);

     Gl->Set(String::NewSymbol("COLOR_LOGIC_OP"), Uint32::New(GL_COLOR_LOGIC_OP), ReadOnly);

     Gl->Set(String::NewSymbol("AUX_BUFFERS"), Uint32::New(GL_AUX_BUFFERS), ReadOnly);

     Gl->Set(String::NewSymbol("DRAW_BUFFER"), Uint32::New(GL_DRAW_BUFFER), ReadOnly);

     Gl->Set(String::NewSymbol("READ_BUFFER"), Uint32::New(GL_READ_BUFFER), ReadOnly);

     Gl->Set(String::NewSymbol("SCISSOR_BOX"), Uint32::New(GL_SCISSOR_BOX), ReadOnly);

     Gl->Set(String::NewSymbol("SCISSOR_TEST"), Uint32::New(GL_SCISSOR_TEST), ReadOnly);

     Gl->Set(String::NewSymbol("INDEX_CLEAR_VALUE"), Uint32::New(GL_INDEX_CLEAR_VALUE), ReadOnly);

     Gl->Set(String::NewSymbol("INDEX_WRITEMASK"), Uint32::New(GL_INDEX_WRITEMASK), ReadOnly);

     Gl->Set(String::NewSymbol("COLOR_CLEAR_VALUE"), Uint32::New(GL_COLOR_CLEAR_VALUE), ReadOnly);

     Gl->Set(String::NewSymbol("COLOR_WRITEMASK"), Uint32::New(GL_COLOR_WRITEMASK), ReadOnly);

     Gl->Set(String::NewSymbol("INDEX_MODE"), Uint32::New(GL_INDEX_MODE), ReadOnly);

     Gl->Set(String::NewSymbol("RGBA_MODE"), Uint32::New(GL_RGBA_MODE), ReadOnly);

     Gl->Set(String::NewSymbol("DOUBLEBUFFER"), Uint32::New(GL_DOUBLEBUFFER), ReadOnly);

     Gl->Set(String::NewSymbol("STEREO"), Uint32::New(GL_STEREO), ReadOnly);

     Gl->Set(String::NewSymbol("RENDER_MODE"), Uint32::New(GL_RENDER_MODE), ReadOnly);

     Gl->Set(String::NewSymbol("PERSPECTIVE_CORRECTION_HINT"), Uint32::New(GL_PERSPECTIVE_CORRECTION_HINT), ReadOnly);

     Gl->Set(String::NewSymbol("POINT_SMOOTH_HINT"), Uint32::New(GL_POINT_SMOOTH_HINT), ReadOnly);

     Gl->Set(String::NewSymbol("LINE_SMOOTH_HINT"), Uint32::New(GL_LINE_SMOOTH_HINT), ReadOnly);

     Gl->Set(String::NewSymbol("POLYGON_SMOOTH_HINT"), Uint32::New(GL_POLYGON_SMOOTH_HINT), ReadOnly);

     Gl->Set(String::NewSymbol("FOG_HINT"), Uint32::New(GL_FOG_HINT), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_GEN_S"), Uint32::New(GL_TEXTURE_GEN_S), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_GEN_T"), Uint32::New(GL_TEXTURE_GEN_T), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_GEN_R"), Uint32::New(GL_TEXTURE_GEN_R), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_GEN_Q"), Uint32::New(GL_TEXTURE_GEN_Q), ReadOnly);

     Gl->Set(String::NewSymbol("PIXEL_MAP_I_TO_I"), Uint32::New(GL_PIXEL_MAP_I_TO_I), ReadOnly);

     Gl->Set(String::NewSymbol("PIXEL_MAP_S_TO_S"), Uint32::New(GL_PIXEL_MAP_S_TO_S), ReadOnly);

     Gl->Set(String::NewSymbol("PIXEL_MAP_I_TO_R"), Uint32::New(GL_PIXEL_MAP_I_TO_R), ReadOnly);

     Gl->Set(String::NewSymbol("PIXEL_MAP_I_TO_G"), Uint32::New(GL_PIXEL_MAP_I_TO_G), ReadOnly);

     Gl->Set(String::NewSymbol("PIXEL_MAP_I_TO_B"), Uint32::New(GL_PIXEL_MAP_I_TO_B), ReadOnly);

     Gl->Set(String::NewSymbol("PIXEL_MAP_I_TO_A"), Uint32::New(GL_PIXEL_MAP_I_TO_A), ReadOnly);

     Gl->Set(String::NewSymbol("PIXEL_MAP_R_TO_R"), Uint32::New(GL_PIXEL_MAP_R_TO_R), ReadOnly);

     Gl->Set(String::NewSymbol("PIXEL_MAP_G_TO_G"), Uint32::New(GL_PIXEL_MAP_G_TO_G), ReadOnly);

     Gl->Set(String::NewSymbol("PIXEL_MAP_B_TO_B"), Uint32::New(GL_PIXEL_MAP_B_TO_B), ReadOnly);

     Gl->Set(String::NewSymbol("PIXEL_MAP_A_TO_A"), Uint32::New(GL_PIXEL_MAP_A_TO_A), ReadOnly);

     Gl->Set(String::NewSymbol("PIXEL_MAP_I_TO_I_SIZE"), Uint32::New(GL_PIXEL_MAP_I_TO_I_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("PIXEL_MAP_S_TO_S_SIZE"), Uint32::New(GL_PIXEL_MAP_S_TO_S_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("PIXEL_MAP_I_TO_R_SIZE"), Uint32::New(GL_PIXEL_MAP_I_TO_R_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("PIXEL_MAP_I_TO_G_SIZE"), Uint32::New(GL_PIXEL_MAP_I_TO_G_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("PIXEL_MAP_I_TO_B_SIZE"), Uint32::New(GL_PIXEL_MAP_I_TO_B_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("PIXEL_MAP_I_TO_A_SIZE"), Uint32::New(GL_PIXEL_MAP_I_TO_A_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("PIXEL_MAP_R_TO_R_SIZE"), Uint32::New(GL_PIXEL_MAP_R_TO_R_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("PIXEL_MAP_G_TO_G_SIZE"), Uint32::New(GL_PIXEL_MAP_G_TO_G_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("PIXEL_MAP_B_TO_B_SIZE"), Uint32::New(GL_PIXEL_MAP_B_TO_B_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("PIXEL_MAP_A_TO_A_SIZE"), Uint32::New(GL_PIXEL_MAP_A_TO_A_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("UNPACK_SWAP_BYTES"), Uint32::New(GL_UNPACK_SWAP_BYTES), ReadOnly);

     Gl->Set(String::NewSymbol("UNPACK_LSB_FIRST"), Uint32::New(GL_UNPACK_LSB_FIRST), ReadOnly);

     Gl->Set(String::NewSymbol("UNPACK_ROW_LENGTH"), Uint32::New(GL_UNPACK_ROW_LENGTH), ReadOnly);

     Gl->Set(String::NewSymbol("UNPACK_SKIP_ROWS"), Uint32::New(GL_UNPACK_SKIP_ROWS), ReadOnly);

     Gl->Set(String::NewSymbol("UNPACK_SKIP_PIXELS"), Uint32::New(GL_UNPACK_SKIP_PIXELS), ReadOnly);

     Gl->Set(String::NewSymbol("UNPACK_ALIGNMENT"), Uint32::New(GL_UNPACK_ALIGNMENT), ReadOnly);

     Gl->Set(String::NewSymbol("PACK_SWAP_BYTES"), Uint32::New(GL_PACK_SWAP_BYTES), ReadOnly);

     Gl->Set(String::NewSymbol("PACK_LSB_FIRST"), Uint32::New(GL_PACK_LSB_FIRST), ReadOnly);

     Gl->Set(String::NewSymbol("PACK_ROW_LENGTH"), Uint32::New(GL_PACK_ROW_LENGTH), ReadOnly);

     Gl->Set(String::NewSymbol("PACK_SKIP_ROWS"), Uint32::New(GL_PACK_SKIP_ROWS), ReadOnly);

     Gl->Set(String::NewSymbol("PACK_SKIP_PIXELS"), Uint32::New(GL_PACK_SKIP_PIXELS), ReadOnly);

     Gl->Set(String::NewSymbol("PACK_ALIGNMENT"), Uint32::New(GL_PACK_ALIGNMENT), ReadOnly);

     Gl->Set(String::NewSymbol("MAP_COLOR"), Uint32::New(GL_MAP_COLOR), ReadOnly);

     Gl->Set(String::NewSymbol("MAP_STENCIL"), Uint32::New(GL_MAP_STENCIL), ReadOnly);

     Gl->Set(String::NewSymbol("INDEX_SHIFT"), Uint32::New(GL_INDEX_SHIFT), ReadOnly);

     Gl->Set(String::NewSymbol("INDEX_OFFSET"), Uint32::New(GL_INDEX_OFFSET), ReadOnly);

     Gl->Set(String::NewSymbol("RED_SCALE"), Uint32::New(GL_RED_SCALE), ReadOnly);

     Gl->Set(String::NewSymbol("RED_BIAS"), Uint32::New(GL_RED_BIAS), ReadOnly);

     Gl->Set(String::NewSymbol("ZOOM_X"), Uint32::New(GL_ZOOM_X), ReadOnly);

     Gl->Set(String::NewSymbol("ZOOM_Y"), Uint32::New(GL_ZOOM_Y), ReadOnly);

     Gl->Set(String::NewSymbol("GREEN_SCALE"), Uint32::New(GL_GREEN_SCALE), ReadOnly);

     Gl->Set(String::NewSymbol("GREEN_BIAS"), Uint32::New(GL_GREEN_BIAS), ReadOnly);

     Gl->Set(String::NewSymbol("BLUE_SCALE"), Uint32::New(GL_BLUE_SCALE), ReadOnly);

     Gl->Set(String::NewSymbol("BLUE_BIAS"), Uint32::New(GL_BLUE_BIAS), ReadOnly);

     Gl->Set(String::NewSymbol("ALPHA_SCALE"), Uint32::New(GL_ALPHA_SCALE), ReadOnly);

     Gl->Set(String::NewSymbol("ALPHA_BIAS"), Uint32::New(GL_ALPHA_BIAS), ReadOnly);

     Gl->Set(String::NewSymbol("DEPTH_SCALE"), Uint32::New(GL_DEPTH_SCALE), ReadOnly);

     Gl->Set(String::NewSymbol("DEPTH_BIAS"), Uint32::New(GL_DEPTH_BIAS), ReadOnly);

     Gl->Set(String::NewSymbol("MAX_EVAL_ORDER"), Uint32::New(GL_MAX_EVAL_ORDER), ReadOnly);

     Gl->Set(String::NewSymbol("MAX_LIGHTS"), Uint32::New(GL_MAX_LIGHTS), ReadOnly);

     Gl->Set(String::NewSymbol("MAX_CLIP_PLANES"), Uint32::New(GL_MAX_CLIP_PLANES), ReadOnly);

     Gl->Set(String::NewSymbol("MAX_TEXTURE_SIZE"), Uint32::New(GL_MAX_TEXTURE_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("MAX_PIXEL_MAP_TABLE"), Uint32::New(GL_MAX_PIXEL_MAP_TABLE), ReadOnly);

     Gl->Set(String::NewSymbol("MAX_ATTRIB_STACK_DEPTH"), Uint32::New(GL_MAX_ATTRIB_STACK_DEPTH), ReadOnly);

     Gl->Set(String::NewSymbol("MAX_MODELVIEW_STACK_DEPTH"), Uint32::New(GL_MAX_MODELVIEW_STACK_DEPTH), ReadOnly);

     Gl->Set(String::NewSymbol("MAX_NAME_STACK_DEPTH"), Uint32::New(GL_MAX_NAME_STACK_DEPTH), ReadOnly);

     Gl->Set(String::NewSymbol("MAX_PROJECTION_STACK_DEPTH"), Uint32::New(GL_MAX_PROJECTION_STACK_DEPTH), ReadOnly);

     Gl->Set(String::NewSymbol("MAX_TEXTURE_STACK_DEPTH"), Uint32::New(GL_MAX_TEXTURE_STACK_DEPTH), ReadOnly);

     Gl->Set(String::NewSymbol("MAX_VIEWPORT_DIMS"), Uint32::New(GL_MAX_VIEWPORT_DIMS), ReadOnly);

     Gl->Set(String::NewSymbol("MAX_CLIENT_ATTRIB_STACK_DEPTH"), Uint32::New(GL_MAX_CLIENT_ATTRIB_STACK_DEPTH), ReadOnly);

     Gl->Set(String::NewSymbol("SUBPIXEL_BITS"), Uint32::New(GL_SUBPIXEL_BITS), ReadOnly);

     Gl->Set(String::NewSymbol("INDEX_BITS"), Uint32::New(GL_INDEX_BITS), ReadOnly);

     Gl->Set(String::NewSymbol("RED_BITS"), Uint32::New(GL_RED_BITS), ReadOnly);

     Gl->Set(String::NewSymbol("GREEN_BITS"), Uint32::New(GL_GREEN_BITS), ReadOnly);

     Gl->Set(String::NewSymbol("BLUE_BITS"), Uint32::New(GL_BLUE_BITS), ReadOnly);

     Gl->Set(String::NewSymbol("ALPHA_BITS"), Uint32::New(GL_ALPHA_BITS), ReadOnly);

     Gl->Set(String::NewSymbol("DEPTH_BITS"), Uint32::New(GL_DEPTH_BITS), ReadOnly);

     Gl->Set(String::NewSymbol("STENCIL_BITS"), Uint32::New(GL_STENCIL_BITS), ReadOnly);

     Gl->Set(String::NewSymbol("ACCUM_RED_BITS"), Uint32::New(GL_ACCUM_RED_BITS), ReadOnly);

     Gl->Set(String::NewSymbol("ACCUM_GREEN_BITS"), Uint32::New(GL_ACCUM_GREEN_BITS), ReadOnly);

     Gl->Set(String::NewSymbol("ACCUM_BLUE_BITS"), Uint32::New(GL_ACCUM_BLUE_BITS), ReadOnly);

     Gl->Set(String::NewSymbol("ACCUM_ALPHA_BITS"), Uint32::New(GL_ACCUM_ALPHA_BITS), ReadOnly);

     Gl->Set(String::NewSymbol("NAME_STACK_DEPTH"), Uint32::New(GL_NAME_STACK_DEPTH), ReadOnly);

     Gl->Set(String::NewSymbol("AUTO_NORMAL"), Uint32::New(GL_AUTO_NORMAL), ReadOnly);

     Gl->Set(String::NewSymbol("MAP1_COLOR_4"), Uint32::New(GL_MAP1_COLOR_4), ReadOnly);

     Gl->Set(String::NewSymbol("MAP1_INDEX"), Uint32::New(GL_MAP1_INDEX), ReadOnly);

     Gl->Set(String::NewSymbol("MAP1_NORMAL"), Uint32::New(GL_MAP1_NORMAL), ReadOnly);

     Gl->Set(String::NewSymbol("MAP1_TEXTURE_COORD_1"), Uint32::New(GL_MAP1_TEXTURE_COORD_1), ReadOnly);

     Gl->Set(String::NewSymbol("MAP1_TEXTURE_COORD_2"), Uint32::New(GL_MAP1_TEXTURE_COORD_2), ReadOnly);

     Gl->Set(String::NewSymbol("MAP1_TEXTURE_COORD_3"), Uint32::New(GL_MAP1_TEXTURE_COORD_3), ReadOnly);

     Gl->Set(String::NewSymbol("MAP1_TEXTURE_COORD_4"), Uint32::New(GL_MAP1_TEXTURE_COORD_4), ReadOnly);

     Gl->Set(String::NewSymbol("MAP1_VERTEX_3"), Uint32::New(GL_MAP1_VERTEX_3), ReadOnly);

     Gl->Set(String::NewSymbol("MAP1_VERTEX_4"), Uint32::New(GL_MAP1_VERTEX_4), ReadOnly);

     Gl->Set(String::NewSymbol("MAP2_COLOR_4"), Uint32::New(GL_MAP2_COLOR_4), ReadOnly);

     Gl->Set(String::NewSymbol("MAP2_INDEX"), Uint32::New(GL_MAP2_INDEX), ReadOnly);

     Gl->Set(String::NewSymbol("MAP2_NORMAL"), Uint32::New(GL_MAP2_NORMAL), ReadOnly);

     Gl->Set(String::NewSymbol("MAP2_TEXTURE_COORD_1"), Uint32::New(GL_MAP2_TEXTURE_COORD_1), ReadOnly);

     Gl->Set(String::NewSymbol("MAP2_TEXTURE_COORD_2"), Uint32::New(GL_MAP2_TEXTURE_COORD_2), ReadOnly);

     Gl->Set(String::NewSymbol("MAP2_TEXTURE_COORD_3"), Uint32::New(GL_MAP2_TEXTURE_COORD_3), ReadOnly);

     Gl->Set(String::NewSymbol("MAP2_TEXTURE_COORD_4"), Uint32::New(GL_MAP2_TEXTURE_COORD_4), ReadOnly);

     Gl->Set(String::NewSymbol("MAP2_VERTEX_3"), Uint32::New(GL_MAP2_VERTEX_3), ReadOnly);

     Gl->Set(String::NewSymbol("MAP2_VERTEX_4"), Uint32::New(GL_MAP2_VERTEX_4), ReadOnly);

     Gl->Set(String::NewSymbol("MAP1_GRID_DOMAIN"), Uint32::New(GL_MAP1_GRID_DOMAIN), ReadOnly);

     Gl->Set(String::NewSymbol("MAP1_GRID_SEGMENTS"), Uint32::New(GL_MAP1_GRID_SEGMENTS), ReadOnly);

     Gl->Set(String::NewSymbol("MAP2_GRID_DOMAIN"), Uint32::New(GL_MAP2_GRID_DOMAIN), ReadOnly);

     Gl->Set(String::NewSymbol("MAP2_GRID_SEGMENTS"), Uint32::New(GL_MAP2_GRID_SEGMENTS), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_1D"), Uint32::New(GL_TEXTURE_1D), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_2D"), Uint32::New(GL_TEXTURE_2D), ReadOnly);

     Gl->Set(String::NewSymbol("FEEDBACK_BUFFER_POINTER"), Uint32::New(GL_FEEDBACK_BUFFER_POINTER), ReadOnly);

     Gl->Set(String::NewSymbol("FEEDBACK_BUFFER_SIZE"), Uint32::New(GL_FEEDBACK_BUFFER_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("FEEDBACK_BUFFER_TYPE"), Uint32::New(GL_FEEDBACK_BUFFER_TYPE), ReadOnly);

     Gl->Set(String::NewSymbol("SELECTION_BUFFER_POINTER"), Uint32::New(GL_SELECTION_BUFFER_POINTER), ReadOnly);

     Gl->Set(String::NewSymbol("SELECTION_BUFFER_SIZE"), Uint32::New(GL_SELECTION_BUFFER_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_WIDTH"), Uint32::New(GL_TEXTURE_WIDTH), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_HEIGHT"), Uint32::New(GL_TEXTURE_HEIGHT), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_INTERNAL_FORMAT"), Uint32::New(GL_TEXTURE_INTERNAL_FORMAT), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_BORDER_COLOR"), Uint32::New(GL_TEXTURE_BORDER_COLOR), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_BORDER"), Uint32::New(GL_TEXTURE_BORDER), ReadOnly);

     Gl->Set(String::NewSymbol("DONT_CARE"), Uint32::New(GL_DONT_CARE), ReadOnly);

     Gl->Set(String::NewSymbol("FASTEST"), Uint32::New(GL_FASTEST), ReadOnly);

     Gl->Set(String::NewSymbol("NICEST"), Uint32::New(GL_NICEST), ReadOnly);

     Gl->Set(String::NewSymbol("LIGHT0"), Uint32::New(GL_LIGHT0), ReadOnly);

     Gl->Set(String::NewSymbol("LIGHT1"), Uint32::New(GL_LIGHT1), ReadOnly);

     Gl->Set(String::NewSymbol("LIGHT2"), Uint32::New(GL_LIGHT2), ReadOnly);

     Gl->Set(String::NewSymbol("LIGHT3"), Uint32::New(GL_LIGHT3), ReadOnly);

     Gl->Set(String::NewSymbol("LIGHT4"), Uint32::New(GL_LIGHT4), ReadOnly);

     Gl->Set(String::NewSymbol("LIGHT5"), Uint32::New(GL_LIGHT5), ReadOnly);

     Gl->Set(String::NewSymbol("LIGHT6"), Uint32::New(GL_LIGHT6), ReadOnly);

     Gl->Set(String::NewSymbol("LIGHT7"), Uint32::New(GL_LIGHT7), ReadOnly);

     Gl->Set(String::NewSymbol("AMBIENT"), Uint32::New(GL_AMBIENT), ReadOnly);

     Gl->Set(String::NewSymbol("DIFFUSE"), Uint32::New(GL_DIFFUSE), ReadOnly);

     Gl->Set(String::NewSymbol("SPECULAR"), Uint32::New(GL_SPECULAR), ReadOnly);

     Gl->Set(String::NewSymbol("POSITION"), Uint32::New(GL_POSITION), ReadOnly);

     Gl->Set(String::NewSymbol("SPOT_DIRECTION"), Uint32::New(GL_SPOT_DIRECTION), ReadOnly);

     Gl->Set(String::NewSymbol("SPOT_EXPONENT"), Uint32::New(GL_SPOT_EXPONENT), ReadOnly);

     Gl->Set(String::NewSymbol("SPOT_CUTOFF"), Uint32::New(GL_SPOT_CUTOFF), ReadOnly);

     Gl->Set(String::NewSymbol("COMPILE"), Uint32::New(GL_COMPILE), ReadOnly);

     Gl->Set(String::NewSymbol("COMPILE_AND_EXECUTE"), Uint32::New(GL_COMPILE_AND_EXECUTE), ReadOnly);

     Gl->Set(String::NewSymbol("CLEAR"), Uint32::New(GL_CLEAR), ReadOnly);

     Gl->Set(String::NewSymbol("AND"), Uint32::New(GL_AND), ReadOnly);

     Gl->Set(String::NewSymbol("AND_REVERSE"), Uint32::New(GL_AND_REVERSE), ReadOnly);

     Gl->Set(String::NewSymbol("COPY"), Uint32::New(GL_COPY), ReadOnly);

     Gl->Set(String::NewSymbol("AND_INVERTED"), Uint32::New(GL_AND_INVERTED), ReadOnly);

     Gl->Set(String::NewSymbol("NOOP"), Uint32::New(GL_NOOP), ReadOnly);

     Gl->Set(String::NewSymbol("XOR"), Uint32::New(GL_XOR), ReadOnly);

     Gl->Set(String::NewSymbol("OR"), Uint32::New(GL_OR), ReadOnly);

     Gl->Set(String::NewSymbol("NOR"), Uint32::New(GL_NOR), ReadOnly);

     Gl->Set(String::NewSymbol("EQUIV"), Uint32::New(GL_EQUIV), ReadOnly);

     Gl->Set(String::NewSymbol("INVERT"), Uint32::New(GL_INVERT), ReadOnly);

     Gl->Set(String::NewSymbol("OR_REVERSE"), Uint32::New(GL_OR_REVERSE), ReadOnly);

     Gl->Set(String::NewSymbol("COPY_INVERTED"), Uint32::New(GL_COPY_INVERTED), ReadOnly);

     Gl->Set(String::NewSymbol("OR_INVERTED"), Uint32::New(GL_OR_INVERTED), ReadOnly);

     Gl->Set(String::NewSymbol("NAND"), Uint32::New(GL_NAND), ReadOnly);

     Gl->Set(String::NewSymbol("SET"), Uint32::New(GL_SET), ReadOnly);

     Gl->Set(String::NewSymbol("EMISSION"), Uint32::New(GL_EMISSION), ReadOnly);

     Gl->Set(String::NewSymbol("SHININESS"), Uint32::New(GL_SHININESS), ReadOnly);

     Gl->Set(String::NewSymbol("AMBIENT_AND_DIFFUSE"), Uint32::New(GL_AMBIENT_AND_DIFFUSE), ReadOnly);

     Gl->Set(String::NewSymbol("COLOR_INDEXES"), Uint32::New(GL_COLOR_INDEXES), ReadOnly);

     Gl->Set(String::NewSymbol("MODELVIEW"), Uint32::New(GL_MODELVIEW), ReadOnly);

     Gl->Set(String::NewSymbol("PROJECTION"), Uint32::New(GL_PROJECTION), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE"), Uint32::New(GL_TEXTURE), ReadOnly);

     Gl->Set(String::NewSymbol("COLOR"), Uint32::New(GL_COLOR), ReadOnly);

     Gl->Set(String::NewSymbol("DEPTH"), Uint32::New(GL_DEPTH), ReadOnly);

     Gl->Set(String::NewSymbol("STENCIL"), Uint32::New(GL_STENCIL), ReadOnly);

     Gl->Set(String::NewSymbol("COLOR_INDEX"), Uint32::New(GL_COLOR_INDEX), ReadOnly);

     Gl->Set(String::NewSymbol("STENCIL_INDEX"), Uint32::New(GL_STENCIL_INDEX), ReadOnly);

     Gl->Set(String::NewSymbol("DEPTH_COMPONENT"), Uint32::New(GL_DEPTH_COMPONENT), ReadOnly);

     Gl->Set(String::NewSymbol("RED"), Uint32::New(GL_RED), ReadOnly);

     Gl->Set(String::NewSymbol("GREEN"), Uint32::New(GL_GREEN), ReadOnly);

     Gl->Set(String::NewSymbol("BLUE"), Uint32::New(GL_BLUE), ReadOnly);

     Gl->Set(String::NewSymbol("ALPHA"), Uint32::New(GL_ALPHA), ReadOnly);

     Gl->Set(String::NewSymbol("RGB"), Uint32::New(GL_RGB), ReadOnly);

     Gl->Set(String::NewSymbol("RGBA"), Uint32::New(GL_RGBA), ReadOnly);

     Gl->Set(String::NewSymbol("LUMINANCE"), Uint32::New(GL_LUMINANCE), ReadOnly);

     Gl->Set(String::NewSymbol("LUMINANCE_ALPHA"), Uint32::New(GL_LUMINANCE_ALPHA), ReadOnly);

     Gl->Set(String::NewSymbol("BITMAP"), Uint32::New(GL_BITMAP), ReadOnly);

     Gl->Set(String::NewSymbol("POINT"), Uint32::New(GL_POINT), ReadOnly);

     Gl->Set(String::NewSymbol("LINE"), Uint32::New(GL_LINE), ReadOnly);

     Gl->Set(String::NewSymbol("FILL"), Uint32::New(GL_FILL), ReadOnly);

     Gl->Set(String::NewSymbol("RENDER"), Uint32::New(GL_RENDER), ReadOnly);

     Gl->Set(String::NewSymbol("FEEDBACK"), Uint32::New(GL_FEEDBACK), ReadOnly);

     Gl->Set(String::NewSymbol("SELECT"), Uint32::New(GL_SELECT), ReadOnly);

     Gl->Set(String::NewSymbol("FLAT"), Uint32::New(GL_FLAT), ReadOnly);

     Gl->Set(String::NewSymbol("SMOOTH"), Uint32::New(GL_SMOOTH), ReadOnly);

     Gl->Set(String::NewSymbol("KEEP"), Uint32::New(GL_KEEP), ReadOnly);

     Gl->Set(String::NewSymbol("REPLACE"), Uint32::New(GL_REPLACE), ReadOnly);

     Gl->Set(String::NewSymbol("INCR"), Uint32::New(GL_INCR), ReadOnly);

     Gl->Set(String::NewSymbol("DECR"), Uint32::New(GL_DECR), ReadOnly);

     Gl->Set(String::NewSymbol("VENDOR"), Uint32::New(GL_VENDOR), ReadOnly);

     Gl->Set(String::NewSymbol("RENDERER"), Uint32::New(GL_RENDERER), ReadOnly);

     Gl->Set(String::NewSymbol("VERSION"), Uint32::New(GL_VERSION), ReadOnly);

     Gl->Set(String::NewSymbol("EXTENSIONS"), Uint32::New(GL_EXTENSIONS), ReadOnly);

     Gl->Set(String::NewSymbol("S"), Uint32::New(GL_S), ReadOnly);

     Gl->Set(String::NewSymbol("T"), Uint32::New(GL_T), ReadOnly);

     Gl->Set(String::NewSymbol("R"), Uint32::New(GL_R), ReadOnly);

     Gl->Set(String::NewSymbol("Q"), Uint32::New(GL_Q), ReadOnly);

     Gl->Set(String::NewSymbol("MODULATE"), Uint32::New(GL_MODULATE), ReadOnly);

     Gl->Set(String::NewSymbol("DECAL"), Uint32::New(GL_DECAL), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_ENV_MODE"), Uint32::New(GL_TEXTURE_ENV_MODE), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_ENV_COLOR"), Uint32::New(GL_TEXTURE_ENV_COLOR), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_ENV"), Uint32::New(GL_TEXTURE_ENV), ReadOnly);

     Gl->Set(String::NewSymbol("EYE_LINEAR"), Uint32::New(GL_EYE_LINEAR), ReadOnly);

     Gl->Set(String::NewSymbol("OBJECT_LINEAR"), Uint32::New(GL_OBJECT_LINEAR), ReadOnly);

     Gl->Set(String::NewSymbol("SPHERE_MAP"), Uint32::New(GL_SPHERE_MAP), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_GEN_MODE"), Uint32::New(GL_TEXTURE_GEN_MODE), ReadOnly);

     Gl->Set(String::NewSymbol("OBJECT_PLANE"), Uint32::New(GL_OBJECT_PLANE), ReadOnly);

     Gl->Set(String::NewSymbol("EYE_PLANE"), Uint32::New(GL_EYE_PLANE), ReadOnly);

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

     Gl->Set(String::NewSymbol("CLAMP"), Uint32::New(GL_CLAMP), ReadOnly);

     Gl->Set(String::NewSymbol("REPEAT"), Uint32::New(GL_REPEAT), ReadOnly);

     Gl->Set(String::NewSymbol("CLIENT_PIXEL_STORE_BIT"), Uint32::New(GL_CLIENT_PIXEL_STORE_BIT), ReadOnly);

     Gl->Set(String::NewSymbol("CLIENT_VERTEX_ARRAY_BIT"), Uint32::New(GL_CLIENT_VERTEX_ARRAY_BIT), ReadOnly);

     Gl->Set(String::NewSymbol("CLIENT_ALL_ATTRIB_BITS"), Uint32::New(GL_CLIENT_ALL_ATTRIB_BITS), ReadOnly);

     Gl->Set(String::NewSymbol("POLYGON_OFFSET_FACTOR"), Uint32::New(GL_POLYGON_OFFSET_FACTOR), ReadOnly);

     Gl->Set(String::NewSymbol("POLYGON_OFFSET_UNITS"), Uint32::New(GL_POLYGON_OFFSET_UNITS), ReadOnly);

     Gl->Set(String::NewSymbol("POLYGON_OFFSET_POINT"), Uint32::New(GL_POLYGON_OFFSET_POINT), ReadOnly);

     Gl->Set(String::NewSymbol("POLYGON_OFFSET_LINE"), Uint32::New(GL_POLYGON_OFFSET_LINE), ReadOnly);

     Gl->Set(String::NewSymbol("POLYGON_OFFSET_FILL"), Uint32::New(GL_POLYGON_OFFSET_FILL), ReadOnly);

     Gl->Set(String::NewSymbol("ALPHA4"), Uint32::New(GL_ALPHA4), ReadOnly);

     Gl->Set(String::NewSymbol("ALPHA8"), Uint32::New(GL_ALPHA8), ReadOnly);

     Gl->Set(String::NewSymbol("ALPHA12"), Uint32::New(GL_ALPHA12), ReadOnly);

     Gl->Set(String::NewSymbol("ALPHA16"), Uint32::New(GL_ALPHA16), ReadOnly);

     Gl->Set(String::NewSymbol("LUMINANCE4"), Uint32::New(GL_LUMINANCE4), ReadOnly);

     Gl->Set(String::NewSymbol("LUMINANCE8"), Uint32::New(GL_LUMINANCE8), ReadOnly);

     Gl->Set(String::NewSymbol("LUMINANCE12"), Uint32::New(GL_LUMINANCE12), ReadOnly);

     Gl->Set(String::NewSymbol("LUMINANCE16"), Uint32::New(GL_LUMINANCE16), ReadOnly);

     Gl->Set(String::NewSymbol("LUMINANCE4_ALPHA4"), Uint32::New(GL_LUMINANCE4_ALPHA4), ReadOnly);

     Gl->Set(String::NewSymbol("LUMINANCE6_ALPHA2"), Uint32::New(GL_LUMINANCE6_ALPHA2), ReadOnly);

     Gl->Set(String::NewSymbol("LUMINANCE8_ALPHA8"), Uint32::New(GL_LUMINANCE8_ALPHA8), ReadOnly);

     Gl->Set(String::NewSymbol("LUMINANCE12_ALPHA4"), Uint32::New(GL_LUMINANCE12_ALPHA4), ReadOnly);

     Gl->Set(String::NewSymbol("LUMINANCE12_ALPHA12"), Uint32::New(GL_LUMINANCE12_ALPHA12), ReadOnly);

     Gl->Set(String::NewSymbol("LUMINANCE16_ALPHA16"), Uint32::New(GL_LUMINANCE16_ALPHA16), ReadOnly);

     Gl->Set(String::NewSymbol("INTENSITY"), Uint32::New(GL_INTENSITY), ReadOnly);

     Gl->Set(String::NewSymbol("INTENSITY4"), Uint32::New(GL_INTENSITY4), ReadOnly);

     Gl->Set(String::NewSymbol("INTENSITY8"), Uint32::New(GL_INTENSITY8), ReadOnly);

     Gl->Set(String::NewSymbol("INTENSITY12"), Uint32::New(GL_INTENSITY12), ReadOnly);

     Gl->Set(String::NewSymbol("INTENSITY16"), Uint32::New(GL_INTENSITY16), ReadOnly);

     Gl->Set(String::NewSymbol("R3_G3_B2"), Uint32::New(GL_R3_G3_B2), ReadOnly);

     Gl->Set(String::NewSymbol("RGB4"), Uint32::New(GL_RGB4), ReadOnly);

     Gl->Set(String::NewSymbol("RGB5"), Uint32::New(GL_RGB5), ReadOnly);

     Gl->Set(String::NewSymbol("RGB8"), Uint32::New(GL_RGB8), ReadOnly);

     Gl->Set(String::NewSymbol("RGB10"), Uint32::New(GL_RGB10), ReadOnly);

     Gl->Set(String::NewSymbol("RGB12"), Uint32::New(GL_RGB12), ReadOnly);

     Gl->Set(String::NewSymbol("RGB16"), Uint32::New(GL_RGB16), ReadOnly);

     Gl->Set(String::NewSymbol("RGBA2"), Uint32::New(GL_RGBA2), ReadOnly);

     Gl->Set(String::NewSymbol("RGBA4"), Uint32::New(GL_RGBA4), ReadOnly);

     Gl->Set(String::NewSymbol("RGB5_A1"), Uint32::New(GL_RGB5_A1), ReadOnly);

     Gl->Set(String::NewSymbol("RGBA8"), Uint32::New(GL_RGBA8), ReadOnly);

     Gl->Set(String::NewSymbol("RGB10_A2"), Uint32::New(GL_RGB10_A2), ReadOnly);

     Gl->Set(String::NewSymbol("RGBA12"), Uint32::New(GL_RGBA12), ReadOnly);

     Gl->Set(String::NewSymbol("RGBA16"), Uint32::New(GL_RGBA16), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_RED_SIZE"), Uint32::New(GL_TEXTURE_RED_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_GREEN_SIZE"), Uint32::New(GL_TEXTURE_GREEN_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_BLUE_SIZE"), Uint32::New(GL_TEXTURE_BLUE_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_ALPHA_SIZE"), Uint32::New(GL_TEXTURE_ALPHA_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_LUMINANCE_SIZE"), Uint32::New(GL_TEXTURE_LUMINANCE_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_INTENSITY_SIZE"), Uint32::New(GL_TEXTURE_INTENSITY_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("PROXY_TEXTURE_1D"), Uint32::New(GL_PROXY_TEXTURE_1D), ReadOnly);

     Gl->Set(String::NewSymbol("PROXY_TEXTURE_2D"), Uint32::New(GL_PROXY_TEXTURE_2D), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_PRIORITY"), Uint32::New(GL_TEXTURE_PRIORITY), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_RESIDENT"), Uint32::New(GL_TEXTURE_RESIDENT), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_BINDING_1D"), Uint32::New(GL_TEXTURE_BINDING_1D), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_BINDING_2D"), Uint32::New(GL_TEXTURE_BINDING_2D), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_BINDING_3D"), Uint32::New(GL_TEXTURE_BINDING_3D), ReadOnly);

     Gl->Set(String::NewSymbol("VERTEX_ARRAY"), Uint32::New(GL_VERTEX_ARRAY), ReadOnly);

     Gl->Set(String::NewSymbol("NORMAL_ARRAY"), Uint32::New(GL_NORMAL_ARRAY), ReadOnly);

     Gl->Set(String::NewSymbol("COLOR_ARRAY"), Uint32::New(GL_COLOR_ARRAY), ReadOnly);

     Gl->Set(String::NewSymbol("INDEX_ARRAY"), Uint32::New(GL_INDEX_ARRAY), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_COORD_ARRAY"), Uint32::New(GL_TEXTURE_COORD_ARRAY), ReadOnly);

     Gl->Set(String::NewSymbol("EDGE_FLAG_ARRAY"), Uint32::New(GL_EDGE_FLAG_ARRAY), ReadOnly);

     Gl->Set(String::NewSymbol("VERTEX_ARRAY_SIZE"), Uint32::New(GL_VERTEX_ARRAY_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("VERTEX_ARRAY_TYPE"), Uint32::New(GL_VERTEX_ARRAY_TYPE), ReadOnly);

     Gl->Set(String::NewSymbol("VERTEX_ARRAY_STRIDE"), Uint32::New(GL_VERTEX_ARRAY_STRIDE), ReadOnly);

     Gl->Set(String::NewSymbol("NORMAL_ARRAY_TYPE"), Uint32::New(GL_NORMAL_ARRAY_TYPE), ReadOnly);

     Gl->Set(String::NewSymbol("NORMAL_ARRAY_STRIDE"), Uint32::New(GL_NORMAL_ARRAY_STRIDE), ReadOnly);

     Gl->Set(String::NewSymbol("COLOR_ARRAY_SIZE"), Uint32::New(GL_COLOR_ARRAY_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("COLOR_ARRAY_TYPE"), Uint32::New(GL_COLOR_ARRAY_TYPE), ReadOnly);

     Gl->Set(String::NewSymbol("COLOR_ARRAY_STRIDE"), Uint32::New(GL_COLOR_ARRAY_STRIDE), ReadOnly);

     Gl->Set(String::NewSymbol("INDEX_ARRAY_TYPE"), Uint32::New(GL_INDEX_ARRAY_TYPE), ReadOnly);

     Gl->Set(String::NewSymbol("INDEX_ARRAY_STRIDE"), Uint32::New(GL_INDEX_ARRAY_STRIDE), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_COORD_ARRAY_SIZE"), Uint32::New(GL_TEXTURE_COORD_ARRAY_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_COORD_ARRAY_TYPE"), Uint32::New(GL_TEXTURE_COORD_ARRAY_TYPE), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_COORD_ARRAY_STRIDE"), Uint32::New(GL_TEXTURE_COORD_ARRAY_STRIDE), ReadOnly);

     Gl->Set(String::NewSymbol("EDGE_FLAG_ARRAY_STRIDE"), Uint32::New(GL_EDGE_FLAG_ARRAY_STRIDE), ReadOnly);

     Gl->Set(String::NewSymbol("VERTEX_ARRAY_POINTER"), Uint32::New(GL_VERTEX_ARRAY_POINTER), ReadOnly);

     Gl->Set(String::NewSymbol("NORMAL_ARRAY_POINTER"), Uint32::New(GL_NORMAL_ARRAY_POINTER), ReadOnly);

     Gl->Set(String::NewSymbol("COLOR_ARRAY_POINTER"), Uint32::New(GL_COLOR_ARRAY_POINTER), ReadOnly);

     Gl->Set(String::NewSymbol("INDEX_ARRAY_POINTER"), Uint32::New(GL_INDEX_ARRAY_POINTER), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_COORD_ARRAY_POINTER"), Uint32::New(GL_TEXTURE_COORD_ARRAY_POINTER), ReadOnly);

     Gl->Set(String::NewSymbol("EDGE_FLAG_ARRAY_POINTER"), Uint32::New(GL_EDGE_FLAG_ARRAY_POINTER), ReadOnly);

     Gl->Set(String::NewSymbol("V2F"), Uint32::New(GL_V2F), ReadOnly);

     Gl->Set(String::NewSymbol("V3F"), Uint32::New(GL_V3F), ReadOnly);

     Gl->Set(String::NewSymbol("C4UB_V2F"), Uint32::New(GL_C4UB_V2F), ReadOnly);

     Gl->Set(String::NewSymbol("C4UB_V3F"), Uint32::New(GL_C4UB_V3F), ReadOnly);

     Gl->Set(String::NewSymbol("C3F_V3F"), Uint32::New(GL_C3F_V3F), ReadOnly);

     Gl->Set(String::NewSymbol("N3F_V3F"), Uint32::New(GL_N3F_V3F), ReadOnly);

     Gl->Set(String::NewSymbol("C4F_N3F_V3F"), Uint32::New(GL_C4F_N3F_V3F), ReadOnly);

     Gl->Set(String::NewSymbol("T2F_V3F"), Uint32::New(GL_T2F_V3F), ReadOnly);

     Gl->Set(String::NewSymbol("T4F_V4F"), Uint32::New(GL_T4F_V4F), ReadOnly);

     Gl->Set(String::NewSymbol("T2F_C4UB_V3F"), Uint32::New(GL_T2F_C4UB_V3F), ReadOnly);

     Gl->Set(String::NewSymbol("T2F_C3F_V3F"), Uint32::New(GL_T2F_C3F_V3F), ReadOnly);

     Gl->Set(String::NewSymbol("T2F_N3F_V3F"), Uint32::New(GL_T2F_N3F_V3F), ReadOnly);

     Gl->Set(String::NewSymbol("T2F_C4F_N3F_V3F"), Uint32::New(GL_T2F_C4F_N3F_V3F), ReadOnly);

     Gl->Set(String::NewSymbol("T4F_C4F_N3F_V4F"), Uint32::New(GL_T4F_C4F_N3F_V4F), ReadOnly);

     Gl->Set(String::NewSymbol("BGR"), Uint32::New(GL_BGR), ReadOnly);

     Gl->Set(String::NewSymbol("BGRA"), Uint32::New(GL_BGRA), ReadOnly);

     Gl->Set(String::NewSymbol("CONSTANT_COLOR"), Uint32::New(GL_CONSTANT_COLOR), ReadOnly);

     Gl->Set(String::NewSymbol("ONE_MINUS_CONSTANT_COLOR"), Uint32::New(GL_ONE_MINUS_CONSTANT_COLOR), ReadOnly);

     Gl->Set(String::NewSymbol("CONSTANT_ALPHA"), Uint32::New(GL_CONSTANT_ALPHA), ReadOnly);

     Gl->Set(String::NewSymbol("ONE_MINUS_CONSTANT_ALPHA"), Uint32::New(GL_ONE_MINUS_CONSTANT_ALPHA), ReadOnly);

     Gl->Set(String::NewSymbol("BLEND_COLOR"), Uint32::New(GL_BLEND_COLOR), ReadOnly);

     Gl->Set(String::NewSymbol("FUNC_ADD"), Uint32::New(GL_FUNC_ADD), ReadOnly);

     Gl->Set(String::NewSymbol("MIN"), Uint32::New(GL_MIN), ReadOnly);

     Gl->Set(String::NewSymbol("MAX"), Uint32::New(GL_MAX), ReadOnly);

     Gl->Set(String::NewSymbol("FUNC_SUBTRACT"), Uint32::New(GL_FUNC_SUBTRACT), ReadOnly);

     Gl->Set(String::NewSymbol("FUNC_REVERSE_SUBTRACT"), Uint32::New(GL_FUNC_REVERSE_SUBTRACT), ReadOnly);

     Gl->Set(String::NewSymbol("COLOR_MATRIX"), Uint32::New(GL_COLOR_MATRIX), ReadOnly);

     Gl->Set(String::NewSymbol("COLOR_MATRIX_STACK_DEPTH"), Uint32::New(GL_COLOR_MATRIX_STACK_DEPTH), ReadOnly);

     Gl->Set(String::NewSymbol("MAX_COLOR_MATRIX_STACK_DEPTH"), Uint32::New(GL_MAX_COLOR_MATRIX_STACK_DEPTH), ReadOnly);

     Gl->Set(String::NewSymbol("POST_COLOR_MATRIX_RED_SCALE"), Uint32::New(GL_POST_COLOR_MATRIX_RED_SCALE), ReadOnly);

     Gl->Set(String::NewSymbol("POST_COLOR_MATRIX_GREEN_SCALE"), Uint32::New(GL_POST_COLOR_MATRIX_GREEN_SCALE), ReadOnly);

     Gl->Set(String::NewSymbol("POST_COLOR_MATRIX_BLUE_SCALE"), Uint32::New(GL_POST_COLOR_MATRIX_BLUE_SCALE), ReadOnly);

     Gl->Set(String::NewSymbol("POST_COLOR_MATRIX_ALPHA_SCALE"), Uint32::New(GL_POST_COLOR_MATRIX_ALPHA_SCALE), ReadOnly);

     Gl->Set(String::NewSymbol("POST_COLOR_MATRIX_RED_BIAS"), Uint32::New(GL_POST_COLOR_MATRIX_RED_BIAS), ReadOnly);

     Gl->Set(String::NewSymbol("POST_COLOR_MATRIX_GREEN_BIAS"), Uint32::New(GL_POST_COLOR_MATRIX_GREEN_BIAS), ReadOnly);

     Gl->Set(String::NewSymbol("POST_COLOR_MATRIX_BLUE_BIAS"), Uint32::New(GL_POST_COLOR_MATRIX_BLUE_BIAS), ReadOnly);

     Gl->Set(String::NewSymbol("POST_COLOR_MATRIX_ALPHA_BIAS"), Uint32::New(GL_POST_COLOR_MATRIX_ALPHA_BIAS), ReadOnly);

     Gl->Set(String::NewSymbol("COLOR_TABLE"), Uint32::New(GL_COLOR_TABLE), ReadOnly);

     Gl->Set(String::NewSymbol("POST_CONVOLUTION_COLOR_TABLE"), Uint32::New(GL_POST_CONVOLUTION_COLOR_TABLE), ReadOnly);

     Gl->Set(String::NewSymbol("POST_COLOR_MATRIX_COLOR_TABLE"), Uint32::New(GL_POST_COLOR_MATRIX_COLOR_TABLE), ReadOnly);

     Gl->Set(String::NewSymbol("PROXY_COLOR_TABLE"), Uint32::New(GL_PROXY_COLOR_TABLE), ReadOnly);

     Gl->Set(String::NewSymbol("PROXY_POST_CONVOLUTION_COLOR_TABLE"), Uint32::New(GL_PROXY_POST_CONVOLUTION_COLOR_TABLE), ReadOnly);

     Gl->Set(String::NewSymbol("PROXY_POST_COLOR_MATRIX_COLOR_TABLE"), Uint32::New(GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE), ReadOnly);

     Gl->Set(String::NewSymbol("COLOR_TABLE_SCALE"), Uint32::New(GL_COLOR_TABLE_SCALE), ReadOnly);

     Gl->Set(String::NewSymbol("COLOR_TABLE_BIAS"), Uint32::New(GL_COLOR_TABLE_BIAS), ReadOnly);

     Gl->Set(String::NewSymbol("COLOR_TABLE_FORMAT"), Uint32::New(GL_COLOR_TABLE_FORMAT), ReadOnly);

     Gl->Set(String::NewSymbol("COLOR_TABLE_WIDTH"), Uint32::New(GL_COLOR_TABLE_WIDTH), ReadOnly);

     Gl->Set(String::NewSymbol("COLOR_TABLE_RED_SIZE"), Uint32::New(GL_COLOR_TABLE_RED_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("COLOR_TABLE_GREEN_SIZE"), Uint32::New(GL_COLOR_TABLE_GREEN_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("COLOR_TABLE_BLUE_SIZE"), Uint32::New(GL_COLOR_TABLE_BLUE_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("COLOR_TABLE_ALPHA_SIZE"), Uint32::New(GL_COLOR_TABLE_ALPHA_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("COLOR_TABLE_LUMINANCE_SIZE"), Uint32::New(GL_COLOR_TABLE_LUMINANCE_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("COLOR_TABLE_INTENSITY_SIZE"), Uint32::New(GL_COLOR_TABLE_INTENSITY_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("CONVOLUTION_1D"), Uint32::New(GL_CONVOLUTION_1D), ReadOnly);

     Gl->Set(String::NewSymbol("CONVOLUTION_2D"), Uint32::New(GL_CONVOLUTION_2D), ReadOnly);

     Gl->Set(String::NewSymbol("SEPARABLE_2D"), Uint32::New(GL_SEPARABLE_2D), ReadOnly);

     Gl->Set(String::NewSymbol("CONVOLUTION_BORDER_MODE"), Uint32::New(GL_CONVOLUTION_BORDER_MODE), ReadOnly);

     Gl->Set(String::NewSymbol("CONVOLUTION_FILTER_SCALE"), Uint32::New(GL_CONVOLUTION_FILTER_SCALE), ReadOnly);

     Gl->Set(String::NewSymbol("CONVOLUTION_FILTER_BIAS"), Uint32::New(GL_CONVOLUTION_FILTER_BIAS), ReadOnly);

     Gl->Set(String::NewSymbol("REDUCE"), Uint32::New(GL_REDUCE), ReadOnly);

     Gl->Set(String::NewSymbol("CONVOLUTION_FORMAT"), Uint32::New(GL_CONVOLUTION_FORMAT), ReadOnly);

     Gl->Set(String::NewSymbol("CONVOLUTION_WIDTH"), Uint32::New(GL_CONVOLUTION_WIDTH), ReadOnly);

     Gl->Set(String::NewSymbol("CONVOLUTION_HEIGHT"), Uint32::New(GL_CONVOLUTION_HEIGHT), ReadOnly);

     Gl->Set(String::NewSymbol("MAX_CONVOLUTION_WIDTH"), Uint32::New(GL_MAX_CONVOLUTION_WIDTH), ReadOnly);

     Gl->Set(String::NewSymbol("MAX_CONVOLUTION_HEIGHT"), Uint32::New(GL_MAX_CONVOLUTION_HEIGHT), ReadOnly);

     Gl->Set(String::NewSymbol("POST_CONVOLUTION_RED_SCALE"), Uint32::New(GL_POST_CONVOLUTION_RED_SCALE), ReadOnly);

     Gl->Set(String::NewSymbol("POST_CONVOLUTION_GREEN_SCALE"), Uint32::New(GL_POST_CONVOLUTION_GREEN_SCALE), ReadOnly);

     Gl->Set(String::NewSymbol("POST_CONVOLUTION_BLUE_SCALE"), Uint32::New(GL_POST_CONVOLUTION_BLUE_SCALE), ReadOnly);

     Gl->Set(String::NewSymbol("POST_CONVOLUTION_ALPHA_SCALE"), Uint32::New(GL_POST_CONVOLUTION_ALPHA_SCALE), ReadOnly);

     Gl->Set(String::NewSymbol("POST_CONVOLUTION_RED_BIAS"), Uint32::New(GL_POST_CONVOLUTION_RED_BIAS), ReadOnly);

     Gl->Set(String::NewSymbol("POST_CONVOLUTION_GREEN_BIAS"), Uint32::New(GL_POST_CONVOLUTION_GREEN_BIAS), ReadOnly);

     Gl->Set(String::NewSymbol("POST_CONVOLUTION_BLUE_BIAS"), Uint32::New(GL_POST_CONVOLUTION_BLUE_BIAS), ReadOnly);

     Gl->Set(String::NewSymbol("POST_CONVOLUTION_ALPHA_BIAS"), Uint32::New(GL_POST_CONVOLUTION_ALPHA_BIAS), ReadOnly);

     Gl->Set(String::NewSymbol("CONSTANT_BORDER"), Uint32::New(GL_CONSTANT_BORDER), ReadOnly);

     Gl->Set(String::NewSymbol("REPLICATE_BORDER"), Uint32::New(GL_REPLICATE_BORDER), ReadOnly);

     Gl->Set(String::NewSymbol("CONVOLUTION_BORDER_COLOR"), Uint32::New(GL_CONVOLUTION_BORDER_COLOR), ReadOnly);

     Gl->Set(String::NewSymbol("MAX_ELEMENTS_VERTICES"), Uint32::New(GL_MAX_ELEMENTS_VERTICES), ReadOnly);

     Gl->Set(String::NewSymbol("MAX_ELEMENTS_INDICES"), Uint32::New(GL_MAX_ELEMENTS_INDICES), ReadOnly);

     Gl->Set(String::NewSymbol("HISTOGRAM"), Uint32::New(GL_HISTOGRAM), ReadOnly);

     Gl->Set(String::NewSymbol("PROXY_HISTOGRAM"), Uint32::New(GL_PROXY_HISTOGRAM), ReadOnly);

     Gl->Set(String::NewSymbol("HISTOGRAM_WIDTH"), Uint32::New(GL_HISTOGRAM_WIDTH), ReadOnly);

     Gl->Set(String::NewSymbol("HISTOGRAM_FORMAT"), Uint32::New(GL_HISTOGRAM_FORMAT), ReadOnly);

     Gl->Set(String::NewSymbol("HISTOGRAM_RED_SIZE"), Uint32::New(GL_HISTOGRAM_RED_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("HISTOGRAM_GREEN_SIZE"), Uint32::New(GL_HISTOGRAM_GREEN_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("HISTOGRAM_BLUE_SIZE"), Uint32::New(GL_HISTOGRAM_BLUE_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("HISTOGRAM_ALPHA_SIZE"), Uint32::New(GL_HISTOGRAM_ALPHA_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("HISTOGRAM_LUMINANCE_SIZE"), Uint32::New(GL_HISTOGRAM_LUMINANCE_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("HISTOGRAM_SINK"), Uint32::New(GL_HISTOGRAM_SINK), ReadOnly);

     Gl->Set(String::NewSymbol("MINMAX"), Uint32::New(GL_MINMAX), ReadOnly);

     Gl->Set(String::NewSymbol("MINMAX_FORMAT"), Uint32::New(GL_MINMAX_FORMAT), ReadOnly);

     Gl->Set(String::NewSymbol("MINMAX_SINK"), Uint32::New(GL_MINMAX_SINK), ReadOnly);

     Gl->Set(String::NewSymbol("TABLE_TOO_LARGE"), Uint32::New(GL_TABLE_TOO_LARGE), ReadOnly);

     Gl->Set(String::NewSymbol("UNSIGNED_BYTE_3_3_2"), Uint32::New(GL_UNSIGNED_BYTE_3_3_2), ReadOnly);

     Gl->Set(String::NewSymbol("UNSIGNED_SHORT_4_4_4_4"), Uint32::New(GL_UNSIGNED_SHORT_4_4_4_4), ReadOnly);

     Gl->Set(String::NewSymbol("UNSIGNED_SHORT_5_5_5_1"), Uint32::New(GL_UNSIGNED_SHORT_5_5_5_1), ReadOnly);

     Gl->Set(String::NewSymbol("UNSIGNED_INT_8_8_8_8"), Uint32::New(GL_UNSIGNED_INT_8_8_8_8), ReadOnly);

     Gl->Set(String::NewSymbol("UNSIGNED_INT_10_10_10_2"), Uint32::New(GL_UNSIGNED_INT_10_10_10_2), ReadOnly);

     Gl->Set(String::NewSymbol("UNSIGNED_BYTE_2_3_3_REV"), Uint32::New(GL_UNSIGNED_BYTE_2_3_3_REV), ReadOnly);

     Gl->Set(String::NewSymbol("UNSIGNED_SHORT_5_6_5"), Uint32::New(GL_UNSIGNED_SHORT_5_6_5), ReadOnly);

     Gl->Set(String::NewSymbol("UNSIGNED_SHORT_5_6_5_REV"), Uint32::New(GL_UNSIGNED_SHORT_5_6_5_REV), ReadOnly);

     Gl->Set(String::NewSymbol("UNSIGNED_SHORT_4_4_4_4_REV"), Uint32::New(GL_UNSIGNED_SHORT_4_4_4_4_REV), ReadOnly);

     Gl->Set(String::NewSymbol("UNSIGNED_SHORT_1_5_5_5_REV"), Uint32::New(GL_UNSIGNED_SHORT_1_5_5_5_REV), ReadOnly);

     Gl->Set(String::NewSymbol("UNSIGNED_INT_8_8_8_8_REV"), Uint32::New(GL_UNSIGNED_INT_8_8_8_8_REV), ReadOnly);

     Gl->Set(String::NewSymbol("UNSIGNED_INT_2_10_10_10_REV"), Uint32::New(GL_UNSIGNED_INT_2_10_10_10_REV), ReadOnly);

     Gl->Set(String::NewSymbol("RESCALE_NORMAL"), Uint32::New(GL_RESCALE_NORMAL), ReadOnly);

     Gl->Set(String::NewSymbol("LIGHT_MODEL_COLOR_CONTROL"), Uint32::New(GL_LIGHT_MODEL_COLOR_CONTROL), ReadOnly);

     Gl->Set(String::NewSymbol("SINGLE_COLOR"), Uint32::New(GL_SINGLE_COLOR), ReadOnly);

     Gl->Set(String::NewSymbol("SEPARATE_SPECULAR_COLOR"), Uint32::New(GL_SEPARATE_SPECULAR_COLOR), ReadOnly);

     Gl->Set(String::NewSymbol("PACK_SKIP_IMAGES"), Uint32::New(GL_PACK_SKIP_IMAGES), ReadOnly);

     Gl->Set(String::NewSymbol("PACK_IMAGE_HEIGHT"), Uint32::New(GL_PACK_IMAGE_HEIGHT), ReadOnly);

     Gl->Set(String::NewSymbol("UNPACK_SKIP_IMAGES"), Uint32::New(GL_UNPACK_SKIP_IMAGES), ReadOnly);

     Gl->Set(String::NewSymbol("UNPACK_IMAGE_HEIGHT"), Uint32::New(GL_UNPACK_IMAGE_HEIGHT), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_3D"), Uint32::New(GL_TEXTURE_3D), ReadOnly);

     Gl->Set(String::NewSymbol("PROXY_TEXTURE_3D"), Uint32::New(GL_PROXY_TEXTURE_3D), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_DEPTH"), Uint32::New(GL_TEXTURE_DEPTH), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_WRAP_R"), Uint32::New(GL_TEXTURE_WRAP_R), ReadOnly);

     Gl->Set(String::NewSymbol("MAX_3D_TEXTURE_SIZE"), Uint32::New(GL_MAX_3D_TEXTURE_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("CLAMP_TO_EDGE"), Uint32::New(GL_CLAMP_TO_EDGE), ReadOnly);

     Gl->Set(String::NewSymbol("CLAMP_TO_BORDER"), Uint32::New(GL_CLAMP_TO_BORDER), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_MIN_LOD"), Uint32::New(GL_TEXTURE_MIN_LOD), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_MAX_LOD"), Uint32::New(GL_TEXTURE_MAX_LOD), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_BASE_LEVEL"), Uint32::New(GL_TEXTURE_BASE_LEVEL), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_MAX_LEVEL"), Uint32::New(GL_TEXTURE_MAX_LEVEL), ReadOnly);

     Gl->Set(String::NewSymbol("SMOOTH_POINT_SIZE_RANGE"), Uint32::New(GL_SMOOTH_POINT_SIZE_RANGE), ReadOnly);

     Gl->Set(String::NewSymbol("SMOOTH_POINT_SIZE_GRANULARITY"), Uint32::New(GL_SMOOTH_POINT_SIZE_GRANULARITY), ReadOnly);

     Gl->Set(String::NewSymbol("SMOOTH_LINE_WIDTH_RANGE"), Uint32::New(GL_SMOOTH_LINE_WIDTH_RANGE), ReadOnly);

     Gl->Set(String::NewSymbol("SMOOTH_LINE_WIDTH_GRANULARITY"), Uint32::New(GL_SMOOTH_LINE_WIDTH_GRANULARITY), ReadOnly);

     Gl->Set(String::NewSymbol("ALIASED_POINT_SIZE_RANGE"), Uint32::New(GL_ALIASED_POINT_SIZE_RANGE), ReadOnly);

     Gl->Set(String::NewSymbol("ALIASED_LINE_WIDTH_RANGE"), Uint32::New(GL_ALIASED_LINE_WIDTH_RANGE), ReadOnly);

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

     Gl->Set(String::NewSymbol("CLIENT_ACTIVE_TEXTURE"), Uint32::New(GL_CLIENT_ACTIVE_TEXTURE), ReadOnly);

     Gl->Set(String::NewSymbol("MAX_TEXTURE_UNITS"), Uint32::New(GL_MAX_TEXTURE_UNITS), ReadOnly);

     Gl->Set(String::NewSymbol("COMBINE"), Uint32::New(GL_COMBINE), ReadOnly);

     Gl->Set(String::NewSymbol("COMBINE_RGB"), Uint32::New(GL_COMBINE_RGB), ReadOnly);

     Gl->Set(String::NewSymbol("COMBINE_ALPHA"), Uint32::New(GL_COMBINE_ALPHA), ReadOnly);

     Gl->Set(String::NewSymbol("RGB_SCALE"), Uint32::New(GL_RGB_SCALE), ReadOnly);

     Gl->Set(String::NewSymbol("ADD_SIGNED"), Uint32::New(GL_ADD_SIGNED), ReadOnly);

     Gl->Set(String::NewSymbol("INTERPOLATE"), Uint32::New(GL_INTERPOLATE), ReadOnly);

     Gl->Set(String::NewSymbol("CONSTANT"), Uint32::New(GL_CONSTANT), ReadOnly);

     Gl->Set(String::NewSymbol("PRIMARY_COLOR"), Uint32::New(GL_PRIMARY_COLOR), ReadOnly);

     Gl->Set(String::NewSymbol("PREVIOUS"), Uint32::New(GL_PREVIOUS), ReadOnly);

     Gl->Set(String::NewSymbol("SUBTRACT"), Uint32::New(GL_SUBTRACT), ReadOnly);

     Gl->Set(String::NewSymbol("SRC0_RGB"), Uint32::New(GL_SRC0_RGB), ReadOnly);

     Gl->Set(String::NewSymbol("SRC1_RGB"), Uint32::New(GL_SRC1_RGB), ReadOnly);

     Gl->Set(String::NewSymbol("SRC2_RGB"), Uint32::New(GL_SRC2_RGB), ReadOnly);

     Gl->Set(String::NewSymbol("SRC0_ALPHA"), Uint32::New(GL_SRC0_ALPHA), ReadOnly);

     Gl->Set(String::NewSymbol("SRC1_ALPHA"), Uint32::New(GL_SRC1_ALPHA), ReadOnly);

     Gl->Set(String::NewSymbol("SRC2_ALPHA"), Uint32::New(GL_SRC2_ALPHA), ReadOnly);

     Gl->Set(String::NewSymbol("SOURCE0_RGB"), Uint32::New(GL_SOURCE0_RGB), ReadOnly);

     Gl->Set(String::NewSymbol("SOURCE1_RGB"), Uint32::New(GL_SOURCE1_RGB), ReadOnly);

     Gl->Set(String::NewSymbol("SOURCE2_RGB"), Uint32::New(GL_SOURCE2_RGB), ReadOnly);

     Gl->Set(String::NewSymbol("SOURCE0_ALPHA"), Uint32::New(GL_SOURCE0_ALPHA), ReadOnly);

     Gl->Set(String::NewSymbol("SOURCE1_ALPHA"), Uint32::New(GL_SOURCE1_ALPHA), ReadOnly);

     Gl->Set(String::NewSymbol("SOURCE2_ALPHA"), Uint32::New(GL_SOURCE2_ALPHA), ReadOnly);

     Gl->Set(String::NewSymbol("OPERAND0_RGB"), Uint32::New(GL_OPERAND0_RGB), ReadOnly);

     Gl->Set(String::NewSymbol("OPERAND1_RGB"), Uint32::New(GL_OPERAND1_RGB), ReadOnly);

     Gl->Set(String::NewSymbol("OPERAND2_RGB"), Uint32::New(GL_OPERAND2_RGB), ReadOnly);

     Gl->Set(String::NewSymbol("OPERAND0_ALPHA"), Uint32::New(GL_OPERAND0_ALPHA), ReadOnly);

     Gl->Set(String::NewSymbol("OPERAND1_ALPHA"), Uint32::New(GL_OPERAND1_ALPHA), ReadOnly);

     Gl->Set(String::NewSymbol("OPERAND2_ALPHA"), Uint32::New(GL_OPERAND2_ALPHA), ReadOnly);

     Gl->Set(String::NewSymbol("DOT3_RGB"), Uint32::New(GL_DOT3_RGB), ReadOnly);

     Gl->Set(String::NewSymbol("DOT3_RGBA"), Uint32::New(GL_DOT3_RGBA), ReadOnly);

     Gl->Set(String::NewSymbol("TRANSPOSE_MODELVIEW_MATRIX"), Uint32::New(GL_TRANSPOSE_MODELVIEW_MATRIX), ReadOnly);

     Gl->Set(String::NewSymbol("TRANSPOSE_PROJECTION_MATRIX"), Uint32::New(GL_TRANSPOSE_PROJECTION_MATRIX), ReadOnly);

     Gl->Set(String::NewSymbol("TRANSPOSE_TEXTURE_MATRIX"), Uint32::New(GL_TRANSPOSE_TEXTURE_MATRIX), ReadOnly);

     Gl->Set(String::NewSymbol("TRANSPOSE_COLOR_MATRIX"), Uint32::New(GL_TRANSPOSE_COLOR_MATRIX), ReadOnly);

     Gl->Set(String::NewSymbol("NORMAL_MAP"), Uint32::New(GL_NORMAL_MAP), ReadOnly);

     Gl->Set(String::NewSymbol("REFLECTION_MAP"), Uint32::New(GL_REFLECTION_MAP), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_CUBE_MAP"), Uint32::New(GL_TEXTURE_CUBE_MAP), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_BINDING_CUBE_MAP"), Uint32::New(GL_TEXTURE_BINDING_CUBE_MAP), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_CUBE_MAP_POSITIVE_X"), Uint32::New(GL_TEXTURE_CUBE_MAP_POSITIVE_X), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_CUBE_MAP_POSITIVE_Y"), Uint32::New(GL_TEXTURE_CUBE_MAP_POSITIVE_Y), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_CUBE_MAP_POSITIVE_Z"), Uint32::New(GL_TEXTURE_CUBE_MAP_POSITIVE_Z), ReadOnly);

     Gl->Set(String::NewSymbol("PROXY_TEXTURE_CUBE_MAP"), Uint32::New(GL_PROXY_TEXTURE_CUBE_MAP), ReadOnly);

     Gl->Set(String::NewSymbol("MAX_CUBE_MAP_TEXTURE_SIZE"), Uint32::New(GL_MAX_CUBE_MAP_TEXTURE_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("COMPRESSED_ALPHA"), Uint32::New(GL_COMPRESSED_ALPHA), ReadOnly);

     Gl->Set(String::NewSymbol("COMPRESSED_LUMINANCE"), Uint32::New(GL_COMPRESSED_LUMINANCE), ReadOnly);

     Gl->Set(String::NewSymbol("COMPRESSED_LUMINANCE_ALPHA"), Uint32::New(GL_COMPRESSED_LUMINANCE_ALPHA), ReadOnly);

     Gl->Set(String::NewSymbol("COMPRESSED_INTENSITY"), Uint32::New(GL_COMPRESSED_INTENSITY), ReadOnly);

     Gl->Set(String::NewSymbol("COMPRESSED_RGB"), Uint32::New(GL_COMPRESSED_RGB), ReadOnly);

     Gl->Set(String::NewSymbol("COMPRESSED_RGBA"), Uint32::New(GL_COMPRESSED_RGBA), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_COMPRESSION_HINT"), Uint32::New(GL_TEXTURE_COMPRESSION_HINT), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_COMPRESSED_IMAGE_SIZE"), Uint32::New(GL_TEXTURE_COMPRESSED_IMAGE_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_COMPRESSED"), Uint32::New(GL_TEXTURE_COMPRESSED), ReadOnly);

     Gl->Set(String::NewSymbol("NUM_COMPRESSED_TEXTURE_FORMATS"), Uint32::New(GL_NUM_COMPRESSED_TEXTURE_FORMATS), ReadOnly);

     Gl->Set(String::NewSymbol("COMPRESSED_TEXTURE_FORMATS"), Uint32::New(GL_COMPRESSED_TEXTURE_FORMATS), ReadOnly);

     Gl->Set(String::NewSymbol("MULTISAMPLE"), Uint32::New(GL_MULTISAMPLE), ReadOnly);

     Gl->Set(String::NewSymbol("SAMPLE_ALPHA_TO_COVERAGE"), Uint32::New(GL_SAMPLE_ALPHA_TO_COVERAGE), ReadOnly);

     Gl->Set(String::NewSymbol("SAMPLE_ALPHA_TO_ONE"), Uint32::New(GL_SAMPLE_ALPHA_TO_ONE), ReadOnly);

     Gl->Set(String::NewSymbol("SAMPLE_COVERAGE"), Uint32::New(GL_SAMPLE_COVERAGE), ReadOnly);

     Gl->Set(String::NewSymbol("SAMPLE_BUFFERS"), Uint32::New(GL_SAMPLE_BUFFERS), ReadOnly);

     Gl->Set(String::NewSymbol("SAMPLES"), Uint32::New(GL_SAMPLES), ReadOnly);

     Gl->Set(String::NewSymbol("SAMPLE_COVERAGE_VALUE"), Uint32::New(GL_SAMPLE_COVERAGE_VALUE), ReadOnly);

     Gl->Set(String::NewSymbol("SAMPLE_COVERAGE_INVERT"), Uint32::New(GL_SAMPLE_COVERAGE_INVERT), ReadOnly);

     Gl->Set(String::NewSymbol("MULTISAMPLE_BIT"), Uint32::New(GL_MULTISAMPLE_BIT), ReadOnly);

     Gl->Set(String::NewSymbol("DEPTH_COMPONENT16"), Uint32::New(GL_DEPTH_COMPONENT16), ReadOnly);

     Gl->Set(String::NewSymbol("DEPTH_COMPONENT24"), Uint32::New(GL_DEPTH_COMPONENT24), ReadOnly);

     Gl->Set(String::NewSymbol("DEPTH_COMPONENT32"), Uint32::New(GL_DEPTH_COMPONENT32), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_DEPTH_SIZE"), Uint32::New(GL_TEXTURE_DEPTH_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("DEPTH_TEXTURE_MODE"), Uint32::New(GL_DEPTH_TEXTURE_MODE), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_COMPARE_MODE"), Uint32::New(GL_TEXTURE_COMPARE_MODE), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_COMPARE_FUNC"), Uint32::New(GL_TEXTURE_COMPARE_FUNC), ReadOnly);

     Gl->Set(String::NewSymbol("COMPARE_R_TO_TEXTURE"), Uint32::New(GL_COMPARE_R_TO_TEXTURE), ReadOnly);

     Gl->Set(String::NewSymbol("QUERY_COUNTER_BITS"), Uint32::New(GL_QUERY_COUNTER_BITS), ReadOnly);

     Gl->Set(String::NewSymbol("CURRENT_QUERY"), Uint32::New(GL_CURRENT_QUERY), ReadOnly);

     Gl->Set(String::NewSymbol("QUERY_RESULT"), Uint32::New(GL_QUERY_RESULT), ReadOnly);

     Gl->Set(String::NewSymbol("QUERY_RESULT_AVAILABLE"), Uint32::New(GL_QUERY_RESULT_AVAILABLE), ReadOnly);

     Gl->Set(String::NewSymbol("SAMPLES_PASSED"), Uint32::New(GL_SAMPLES_PASSED), ReadOnly);

     Gl->Set(String::NewSymbol("FOG_COORD_SRC"), Uint32::New(GL_FOG_COORD_SRC), ReadOnly);

     Gl->Set(String::NewSymbol("FOG_COORD"), Uint32::New(GL_FOG_COORD), ReadOnly);

     Gl->Set(String::NewSymbol("FRAGMENT_DEPTH"), Uint32::New(GL_FRAGMENT_DEPTH), ReadOnly);

     Gl->Set(String::NewSymbol("CURRENT_FOG_COORD"), Uint32::New(GL_CURRENT_FOG_COORD), ReadOnly);

     Gl->Set(String::NewSymbol("FOG_COORD_ARRAY_TYPE"), Uint32::New(GL_FOG_COORD_ARRAY_TYPE), ReadOnly);

     Gl->Set(String::NewSymbol("FOG_COORD_ARRAY_STRIDE"), Uint32::New(GL_FOG_COORD_ARRAY_STRIDE), ReadOnly);

     Gl->Set(String::NewSymbol("FOG_COORD_ARRAY_POINTER"), Uint32::New(GL_FOG_COORD_ARRAY_POINTER), ReadOnly);

     Gl->Set(String::NewSymbol("FOG_COORD_ARRAY"), Uint32::New(GL_FOG_COORD_ARRAY), ReadOnly);

     Gl->Set(String::NewSymbol("FOG_COORDINATE_SOURCE"), Uint32::New(GL_FOG_COORDINATE_SOURCE), ReadOnly);

     Gl->Set(String::NewSymbol("FOG_COORDINATE"), Uint32::New(GL_FOG_COORDINATE), ReadOnly);

     Gl->Set(String::NewSymbol("CURRENT_FOG_COORDINATE"), Uint32::New(GL_CURRENT_FOG_COORDINATE), ReadOnly);

     Gl->Set(String::NewSymbol("FOG_COORDINATE_ARRAY_TYPE"), Uint32::New(GL_FOG_COORDINATE_ARRAY_TYPE), ReadOnly);

     Gl->Set(String::NewSymbol("FOG_COORDINATE_ARRAY_STRIDE"), Uint32::New(GL_FOG_COORDINATE_ARRAY_STRIDE), ReadOnly);

     Gl->Set(String::NewSymbol("FOG_COORDINATE_ARRAY_POINTER"), Uint32::New(GL_FOG_COORDINATE_ARRAY_POINTER), ReadOnly);

     Gl->Set(String::NewSymbol("FOG_COORDINATE_ARRAY"), Uint32::New(GL_FOG_COORDINATE_ARRAY), ReadOnly);

     Gl->Set(String::NewSymbol("COLOR_SUM"), Uint32::New(GL_COLOR_SUM), ReadOnly);

     Gl->Set(String::NewSymbol("CURRENT_SECONDARY_COLOR"), Uint32::New(GL_CURRENT_SECONDARY_COLOR), ReadOnly);

     Gl->Set(String::NewSymbol("SECONDARY_COLOR_ARRAY_SIZE"), Uint32::New(GL_SECONDARY_COLOR_ARRAY_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("SECONDARY_COLOR_ARRAY_TYPE"), Uint32::New(GL_SECONDARY_COLOR_ARRAY_TYPE), ReadOnly);

     Gl->Set(String::NewSymbol("SECONDARY_COLOR_ARRAY_STRIDE"), Uint32::New(GL_SECONDARY_COLOR_ARRAY_STRIDE), ReadOnly);

     Gl->Set(String::NewSymbol("SECONDARY_COLOR_ARRAY_POINTER"), Uint32::New(GL_SECONDARY_COLOR_ARRAY_POINTER), ReadOnly);

     Gl->Set(String::NewSymbol("SECONDARY_COLOR_ARRAY"), Uint32::New(GL_SECONDARY_COLOR_ARRAY), ReadOnly);

     Gl->Set(String::NewSymbol("POINT_SIZE_MIN"), Uint32::New(GL_POINT_SIZE_MIN), ReadOnly);

     Gl->Set(String::NewSymbol("POINT_SIZE_MAX"), Uint32::New(GL_POINT_SIZE_MAX), ReadOnly);

     Gl->Set(String::NewSymbol("POINT_FADE_THRESHOLD_SIZE"), Uint32::New(GL_POINT_FADE_THRESHOLD_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("BLEND_DST_RGB"), Uint32::New(GL_BLEND_DST_RGB), ReadOnly);

     Gl->Set(String::NewSymbol("BLEND_SRC_RGB"), Uint32::New(GL_BLEND_SRC_RGB), ReadOnly);

     Gl->Set(String::NewSymbol("BLEND_DST_ALPHA"), Uint32::New(GL_BLEND_DST_ALPHA), ReadOnly);

     Gl->Set(String::NewSymbol("BLEND_SRC_ALPHA"), Uint32::New(GL_BLEND_SRC_ALPHA), ReadOnly);

     Gl->Set(String::NewSymbol("GENERATE_MIPMAP"), Uint32::New(GL_GENERATE_MIPMAP), ReadOnly);

     Gl->Set(String::NewSymbol("GENERATE_MIPMAP_HINT"), Uint32::New(GL_GENERATE_MIPMAP_HINT), ReadOnly);

     Gl->Set(String::NewSymbol("INCR_WRAP"), Uint32::New(GL_INCR_WRAP), ReadOnly);

     Gl->Set(String::NewSymbol("DECR_WRAP"), Uint32::New(GL_DECR_WRAP), ReadOnly);

     Gl->Set(String::NewSymbol("MIRRORED_REPEAT"), Uint32::New(GL_MIRRORED_REPEAT), ReadOnly);

     Gl->Set(String::NewSymbol("MAX_TEXTURE_LOD_BIAS"), Uint32::New(GL_MAX_TEXTURE_LOD_BIAS), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_FILTER_CONTROL"), Uint32::New(GL_TEXTURE_FILTER_CONTROL), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_LOD_BIAS"), Uint32::New(GL_TEXTURE_LOD_BIAS), ReadOnly);

     Gl->Set(String::NewSymbol("ARRAY_BUFFER"), Uint32::New(GL_ARRAY_BUFFER), ReadOnly);

     Gl->Set(String::NewSymbol("ELEMENT_ARRAY_BUFFER"), Uint32::New(GL_ELEMENT_ARRAY_BUFFER), ReadOnly);

     Gl->Set(String::NewSymbol("ARRAY_BUFFER_BINDING"), Uint32::New(GL_ARRAY_BUFFER_BINDING), ReadOnly);

     Gl->Set(String::NewSymbol("ELEMENT_ARRAY_BUFFER_BINDING"), Uint32::New(GL_ELEMENT_ARRAY_BUFFER_BINDING), ReadOnly);

     Gl->Set(String::NewSymbol("VERTEX_ARRAY_BUFFER_BINDING"), Uint32::New(GL_VERTEX_ARRAY_BUFFER_BINDING), ReadOnly);

     Gl->Set(String::NewSymbol("NORMAL_ARRAY_BUFFER_BINDING"), Uint32::New(GL_NORMAL_ARRAY_BUFFER_BINDING), ReadOnly);

     Gl->Set(String::NewSymbol("COLOR_ARRAY_BUFFER_BINDING"), Uint32::New(GL_COLOR_ARRAY_BUFFER_BINDING), ReadOnly);

     Gl->Set(String::NewSymbol("INDEX_ARRAY_BUFFER_BINDING"), Uint32::New(GL_INDEX_ARRAY_BUFFER_BINDING), ReadOnly);

     Gl->Set(String::NewSymbol("TEXTURE_COORD_ARRAY_BUFFER_BINDING"), Uint32::New(GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING), ReadOnly);

     Gl->Set(String::NewSymbol("EDGE_FLAG_ARRAY_BUFFER_BINDING"), Uint32::New(GL_EDGE_FLAG_ARRAY_BUFFER_BINDING), ReadOnly);

     Gl->Set(String::NewSymbol("SECONDARY_COLOR_ARRAY_BUFFER_BINDING"), Uint32::New(GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING), ReadOnly);

     Gl->Set(String::NewSymbol("FOG_COORD_ARRAY_BUFFER_BINDING"), Uint32::New(GL_FOG_COORD_ARRAY_BUFFER_BINDING), ReadOnly);

     Gl->Set(String::NewSymbol("WEIGHT_ARRAY_BUFFER_BINDING"), Uint32::New(GL_WEIGHT_ARRAY_BUFFER_BINDING), ReadOnly);

     Gl->Set(String::NewSymbol("VERTEX_ATTRIB_ARRAY_BUFFER_BINDING"), Uint32::New(GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING), ReadOnly);

     Gl->Set(String::NewSymbol("STREAM_DRAW"), Uint32::New(GL_STREAM_DRAW), ReadOnly);

     Gl->Set(String::NewSymbol("STREAM_READ"), Uint32::New(GL_STREAM_READ), ReadOnly);

     Gl->Set(String::NewSymbol("STREAM_COPY"), Uint32::New(GL_STREAM_COPY), ReadOnly);

     Gl->Set(String::NewSymbol("DYNAMIC_DRAW"), Uint32::New(GL_DYNAMIC_DRAW), ReadOnly);

     Gl->Set(String::NewSymbol("DYNAMIC_READ"), Uint32::New(GL_DYNAMIC_READ), ReadOnly);

     Gl->Set(String::NewSymbol("DYNAMIC_COPY"), Uint32::New(GL_DYNAMIC_COPY), ReadOnly);

     Gl->Set(String::NewSymbol("READ_ONLY"), Uint32::New(GL_READ_ONLY), ReadOnly);

     Gl->Set(String::NewSymbol("WRITE_ONLY"), Uint32::New(GL_WRITE_ONLY), ReadOnly);

     Gl->Set(String::NewSymbol("READ_WRITE"), Uint32::New(GL_READ_WRITE), ReadOnly);

     Gl->Set(String::NewSymbol("BUFFER_SIZE"), Uint32::New(GL_BUFFER_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("BUFFER_USAGE"), Uint32::New(GL_BUFFER_USAGE), ReadOnly);

     Gl->Set(String::NewSymbol("BUFFER_ACCESS"), Uint32::New(GL_BUFFER_ACCESS), ReadOnly);

     Gl->Set(String::NewSymbol("BUFFER_MAPPED"), Uint32::New(GL_BUFFER_MAPPED), ReadOnly);

     Gl->Set(String::NewSymbol("BUFFER_MAP_POINTER"), Uint32::New(GL_BUFFER_MAP_POINTER), ReadOnly);

     Gl->Set(String::NewSymbol("FOG_COORDINATE_ARRAY_BUFFER_BINDING"), Uint32::New(GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING), ReadOnly);

     Gl->Set(String::NewSymbol("CURRENT_PROGRAM"), Uint32::New(GL_CURRENT_PROGRAM), ReadOnly);

     Gl->Set(String::NewSymbol("SHADER_TYPE"), Uint32::New(GL_SHADER_TYPE), ReadOnly);

     Gl->Set(String::NewSymbol("DELETE_STATUS"), Uint32::New(GL_DELETE_STATUS), ReadOnly);

     Gl->Set(String::NewSymbol("COMPILE_STATUS"), Uint32::New(GL_COMPILE_STATUS), ReadOnly);

     Gl->Set(String::NewSymbol("LINK_STATUS"), Uint32::New(GL_LINK_STATUS), ReadOnly);

     Gl->Set(String::NewSymbol("VALIDATE_STATUS"), Uint32::New(GL_VALIDATE_STATUS), ReadOnly);

     Gl->Set(String::NewSymbol("INFO_LOG_LENGTH"), Uint32::New(GL_INFO_LOG_LENGTH), ReadOnly);

     Gl->Set(String::NewSymbol("ATTACHED_SHADERS"), Uint32::New(GL_ATTACHED_SHADERS), ReadOnly);

     Gl->Set(String::NewSymbol("ACTIVE_UNIFORMS"), Uint32::New(GL_ACTIVE_UNIFORMS), ReadOnly);

     Gl->Set(String::NewSymbol("ACTIVE_UNIFORM_MAX_LENGTH"), Uint32::New(GL_ACTIVE_UNIFORM_MAX_LENGTH), ReadOnly);

     Gl->Set(String::NewSymbol("SHADER_SOURCE_LENGTH"), Uint32::New(GL_SHADER_SOURCE_LENGTH), ReadOnly);

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

     Gl->Set(String::NewSymbol("SAMPLER_1D"), Uint32::New(GL_SAMPLER_1D), ReadOnly);

     Gl->Set(String::NewSymbol("SAMPLER_2D"), Uint32::New(GL_SAMPLER_2D), ReadOnly);

     Gl->Set(String::NewSymbol("SAMPLER_3D"), Uint32::New(GL_SAMPLER_3D), ReadOnly);

     Gl->Set(String::NewSymbol("SAMPLER_CUBE"), Uint32::New(GL_SAMPLER_CUBE), ReadOnly);

     Gl->Set(String::NewSymbol("SAMPLER_1D_SHADOW"), Uint32::New(GL_SAMPLER_1D_SHADOW), ReadOnly);

     Gl->Set(String::NewSymbol("SAMPLER_2D_SHADOW"), Uint32::New(GL_SAMPLER_2D_SHADOW), ReadOnly);

     Gl->Set(String::NewSymbol("SHADING_LANGUAGE_VERSION"), Uint32::New(GL_SHADING_LANGUAGE_VERSION), ReadOnly);

     Gl->Set(String::NewSymbol("VERTEX_SHADER"), Uint32::New(GL_VERTEX_SHADER), ReadOnly);

     Gl->Set(String::NewSymbol("MAX_VERTEX_UNIFORM_COMPONENTS"), Uint32::New(GL_MAX_VERTEX_UNIFORM_COMPONENTS), ReadOnly);

     Gl->Set(String::NewSymbol("MAX_VARYING_FLOATS"), Uint32::New(GL_MAX_VARYING_FLOATS), ReadOnly);

     Gl->Set(String::NewSymbol("MAX_VERTEX_TEXTURE_IMAGE_UNITS"), Uint32::New(GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS), ReadOnly);

     Gl->Set(String::NewSymbol("MAX_COMBINED_TEXTURE_IMAGE_UNITS"), Uint32::New(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS), ReadOnly);

     Gl->Set(String::NewSymbol("ACTIVE_ATTRIBUTES"), Uint32::New(GL_ACTIVE_ATTRIBUTES), ReadOnly);

     Gl->Set(String::NewSymbol("ACTIVE_ATTRIBUTE_MAX_LENGTH"), Uint32::New(GL_ACTIVE_ATTRIBUTE_MAX_LENGTH), ReadOnly);

     Gl->Set(String::NewSymbol("FRAGMENT_SHADER"), Uint32::New(GL_FRAGMENT_SHADER), ReadOnly);

     Gl->Set(String::NewSymbol("MAX_FRAGMENT_UNIFORM_COMPONENTS"), Uint32::New(GL_MAX_FRAGMENT_UNIFORM_COMPONENTS), ReadOnly);

     Gl->Set(String::NewSymbol("MAX_VERTEX_ATTRIBS"), Uint32::New(GL_MAX_VERTEX_ATTRIBS), ReadOnly);

     Gl->Set(String::NewSymbol("VERTEX_ATTRIB_ARRAY_ENABLED"), Uint32::New(GL_VERTEX_ATTRIB_ARRAY_ENABLED), ReadOnly);

     Gl->Set(String::NewSymbol("VERTEX_ATTRIB_ARRAY_SIZE"), Uint32::New(GL_VERTEX_ATTRIB_ARRAY_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("VERTEX_ATTRIB_ARRAY_STRIDE"), Uint32::New(GL_VERTEX_ATTRIB_ARRAY_STRIDE), ReadOnly);

     Gl->Set(String::NewSymbol("VERTEX_ATTRIB_ARRAY_TYPE"), Uint32::New(GL_VERTEX_ATTRIB_ARRAY_TYPE), ReadOnly);

     Gl->Set(String::NewSymbol("VERTEX_ATTRIB_ARRAY_NORMALIZED"), Uint32::New(GL_VERTEX_ATTRIB_ARRAY_NORMALIZED), ReadOnly);

     Gl->Set(String::NewSymbol("CURRENT_VERTEX_ATTRIB"), Uint32::New(GL_CURRENT_VERTEX_ATTRIB), ReadOnly);

     Gl->Set(String::NewSymbol("VERTEX_ATTRIB_ARRAY_POINTER"), Uint32::New(GL_VERTEX_ATTRIB_ARRAY_POINTER), ReadOnly);

     Gl->Set(String::NewSymbol("VERTEX_PROGRAM_POINT_SIZE"), Uint32::New(GL_VERTEX_PROGRAM_POINT_SIZE), ReadOnly);

     Gl->Set(String::NewSymbol("VERTEX_PROGRAM_TWO_SIDE"), Uint32::New(GL_VERTEX_PROGRAM_TWO_SIDE), ReadOnly);

     Gl->Set(String::NewSymbol("MAX_TEXTURE_COORDS"), Uint32::New(GL_MAX_TEXTURE_COORDS), ReadOnly);

     Gl->Set(String::NewSymbol("MAX_TEXTURE_IMAGE_UNITS"), Uint32::New(GL_MAX_TEXTURE_IMAGE_UNITS), ReadOnly);

     Gl->Set(String::NewSymbol("MAX_DRAW_BUFFERS"), Uint32::New(GL_MAX_DRAW_BUFFERS), ReadOnly);

     Gl->Set(String::NewSymbol("DRAW_BUFFER0"), Uint32::New(GL_DRAW_BUFFER0), ReadOnly);

     Gl->Set(String::NewSymbol("DRAW_BUFFER1"), Uint32::New(GL_DRAW_BUFFER1), ReadOnly);

     Gl->Set(String::NewSymbol("DRAW_BUFFER2"), Uint32::New(GL_DRAW_BUFFER2), ReadOnly);

     Gl->Set(String::NewSymbol("DRAW_BUFFER3"), Uint32::New(GL_DRAW_BUFFER3), ReadOnly);

     Gl->Set(String::NewSymbol("DRAW_BUFFER4"), Uint32::New(GL_DRAW_BUFFER4), ReadOnly);

     Gl->Set(String::NewSymbol("DRAW_BUFFER5"), Uint32::New(GL_DRAW_BUFFER5), ReadOnly);

     Gl->Set(String::NewSymbol("DRAW_BUFFER6"), Uint32::New(GL_DRAW_BUFFER6), ReadOnly);

     Gl->Set(String::NewSymbol("DRAW_BUFFER7"), Uint32::New(GL_DRAW_BUFFER7), ReadOnly);

     Gl->Set(String::NewSymbol("DRAW_BUFFER8"), Uint32::New(GL_DRAW_BUFFER8), ReadOnly);

     Gl->Set(String::NewSymbol("DRAW_BUFFER9"), Uint32::New(GL_DRAW_BUFFER9), ReadOnly);

     Gl->Set(String::NewSymbol("DRAW_BUFFER10"), Uint32::New(GL_DRAW_BUFFER10), ReadOnly);

     Gl->Set(String::NewSymbol("DRAW_BUFFER11"), Uint32::New(GL_DRAW_BUFFER11), ReadOnly);

     Gl->Set(String::NewSymbol("DRAW_BUFFER12"), Uint32::New(GL_DRAW_BUFFER12), ReadOnly);

     Gl->Set(String::NewSymbol("DRAW_BUFFER13"), Uint32::New(GL_DRAW_BUFFER13), ReadOnly);

     Gl->Set(String::NewSymbol("DRAW_BUFFER14"), Uint32::New(GL_DRAW_BUFFER14), ReadOnly);

     Gl->Set(String::NewSymbol("DRAW_BUFFER15"), Uint32::New(GL_DRAW_BUFFER15), ReadOnly);

     Gl->Set(String::NewSymbol("POINT_SPRITE"), Uint32::New(GL_POINT_SPRITE), ReadOnly);

     Gl->Set(String::NewSymbol("COORD_REPLACE"), Uint32::New(GL_COORD_REPLACE), ReadOnly);

     Gl->Set(String::NewSymbol("POINT_SPRITE_COORD_ORIGIN"), Uint32::New(GL_POINT_SPRITE_COORD_ORIGIN), ReadOnly);

     Gl->Set(String::NewSymbol("LOWER_LEFT"), Uint32::New(GL_LOWER_LEFT), ReadOnly);

     Gl->Set(String::NewSymbol("UPPER_LEFT"), Uint32::New(GL_UPPER_LEFT), ReadOnly);

     Gl->Set(String::NewSymbol("STENCIL_BACK_FUNC"), Uint32::New(GL_STENCIL_BACK_FUNC), ReadOnly);

     Gl->Set(String::NewSymbol("STENCIL_BACK_VALUE_MASK"), Uint32::New(GL_STENCIL_BACK_VALUE_MASK), ReadOnly);

     Gl->Set(String::NewSymbol("STENCIL_BACK_REF"), Uint32::New(GL_STENCIL_BACK_REF), ReadOnly);

     Gl->Set(String::NewSymbol("STENCIL_BACK_FAIL"), Uint32::New(GL_STENCIL_BACK_FAIL), ReadOnly);

     Gl->Set(String::NewSymbol("STENCIL_BACK_PASS_DEPTH_FAIL"), Uint32::New(GL_STENCIL_BACK_PASS_DEPTH_FAIL), ReadOnly);

     Gl->Set(String::NewSymbol("STENCIL_BACK_PASS_DEPTH_PASS"), Uint32::New(GL_STENCIL_BACK_PASS_DEPTH_PASS), ReadOnly);

     Gl->Set(String::NewSymbol("STENCIL_BACK_WRITEMASK"), Uint32::New(GL_STENCIL_BACK_WRITEMASK), ReadOnly);

     Gl->Set(String::NewSymbol("CURRENT_RASTER_SECONDARY_COLOR"), Uint32::New(GL_CURRENT_RASTER_SECONDARY_COLOR), ReadOnly);

     Gl->Set(String::NewSymbol("PIXEL_PACK_BUFFER"), Uint32::New(GL_PIXEL_PACK_BUFFER), ReadOnly);

     Gl->Set(String::NewSymbol("PIXEL_UNPACK_BUFFER"), Uint32::New(GL_PIXEL_UNPACK_BUFFER), ReadOnly);

     Gl->Set(String::NewSymbol("PIXEL_PACK_BUFFER_BINDING"), Uint32::New(GL_PIXEL_PACK_BUFFER_BINDING), ReadOnly);

     Gl->Set(String::NewSymbol("PIXEL_UNPACK_BUFFER_BINDING"), Uint32::New(GL_PIXEL_UNPACK_BUFFER_BINDING), ReadOnly);

     Gl->Set(String::NewSymbol("FLOAT_MAT2x3"), Uint32::New(GL_FLOAT_MAT2x3), ReadOnly);

     Gl->Set(String::NewSymbol("FLOAT_MAT2x4"), Uint32::New(GL_FLOAT_MAT2x4), ReadOnly);

     Gl->Set(String::NewSymbol("FLOAT_MAT3x2"), Uint32::New(GL_FLOAT_MAT3x2), ReadOnly);

     Gl->Set(String::NewSymbol("FLOAT_MAT3x4"), Uint32::New(GL_FLOAT_MAT3x4), ReadOnly);

     Gl->Set(String::NewSymbol("FLOAT_MAT4x2"), Uint32::New(GL_FLOAT_MAT4x2), ReadOnly);

     Gl->Set(String::NewSymbol("FLOAT_MAT4x3"), Uint32::New(GL_FLOAT_MAT4x3), ReadOnly);

     Gl->Set(String::NewSymbol("SRGB"), Uint32::New(GL_SRGB), ReadOnly);

     Gl->Set(String::NewSymbol("SRGB8"), Uint32::New(GL_SRGB8), ReadOnly);

     Gl->Set(String::NewSymbol("SRGB_ALPHA"), Uint32::New(GL_SRGB_ALPHA), ReadOnly);

     Gl->Set(String::NewSymbol("SRGB8_ALPHA8"), Uint32::New(GL_SRGB8_ALPHA8), ReadOnly);

     Gl->Set(String::NewSymbol("SLUMINANCE_ALPHA"), Uint32::New(GL_SLUMINANCE_ALPHA), ReadOnly);

     Gl->Set(String::NewSymbol("SLUMINANCE8_ALPHA8"), Uint32::New(GL_SLUMINANCE8_ALPHA8), ReadOnly);

     Gl->Set(String::NewSymbol("SLUMINANCE"), Uint32::New(GL_SLUMINANCE), ReadOnly);

     Gl->Set(String::NewSymbol("SLUMINANCE8"), Uint32::New(GL_SLUMINANCE8), ReadOnly);

     Gl->Set(String::NewSymbol("COMPRESSED_SRGB"), Uint32::New(GL_COMPRESSED_SRGB), ReadOnly);

     Gl->Set(String::NewSymbol("COMPRESSED_SRGB_ALPHA"), Uint32::New(GL_COMPRESSED_SRGB_ALPHA), ReadOnly);

     Gl->Set(String::NewSymbol("COMPRESSED_SLUMINANCE"), Uint32::New(GL_COMPRESSED_SLUMINANCE), ReadOnly);

     Gl->Set(String::NewSymbol("COMPRESSED_SLUMINANCE_ALPHA"), Uint32::New(GL_COMPRESSED_SLUMINANCE_ALPHA), ReadOnly);

     Gl->Set(String::NewSymbol("Accum"), FunctionTemplate::New(GLglAccumCallback));

     Gl->Set(String::NewSymbol("AlphaFunc"), FunctionTemplate::New(GLglAlphaFuncCallback));

     Gl->Set(String::NewSymbol("AreTexturesResident"), FunctionTemplate::New(GLglAreTexturesResidentCallback));

     Gl->Set(String::NewSymbol("ArrayElement"), FunctionTemplate::New(GLglArrayElementCallback));

     Gl->Set(String::NewSymbol("Begin"), FunctionTemplate::New(GLglBeginCallback));

     Gl->Set(String::NewSymbol("BindTexture"), FunctionTemplate::New(GLglBindTextureCallback));

     Gl->Set(String::NewSymbol("Bitmap"), FunctionTemplate::New(GLglBitmapCallback));

     Gl->Set(String::NewSymbol("BlendColor"), FunctionTemplate::New(GLglBlendColorCallback));

     Gl->Set(String::NewSymbol("BlendEquation"), FunctionTemplate::New(GLglBlendEquationCallback));

     Gl->Set(String::NewSymbol("BlendEquationSeparate"), FunctionTemplate::New(GLglBlendEquationSeparateCallback));

     Gl->Set(String::NewSymbol("BlendFunc"), FunctionTemplate::New(GLglBlendFuncCallback));

     Gl->Set(String::NewSymbol("CallList"), FunctionTemplate::New(GLglCallListCallback));

     Gl->Set(String::NewSymbol("Clear"), FunctionTemplate::New(GLglClearCallback));

     Gl->Set(String::NewSymbol("ClearAccum"), FunctionTemplate::New(GLglClearAccumCallback));

     Gl->Set(String::NewSymbol("ClearColor"), FunctionTemplate::New(GLglClearColorCallback));

     Gl->Set(String::NewSymbol("ClearDepth"), FunctionTemplate::New(GLglClearDepthCallback));

     Gl->Set(String::NewSymbol("ClearIndex"), FunctionTemplate::New(GLglClearIndexCallback));

     Gl->Set(String::NewSymbol("ClearStencil"), FunctionTemplate::New(GLglClearStencilCallback));

     Gl->Set(String::NewSymbol("ClipPlane"), FunctionTemplate::New(GLglClipPlaneCallback));

     Gl->Set(String::NewSymbol("Color3b"), FunctionTemplate::New(GLglColor3bCallback));

     Gl->Set(String::NewSymbol("Color3bv"), FunctionTemplate::New(GLglColor3bvCallback));

     Gl->Set(String::NewSymbol("Color3d"), FunctionTemplate::New(GLglColor3dCallback));

     Gl->Set(String::NewSymbol("Color3dv"), FunctionTemplate::New(GLglColor3dvCallback));

     Gl->Set(String::NewSymbol("Color3f"), FunctionTemplate::New(GLglColor3fCallback));

     Gl->Set(String::NewSymbol("Color3fv"), FunctionTemplate::New(GLglColor3fvCallback));

     Gl->Set(String::NewSymbol("Color3i"), FunctionTemplate::New(GLglColor3iCallback));

     Gl->Set(String::NewSymbol("Color3iv"), FunctionTemplate::New(GLglColor3ivCallback));

     Gl->Set(String::NewSymbol("Color3s"), FunctionTemplate::New(GLglColor3sCallback));

     Gl->Set(String::NewSymbol("Color3sv"), FunctionTemplate::New(GLglColor3svCallback));

     Gl->Set(String::NewSymbol("Color3ub"), FunctionTemplate::New(GLglColor3ubCallback));

     Gl->Set(String::NewSymbol("Color3ubv"), FunctionTemplate::New(GLglColor3ubvCallback));

     Gl->Set(String::NewSymbol("Color3ui"), FunctionTemplate::New(GLglColor3uiCallback));

     Gl->Set(String::NewSymbol("Color3uiv"), FunctionTemplate::New(GLglColor3uivCallback));

     Gl->Set(String::NewSymbol("Color3us"), FunctionTemplate::New(GLglColor3usCallback));

     Gl->Set(String::NewSymbol("Color3usv"), FunctionTemplate::New(GLglColor3usvCallback));

     Gl->Set(String::NewSymbol("Color4b"), FunctionTemplate::New(GLglColor4bCallback));

     Gl->Set(String::NewSymbol("Color4bv"), FunctionTemplate::New(GLglColor4bvCallback));

     Gl->Set(String::NewSymbol("Color4d"), FunctionTemplate::New(GLglColor4dCallback));

     Gl->Set(String::NewSymbol("Color4dv"), FunctionTemplate::New(GLglColor4dvCallback));

     Gl->Set(String::NewSymbol("Color4f"), FunctionTemplate::New(GLglColor4fCallback));

     Gl->Set(String::NewSymbol("Color4fv"), FunctionTemplate::New(GLglColor4fvCallback));

     Gl->Set(String::NewSymbol("Color4i"), FunctionTemplate::New(GLglColor4iCallback));

     Gl->Set(String::NewSymbol("Color4iv"), FunctionTemplate::New(GLglColor4ivCallback));

     Gl->Set(String::NewSymbol("Color4s"), FunctionTemplate::New(GLglColor4sCallback));

     Gl->Set(String::NewSymbol("Color4sv"), FunctionTemplate::New(GLglColor4svCallback));

     Gl->Set(String::NewSymbol("Color4ub"), FunctionTemplate::New(GLglColor4ubCallback));

     Gl->Set(String::NewSymbol("Color4ubv"), FunctionTemplate::New(GLglColor4ubvCallback));

     Gl->Set(String::NewSymbol("Color4ui"), FunctionTemplate::New(GLglColor4uiCallback));

     Gl->Set(String::NewSymbol("Color4uiv"), FunctionTemplate::New(GLglColor4uivCallback));

     Gl->Set(String::NewSymbol("Color4us"), FunctionTemplate::New(GLglColor4usCallback));

     Gl->Set(String::NewSymbol("Color4usv"), FunctionTemplate::New(GLglColor4usvCallback));

     Gl->Set(String::NewSymbol("ColorMask"), FunctionTemplate::New(GLglColorMaskCallback));

     Gl->Set(String::NewSymbol("ColorMaterial"), FunctionTemplate::New(GLglColorMaterialCallback));

     Gl->Set(String::NewSymbol("ColorTableParameterfv"), FunctionTemplate::New(GLglColorTableParameterfvCallback));

     Gl->Set(String::NewSymbol("ColorTableParameteriv"), FunctionTemplate::New(GLglColorTableParameterivCallback));

     Gl->Set(String::NewSymbol("ConvolutionParameterf"), FunctionTemplate::New(GLglConvolutionParameterfCallback));

     Gl->Set(String::NewSymbol("ConvolutionParameterfv"), FunctionTemplate::New(GLglConvolutionParameterfvCallback));

     Gl->Set(String::NewSymbol("ConvolutionParameteri"), FunctionTemplate::New(GLglConvolutionParameteriCallback));

     Gl->Set(String::NewSymbol("ConvolutionParameteriv"), FunctionTemplate::New(GLglConvolutionParameterivCallback));

     Gl->Set(String::NewSymbol("CopyColorSubTable"), FunctionTemplate::New(GLglCopyColorSubTableCallback));

     Gl->Set(String::NewSymbol("CopyColorTable"), FunctionTemplate::New(GLglCopyColorTableCallback));

     Gl->Set(String::NewSymbol("CopyConvolutionFilter1D"), FunctionTemplate::New(GLglCopyConvolutionFilter1DCallback));

     Gl->Set(String::NewSymbol("CopyConvolutionFilter2D"), FunctionTemplate::New(GLglCopyConvolutionFilter2DCallback));

     Gl->Set(String::NewSymbol("CopyPixels"), FunctionTemplate::New(GLglCopyPixelsCallback));

     Gl->Set(String::NewSymbol("CopyTexImage1D"), FunctionTemplate::New(GLglCopyTexImage1DCallback));

     Gl->Set(String::NewSymbol("CopyTexImage2D"), FunctionTemplate::New(GLglCopyTexImage2DCallback));

     Gl->Set(String::NewSymbol("CopyTexSubImage1D"), FunctionTemplate::New(GLglCopyTexSubImage1DCallback));

     Gl->Set(String::NewSymbol("CopyTexSubImage2D"), FunctionTemplate::New(GLglCopyTexSubImage2DCallback));

     Gl->Set(String::NewSymbol("CopyTexSubImage3D"), FunctionTemplate::New(GLglCopyTexSubImage3DCallback));

     Gl->Set(String::NewSymbol("CullFace"), FunctionTemplate::New(GLglCullFaceCallback));

     Gl->Set(String::NewSymbol("DeleteLists"), FunctionTemplate::New(GLglDeleteListsCallback));

     Gl->Set(String::NewSymbol("DeleteTextures"), FunctionTemplate::New(GLglDeleteTexturesCallback));

     Gl->Set(String::NewSymbol("DepthFunc"), FunctionTemplate::New(GLglDepthFuncCallback));

     Gl->Set(String::NewSymbol("DepthMask"), FunctionTemplate::New(GLglDepthMaskCallback));

     Gl->Set(String::NewSymbol("DepthRange"), FunctionTemplate::New(GLglDepthRangeCallback));

     Gl->Set(String::NewSymbol("Disable"), FunctionTemplate::New(GLglDisableCallback));

     Gl->Set(String::NewSymbol("DisableClientState"), FunctionTemplate::New(GLglDisableClientStateCallback));

     Gl->Set(String::NewSymbol("DrawArrays"), FunctionTemplate::New(GLglDrawArraysCallback));

     Gl->Set(String::NewSymbol("DrawBuffer"), FunctionTemplate::New(GLglDrawBufferCallback));

     Gl->Set(String::NewSymbol("EdgeFlag"), FunctionTemplate::New(GLglEdgeFlagCallback));

     Gl->Set(String::NewSymbol("EdgeFlagv"), FunctionTemplate::New(GLglEdgeFlagvCallback));

     Gl->Set(String::NewSymbol("Enable"), FunctionTemplate::New(GLglEnableCallback));

     Gl->Set(String::NewSymbol("EnableClientState"), FunctionTemplate::New(GLglEnableClientStateCallback));

     Gl->Set(String::NewSymbol("End"), FunctionTemplate::New(GLglEndCallback));

     Gl->Set(String::NewSymbol("EndList"), FunctionTemplate::New(GLglEndListCallback));

     Gl->Set(String::NewSymbol("EvalCoord1d"), FunctionTemplate::New(GLglEvalCoord1dCallback));

     Gl->Set(String::NewSymbol("EvalCoord1dv"), FunctionTemplate::New(GLglEvalCoord1dvCallback));

     Gl->Set(String::NewSymbol("EvalCoord1f"), FunctionTemplate::New(GLglEvalCoord1fCallback));

     Gl->Set(String::NewSymbol("EvalCoord1fv"), FunctionTemplate::New(GLglEvalCoord1fvCallback));

     Gl->Set(String::NewSymbol("EvalCoord2d"), FunctionTemplate::New(GLglEvalCoord2dCallback));

     Gl->Set(String::NewSymbol("EvalCoord2dv"), FunctionTemplate::New(GLglEvalCoord2dvCallback));

     Gl->Set(String::NewSymbol("EvalCoord2f"), FunctionTemplate::New(GLglEvalCoord2fCallback));

     Gl->Set(String::NewSymbol("EvalCoord2fv"), FunctionTemplate::New(GLglEvalCoord2fvCallback));

     Gl->Set(String::NewSymbol("EvalMesh1"), FunctionTemplate::New(GLglEvalMesh1Callback));

     Gl->Set(String::NewSymbol("EvalMesh2"), FunctionTemplate::New(GLglEvalMesh2Callback));

     Gl->Set(String::NewSymbol("EvalPoint1"), FunctionTemplate::New(GLglEvalPoint1Callback));

     Gl->Set(String::NewSymbol("EvalPoint2"), FunctionTemplate::New(GLglEvalPoint2Callback));

     Gl->Set(String::NewSymbol("FeedbackBuffer"), FunctionTemplate::New(GLglFeedbackBufferCallback));

     Gl->Set(String::NewSymbol("Finish"), FunctionTemplate::New(GLglFinishCallback));

     Gl->Set(String::NewSymbol("Flush"), FunctionTemplate::New(GLglFlushCallback));

     Gl->Set(String::NewSymbol("Fogf"), FunctionTemplate::New(GLglFogfCallback));

     Gl->Set(String::NewSymbol("Fogfv"), FunctionTemplate::New(GLglFogfvCallback));

     Gl->Set(String::NewSymbol("Fogi"), FunctionTemplate::New(GLglFogiCallback));

     Gl->Set(String::NewSymbol("Fogiv"), FunctionTemplate::New(GLglFogivCallback));

     Gl->Set(String::NewSymbol("FrontFace"), FunctionTemplate::New(GLglFrontFaceCallback));

     Gl->Set(String::NewSymbol("Frustum"), FunctionTemplate::New(GLglFrustumCallback));

     Gl->Set(String::NewSymbol("GenLists"), FunctionTemplate::New(GLglGenListsCallback));

     Gl->Set(String::NewSymbol("GenTextures"), FunctionTemplate::New(GLglGenTexturesCallback));

     Gl->Set(String::NewSymbol("GetBooleanv"), FunctionTemplate::New(GLglGetBooleanvCallback));

     Gl->Set(String::NewSymbol("GetClipPlane"), FunctionTemplate::New(GLglGetClipPlaneCallback));

     Gl->Set(String::NewSymbol("GetColorTableParameterfv"), FunctionTemplate::New(GLglGetColorTableParameterfvCallback));

     Gl->Set(String::NewSymbol("GetColorTableParameteriv"), FunctionTemplate::New(GLglGetColorTableParameterivCallback));

     Gl->Set(String::NewSymbol("GetConvolutionParameterfv"), FunctionTemplate::New(GLglGetConvolutionParameterfvCallback));

     Gl->Set(String::NewSymbol("GetConvolutionParameteriv"), FunctionTemplate::New(GLglGetConvolutionParameterivCallback));

     Gl->Set(String::NewSymbol("GetDoublev"), FunctionTemplate::New(GLglGetDoublevCallback));

     Gl->Set(String::NewSymbol("GetError"), FunctionTemplate::New(GLglGetErrorCallback));

     Gl->Set(String::NewSymbol("GetFloatv"), FunctionTemplate::New(GLglGetFloatvCallback));

     Gl->Set(String::NewSymbol("GetHistogramParameterfv"), FunctionTemplate::New(GLglGetHistogramParameterfvCallback));

     Gl->Set(String::NewSymbol("GetHistogramParameteriv"), FunctionTemplate::New(GLglGetHistogramParameterivCallback));

     Gl->Set(String::NewSymbol("GetIntegerv"), FunctionTemplate::New(GLglGetIntegervCallback));

     Gl->Set(String::NewSymbol("GetLightfv"), FunctionTemplate::New(GLglGetLightfvCallback));

     Gl->Set(String::NewSymbol("GetLightiv"), FunctionTemplate::New(GLglGetLightivCallback));

     Gl->Set(String::NewSymbol("GetMapdv"), FunctionTemplate::New(GLglGetMapdvCallback));

     Gl->Set(String::NewSymbol("GetMapfv"), FunctionTemplate::New(GLglGetMapfvCallback));

     Gl->Set(String::NewSymbol("GetMapiv"), FunctionTemplate::New(GLglGetMapivCallback));

     Gl->Set(String::NewSymbol("GetMaterialfv"), FunctionTemplate::New(GLglGetMaterialfvCallback));

     Gl->Set(String::NewSymbol("GetMaterialiv"), FunctionTemplate::New(GLglGetMaterialivCallback));

     Gl->Set(String::NewSymbol("GetMinmaxParameterfv"), FunctionTemplate::New(GLglGetMinmaxParameterfvCallback));

     Gl->Set(String::NewSymbol("GetMinmaxParameteriv"), FunctionTemplate::New(GLglGetMinmaxParameterivCallback));

     Gl->Set(String::NewSymbol("GetPixelMapfv"), FunctionTemplate::New(GLglGetPixelMapfvCallback));

     Gl->Set(String::NewSymbol("GetPixelMapuiv"), FunctionTemplate::New(GLglGetPixelMapuivCallback));

     Gl->Set(String::NewSymbol("GetPixelMapusv"), FunctionTemplate::New(GLglGetPixelMapusvCallback));

     Gl->Set(String::NewSymbol("GetPolygonStipple"), FunctionTemplate::New(GLglGetPolygonStippleCallback));

     Gl->Set(String::NewSymbol("GetTexEnvfv"), FunctionTemplate::New(GLglGetTexEnvfvCallback));

     Gl->Set(String::NewSymbol("GetTexEnviv"), FunctionTemplate::New(GLglGetTexEnvivCallback));

     Gl->Set(String::NewSymbol("GetTexGendv"), FunctionTemplate::New(GLglGetTexGendvCallback));

     Gl->Set(String::NewSymbol("GetTexGenfv"), FunctionTemplate::New(GLglGetTexGenfvCallback));

     Gl->Set(String::NewSymbol("GetTexGeniv"), FunctionTemplate::New(GLglGetTexGenivCallback));

     Gl->Set(String::NewSymbol("GetTexLevelParameterfv"), FunctionTemplate::New(GLglGetTexLevelParameterfvCallback));

     Gl->Set(String::NewSymbol("GetTexLevelParameteriv"), FunctionTemplate::New(GLglGetTexLevelParameterivCallback));

     Gl->Set(String::NewSymbol("GetTexParameterfv"), FunctionTemplate::New(GLglGetTexParameterfvCallback));

     Gl->Set(String::NewSymbol("GetTexParameteriv"), FunctionTemplate::New(GLglGetTexParameterivCallback));

     Gl->Set(String::NewSymbol("Hint"), FunctionTemplate::New(GLglHintCallback));

     Gl->Set(String::NewSymbol("Histogram"), FunctionTemplate::New(GLglHistogramCallback));

     Gl->Set(String::NewSymbol("IndexMask"), FunctionTemplate::New(GLglIndexMaskCallback));

     Gl->Set(String::NewSymbol("Indexd"), FunctionTemplate::New(GLglIndexdCallback));

     Gl->Set(String::NewSymbol("Indexdv"), FunctionTemplate::New(GLglIndexdvCallback));

     Gl->Set(String::NewSymbol("Indexf"), FunctionTemplate::New(GLglIndexfCallback));

     Gl->Set(String::NewSymbol("Indexfv"), FunctionTemplate::New(GLglIndexfvCallback));

     Gl->Set(String::NewSymbol("Indexi"), FunctionTemplate::New(GLglIndexiCallback));

     Gl->Set(String::NewSymbol("Indexiv"), FunctionTemplate::New(GLglIndexivCallback));

     Gl->Set(String::NewSymbol("Indexs"), FunctionTemplate::New(GLglIndexsCallback));

     Gl->Set(String::NewSymbol("Indexsv"), FunctionTemplate::New(GLglIndexsvCallback));

     Gl->Set(String::NewSymbol("Indexub"), FunctionTemplate::New(GLglIndexubCallback));

     Gl->Set(String::NewSymbol("Indexubv"), FunctionTemplate::New(GLglIndexubvCallback));

     Gl->Set(String::NewSymbol("InitNames"), FunctionTemplate::New(GLglInitNamesCallback));

     Gl->Set(String::NewSymbol("IsEnabled"), FunctionTemplate::New(GLglIsEnabledCallback));

     Gl->Set(String::NewSymbol("IsList"), FunctionTemplate::New(GLglIsListCallback));

     Gl->Set(String::NewSymbol("IsTexture"), FunctionTemplate::New(GLglIsTextureCallback));

     Gl->Set(String::NewSymbol("LightModelf"), FunctionTemplate::New(GLglLightModelfCallback));

     Gl->Set(String::NewSymbol("LightModelfv"), FunctionTemplate::New(GLglLightModelfvCallback));

     Gl->Set(String::NewSymbol("LightModeli"), FunctionTemplate::New(GLglLightModeliCallback));

     Gl->Set(String::NewSymbol("LightModeliv"), FunctionTemplate::New(GLglLightModelivCallback));

     Gl->Set(String::NewSymbol("Lightf"), FunctionTemplate::New(GLglLightfCallback));

     Gl->Set(String::NewSymbol("Lightfv"), FunctionTemplate::New(GLglLightfvCallback));

     Gl->Set(String::NewSymbol("Lighti"), FunctionTemplate::New(GLglLightiCallback));

     Gl->Set(String::NewSymbol("Lightiv"), FunctionTemplate::New(GLglLightivCallback));

     Gl->Set(String::NewSymbol("LineStipple"), FunctionTemplate::New(GLglLineStippleCallback));

     Gl->Set(String::NewSymbol("LineWidth"), FunctionTemplate::New(GLglLineWidthCallback));

     Gl->Set(String::NewSymbol("ListBase"), FunctionTemplate::New(GLglListBaseCallback));

     Gl->Set(String::NewSymbol("LoadIdentity"), FunctionTemplate::New(GLglLoadIdentityCallback));

     Gl->Set(String::NewSymbol("LoadMatrixd"), FunctionTemplate::New(GLglLoadMatrixdCallback));

     Gl->Set(String::NewSymbol("LoadMatrixf"), FunctionTemplate::New(GLglLoadMatrixfCallback));

     Gl->Set(String::NewSymbol("LoadName"), FunctionTemplate::New(GLglLoadNameCallback));

     Gl->Set(String::NewSymbol("LogicOp"), FunctionTemplate::New(GLglLogicOpCallback));

     Gl->Set(String::NewSymbol("Map1d"), FunctionTemplate::New(GLglMap1dCallback));

     Gl->Set(String::NewSymbol("Map1f"), FunctionTemplate::New(GLglMap1fCallback));

     Gl->Set(String::NewSymbol("Map2d"), FunctionTemplate::New(GLglMap2dCallback));

     Gl->Set(String::NewSymbol("Map2f"), FunctionTemplate::New(GLglMap2fCallback));

     Gl->Set(String::NewSymbol("MapGrid1d"), FunctionTemplate::New(GLglMapGrid1dCallback));

     Gl->Set(String::NewSymbol("MapGrid1f"), FunctionTemplate::New(GLglMapGrid1fCallback));

     Gl->Set(String::NewSymbol("MapGrid2d"), FunctionTemplate::New(GLglMapGrid2dCallback));

     Gl->Set(String::NewSymbol("MapGrid2f"), FunctionTemplate::New(GLglMapGrid2fCallback));

     Gl->Set(String::NewSymbol("Materialf"), FunctionTemplate::New(GLglMaterialfCallback));

     Gl->Set(String::NewSymbol("Materialfv"), FunctionTemplate::New(GLglMaterialfvCallback));

     Gl->Set(String::NewSymbol("Materiali"), FunctionTemplate::New(GLglMaterialiCallback));

     Gl->Set(String::NewSymbol("Materialiv"), FunctionTemplate::New(GLglMaterialivCallback));

     Gl->Set(String::NewSymbol("MatrixMode"), FunctionTemplate::New(GLglMatrixModeCallback));

     Gl->Set(String::NewSymbol("Minmax"), FunctionTemplate::New(GLglMinmaxCallback));

     Gl->Set(String::NewSymbol("MultMatrixd"), FunctionTemplate::New(GLglMultMatrixdCallback));

     Gl->Set(String::NewSymbol("MultMatrixf"), FunctionTemplate::New(GLglMultMatrixfCallback));

     Gl->Set(String::NewSymbol("NewList"), FunctionTemplate::New(GLglNewListCallback));

     Gl->Set(String::NewSymbol("Normal3b"), FunctionTemplate::New(GLglNormal3bCallback));

     Gl->Set(String::NewSymbol("Normal3bv"), FunctionTemplate::New(GLglNormal3bvCallback));

     Gl->Set(String::NewSymbol("Normal3d"), FunctionTemplate::New(GLglNormal3dCallback));

     Gl->Set(String::NewSymbol("Normal3dv"), FunctionTemplate::New(GLglNormal3dvCallback));

     Gl->Set(String::NewSymbol("Normal3f"), FunctionTemplate::New(GLglNormal3fCallback));

     Gl->Set(String::NewSymbol("Normal3fv"), FunctionTemplate::New(GLglNormal3fvCallback));

     Gl->Set(String::NewSymbol("Normal3i"), FunctionTemplate::New(GLglNormal3iCallback));

     Gl->Set(String::NewSymbol("Normal3iv"), FunctionTemplate::New(GLglNormal3ivCallback));

     Gl->Set(String::NewSymbol("Normal3s"), FunctionTemplate::New(GLglNormal3sCallback));

     Gl->Set(String::NewSymbol("Normal3sv"), FunctionTemplate::New(GLglNormal3svCallback));

     Gl->Set(String::NewSymbol("Ortho"), FunctionTemplate::New(GLglOrthoCallback));

     Gl->Set(String::NewSymbol("PassThrough"), FunctionTemplate::New(GLglPassThroughCallback));

     Gl->Set(String::NewSymbol("PixelMapfv"), FunctionTemplate::New(GLglPixelMapfvCallback));

     Gl->Set(String::NewSymbol("PixelMapuiv"), FunctionTemplate::New(GLglPixelMapuivCallback));

     Gl->Set(String::NewSymbol("PixelMapusv"), FunctionTemplate::New(GLglPixelMapusvCallback));

     Gl->Set(String::NewSymbol("PixelStoref"), FunctionTemplate::New(GLglPixelStorefCallback));

     Gl->Set(String::NewSymbol("PixelStorei"), FunctionTemplate::New(GLglPixelStoreiCallback));

     Gl->Set(String::NewSymbol("PixelTransferf"), FunctionTemplate::New(GLglPixelTransferfCallback));

     Gl->Set(String::NewSymbol("PixelTransferi"), FunctionTemplate::New(GLglPixelTransferiCallback));

     Gl->Set(String::NewSymbol("PixelZoom"), FunctionTemplate::New(GLglPixelZoomCallback));

     Gl->Set(String::NewSymbol("PointSize"), FunctionTemplate::New(GLglPointSizeCallback));

     Gl->Set(String::NewSymbol("PolygonMode"), FunctionTemplate::New(GLglPolygonModeCallback));

     Gl->Set(String::NewSymbol("PolygonOffset"), FunctionTemplate::New(GLglPolygonOffsetCallback));

     Gl->Set(String::NewSymbol("PolygonStipple"), FunctionTemplate::New(GLglPolygonStippleCallback));

     Gl->Set(String::NewSymbol("PopAttrib"), FunctionTemplate::New(GLglPopAttribCallback));

     Gl->Set(String::NewSymbol("PopClientAttrib"), FunctionTemplate::New(GLglPopClientAttribCallback));

     Gl->Set(String::NewSymbol("PopMatrix"), FunctionTemplate::New(GLglPopMatrixCallback));

     Gl->Set(String::NewSymbol("PopName"), FunctionTemplate::New(GLglPopNameCallback));

     Gl->Set(String::NewSymbol("PrioritizeTextures"), FunctionTemplate::New(GLglPrioritizeTexturesCallback));

     Gl->Set(String::NewSymbol("PushAttrib"), FunctionTemplate::New(GLglPushAttribCallback));

     Gl->Set(String::NewSymbol("PushClientAttrib"), FunctionTemplate::New(GLglPushClientAttribCallback));

     Gl->Set(String::NewSymbol("PushMatrix"), FunctionTemplate::New(GLglPushMatrixCallback));

     Gl->Set(String::NewSymbol("PushName"), FunctionTemplate::New(GLglPushNameCallback));

     Gl->Set(String::NewSymbol("RasterPos2d"), FunctionTemplate::New(GLglRasterPos2dCallback));

     Gl->Set(String::NewSymbol("RasterPos2dv"), FunctionTemplate::New(GLglRasterPos2dvCallback));

     Gl->Set(String::NewSymbol("RasterPos2f"), FunctionTemplate::New(GLglRasterPos2fCallback));

     Gl->Set(String::NewSymbol("RasterPos2fv"), FunctionTemplate::New(GLglRasterPos2fvCallback));

     Gl->Set(String::NewSymbol("RasterPos2i"), FunctionTemplate::New(GLglRasterPos2iCallback));

     Gl->Set(String::NewSymbol("RasterPos2iv"), FunctionTemplate::New(GLglRasterPos2ivCallback));

     Gl->Set(String::NewSymbol("RasterPos2s"), FunctionTemplate::New(GLglRasterPos2sCallback));

     Gl->Set(String::NewSymbol("RasterPos2sv"), FunctionTemplate::New(GLglRasterPos2svCallback));

     Gl->Set(String::NewSymbol("RasterPos3d"), FunctionTemplate::New(GLglRasterPos3dCallback));

     Gl->Set(String::NewSymbol("RasterPos3dv"), FunctionTemplate::New(GLglRasterPos3dvCallback));

     Gl->Set(String::NewSymbol("RasterPos3f"), FunctionTemplate::New(GLglRasterPos3fCallback));

     Gl->Set(String::NewSymbol("RasterPos3fv"), FunctionTemplate::New(GLglRasterPos3fvCallback));

     Gl->Set(String::NewSymbol("RasterPos3i"), FunctionTemplate::New(GLglRasterPos3iCallback));

     Gl->Set(String::NewSymbol("RasterPos3iv"), FunctionTemplate::New(GLglRasterPos3ivCallback));

     Gl->Set(String::NewSymbol("RasterPos3s"), FunctionTemplate::New(GLglRasterPos3sCallback));

     Gl->Set(String::NewSymbol("RasterPos3sv"), FunctionTemplate::New(GLglRasterPos3svCallback));

     Gl->Set(String::NewSymbol("RasterPos4d"), FunctionTemplate::New(GLglRasterPos4dCallback));

     Gl->Set(String::NewSymbol("RasterPos4dv"), FunctionTemplate::New(GLglRasterPos4dvCallback));

     Gl->Set(String::NewSymbol("RasterPos4f"), FunctionTemplate::New(GLglRasterPos4fCallback));

     Gl->Set(String::NewSymbol("RasterPos4fv"), FunctionTemplate::New(GLglRasterPos4fvCallback));

     Gl->Set(String::NewSymbol("RasterPos4i"), FunctionTemplate::New(GLglRasterPos4iCallback));

     Gl->Set(String::NewSymbol("RasterPos4iv"), FunctionTemplate::New(GLglRasterPos4ivCallback));

     Gl->Set(String::NewSymbol("RasterPos4s"), FunctionTemplate::New(GLglRasterPos4sCallback));

     Gl->Set(String::NewSymbol("RasterPos4sv"), FunctionTemplate::New(GLglRasterPos4svCallback));

     Gl->Set(String::NewSymbol("ReadBuffer"), FunctionTemplate::New(GLglReadBufferCallback));

     Gl->Set(String::NewSymbol("Rectd"), FunctionTemplate::New(GLglRectdCallback));

     Gl->Set(String::NewSymbol("Rectdv"), FunctionTemplate::New(GLglRectdvCallback));

     Gl->Set(String::NewSymbol("Rectf"), FunctionTemplate::New(GLglRectfCallback));

     Gl->Set(String::NewSymbol("Rectfv"), FunctionTemplate::New(GLglRectfvCallback));

     Gl->Set(String::NewSymbol("Recti"), FunctionTemplate::New(GLglRectiCallback));

     Gl->Set(String::NewSymbol("Rectiv"), FunctionTemplate::New(GLglRectivCallback));

     Gl->Set(String::NewSymbol("Rects"), FunctionTemplate::New(GLglRectsCallback));

     Gl->Set(String::NewSymbol("Rectsv"), FunctionTemplate::New(GLglRectsvCallback));

     Gl->Set(String::NewSymbol("RenderMode"), FunctionTemplate::New(GLglRenderModeCallback));

     Gl->Set(String::NewSymbol("ResetHistogram"), FunctionTemplate::New(GLglResetHistogramCallback));

     Gl->Set(String::NewSymbol("ResetMinmax"), FunctionTemplate::New(GLglResetMinmaxCallback));

     Gl->Set(String::NewSymbol("Rotated"), FunctionTemplate::New(GLglRotatedCallback));

     Gl->Set(String::NewSymbol("Rotatef"), FunctionTemplate::New(GLglRotatefCallback));

     Gl->Set(String::NewSymbol("Scaled"), FunctionTemplate::New(GLglScaledCallback));

     Gl->Set(String::NewSymbol("Scalef"), FunctionTemplate::New(GLglScalefCallback));

     Gl->Set(String::NewSymbol("Scissor"), FunctionTemplate::New(GLglScissorCallback));

     Gl->Set(String::NewSymbol("SelectBuffer"), FunctionTemplate::New(GLglSelectBufferCallback));

     Gl->Set(String::NewSymbol("ShadeModel"), FunctionTemplate::New(GLglShadeModelCallback));

     Gl->Set(String::NewSymbol("StencilFunc"), FunctionTemplate::New(GLglStencilFuncCallback));

     Gl->Set(String::NewSymbol("StencilMask"), FunctionTemplate::New(GLglStencilMaskCallback));

     Gl->Set(String::NewSymbol("StencilOp"), FunctionTemplate::New(GLglStencilOpCallback));

     Gl->Set(String::NewSymbol("TexCoord1d"), FunctionTemplate::New(GLglTexCoord1dCallback));

     Gl->Set(String::NewSymbol("TexCoord1dv"), FunctionTemplate::New(GLglTexCoord1dvCallback));

     Gl->Set(String::NewSymbol("TexCoord1f"), FunctionTemplate::New(GLglTexCoord1fCallback));

     Gl->Set(String::NewSymbol("TexCoord1fv"), FunctionTemplate::New(GLglTexCoord1fvCallback));

     Gl->Set(String::NewSymbol("TexCoord1i"), FunctionTemplate::New(GLglTexCoord1iCallback));

     Gl->Set(String::NewSymbol("TexCoord1iv"), FunctionTemplate::New(GLglTexCoord1ivCallback));

     Gl->Set(String::NewSymbol("TexCoord1s"), FunctionTemplate::New(GLglTexCoord1sCallback));

     Gl->Set(String::NewSymbol("TexCoord1sv"), FunctionTemplate::New(GLglTexCoord1svCallback));

     Gl->Set(String::NewSymbol("TexCoord2d"), FunctionTemplate::New(GLglTexCoord2dCallback));

     Gl->Set(String::NewSymbol("TexCoord2dv"), FunctionTemplate::New(GLglTexCoord2dvCallback));

     Gl->Set(String::NewSymbol("TexCoord2f"), FunctionTemplate::New(GLglTexCoord2fCallback));

     Gl->Set(String::NewSymbol("TexCoord2fv"), FunctionTemplate::New(GLglTexCoord2fvCallback));

     Gl->Set(String::NewSymbol("TexCoord2i"), FunctionTemplate::New(GLglTexCoord2iCallback));

     Gl->Set(String::NewSymbol("TexCoord2iv"), FunctionTemplate::New(GLglTexCoord2ivCallback));

     Gl->Set(String::NewSymbol("TexCoord2s"), FunctionTemplate::New(GLglTexCoord2sCallback));

     Gl->Set(String::NewSymbol("TexCoord2sv"), FunctionTemplate::New(GLglTexCoord2svCallback));

     Gl->Set(String::NewSymbol("TexCoord3d"), FunctionTemplate::New(GLglTexCoord3dCallback));

     Gl->Set(String::NewSymbol("TexCoord3dv"), FunctionTemplate::New(GLglTexCoord3dvCallback));

     Gl->Set(String::NewSymbol("TexCoord3f"), FunctionTemplate::New(GLglTexCoord3fCallback));

     Gl->Set(String::NewSymbol("TexCoord3fv"), FunctionTemplate::New(GLglTexCoord3fvCallback));

     Gl->Set(String::NewSymbol("TexCoord3i"), FunctionTemplate::New(GLglTexCoord3iCallback));

     Gl->Set(String::NewSymbol("TexCoord3iv"), FunctionTemplate::New(GLglTexCoord3ivCallback));

     Gl->Set(String::NewSymbol("TexCoord3s"), FunctionTemplate::New(GLglTexCoord3sCallback));

     Gl->Set(String::NewSymbol("TexCoord3sv"), FunctionTemplate::New(GLglTexCoord3svCallback));

     Gl->Set(String::NewSymbol("TexCoord4d"), FunctionTemplate::New(GLglTexCoord4dCallback));

     Gl->Set(String::NewSymbol("TexCoord4dv"), FunctionTemplate::New(GLglTexCoord4dvCallback));

     Gl->Set(String::NewSymbol("TexCoord4f"), FunctionTemplate::New(GLglTexCoord4fCallback));

     Gl->Set(String::NewSymbol("TexCoord4fv"), FunctionTemplate::New(GLglTexCoord4fvCallback));

     Gl->Set(String::NewSymbol("TexCoord4i"), FunctionTemplate::New(GLglTexCoord4iCallback));

     Gl->Set(String::NewSymbol("TexCoord4iv"), FunctionTemplate::New(GLglTexCoord4ivCallback));

     Gl->Set(String::NewSymbol("TexCoord4s"), FunctionTemplate::New(GLglTexCoord4sCallback));

     Gl->Set(String::NewSymbol("TexCoord4sv"), FunctionTemplate::New(GLglTexCoord4svCallback));

     Gl->Set(String::NewSymbol("TexEnvf"), FunctionTemplate::New(GLglTexEnvfCallback));

     Gl->Set(String::NewSymbol("TexEnvfv"), FunctionTemplate::New(GLglTexEnvfvCallback));

     Gl->Set(String::NewSymbol("TexEnvi"), FunctionTemplate::New(GLglTexEnviCallback));

     Gl->Set(String::NewSymbol("TexEnviv"), FunctionTemplate::New(GLglTexEnvivCallback));

     Gl->Set(String::NewSymbol("TexGend"), FunctionTemplate::New(GLglTexGendCallback));

     Gl->Set(String::NewSymbol("TexGendv"), FunctionTemplate::New(GLglTexGendvCallback));

     Gl->Set(String::NewSymbol("TexGenf"), FunctionTemplate::New(GLglTexGenfCallback));

     Gl->Set(String::NewSymbol("TexGenfv"), FunctionTemplate::New(GLglTexGenfvCallback));

     Gl->Set(String::NewSymbol("TexGeni"), FunctionTemplate::New(GLglTexGeniCallback));

     Gl->Set(String::NewSymbol("TexGeniv"), FunctionTemplate::New(GLglTexGenivCallback));

     Gl->Set(String::NewSymbol("TexParameterf"), FunctionTemplate::New(GLglTexParameterfCallback));

     Gl->Set(String::NewSymbol("TexParameterfv"), FunctionTemplate::New(GLglTexParameterfvCallback));

     Gl->Set(String::NewSymbol("TexParameteri"), FunctionTemplate::New(GLglTexParameteriCallback));

     Gl->Set(String::NewSymbol("TexParameteriv"), FunctionTemplate::New(GLglTexParameterivCallback));

     Gl->Set(String::NewSymbol("Translated"), FunctionTemplate::New(GLglTranslatedCallback));

     Gl->Set(String::NewSymbol("Translatef"), FunctionTemplate::New(GLglTranslatefCallback));

     Gl->Set(String::NewSymbol("Vertex2d"), FunctionTemplate::New(GLglVertex2dCallback));

     Gl->Set(String::NewSymbol("Vertex2dv"), FunctionTemplate::New(GLglVertex2dvCallback));

     Gl->Set(String::NewSymbol("Vertex2f"), FunctionTemplate::New(GLglVertex2fCallback));

     Gl->Set(String::NewSymbol("Vertex2fv"), FunctionTemplate::New(GLglVertex2fvCallback));

     Gl->Set(String::NewSymbol("Vertex2i"), FunctionTemplate::New(GLglVertex2iCallback));

     Gl->Set(String::NewSymbol("Vertex2iv"), FunctionTemplate::New(GLglVertex2ivCallback));

     Gl->Set(String::NewSymbol("Vertex2s"), FunctionTemplate::New(GLglVertex2sCallback));

     Gl->Set(String::NewSymbol("Vertex2sv"), FunctionTemplate::New(GLglVertex2svCallback));

     Gl->Set(String::NewSymbol("Vertex3d"), FunctionTemplate::New(GLglVertex3dCallback));

     Gl->Set(String::NewSymbol("Vertex3dv"), FunctionTemplate::New(GLglVertex3dvCallback));

     Gl->Set(String::NewSymbol("Vertex3f"), FunctionTemplate::New(GLglVertex3fCallback));

     Gl->Set(String::NewSymbol("Vertex3fv"), FunctionTemplate::New(GLglVertex3fvCallback));

     Gl->Set(String::NewSymbol("Vertex3i"), FunctionTemplate::New(GLglVertex3iCallback));

     Gl->Set(String::NewSymbol("Vertex3iv"), FunctionTemplate::New(GLglVertex3ivCallback));

     Gl->Set(String::NewSymbol("Vertex3s"), FunctionTemplate::New(GLglVertex3sCallback));

     Gl->Set(String::NewSymbol("Vertex3sv"), FunctionTemplate::New(GLglVertex3svCallback));

     Gl->Set(String::NewSymbol("Vertex4d"), FunctionTemplate::New(GLglVertex4dCallback));

     Gl->Set(String::NewSymbol("Vertex4dv"), FunctionTemplate::New(GLglVertex4dvCallback));

     Gl->Set(String::NewSymbol("Vertex4f"), FunctionTemplate::New(GLglVertex4fCallback));

     Gl->Set(String::NewSymbol("Vertex4fv"), FunctionTemplate::New(GLglVertex4fvCallback));

     Gl->Set(String::NewSymbol("Vertex4i"), FunctionTemplate::New(GLglVertex4iCallback));

     Gl->Set(String::NewSymbol("Vertex4iv"), FunctionTemplate::New(GLglVertex4ivCallback));

     Gl->Set(String::NewSymbol("Vertex4s"), FunctionTemplate::New(GLglVertex4sCallback));

     Gl->Set(String::NewSymbol("Vertex4sv"), FunctionTemplate::New(GLglVertex4svCallback));

     Gl->Set(String::NewSymbol("Viewport"), FunctionTemplate::New(GLglViewportCallback));

     Gl->Set(String::NewSymbol("SampleCoverage"), FunctionTemplate::New(GLglSampleCoverageCallback));

     Gl->Set(String::NewSymbol("LoadTransposeMatrixf"), FunctionTemplate::New(GLglLoadTransposeMatrixfCallback));

     Gl->Set(String::NewSymbol("LoadTransposeMatrixd"), FunctionTemplate::New(GLglLoadTransposeMatrixdCallback));

     Gl->Set(String::NewSymbol("MultTransposeMatrixf"), FunctionTemplate::New(GLglMultTransposeMatrixfCallback));

     Gl->Set(String::NewSymbol("MultTransposeMatrixd"), FunctionTemplate::New(GLglMultTransposeMatrixdCallback));

     Gl->Set(String::NewSymbol("ActiveTexture"), FunctionTemplate::New(GLglActiveTextureCallback));

     Gl->Set(String::NewSymbol("ClientActiveTexture"), FunctionTemplate::New(GLglClientActiveTextureCallback));

     Gl->Set(String::NewSymbol("MultiTexCoord1d"), FunctionTemplate::New(GLglMultiTexCoord1dCallback));

     Gl->Set(String::NewSymbol("MultiTexCoord1dv"), FunctionTemplate::New(GLglMultiTexCoord1dvCallback));

     Gl->Set(String::NewSymbol("MultiTexCoord1f"), FunctionTemplate::New(GLglMultiTexCoord1fCallback));

     Gl->Set(String::NewSymbol("MultiTexCoord1fv"), FunctionTemplate::New(GLglMultiTexCoord1fvCallback));

     Gl->Set(String::NewSymbol("MultiTexCoord1i"), FunctionTemplate::New(GLglMultiTexCoord1iCallback));

     Gl->Set(String::NewSymbol("MultiTexCoord1iv"), FunctionTemplate::New(GLglMultiTexCoord1ivCallback));

     Gl->Set(String::NewSymbol("MultiTexCoord1s"), FunctionTemplate::New(GLglMultiTexCoord1sCallback));

     Gl->Set(String::NewSymbol("MultiTexCoord1sv"), FunctionTemplate::New(GLglMultiTexCoord1svCallback));

     Gl->Set(String::NewSymbol("MultiTexCoord2d"), FunctionTemplate::New(GLglMultiTexCoord2dCallback));

     Gl->Set(String::NewSymbol("MultiTexCoord2dv"), FunctionTemplate::New(GLglMultiTexCoord2dvCallback));

     Gl->Set(String::NewSymbol("MultiTexCoord2f"), FunctionTemplate::New(GLglMultiTexCoord2fCallback));

     Gl->Set(String::NewSymbol("MultiTexCoord2fv"), FunctionTemplate::New(GLglMultiTexCoord2fvCallback));

     Gl->Set(String::NewSymbol("MultiTexCoord2i"), FunctionTemplate::New(GLglMultiTexCoord2iCallback));

     Gl->Set(String::NewSymbol("MultiTexCoord2iv"), FunctionTemplate::New(GLglMultiTexCoord2ivCallback));

     Gl->Set(String::NewSymbol("MultiTexCoord2s"), FunctionTemplate::New(GLglMultiTexCoord2sCallback));

     Gl->Set(String::NewSymbol("MultiTexCoord2sv"), FunctionTemplate::New(GLglMultiTexCoord2svCallback));

     Gl->Set(String::NewSymbol("MultiTexCoord3d"), FunctionTemplate::New(GLglMultiTexCoord3dCallback));

     Gl->Set(String::NewSymbol("MultiTexCoord3dv"), FunctionTemplate::New(GLglMultiTexCoord3dvCallback));

     Gl->Set(String::NewSymbol("MultiTexCoord3f"), FunctionTemplate::New(GLglMultiTexCoord3fCallback));

     Gl->Set(String::NewSymbol("MultiTexCoord3fv"), FunctionTemplate::New(GLglMultiTexCoord3fvCallback));

     Gl->Set(String::NewSymbol("MultiTexCoord3i"), FunctionTemplate::New(GLglMultiTexCoord3iCallback));

     Gl->Set(String::NewSymbol("MultiTexCoord3iv"), FunctionTemplate::New(GLglMultiTexCoord3ivCallback));

     Gl->Set(String::NewSymbol("MultiTexCoord3s"), FunctionTemplate::New(GLglMultiTexCoord3sCallback));

     Gl->Set(String::NewSymbol("MultiTexCoord3sv"), FunctionTemplate::New(GLglMultiTexCoord3svCallback));

     Gl->Set(String::NewSymbol("MultiTexCoord4d"), FunctionTemplate::New(GLglMultiTexCoord4dCallback));

     Gl->Set(String::NewSymbol("MultiTexCoord4dv"), FunctionTemplate::New(GLglMultiTexCoord4dvCallback));

     Gl->Set(String::NewSymbol("MultiTexCoord4f"), FunctionTemplate::New(GLglMultiTexCoord4fCallback));

     Gl->Set(String::NewSymbol("MultiTexCoord4fv"), FunctionTemplate::New(GLglMultiTexCoord4fvCallback));

     Gl->Set(String::NewSymbol("MultiTexCoord4iv"), FunctionTemplate::New(GLglMultiTexCoord4ivCallback));

     Gl->Set(String::NewSymbol("MultiTexCoord4s"), FunctionTemplate::New(GLglMultiTexCoord4sCallback));

     Gl->Set(String::NewSymbol("MultiTexCoord4sv"), FunctionTemplate::New(GLglMultiTexCoord4svCallback));

     Gl->Set(String::NewSymbol("FogCoordf"), FunctionTemplate::New(GLglFogCoordfCallback));

     Gl->Set(String::NewSymbol("FogCoordfv"), FunctionTemplate::New(GLglFogCoordfvCallback));

     Gl->Set(String::NewSymbol("FogCoordd"), FunctionTemplate::New(GLglFogCoorddCallback));

     Gl->Set(String::NewSymbol("SecondaryColor3b"), FunctionTemplate::New(GLglSecondaryColor3bCallback));

     Gl->Set(String::NewSymbol("SecondaryColor3bv"), FunctionTemplate::New(GLglSecondaryColor3bvCallback));

     Gl->Set(String::NewSymbol("SecondaryColor3d"), FunctionTemplate::New(GLglSecondaryColor3dCallback));

     Gl->Set(String::NewSymbol("SecondaryColor3dv"), FunctionTemplate::New(GLglSecondaryColor3dvCallback));

     Gl->Set(String::NewSymbol("SecondaryColor3f"), FunctionTemplate::New(GLglSecondaryColor3fCallback));

     Gl->Set(String::NewSymbol("SecondaryColor3fv"), FunctionTemplate::New(GLglSecondaryColor3fvCallback));

     Gl->Set(String::NewSymbol("SecondaryColor3i"), FunctionTemplate::New(GLglSecondaryColor3iCallback));

     Gl->Set(String::NewSymbol("SecondaryColor3iv"), FunctionTemplate::New(GLglSecondaryColor3ivCallback));

     Gl->Set(String::NewSymbol("SecondaryColor3s"), FunctionTemplate::New(GLglSecondaryColor3sCallback));

     Gl->Set(String::NewSymbol("SecondaryColor3sv"), FunctionTemplate::New(GLglSecondaryColor3svCallback));

     Gl->Set(String::NewSymbol("SecondaryColor3ub"), FunctionTemplate::New(GLglSecondaryColor3ubCallback));

     Gl->Set(String::NewSymbol("SecondaryColor3ubv"), FunctionTemplate::New(GLglSecondaryColor3ubvCallback));

     Gl->Set(String::NewSymbol("SecondaryColor3ui"), FunctionTemplate::New(GLglSecondaryColor3uiCallback));

     Gl->Set(String::NewSymbol("SecondaryColor3uiv"), FunctionTemplate::New(GLglSecondaryColor3uivCallback));

     Gl->Set(String::NewSymbol("SecondaryColor3us"), FunctionTemplate::New(GLglSecondaryColor3usCallback));

     Gl->Set(String::NewSymbol("SecondaryColor3usv"), FunctionTemplate::New(GLglSecondaryColor3usvCallback));

     Gl->Set(String::NewSymbol("PointParameterf"), FunctionTemplate::New(GLglPointParameterfCallback));

     Gl->Set(String::NewSymbol("PointParameterfv"), FunctionTemplate::New(GLglPointParameterfvCallback));

     Gl->Set(String::NewSymbol("PointParameteri"), FunctionTemplate::New(GLglPointParameteriCallback));

     Gl->Set(String::NewSymbol("PointParameteriv"), FunctionTemplate::New(GLglPointParameterivCallback));

     Gl->Set(String::NewSymbol("BlendFuncSeparate"), FunctionTemplate::New(GLglBlendFuncSeparateCallback));

     Gl->Set(String::NewSymbol("MultiDrawArrays"), FunctionTemplate::New(GLglMultiDrawArraysCallback));

     Gl->Set(String::NewSymbol("WindowPos2d"), FunctionTemplate::New(GLglWindowPos2dCallback));

     Gl->Set(String::NewSymbol("WindowPos2dv"), FunctionTemplate::New(GLglWindowPos2dvCallback));

     Gl->Set(String::NewSymbol("WindowPos2f"), FunctionTemplate::New(GLglWindowPos2fCallback));

     Gl->Set(String::NewSymbol("WindowPos2fv"), FunctionTemplate::New(GLglWindowPos2fvCallback));

     Gl->Set(String::NewSymbol("WindowPos2i"), FunctionTemplate::New(GLglWindowPos2iCallback));

     Gl->Set(String::NewSymbol("WindowPos2iv"), FunctionTemplate::New(GLglWindowPos2ivCallback));

     Gl->Set(String::NewSymbol("WindowPos2s"), FunctionTemplate::New(GLglWindowPos2sCallback));

     Gl->Set(String::NewSymbol("WindowPos2sv"), FunctionTemplate::New(GLglWindowPos2svCallback));

     Gl->Set(String::NewSymbol("WindowPos3d"), FunctionTemplate::New(GLglWindowPos3dCallback));

     Gl->Set(String::NewSymbol("WindowPos3dv"), FunctionTemplate::New(GLglWindowPos3dvCallback));

     Gl->Set(String::NewSymbol("WindowPos3f"), FunctionTemplate::New(GLglWindowPos3fCallback));

     Gl->Set(String::NewSymbol("WindowPos3fv"), FunctionTemplate::New(GLglWindowPos3fvCallback));

     Gl->Set(String::NewSymbol("WindowPos3i"), FunctionTemplate::New(GLglWindowPos3iCallback));

     Gl->Set(String::NewSymbol("WindowPos3iv"), FunctionTemplate::New(GLglWindowPos3ivCallback));

     Gl->Set(String::NewSymbol("WindowPos3s"), FunctionTemplate::New(GLglWindowPos3sCallback));

     Gl->Set(String::NewSymbol("WindowPos3sv"), FunctionTemplate::New(GLglWindowPos3svCallback));

     Gl->Set(String::NewSymbol("GenQueries"), FunctionTemplate::New(GLglGenQueriesCallback));

     Gl->Set(String::NewSymbol("DeleteQueries"), FunctionTemplate::New(GLglDeleteQueriesCallback));

     Gl->Set(String::NewSymbol("IsQuery"), FunctionTemplate::New(GLglIsQueryCallback));

     Gl->Set(String::NewSymbol("BeginQuery"), FunctionTemplate::New(GLglBeginQueryCallback));

     Gl->Set(String::NewSymbol("EndQuery"), FunctionTemplate::New(GLglEndQueryCallback));

     Gl->Set(String::NewSymbol("GetQueryiv"), FunctionTemplate::New(GLglGetQueryivCallback));

     Gl->Set(String::NewSymbol("GetQueryObjectiv"), FunctionTemplate::New(GLglGetQueryObjectivCallback));

     Gl->Set(String::NewSymbol("GetQueryObjectuiv"), FunctionTemplate::New(GLglGetQueryObjectuivCallback));

     Gl->Set(String::NewSymbol("BindBuffer"), FunctionTemplate::New(GLglBindBufferCallback));

     Gl->Set(String::NewSymbol("DeleteBuffers"), FunctionTemplate::New(GLglDeleteBuffersCallback));

     Gl->Set(String::NewSymbol("GenBuffers"), FunctionTemplate::New(GLglGenBuffersCallback));

     Gl->Set(String::NewSymbol("IsBuffer"), FunctionTemplate::New(GLglIsBufferCallback));

     Gl->Set(String::NewSymbol("UnmapBuffer"), FunctionTemplate::New(GLglUnmapBufferCallback));

     Gl->Set(String::NewSymbol("GetBufferParameteriv"), FunctionTemplate::New(GLglGetBufferParameterivCallback));

     Gl->Set(String::NewSymbol("DrawBuffers"), FunctionTemplate::New(GLglDrawBuffersCallback));

     Gl->Set(String::NewSymbol("VertexAttrib1d"), FunctionTemplate::New(GLglVertexAttrib1dCallback));

     Gl->Set(String::NewSymbol("VertexAttrib1dv"), FunctionTemplate::New(GLglVertexAttrib1dvCallback));

     Gl->Set(String::NewSymbol("VertexAttrib1f"), FunctionTemplate::New(GLglVertexAttrib1fCallback));

     Gl->Set(String::NewSymbol("VertexAttrib1fv"), FunctionTemplate::New(GLglVertexAttrib1fvCallback));

     Gl->Set(String::NewSymbol("VertexAttrib1s"), FunctionTemplate::New(GLglVertexAttrib1sCallback));

     Gl->Set(String::NewSymbol("VertexAttrib1sv"), FunctionTemplate::New(GLglVertexAttrib1svCallback));

     Gl->Set(String::NewSymbol("VertexAttrib2d"), FunctionTemplate::New(GLglVertexAttrib2dCallback));

     Gl->Set(String::NewSymbol("VertexAttrib2dv"), FunctionTemplate::New(GLglVertexAttrib2dvCallback));

     Gl->Set(String::NewSymbol("VertexAttrib2f"), FunctionTemplate::New(GLglVertexAttrib2fCallback));

     Gl->Set(String::NewSymbol("VertexAttrib2fv"), FunctionTemplate::New(GLglVertexAttrib2fvCallback));

     Gl->Set(String::NewSymbol("VertexAttrib2s"), FunctionTemplate::New(GLglVertexAttrib2sCallback));

     Gl->Set(String::NewSymbol("VertexAttrib2sv"), FunctionTemplate::New(GLglVertexAttrib2svCallback));

     Gl->Set(String::NewSymbol("VertexAttrib3d"), FunctionTemplate::New(GLglVertexAttrib3dCallback));

     Gl->Set(String::NewSymbol("VertexAttrib3dv"), FunctionTemplate::New(GLglVertexAttrib3dvCallback));

     Gl->Set(String::NewSymbol("VertexAttrib3f"), FunctionTemplate::New(GLglVertexAttrib3fCallback));

     Gl->Set(String::NewSymbol("VertexAttrib3fv"), FunctionTemplate::New(GLglVertexAttrib3fvCallback));

     Gl->Set(String::NewSymbol("VertexAttrib3s"), FunctionTemplate::New(GLglVertexAttrib3sCallback));

     Gl->Set(String::NewSymbol("VertexAttrib3sv"), FunctionTemplate::New(GLglVertexAttrib3svCallback));

     Gl->Set(String::NewSymbol("VertexAttrib4Nbv"), FunctionTemplate::New(GLglVertexAttrib4NbvCallback));

     Gl->Set(String::NewSymbol("VertexAttrib4Niv"), FunctionTemplate::New(GLglVertexAttrib4NivCallback));

     Gl->Set(String::NewSymbol("VertexAttrib4Nsv"), FunctionTemplate::New(GLglVertexAttrib4NsvCallback));

     Gl->Set(String::NewSymbol("VertexAttrib4Nub"), FunctionTemplate::New(GLglVertexAttrib4NubCallback));

     Gl->Set(String::NewSymbol("VertexAttrib4Nubv"), FunctionTemplate::New(GLglVertexAttrib4NubvCallback));

     Gl->Set(String::NewSymbol("VertexAttrib4Nuiv"), FunctionTemplate::New(GLglVertexAttrib4NuivCallback));

     Gl->Set(String::NewSymbol("VertexAttrib4Nusv"), FunctionTemplate::New(GLglVertexAttrib4NusvCallback));

     Gl->Set(String::NewSymbol("VertexAttrib4bv"), FunctionTemplate::New(GLglVertexAttrib4bvCallback));

     Gl->Set(String::NewSymbol("VertexAttrib4d"), FunctionTemplate::New(GLglVertexAttrib4dCallback));

     Gl->Set(String::NewSymbol("VertexAttrib4dv"), FunctionTemplate::New(GLglVertexAttrib4dvCallback));

     Gl->Set(String::NewSymbol("VertexAttrib4f"), FunctionTemplate::New(GLglVertexAttrib4fCallback));

     Gl->Set(String::NewSymbol("VertexAttrib4fv"), FunctionTemplate::New(GLglVertexAttrib4fvCallback));

     Gl->Set(String::NewSymbol("VertexAttrib4iv"), FunctionTemplate::New(GLglVertexAttrib4ivCallback));

     Gl->Set(String::NewSymbol("VertexAttrib4s"), FunctionTemplate::New(GLglVertexAttrib4sCallback));

     Gl->Set(String::NewSymbol("VertexAttrib4sv"), FunctionTemplate::New(GLglVertexAttrib4svCallback));

     Gl->Set(String::NewSymbol("VertexAttrib4ubv"), FunctionTemplate::New(GLglVertexAttrib4ubvCallback));

     Gl->Set(String::NewSymbol("VertexAttrib4uiv"), FunctionTemplate::New(GLglVertexAttrib4uivCallback));

     Gl->Set(String::NewSymbol("VertexAttrib4usv"), FunctionTemplate::New(GLglVertexAttrib4usvCallback));

     Gl->Set(String::NewSymbol("EnableVertexAttribArray"), FunctionTemplate::New(GLglEnableVertexAttribArrayCallback));

     Gl->Set(String::NewSymbol("DisableVertexAttribArray"), FunctionTemplate::New(GLglDisableVertexAttribArrayCallback));

     Gl->Set(String::NewSymbol("GetVertexAttribdv"), FunctionTemplate::New(GLglGetVertexAttribdvCallback));

     Gl->Set(String::NewSymbol("GetVertexAttribfv"), FunctionTemplate::New(GLglGetVertexAttribfvCallback));

     Gl->Set(String::NewSymbol("GetVertexAttribiv"), FunctionTemplate::New(GLglGetVertexAttribivCallback));

     Gl->Set(String::NewSymbol("DeleteShader"), FunctionTemplate::New(GLglDeleteShaderCallback));

     Gl->Set(String::NewSymbol("DetachShader"), FunctionTemplate::New(GLglDetachShaderCallback));

     Gl->Set(String::NewSymbol("CreateShader"), FunctionTemplate::New(GLglCreateShaderCallback));

     Gl->Set(String::NewSymbol("CompileShader"), FunctionTemplate::New(GLglCompileShaderCallback));

     Gl->Set(String::NewSymbol("CreateProgram"), FunctionTemplate::New(GLglCreateProgramCallback));

     Gl->Set(String::NewSymbol("AttachShader"), FunctionTemplate::New(GLglAttachShaderCallback));

     Gl->Set(String::NewSymbol("LinkProgram"), FunctionTemplate::New(GLglLinkProgramCallback));

     Gl->Set(String::NewSymbol("UseProgram"), FunctionTemplate::New(GLglUseProgramCallback));

     Gl->Set(String::NewSymbol("DeleteProgram"), FunctionTemplate::New(GLglDeleteProgramCallback));

     Gl->Set(String::NewSymbol("ValidateProgram"), FunctionTemplate::New(GLglValidateProgramCallback));

     Gl->Set(String::NewSymbol("Uniform1f"), FunctionTemplate::New(GLglUniform1fCallback));

     Gl->Set(String::NewSymbol("Uniform2f"), FunctionTemplate::New(GLglUniform2fCallback));

     Gl->Set(String::NewSymbol("Uniform3f"), FunctionTemplate::New(GLglUniform3fCallback));

     Gl->Set(String::NewSymbol("Uniform4f"), FunctionTemplate::New(GLglUniform4fCallback));

     Gl->Set(String::NewSymbol("Uniform1i"), FunctionTemplate::New(GLglUniform1iCallback));

     Gl->Set(String::NewSymbol("Uniform2i"), FunctionTemplate::New(GLglUniform2iCallback));

     Gl->Set(String::NewSymbol("Uniform3i"), FunctionTemplate::New(GLglUniform3iCallback));

     Gl->Set(String::NewSymbol("Uniform4i"), FunctionTemplate::New(GLglUniform4iCallback));

     Gl->Set(String::NewSymbol("Uniform1fv"), FunctionTemplate::New(GLglUniform1fvCallback));

     Gl->Set(String::NewSymbol("Uniform2fv"), FunctionTemplate::New(GLglUniform2fvCallback));

     Gl->Set(String::NewSymbol("Uniform3fv"), FunctionTemplate::New(GLglUniform3fvCallback));

     Gl->Set(String::NewSymbol("Uniform4fv"), FunctionTemplate::New(GLglUniform4fvCallback));

     Gl->Set(String::NewSymbol("Uniform1iv"), FunctionTemplate::New(GLglUniform1ivCallback));

     Gl->Set(String::NewSymbol("Uniform2iv"), FunctionTemplate::New(GLglUniform2ivCallback));

     Gl->Set(String::NewSymbol("Uniform3iv"), FunctionTemplate::New(GLglUniform3ivCallback));

     Gl->Set(String::NewSymbol("Uniform4iv"), FunctionTemplate::New(GLglUniform4ivCallback));

     Gl->Set(String::NewSymbol("UniformMatrix2fv"), FunctionTemplate::New(GLglUniformMatrix2fvCallback));

     Gl->Set(String::NewSymbol("UniformMatrix3fv"), FunctionTemplate::New(GLglUniformMatrix3fvCallback));

     Gl->Set(String::NewSymbol("UniformMatrix4fv"), FunctionTemplate::New(GLglUniformMatrix4fvCallback));

     Gl->Set(String::NewSymbol("IsShader"), FunctionTemplate::New(GLglIsShaderCallback));

     Gl->Set(String::NewSymbol("IsProgram"), FunctionTemplate::New(GLglIsProgramCallback));

     Gl->Set(String::NewSymbol("GetShaderiv"), FunctionTemplate::New(GLglGetShaderivCallback));

     Gl->Set(String::NewSymbol("GetProgramiv"), FunctionTemplate::New(GLglGetProgramivCallback));

     Gl->Set(String::NewSymbol("GetAttachedShaders"), FunctionTemplate::New(GLglGetAttachedShadersCallback));

     Gl->Set(String::NewSymbol("GetUniformfv"), FunctionTemplate::New(GLglGetUniformfvCallback));

     Gl->Set(String::NewSymbol("GetUniformiv"), FunctionTemplate::New(GLglGetUniformivCallback));

     Gl->Set(String::NewSymbol("StencilFuncSeparate"), FunctionTemplate::New(GLglStencilFuncSeparateCallback));

     Gl->Set(String::NewSymbol("StencilOpSeparate"), FunctionTemplate::New(GLglStencilOpSeparateCallback));

     Gl->Set(String::NewSymbol("StencilMaskSeparate"), FunctionTemplate::New(GLglStencilMaskSeparateCallback));

     Gl->Set(String::NewSymbol("UniformMatrix2x3fv"), FunctionTemplate::New(GLglUniformMatrix2x3fvCallback));

     Gl->Set(String::NewSymbol("UniformMatrix3x2fv"), FunctionTemplate::New(GLglUniformMatrix3x2fvCallback));

     Gl->Set(String::NewSymbol("UniformMatrix2x4fv"), FunctionTemplate::New(GLglUniformMatrix2x4fvCallback));

     Gl->Set(String::NewSymbol("UniformMatrix4x2fv"), FunctionTemplate::New(GLglUniformMatrix4x2fvCallback));

     Gl->Set(String::NewSymbol("UniformMatrix3x4fv"), FunctionTemplate::New(GLglUniformMatrix3x4fvCallback));

     Gl->Set(String::NewSymbol("UniformMatrix4x3fv"), FunctionTemplate::New(GLglUniformMatrix4x3fvCallback));


      // Again, return the result through the current handle scope.
      return handle_scope.Close(Gl);
}    
