#include <stdio.h>

#define TRUE 1
#define FALSE 0

#define QUEUE_SIZE 110000

int queue[QUEUE_SIZE];
int front = -1; // 가장 최근에 삭제된 원소의 인덱스를 가짐
int rear = -1; // 가장 최근에 추가된 원소의 인덱스를 가짐

int is_empty() {
    return front == rear ? TRUE : FALSE;
}

int is_full() {
    return rear == QUEUE_SIZE - 1 ? TRUE : FALSE;
}

void enqueue(int val) {
    if (is_full()) {
        return;
    }
    queue[++rear] = val;
}

int dequeue() {
    if (is_empty()) {
        return -1;
    }
    return queue[++front];
}

int peek() {
    if (is_empty()) {
        return -1;
    }
    return queue[front + 1];
}

int main(void) {

    return 0;
}