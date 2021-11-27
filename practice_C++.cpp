#include <stdio.h>

int N;
int sum=1;
void get_input(){
    scanf("%d", &N);
}

int main(){
    get_input();
    for(int i=N;i>0;i--){
        sum*=i;
    }
    printf("%d", sum);
    return 0;
}