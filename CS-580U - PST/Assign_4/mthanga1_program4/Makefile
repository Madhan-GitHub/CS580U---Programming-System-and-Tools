all: program4 run checkmem clean

program4:program4.o tournament.o
	gcc -g program4.o tournament.o -o program4

program4.o: program4.c
	gcc -g -c program4.c -o program4.o

tournament.o:tournament.c 
	gcc -g -c tournament.c -o tournament.o

run: program4
	./program4

checkmem:program4
	valgrind ./program4

clean:
	rm program4.o tournament.o program4