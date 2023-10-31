all: menus.o submenus.o validacao.o salvar.o
	gcc menus.o submenus.o validacao.o salvar.o main.c -o main && rm -rf *.o && clear && ./main

menus.o:	menus.h
	gcc -c menus.c

submenus.o:	submenus.h
	gcc -c submenus.c

validacao.o:	validacao.h
	gcc -c validacao.c

salvar.o:	salvar.h
	gcc -c salvar.c

clean:
	rm -rf *.o

run:
	./main

