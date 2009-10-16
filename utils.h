#ifndef UTILS_H_
#define UTILS_H_

namespace Utils {
		void setRootPath(char* program_path, char* jsfile_path);

		char* getRootPath(void);
		char* getRealPath(char* file_path);
};

#endif
