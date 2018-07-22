CC:=gcc
CFLAGS:=-Wall -O3 -I.
LDFLAGS:=-lm

all: list.o tree.o util.o solution.o tests.o main.o
	gcc -o app  list.o tree.o util.o solution.o tests.o main.o $(LDFLAGS)

list.o:
	$(CC) $(CFLAGS) -c list.c

tree.o:
	$(CC) $(CFLAGS) -c tree.c
	
util.o:
	$(CC) $(CFLAGS) -c util.c
	
solution.o:
	$(CC) $(CFLAGS) -c solution.c
	
tests.o:
	$(CC) $(CFLAGS) -c tests.c
	
main.o:
	$(CC) $(CFLAGS) -c main.c
	
clean:
	rm -f *.o
	rm -f *.exe
