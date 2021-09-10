#include<stdio.h>

#define TRUE 1
#define FALSE 0
#define SIZE 1100000

int top = -1;
int front = -1;
int rear = -1;

int stack[SIZE];
int queue[SIZE];

int DFS_full() {
    if (top == SIZE - 1) {
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

int BFS_full() {
    if (rear == SIZE - 1) {
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

int pop() {
    if (DFS_empty()) {
        return -1;
    }
    return stack[top--];
}

void enqueue(int val2) {
    if (BFS_full()) {
        return;
    }
    queue[++rear] = val2;
}

int dequeue() {
    if (BFS_empty()) {
        return -1;
    }
    return queue[++front];
}

int edge[1001][1001];
int DFS_visit[1001];

int main() {
    int N;
    int M;
    int cnt=0;
    scanf("%d %d", &N, &M);
    for(int i=0;i<M;i++){
        int v1, v2;
        scanf("%d %d", &v1,&v2);
        edge[v1][v2]=1;
        edge[v2][v1]=1;
    }
    push(1);
    while(!DFS_empty()){
        int v=pop();
        if(!DFS_visit[v]){
            DFS_visit[v]=TRUE;
            cnt++;
            for(int w=N;w>0;w--){
                if(!DFS_visit[w]){
                    if(edge[v][w]==TRUE){
                        push(w);
                    }
                }
            }
        }
    }
    printf("%d", cnt-1);
    return 0;
}