CC=gcc
CFLAGS=-Wall -ansi -pedantic

all: main

main: main.o doublyList.o
	$(CC) main.o doublyList.o -o doublyList

main.o: main.c doublyList.h
	$(CC) $(CFLAGS) -c main.c -o $@

doublyList.o: doublyList.c doublyList.h
	$(CC) $(CFLAGS) -c doublyList.c -o $@

clean:
	rm *.o
