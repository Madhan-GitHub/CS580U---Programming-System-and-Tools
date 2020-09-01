all: stack.o queue.o classwork2.o
	gcc -g stack.o queue.o classwork2.o -o classwork2

stack.o: stack.c
	gcc -c stack.c

queue.o: queue.c
	gcc -c queue.c

classwork2.o: classwork2.c
	gcc -c classwork2.c

run: all
	./classwork2

clean: 
	rm -rf stack.o classwork2.o queue.o classwork2

checkmem: all
	valgrind --leak-check=full --show-leak-kinds=all ./classwork2