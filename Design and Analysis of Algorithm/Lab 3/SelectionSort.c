#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define CLOCK_PER_SEC
#define N 100000

void Selection_Sort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        int minj = i;
        int minx = arr[i];
        for(int j=i+1;j<n;j++){
            if(arr[j]<minx){
                minx = arr[j];
                minj = j;
            }
        }
        arr[minj] = arr[i];
        arr[i] = minx;
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
        Selection_Sort(arr , N);
        end = clock();

        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC*1000;
        
        printf("Best Case Time %lf ms\n",time_taken);
    }

    if(readArrayFromFile("D:\\Sem-5\\DAA\\Lab\\Arrays\\worst_case_100000.txt", arr , N)){
        start = clock();
        Selection_Sort(arr , N);
        end = clock();

        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC*1000;
        
        printf("Worst Case Time %lf ms\n",time_taken);
    }

    if(readArrayFromFile("D:\\Sem-5\\DAA\\Lab\\Arrays\\average_case_100000.txt", arr , N)){
        start = clock();
        Selection_Sort(arr , N);
        end = clock();

        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC*1000;
        
        printf("Average Case Time %lf ms\n",time_taken);
    }
}
