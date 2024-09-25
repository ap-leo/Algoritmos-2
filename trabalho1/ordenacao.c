#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordenacao.h"
#include "pilha.h"

/* troca dois valores entre indices de v[] de lugar */
void trocar(int v[], int ini, int fim){
    int aux = v[ini];
    v[ini] = v[fim];
    v[fim] = aux;

    return;
}

/* "ordena" o elemento x e retorna seu indice */
int particionar(int v[], int ini, int fim, uint64_t *comp){
    int x = v[fim];
    int m = ini;
    for (int i = ini; i < fim; i++){
        if (v[i] <= x){
             trocar(v, m, i);
             m++;
        }
    (*comp)++;
    }
    trocar(v, m, fim);

    return m;
}

/* copia o vetor v em um vetor u */
void copiar (int v[], int u[], int ini, int fim){
    int i = 0;
    while (i <= fim - ini){
        v[ini + i] = u[i];
        i++;
    }

    return;
}

/* da merge entre dois intervalos de v */
void merge (int v[], int ini, int m, int fim, uint64_t *comp){
    if (ini >= fim)
        return;
    int* u = (int*)malloc((fim + 1) * sizeof(int));
    if (u == NULL){
        printf("Erro alocacao merge"); 

        return;
    }

    int k = 0;
    int i = ini;
    int j = m + 1;
    int p;
    while (k <= fim - ini){
        (*comp)++;
        if (j > fim || (i <= m && v[i] <= v[j])){
            p = i;
            i++;
        }
        else{
            p = j;
            j++;
        }
        u[k] = v[p];
        k++;
    }

    copiar(v, u, ini, fim);
    free(u);

    return;
}


/* ordena v com quickSort recursivo */
void quickSortAux(int v[], int ini, int fim, uint64_t* comp){
    if (ini >= fim)
        return;

    int m = particionar(v, ini, fim, comp);
    quickSortAux(v, ini, m - 1, comp);
    quickSortAux(v, m + 1, fim, comp);

    return;
}

/* ordena v com mergeSort recursivo */
void mergeSortAux (int v[], int ini, int fim, uint64_t *comp){
    if (ini >= fim)
        return;
    
    int m = (ini + fim) / 2;
    mergeSortAux(v, ini, m, comp);
    mergeSortAux(v, m + 1, fim, comp);
    merge(v, ini, m, fim, comp);
    
    return;
}

int pai(int i){
    return i / 2;
}

int esquerda (int i){
    return i * 2;
}

int direita (int i){
    return i * 2 + 1;
}

/* cria uma max heap do vetor recebido de forma recursiva*/
void max_heapify(int vetor[], int i, int n, uint64_t *comp){
    int l = esquerda(i);
    int r = direita(i);

    int maior;
    *comp += 2;
    if(l <= n && vetor[l] > vetor[i]){
        maior = l;
    }

    else{
        maior = i;
    }

    if(r <= n && vetor[r] > vetor[maior]){
        maior = r;
    }

    if(maior != i){
        trocar(vetor, i, maior);
        max_heapify(vetor, maior, n, comp);
    }

    return;
}

/* cria uma max heap do vetor recebido de forma iterativa*/
void max_heapifySR(int vetor[], int i, int n, uint64_t *comp){
    struct pilha *h = pilha_cria();
    if(h == NULL){
        printf("Erro: Falha na alocação da pilha.\n");

        return;
    }

    push(h, i);
    int l, r, maior;

    while(!pilha_vazia(h)){
        pop(h, &i);
        l = esquerda(i);
        r = direita(i);
        maior = i;

        *comp += 2;
        if(l <= n && vetor[l] > vetor[maior]){
            maior = l;
        }

        if(r <= n && vetor[r] > vetor[maior]){
            maior = r;
        }

        if(maior != i){
            trocar(vetor, i, maior);
            push(h, maior); 
        }
    }

    free(h);

    return;
}

/* chama max_heapify para criar a max heap em todo o vetor */
/* se aux = 1 max_heapify recursivo */
/* se aux = 1 max_heapify iterativo */
void construir_max_heap(int vetor[], int fim, uint64_t *comp, int aux){
    if(aux){
        for (int i = (fim / 2); i >= 0; i--){
            max_heapify(vetor, i, fim, comp);
        }
    }
    else{
        for (int i = (fim / 2); i >= 0; i--){
            max_heapifySR(vetor, i, fim, comp);
        }
    }

    return;
}

/* ordena v com heapSort recursivo */
void heapSortAux(int vetor[], int inicio , int fim, uint64_t *comp){
    construir_max_heap(vetor, fim, comp, 1);

    for (int i = fim; i > 0; i--){
        trocar(vetor, 0, i);
        max_heapify(vetor, 0, i - 1, comp);
    }

    return;
}

void getNome(char nome[]) {
    strncpy(nome, "Leonardo Moisés Pires de Alcides", MAX_CHAR);
    // adicionada terminação manual para caso de overflow
    nome[MAX_CHAR - 1] = '\0';
}

// ini função ini seguir deve retornar o seu número de GRR
uint32_t getGRR() {
    return 20232376; 
}

/* retorna o numero de comparações */
uint64_t mergeSort(int v[], size_t tam) {
    uint64_t comp = 0;
    mergeSortAux(v, 0, tam - 1, &comp);

    return comp;
}

/* retorna o numero de comparações */
uint64_t quickSort(int v[], size_t tam) {
    uint64_t comp = 0;
    quickSortAux(v, 0, tam - 1, &comp);

    return comp;
}

/* retorna o numero de comparações */
uint64_t heapSort(int v[], size_t tam) {
    uint64_t comp = 0;
    heapSortAux(v, 0, tam - 1, &comp);

    return comp;
}

/* retorna o menor parametro recebido */
int min(int x, int y) {
    if (x < y) {
        return x;
    } 

    return y;
}

/* ordena v com mergeSort iterativo */
/* retorna o numero de comparações */
/* retorna -1 caso alocação falhe */
/* Algoritmo inspirado no livro Algorithms 4ed. SEDGEWICK R. & KEVIN W. */
uint64_t mergeSortSR(int v[], size_t tam) {
    int inicio;
    uint64_t comp = 0; 
    for (int i = 1; i <= tam - 1; i = 2 * i)
    {
        for (inicio = 0; inicio < tam - 1; inicio  += 2 * i)
        {
            int mid = min(inicio  + i - 1, tam-1);
            int right_end = min(inicio  + 2 * i - 1, tam - 1);
            merge(v, inicio , mid, right_end, &comp);
        }
    }

    return comp;
}

/* ordena v com quickSort iterativo */
/* retorna o numero de comparações */
/* retorna -1 caso alocação falhe */
/* inspirado nos slides do professor Paulo Lisboa UFPR */
uint64_t quickSortSR(int v[], size_t tam) {
    struct pilha *q = pilha_cria();
    if (q == NULL){
        printf("Erro alocacao quick\n"); 

        return -1;
    }

    int a = 0;
    int b = tam - 1;
    uint64_t comp = 0;
    push(q, a);
    push(q, b);
    while(!pilha_vazia(q)){
        if(pop(q, &b) && pop(q, &a)){
            if (a < b){
                int m = particionar(v,a,b, &comp);
                push(q, a);
                push(q, m - 1);
                push(q, m + 1);
                push(q, b);
            }
        }
    }

    free(q);

    return comp;
}

/* ordena v com quickSort iterativo */
/* retorna o numero de comparações */
/* retorna -1 caso alocação falhe */
uint64_t heapSortSR(int v[], size_t tam) {
    uint64_t comp = 0;
    construir_max_heap(v, tam - 1, &comp, 0);
    for (int i = tam - 1; i > 0; i--){
        trocar(v, 0, i);
        max_heapifySR(v, 0, i - 1, &comp);
    }

    return comp;
}

