#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef int boolean;

int N;
int map[25][25];
boolean visit[25][25]; //->9/29 토마토와 다르게 여긴 왜 visit를 사용했는지> 그냥 map로 처리하면 안되나?
int home_count[110000];
int length;

int stack[110000][2];
int top = -1;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void push(int x, int y) {
    top++;
    stack[top][0] = x;
    stack[top][1] = y;
}

void pop(int* x, int* y) {
    *x = stack[top][0];
    *y = stack[top][1];
    top--;
}

void dfs() {
    int cnt = 0; // 단지 내 집의 수
    while (top != -1) {
        int cx, cy;
        pop(&cx, &cy);
        if (visit[cx][cy]==0) {
            visit[cx][cy] = TRUE;
            cnt++;
            for (int k = 0; k < 4; k++) {
                int nx = cx + dx[k];
                int ny = cy + dy[k];
                if (0 <= nx && nx < N && 0 <= ny && ny < N) {
                    if (map[nx][ny] == 1) { //9/29 ->44-46항이 이해가안감 뭘뜻하는지..? 왜 ==0이아닌지?
                        if (!visit[nx][ny]) {
                            push(nx, ny);
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
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            // 입력이 0110100 처럼 들어오기 때문에
            // 정수형 변수에 입력을 받으면, 의도하지 않은 형태로 값이 입력됨
            // char형 변수에 입력을 받은 뒤, int로 변환하여 사용
            char c;
            scanf(" %c", &c);
            map[x][y] = c - '0';
        }
    }

    for (int x = 0; x < N; x++) { //->9/29 85항부터가 무슨역할을하는지 ??
                                  // 토마토같은경우는 get_input에서 바로 푸쉬를해줬는데 왜 73항 85항여긴 따로 ??
        for (int y = 0; y < N; y++) {
            if (map[x][y] == 1) { // 집
                if (visit[x][y] == FALSE) {
                    push(x, y);
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