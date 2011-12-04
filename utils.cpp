#include "utils.h"
#include <string>
#include <string.h>

namespace V8GLUtils {
	char separator = '/';
	char* root_path;

	void setRootPath(char* program_path, char* jsfile_path) {
	  //Set the root_path for opening shader files with
	  //relative paths
	  //take path from executable
	  char* pch = strrchr(program_path, V8GLUtils::separator);
	  int last_index = pch ? (pch - program_path +1) : 2;
	  char* tmp_exec_path = new char[last_index +1];
	  strncpy(tmp_exec_path, pch ? program_path : "./", last_index);
	  tmp_exec_path[last_index] = '\0';

	  //take relative path from javascript file
	  char* p1ch = strrchr(jsfile_path, V8GLUtils::separator);
	  int last_index1 = p1ch ? (p1ch - jsfile_path +1) : 2;
	  char* tmp_js_path = new char[last_index1 +1];
	  strncpy(tmp_js_path, p1ch ? jsfile_path : "./", last_index1);
	  tmp_js_path[last_index1] = '\0';

	  V8GLUtils::root_path = new char[last_index + last_index1 +1];

	  strcpy(V8GLUtils::root_path, tmp_exec_path);
	  strcat(V8GLUtils::root_path, tmp_js_path);

	  delete[] tmp_exec_path;
	  delete[] tmp_js_path;
	}

	char* getRootPath(void) {
		return V8GLUtils::root_path;
	}

	char* getRealPath(char* filepath_str) {
		//read the file source
		char* filename = NULL;
		if(filepath_str[0] != V8GLUtils::separator) {
		  filename = new char[strlen(V8GLUtils::root_path) + strlen(filepath_str) +1];
		  strcpy(filename, V8GLUtils::root_path);
		  strcat(filename, filepath_str);
		} else {
		  filename = new char[strlen(filepath_str) +1];
		  strcpy(filename, filepath_str);
		}
		return filename;
	}
};
