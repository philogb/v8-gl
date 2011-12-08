/*
 * v8-gl.cpp
 *
 */

#include "v8-gl.h"
#include <assert.h>
#include <stdio.h>
#include <string>
#include <string.h>

extern "C" void
v8_typed_array_init (Handle<Object> target);

Persistent<Context> V8GL::context;

//UTILITY FUNCTIONS
// Reads a file into a v8 string.
Handle<String> ReadFile(const string& name) {
  FILE* file = fopen(name.c_str(), "rb");
  if (file == NULL) return Handle<String>();

  fseek(file, 0, SEEK_END);
  int size = ftell(file);
  rewind(file);

  char* chars = new char[size + 1];
  chars[size] = '\0';
  for (int i = 0; i < size;) {
    int read = fread(&chars[i], 1, size - i, file);
    i += read;
  }
  fclose(file);
  Handle<String> result = String::New(chars, size);
  delete[] chars;
  return result;
}

bool exec(string file) {
  HandleScope handle_scope;
  Handle<String> source = ReadFile(file);

  if (source.IsEmpty()) {
	fprintf(stderr, "Error reading '%s'.\n", file.c_str());
	return false;
  }

  // We're just about to compile the script; set up an error handler to
  // catch any exceptions the script might throw.
  TryCatch try_catch;

  // Compile the script and check for errors.
  Handle<Script> compiled_script = Script::Compile(source,
						   String::New(file.c_str()));
  if (compiled_script.IsEmpty()) {
	V8GL::ReportException(&try_catch);
	// The script failed to compile; bail out.
	return false;
  }

  // Run the script!
  Handle<Value> result = compiled_script->Run();
  if (result.IsEmpty()) {
	// The TryCatch above is still in effect and will have caught the error.
	assert(try_catch.HasCaught());
	V8GL::ReportException(&try_catch);
	// Running the script failed; bail out.
	return false;
  }
  return true;
}

// nicer exception handling (borrowed from d8)
const char* V8GL::ToCString(const v8::String::Utf8Value& value) {
  return *value ? *value : "<string conversion failed>";
}
void V8GL::ReportException(v8::TryCatch* try_catch) {
  HandleScope handle_scope;
  v8::String::Utf8Value exception(try_catch->Exception());
  const char* exception_string = ToCString(exception);
  Handle<Message> message = try_catch->Message();
  if (message.IsEmpty()) {
    // V8 didn't provide any extra information about this error; just
    // print the exception.
    printf("%s\n", exception_string);
  } else {
    // Print (filename):(line number): (message).
    v8::String::Utf8Value filename(message->GetScriptResourceName());
    const char* filename_string = ToCString(filename);
    int linenum = message->GetLineNumber();
    printf("%s:%i: %s\n", filename_string, linenum, exception_string);
    // Print line of source code.
    v8::String::Utf8Value sourceline(message->GetSourceLine());
    const char* sourceline_string = ToCString(sourceline);
    printf("%s\n", sourceline_string);
    // Print wavy underline (GetUnderline is deprecated).
    int start = message->GetStartColumn();
    for (int i = 0; i < start; i++) {
      printf(" ");
    }
    int end = message->GetEndColumn();
    for (int i = start; i < end; i++) {
      printf("^");
    }
    printf("\n");
    v8::String::Utf8Value stack_trace(try_catch->StackTrace());
    if (stack_trace.length() > 0) {
      const char* stack_trace_string = ToCString(stack_trace);
      printf("%s\n", stack_trace_string);
    }
  }
}

//FUNCTIONS IN GLOBAL SCOPE

//prints a string to stdout
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

//loads a js file
Handle<Value> load(const Arguments& args) {
  //if less that nbr of formal parameters then do nothing
  int len = args.Length();
  int i;

  if (len < 1) return v8::Undefined();
  //define handle scope
  HandleScope scope;

  // Enter the new context so all the following operations take place
  // within it.
  Context::Scope context_scope(V8GL::context);

  for (i = 0; i < len; ++i) {
	  //get argument
	  String::Utf8Value value0(args[i]);
	  char* arg0 = *value0;
	  char* filepath = V8GLUtils::getRealPath(arg0);

	  char *old_path = V8GLUtils::pushRootPath(filepath);
	  bool success = exec(string(filepath));
	  V8GLUtils::popRootPath(old_path);

	  if(!success) {
		  fprintf(stderr, "Error reading '%s'.\n", arg0);
		  return ThrowException(String::New("Failed to load script"));
	  }
  }

  return v8::Undefined();
}

bool V8GL::executeScript(string file) {
	return exec(file);
}

bool V8GL::initialize(int* pargc, char** argv, string scriptname) {
	  // Create a handle scope to hold the temporary references.
	  HandleScope handle_scope;

	  // Create a template for the global object where we set the
	  // built-in global functions.
	  Handle<ObjectTemplate> global = ObjectTemplate::New();

	  // Each processor gets its own context so different processors
	  // don't affect each other.
#ifdef BUILD_GL_BINDINGS
	  Handle<ObjectTemplate> Gl = GlFactory::createGl();
#endif
#ifdef BUILD_GLES_BINDINGS
	  Handle<ObjectTemplate> Gles = GlesFactory::createGles();
#endif

	  //Set global objects and functions.
#ifdef BUILD_GL_BINDINGS
	  global->Set(String::New("Gl"), Gl);
#endif
#ifdef BUILD_GLES_BINDINGS
	  global->Set(String::New("Gles"), Gles);
#endif
#ifdef BUILD_GLU_BINDINGS
	  global->Set(String::New("Glu"), createGlu());
#endif
#ifdef BUILD_GLUT_BINDINGS
	  global->Set(String::New("Glut"), GlutFactory::createGlut(pargc, argv));
#endif
	  global->Set(String::New("log"), FunctionTemplate::New(log));
	  global->Set(String::New("load"), FunctionTemplate::New(load));

	  Handle<Context> context = Context::New(NULL, global);

	  //TODO(nico): should find another way to set the right context when calling a func.
	  V8GL::context = Persistent<Context>::New(context);
#ifdef BUILD_GLUT_BINDINGS
	  GlutFactory::glut_persistent_context = V8GL::context;
#endif
#ifdef BUILD_GLES_BINDINGS
	  GlesFactory::gles_persistent_context = V8GL::context;
#endif

	  // Enter the new context so all the following operations take place
	  // within it.
	  Context::Scope context_scope(context);
	  // hook up typed array support
	  v8_typed_array_init(context->Global());

	  //Append *this* as Gl static variable so we can do dot-this-dot-that stuff
#ifdef BUILD_GL_BINDINGS
	  GlFactory::self_ = Persistent<Object>::New(Gl->NewInstance());
#endif
#ifdef BUILD_GLES_BINDINGS
	  GlesFactory::self_ = Persistent<Object>::New(Gles->NewInstance());
#endif

	  //Set (only once) the absolute path for the .js file being executed.
	  V8GLUtils::setRootPath(argv[0], argv[1]);

	  // Compile and run the script
	  if (!executeScript(scriptname))
		return false;

	  return true;
}
