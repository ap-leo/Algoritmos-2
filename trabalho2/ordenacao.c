#include <string.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include "funcoes.c"
#define MAX_CHAR_NOME 40

void getNome(char nome[]) {
    // substitua por seu nome
    strncpy(nome, "Leonardo Moisés Pires de Alcides", MAX_CHAR_NOME);
    nome[MAX_CHAR_NOME - 1] =
        '\0';  // adicionada terminação manual para caso de overflow
}

// a função a seguir deve retornar o seu número de GRR
uint32_t getGRR() { return 20232376; }

ssize_t buscaSequencial(int vetor[], size_t tam, int valor,
                        uint64_t* numComparacoes) {
    int i = tam;
    while(vetor[i] > valor && i > 0){ //a verificação começa no ultimo indice e vai até o primeiro ou até encontrar o valor
        (*numComparacoes)++;
        i--;
    }

    return i; //retorna o indice encontrado
}

ssize_t buscaSequencialRec(int vetor[], size_t tam, int valor,
                           uint64_t* numComparacoes) {
    return buscaR(vetor, valor, 0, tam, numComparacoes);
}

ssize_t buscaBinaria(int vetor[], size_t tam, int valor,
                     uint64_t* numComparacoes) {
    ssize_t inicio = 0; //vetor[0...tam]

    while (inicio <= tam) { //enquanto inicio ainda estiver dentro do módulo do vetor
        int meio = (inicio + tam) / 2;

        (*numComparacoes)++;
        if (vetor[meio] > valor) {
            tam = meio - 1;
        }
        else {
            inicio = meio + 1;
        }
    }

    return inicio - 1;
}

ssize_t buscaBinariaRec(int vetor[], size_t tam, int valor,
                        uint64_t* numComparacoes) {
    return binariaR(vetor, valor, 0, tam, numComparacoes);
}

uint64_t insertionSort(int vetor[], size_t tam) {
    uint64_t numComparacoes = 0;
    for (int i = 0; i < tam; i++) { //a verificação começa no primeiro elemento
        numComparacoes++;
        while(vetor[i] > vetor[i + 1]){ //se seu elemento pŕoximo for menor, trocamos as posições
            trocar(vetor, i, i + 1);
            i++;
        }
    }

    return numComparacoes;
}

uint64_t insertionSortRec(int vetor[], size_t tam) {
    uint64_t numComparacoes = 0;
    isR(vetor, 0, tam, &numComparacoes);

    return numComparacoes;
}

uint64_t selectionSort(int vetor[], size_t tam) {
    uint64_t numComparacoes = 0;
    int inicio = 0;
    while(inicio < tam){
        trocar(vetor, inicio, minimo(vetor, inicio, tam, &numComparacoes)); //troca-se o primeiro elemento com o menor elemento do vetor
        inicio++; //passamos para o próximo indice: vetor[0...inicio] está ordenado
    }

    return numComparacoes;
}

uint64_t selectionSortRec(int vetor[], size_t tam) {
    uint64_t numComparacoes = 0;
    ssR(vetor, 0, tam, &numComparacoes);

    return numComparacoes;
}

uint64_t mergeSortRec(int vetor[], size_t tam) {
    uint64_t numComparacoes = 0;
    mS(vetor, 0, tam, &numComparacoes);

    return numComparacoes;
}