
#include<stdio.h>

#define TRUE 1
#define FALSE 0
#define QUEUE_SIZE 2200000

int queue[QUEUE_SIZE];
int front = -1;
int rear = -1;

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
    queue[++rear]=val;
}

int dequeue(){
    if(is_empty()){
        return -1;
    }
    return queue[++front];
}

int main(){
    int N;
    scanf("%d", &N);
    for(int n=0;n<N;n++){
        char buf[6];
        scanf("%s", buf);
        if(buf[0]=='p'&&buf[1]=='u'){
            int X;
            scanf("%d", &X);
            enqueue(X);
        }
        else if(buf[1]=='o'){
            if(is_empty()){
                printf("-1\n");
            }
            else {
                printf("%d\n", dequeue());
            }
        }
        else if(buf[0]=='s'){
            printf("%d\n", rear - front);
        }
        else if(buf[0]=='e'){
            printf("%d\n", is_empty());
        }
        else if(buf[0]=='f'){
            if(is_empty()){
                printf("-1\n");
            }
            else{
                printf("%d\n", queue[front+1]);
            }
        }
        else{
            if(is_empty()){
                printf("-1\n");
            }
            else{
                printf("%d\n",queue[rear]);
            }
        }
    }
    return 0;
}

