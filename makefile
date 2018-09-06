all: P0

P0: main.o
	gcc -Wall -o P0 main.o

main.o: main.c
	gcc -Wall -c main.c

clean:
	rm *.o P0