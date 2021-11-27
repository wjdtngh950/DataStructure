#include<stdio.h>


int A, B, C;
int BC;
int sum;
long long int answer;

void get_input(){
    scanf("%d %d %d", &A, &B, &C);
    BC=C-B;
}



int main() {
    get_input();
    if (BC<=0) {
        answer = -1;
        printf("%lld", answer);
    } else{
        answer=A/BC;
        printf("%lld", answer+1);
    }
    return 0;
}