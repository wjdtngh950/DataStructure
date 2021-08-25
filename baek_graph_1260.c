#include<stdio.h>
#define TRUE 1
#define FALSE 0
#define STACK_SIZE 1100000

int stack[STACK_SIZE];
int top=-1;

int queue[1100000];
int front = -1;
int rear = -1;

int is_full1(){
    if(top==STACK_SIZE-1){
        return TRUE;
    }
    return FALSE;
}
int is_full2(){
    if(rear==STACK_SIZE-1){
        return TRUE;
    }
    return FALSE;
}

int is_empty1(){
    if(top==-1){
        return TRUE;
    }
    return FALSE;
}

int is_empty2(){
    if(front==rear){
        return TRUE;
    }
    return FALSE;
}


void push(int val1){
    if(is_full1()){
        return;
    }
    stack[++top]=val1;
}

void enqueue(int val2){
    if(is_full2()){
        return;
    }
    queue[++rear]= val2;
}

int pop(){
    if(is_empty1()){
        return -1;
    }
    return stack[top--];
}

int dequeue(){
    if(is_empty2()){
        return -1;
    }
    return queue[++front];
}

int edge[1001][1001];

int visitDFS[1001];
int visitBFS[1001];
int main(){
    int N, M, V;
    scanf("%d %d %d", &N, &M, &V);
    for(int i=0;i<M;i++){
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        edge[v1][v2]=TRUE;
        edge[v2][v1]=TRUE;
    }
    //DFS
    push(V);
    while(!(is_empty1())){
        int v=pop();
        if(!visitDFS[v]){
            visitDFS[v]=TRUE;
            printf("%d ", v);
            for(int w=N;w>=1;w--){
                if(edge[v][w]==TRUE) {
                    if (!visitDFS[w]) {
                        push(w);
                    }
                }
            }
        }
    }
    printf("\n");
    //BFS
    enqueue(V);
    while (!(is_empty2())){
        int v=dequeue();
        if(!visitBFS[v]){
            visitBFS[v]=TRUE;
            printf("%d ", v);
            for(int w=1;w<=N;w++){
                if(edge[v][w]==TRUE){
                    if(!visitBFS[w]){
                        enqueue(w);
                    }
                }
            }
        }
    }
    return 0;
}