#include <v8.h>

#include "v8-gl.h"
#include <string>

using namespace v8;

void ParseOptions(int argc,
                  char* argv[],
                  string* file) {
  for (int i = 1; i < argc; i++) {
    std::string arg = argv[i];
    size_t index = arg.find('=', 0);
    if (index == std::string::npos) {
      *file = arg;
    } else {
      std::string key = arg.substr(0, index);
      std::string value = arg.substr(index+1);
    }
  }
}

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

int main(int argc, char* argv[]) {
	  string file;
	  ParseOptions(argc, argv, &file);
	  if (file.empty()) {
	    fprintf(stderr, "No script was specified.\n");
	    return 1;
	  }

	  HandleScope scope;
	  Handle<String> source = ReadFile(file);
	  if (source.IsEmpty()) {
	    fprintf(stderr, "Error reading '%s'.\n", file.c_str());
	    return 1;
	  }
	  V8GL v8gl(source);
	  if(!v8gl.initialize(&argc, argv)) {
		    fprintf(stderr, "Error initializing script.\n");
		    return 1;
	  }

	  return 0;
}
