#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 100

int partition(int arr[],int low,int high){
    int p = arr[low];
    int k = low;
    int l = high+1;
    do{
        k++;
    }
    while(arr[k]<=p && k<high);

    do{
        l--;
    }while(arr[l]>p && l>low);

    while(k<l){
        int temp = arr[k];
        arr[k] = arr[l];
        arr[l] = temp;
        do{
            k++;
        }
        while(arr[k]<=p && k<high);

        do{
            l--;
        }while(arr[l]>p && l>low);
    }
    int temp = arr[low];
    arr[low] = arr[l];
    arr[l] = temp;

    return l;
}

void Quick_Sort(int arr[],int low,int high){
  if(low<high){
    int pi = partition(arr,low,high);
    Quick_Sort(arr,low,pi-1);
    Quick_Sort(arr,pi+1,high);
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
        Quick_Sort(arr , 0 , N-1);
        end = clock();

        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC*1000;
        
        printf("Best Case Time %lf ms\n",time_taken);
    }

    if(readArrayFromFile("D:\\Sem-5\\DAA\\Lab\\Arrays\\worst_case_100.txt", arr , N)){
        start = clock();
        Quick_Sort(arr , 0 , N-1);
        end = clock();

        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC*1000;
        
        printf("Worst Case Time %lf ms\n",time_taken);
    }

    if(readArrayFromFile("D:\\Sem-5\\DAA\\Lab\\Arrays\\average_case_100.txt", arr , N)){
        start = clock();
        Quick_Sort(arr , 0,N-1);
        end = clock();

        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC*1000;
        
        printf("Average Case Time %lf ms\n",time_taken);
    }
}
