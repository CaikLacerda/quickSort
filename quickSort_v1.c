#include <stdio.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int left, int right) {
    int pivot = arr[right];
    int i = (left - 1);
    for(int j = left; j <= right -1; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[right]);
    return (i + 1);
}

void quickSort(int arr[], long int left, long int right){
    if (left < right){
        long int pi = partition(arr, left, right);
        quickSort(arr, left, pi - 1);
        quickSort(arr, pi + 1, right);
    }
}

void printArray(int arr[], int size){
   int i;
   for (i=0; i < size; i++)
      printf("%d ", arr[i]);
   printf("\n");
}

int main(){
   int arr[] = {10,8,11,15,7,12,33,3};
   int n = sizeof(arr)/sizeof(arr[0]);

   quickSort(arr, 0, n-1);

   printf("The sorted array is: \n");
   printArray(arr, n);
   return 0;
}