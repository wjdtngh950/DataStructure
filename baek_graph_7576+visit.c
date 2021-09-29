#include <stdio.h>

#define TRUE 1
#define FALSE 0

int arr[1001][1001];
int visit[1001][1001];
int queue[5500000][3];
int front = -1;
int rear = -1;

int N, M;
int n_tomato;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

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
    scanf("%d %d", &M, &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == 0) {
                n_tomato++;
            }
            else if (arr[i][j] == 1) {
                n_tomato++;
                enqueue(i, j, 0); // i, j 위치의 토마토는 0일에 익는다.
            }
        }
    }
}

int bfs() {
    int answer = 0;
    while (front != rear) {
        int cx, cy, cd; //38항에서 enqueue해준걸 빼오는것(i,j,0)
        dequeue(&cx, &cy, &cd);
        if (arr[cx][cy] != -1) { // 큐에서 꺼낸 위치에 토마토가 존재하는 경우
            if (visit[cx][cy] == FALSE) { // visit[cx][cy]에 방문하지 않았으면,
                visit[cx][cy] = TRUE; // 방문처리
                answer = cd;
                n_tomato--; //익었으니까
                for (int k = 0; k < 4; k++) {
                    int nx = cx + dx[k];
                    int ny = cy + dy[k];
                    if (0 <= nx && nx < N && 0 <= ny && ny < M) { // 배열 내부 체크
                        // ==((0 <= nx && nx < N) && (0 <= ny && ny < M))
                        if (arr[nx][ny] != -1) {// 큐에 삽입할 위치에 토마토가 존재하는 경우
                            if (visit[nx][ny] == FALSE) { //현재 위치와 인접(상하좌우)한위치에아직 익지않은 토마토가 존재하는 경우
                                enqueue(nx, ny, cd + 1); //해당 위치를 큐에 삽입(인접한 토마토는 다음날에 익는다)
                            }
                        }
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