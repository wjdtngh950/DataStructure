#include<iostream>

using namespace std;

int arr[1001];
int N;

void get_input(){
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
}

void up(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N-1;j++){
            if(arr[j]>arr[j+1]){
                int target = arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=target;
            }
        }
    }
}

int main(){
    get_input();
    up();
    for(int i =0;i<N;i++){
        printf("%d\n", arr[i]);
    }
    return 0;
}