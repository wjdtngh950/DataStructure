#include "stdio.h"

#define TRUE 1
#define FALSE 0
#define SIZE 1100000

int top = -1;
int front = -1;
int rear = -1;
int stack[SIZE];
int queue[SIZE];
dd
int DFS_full() {
    if (top == SIZE - 1) {
        return TRUE;
    }
    return FALSE;
}

int BFS_full() {
    if (rear == SIZE - 1) {
        return TRUE;
    }
    return FALSE;
}

int DFS_empty() {
    if (top == -1) {
        return TRUE;
    }
    return FALSE;
}

int BFS_empty() {
    if (front == rear) {
        return TRUE;
    }
    return FALSE;
}

void push(int val1) {
    if (DFS_full()) {
        return;
    }
    stack[++top] = val1;
}

void enqueue(int val2) {
    if (BFS_full()) {
        return;
    }
    queue[++rear] = val2;
}

int pop() {
    if (DFS_empty()) {
        return -1;
    }
    return stack[top--];
}

int dequeue() {
    if (BFS_full()) {
        return -1;
    }
    return queue[++front];
}

int visitDFS[1001];
int visitBFS[1001];
int edge[1001][1001];

int main() {
    int N, M, V;
    scanf("%d %d %d", &N, &M, &V);
    for (int i = 0; i < M; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        edge[v1][v2] = TRUE;
        edge[v2][v1] = TRUE;
    }
    //DFS
    push(V);
    while (!(DFS_empty())){
        int v=pop();
        if(!(visitDFS[v])){
            visitDFS[v]=TRUE;
            printf("%d ", v);
            for(int w=N;w>0;w--){
                if(!(visitDFS[w])){
                    if(edge[v][w]==TRUE){
                        push(w);
                    }
                }
            }
        }
    }
    printf("\n");
    //BFS
    enqueue(V);
    while (!(BFS_empty())){
        int v=dequeue();
        if(!(visitBFS[v])){
            visitBFS[v]=TRUE;
            printf("%d ", v);
            for(int w=1;w<=N;w++){
                if(!visitBFS[w]){
                    if(edge[v][w]==TRUE){
                        enqueue(w);
                    }
                }
            }
        }
    }


    return 0;
}