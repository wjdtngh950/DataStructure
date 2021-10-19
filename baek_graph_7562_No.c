#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define SIZE 5500000

int front =-1;
int rear = -1;
int queue[SIZE][2];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int map[310][310];
int visit[310][310];
int N,m,M,l,L;
int knight=0;

void enqueue(int x, int y){
    rear++;
    queue[rear][0]=x;
    queue[rear][1]=y;
}

void dequeue(int *x, int *y){
    front++;
    *x=queue[front][0];
    *y=queue[front][1];
}

void get_input(){
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            map[i][j]=0;
        }
    }
    scanf("%d %d", &m, &M);
    scanf("%d %d", &l,&L);
    map[m][M]=1;
    map[l][L]=1;
}
void bfs(){
    while (front!=rear){
        int cx, cy;
        dequeue(&cx, &cy);
        if(visit[cx][cy]==0){
            visit[cx][cy]=1;
            knight++;
            for(int k=0;k<4;k++){
                int nx=cx+dx[k];
                int ny=cy+dy[k];
                if(0<=nx&&nx<N&&0<=ny&&ny<N){
                    if(map[nx][ny]==1){
                        if(visit[nx][ny]==0){
                            enqueue(nx,ny);
                        }
                    }
                }
            }
        }
    }
}

int main(){
    get_input();


    return 0;
}