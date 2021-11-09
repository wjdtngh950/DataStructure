#include <iostream>

using namespace std;

int rear = -1;
int front = -1;
int queue[2200000][2];
int answer;
bool visit[100001];
int N, K;

void enqueue(int x, int y) {
    rear++;
    queue[rear][0] = x;
    queue[rear][1] = y;
}

void dequeue(int& a1, int& a2) {
    front++;
    a1 = queue[front][0];
    a2 = queue[front][1];
}

int Next(int x, int idx) {
    switch (idx) {
        case 0:
            return x - 1;
        case 1:
            return x + 1;
        case 2:
            return 2 * x;

    }
}

void get_input() {
    cin >> N >> K;
}

int bfs() {
    while (front != rear) {
        int v, t;
        dequeue(v, t);
        if (v == K) {
            return t;
        }
        if (!visit[v]) {
            visit[v] = true;
            for (int idx = 0; idx < 3; idx++) {
                int nx = Next(v, idx);
                if (0 <= nx && nx <= 100000) {
                    if (!visit[nx]) {
                        enqueue(nx, t + 1);
                    }
                }
            }
        }
    }
}

int main() {
    get_input();
    enqueue(N, 0);

    answer = bfs();
    cout << answer;

    return 0;
}