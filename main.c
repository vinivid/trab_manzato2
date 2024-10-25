#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "ordenacao.h"

int main(int argc, char** argv) {
    if (argc <= 1) {
        printf("É necessário que se passe no primeiro um método de ordenação a ser utilizado\n");
        printf("Os argumentos possíveis são:\nbubble : BubbleSort\nselect : SelectionSort\ninsert : InsertSort\nquick : QuickSort\nheap : HeapSort\nmerge : MegeSort\ncount : Contagem dos menores\nradix : RadixSort\n");
        printf("Como segundo argumento é selecionado o tipo de saida que se tera:\n");
        printf("0 ou nada para que saia a quantidade de comparações usada pelo método, as trocas nos registros e o tempo tomado pelo algoritimo\n");
        printf("1 para que saia o vetor ordenanado pelo método\n");
        return 1;
    }

    metodo_de_sort sort = numero_sort(argv[1]);

    int type_exit = 0;
    if (argv[2]) type_exit = atoi(argv[2]);

    int tamanho;
    scanf("%d", &tamanho);
    int* vetor = malloc(tamanho * sizeof(int));

    for (int i = 0; i < tamanho; ++i) 
        scanf("%d", &vetor[i]);

    switch (sort) {
        case Bubble:
            bubble_sort(vetor, tamanho);
            break;
        case Select:
            selection_sort(vetor, tamanho);
            break;
        case Insert:
            insert_sort(vetor, tamanho);
            break;
        case Shell:
            shell_sort(vetor, tamanho);
            break;
        case Quick:
            quick_sort(vetor, tamanho);
            break;
        case Heap:
            heap_sort(vetor, tamanho);
            break;
        case Merge:
            merge_sort(vetor, tamanho);
            break;
        case Count:
            counting_sort(vetor, tamanho);
            break;
        case Radix:
            radix_sort(vetor, tamanho);
            break;
        default:
            printf("\n\nMétodo de ordenação não encontrado\n\n");
            return 2;
    } 

    if (type_exit) {
        for (int i = 0; i < tamanho; i++)
            printf("%d\n", vetor[i]);
    }

    free(vetor);
}