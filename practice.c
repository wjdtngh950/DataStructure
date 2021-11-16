#include<stdio.h>

#define SIZE 550000

int top = -1;
int stack[SIZE];
int stack2[SIZE]; //기호저장
int top2 = -1;
int arr[SIZE];


int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    int n = 1;
    int i= 0;
    while(i<N) {
        if (top > -1 && stack[top] == arr[i]) {
            top--;
            i++;
            stack2[++top2] = '-';
        }
        else if (n<=arr[i]){
            while (n<=arr[i]) {
                stack[++top]=n;
                n++;
                stack2[++top2] = '+';
            }
        }
        else{
            printf("NO");
            return 0;
        }
    }

    for(int i=0;i<=top2;i++){
        printf("%c\n", stack2[i]);
    }
    return 0;

}

