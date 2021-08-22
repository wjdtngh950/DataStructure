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

void addNode(char value) { //커서의 왼쪽에 삽처럼
    if (cursor == head) {
        head = (Node*)malloc(sizeof(Node)); //last는 왜 동적할당 안하는지 ?? 8/22
        head->val = value;
        head->prev = NULL;
        head->next = cursor; //왜지?? head->prev는 NULL인데?? //왼쪽에 삽입해주는거라?? 8/22
        cursor->prev = head; //이것도...? 8/22
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
        head = last = cursor; // 비어있는 연결리스트에 노드 삽입 //46~49 한번밖에안쓰이는거라 굳이 에드노드말고 한번만넣어준거
        //last =head=cursor 처럼 순서 바뀌어도 되나?
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
                    if (cursor->prev->prev == NULL) { // 삭제할 노드가 헤드 //cursor->prev==head
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
            /*else if(buf[i]=='-'){   //이렇게도 쓸 수 있음! '-'
                if(cursor!=head){
                    if(cursor->prev!=head){
                        cursor->prev->prev->next=cursor;
                        cursor->prev=cursor->prev->prev;
                    }
                    else{
                        head=cursor;
                        cursor->prev=NULL;
                    }
                }
            }*/
            else {
                addNode(buf[i]);
            }
        }
        printList();
    }

    return 0;
}