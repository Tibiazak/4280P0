all: P0

P0: main.o
	gcc -Wall -o P0 main.o tree.o

main.o: main.c
	gcc -Wall -c main.c tree.c node.h

clean:
	rm *.o *.gch P0
