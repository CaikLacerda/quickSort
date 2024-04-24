#include <stdio.h>

void quickSort (int *vetor, int esquerda, int direita) {
    long int i, j, pivo, aux, meio;

    pivo = vetor[direita];
    i = esquerda;
    j = direita;

    while (i <= j) {
        while (vetor[i] < pivo && i < direita)
            i += 1;

        while (vetor[j] > pivo && j > esquerda)
            j -= 1;

        if (i <= j) {
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i += 1;
            j -= 1;
        } 
    }

    if (j > esquerda)
        quickSort(vetor, esquerda, j);

    if (j < direita)
        quickSort(vetor, i , direita);

}

void printArray(int arr[], int size){
   int i;
   for (i=0; i < size; i++)
      printf("%d ", arr[i]);
   printf("\n");
}

void main() {
    int n = 10;
    int *arr = (int*)malloc(n * sizeof(int));
    srand(0);
    long int i;

    // Alocar valores aleatorios no array
    for(i=0; i<n; i++) {
        arr[i] =  rand() % n;
    }

    // Chamada da funcao quickSort
    quickSort(arr, 0, n-1);

    printf("O array ordenado ficou: \n");
    printArray(arr, n);

}