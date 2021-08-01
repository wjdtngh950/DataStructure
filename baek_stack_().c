#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define STACK_SIZE 110000

char stack[STACK_SIZE];
int top = -1;

int is_full() {
    if (top == STACK_SIZE - 1)
        return TRUE;
    return FALSE;
}

int is_empty() {
    if (top == -1)
        return TRUE;
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
    return stack[top--];
}

char peek() {
    if (is_empty()) {
        return '\0';
    }
    return stack[top];
}

int main(void) {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        top = -1;
        int error = FALSE;
        char buf[51];
        scanf("%s", buf);
        for (int i = 0; buf[i] != '\0'; i++) {
            if (buf[i] == '(') {
                // push
                push(buf[i]);
            } else {
                if (is_empty()) {
                    error = TRUE;
                    break;
                }
                pop();
            }
        }
        if (!is_empty()) { //= if(!(top==-1)) = if(top!=-1)
            error = TRUE;
        }
        if (error == TRUE) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }
    return 0;
}