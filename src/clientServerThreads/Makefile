CC=gcc
CCFLAGS=-O2

SVR_SRC=server.c server_cli.c
SVR_OBJS=server.o server_cli.o log.o

LDFLAGS=-pthread
LIBS=
EXEC=server_cli

all: $(EXEC) 

%.o: %.c
	$(CC) $(CCFLAGS) $(INCLUDES) -c $< 
	
server_cli: $(SVR_OBJS)
	$(CC) $(LDFLAGS) -o $@ $(SVR_OBJS) $(LIBS)

clean:
	$(RM) *.o *.so *.a $(EXEC)
       