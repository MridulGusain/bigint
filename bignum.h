// bignum.h

#ifndef BIGNUM_H
#define BIGNUM_H

typedef struct Node {
    int digit;
    struct Node* next;
} Node;

Node* stringToList(const char* str);
Node* add(Node* a, Node* b);
Node* subtract(Node* a, Node* b);
Node* multiply(Node* a, Node* b);
Node* divide(Node* a, Node* b);
Node* modulo(Node* a, Node* b);
int compare(Node* a, Node* b);
void printList(Node* head);
void freeList(Node* head);
int tryLongLong(const char* str, long long* out);

#endif
