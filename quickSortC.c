#include <stdio.h>

void swap(int *a, int*b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int partition(int arr[], int inicio, int fim) {
    int pivot = arr[fim];
    int i = (inicio - 1);

    for(int j = inicio; j <= fim -1; j++) {
        if(arr[j] <= pivot){
            i++;
            swap(&arr[j], &arr[i]); 
        }
    }
    // Fazendo a troca do pivo para o fim da barra amarela
    swap(&arr[i + 1], &arr[fim]);
    return (i +1);
}

void quickSort(int arr[], long int inicio, long int fim) {
    if(inicio < fim) {
        long int p = partition(arr, inicio, fim);
        // Ordenando a barra amarela (i)
        quickSort(arr, inicio, p - 1);
        // Ordenando a barra roxa (j)
        quickSort(arr, p + 1, fim);
    }
}

void printArray(int arr[], int size) {
    int i;
    for(i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {10,2,4,6,3,5,8,7,6,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr, 0, n -1);

    printf("O array ordenado ficou: \n");
    printArray(arr, n);
    
    return 0;
}