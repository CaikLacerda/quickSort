#include <stdio.h>

void swap(int *a, int* b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int partition(int arr[], int inicio, int fim) {
    int pivot = arr[fim];
    int i = (inicio -1);
    for(int j = inicio; j <= fim - 1; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(&arr[j], &arr[i]);
        }
    }
    swap(&arr[i + 1], &arr[fim]);
    return (i + 1);
}

void quickSort(int arr[], int inicio, int fim) {
    if (inicio < fim) {
        long int p = partition(arr, inicio, fim);
        quickSort(arr, inicio, p - 1);
        quickSort(arr, p + 1, fim);
    }
}

void printArray(int arr[], int size) {
    int i;
    for(i=0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main () {
    int n = 100;
    int *arr = (int*)malloc(n * sizeof(int));
    srand();
    
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % n;
    }

    quickSort(arr, 0, n - 1);

    printf("O array ordenado ficou: \n");
    printArray(arr, n);
    return 0;
}