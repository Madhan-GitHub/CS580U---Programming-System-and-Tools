all: mthanga1_program9

mthanga1_program9: mthanga1_program9.o mthanga1_Hash.o
	gcc mthanga1_program9.o mthanga1_Hash.o -o mthanga1_program9

mthanga1_program9.o: mthanga1_program9.c mthanga1_Hash.h
	gcc -c -g mthanga1_program9.c -o mthanga1_program9.o

mthanga1_Hash.o: mthanga1_Hash.c mthanga1_Hash.h
	gcc -c -g mthanga1_Hash.c -o mthanga1_Hash.o

run: all
	./mthanga1_program9

checkmem: all
	valgrind -v --leak-check=full ./mthanga1_program9

clean:
	rm -f *.o mthanga1_program9