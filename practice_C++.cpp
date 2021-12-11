#include<stdio.h>

int A, B, C;
int BC;
long long int answer;


int main(){
    scanf("%d %d %d", &A, &B, &C);

    BC=C-B;
    if(BC<=0){
        answer=-1;
    }
    else {
        answer = A / BC;
        answer++;
    }
    printf("%lld", answer);
    return 0;
}