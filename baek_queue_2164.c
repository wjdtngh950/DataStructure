#include<stdio.h>

#define TRUE 1
#define FALSE 0
#define QUEUE_SIZE 1100000

int queue[QUEUE_SIZE];
int front =-1;
int rear=-1;

int is_full(){
    if(rear==QUEUE_SIZE-1){
        return TRUE;
    }
    return FALSE;
}

int is_empty(){
    if(front==rear){
        return TRUE;
    }
    return FALSE;
}

void enqueue(int val){
    if(is_full()){
        return;
    }
    rear++;
    queue[rear]=val;
}

int dequeue(){
    if(is_empty()){
        return -1;
    }
    front++;
    int rtn=queue[front];
    return rtn;
}

int main(){
    int N;
    scanf("%d", &N);
    for(int i=1;i<=N;i++){
        enqueue(i); //1-N 까지 넣어주기
    }
    for(int j=1;j<=N-1;j++){
        dequeue();
        enqueue(dequeue()); //그림으로 설명 요함 8/23
    }
    printf("%d", queue[rear]);

    return 0;
}