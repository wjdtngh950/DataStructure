#include <stdio.h>

int arr[1001][1001];
int queue[5500000][3];
int front = -1;
int rear = -1;

int N, M;
int n_tomato;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

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
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == 0) {
                n_tomato++;
            }
            else if(arr[i][j] == 1){
                n_tomato++;
                enqueue(i, j, 0); // i, j 위치의 토마토는 0일에 익는다.
                arr[i][j] = 0;
            }
        }
    }
}

int bfs() {
    int answer = 0;
    while (front != rear) {
        int cx, cy, cd;
        dequeue(&cx, &cy, &cd);
        if (arr[cx][cy] == 0) { // arr[curx][cury]에 방문하지 않았으면,
            arr[cx][cy] = 1; // 방문처리
            answer = cd;
            n_tomato--;
            for (int k = 0; k < 4; k++) {
                int nx = cx + dx[k];
                int ny = cy + dy[k];
                if (0 <= nx && nx < M && 0 <= ny && ny < N) { // 배열 내부 체크
                    if (arr[nx][ny] == 0) {
                        enqueue(nx, ny, cd + 1);
                    }
                }
            }
        }
    }
    if (n_tomato == 0)
        return answer;
    else
        return -1;
}


int main(void) {
    get_input();
    printf("%d", bfs());
    return 0;
}