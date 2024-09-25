#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

void cria(int v[], int tamVetor){
	for (int i = 0; i < tamVetor; i++){
		v[i] = i;
	}

	return;
}

void criaRandom(int v[], int tamVetor){
	for (int i = 0; i < tamVetor; i++){
		v[i] = rand() % 20;
	}

	return;
}


void imprime(int v[], int tamVetor){
	for (int i = 0; i < tamVetor; i++){
		printf("\n%d\n", v[i]);
	}

	return;
}

void trocar(int v[], int a, int b){
	int aux = v[a];
	v[a] = v[b];
	v[b] = aux;

	return;
}

int buscar(int v[], int x, int b, uint64_t* numComp){
	(*numComp)++;
	while (v[b] > x){
		(*numComp)++;
		b--;
	}

	return b;
}

void inserir(int v[], int a, int b, uint64_t* numComp){
	int p = buscar(v, v[b], b - 1, numComp);
	int i = b;

	while (i > p + 1){
		trocar(v, i , i - 1);
		i--;
	}

	return;
}

int minimo(int v[], int a, int b, uint64_t* numComp){
	int aux = v[b];
	int ind = b;

	for (int i = b - 1; i >= a; i--){
		(*numComp)++;
		if (v[i] < aux){
			aux = v[i];
			ind = i;
		}
	}

	return ind;
}

void copiar(int v[], int a, int b, int u[]){
	int i = 0;
	while (i <= b - a){
		v[a + i] = u[i];
		i++;
	}

	return;
}

void merge(int vet[], int m, int a, int b, uint64_t* numComp){
	if (a >= b)
		return;

	int k = 0;
	int i = a;
	int j = m + 1;
	int p;
	int u[b];

	while (k <= b - a){
		(*numComp)++;
		if (j > b || (i <= m && vet[i] <= vet[j])){
			p = i;
			i++;
		}
		else{
			p = j;
			j++;
		}
		u[k] = vet[p];
		k++;
	}

	return copiar (vet, a, b, u);
}