all: bst.o
	gcc -g bst.o -o bst

bst.o: bst.c
	gcc -c bst.c

run: all
	./bst

clean: 
	rm -rf bst.o bst