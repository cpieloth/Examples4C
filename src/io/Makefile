CC=gcc
CCFLAGS=-O2 -DNDEBUG

SRC=person.c person_io.c person_rw_cli.c
OBJS=person.o person_io.o person_rw_cli.o log.o

LIBS=-lm
EXEC=person_rw_cli

all: $(EXEC) 

%.o: %.c
	$(CC) $(CCFLAGS) $(INCLUDES) -c $< 
	
person_rw_cli: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS) $(LIBS)

clean:
	$(RM) *.o *.so *.a $(EXEC)
       