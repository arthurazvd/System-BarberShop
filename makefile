all: menus.o
	gcc menus.o main.c -o main

menus.o:	menus.h
	gcc -c menus.c

clean:
	rm -rf *.o

run:
	./main
