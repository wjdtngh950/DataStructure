#include<stdio.h>

typedef struct _Node{
    int data;
    struct _node* link;
}Node;

int main(){
    Node a, b, c, d;
    a.data=10;
    a.link=&b;
    b.data=6;
    b.link=&c;
    c.data=4;
    c.link=&d;
    d.data=2;
    d.link=NULL;

    for(Node* p =&a;p!=NULL;p=p->link){
        printf("%d->", p->data);
    }
    return 0;
}