#include "registro.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 2000000

long int gerarAleatorio() {
    long int parteAlta = ((long int) rand() << 32) | rand();
    long int parteBaixa = ((long int) rand() << 32) | rand();
    //faz gerar numeros negativos
    return (parteAlta << 1) ^ (parteBaixa >> 31);
}

void gerarDadoAleatorio(char *dado, int tamanho){
    for(int i = 0; i < (tamanho - 1); i++){
        int codigoASCII = (rand() % 95) + 32;
        dado[i] = codigoASCII;
    }
    dado[tamanho - 1] = '\0';
}

void crescente(){
    srand(42);

    Registro reg;
    memset(&reg, 0, sizeof(Registro));

    FILE *pArquivo = NULL;
    pArquivo = fopen("crescente.bin", "wb");
    for(int i = 0; i <= MAX; i++){
        if(i % 10000 == 0){
            printf("gerando registro %d\n", i);
        }
        reg.chave = i;
        reg.dado1 = gerarAleatorio();
        gerarDadoAleatorio(reg.dado2, 5001);
        fwrite(&reg, sizeof(Registro), 1, pArquivo);
    }

    fclose(pArquivo);
}

void decrescente(){
    Registro reg;
    memset(&reg, 0, sizeof(Registro));

    FILE *pCrescente = NULL;
    pCrescente = fopen("crescente.bin", "rb");

    FILE *pDecrescente = NULL;
    pDecrescente = fopen("decrescente.bin", "wb");

    for(int i = MAX; i >= 1; i--){
        fseek(pCrescente, (i - 1) * sizeof(Registro), SEEK_SET);
        fread(&reg, sizeof(Registro), 1, pCrescente);
        fread(&reg, sizeof(Registro), 1, pDecrescente);
    }
    fclose(pCrescente);
    fclose(pDecrescente);
}

void aleatorio(){
    srand(42);

    Registro reg;
    memset(&reg, 0, sizeof(Registro));

    FILE *pCrescente = NULL;
    pCrescente = fopen("crescente.bin", "rb");

    FILE *pAleatorio = NULL;
    pAleatorio = fopen("aleatorio.bin", "wb");

    int *vetor = (int*)malloc(MAX * sizeof(int));
    for(int i = 0; i < MAX; i++){
        vetor[i] = i;
    }


    //embaralha o vetor
    for (int i = 0; i < MAX; i++){
        int posicao = rand() % MAX;
        int aux = vetor[i];
        vetor[i] = vetor[posicao];
        vetor[posicao] = aux;
    }

    // Escreve o Registro em ordem aleatoria
    for(int i = 0; i < MAX; i++){
        fseek(pCrescente, vetor[i] * sizeof(Registro), SEEK_SET);
        fread(&reg, sizeof(Registro), 1, pCrescente);
        fread(&reg, sizeof(Registro), 1, pAleatorio);
    }

    fclose(pCrescente);
    fclose(pAleatorio);
    free(vetor);
}

int main(){

    //quando for criar os arquivos comenta os outros
    crescente();
    //decrescente();
    //aleatorio();

    return 0;
}
