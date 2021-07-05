#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct _Node {
    int data;
    struct _Node* prev;
    struct _Node* next;
}Node;

Node* head = NULL;
Node* tail = NULL;

void addNode(int val) { // 연결 리스트의 맨 뒤에 데이터를 삽입
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;
    if (head == NULL) { // 연결리스트가 비어있는 경우
        head = newNode;
    }
    else { // 연결리스트가 비어있지 않은 경우
        tail->next = newNode;
        newNode->prev = tail;
    }
    tail = newNode;
}

int insertNode(int target, int value) {
    Node* cur;
    for (cur = head; cur != NULL; cur = cur->next) {
        if (cur->data == target) {
            break;
        }
    }
    if (cur != NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = value;
        newNode->next = cur;
        newNode->prev = cur->prev;
        if (head == cur) {
            head = newNode;
        }
        else {
            cur->prev->next = newNode;
        }
        cur->prev = newNode;
        return TRUE;
    }
    return FALSE;
}

int deleteNode(int target) {
    Node* cur;
    for (cur = head; cur != NULL; cur = cur->next) {
        if (cur->data == target) {
            break;
        }
    }
    if (cur != NULL) { // 탐색 성공
        if (cur != head) {
            cur->prev->next = cur->next;
        }
        else { // 삭제할 노드가 head 노드
            head = cur->next;
        }
        if (cur != tail) {
            cur->next->prev = cur->prev;
        }
        else {
            tail = cur->prev;
        }
        free(cur);
        return TRUE;
    }
    return FALSE;
}

void printList() {
    for (Node* p = head; p != NULL; p = p->next) {
        printf("%d -> ", p->data);
    }
    printf("\n");
}

void printListRev() {
    for (Node* p = tail; p != NULL; p = p->prev) {
        printf("%d -> ", p->data);
    }
    printf("\n");
}

int main(void) {
    addNode(10);
    addNode(9);
    addNode(8);
    addNode(7);
    addNode(6);
    addNode(5);
    addNode(2);

    printList();

    // 값이 7인 노드 삭제
    if (deleteNode(7) == TRUE) {
        printf("삭제 성공\n");
    }
    else {
        printf("삭제 실패\n");
    }
    printList();

    // 6 앞에 15 삽입
    if (insertNode(6, 15) == TRUE) {
        printf("삽입 성공\n");
    }
    else {
        printf("삽입 실패\n");
    }
    printList();

    // 6 앞에 15 삽입
    if (insertNode(10, 100) == TRUE) {
        printf("삽입 성공\n");
    }
    else {
        printf("삽입 실패\n");
    }
    printList();

    // 6 앞에 15 삽입
    if (insertNode(2, 999) == TRUE) {
        printf("삽입 성공\n");
    }
    else {
        printf("삽입 실패\n");
    }
    printList();

    return 0;
}