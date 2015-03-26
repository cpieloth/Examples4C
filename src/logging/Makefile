CC=gcc
CCFLAGS=-O2 -DNDEBUG

# OBJS=log_stdout.o log_cli.o # logging to stdout
OBJS=log_syslog.o log_cli.o # logging to syslog

LIBS=
EXEC=log_cli

all: $(EXEC) 

%.o: %.c
	$(CC) $(CCFLAGS) $(INCLUDES) -c $< 
	
log_cli: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS) $(LIBS)

clean:
	$(RM) *.o *.so *.a $(EXEC)
       