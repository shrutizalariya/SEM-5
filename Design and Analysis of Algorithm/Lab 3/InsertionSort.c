#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define CLOCK_PER_SEC
#define N 100000

void Insertion_Sort(int arr[], int n){
    for(int i=0 ; i<n; i++){
        int j = i - 1;
        int x = arr[i];
        while(j>=0 && x<arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = x;
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

    if(readArrayFromFile("D:\\Sem-5\\DAA\\Lab\\Arrays\\best_case_100000.txt", arr , N)){
        start = clock();
        Insertion_Sort(arr , N);
        end = clock();

        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC*1000;
        
        printf("Best Case Time %lf ms\n",time_taken);
    }

    if(readArrayFromFile("D:\\Sem-5\\DAA\\Lab\\Arrays\\worst_case_100000.txt", arr , N)){
        start = clock();
        Insertion_Sort(arr , N);
        end = clock();

        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC*1000;
        
        printf("Worst Case Time %lf ms\n",time_taken);
    }

    if(readArrayFromFile("D:\\Sem-5\\DAA\\Lab\\Arrays\\average_case_100000.txt", arr , N)){
        start = clock();
        Insertion_Sort(arr , N);
        end = clock();

        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC*1000;
        
        printf("Average Case Time %lf ms\n",time_taken);
    }
}
