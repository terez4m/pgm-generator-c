CFLAGS = -Wall -g  # flags de compilacao

CC = gcc

# arquivos-objeto
	objects = libgerador.o 

all: libgerador.o 
	$(CC) $(CFLAGS) -o gerador_pgm  libgerador.o  gerador_pgm.c

libgerador.o: libgerador.c
	$(CC) $(CFLAGS) -c libgerador.c

clean:
	rm -f $(objects) gerador_pgm
