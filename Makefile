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


supp_liste.o : supp_liste.c
	$(CC) $(CFLAGS) -c supp_liste.c

supp_liste : supp_liste.o 
	$(CC) $(CFLAGS) -o supp_liste supp_liste.o


clean:
	$(RM) *.o *~ $(EXECUTABLES)
