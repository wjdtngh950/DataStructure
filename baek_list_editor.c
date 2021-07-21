#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    char val;
    struct _Node* prev;
    struct _Node* next;
} Node;

Node* head;
Node* last;
Node* cursor;

void addNode(char value) { //뒤에 삽입해줌
    if (head == NULL) {
        last = head = (Node*)malloc(sizeof(Node));
        head->val = value;
        head->prev = NULL;
        head->next = NULL;
    }
    else {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->val = value;
        newNode->prev = last;
        newNode->next = NULL;
        last = last->next = newNode;
    }
}

int main(void) {
    char buf[110000];
    scanf("%s", buf);
    for (int i = 0; buf[i] != '\0'; i++) {
        addNode(buf[i]);
    }
    addNode('$');
    cursor = last;
    int M;
    scanf("%d", &M);
    for (int m = 0; m < M; m++) {
        char cmd;
        scanf(" %c", &cmd);
        if (cmd == 'L') {
            if (cursor != head) {
                cursor = cursor->prev;
            }
        }
        else if (cmd == 'D') {
            if (cursor != last) {
                cursor = cursor->next;
            }
        }
        else if (cmd == 'B') {
            if (cursor != head) {
                if (cursor->prev != head) {
                    cursor->prev->prev->next = cursor;
                    cursor->prev=cursor->prev->prev;
                }
                else {
                    cursor->prev = head;
                    head = cursor;
                }
            }
        }
        else {
            char c;
            scanf(" %c", &c);
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->val = c;
            newNode->prev = cursor->prev;
            newNode->next = cursor;
            if (cursor == head) {
                head = newNode;
            }
            else {
                cursor->prev->next = newNode;
            }
            cursor->prev = newNode;
        }
    }
    for (Node* p = head; p->val != '$'; p = p->next) {
        printf("%c", p->val);
    }
    printf("\n");

    return 0;
}