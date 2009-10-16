# Pull in platform specific settings.
include Makefile.$(firstword $(subst _, ,$(shell uname -s)))

CC = g++
CFLAGS := $(CFLAGS) -m32 -Wall -Iv8/include 
PROG = v8-gl 

SRCS = main.cpp imageloader.cpp utils.cpp v8-gl.cpp glbindings/glbind.cpp glesbindings/glesbind.cpp glubindings/glubind.cpp glutbindings/glutbind.cpp

all: $(PROG)

$(PROG):	$(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(PROG) $(LIBS)

clean:
	rm -f $(PROG)
