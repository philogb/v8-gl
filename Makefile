# Pull in platform specific settings.
include Makefile.$(firstword $(subst _, ,$(shell uname -s)))

CC = g++
CFLAGS := $(CFLAGS) -m32 -Wall -Iv8/include 
PROG = v8-gl 

BUILD_GL_BINDINGS=1
BUILD_GLES_BINDINGS=1
BUILD_GLU_BINDINGS=1
BUILD_GLUT_BINDINGS=1

SRCS = main.cpp imageloader.cpp utils.cpp v8-gl.cpp \
	v8-typed-array/typed-array.cc

ifdef BUILD_GL_BINDINGS
SRCS += glbindings/glbind.cpp
CFLAGS += -DBUILD_GL_BINDINGS
endif

ifdef BUILD_GLES_BINDINGS
SRCS += glesbindings/glesbind.cpp
CFLAGS += -DBUILD_GLES_BINDINGS
endif

ifdef BUILD_GLU_BINDINGS
SRCS += glubindings/glubind.cpp
CFLAGS += -DBUILD_GLU_BINDINGS
endif

ifdef BUILD_GLUT_BINDINGS
SRCS += glutbindings/glutbind.cpp
CFLAGS += -DBUILD_GLUT_BINDINGS
endif

all: $(PROG)

$(PROG):	$(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(PROG) $(LIBS)

clean:
	rm -f $(PROG)
