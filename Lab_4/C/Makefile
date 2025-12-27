CC = gcc
CFLAGS = -Wall -g
lab_4: main.o lab_4.o
	$(CC) $(CFLAGS) main.o lab_4.o -o lab_4

prog: main.o lab_4.o
	$(CC) $(CFLAGS) main.o lab_4.o -o lab_4
	rm -rf *.o

main.o: main.c lab_4.h
	$(CC) $(CFLAGS) -c main.c

lab_4.o: lab_4.c lab_4.h
	$(CC) $(CFLAGS) -c lab_4.c

clean:
	rm -rf *.o
	rm -rf lab_4
