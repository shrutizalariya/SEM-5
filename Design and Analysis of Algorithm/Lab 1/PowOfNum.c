//Power Of a number

//Iterative Approach
// #include <stdio.h>
// int main(){
//     int x,y,pow=1;
//     printf("Enter x and y:");
//     scanf("%d",&x);
//     scanf("%d",&y);
//     for(int i=1;i<=y;i++){
//         pow = pow*x;
//     }
//     printf("%d Power Of %d is %d",y,x,pow);
// }

//Recursive Approach
#include <stdio.h>

int power(int x,int y){
    if(y==0){
        return 1;
    }
    else{
        return x*power(x,y-1);
    }
}

int main(){
    int x,y;
    printf("Enter x and y:");
    scanf("%d",&x);
    scanf("%d",&y);
    printf("%d Power Of %d is %d",y,x,power(x,y));
}



//Power of negative number

//Iterative Approach
// #include <stdio.h>
// #include <math.h>

// int main(){
//     int x,y;
//     printf("Enter x and y:");
//     scanf("%d",&x);
//     scanf("%d",&y);
//     if(y<0){
//         printf("%d Power Of %d is %f",y,x,1/pow(x,-y));
//     }
//     else{
//         printf("%d Power Of %d is %d",y,x,pow(x,y));
//     }
    
//     return 0;
// }
