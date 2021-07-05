//
// Created by 정수호 on 05/07/2021.
//

#include <stdio.h>

typedef struct _Node {
    int val;
    struct _Node* next;
}Node;

Node buf[11000000];
int bufCnt;
Node* head;
Node* last;

Node* myAlloc(int n, Node* next) {
    buf[bufCnt].val = n;
    buf[bufCnt].next = next;
    return &buf[bufCnt++];
}

void addNode(int value) {
    if (head == NULL) {
        last = head = myAlloc(value, NULL);
    }
    else {
        last = last->next = myAlloc(value, NULL);
    }
}

int main(void) {
    addNode(1);
    addNode(2);
    addNode(3);
    addNode(4);
    addNode(5);

    for (Node* p = head; p != NULL; p = p->next) {
        printf("%d -> ", p->val);
    }
    return 0;
}