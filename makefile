CC = g++
CFLAGS = -g 
COPTFLAGS = 
LIBFLAGS = -lglut -lGLU -lGL -lm
HEADERS = prototype.h
OBJECTS = collision.o asteroid.o window.o

main : main.o $(OBJECTS)
	$(CC) main.o $(OBJECTS) -o main $(LIBFLAGS)

main.o : main.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c main.cpp

asteroid.o : asteroid.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c asteroid.cpp

collision.o : collision.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c collision.cpp

window.o : window.cpp
	$(CC) $(CFLAGS) -c window.cpp

clean :
	rm *.o

pristine :
	rm *.o
	touch *.c

ctags :
	ctags *.c
