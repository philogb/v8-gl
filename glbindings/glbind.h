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
#else
#include <GL/gl.h>
#endif

using namespace std;
using namespace v8;

class GlFactory {
public:
	static Handle<ObjectTemplate> createGl(void);

	static Persistent<Object> self_;
};
#endif /* GLBIND_H_ */
