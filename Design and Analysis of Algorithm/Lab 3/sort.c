#include <stdio.h>
#include <time.h>

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; 
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void display(int arr[], int n) {
    printf("Final array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

void main() {
    int arr[10] = {11, 6, 3, 7, 10, 2, 1, 0, 13, 15};
    int n = 10;
    clock_t start;
    clock_t end;
    double time_taken;
   
    start = clock();
    mergeSort(arr, 0, n - 1);
    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC*1000;
        
    printf("Best Case Time %lf ms\n",time_taken);
    display(arr, n);
}





