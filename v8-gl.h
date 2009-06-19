/*
 * v8-gl.h
 *
 *  Created on: Jun 15, 2009
 *      Author: nicolas
 */

#ifndef V8GL_H_
#define V8GL_H_

#include <v8-debug.h>

#include "glbind.h"
#include "glubind.h"
#include "glutbind.h"

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
