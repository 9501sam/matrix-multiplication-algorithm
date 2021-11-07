CC = gcc
CFLAGS = -Wall -O1

mm: mm.o malgo.o
	$(CC) $(CFLAGS) -o mm mm.o malgo.o

malgo.o: malgo.c
	$(CC) $(CFLAGS) -c malgo.c

mm.o: mm.c malgo.h
	$(CC) $(CFLAGS) -c mm.c

run: mm mm.c malgo.c malgo.h
	./mm -a

run-perf: mm mm.c malgo.c malgo.h
	sudo perf stat -d -d -d ./mm -1
	sudo perf stat -d -d -d ./mm -2
	sudo perf stat -d -d -d ./mm -3
	sudo perf stat -d -d -d ./mm -4
	sudo perf stat -d -d -d ./mm -5

clean:
	$(RM) mm.o mm malgo.o

