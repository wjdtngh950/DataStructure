//
// Created by 정수호 on 01/08/2021.
//

#include<stdio.h>

#define TRUE 1
#define FALSE 0
#define STACK_SIZE 1100000

int stack[STACK_SIZE];
int top = -1;

int is_full() {
    if (top == STACK_SIZE - 1) {
        return TRUE;
    }
    return FALSE;
}

int is_empty() {
    if (top == -1) {
        return TRUE;
    }
    return FALSE;
}

void push(int val){
    if(is_full()){
        return;
    }

    stack[++top]=val;
}

int pop(){
    if(is_empty()){
        return -1;
    }
    return stack[top--];
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        char buf[6];
        scanf("%s", buf);
        if (buf[0] == 'p' && buf[1] == 'u') {
            int X;
            scanf("%d", &X);
            push(X);
        } else if (buf[0] == 'p' && buf[1] == 'o') {
            printf("%d\n", pop());
        } else if (buf[0] == 's') {
            printf("%d\n", top + 1);
        } else if (buf[0] == 'e') {
            printf("%d\n", is_empty());
        } else if(buf[0]=='t'){
            if (!(is_empty())) {
                printf("%d\n", stack[top]);
            } else {
                printf("-1\n");
            }
        }
    }
    return 0;
}