#include <iostream>
#include <stdio.h>

using namespace std;

int rear = -1;
int front = -1;
int queue[5500000][2];
int N, K;
int visit[100001];
int answer;

void get_input(){
    scanf("%d %d", &N, &K);
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



int bfs(){
    while (front!=rear) {
        front ++;
        int v=queue[front][0];
        int t=queue[front][1];
        if(v==K){
            return t;
        }
        if(!visit[v]){
            visit[v]=true;
            for(int k=0;k<3;k++){
                int nx=Next(v, k);
                if(0<=nx&&nx<=100000){
                    if(!visit[nx]){
                        rear++;
                        queue[rear][0]=nx;
                        queue[rear][1]=t+1;
                    }
                }
            }
        }
    }
}

int main(){
    get_input();
    rear++;
    queue[rear][0]=N;
    queue[rear][1]=0;

    answer=bfs();
    cout<<answer;

    return 0;
}