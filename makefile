all:

	# Compilando a implementacao da fila
	gcc -c fila_contigua.c
	
	# Compilando e gerando o executavel
	gcc main.c fila_contigua.o -o main
	
	# Executando
	./main

