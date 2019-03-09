CC = gcc
PR = 
LDFLAGS = -lSDL2_image -lSDL2 -lstdc++
src = $(wildcard src/*.cpp)\
	  $(wildcard src/objects/*.cpp)\
	  
obj = $(src:.cpp=.o)

all: main

main: $(obj)
	$(CC) $(PR) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(obj) main
