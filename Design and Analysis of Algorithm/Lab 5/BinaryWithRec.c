#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 100000

int Binary_Search(int arr[],int l,int r,int target){
        while(l<=r){
            int mid = (l+r)/2;
            if(arr[mid]==target){
                return mid;
            }
            else if(arr[mid]>target){
                return Binary_Search(arr,l,(mid-1),target);
            }
            else if(arr[mid]<target){
                return Binary_Search(arr,(mid+1),r,target);
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

    if(readArrayFromFile("D:\\Sem-5\\DAA\\Lab\\Arrays\\best_case_100000.txt", arr , N)){
        start = clock();
        Binary_Search(arr , 0, N-1, 1);
        end = clock();

        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC*1000;
        
        printf("Best Case Time %lf ms\n",time_taken);
    }

    if(readArrayFromFile("D:\\Sem-5\\DAA\\Lab\\Arrays\\best_case_100000.txt", arr , N)){
        start = clock();
        Binary_Search(arr , 0, N-1, 100);
        end = clock();

        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC*1000;
        
        printf("Worst Case Time %lf ms\n",time_taken);
    }
 
    if(readArrayFromFile("D:\\Sem-5\\DAA\\Lab\\Arrays\\best_case_100000.txt", arr , N)){
        start = clock();
        Binary_Search(arr , 0, N-1, 50);
        end = clock();

        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC*1000;
        
        printf("Average Case Time %lf ms\n",time_taken);
    }
}