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

#include <map>
using namespace std;
using namespace v8;

Handle<ObjectTemplate> createGlut(int* pargc, char** argv, Persistent<Context> context);

#endif /* GLUTBIND_H_ */
