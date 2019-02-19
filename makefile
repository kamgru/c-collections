CC=gcc

build: src/DLList.c
	$(CC) -Wall -g -c src/DLList.c -o bin/DLList.o

test: build
	$(CC) -g test/DLListTests.c bin/DLList.o -o bin/DLListTests
	
