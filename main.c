#include <stdlib.h>
#include <stdio.h>

#include "ordenacao.h"

typedef enum metodo_de_sort_ {
    bubble = 620,
    selectt = 640,
    insert = 661,
    shell = 536,
    quick = 541,
    heap = 414,
    merge = 528,
    count = 553,
    radix = 416,
}metodo_de_sort;

metodo_de_sort numero_sort(char* sort);

int main(int argc, char** argv) {
    if (argc <= 1) {
        printf("\n\nÉ necessário que se passe um método de ordenação a ser utilizado\n\n");
        return 1;
    }

    metodo_de_sort sort = numero_sort(argv[1]);

    int tamanho;
    scanf("%d", &tamanho);
    int* vetor = malloc(tamanho * sizeof(int));

    for (int i = 0; i < tamanho; ++i) 
        scanf("%d", &vetor[i]);

    switch (sort) {
        case bubble:
            bubble_sort(vetor, tamanho);
            break;
        case selectt:
            selection_sort(vetor, tamanho);
            break;
        case insert:
            insert_sort(vetor, tamanho);
            break;
        case shell:
            shell_sort(vetor, tamanho);
            break;
        case quick:
            quick_sort(vetor, tamanho);
            break;
        case heap:
            break;
        case merge:
            merge_sort(vetor, tamanho);
            break;
        case count:
            break;
        case radix:
            break;
        default:
            printf("\n\nMétodo de ordenação não encontrado\n\n");
            return 2;
    } 

    for (int i = 0; i < tamanho; i++) {
        printf("%d\n", vetor[i]);
    }

    free(vetor);
}

metodo_de_sort numero_sort(char* sort) {
    int acc = 0;

    for(int i = 0; sort[i]; ++i) {
        if (sort[i] == 'x')
            continue;
        acc += sort[i];
    }

    return (metodo_de_sort)acc;
}