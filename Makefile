CC:=gcc
CFLAGS:=-Wall -O3 -I.

all: list.o tree.o list.o main.o 
	gcc -o app.exe $(LDFLAGS) list.o tree.o main.o

list.o:
	$(CC) $(CFLAGS) -c list.c

tree.o:
	$(CC) $(CFLAGS) -c tree.c
	
main.o:
	$(CC) $(CFLAGS) -c main.c
	
clean:
	rm -f *.o
	rm -f *.exe