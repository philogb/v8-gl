/*
 * glubind.h
 *
 *  Created on: Jun 15, 2009
 *      Author: nicolas
 */

#ifndef GLUBIND_H_
#define GLUBIND_H_


#include <v8-debug.h>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdio.h>

using namespace std;
using namespace v8;

Handle<ObjectTemplate> createGlu(void);

#endif /* GLUBIND_H_ */
