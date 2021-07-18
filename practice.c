#include<stdio.h>

typedef struct _Node {
    char val;
    struct _Node *prev;
    struct _Node *next;
} Node;

Node buf[1100000];
int bufCnt;
Node *head = NULL;
Node *last = NULL;

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
    char buf[100000];
    scanf("%s", buf);
    for (int i = 0; buf[i] != '\0'; i++) {
        addNode(buf[i]);
    }
    int M;
    scanf("%d", &M);
    addNode('$');
    Node *cursor = last;
    for (int m = 1; m <= M; m++) {
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
                    cursor->prev = NULL;
                    head = cursor;
                }
            }
        } else {
            char c;
            scanf(" %c", &c);
            Node *newNode = myAlloc(c);
            if (cursor == head) {
                cursor->prev = newNode;
                newNode->next = cursor;
                head = newNode;
            } else {
                newNode->prev = cursor->prev;
                cursor->prev->next = newNode;
                newNode->next = cursor;
                cursor->prev = newNode;
            }
        }
    }
    for (Node *p = head; p->val != '$'; p = p->next) {
        printf("%c", p->val);
    }
    return 0;
}