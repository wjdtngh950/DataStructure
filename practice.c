#include<stdio.h>

int top = -1;
int stack[100001];

int top2=-1;
int stack2[1000001];

int arr[100001];
int N;

void get_input() {
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        scanf("%d", &arr[i]);
    }
}

int main(){
    get_input();
    int n=1;
    int i=0;
    while (i<N){
        if(n<=arr[i]){
            while (n<=arr[i]){ //이 부분이 이해가안감
                stack[++top]=n; //push
                n++;
                stack2[++top2]='+';
            }
        }
        else if(top>-1&&stack[top]==arr[i]){
            top--;
            i++;
            stack2[++top2]='-';
        }
        else{
            printf("NO");
            return 0;
        }
    }
    for(int t=0;t<=top2;t++){
        printf("%c\n", stack2[t]);
    }
    return 0;

}