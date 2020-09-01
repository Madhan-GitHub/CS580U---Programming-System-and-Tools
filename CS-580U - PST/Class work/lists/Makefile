all: list.o program5.o
	gcc -g list.o program5.o -o program5

list.o: list.c
	gcc -c list.c

program5.o: program5.c
	gcc -c program5.c

run: all
	./program5

clean: 
	rm -rf program5.o list.o program5