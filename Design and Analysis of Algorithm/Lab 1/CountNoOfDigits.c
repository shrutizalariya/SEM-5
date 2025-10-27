//Count number of digits

//Iterative Approach
// #include<stdio.h>

// int main(){
//     int n,count=0;
//     printf("Enter a number: ");
//     scanf("%d",&n);
//     int temp = n;
//     while(n!=0){
//         n=n/10;
//         count++;
//     }
//     printf("Number of digits in %d is %d",temp,count);
//     return 0;
// }



//Recursive Approach
#include <stdio.h>

int countDigit(long n){
    while(n!=0){
        return 1+countDigit(n/10);
    }
}

int main(){
    long n;
    printf("Enter a number: ");
    scanf("%ld",&n);
    printf("Number of digits in %ld is %ld",n,countDigit(n));
}
