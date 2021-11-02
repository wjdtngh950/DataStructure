#include <stdio.h>
#include <stdlib.h>

int N;

typedef struct _Node {
    char val;
    struct _Node *prev;
    struct _Node *next;
} Node;

Node *last;
Node *cursor;
Node *head;

void addNode(char value) {
    if (head == cursor) {
        head = (Node *) malloc(sizeof(Node));
        head->val = value;
        head->prev = NULL;
        head->next = cursor;
        cursor->prev = head;
    } else {
        Node *newNode = (Node *) malloc(sizeof(Node));
        newNode->val = value;
        newNode->prev = cursor->prev;
        newNode->next = cursor;
        cursor->prev = newNode;
        cursor->prev->prev->next = newNode;
    }
}

int main() {
    scanf("%d", &N);
    for (int n = 0; n < N; n++) {
        char buf[1100000];
        scanf("%s", buf);
        cursor = (Node *) malloc(sizeof(Node));
        cursor->val = '$';
        cursor->prev = NULL;
        cursor->next = NULL;
        head=last = cursor;
        for (int i = 0; buf[i] != '\0'; i++) {
            if (buf[i] == '<') {
                if (cursor != head) {
                    cursor = cursor->prev;
                }
            } else if (buf[i] == '>') {
                if (cursor != last) {
                    cursor = cursor->next;
                }
            } else if (buf[i] == '-') {
                if (cursor != head) {
                    if (cursor->prev == head) {
                        head = cursor;
                        cursor->prev = NULL;
                    } else {
                        cursor->prev->prev->next = cursor;
                        cursor->prev=cursor->prev->prev;
                    }
                }
            }
            else{
                addNode(buf[i]);
            }
        }
        for(Node*p=head;p->val!='$';p=p->next){
            printf("%c", p->val);
        }
        printf("\n");
    }
    return 0;
}
