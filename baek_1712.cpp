#include<stdio.h>

int A, B, C;
int BC;
int answer;


int main(){
    scanf("%d %d %d", &A, &B, &C);

    BC=C-B;
    if(BC<0){
        answer=-1;
    }
    else {
        if(A==0){
            answer = 1;
        }
        else {
            answer = A / BC;
            answer++;
        }
    }
    printf("%d", answer);
    return 0;
}