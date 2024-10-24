#include "ordenacao.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubble_sort(int *A, int size){
    bool swaped = false;

    do{
        swaped = false;

        for(int i = 0; i < size - 1; ++i){
            if(A[i] > A[i+1]){
                swap(&A[i], &A[i+1]);
                swaped = true;
            }
        }

        size -= 1;
    }while(swaped == true);
}

void insert_sort(int *A, int size){
    int i;
    int comp;

    for(int j = 1; j < size; j++){
        comp = A[j];
        i = j - 1;

        while(A[i] > comp  && i > -1){
            A[i + 1] = A[i];
            --i;
        }

        A[i+1] = comp;
    }
}

void merge(int *A, int start, int middle, int end, int *B){
    int i = start;
    int j = middle;                  

    for(int k = start; k < end; ++k){
        if(i < middle && (j >= end || A[i] <= A[j])){
            B[k] = A[i];
            ++i;
        }else{
            B[k] = A[j];
            ++j;
        }
    }

    for(int k = start; k < end; ++k) A[k] = B[k];
}

void merge_sort(int *A, int size){
    int *B = (int *)malloc(size * sizeof(int));
    if(B == NULL){
        printf("ERRO: ALOCACAO DE MEMORIA FALHOU\n");
        exit(EXIT_FAILURE);        
    }

    for(int i = 0; i < size; ++i) B[i] = A[i];

    for(int i = 2; i < size*2; i *=2){
        int middle = 0;
        int end = 0;

        for(int j = 0; j < size; j += i){
            end = j+i;
            middle = (j + end)/2;
            if(end > size) end -= end-size;      

            merge(A, j, middle, end, B);
        }
    }

    free(B); B = NULL; 
}

int mediana_de_tres(int a, int b, int c) {
    int x = a - b;
    int y = b - c;
    int z = a - c;
 
    if (x * y > 0)
        return b;

    else if (x * z > 0)
        return c;
    else
        return a;
}

int particao (int* vec, int inf, int sup) {
	int meio = (inf + sup)/2;
    int i = inf;
	int j = sup;

    int pivo = mediana_de_tres(vec[inf], vec[meio], vec[sup]);
	
	while (i <= j) {
		while (vec[i] < pivo) ++i;
		while (vec[j] > pivo) --j;

		if (i <= j) {
			swap (&vec[i], &vec[j]);
			++i;
			--j;
		}
	}

	return i;
}

void quick_sort (int* A, int size) {
    int inf = 0;
    int sup = size - 1;
	int* stack = malloc( (size) * sizeof(int));

	int top = -1;

	stack[++top] = inf;
	stack[++top] = sup;

	while (top >= 0) {
		sup = stack[top--];
		inf = stack[top--];
		
		int part = particao(A, inf, sup);

		if (part - 1 > inf) {
			stack[++top] = inf;
			stack[++top] = part - 1;
		}

		if (part < sup) {
			stack[++top] = part;
			stack[++top] = sup;
		}
	}

	free(stack);
}