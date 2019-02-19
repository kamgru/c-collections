CC=gcc

build: DLList Hashtable

Hashtable: src/Hashtable.c
	$(CC) -Wall -g -c src/Hashtable.c -o bin/Hashtable.o

DLList: src/DLList.c
	$(CC) -Wall -g -c src/DLList.c -o bin/DLList.o

DLListTests: DLList
	$(CC) -g test/DLListTests.c bin/DLList.o -o bin/DLListTests

HashtableTests: Hashtable DLList
	$(CC) -g test/HashtableTests.c bin/Hashtable.o bin/DLList.o -o bin/HashtableTests

test: build DLListTests HashtableTests
	./bin/DLListTests
	./bin/HashtableTests