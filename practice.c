#include<stdio.h>

int top = -1;
int stack[1000001];

int top2 = -1;
int stack2[1000001];

int arr[1000001];


int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);

    }
    int i=0;
    int n = 1;

    while (i<N) {
        if (n <= arr[i]) {
            while (n <= arr[i]) {
                stack[++top] = n;
                n++;
                stack2[++top2] = '+';
            }
        } else if (top > -1 && stack[top] == arr[i]) {
            top--;
            i++;
            stack2[++top2] = '-';
        } else {
            printf("NO");
            return 0;
        }
    }

    for(int i=0;i<=top2;i++){
        printf("%c\n", stack2[i]);
    }
    return 0;
}