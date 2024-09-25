#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>


/* cria um vetor ordenado */
void cria(int v[], int tamVetor);

/* cria um vetor não ordenado */
void criaRandom(int v[], int tamVetor);

/* imprime um vetor */
void imprime(int v[], int tamVetor);

/* troca v[a] e v[b] de posição*/
void trocar(int v[], int a, int b);

/* encontra a posição que x deveria estar */
int buscar(int v[], int x, int b, uint64_t* numComp);

/* troca a posição dos elementos do vetor para que inserir um valor p */
void inserir(int v[], int a, int b, uint64_t* numComp);

/* encontra o o menor valor do vetor */
int minimo(int v[], int a, int b, uint64_t* numComp);

/* copia v[] para u[] */
void copiar(int v[], int a, int b, int u[]);

/* ordena dois subvetores ordenados */
void merge(int vet[], int m, int a, int b, uint64_t* numComp);