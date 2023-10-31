all: menus.o menus_horario.o menus_clientes.o menus_precos.o menus_maquinas.o validacao.o
	gcc menus.o menus_horario.o menus_clientes.o menus_precos.o menus_maquinas.o validacao.o main.c -o main && rm -rf *.o && clear && ./main

menus.o:	menus.h
	gcc -c menus.c

menus_horario.o:	menus_horario.h
	gcc -c menus_horario.c

menus_clientes.o:	menus_clientes.h
	gcc -c menus_clientes.c

menus_precos.o:	menus_precos.h
	gcc -c menus_precos.c

menus_maquinas.o:	menus_maquinas.h
	gcc -c menus_maquinas.c

validacao.o:	validacao.h
	gcc -c validacao.c


clean:
	rm -rf *.o

run:
	./main

bug: menus.o menus_horario.o menus_clientes.o menus_precos.o menus_maquinas.o validacao.o
	gcc menus.o menus_horario.o menus_clientes.o menus_precos.o menus_maquinas.o validacao.o main.c -o main

