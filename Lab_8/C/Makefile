CC = gcc
CFLAGS = -Wall -Wextra -g
ALL = main.o union_find.o uf_dict.o kruskal_graph.o list.o prim_graph.o p_dict.o heap.o
all: $(ALL)
	$(CC) $(CFLAGS) $(ALL) -o lab8

prog: $(ALL)
	$(CC) $(ALL) -o lab8
	rm -rf *.o

main.o: main.c kruskal_graph.h
	$(CC) $(CFLAGS) -c main.c

kruskal_graph.o: kruskal_graph.c kruskal_graph.h union_find.h list.h
	$(CC) $(CFLAGS) -c kruskal_graph.c

prim_graph.o: prim_graph.c prim_graph.h list.h p_dict.h heap.h
	$(CC) $(CFLAGS) -c prim_graph.c

union_find.o: union_find.c union_find.h uf_dict.h
	$(CC) $(CFLAGS) -c union_find.c

uf_dict.o: uf_dict.c uf_dict.h
	$(CC) $(CFLAGS) -c uf_dict.c
	
list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c

p_dict.o: p_dict.c p_dict.h list.h
	$(CC) $(CFLAGS) -c p_dict.c
	
heap.o: heap.c heap.h 
	$(CC) $(CFLAGS) -c heap.c
clean:
	rm -rf *.o
	rm -rf lab8
