/*
 * v8-gl.cpp
 *
 *  Created on: Jun 15, 2009
 *      Author: nicolas
 */

#include "v8-gl.h"


V8GL::V8GL(Handle<String> script) : script_(script) {};

bool V8GL::executeScript() {
  HandleScope handle_scope;

  // We're just about to compile the script; set up an error handler to
  // catch any exceptions the script might throw.
  TryCatch try_catch;

  // Compile the script and check for errors.
  Handle<Script> compiled_script = Script::Compile(script_);
  if (compiled_script.IsEmpty()) {
    String::Utf8Value error(try_catch.Exception());
    // The script failed to compile; bail out.
    return false;
  }

  // Run the script!
  Handle<Value> result = compiled_script->Run();
  if (result.IsEmpty()) {
    // The TryCatch above is still in effect and will have caught the error.
    String::Utf8Value error(try_catch.Exception());
    // Running the script failed; bail out.
    return false;
  }
  return true;
}

bool V8GL::initialize(int* pargc, char** argv) {
	  // Create a handle scope to hold the temporary references.
	  HandleScope handle_scope;

	  // Create a template for the global object where we set the
	  // built-in global functions.
	  Handle<ObjectTemplate> global = ObjectTemplate::New();

	  global->Set(String::New("Gl"), createGl());
	  global->Set(String::New("Glu"), createGlu());
	  global->Set(String::New("Glut"), createGlut(pargc, argv));

	  // Each processor gets its own context so different processors
	  // don't affect each other (ignore the first three lines).
	  Handle<Context> context = Context::New(NULL, global);

	  // Store the context in the processor object in a persistent handle,
	  // since we want the reference to remain after we return from this
	  // method.
	  //context_ = Persistent<Context>::New(context);

	  // Enter the new context so all the following operations take place
	  // within it.
	  Context::Scope context_scope(context);

	  // Compile and run the script
	  if (!executeScript())
		return false;

	  return true;
}
