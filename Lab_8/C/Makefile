CC = gcc
CFLAGS = -Wall -Wextra -g
lab8: main.o union_find.o uf_dict.o kruskal_graph.o
	$(CC) $(CFLAGS) main.o union_find.o uf_dict.o kruskal_graph.o -o lab8

prog: main.o union_find.o uf_dict.o kruskal_graph.o
	$(CC) $(CFLAGS) main.o union_find.o uf_dict.o kruskal_graph.o -o lab8
	rm -rf *.o

main.o: main.c kruskal_graph.h
	$(CC) $(CFLAGS) -c main.c

kruskal_graph.o: kruskal_graph.c kruskal_graph.h union_find.h
	$(CC) $(CFLAGS) -c kruskal_graph.c

union_find.o: union_find.c union_find.h uf_dict.h
	$(CC) $(CFLAGS) -c union_find.c

uf_dict.o: uf_dict.c uf_dict.h
	$(CC) $(CFLAGS) -c uf_dict.c

clean:
	rm -rf *.o
	rm -rf lab8
