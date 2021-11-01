#include<stdio.h>

#define TRUE 1
#define FALSE 0
#define SIZE 5500000

int top= -1;
int front = -1;
int rear = -1;
int stack[SIZE];
int queue[SIZE];

int edge[1001][1001];
int visit[1001];

int N, M, K;

void push(val1){
    top++;
    stack[top]=val1;
}

int pop(){
    return stack[top--];
}

void enqueue(val2){
    rear++;
    queue[rear]=val2;
}

int dequeue(){
   return queue[++front];
}

void get_input(){
   scanf("%d %d %d", &N, &M, &K);
   for(int i =0;i<M;i++){
       int v1, v2;
       scanf("%d %d", &v1, &v2);
       edge[v1][v2]=TRUE;
       edge[v2][v1]=TRUE;
   }
}

void dfs(){
    push(K);
    while (top!=-1){
        int v=pop();
        if(visit[v]==FALSE){
            visit[v]=TRUE;
            printf("%d ", v);
            for(int w=N;w>0;w--){
                if(edge[v][w]==TRUE){
                    if(visit[w]==FALSE){
                        push(w);
                    }
                }
            }
        }
    }
}

void reset(){
}

int main(){
    get_input();
    dfs();

}



