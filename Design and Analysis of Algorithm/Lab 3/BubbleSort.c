#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 100

void Bubble_Sort(int arr[], int n){
    for(int i=0 ; i<n; i++){
        int swap = 0;
        for(int j=0; j<n-i-1 ;j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swap = 1;
            }
        }
        if(swap==0){
            break;
        }
    }
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

    if(readArrayFromFile("D:\\Sem-5\\DAA\\Lab\\Arrays\\best_case_100.txt", arr , N)){
        start = clock();
        Bubble_Sort(arr , N);
        end = clock();

        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC*1000;
        
        printf("Best Case Time %lf ms\n",time_taken);
    }

    if(readArrayFromFile("D:\\Sem-5\\DAA\\Lab\\Arrays\\worst_case_100.txt", arr , N)){
        start = clock();
        Bubble_Sort(arr , N);
        end = clock();

        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC*1000;
        
        printf("Worst Case Time %lf ms\n",time_taken);
    }

    if(readArrayFromFile("D:\\Sem-5\\DAA\\Lab\\Arrays\\average_case_100.txt", arr , N)){
        start = clock();
        Bubble_Sort(arr , N);
        end = clock();

        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC*1000;
        
        printf("Average Case Time %lf ms\n",time_taken);
    }
}
