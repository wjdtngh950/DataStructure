#include<stdio.h>

#define TRUE 1
#define FALSE 0
#define SIZE 5500000

int rear = -1;
int front = -1;
int queue[SIZE][3];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int box[1001][1001];
int visit[1001][1001];
int N,M;
int tomato;

void enqueue(int x, int y, int d) {
    rear++;
    queue[rear][0] = x;
    queue[rear][1] = y;
    queue[rear][2] = d;
}

void dequeue(int *x, int *y, int *d) {
    front++;
    *x=queue[front][0];
    *y=queue[front][1];
    *d=queue[front][2];
}

void get_input(){
    scanf("%d %d", &M, &N);
    for(int i =0; i<N;i++){
        for(int j =0; j<M;j++){
            int K;
            scanf("%d", &K);
            box[i][j]=K;
            if(box[i][j]==0){
                tomato++;
            }
            else if(box[i][j]==1){
                tomato++;
                enqueue(i,j,0);
            }
        }
    }
}

int bfs() {
    int answer=0;
    while (front != rear) {
        int cx, cy, cd;
        dequeue(&cx, &cy, &cd);
        if (box[cx][cy] != -1) {
            if (visit[cx][cy] == FALSE) {
                visit[cx][cy] = TRUE;
                answer = cd;
                tomato--;
                for(int k=0;k<4;k++){
                    int nx=cx+dx[k];
                    int ny=cy+dy[k];
                    if(0<=nx&&nx<N&&0<=ny&&ny<M){
                        if(box[nx][ny]!=-1){
                            if(visit[nx][ny]==FALSE){
                                enqueue(nx,ny,cd+1);
                            }
                        }
                    }
                }
            }
        }
    }
    if(tomato==0){
        return answer;
    }
    else{
        return -1;
    }
}

int main(){
    get_input();
    printf("%d", bfs());
    return 0;
}