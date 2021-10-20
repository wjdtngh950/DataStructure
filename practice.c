#include<stdio.h>
#define TRUE 1
#define FALSE 0
#define SIZE 5500000


int front = -1;
int rear = -1;
int queue[SIZE][3];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int N, M;
int map[101][101];
int visit[101][101];
int cnt;

void enqueue(int x, int y, int d){
    rear++;
    queue[rear][0]=x;
    queue[rear][1]=y;
    queue[rear][2]=d;
}

void dequeue(int *x, int *y, int *d){
    front++;
    *x=queue[front][0];
    *y=queue[front][1];
    *d=queue[front][2];
}

void get_input(){
    scanf("%d %d", &N, &M);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            char c;
            scanf(" %c", &c);
            map[i][j]=c -'0';
        }
    }
}

int bfs(){
    while (front!=rear) {
        int cx, cy, cd;
        dequeue(&cx, &cy, &cd);
        if (visit[cx][cy] == FALSE) {
            visit[cx][cy] = TRUE;
            cnt = cd;
            if (cx == N - 1 && cy == M - 1) break;
            for(int k=0;k<4;k++){
                int nx=cx+dx[k];
                int ny=cy+dy[k];
                if(0<=nx&&nx<N&&0<=ny&&ny<M){
                    if(map[nx][ny]==1){
                        if(visit[nx][ny]==0){
                            enqueue(nx, ny, cd+1);
                        }
                    }
                }
            }
        }
    }
    return cnt;
}

int main(){
    get_input();
    enqueue(0, 0, 1);
    bfs();

    printf("%d", cnt);
    return 0;
}