/*
 * v8-gl.h
 */

#ifndef V8GL_H_
#define V8GL_H_

#include <v8-debug.h>

#include "glbindings/glbind.h"
#include "glesbindings/glesbind.h"
#include "glubindings/glubind.h"
#include "glutbindings/glutbind.h"

using namespace std;
using namespace v8;

class V8GL {

public:
	V8GL(Handle<String> script);

	bool initialize(int* pargc, char** argv);
	bool executeScript();

private:
	Handle<String> script_;

};

#endif /* V8GL_H_ */
