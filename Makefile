CC = g++
CFLAGS = -m32 -Wall -Iv8/include 
PROG = v8-gl 

SRCS = main.cpp v8-gl.cpp glbindings/glbind.cpp glesbindings/glesbind.cpp glubindings/glubind.cpp glutbindings/glutbind.cpp

LIBS =  v8/libv8.a -lpthread -lglut -lGLU -lGL

all: $(PROG)

$(PROG):	$(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(PROG) $(LIBS)

clean:
	rm -f $(PROG)
