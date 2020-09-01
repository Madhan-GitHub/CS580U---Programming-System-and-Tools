all: program7

program7: program7.o heap.o
	gcc program7.o heap.o -o program7

program7.o: program7.c heap.h
	gcc -c program7.c -o program7.o

heap.o: heap.c heap.h
	gcc -c heap.c -o heap.o

run: all
	./program7

checkmem: all
	valgrind -v ./program7

clean:
	rm -f *.o program7