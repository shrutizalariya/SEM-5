//Sum of n num


//Iterative Approach
// #include <stdio.h>

// int main(){
//     int num,sum = 0;
//     printf("Enter a number:");
//     scanf("%d",&num);

//     for(int i=1;i<=num;i++){
//         sum = sum + i;
//     }

//     printf("Sum of 1 to %d is %d",num,sum);
// }


//Recursive Approach
#include <stdio.h>

int sum(long num){
    if (num!=0){
        return num + sum(num-1);
    }
}

int main(){
    long num;
    printf("Enter a number:");
    scanf("%ld",&num);
    printf("Sum of 1 to %ld is %ld",num,sum(num));
}