#include<stdio.h>
#include<limits.h>

#define V 5

int main(){
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 9},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int selected[V] = {0};
    selected[0] = 1;

    int edges = 0;
    int i, j;
    int Total_Cost = 0;

    printf("\nEdges \t Weigth\n");

    while(edges < V-1){
        int min = INT_MAX;
        int x = 0, y = 0;

        for(i=0; i<V; i++){
            if(selected[i]==1){
                for(j=0; j<V; j++){
                    if(selected[j]==0 && graph[i][j]!=0){
                        if(graph[i][j] < min){
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        printf("%d %d \t %d \n", x ,y , min); //min or graph[x][y7]
        Total_Cost = Total_Cost + graph[x][y];
        selected[y] = 1;
        edges++;
    }
    printf("Total Cost = %d",Total_Cost);
    return 0;
}