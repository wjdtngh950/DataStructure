#include <iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Node{
    char val;
    Node* prev;
    Node* next;
};

Node* head;
Node* last;
Node* cursor;

void addNode(char value){
    if(head==NULL){
        last = head = new Node;
        head->val=value;
        head->prev=NULL;
        head->next=NULL;
    }
    else{
        Node* newNode= new Node;
        newNode->val=value;
        newNode->prev=last;
        newNode->next=NULL;
        last->next=newNode;
        last=newNode;
    }
}

void get_input(){
    char buf[1100000];
    //scanf("%s", buf);
    cin >> buf;
    for(int i=0;buf[i]!='\0';i++){
        addNode(buf[i]);
    }
    addNode('$');
}

int main(){
    get_input();
    cursor=last;
    int N;
    //scanf("%d", &N);
    cin >> N;
    for(int i=0;i<N;i++){
        char c;
        //scanf(" %c", &c);
        cin >> c;
        if(c=='L'){
            if(cursor->prev!=NULL){ // (cursor!=head)
                cursor=cursor->prev;
            }
        }
        else if(c=='D'){
            if(cursor->next!=NULL){ //(cursor!=last)
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
            cin >> c2;
            Node* newNode = new Node;
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
        //printf("%c", p->val);
        cout << p->val;
    }
    //printf("\n");
    cout << endl;
    return 0;
}