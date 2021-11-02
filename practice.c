#include<stdio.h>
#include<stdlib.h>

typedef struct _Node{
    char val;
    struct _Node* prev;
    struct _Node* next;
}Node;

Node* head;
Node* last;
Node* cursor;

void addNode(char value){
    if(head==NULL){
        last=head=(Node*) malloc(sizeof (Node));
        head->val=value;
        head->prev=NULL;
        head->next=NULL;
    }
    else{
        Node* newNode=(Node*) malloc(sizeof (Node));
        newNode->val=value;
        newNode->prev=last;
        newNode->next=NULL;
        last->next=newNode;
        last=newNode;
    }
}

void get_input(){
    char buf[1100000];
    scanf("%s", buf);
    for(int i=0;buf[i]!='\0';i++){
        addNode(buf[i]);
    }
    addNode('$');
}

int main(){
    get_input();
    cursor=last;
    int N;
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        char c;
        scanf(" %c", &c);
        if(c=='L'){
            if(cursor->prev!=NULL){ // (cursor!=head)
                cursor=cursor->prev;
            }
        }
        else if(c=='D'){
            if(cursor->next!=last){ //(cursor!=last)
                cursor=cursor->next;
            }
        }
        else if(c=='B'){
            if(cursor!=head){
                if(cursor->prev!=head){
                    cursor->prev=cursor->prev->prev;
                    cursor->prev->next=cursor;
                }
                else{
                    head=cursor;
                    cursor->prev=NULL;
                }
            }
        }
        else{
            char c2;
            scanf(" %c", &c2);
            Node* newNode=(Node*) malloc(sizeof (Node));
            newNode->val=c2;
            newNode->prev=cursor->prev;
            newNode->next=cursor;
            if(head==cursor){
                head=newNode;
            }
            else{
                cursor->prev->next=newNode;
            }
            cursor->prev=newNode;
        }
    }
    for(Node* p=head;p->val!='$';p=p->next){
        printf("%c", p->val);
    }
    printf("\n");
    return 0;
}

