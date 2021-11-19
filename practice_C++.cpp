#include<stdio.h>

int N;
int arr[1001];

void get_input(){
    scanf("%d", &N);
    for(int i=0; i<N;i++){
        scanf("%d", &arr[i]);
    }
}

void up(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N-1;j++){
            int target=arr[j+1];
            if(arr[j]>arr[j+1]){
                arr[j+1]=arr[j];
                arr[j]=target;
            }
        }
    }
    for()
}