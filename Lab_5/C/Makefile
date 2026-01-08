CC = gcc
CFLAGS = -Wall -g
lab_5: main.o lab_5.o
	$(CC) $(CFLAGS) main.o lab_5.o -o lab_5

prog: main.o lab_5.o
	$(CC) $(CFLAGS) main.o lab_5.o -o lab_5
	rm -rf *.o

main.o: main.c lab_5.h
	$(CC) $(CFLAGS) -c main.c

lab_5.o: lab_5.c lab_5.h
	$(CC) $(CFLAGS) -c lab_5.c

clean:
	rm -rf *.o
	rm -rf lab_5
