CXXFLAGS:=-O3 -I.

all: list.o main.o
	gcc -o app.exe list.o main.o

list.o:
	gcc $(CXXFLAGS) -c list.c
	
main.o:
	gcc $(CXXFLAGS) -c main.c
	
clean:
	rm -f *.o
	rm -f *.exe