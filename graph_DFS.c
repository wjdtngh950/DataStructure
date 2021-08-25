#include <stdio.h>

#define TRUE 1
#define FALSE 0

#define N 7

int edge[8][8] = {
        {0, 0, 0, 0, 0, 0, 0, 0}, // 0행
        {0, 0, 1, 1, 0, 0, 0, 0}, // 1행
        {0, 1, 0, 0, 1, 1, 0, 0}, // 2행
        {0, 1, 0, 0, 0, 0, 0, 1}, // 3행
        {0, 0, 1, 0, 0, 0, 1, 0}, // 4행
        {0, 0, 1, 0, 0, 0, 1, 0}, // 5행
        {0, 0, 0, 0, 1, 1, 0, 1}, // 6행
        {0, 0, 0, 1, 0, 0, 1, 0}  // 7행
};


int visited[8] = { 0, };
// DFS
int stack[110000];
int top = -1;

int main(void) {
    stack[++top] = 1; // 1번 정점에서 시작
    while (top > -1) {
        int v = stack[top--]; // v는 행
        if (!visited[v]) {
            visited[v] = TRUE;
            printf("%d ", v);
            for (int w = 1; w <= N; w++) { // w는 열
                if (edge[v][w] == 1) {
                    if (!visited[w]) {
                        stack[++top] = w;
                    }
                }
            }
        }
    }

    return 0;
}