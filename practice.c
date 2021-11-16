#include <stdio.h>


int rear = -1;
int front = -1;
int queue[100000];
int arr[100000];
int cnt;
int N,M;

void enqueue(int val){
    queue[++rear]=val;
}

int dequeue(){
    return queue[++front];
}


void get_input(){
    int n=1;
    scanf("%d %d", &N, &M);
    for(int i=1;i<=N;i++){
       enqueue(n);
        n++;
    }
    for(int m=0;m<M;m++){
        scanf("%d", &arr[m]);
    }
}

int main(){
    get_input();


    return 0;
}