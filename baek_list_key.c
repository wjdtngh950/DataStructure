#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    char val;
    struct _Node* prev;
    struct _Node* next;
} Node;

Node* head = NULL;
Node* last = NULL;
Node* cursor = NULL;

void addNode(char value) { //커서의 왼쪽에 삽
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
        cursor = (Node*)malloc(sizeof(Node));
        cursor->val = '$';
        cursor->prev = NULL;
        cursor->next = NULL; // 새로운 노드 '$' 생성 & 초기화
        head = last = cursor; // 비어있는 연결리스트에 노드 삽입
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
                if (cursor!=head) { // 삭제할 수 있는 노드가 있는지 확인
                    if (cursor->prev->prev == NULL) { // 삭제할 노드가 헤드
                        head = cursor;
                    }
                    else {
                        cursor->prev->prev->next = cursor;
                    }
                    cursor->prev = cursor->prev->prev;
                    // 삭제할 노드가 헤드 노드인 경우에도
                    // 삭제 이후 cursor가 가리키는 노드의
                    // prev 링크를 NULL 값으로 설정해줘야 하기 때문에
                    // if / else 구문 모두 적용해야 하는 코드(69 Line)
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