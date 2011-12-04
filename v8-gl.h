/*
 * v8-gl.h
 */

#ifndef V8GL_H_
#define V8GL_H_

#include <string>
#include <v8-debug.h>

#include "utils.h"
#ifdef BUILD_GL_BINDINGS
#include "glbindings/glbind.h"
#endif
#ifdef BUILD_GLES_BINDINGS
#include "glesbindings/glesbind.h"
#endif
#ifdef BUILD_GLU_BINDINGS
#include "glubindings/glubind.h"
#endif
#ifdef BUILD_GLUT_BINDINGS
#include "glutbindings/glutbind.h"
#endif

using namespace std;
using namespace v8;

class V8GL {

public:
	bool initialize(int* pargc, char** argv, string scriptname);
	bool executeScript(string scriptname);
	static const char* ToCString(const v8::String::Utf8Value& value);
	static void ReportException(TryCatch* try_catch);

	//keep a reference to the global context.
	static Persistent<Context> context;
};

#endif /* V8GL_H_ */
