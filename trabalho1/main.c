#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "ordenacao.h"
#include "pilha.h"

/* adiciona valores aleatorios até 50 em vetor */
void criarVetor(int vetor[], int tam){
    for(int i = 0; i < tam; i++){
        vetor[i] = rand() % 50;
    }

    return;
}

/* Programa criado para testar tempo e comparações em alg de ordenação */
/* testes em 4000, 40000 e 400000 posições*/
int main() {
    srand(0);
    char nome[MAX_CHAR];
    int numComp;
    clock_t start, end;
    double total;

    int tamVetor = 4000;
    printf("\n");
    getNome(nome);
    printf("Trabalho de %s\n", nome);
    printf("GRR %u\n", getGRR()); 
    printf("\n");

    for (int i = 1; i <= 3; i++){
        int* vetor = (int*)malloc(tamVetor * sizeof(int));
        if (vetor == NULL) {
            printf("Falha fatal. Impossível alocar memoria.");

            return 1;
        }

        printf("/-------------Teste em vetor de %d posições-------------/\n", tamVetor);

        criarVetor(vetor, tamVetor);
        start = clock();
        numComp = mergeSort(vetor, tamVetor);  
        end = clock(); 
        total = ((double)end - start) / CLOCKS_PER_SEC;
        printf("\n\nmergeSort NumComp: %d    tempo: %f", numComp, total);

        criarVetor(vetor, tamVetor);
        start = clock();
        numComp = quickSort(vetor, tamVetor);
        end = clock(); 
        total = ((double)end - start) / CLOCKS_PER_SEC;
        printf("\n\nquickSort NumComp: %d    tempo: %f", numComp, total);

        criarVetor(vetor, tamVetor);
        start = clock();
        numComp = heapSort(vetor, tamVetor);
        end = clock(); 
        total = ((double)end - start) / CLOCKS_PER_SEC;
        printf("\n\nheapSort NumComp: %d    tempo: %f", numComp, total);

        criarVetor(vetor, tamVetor);
        start = clock();
        numComp = mergeSortSR(vetor, tamVetor);
        end = clock(); 
        total = ((double)end - start) / CLOCKS_PER_SEC;
        printf("\n\nmergeSortSR NumComp: %d    tempo: %f", numComp, total);

        criarVetor(vetor, tamVetor);
        start = clock();
        numComp = quickSortSR(vetor, tamVetor);
        end = clock(); 
        total = ((double)end - start) / CLOCKS_PER_SEC;
        printf("\n\nquickSortSR NumComp: %d    tempo: %f", numComp, total);

        criarVetor(vetor, tamVetor);
        start = clock();
        numComp = heapSortSR(vetor, tamVetor);
        end = clock(); 
        total = ((double)end - start) / CLOCKS_PER_SEC;
        printf("\n\nheapSortSR NumComp: %d    tempo: %f\n\n\n", numComp, total);

        free(vetor);

        tamVetor = tamVetor * 10;

    }

    printf("\n");

    return 0;
}
