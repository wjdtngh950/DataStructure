#include<stdio.h>

#define TRUE 1
#define FALSE 0
#define SIZE 5500000

int worm;
int top = -1;
int stack[SIZE][2];
int N, M, K;
int map[50][50];
int visit[50][50];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void push(int x, int y) {
    top++;
    stack[top][0] = x;
    stack[top][1] = y;
}

void pop(int *x, int *y) {
    *x = stack[top][0];
    *y = stack[top][1];
    top--;
}

void get_input() {
    scanf("%d %d %d", &M, &N, &K);
    for (int i = 0; i < K; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        map[v2][v1] = 1;
    }
}

void dfs() {
    while (top!=-1) {
        int cx, cy;
        pop(&cx, &cy);
        if (visit[cx][cy] == FALSE) {
            visit[cx][cy] = TRUE;
            for (int k = 0; k < 4; k++) {
                int nx, ny;
                nx = cx + dx[k];
                ny = cy + dy[k];
                if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                    if (map[nx][ny] == TRUE) {
                        if (visit[nx][ny] == FALSE) {
                            push(nx, ny);
                        }
                    }
                }
            }
        }
    }
    worm++;
}

void test(){
    for(int i=0;i<50;i++){
        for(int j=0;j<50;j++){
            map[i][j]=0;
            visit[i][j]=0;
        }
    }
    worm=0;
}

int main() {
    int t;
    scanf("%d", &t);
    for(int p=0;p<t;p++) {
     test();
     get_input();
     for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] == 1) {
                    if (visit[i][j] == 0) {
                        push(i, j);
                        dfs();
                    }
                }
            }
        }
        printf("%d\n", worm);
    }
    return 0;
}