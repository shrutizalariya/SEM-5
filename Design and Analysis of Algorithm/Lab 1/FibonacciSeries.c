//Fibonacci series

// #include <stdio.h>

// int fibonacci(int n);

// int main(){
//     int n;
//     printf("Enter the number :");
//     scanf("%d",&n);
//     printf("%dth term of fibonacci series is %d",n,fibonacci(n));
//     return 0;
   
// }

// int fibonacci(int n){
//     if(n<0){
//         printf("Invalid input");
//     }
//     if(n==0 || n==1){
//         return n;
//     }
//     else{
//         return fibonacci(n-2) + fibonacci(n-1);
//     }
// }


//print fibonacci series upto n

#include <stdio.h>

int fibonacci(int n){
    if(n<0){
        printf("Invalid input");
        return 0;
    }
    if(n==0 || n==1){
        return n;
    }
    else{
        return fibonacci(n-2) + fibonacci(n-1); 
    }
}

int main(){
    int n;
    printf("Enter the number :");
    scanf("%d",&n);
    for(int i=0;i<=n;i++){
        printf("%d ",fibonacci(i));
    }
    
    return 0;
}