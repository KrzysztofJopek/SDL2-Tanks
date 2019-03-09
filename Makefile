CC = gcc
PR = 

all: main

main: app.o renderer.o controls.o
	$(CC) $(PR) main.cpp app.o renderer.o controls.o -o main -lSDL2_image -lSDL2 -lstdc++

app.o: app.cpp app.h
	$(CC) $(PR) -c app.cpp -o app.o 

renderer.o: renderer.cpp renderer.h
	$(CC) $(PR) -c renderer.cpp -o renderer.o 

controls.o: controls.cpp controls.h
	$(CC) $(PR) -c controls.cpp -o controls.o 

clean:
	rm *.o main
