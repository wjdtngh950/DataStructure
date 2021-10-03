#include<stdio.h>
#define TRUE 1
#define FALSE 0
#define SIZE 5500000

int top =-1;
int stack[SIZE][2];
int map[25][25];
int visit[25][25];
int dx[4]={-1,1,0,0,};
int dy[4]={0,0,-1,1};
int N;
int home_count[1100000];
int length;

void push(int x, int y){
    top++;
    stack[top][0]=x;
    stack[top][1]=y;
}

void pop(int* x, int*y){
    *x= stack[top][0];
    *y= stack[top][1];
    top--;
}
void get_input(){
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            char c;
            scanf(" %c", &c);
            map[i][j]=c-'0';
        }
    }
}

void dfs(){
    int cnt=0;
    while (top!=-1){
        int cx,cy;
        pop(&cx, &cy);
        if(visit[cx][cy]==0){
            visit[cx][cy]=1;
            cnt++;
            for(int k=0;k<4;k++){
                int nx =cx+dx[k];
                int ny =cy+dy[k];
                if(0<=nx&&nx<N&&0<=ny&&ny<N){
                    if(map[nx][ny]==1){
                        if(visit[nx][ny]==0){
                            push(nx,ny);
                        }
                    }
                }
            }
        }
    }
    home_count[length++]=cnt;
}

void swap(int* v1, int* v2) {
    int tmp = *v1;
    *v1 = *v2;
    *v2 = tmp;
}

void bubble_sort() {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (home_count[j] > home_count[j + 1]) {
                swap(&home_count[j], &home_count[j + 1]);
            }
        }
    }
}


int main(){
    get_input();
    for(int x=0;x<N;x++){
        for(int y=0;y<N;y++){
            if(map[x][y]==1){
                if(visit[x][y]==0){
                    push(x,y);
                    dfs();
                }
            }
        }
    }
    bubble_sort();

    printf("%d\n", length);
    for (int l = 0; l < length; l++) {
        printf("%d\n", home_count[l]);
    }
    return 0;
}
