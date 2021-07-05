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

void addNode(int value) {
    if (head == NULL) {
        last = head = myAlloc(value);
    } else {
        last = last->next = myAlloc(value);
    }
}

void printList(){
        for (Node* cursor = head; cursor != NULL; cursor = cursor->next) {
            printf("%c", cursor->val);
        }
        printf("\n");
    }

int main(void) {
    // 초기 입력 문자열들을 리스트에 삽입
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
            cursor->prev->prev->next = cursor;
            cursor->prev = cursor->prev->prev;
        } else {
            char c;
            scanf(" %c", &c);

        }
    }
    printList();
    return 0;
}