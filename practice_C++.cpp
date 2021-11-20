#include<stdio.h>

int N;
int arr[1001];

void get_input(){
    scanf("%d", &N);
    for(int i=0; i< N;i++){
        scanf("%d", &arr[i]);
    }
}

void down(){
    for(int i =0; i<N;i++){
        for(int j=0;j<N-1;++){
            if(arr[j]<arr[j+1]){
                int target=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=target;
            }
        }
    }
}

int main(){
    get_input();
    down();
    for(int k=0;k<N;k++){
        printf("%d\n", arr[k]);
    }
    return 0;
}