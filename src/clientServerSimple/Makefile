CC=gcc
CCFLAGS=-O2

SVR_SRC=server.c server_cli.c
SVR_OBJS=server.o server_cli.o log.o

CNT_SRC=client.c client_cli.c
CNT_OBJS=client.o client_cli.o log.o

LIBS=
EXEC=client_cli server_cli

all: $(EXEC) 

%.o: %.c
	$(CC) $(CCFLAGS) $(INCLUDES) -c $< 

client_cli: $(CNT_OBJS)
	$(CC) $(LDFLAGS) -o $@ $(CNT_OBJS) $(LIBS)
	
server_cli: $(SVR_OBJS)
	$(CC) $(LDFLAGS) -o $@ $(SVR_OBJS) $(LIBS)

clean:
	$(RM) *.o *.so *.a $(EXEC)
       