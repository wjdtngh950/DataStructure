#include<stdio.h>

#define TRUE 1
#define FALSE 0
#define STACK_SIZE 1100000

char stack[STACK_SIZE];
int top=-1;

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

void push(char val) {
    if (is_full()) {
        return;
    }
    top++;
    stack[top] = val;
}

char pop() {
    if (is_empty()) {
        return '\0';
    }
    char rtn = stack[top];
    top--;
    return rtn;
}

int main() {
    while (1) {
        char buf[101];
        scanf("%s", buf);
        int error=FALSE;
        int cnt1=0;
        int cnt2=0;
        top=-1;
        for (int i = 0; buf[i] != '.'; i++) {
            if (buf[i] == '(') {
                push(buf[i]);
                cnt1++;
            }
            else if(buf[i]==')'){
                if(is_empty()||cnt2!=0){
                    error=TRUE;
                    break;
                }
                pop();
                cnt1--;
            }
            else if(buf[i]=='['){
                push(buf[i]);
                cnt2++;
            }
            else if(buf[i]==']'){
                if(is_empty()||cnt1!=0){
                    error=TRUE;
                    break;
                }
                pop();
                cnt2--;
            }
        }
        if(!(is_empty())){
            error=TRUE;
        }
        if(error==TRUE){
            printf("NO\n");
        }
        else{
            printf("YES\n");
        }

        //break; //나중에 지워주기
    }

    return 0;
}