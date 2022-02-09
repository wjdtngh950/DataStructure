#include<stdio.h>

#define TRUE 1
#define FALSE 0
#define STACK_SIZE 1100000

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
        return -1;
    }
    int rtn= stack[top];
    top--;
    return rtn;
    //return stack[top--];
}

int main(){
    int N;
    scanf("%d", &N);
    int sum=0;
    for(int n=0;n<N;n++){
        int m;
        scanf("%d", &m);
        if(m==0){
            pop() 
        }
        else{
            push(m);
        }
    }
    for(int i=0; i<=top;i++){
        sum+=stack[i];
    }
    printf("%d", sum);
    return 0;

}

