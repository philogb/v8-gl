/*
 * v8-gl.h
 */

#ifndef V8GL_H_
#define V8GL_H_

#include <string>
#include <v8-debug.h>

#include "utils.h"
#include "glbindings/glbind.h"
#include "glesbindings/glesbind.h"
#include "glubindings/glubind.h"
#include "glutbindings/glutbind.h"

using namespace std;
using namespace v8;

class V8GL {

public:
	bool initialize(int* pargc, char** argv, string scriptname);
	bool executeScript(string scriptname);

	//keep a reference to the global context.
	static Persistent<Context> context;
};

#endif /* V8GL_H_ */
