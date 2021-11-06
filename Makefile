CC = gcc
CFLAGS = -Wall -O3 -g

mm: mm.o malgo.o
	$(CC) $(CFLAGS) -o mm mm.o malgo.o

malgo.o: malgo.c
	$(CC) $(CFLAGS) -c malgo.c

mm.o: mm.c malgo.h
	$(CC) $(CFLAGS) -c mm.c

100:
	$(CC) $(CFLAGS) -c mm.c -DBLK_SIZE=100

run: mm
	./mm

clean:
	$(RM) mm.o mm malgo.o

