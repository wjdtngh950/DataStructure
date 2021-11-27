#include<stdio.h>
#define SIZE 5500000

int top =-1;
int stack[SIZE];

int top2= -1;
char stack2[SIZE];

int arr[SIZE];

int N;

void get_input(){
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        scanf("%d", &arr[i]);
    }
}

int main(){
    get_input();
    int i=0;
    int n=1;

    while(i<N){
        if(top>-1&&stack[top]==arr[i]){
            top--;
            i++;
            stack2[++top2]='-';
        }
        else if(n<=arr[i]){
            while (n<=arr[i]){
               stack[++top]=n;
                n++;
                stack2[++top2]='+';
            }
        }
        else{
            printf("NO");
            return 0;
        }
    }
    for(int k=0;k<top2;k++){
        printf("%c\n", stack2[k]);
    }
    return 0;
}