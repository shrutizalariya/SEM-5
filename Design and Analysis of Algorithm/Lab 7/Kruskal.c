#include<stdio.h>

typedef struct{
    int source;
    int dest;
    int weight;
}Edge;

int find(int parent[],int i){
    if(parent[i]==i)
        return i;
    return find(parent,parent[i]);
}

void Setunion(int parent[],int u,int v){
    parent[u] = v;
}

void sortEdges(Edge edges[],int E){
    for(int i = 0; i < E ; i++){
        for(int j = 0 ; j < E-i-1 ; j++){
            if(edges[j].weight > edges[j+1].weight){
                Edge temp = edges[j];
                edges[j] = edges[j+1];
                edges[j+1] = temp;
            }
        }
    }
}

void kruskal(Edge edges[],int V,int E){
    int parent[V];
    int edge = 0;
    Edge mst[V-1];

    sortEdges(edges,E);

    for(int i = 0 ; i < V ; i++){
        parent[i] = i;
    }

    for (int i = 0;i < E; i++){
        int u = edges[i].source;
        int v = edges[i].dest;

        int ucomp = find(parent,u);
        int vcomp = find(parent,v);

        if(ucomp!=vcomp){
            mst[edge] = edges[i];
            Setunion(parent,ucomp,vcomp);
            edge++;
        }
        
        if(edge == V-1) break;
    }

    int total_cost= 0;

    for(int i = 0 ; i < V-1 ; i++){
        printf("%d -- %d == %d\n",mst[i].source,mst[i].dest,mst[i].weight);
        total_cost += mst[i].weight;
    }

    printf("Total Cost = %d",total_cost);
}

void main(){
    Edge edges[] = {
        {0,1,7},
        {0,3,5},
        {1,2,8},
        {1,3,9},
        {1,4,7},
        {2,4,5},
        {3,4,15},
        {3,5,6},
        {4,5,8},
        {4,6,9},
        {5,6,11}
    };

    int V = 7;
    int E = sizeof(edges)/sizeof(edges[0]);
    kruskal(edges,V,E); // 7 vertices and 11 edges
}