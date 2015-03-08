CC=gcc
CCFLAGS=-O2 -DNDEBUG -std=c99
#CCFLAGS=-O0 -g -std=c99

SRC=list.c list_cli.c
OBJS=list.o list_cli.o

LIBS=
EXEC=list_cli

all: $(EXEC) 

%.o: %.c
	$(CC) $(CCFLAGS) $(INCLUDES) -c $< 
	
list_cli: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS) $(LIBS)

clean:
	$(RM) *.o *.so *.a $(EXEC)
       