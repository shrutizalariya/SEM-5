#include<stdio.h>
#define V 8

int front = -1,rear=-1;
int queue[V];

int dequeue() {
    if (!isEmpty()) {
        int val = queue[front];
        if (front == rear) {
            front = rear = -1; 
        } else {
            front++;
        }
        return val;
    }
    return -1; 
}

void enqueue(int val){
    if(rear<V-1){
        queue[++rear] = val;  
    }
    if(front==-1){
        front = 0;
    }
}

int isEmpty(){
   return front==-1;
}

int bfs(int graph[V][V]){
    int visited[V] = {0};

    visited[0] = 1;
    enqueue(0);

    while(!isEmpty()){
        int u = dequeue();
        printf("%d ",u+1);
        for(int i=0;i<V;i++){
            if(visited[i]==0 && graph[u][i]!=0){
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

void main(){
    int graph[V][V] = {
        {0, 1, 1, 1, 0, 0, 0, 0},
        {1, 0, 1, 0, 1, 1, 0, 0},
        {1, 1, 0, 0, 0, 1, 0, 0},
        {1, 0, 0, 0, 0, 0, 1, 1},
        {0, 1, 0, 0, 0, 1, 0, 0},
        {0, 1, 1, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 1},
        {0, 0, 0, 1, 0, 0, 1, 0}
    };
    bfs(graph);
}