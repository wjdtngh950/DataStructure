

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char val;
    struct Node* next;
}Node;

Node* head, * last;

char dequeue() {
    if (head == NULL) {
        return '\0';
    }
    Node* tmp = head;
    char rtn = tmp->val;
    head = head->next;
    if (head == NULL) {
        last = NULL;
    }
    free(tmp);
    return rtn;
}

void enqueue(char v, int num) {
    if (head == NULL) {
        head = (Node*)malloc(sizeof(Node));
        head->val = v;
        head->next = NULL;
        last = head;
        return;
    }
    last->next = (Node*)malloc(sizeof(Node));
    last = last->next;
    last->val = v;
    last->next = NULL;
}

int main(void) {
    enqueue('A', 2);
    enqueue('V', 5);
    enqueue('Q', 7);
    enqueue('W', 8);
    enqueue('E', 4);
    for (Node* p = head; p != NULL; p = p->next) {
        printf("%c -> ", p->val);
    }
    printf("\n");
    printf("dequeue: %c\n", dequeue());
    for (Node* p = head; p != NULL; p = p->next) {
        printf("%c -> ", p->val);
    }
    printf("\n");
    return 0;
}