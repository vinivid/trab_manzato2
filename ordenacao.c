#include "ordenacao.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

static void swap(int *a, int *b){
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

void selection_sort(int* vec, int size) {
    for (int i = 0; i < size - 1; ++i) {
        int current_low = i;

        for (int j = i + 1; j < size; ++j) {
            if (vec[j] < vec[current_low])
                current_low = j; 
        }

        swap(&vec[i], &vec[current_low]);
    }
}

void insert_sort(int *A, int size){
    int i;
    int comp;

    for(int j = 1; j < size; j++){
        comp = A[j];
        i = j - 1;

        while( i > -1 && A[i] > comp){
            A[i + 1] = A[i];
            --i;
        }

        A[i+1] = comp;
    }
}

void shell_sort(int* vec, int size){
    int k = size/2;

    while (k != 1) {
        for (int j = k; j < size; ++j) {
            int temp = vec[j];

            int i;
            for (i = j; (i >= k) && (vec[i - k] > temp); i -= k) {
                vec[i] = vec[i - k];                
            }

            vec[i] = temp;
        }

        k = k/2;
    }

    insert_sort(vec, size);
}

static void merge(int *A, int start, int middle, int end, int *B){
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

static void build_max_heap(int* A, int size) {
    for (int i = 0; i < size; ++i) {
        int child = i + 1;

        while (child > 0 && A[child/2] < A[child]) {
            swap(&A[child], &A[child/2]);
            child /= 2;
        }
    }
}

static void sieve(int* A, int size) {
    int parent = 0;
    int child = 1;
    int top_heap = A[0];

    while (child <= size) {
        if ( (child < size) && (A[child] < A[child + 1])) 
            ++child;

        if (top_heap >= A[child]) 
            break;

        A[parent] = A[child];
        parent = child;
        child = 2*parent;    
    }

    A[parent] = top_heap;
}

void heap_sort(int* A, int size) {
    build_max_heap(A, size - 1);

    for (int m = size - 1; m >= 1; --m) {
        swap(&A[0], &A[m]);
        sieve(A, m - 1);
    }
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

static int median(int a, int b, int c) {
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

static int partition (int* vec, int inf, int sup) {
	int meio = (inf + sup)/2;
    int i = inf;
	int j = sup;

    int pivo = median(vec[inf], vec[meio], vec[sup]);
	
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
		
		int part = partition(A, inf, sup);

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

void counting_sort(int* A, int size) {
    int max_elem = A[0];

    for (int i = 1; i < size; ++i)
        if (A[i] > max_elem)
            max_elem = A[i];

    int *fp = calloc ((max_elem + 1), sizeof(int));
    int *aux = malloc (size * sizeof(int));

    if (!fp || !aux) {
        printf("ERRO: ALOCACAO DE MEMORIA FALHOU\n");
        exit(EXIT_FAILURE);    
    }

    for (int i = 0; i < size; ++i)
        ++fp[A[i]];

    for (int i = 1; i <= max_elem; i++) 
        fp[i] += fp[i - 1];
    
    for (int i = size - 1; i >= 0; i--) {
        aux[fp[A[i]] - 1] = A[i];
        --fp[A[i]];
    }

    for (int i = 0; i < size; ++i) 
        A[i] = aux[i];

    free(fp);
    free(aux);
}   