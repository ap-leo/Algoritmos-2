#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include "extras.c"



ssize_t buscaR(int v[], int x, int a, int b, uint64_t* numComp){
	if (a > b){
		return a - 1;
	}

	(*numComp)++;
	if(x >= v[b]){
		return b;
	}

	return buscaR(v, x, a, b - 1, numComp);
}

ssize_t binariaR(int v[], int x, int a, int b, uint64_t* numComp){
	if (a > b)
		return a - 1;

	int m = (a + b / 2);

	(*numComp)++;
	if(x < v[b]){
		return binariaR(v, x, a, m - 1, numComp);
	}

	return binariaR(v, x, m + 1, b, numComp);
}

void isR(int v[], int a, int b, uint64_t* numComp){
	if (a >= b)
		return;

	isR(v, a, b - 1, numComp);
	inserir(v, a, b, numComp);

	return;
}

void ssR(int v[], int a, int b, uint64_t* numComp){
	if (a >= b)
		return;
	trocar(v, a, minimo(v, a, b, numComp));

	return ssR(v, a + 1, b, numComp);
}

void mS(int v[], int a, int b, uint64_t* numComp){
	if (a >= b)
		return;

	int m = (a + b) / 2;
	mS(v, a, m, numComp);
	mS(v, m + 1, b, numComp);

	return merge(v, m, a, b, numComp);
}