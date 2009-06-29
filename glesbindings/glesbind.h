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
#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#endif

// If we're running on desktop OpenGL, some ES 2.0 constants don't exist, or
// are under a name with EXT in them, etc.
#ifndef GL_ES_VERSION_2_0
#include "gles_desktop_shim.h"
#endif

using namespace std;
using namespace v8;

class GlesFactory {
public:
	static Handle<ObjectTemplate> createGles(void);

	static Persistent<Object> self_;
};

#endif /* GLESBIND_H_ */
