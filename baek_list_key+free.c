#include<stdio.h>
#include<stdlib.h>

typedef struct _Node {
    char val;
    struct _Node* prev;
    struct _Node* next;
}Node;

Node* head;
Node* last;
Node* cursor;

void addNode(char value) {
    if (cursor == head) {
        head = (Node*)malloc(sizeof(Node));
        head->val = value;
        head->prev = NULL;
        head->next = cursor;
        cursor->prev = head;
    }
    else {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->val = value;
        newNode->prev = cursor->prev;
        newNode->next = cursor;
        cursor->prev->next = newNode;
        cursor->prev = newNode;
    }
}

int main() {
    int M;
    scanf("%d", &M);

    for (int m = 0; m < M; m++) {
        char buf[1000001];
        scanf("%s", buf);
        cursor = (Node*)malloc(sizeof(Node));
        cursor->val = '$';
        cursor->prev = NULL;
        cursor->next = NULL;
        last = head = cursor;
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
                if (cursor != head) {
                    if (cursor->prev == head) {
                        cursor->prev = NULL;
                        free(head);
                        head = cursor;
                    }
                    else {
                        cursor->prev->prev->next = cursor;
                        cursor->prev = cursor->prev->prev;
                    }
                }
            }
            else {
                addNode(buf[i]);
            }
        }
        for (Node* p = head; p->val != '$'; p = p->next) {
            printf("%c", p->val);
        }
        printf("\n");
        Node* p = head;
        while (p->val != '$') {
            Node* next = p->next;
            free(p);
            p = next;
        }
    }
    return 0;
}