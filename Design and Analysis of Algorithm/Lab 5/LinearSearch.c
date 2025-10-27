#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 100

int LinearSearch(int arr[],int n,int target){
     for(int i=0;i<n;i++){
        if(arr[i]==target){
            return i;
        }
    }
    return 0;
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
        LinearSearch(arr , N, 1);
        end = clock();

        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC*1000;
        
        printf("Best Case Time %lf ms\n",time_taken);
    }

    if(readArrayFromFile("D:\\Sem-5\\DAA\\Lab\\Arrays\\best_case_100.txt", arr , N)){
        start = clock();
        LinearSearch(arr , N, 50);
        end = clock();

        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC*1000;
        
        printf("Worst Case Time %lf ms\n",time_taken);
    }
 
    if(readArrayFromFile("D:\\Sem-5\\DAA\\Lab\\Arrays\\best_case_100.txt", arr , N)){
        start = clock();
        LinearSearch(arr , N, 100);
        end = clock();

        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC*1000;
        
        printf("Average Case Time %lf ms\n",time_taken);
    }
}