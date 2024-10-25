#ifndef SRT_H
#define SRT_H

extern int swap_qtt;
extern int comparison_qtt;

typedef enum metodo_de_sort_ {
    Bubble = 620,
    Select = 640,
    Insert = 661,
    Shell = 536,
    Quick = 541,
    Heap = 414,
    Merge = 528,
    Count = 553,
    Radix = 416,
}metodo_de_sort;

metodo_de_sort numero_sort(char* sort);

void bubble_sort(int *A, int size);
void selection_sort(int* vec, int size);
void insert_sort(int *A, int size);
void shell_sort(int* vec, int size);
void merge_sort(int *A, int size);
void quick_sort (int* A, int size);
void heap_sort(int* A, int size);
void counting_sort(int* A, int size);
void radix_sort(int* A, int size);

#endif