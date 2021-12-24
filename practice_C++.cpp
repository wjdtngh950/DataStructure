#include<stdio.h>

#define TRUE 1
#define FALSE 0
#define SIZE 5500000

int N, M, K;
int queue[SIZE][2];
int front = -1;
int rear = -1;
int worm;

int map[300][300];
int visit [300][300];

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

void enqueue(int x, int y){
    rear++;
    queue[rear][0]=x;
    queue[rear][1]=y;
}

void dequeue(int*x, int*y){
    front++;
    *x=queue[front][0];
    *y=queue[front][1];
}

void get_input()
    scanf("%d %d %d", &M, &N, &K);
    for(int i=0;i<K;i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        map[v2][v1]=1;
    }
}

void bfs() {
    while (rear != front) {
        int cx, cy;
        dequeue(&cx, &cy);
        if (visit[cx][cy] == 0) {
            visit[cx][cy] = 1;
            for (int i = 0; i < 4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                    if (map[nx][ny] == 1) {
                        if (visit[nx][ny] == 0) {
                            enqueue(nx, ny);
                        }
                    }
                }
            }
        }
    }
    worm++;
}

void resett(){
    for(int i=0;i<300;i++){
        for(int j=0;j<300;j++){
            map[i][j]=0;
            visit[i][j]=0;
        }
    }
    worm=0;
}

int main(){
    int T;
    scanf("%d", &T);
    for(int t=0;t<T;t++) {
        resett();
        get_input();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] == 1) {
                    if (visit[i][j] == 0) {
                        enqueue(i, j);
                        bfs();
                    }
                }
            }
        }
        printf("%d\n", worm);
    }
    return 0;
}