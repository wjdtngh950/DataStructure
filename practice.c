#include <stdio.h>
using namespace std;

int N, temp;

int arr[100001]; // 입력 배열
int stack[100001]; // 스택
int stack_top = -1;

char op_stack[200002]; // 문자 스택(+/-)
int op_stack_top = -1;

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) { // 수열 입력
        scanf("%d", &arr[i]);
    }
    int n = 1; // 1 ~ N
    int i = 0;
    while (i < N) { // arr[0] ~ arr[N-1]
        if (stack_top > -1 && stack[stack_top] == arr[i]) {
            stack_top--; // pop;
            i++;
            op_stack[++op_stack_top] = '-';
        } // 스택에서 값을 꺼내는 동작
        else if (n <= arr[i]) {
            while (n <= arr[i]) {
                stack[++stack_top] = n;
                n++;
                op_stack[++op_stack_top] = '+';
            }
        }
        else {
            printf("NO");
            return 0;
        }
    }
    for (int i = 0; i <= op_stack_top; i++) {
        printf("%c\n", op_stack[i]);
    }

    return 0;
}