/* Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above notice and this permission notice shall be included in all copies
 * or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
/* File for "Putting It All Together" lesson of the OpenGL tutorial on
 * www.videotutorialsrock.com
 */



#include <assert.h>
#include <fstream>

#include "imageloader.h"

using namespace std;

Image::Image(char* ps, int w, int h) : pixels(ps), width(w), height(h) {

}

Image::~Image() {
	delete[] pixels;
}

namespace {
	//Converts a four-character array to an integer, using big-endian form
	int toInt(const char* bytes) {
		return (int)(((unsigned char)bytes[0] << 24) |
					 ((unsigned char)bytes[1] << 16) |
					 ((unsigned char)bytes[2] << 8) |
					 (unsigned char)bytes[3]);
	}

	//Converts a two-character array to a short, using little-endian form
	short toShort(const char* bytes) {
		return (short)(((unsigned char)bytes[1] << 8) |
					   (unsigned char)bytes[0]);
	}

	//Reads the next four bytes as an integer, using big-endian form
	int readInt(ifstream &input) {
		char buffer[4];
		input.read(buffer, 4);
		return toInt(buffer);
	}

	//Reads the next two bytes as a short, using little-endian form
	short readShort(ifstream &input) {
		char buffer[2];
		input.read(buffer, 2);
		return toShort(buffer);
	}

	//Just like auto_ptr, but for arrays
	template<class T>
	class auto_array {
		private:
			T* array;
			mutable bool isReleased;
		public:
			explicit auto_array(T* array_ = NULL) :
				array(array_), isReleased(false) {
			}

			auto_array(const auto_array<T> &aarray) {
				array = aarray.array;
				isReleased = aarray.isReleased;
				aarray.isReleased = true;
			}

			~auto_array() {
				if (!isReleased && array != NULL) {
					delete[] array;
				}
			}

			T* get() const {
				return array;
			}

			T &operator*() const {
				return *array;
			}

			void operator=(const auto_array<T> &aarray) {
				if (!isReleased && array != NULL) {
					delete[] array;
				}
				array = aarray.array;
				isReleased = aarray.isReleased;
				aarray.isReleased = true;
			}

			T* operator->() const {
				return array;
			}

			T* release() {
				isReleased = true;
				return array;
			}

			void reset(T* array_ = NULL) {
				if (!isReleased && array != NULL) {
					delete[] array;
				}
				array = array_;
			}

			T* operator+(int i) {
				return array + i;
			}

			T &operator[](int i) {
				return array[i];
			}
	};


}

Image* loadBMP(const char* filename) {
	ifstream input;
	input.open(filename, ifstream::binary);
	assert(!input.fail() || !"Could not find file");
	char buffer[2];
	input.read(buffer, 2);
	assert((buffer[0] == 'B' && buffer[1] == 'M') || !"Not a bitmap file");
	input.ignore(8);
	int dataOffset = readInt(input);

	//Read the header
	int headerSize = readInt(input);
	int width;
	int height;
	switch(headerSize) {
		case 40:
			//V3
			width = readInt(input);
			height = readInt(input);
			input.ignore(2);
			assert(readShort(input) == 24 || !"Image is not 24 bits per pixel");
			assert(readShort(input) == 0 || !"Image is compressed");
			break;
		case 12:
			//OS/2 V1
			width = readShort(input);
			height = readShort(input);
			input.ignore(2);
			assert(readShort(input) == 24 || !"Image is not 24 bits per pixel");
			break;
		case 64:
			//OS/2 V2
			assert(!"Can't load OS/2 V2 bitmaps");
			break;
		case 108:
			//Windows V4
			assert(!"Can't load Windows V4 bitmaps");
			break;
		case 124:
			//Windows V5
			assert(!"Can't load Windows V5 bitmaps");
			break;
		default:
			assert(!"Unknown bitmap format");
	}

	//Read the data
	int bytesPerRow = ((width * 3 + 3) / 4) * 4 - (width * 3 % 4);
	int size = bytesPerRow * height;
	auto_array<char> pixels(new char[size]);
	input.seekg(dataOffset, ios_base::beg);
	input.read(pixels.get(), size);

	//Get the data into the right format
	auto_array<char> pixels2(new char[width * height * 3]);
	for(int y = 0; y < height; y++) {
		for(int x = 0; x < width; x++) {
			for(int c = 0; c < 3; c++) {
				pixels2[3 * (width * y + x) + c] =
					pixels[bytesPerRow * y + 3 * x + (2 - c)];
			}
		}
	}

	input.close();
	return new Image(pixels2.release(), width, height);
}

Image* loadPNG(const char* filename) {
	ifstream input;
	input.open(filename, ifstream::binary);
	assert(!input.fail() || !"Could not find file");
	//check if png file
	char buffer[8];
	input.read(buffer, 8);
	assert((buffer[1] == 'P' && buffer[2] == 'N' && buffer[3] == 'G')
			|| !"Not a png file");

	char* data;
	int width, height;

	//read header
	char type_buffer[4];
	//read header length
	int len = readInt(input);
	printf("%d - len\n", len);
	input.read(type_buffer, 4);
	if(type_buffer[0] == 'I' && type_buffer[1] == 'H'
			&& type_buffer[2] == 'D' && type_buffer[3] == 'R') {
		//grab width and height
		width = readInt(input);
		height = readInt(input);

		printf("\n\nheader - width: %d, height: %d\n\n", width, height);
		//read other header options like color type, bit depths
		char buff[5];
		input.read(buff, 5);
		//check for RGB pixel data
		if((buff[0] == 8 || buff[0] == 16)
				&& buff[1] == 2) {
			input.ignore(4); //CRC
			//store data.
			data = new char[width * height * 3];
			int len_accum = 0;
			int len = 0;
			//read all data chunks
			len = readInt(input);
			input.read(type_buffer, 4);
			while(!(type_buffer[0] == 'I' && type_buffer[1] == 'E'
					&& type_buffer[2] == 'N' && type_buffer[3] == 'D')) {
				printf("%c-%c-%c-%c ", type_buffer[0], type_buffer[1], type_buffer[2], type_buffer[3]);
				if(type_buffer[0] == 'I' && type_buffer[1] == 'D'
						&& type_buffer[2] == 'A' && type_buffer[3] == 'T') {
					printf("data\n\n");
//					char* d = new char[len];
//					input.read(d, len);
//					for(int i=0; i < len; i++) {
//						data[len_accum + (len - i - 1)] = d[i];
//					}
//					delete[] d;
					input.read(data + len_accum, len);
					len_accum += len;
				} else {
					printf("not data\n\n");
					input.ignore(len);
				}

				input.ignore(4); //CRC
				len = readInt(input);
				input.read(type_buffer, 4);
			}
		} else {
			//TODO(nico) take care of other png formats also
			return NULL;
		}
	} else {
		return NULL;
	}

	input.close();
	return new Image(data, width, height);
}







