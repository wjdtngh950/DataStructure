#include<stdio.h>

#define TRUE 1
#define FALSE 0
#define QUEUE_SIZE 1100000

int front = -1;
int rear = -1;
int rear2 = -1;
int queue[QUEUE_SIZE];
int queue2[QUEUE_SIZE];

int is_full() {
    if (rear == QUEUE_SIZE - 1) {
        return TRUE;
    }
    return FALSE;
}

int is_empty() {
    if (rear == front) {
        return TRUE;
    }
    return FALSE;
}

void enqueue(int val) {
    if (is_full()) {
        return;
    }
    queue[++rear] = val;
}
void enqueue2(int val2) {
    if (is_full()) {
        return;
    }
    queue2[++rear2] = val2;
}

int dequeue() {
    if (is_empty()) {
        return -1;
    }
    return queue[++front];
}

int main() {
    int N;
    int K;
    int cnt = 0;
    scanf("%d %d", &N, &K);

    for (int i = 1; i <= N; i++) {
        enqueue(i);
    }

    while (1) {
        for (int i = 1; i <=K - 1; i++) {
            enqueue(dequeue());
        }
        enqueue2(dequeue());
        cnt++;
        if(cnt==N){
            break;
        }
    }
    printf("<%d, ", queue2[0]);
    for (int i = 1; i < N; i++) {
        printf(", %d", queue2[i]);
    }
    printf(">", queue2[N-1]);
    return 0;

}