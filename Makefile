all: main utilidades sequencial arvoreBin arvoreB arvoreBE compile clean

compile:
	@gcc main.o utilidades.o acessoSequencial.c abp.o arvoreB.o arvorebestrela.o -o pesquisa -Wall

main: main.c
	@gcc -c main.c -Wall

utilidades: utilidades.c
	@gcc -c utilidades.c -Wall

sequencial: acessoSequencial.c
	@gcc -c acessoSequencial.c -Wall

arvoreBin: abp.c
	@gcc abp.c -c -Wall

arvoreB: arvoreB.c
	@gcc -c arvoreB.c -Wall

arvoreBE: arvorebestrela.c
	@gcc -c arvorebestrela.c -Wall

clean: 
	@rm -f main.o utilidades.o acessoSequencial.o abp.o abp.bin arvoreB.o arvorebestrela.o