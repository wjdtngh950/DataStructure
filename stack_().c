#include<stdio.h>

char s[100000];
int top=-1;

int main(){
    char buffer[1000];
    scanf("%s", buffer);
    int ERROR=0;

    for(int i=0; buffer[i]!='\0';i++){
        if(buffer[i]=='('){
            s[++top]='(';
        }
        else{
            if(top==-1){
                ERROR=1;
                break;
            }
            char open=s[top--];
            if(!(open=='(' && buffer[i]==')')){
                ERROR=1;
                break;
            }
        }
    }
    if(top!=-1){
        ERROR=1;
    }
    if(ERROR==1){
        printf("F");
    }
    else{
        printf("T");
    }
    return 0;
}

