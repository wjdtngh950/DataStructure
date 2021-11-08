#include<iostream>
#include<stdio.h>

using namespace std;

struct Node {
    char val;
    Node *prev;
    Node *next;
};

Node *head;
Node *last;
Node *cursor;

void addNode(char value) {
    if (head == cursor) {
        head = new Node;
        head->val = value;
        head->prev = NULL;
        head->next = cursor;
        cursor->prev = head;
    } else {
        Node *newNode = new Node;
        newNode->val = value;
        newNode->prev = cursor->prev;
        newNode->next = cursor;
        cursor->prev->next = newNode;
        cursor->prev = newNode;
    }
}

int main() {
    int N;
    cin >> N;
    for (int n = 0; n < N; n++) {
        char buf[1100000];
        cin >> buf;
        cursor = new Node;
        cursor->val = '$';
        cursor->prev = NULL;
        cursor->next = NULL;
        head = last = cursor;
        for (int i = 0; i < buf[i] != '\0'; i++) {
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
                    if (cursor->prev != head) {
                        cursor->prev->prev->next = cursor;
                        cursor->prev = cursor->prev->prev;
                    } else {
                        head = cursor;
                        cursor->prev = NULL;
                    }
                }
            }
            else {
                addNode(buf[i]);
            }
        }
        for (Node *p = head; p->val != '$'; p = p->next) {
            printf("%c", p->val);
        }
        printf("\n");
    }
    return 0;
}