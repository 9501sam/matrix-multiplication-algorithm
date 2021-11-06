CC = gcc
CFLAGS = -Wall -O0

mm: mm.o malgo.o
	$(CC) $(CFLAGS) -o mm mm.o malgo.o

malgo.o: malgo.c
	$(CC) $(CFLAGS) -c malgo.c

mm.o: mm.c malgo.h
	$(CC) $(CFLAGS) -c mm.c

run: mm
	./mm

clean:
	$(RM) mm.o mm malgo.o

