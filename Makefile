CC = g++
CFLAGS = -Wall -Iv8/include
PROG = v8-gl v8/libv8.a

SRCS = main.cpp v8-gl.cpp glbind.cpp glubind.cpp glutbind.cpp

LIBS = -lpthread -lglut

all: $(PROG)

$(PROG):	$(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(PROG) $(LIBS)

clean:
	rm -f $(PROG)
