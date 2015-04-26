CC=gcc
CCFLAGS=-O2 -DNDEBUG -std=c11

SRC=
OBJS=
LIBS=
EXEC=getopt getoptlong

all: $(EXEC) 

%.o: %.c
	$(CC) $(CCFLAGS) $(INCLUDES) -c $< 
	
getopt: getopt_main.o
	$(CC) $(LDFLAGS) -o $@ getopt_main.o $(OBJS) $(LIBS)
	
getoptlong: getoptlong_main.o
	$(CC) $(LDFLAGS) -o $@ getoptlong_main.o $(OBJS) $(LIBS)

clean:
	$(RM) *.o *.so *.a $(EXEC)
