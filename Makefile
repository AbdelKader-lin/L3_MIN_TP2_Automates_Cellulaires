CC = gcc
RM = rm -f
CFLAGS = -Wall
SRC = ps.c psm.c
OBJECTS=$ ( SRC : . c =. o )
EXECUTABLES = $(SOURCES:.c=)

all : $(EXECUTABLES)


aut.o : aut.c
	$(CC) $(CFLAGS) -c aut.c

aut : aut.o 
	$(CC) $(CFLAGS) -o aut aut.o 


clean:
	$(RM) *.o *~ $(EXECUTABLES)
