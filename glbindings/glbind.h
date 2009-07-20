/*
 * glbind.h
 *
 *  Created on: Jun 15, 2009
 *      Author: nicolas
 */

#ifndef GLBIND_H_
#define GLBIND_H_

#include <v8.h>

class GlFactory {
public:
	static v8::Handle<v8::ObjectTemplate> createGl(void);

	static v8::Persistent<v8::Object> self_;
};

#endif /* GLBIND_H_ */
