/*
 * glutbind.h
 *
 *  Created on: Jun 15, 2009
 *      Author: nicolas
 */

#ifndef GLUTBIND_H_
#define GLUTBIND_H_

#include <v8-debug.h>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#ifndef GLUT_APIENTRY_DEFINED
#define GLUT_APIENTRY_DEFINED 1
#endif

#ifndef GLUT_WINGDIAPI_DEFINED
#define GLUT_WINGDIAPI_DEFINED 1
#endif

#include <stdio.h>
#include <map>
using namespace std;
using namespace v8;

class GlutFactory {
public:
	static Handle<ObjectTemplate> createGlut(int* pargc, char** argv);
	static Persistent<Context> glut_persistent_context;
};

#endif /* GLUTBIND_H_ */
