#include <stdio.h>
#include "../registro.h"

int main(){

    FILE *arquivoBin = fopen("crescente.bin", "rb");
    if(arquivoBin == NULL){
        return 1;
    }

    Registro registro;
    FILE *arquivoTxt = fopen("crescente.txt", "w");
    for(int i = 0; i < 2000000; i++){
        if(i % 10000 == 0){
            printf("gerando registro %d\n", i);
        }
        fread(&registro, sizeof(Registro), 1, arquivoBin);
        fprintf(arquivoTxt, "registro %d: ", i);
        fprintf(arquivoTxt, " ");
        fprintf(arquivoTxt, "chave %d: ", registro.chave);
        fprintf(arquivoTxt, " ");
        fprintf(arquivoTxt, "dado1 %ld: ", registro.dado1);
        fprintf(arquivoTxt, " ");
        fprintf(arquivoTxt, "dado2 %.5s: ", registro.dado2);
        fprintf(arquivoTxt, "\n");

    }
    fclose(arquivoTxt);
    fclose(arquivoBin);

    return 0;
}   


