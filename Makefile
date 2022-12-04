CC:=gcc
DBGFLAGS:=
OPTFLAGS:=-O3
INCLUDES:=-I.
CFLAGS:=-Wall $(DBGFLAGS) $(OPTFLAGS) $(INCLUDES) -Wl,-z,noexecstack -fcf-protection -fPIE -fstack-protector-strong
#-mfunction-return=thunk
STATICFLAGS:=-static-libgcc -static
LDFLAGS:=-lm -pie
OBJDIR:=obj
BIN:=app

OBJECTS:=$(OBJDIR)/*.o

all: objects
	$(CC) -o $(BIN) $(OBJECTS) $(LDFLAGS)

static: objects
	$(CC) -o $(BIN) $(OBJECTS) $(LDFLAGS) $(STATICFLAGS)

prepare:
	mkdir -p $(OBJDIR)

objects: prepare list.o tree.o util.o solution.o tests.o main.o

list.o:
	$(CC) $(CFLAGS) -c list.c -o $(OBJDIR)/list.o

tree.o:
	$(CC) $(CFLAGS) -c tree.c -o $(OBJDIR)/tree.o

util.o:
	$(CC) $(CFLAGS) -c util.c -o $(OBJDIR)/util.o

solution.o:
	$(CC) $(CFLAGS) -c solution.c -o $(OBJDIR)/solution.o

tests.o:
	$(CC) $(CFLAGS) -c tests.c -o $(OBJDIR)/tests.o

main.o:
	$(CC) $(CFLAGS) -c main.c -o $(OBJDIR)/main.o

clean:
	rm -f $(BIN)
	rm -rf $(OBJDIR)
