/*
 * glbind.h
 *
 *  Created on: Jun 15, 2009
 *      Author: nicolas
 */

#ifndef GLBIND_H_
#define GLBIND_H_


#include <v8-debug.h>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;
using namespace v8;

Handle<ObjectTemplate> createGl(void);

#endif /* GLBIND_H_ */
