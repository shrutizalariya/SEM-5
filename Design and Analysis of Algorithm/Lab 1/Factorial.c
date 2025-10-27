//factorial of num

//Iterative Approach
// #include<stdio.h>

// int main(){
//     int num,fact=1;
//     printf("Enter a number: ");
//     scanf("%d",&num);
//      if(num<0){
//           printf("Factorial of negative number doesn't exist");
//      }
//     for(int i=num;i>=1;i--){
//         fact=fact*i;
//     }
//     printf("The factorial of %d is %d",num,fact);
// }


//Recursive Approach
#include<stdio.h>

int factorial(int num){
    if(num==0 || num==1){
        return 1;
    }
    else{
        return num*factorial(num-1);
    }
}

int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d",&num);
    printf("The factorial of %d is %d",num,factorial(num));
}