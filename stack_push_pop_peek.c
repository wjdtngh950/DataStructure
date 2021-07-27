#include<stdio.h>

#define TRUE 1
#define FALSE 0
#define STACK_SIZE 110000

int stack[110000]; // int stack[STACK_SIZE]
int top = -1;

// is_full 스택이 가득찬지 확인
int is_full() {
    if (top == STACK_SIZE - 1) {
        return TRUE;
    } else {
        return FALSE;
    }
}

// is_empty 스택이 비어있는지 확인
int is_empty() {
    if (top == -1) {
        return TRUE;
    } else {
        return FALSE;
    }
}

void push(int val) {
    if (is_full()) {
        return; //stack 이가득 차면 종료
    }
    top++;
    stack[top] = val;
}

int pop() {
    if (top == -1) {
        return -1;
    }
    int rtn = stack[top];
    top--;
    return rtn; //15~17은 간단하게 이렇게 표현 가능 return stack[top--];
}

int peek() {
    if (top == -1) {
        return -1;
    }
    return stack[top];  //peek는 스택의 최상단에 값을 확인하는용 pop랑 같으나 빼지 않는것
}


int main() {
    for (int n = 1; n <= 3; n++) {
        push(n);
    }
    while(!is_empty()){ //=while(top>-1)
    printf("%d\n", pop());
}

    return 0;
}

