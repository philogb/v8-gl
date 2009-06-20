/*
 * v8-gl.cpp
 *
 */

#include "v8-gl.h"
#include <stdio.h>

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
    printf("%s \n\n", *error);
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

	  // Each processor gets its own context so different processors
	  // don't affect each other.
	  global->Set(String::New("Gl"), createGl());
	  global->Set(String::New("Glu"), createGlu());
	  global->Set(String::New("Glut"), GlutFactory::createGlut(pargc, argv));

	  Handle<Context> context = Context::New(NULL, global);

	  GlutFactory::glut_persistent_context = Persistent<Context>::New(context);

	  // Enter the new context so all the following operations take place
	  // within it.
	  Context::Scope context_scope(context);

	  // Compile and run the script
	  if (!executeScript())
		return false;


	  return true;
}
