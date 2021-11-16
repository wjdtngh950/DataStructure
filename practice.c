#include<stdio.h>

int A, B, C;
int BC;
int AC;
int answer;


int main(){
    scanf("%d %d %d", &A, &B, &C);
    AC=A-C;
    BC=C-B;
    answer=A/BC;
    answer++;

    if(AC==B){
        answer=-1;
    }

    printf("%d", answer);
    return 0;
}