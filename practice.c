#include<stdio.h>
typedef struct _Node{
    char val;
    struct Node* prev;
    struct Node* next;
}Node;

Node buf[110000];
int bufCnt;
Node* head;
Node* last;

Node* myAlloc(int n){
    buf[bufCnt].val=n;
    buf[bufCnt].prev=last;
    buf[bufCnt].next=NULL;
    return &buf[bufCnt++];
}

void addNode(char value){
    if(head==NULL){
        last=head= myAlloc(value);
    }
    else{
        last=last->next= myAlloc(value);
    }
}

void printList(){
    for(Node* p=head;p!=NULL;p=p->next){
        printf("%d", p->val);
    }
}

int main(){
    char N[100000];
    scanf("%s", N);
    for(int i=0;N[i]!='\0';i++){
        addNode(N[i]);
    }
    addNode('$');
    Node *cursor=last;
    int M;
    scanf("%d", &M);
    for(int i=0;i<M;i++){
        char cmd;
        scanf(" %c", &cmd);
        if(cmd=='L'){
            if(head!=NULL){
                cursor=cursor->prev;
            }
        }
        else if(cmd=='D'){
            if(last!=NULL){
                cursor=cursor->next;
            }
        }
        else if(cmd=='B'){

        }
    }

    printList();
    return 0;
}