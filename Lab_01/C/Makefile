CC = gcc
CFLAGS = -Wall -g
lab_01: main.o lab_01.o
	$(CC) $(CFLAGS) main.o lab_01.o -o lab_01

prog: main.o lab_01.o
	$(CC) $(CFLAGS) main.o lab_01.o -o lab_01
	rm -rf *.o

main.o: main.c lab_01.h
	$(CC) $(CFLAGS) -c main.c

lab_01.0: lab_01.c lab_01.h
	$(CC) $(CFLAGS) -c lab_01.c

clean:
	rm -rf *.o
	rm -rf lab_01
