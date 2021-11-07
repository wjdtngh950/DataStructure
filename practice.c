#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define SIZE 5500000

int front = -1;
int rear = -1;
int queue[SIZE][3];
int dx[8] = { -2, -1,  1,  2,  2,  1, -1, -2 }; //나이트의 이동범위만 적어주면됨 한번에 이동할 수 있는 거리
int dy[8] = {  1,  2,  2,  1, -1, -2, -2, -1 };
int visit[310][310];
int T, N, m, M, l, L;
int knight = 0;

void enqueue(int x, int y, int d) {
    rear++;
    queue[rear][0] = x;
    queue[rear][1] = y;
    queue[rear][2] = d;
}

void dequeue(int* x, int* y, int* d) {
    front++;
    *x = queue[front][0];
    *y = queue[front][1];
    *d = queue[front][2];
}

void get_input() {
    scanf("%d", &N);
    scanf("%d %d", &m, &M);
    scanf("%d %d", &l, &L);
    enqueue(m, M, 0); //나이트의 처음갯수는 0
}

void bfs() {
    while (front != rear) {
        int cx, cy, cd;
        dequeue(&cx, &cy, &cd);
        if (visit[cx][cy] == 0) {
            visit[cx][cy] = 1;
            knight = cd;
            if (cx == l && cy == L) break;
            for (int k = 0; k < 8; k++) {
                int nx = cx + dx[k];
                int ny = cy + dy[k];
                if (0 <= nx && nx < N && 0 <= ny && ny < N) {
                    if (visit[nx][ny] == 0) {
                        enqueue(nx, ny, cd + 1);
                    }
                }
            }
        }
    }
}

void init() {
    front = rear = -1;
    for (int i = 0; i < 300; i++) {
        for (int j = 0; j < 300; j++) {
            visit[i][j] = 0;
        }
    }
}

int main() {
    scanf("%d", &T);

    for (int tc = 0; tc < T; tc++) {
        init();
        get_input();
        bfs();
        printf("%d\n", knight);
    }

    return 0;
}