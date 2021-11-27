#include<stdio.h>
#define SIZE 5500000
int top =-1;
int stack[SIZE];

int top2= -1;
int stack2[SIZE];

int arr[SIZE];

int N;

void get_input(){
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        scanf("%d", &arr[i]);
    }
}
