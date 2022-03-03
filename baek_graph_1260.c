#include<stdio.h>

#define TRUE 1
#define FALSE 0
#define SIZE 1100000
int top = -1;
int front = -1;
int rear = -1;
int queue[SIZE];
int stack[SIZE];

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
    if (BFS_empty()) {
        return -1;
    }
    return queue[++front];
}

int edge[1001][1001];
int DFS_visit[1001];
int BFS_visit[1001];

int main() {
    int N, M, V;
    scanf("%d %d %d", &N, &M, &V);
    for (int m = 0; m < M; m++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        edge[v1][v2] = TRUE;
        edge[v2][v1] = TRUE;
    }
    //DFS
    push(V);
    while (!DFS_empty()) {
        int v = pop();
        if (!DFS_visit[v]) {
            DFS_visit[v] = TRUE;
            printf("%d ", v);
            for (int w = N; w > 0; w--) { //왜 반대로했더라 ?? 9/10
                if (!DFS_visit[w]) {
                    if (edge[v][w] == TRUE) {
                        push(w);
                    }
                }
            }
        }
    }
    printf("\n");

    enqueue(V);
    while (!BFS_empty()) {
        int v = dequeue();
        if (!BFS_visit[v]) {
            BFS_visit[v] = TRUE;
            printf("%d ", v);
            for (int w = 1; w <= N; w++) {
                if (!BFS_visit[w]) {
                    if (edge[v][w] == TRUE) {
                        enqueue(w);
                    }
                }
            }
        }
    }
    return 0;
}

