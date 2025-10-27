#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 100000

int heapify(int arr[], int n,int i){
    int largest = i;
    int right = 2*i+2;
    int left = 2*i+1;
    if(left < n && arr[left] > arr[largest]){
        largest=left;
    }
    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }
    if(largest!=i){
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr,n,largest);
    }
    return 1;
}

int heapSort(int arr[],int n){
    for(int i=(n/2)-1;i>=0;i--){
        heapify(arr,n,i);
    }
    for(int i=n-1;i>0;i--){
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr,i,0);
    }
    return 1;
}

int readArrayFromFile(const char *filename , int arr[] , int n){
    FILE *f = fopen(filename,"r");

    if(!f){
        printf("Cannot Open File %s",filename);
        return 0;
    }
    for(int i=0 ; i<n ;i++){
        fscanf(f, "%d", &arr[i]);
    }
    fclose(f);
    return 1;
}

void main(){
    int arr[N];
    clock_t start;
    clock_t end;
    double time_taken;

    if(readArrayFromFile("D:\\Sem-5\\DAA\\Lab\\Arrays\\best_case_100000.txt", arr , N)){
        start = clock();
        heapSort(arr , N);
        end = clock();

        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC*1000;
        
        printf("Best Case Time %lf ms\n",time_taken);
    }

    if(readArrayFromFile("D:\\Sem-5\\DAA\\Lab\\Arrays\\worst_case_100000.txt", arr , N)){
        start = clock();
        heapSort(arr , N);
        end = clock();

        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC*1000;
        
        printf("Worst Case Time %lf ms\n",time_taken);
    }

    if(readArrayFromFile("D:\\Sem-5\\DAA\\Lab\\Arrays\\average_case_100000.txt", arr , N)){
        start = clock();
        heapSort(arr , N);
        end = clock();

        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC*1000;
        
        printf("Average Case Time %lf ms\n",time_taken);
    }
}
