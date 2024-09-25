#define MAX_CHAR_NOME 40
#define N 100000
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include "extras.h"
#include "extras.h"
#include "ordenacao.h"

int main() {
    char nome[MAX_CHAR_NOME];
    uint64_t numComp = 0;
    uint64_t aux;

    ssize_t tamVetor = N;
    int* vetor = malloc(tamVetor * sizeof(int));
    if (vetor == NULL) {
        printf("Falha fatal. Impossível alocar memoria.");
        return 1;
    }

    getNome(nome);
    printf("Trabalho de %s\n", nome);
    printf("GRR %u\n", getGRR());

    clock_t start, end;
    double total;

    cria(vetor, tamVetor);

    printf("\n ☆ Teste para vetor de 100000 posições para Algortimos de Busca com Valor=-1 ☆\n\n");

    int valor = -1;

    start = clock();  // start recebe o "ciclo" corrente
    aux = buscaSequencialRec(vetor, tamVetor - 1, valor, &numComp);
    end = clock();  // end recebe o "ciclo" corrente
    // o tempo total é a diferença dividia pelos ciclos por segundo
    total = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Tempo total Busca Ingênua: %f \nComparações Busca Ingênua %lu\n\n", total, numComp);
    numComp = 0;

    start = clock(); 
    aux = buscaBinariaRec(vetor, tamVetor - 1, valor, &numComp);
    end = clock();  
    total = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Tempo total Busca Binária: %f \nComparações Busca Binária %lu\n\n", total, numComp);
    numComp = 0;

    start = clock();  
    aux = buscaBinariaRec(vetor, tamVetor - 1, valor, &numComp);
    end = clock();  
    total = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Tempo total Busca Binária: %f \nComparações Busca Binária %lu\n", total, numComp);
    numComp = 0;

    criaRandom(vetor, tamVetor);
    printf("\n ☆ Teste para vetor de 100000 posições para Algoritmos de Ordenação ☆ \n\n");

    start = clock(); 
    aux = insertionSortRec(vetor, tamVetor - 1);
    end = clock(); 
    total = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Tempo total InsertionSort: %f \nComparações InsertionSort %lu\n\n", total, aux);

    start = clock(); 
    aux = selectionSortRec(vetor, tamVetor - 1);
    end = clock(); 
    total = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Tempo total SelectionSort: %f \nComparações SelectionSort %lu\n\n", total, aux);

    start = clock(); 
    aux = mergeSortRec(vetor, tamVetor - 1);
    end = clock(); 
    total = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Tempo total MergeSort: %f \nComparações MergeSort %lu\n\n", total, aux);


    free(vetor);

    return 0;
}
