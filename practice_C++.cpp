#include<stdio.h>
#include "iostream"

using namespace std;

int N, K;
bool visit[100001];
int queue[1000001][2];
int rear, front =-1;
int answer;

void enqueue(int x, int y){
    rear++;
    queue[rear][0]=x;
    queue[rear][1]=y;
}

void dequeue(int *x, int* y){
    front++;
    *x=queue[front][0];
    *y=queue[front][1];
}

int Next(int x, int idx){
    switch (idx) {
        case 0: {
            return x-1;
        }
        case 1: {
            return x+1;
        }
        case 2:{
            return 2*x;
        }
    }
}

void get_input(){
    scanf("%d %d", &N, &K);
    enqueue(N, 0);
}

int bfs(){
    while (front!=rear){
        int v, t;
        dequeue(&v, &t);
        if(v==K){
            return t;
        }
        if(visit[v]==0){
            visit[v]=true;
            for(int k=0;k<3;k++){
                int nx=Next(v, k);
                if(0<=nx&&nx<=100000){
                    if(visit[nx]==0){
                        enqueue(nx, t+1);
                    }
                }
            }
        }
    }
}


int main(){
    get_input();
    enqueue(N, 0);
    answer=bfs();
    printf("%d", answer);
    return 0;
}

