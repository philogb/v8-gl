#ifndef V8GLUTILS_H_
#define V8GLUTILS_H_

namespace V8GLUtils {
		void setRootPath(char* program_path, char* jsfile_path);

		char* getRootPath(void);
		char* getRealPath(char* file_path);

		char *pushRootPath(char *new_path);
		void popRootPath(char *old_path);
};

#endif
