all: menus.o menus_horario.o menus_clientes.o menus_precos.o menus_maquinas.o validacao.o digitar.o
	gcc menus.o menus_horario.o menus_clientes.o menus_precos.o menus_maquinas.o validacao.o digitar.o main.c -o main && rm -rf *.o && clear && ./main

menus.o:	MENUS/menus.h
	gcc -c MENUS/menus.c

menus_horario.o:	MENUS/menus_horario.h
	gcc -c MENUS/menus_horario.c

menus_clientes.o:	MENUS/menus_clientes.h
	gcc -c MENUS/menus_clientes.c

menus_precos.o:	MENUS/menus_precos.h
	gcc -c MENUS/menus_precos.c

menus_maquinas.o:	MENUS/menus_maquinas.h
	gcc -c MENUS/menus_maquinas.c

validacao.o:	UTILITARIOS/validacao.h
	gcc -c UTILITARIOS/validacao.c

digitar.o:	UTILITARIOS/digitar.h
	gcc -c UTILITARIOS/digitar.c

clean:
	rm -rf *.o

run:
	./main

bug: menus.o menus_horario.o menus_clientes.o menus_precos.o menus_maquinas.o validacao.o digitar.o
	gcc menus.o menus_horario.o menus_clientes.o menus_precos.o menus_maquinas.o validacao.o digitar.o main.c -o main && rm -rf *.o

