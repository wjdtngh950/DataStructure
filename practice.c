#include<stdio.h>

#define TRUE 1
#define FALSE 0
#define SIZE 5500000


int front = -1;
int rear = -1;
int queue[SIZE][3];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int N, M;
int map[101][101];
int visit[101][101];

void enqueue(int x, int y) {
    rear++;
    queue[rear][0] = x;
    queue[rear][1] = y;
}

void dequeue(int *x, int *y) {
    front++;
    *x = queue[front][0];
    *y = queue[front][1];
}

void get_input(){
    
}
