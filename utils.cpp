#include "utils.h"
#include <string>

namespace Utils {
	char separator = '/';
	char* root_path;

	void setRootPath(char* program_path, char* jsfile_path) {
	  //Set the root_path for opening shader files with
	  //relative paths
	  //take path from executable
	  char* pch = strrchr(program_path, Utils::separator);
	  int last_index = pch - program_path +1;
	  char* tmp_exec_path = new char[last_index +1];
	  strncpy(tmp_exec_path, program_path, last_index);
	  tmp_exec_path[last_index] = '\0';

	  //take relative path from javascript file
	  char* p1ch = strrchr(jsfile_path, Utils::separator);
	  int last_index1 = p1ch - jsfile_path +1;
	  char* tmp_js_path = new char[last_index1 +1];
	  strncpy(tmp_js_path, jsfile_path, last_index1);
	  tmp_js_path[last_index1] = '\0';

	  Utils::root_path = new char[last_index + last_index1 +1];

	  strcpy(Utils::root_path, tmp_exec_path);
	  strcat(Utils::root_path, tmp_js_path);

	  delete[] tmp_exec_path;
	  delete[] tmp_js_path;
	}

	char* getRootPath(void) {
		return Utils::root_path;
	}

	char* getRealPath(char* filepath_str) {
		//read the file source
		char* filename = NULL;
		if(filepath_str[0] != Utils::separator) {
		  filename = new char[strlen(Utils::root_path) + strlen(filepath_str) +1];
		  strcpy(filename, Utils::root_path);
		  strcat(filename, filepath_str);
		} else {
		  filename = new char[strlen(filepath_str) +1];
		  strcpy(filename, filepath_str);
		}
		return filename;
	}
};
