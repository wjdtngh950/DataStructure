#include <stdio.h>

#define TRUE 1
#define FALSE 0

int edge[1001][1001];


int stack[1100000];
int top = -1;
int queue[1100000];
int front = -1, rear = -1;

int visitDFS[1001];
int visitBFS[1001];

int N, M, V;

int main(void) {
    scanf("%d %d %d", &N, &M, &V);
    for (int i = 0; i < M; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        edge[v1][v2] = 1;
        edge[v2][v1] = 1;
    }

    //DFS
    stack[++top] = V;
    while (top > -1) {
        int v = stack[top--];
        if (!visitDFS[v]) {
            visitDFS[v] = TRUE;
            printf("%d ", v);
            for (int w = N; w >= 1; w--) {
                if (edge[v][w] == 1) {
                    if (!visitDFS[w]) {
                        stack[++top] = w;
                    }
                }
            }
        }
    }
    printf("\n");

    //BFS
    queue[++rear] = V;
    while (front != rear) {
        int v = queue[++front];
        if (!visitBFS[v]) {
            visitBFS[v] = TRUE;
            printf("%d ", v);
            for (int w = 1; w <= N; w++) {
                if (edge[v][w] == 1) {
                    if (!visitBFS[w]) {
                        queue[++rear] = w;
                    }
                }
            }
        }
    }

    return 0;
}