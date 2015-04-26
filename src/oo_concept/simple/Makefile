CC=gcc
CCFLAGS=-O2 -DNDEBUG -std=c11

SRC=
OBJS=Counter.o oo_main.o
LIBS=
EXEC=oo_main

all: $(OBJS) $(EXEC) 

%.o: %.c
	$(CC) $(CCFLAGS) $(INCLUDES) -c $< 
	
oo_main: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ oo_main.o Counter.o $(LIBS)

clean:
	$(RM) *.o *.so *.a $(EXEC)
