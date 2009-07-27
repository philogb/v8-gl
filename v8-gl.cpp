/*
 * v8-gl.cpp
 *
 */

#include "v8-gl.h"
#include <stdio.h>
#include <string.h>

Handle<Value> log(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  if (args.Length() < 1) return v8::Undefined();
  //define handle scope
  HandleScope scope;
  //get arguments
  String::Utf8Value value0(args[0]);
  char* arg0 = *value0;

  //make call
  fprintf(stdout, "%s", arg0);
  return v8::Undefined();
}

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
    printf("%s \n\n", *error);
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
	  Handle<ObjectTemplate> Gl = GlFactory::createGl();
	  Handle<ObjectTemplate> Gles = GlesFactory::createGles();

	  global->Set(String::New("Gl"), Gl);
	  global->Set(String::New("Gles"), Gles);
	  global->Set(String::New("Glu"), createGlu());
	  global->Set(String::New("Glut"), GlutFactory::createGlut(pargc, argv));
	  global->Set(String::New("log"), FunctionTemplate::New(log));

	  Handle<Context> context = Context::New(NULL, global);

	  GlutFactory::glut_persistent_context = Persistent<Context>::New(context);
	  GlesFactory::gles_persistent_context = Persistent<Context>::New(context);

	  // Enter the new context so all the following operations take place
	  // within it.
	  Context::Scope context_scope(context);

	  //Append *this* as Gl static variable so we can do dot-this-dot-that stuff
	  GlFactory::self_ = Persistent<Object>::New(Gl->NewInstance());
	  GlesFactory::self_ = Persistent<Object>::New(Gles->NewInstance());

	  //Set the root_path for opening shader files with
	  //relative paths
	  //take path from executable
	  char* pch = strrchr(argv[0], '/');
	  int last_index = pch - argv[0] +1;
	  char* tmp_exec_path = new char[last_index +1];
	  strncpy(tmp_exec_path, argv[0], last_index);
	  tmp_exec_path[last_index] = '\0';

	  //take relative path from javascript file
	  char* p1ch = strrchr(argv[1], '/');
	  int last_index1 = p1ch - argv[1] +1;
	  char* tmp_js_path = new char[last_index1 +1];
	  strncpy(tmp_js_path, argv[1], last_index1);
	  tmp_js_path[last_index1] = '\0';

	  GlesFactory::root_path = new char[last_index + last_index1 +1];
	  strcpy(GlesFactory::root_path, tmp_exec_path);
	  strcat(GlesFactory::root_path, tmp_js_path);

	  delete[] tmp_exec_path;
	  delete[] tmp_js_path;
	  // Compile and run the script
	  if (!executeScript())
		return false;


	  return true;
}
