
#include<stdio.h>

#define TRUE 1
#define FALSE 0
#define STACK_SIZE 110000

int stack[STACK_SIZE];
int top=-1;

int is_full(){
    if(top==STACK_SIZE-1){
        return TRUE;
    }
    return FALSE;
}

int is_empty(){
    if(top==-1){
        return TRUE;
    }
    return FALSE;
}

void push(int val){
    if(is_full()){
        return;
    }
    top++;
    stack[top]=val;
}

int pop(){
    if(is_empty()){
        return -1; // int 에는 -1 char 에는 '\0'
    }
    int rtn=stack[top];
    top--;
    return rtn;
    //return stack[top--];
}

int main(){
    int N;
    int sum=0;
    scanf("%d", &N);

    for(int n=0;n<N;n++){
        int m;
        scanf("%d", &m);
        if(m==0){
            sum-=pop() // 이거 다시그림으로 설명 요함 ...
        }
        else{
            push(m);
            sum+=m; //sum+=push(m)은 안됨 왜냐하면 반환값이 없기때문
        }
    }
    printf("%d", sum);
    return 0;
}