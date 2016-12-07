CC = g++
CFLAGS = -g 
COPTFLAGS = 
LIBFLAGS = -lglut -lGLU -lGL -lm
HEADERS = prototype.h
OBJECTS = collision.o asteroid.o window.o player.o tesselate.o

all : pristine sanic clean

sanic : main.o $(OBJECTS)
	$(CC) main.o $(OBJECTS) -o sanic $(LIBFLAGS)

main.o : main.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c main.cpp

asteroid.o : asteroid.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c asteroid.cpp

collision.o : collision.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c collision.cpp

window.o : window.cpp
	$(CC) $(CFLAGS) -c window.cpp

player.o : player.cpp
	$(CC) $(CFLAGS) -c player.cpp

tesselate.o : tesselate.cpp
	$(CC) $(CLFAGS) -c tesselate.cpp

clean :
	rm *.o

pristine :
	rm -f *.o 
	touch *.cpp

ctags :
	ctags *.cpp
