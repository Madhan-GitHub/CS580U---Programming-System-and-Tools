all: defuseTheBomb checkmem clean

defuseTheBomb: hidden.o bomb.o defuseMe.o
	gcc -g hidden.o bomb.o defuseMe.o -o defuseTheBomb

bomb.o: bomb.c
	gcc -g -c bomb.c -o bomb.o

defuseMe.o: defuseMe.c
	gcc -g -c defuseMe.c -o defuseMe.o

checkmem: program3B.c
	gcc program3B.c -c
	gcc -Wall -g program3B.o -o checkmem
	valgrind ./checkmem

clean: trash.sh
	chmod +x trash.sh
	./trash.sh bomb.o defuseMe.o program3B.o defuseTheBomb checkmem
