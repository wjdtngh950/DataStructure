#include<stdio.h> //제출 c11 로 하기

#define TRUE 1
#define FALSE 0
#define STACK_SIZE 1100000

char stack[STACK_SIZE];
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
        char buf[102];
        int error = FALSE;
        top = -1;
        gets(buf);
        // 입력 버퍼
        if (buf[0] == '.' && buf[1] == '\0') {
            break;
        }
        for (int i = 0; buf[i] != '.'; i++) {
            if (buf[i] == '(') {
                push(buf[i]);
            }
            else if (buf[i] == ')') {
                if (is_empty()) {
                    error = TRUE;
                    break;
                }
                else if (stack[top] != '(') {
                    error = TRUE;
                    break;
                }
                pop();
            }
            else if (buf[i] == '[') {
                push(buf[i]);
            }
            else if (buf[i] == ']') {
                if (is_empty()) {
                    error = TRUE;
                    break;
                }
                else if (stack[top] != '[') {
                    error = TRUE;
                    break;
                }
                pop();
            }
        }
        if (!(is_empty())) {
            error = TRUE;
        }
        if (error == TRUE) {
            printf("no\n");
        }
        else {
            printf("yes\n");
        }
    }
    return 0;
}