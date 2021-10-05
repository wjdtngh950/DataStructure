#include<stdio.h>
#define TRUE 1
#define FALSE 0
#define SIZE 5500000

int top=-1;
int stack[SIZE][2];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int N;
int map[25][25];
int visit[25][25];
int home_count[1100000];
int length;

void push(int x, int y){
    top++;
    stack[top][0]=x;
    stack[top][1]=y;
}

void pop(int* x, int*y){
    *x=stack[top][0];
    *y=stack[top][1];
    top--;
}

void get_input() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c;
            scanf(" %c", &c);
            map[i][j] = c - '0';
        }
    }
}

void dfs(){
    int cnt=0;
    int cx, cy;
    pop(&cx, &cy);
    if(visit[cx][cy]==FALSE){
        visit[cx][cy]=TRUE;
        cnt++;
        for(int k=0;k<4;k++){
            int nx= cx+dx[k];
            int ny = cy+dy[k];
            if(0<=nx&&nx<N&&0<ny&&ny<N){
                if(map[nx][ny]==TRUE){
                    if(visit[nx][ny]==FALSE){
                        push(nx,ny);
                    }
                }
            }
        }
    }
    home_count[length++]=cnt;
}

int main(){
get_input();

for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
        if(map[i][j]==1){
            if(visit[i][j]==0){
                push(i,j);
                dfs();
            }
        }
    }
}

    return 0;
}
