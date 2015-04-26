CC=gcc
CCFLAGS=-O2 -DNDEBUG -std=c11

OBJS=getopt_cli.o getoptlong_cli.o

LIBS=
EXEC=getopt_cli getoptlong_cli

all: $(EXEC) 

%.o: %.c
	$(CC) $(CCFLAGS) $(INCLUDES) -c $< 
	
getopt_cli: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ getopt_cli.o $(LIBS)
	
getoptlong_cli: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ getoptlong_cli.o $(LIBS)

clean:
	$(RM) *.o *.so *.a $(EXEC)
       