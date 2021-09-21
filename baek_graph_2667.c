#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef int boolean;

int N;
int map[25][25];
boolean visit[25][25];
int home_count[110000];
int length;

int stack[110000][2];
int top = -1;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void push(int y, int x) {
    top++;
    stack[top][0] = y;
    stack[top][1] = x;
}

void pop(int* py, int* px) {
    *py = stack[top][0];
    *px = stack[top][1];
    top--;
}

void dfs() {
    int cnt = 0; // 단지 내 집의 수
    while (top != -1) {
        int cur_y, cur_x;
        pop(&cur_y, &cur_x);
        if (!visit[cur_y][cur_x]) {
            visit[cur_y][cur_x] = TRUE;
            cnt++;
            for (int k = 0; k < 4; k++) {
                int next_y = cur_y + dy[k];
                int next_x = cur_x + dx[k];
                if (0 <= next_y && next_y < N && 0 <= next_x && next_x < N) {
                    if (map[next_y][next_x] == 1) {
                        if (!visit[next_y][next_x]) {
                            push(next_y, next_x);
                        }
                    }
                }
            }
        }
    }
    home_count[length++] = cnt;
}

void swap(int* v1, int* v2) {
    int tmp = *v1;
    *v1 = *v2;
    *v2 = tmp;
}

void bubble_sort() {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (home_count[j] > home_count[j + 1]) {
                swap(&home_count[j], &home_count[j + 1]);
            }
        }
    }
}

int main(void) {
    scanf("%d", &N);
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            // 입력이 0110100 처럼 들어오기 때문에
            // 정수형 변수에 입력을 받으면, 의도하지 않은 형태로 값이 입력됨
            // char형 변수에 입력을 받은 뒤, int로 변환하여 사용
            char c;
            scanf(" %c", &c);
            map[y][x] = c - '0';
        }
    }

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (map[y][x] == 1) { // 집
                if (visit[y][x] == FALSE) {
                    push(y, x);
                    dfs();
                }
            }
        }
    }

    bubble_sort();

    printf("%d\n", length);
    for (int l = 0; l < length; l++) {
        printf("%d\n", home_count[l]);
    }

    return 0;
}