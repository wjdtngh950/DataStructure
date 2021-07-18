#include<stdio.h>

typedef struct _Node {
    char val;
    struct _Node* prev;
    struct _Node* next;
} Node;

Node buf[11000000];
int bufCnt;
Node* head = NULL;
Node* last = NULL;
Node* cursor = NULL; // ??

Node* myAlloc(char n) { //이 부분이 뭔지 모르겠음
    buf[bufCnt].val = n;
    buf[bufCnt].prev = NULL;
    buf[bufCnt].next = cursor;
    return &buf[bufCnt++];
}

void addNode(char value) {
    if (cursor == head) {
        head = myAlloc(value);
        cursor->prev = head;
    }
    else {
        Node* newNode = myAlloc(value);
        newNode->prev = cursor->prev;
        cursor->prev->next = newNode;
        cursor->prev = newNode;
    }
}

void printList() {
    for (Node* p = head; p->val != '$'; p = p->next) {
        printf("%c", p->val);
    }
    printf("\n");
}

int main(void) {
    int M;
    scanf("%d", &M);
    for (int m = 0; m < M; m++) {
        char buf[1000000];
        scanf("%s", buf);
        cursor = myAlloc('$');
        head = last = cursor;
        for (int i = 0; buf[i] != '\0'; i++) {
            if (buf[i] == '<') {
                if (cursor != head) {
                    cursor = cursor->prev;
                }
            }
            else if (buf[i] == '>') {
                if (cursor != last) {
                    cursor = cursor->next;
                }
            }
            else if (buf[i] == '-') {
                if (cursor->prev != NULL) {
                    if (cursor->prev->prev == NULL) { // 삭제할 노드가 헤드
                        head = cursor;
                    }
                    else {
                        cursor->prev->prev->next = cursor;
                    }
                    cursor->prev = cursor->prev->prev;
                }
            }
            else {
                addNode(buf[i]);
            }
        }
        printList();
    }

    return 0;
}