#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "ordenacao.h"

int main(int argc, char** argv) {
    if (argc <= 1) {
        printf("É necessário que se passe no primeiro um método de ordenação a ser utilizado\n");
        printf("Os argumentos possíveis estão a seguir em que na esquerda é o argumento e na direita é o método de ordenação que o programa utilizara para aquele argumento.\nbubble : BubbleSort\nselect : SelectionSort\ninsert : InsertSort\nquick : QuickSort\nheap : HeapSort\nmerge : MegeSort\ncount : Contagem dos menores\nradix : RadixSort\n");
        printf("Como segundo argumento é selecionado o tipo de saida que se tera:\n");
        printf("0 ou nada para que saia a quantidade de comparações usada pelo método, as trocas nos registros e o tempo tomado pelo algoritimo\n");
        printf("1 para que saia o vetor ordenanado pelo método\n");
        return 1;
    }

    metodo_de_sort sort = numero_sort(argv[1]);

    int type_exit = 0;
    if (argv[2]) type_exit = atoi(argv[2]);

    clock_t a, b;

    int tamanho;
    scanf("%d", &tamanho);
    int* vetor = malloc(tamanho * sizeof(int));

    for (int i = 0; i < tamanho; ++i) 
        scanf("%d", &vetor[i]);

    switch (sort) {
        case Bubble:
            a = clock();
            bubble_sort(vetor, tamanho);
            b = clock();
            if (!type_exit) {
                printf("%llu %llu %d %lf\n", comparison_qtt, swap_qtt, tamanho, (double)(b - a)/CLOCKS_PER_SEC);
            }
            break;
        case Select:
            a = clock();
            selection_sort(vetor, tamanho);
            b = clock();
            if (!type_exit) {
                printf("%llu %llu %d %lf\n", comparison_qtt, swap_qtt, tamanho, (double)(b - a)/CLOCKS_PER_SEC);
            }
            break;
        case Insert:
            a = clock();
            insert_sort(vetor, tamanho);
            b = clock();
            if (!type_exit) {
                printf("%llu %llu %d %lf\n", comparison_qtt, swap_qtt, tamanho, (double)(b - a)/CLOCKS_PER_SEC);
            }
            break;
        case Shell:
            a = clock();
            shell_sort(vetor, tamanho);
            b = clock();
            if (!type_exit) {
                printf("%llu %llu %d %lf\n", comparison_qtt, swap_qtt, tamanho, (double)(b - a)/CLOCKS_PER_SEC);
            }
            break;
        case Quick:
            a = clock();
            quick_sort(vetor, tamanho);
            b = clock();
            if (!type_exit) {
                printf("%llu %llu %d %lf\n", comparison_qtt, swap_qtt, tamanho, (double)(b - a)/CLOCKS_PER_SEC);
            }
            break;
        case Heap:
            a = clock();
            heap_sort(vetor, tamanho);
            b = clock();
            if (!type_exit) {
                printf("%llu %llu %d %lf\n", comparison_qtt, swap_qtt, tamanho, (double)(b - a)/CLOCKS_PER_SEC);
            }
            break;
        case Merge:
            a = clock();
            merge_sort(vetor, tamanho);
            b = clock();
            if (!type_exit) {
                printf("%llu %llu %d %lf\n", comparison_qtt, swap_qtt, tamanho, (double)(b - a)/CLOCKS_PER_SEC);
            }
            break;
        case Count:
            a = clock();
            counting_sort(vetor, tamanho);
            b = clock();
            if (!type_exit) {
                printf("%llu %llu %d %lf\n", comparison_qtt, swap_qtt, tamanho, (double)(b - a)/CLOCKS_PER_SEC);
            }
            break;
        case Radix:
            a = clock();
            radix_sort(vetor, tamanho);
            b = clock();
            if (!type_exit) {
                printf("%llu %llu %d %lf\n", comparison_qtt, swap_qtt, tamanho, (double)(b - a)/CLOCKS_PER_SEC);
            }
            break;
        default:
            printf("\n\nMétodo de ordenação não encontrado\n\n");
            free(vetor);
            return 2;
    } 

    if (type_exit) {
        for (int i = 0; i < tamanho; i++)
            printf("%d\n", vetor[i]);
    }

    free(vetor);
}