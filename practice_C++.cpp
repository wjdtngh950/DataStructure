#include<iostream>
#include <stdio.h>

using namespace std;

int rear = -1;
int front = -1;
int queue[5500000][2];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int visit[50][50];
int map[50][50];
int N, M, K;
int worm;

void enqueue(int x, int y) {
    rear++;
    queue[rear][0] = x;
    queue[rear][1] = y;
}

void dequeue(int *x, int *y) {
    front++;
    *x = queue[front][0];
    *y = queue[front][1];
}

void get_input() {
    cin>>N>>M>>K;
    for (int i = 0; i < K; i++) {
        int v1, v2;
       cin>>v1>>v2;
        map[v1][v2] = 1;
    }
}

void bfs() {
    while (front != rear) {
        int cx, cy;
        dequeue(&cx, &cy);
        if(visit[cx][cy]==0){
            visit[cx][cy]=1;
           for(int k=0;k<4;k++){
                int nx=cx+dx[k];
                int ny=cy+dy[k];
                if(0<=nx&&nx<N&&0<=ny&&ny<M){
                    if(map[nx][ny]==1){
                        if(visit[nx][ny]==0) {
                            enqueue(nx, ny);
                        }
                    }
                }
            }
        }
    }
    worm++;
}

void reset(){
    for(int i =0;i<50;i++){
        for(int j=0;j<50;j++){
            map[i][j]=0;
            visit[i][j]=0;
        }
    }
    worm =0;
}

int main(){
    int T;
    cin >>T;
    for(int t=0;t<T;t++) {
        reset();
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
       cout<<worm<<endl;

   }
    return 0;
}