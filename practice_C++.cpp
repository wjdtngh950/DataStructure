#include <iostream>
#define SIZE 2200000

using namespace std;

int rear = -1;
int front = -1;
int queue[SIZE][2];
int answer;
bool visit[100001];
int N, K;

int Next(int x, int idx){
    switch (idx) {
        case 0:
            return x-1;
        case 1:
            return x+1;
        case 2:
            return 2*x;

    }
}

void get_input() {
    cin >> N >> K;
}

int bfs() {
    while (front != rear) {
        front++;
        int v=queue[front][0];
        int t=queue[front][1];
        if(v==K){
            return t;
        }
        if(!visit[v]){
            visit[v]=true;
            for(int idx=0;idx<3;idx++){
                int nx=Next(v, idx);
                if(0<nx&&nx<=100000){
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

int main() {
    get_input();
   rear++;
    queue[rear][0] = N;
    queue[rear][1] = 0;

     answer=bfs();
    cout<<answer;

    return 0;
}