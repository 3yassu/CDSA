CC = gcc
CFLAGS = -Wall -g
lab_1: main.o lab_1.o
	$(CC) $(CFLAGS) main.o lab_1.o -o lab_1

prog: main.o lab_1.o
	$(CC) $(CFLAGS) main.o lab_1.o -o lab_1
	rm -rf *.o

main.o: main.c lab_1.h
	$(CC) $(CFLAGS) -c main.c

lab_1.o: lab_1.c lab_1.h
	$(CC) $(CFLAGS) -c lab_1.c

clean:
	rm -rf *.o
	rm -rf lab_1
