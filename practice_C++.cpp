#include<stdio.h>


int A, B, C;

int BC;

int sum;

int get_input(){
    scanf("%d %d %d", &A, &B, &C);
    BC=C-B;
    sum = A/BC;
    if(sum <=0){
        printf("%d", -1);
        return 0;
    }
}



int main() {
    get_input();
    if (A <= BC) {
        printf("%d", 1);
    } else if (sum >= 0) {
        printf("%d", sum+1);
    }
    return 0;
}