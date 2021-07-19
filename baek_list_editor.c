#include <stdio.h>

typedef struct _Node {
    char val;
    struct _Node *prev;
    struct _Node *next;
} Node;

Node buf[11000000];
int bufCnt;
Node *head;
Node *last;

Node *myAlloc(char n) {
    buf[bufCnt].val = n;
    buf[bufCnt].prev = last;
    buf[bufCnt].next = NULL;
    return &buf[bufCnt++];
}

void addNode(char value) {
    if (head == NULL) {
        last = head = myAlloc(value);
    } else {
        last = last->next = myAlloc(value);
    }
}

int main(void) {
    char buf[110000];
    scanf("%s", buf);
    for (int i = 0; buf[i] != '\0'; i++) {
        addNode(buf[i]);
    }
    addNode('$');
    Node *cursor = last;
    int M;
    scanf("%d", &M);
    for (int m = 0; m < M; m++) {
        char cmd;
        scanf(" %c", &cmd);
        if (cmd == 'L') {
            if (cursor != head) {
                cursor = cursor->prev;
            }
        } else if (cmd == 'D') {
            if (cursor != last) {
                cursor = cursor->next;
            }
        } else if (cmd == 'B') {
            if (cursor != head) {
                if (cursor->prev != head) {
                    cursor->prev->prev->next = cursor;
                    cursor->prev = cursor->prev->prev;
                } else {
                    cursor->prev=head;
                    head = cursor;
                }
            }
        } else {
            char c;
            scanf(" %c", &c);
            Node *newNode = myAlloc(c);
          if(cursor==head){
              cursor->prev=newNode;
              newNode->next=cursor;
              head=newNode;
              head->prev=NULL;
          }
          else{
           newNode->next=cursor;
           newNode->prev=cursor->prev;
           cursor->prev->next=newNode;
           cursor->prev=newNode;
          }
        }
    }
    for (Node *p = head; p->val != '$'; p = p->next) {
        printf("%c", p->val);
    }
    printf("\n");

    return 0;
}