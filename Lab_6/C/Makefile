CC = gcc
CFLAGS = -Wall -g
lab6: main.o lab6.o
	$(CC) $(CFLAGS) main.o lab6.o -o lab6

prog: main.o lab6.o
	$(CC) $(CFLAGS) main.o lab6.o -o lab6
	rm -rf *.o

main.o: main.c lab6.h
	$(CC) $(CFLAGS) -c main.c

lab6.o: lab6.c lab6.h
	$(CC) $(CFLAGS) -c lab6.c

clean:
	rm -rf *.o
	rm -rf lab6
