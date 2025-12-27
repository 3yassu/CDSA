CC = gcc
CFLAGS = -Wall -g
lab_2: main.o lab_2.o
	$(CC) $(CFLAGS) main.o lab_2.o -o lab_2

prog: main.o lab_2.o
	$(CC) $(CFLAGS) main.o lab_2.o -o lab_2
	rm -rf *.o

main.o: main.c lab_2.h
	$(CC) $(CFLAGS) -c main.c

lab_2.o: lab_2.c lab_2.h
	$(CC) $(CFLAGS) -c lab_2.c

clean:
	rm -rf *.o
	rm -rf lab_2
