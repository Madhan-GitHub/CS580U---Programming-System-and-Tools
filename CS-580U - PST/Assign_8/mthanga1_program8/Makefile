all: program8

program8: program8.o map.o city.o vector.o data.o list.o
	gcc -g program8.o map.o city.o vector.o data.o list.o -o program8

program8.o: program8.c map.h list.h
	gcc -c program8.c -o program8.o

map.o: map.c map.h data.h vector.h list.h
	gcc -c map.c -o map.o

city.o: city.c city.h map.h vector.h list.h
	gcc -c city.c -o city.o

vector.o: vector.c vector.h data.h
	gcc -c vector.c -o vector.o

data.o: data.c data.h city.h
	gcc -c data.c -o data.o

list.o: list.c list.h data.h
	gcc -c list.c -o list.o

run: all
	./program8

checkmem: all
	valgrind -v ./program8

clean:
	rm -f *.o program8
