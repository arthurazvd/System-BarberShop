all: menus.o submenus.o validacao.o
	gcc menus.o submenus.o validacao.o main.c -o main

menus.o:	menus.h
	gcc -c menus.c

submenus.o:	submenus.h
	gcc -c submenus.c

validacao.o:	validacao.h
	gcc -c validacao.c

clean:
	rm -rf *.o

run:
	./main
