CC = gcc
CFLAGS = -Wall -g
lab_3: main.o lab_3.o
	$(CC) $(CFLAGS) main.o lab_3.o -o lab_3

prog: main.o lab_3.o
	$(CC) $(CFLAGS) main.o lab_3.o -o lab_3
	rm -rf *.o

main.o: main.c lab_3.h
	$(CC) $(CFLAGS) -c main.c

lab_3.o: lab_3.c lab_3.h
	$(CC) $(CFLAGS) -c lab_3.c

clean:
	rm -rf *.o
	rm -rf lab_3
