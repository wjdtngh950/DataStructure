#include<stdio.h>

int A, B, C;
int AC;
int answer;


int main(){
    scanf("%d %d %d", &A, &B, &C);
    AC=A-C;
    answer=AC/B;

    if(AC==B){
        answer=-1;
    }

    printf("%d", answer);
    return 0;
}