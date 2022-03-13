#include<stdio.h>
#include<string.h>

#define TRUE 1
#define FALSE 0
#define STACK_SIZE 110000

int stack[STACK_SIZE];
int top = -1;
int cnt;



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

void push(int val) {
    if (is_full()) {
        return;
    }
    top++;
    stack[top] = val;
}

int pop() {
    if (is_empty()) {
        return -1;
    }
    int rtn = stack[top];
    top--;
    return rtn;
    //return stack[top--];
}

int main() {
    int N;
    int m;
    scanf("%d", &N);
    char buf[6]; //  가장 긴게 엠티니까
    for (int i = 0; i < N; i++) {
        scanf("%s", buf);
        if (buf[0] == 'p' && buf[1] == 'u') {
            scanf("%d", &m);
            push(m);
        }
        else if(buf[0]=='p'&&buf[1]=='o'){
            printf("%d\n", pop());
        }
        else if(buf[0]=='s'){
            printf("%d\n", top+1);
        }
        else if(buf[0]=='e'){
            if(is_empty()){
                printf("%d\n", TRUE);
            }
            else{
                printf("%d\n", FALSE);
            }
        }
        else{
            if(!is_empty()){
                printf("%d\n", stack[top]);
            }
            else{
                printf("-1\n");
            }
        }
    }
    return 0;
}