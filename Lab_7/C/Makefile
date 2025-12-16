CC = gcc
CFLAGS = -Wall -g
lab7: main.o lab7.o
	$(CC) $(CFLAGS) main.o lab7.o -o lab7

prog: main.o lab7.o
	$(CC) $(CFLAGS) main.o lab7.o -o lab7
	rm -rf *.o

main.o: main.c lab7.h
	$(CC) $(CFLAGS) -c main.c

lab6.o: lab7.c lab7.h
	$(CC) $(CFLAGS) -c lab7.c

clean:
	rm -rf *.o
	rm -rf lab7
