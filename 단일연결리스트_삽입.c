
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int data; // 값 저장
    struct _Node* link; // 메모리 주소 저장
}Node;

Node* head = NULL;
Node* tail = NULL;

void addNode(int val) { // 연결 리스트의 맨 뒤에 데이터를 삽입
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->link = NULL;
    if (head == NULL) { // 연결리스트가 비어있는 경우
        head = newNode;
    }
    else { // 연결리스트가 비어있지 않은 경우
        tail->link = newNode;
    }
    tail = newNode;
}

int main(void) {
    addNode(10);
    addNode(9);
    addNode(8);
    addNode(7);
    addNode(6);
    addNode(5);
    addNode(2);

    for (Node* p = head; p != NULL; p = p->link) {
        printf("%d -> ", p->data);
    }
    printf("\n");

    // 값이 7인 노드 삭제
    int target = 7;
    Node* pre = NULL;
    Node* cur;
    for (cur = head; cur != NULL; cur = cur->link) {
        if (cur->data == target) {
            break;
        }
        pre = cur;
    }
    if (pre != NULL && cur != NULL) { // 찾은 경우
        pre->link = cur->link;
        if (cur == tail) {
            tail = pre;
        }
        free(cur);
    }

    for (Node* p = head; p != NULL; p = p->link) {
        printf("%d -> ", p->data);
    }
    printf("\n");

    // 6 앞에 15 삽입
    target = 10;
    pre = NULL;
    cur;
    for (cur = head; cur != NULL; cur = cur->link) {
        if (cur->data == target) {
            break;
        }
        pre = cur;
    }
    if (cur != NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = 15;
        newNode->link = cur;
        if (pre == NULL) {
            head = newNode;
        }
        else if (pre != NULL && cur != NULL) {
            pre->link = newNode;
        }
    }

    for (Node* p = head; p != NULL; p = p->link) {
        printf("%d -> ", p->data);
    }
    printf("\n");

    return 0;
}