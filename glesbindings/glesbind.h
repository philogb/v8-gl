/*
 * glesbind.h
 *
 */

#ifndef GLESBIND_H_
#define GLESBIND_H_

#include <v8-debug.h>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#else
#include <GL/gl.h>
#endif

using namespace std;
using namespace v8;

class GlesFactory {
public:
	static Handle<ObjectTemplate> createGles(void);

	static Persistent<Object> self_;
};

#endif /* GLESBIND_H_ */
