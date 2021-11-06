#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Node {
    char val;
    struct Node* prev;
    struct Node* next;
};

Node* head = NULL;
Node* last = NULL;
Node* cursor = NULL;

void addNode(char value) { //커서의 왼쪽에 삽처럼
    if (cursor == head) {
        //Node* newNode = (Node*)malloc(sizeof(Node));
        //head = newNode;
        // 19라인을 줄여서 씀
        head = new Node;
        head->val = value; // 새로 생성한 노드에 값을 넣어줌
        head->prev = NULL; // 새로 생성한…