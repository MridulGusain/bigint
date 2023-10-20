#ifndef BIG_NUMBER_OPERATIONS_H
#define BIG_NUMBER_OPERATIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data);
struct Node* reverseLinkedList(struct Node* head);
struct Node* addBigNumbers(struct Node* num1, struct Node* num2);
struct Node* subtractBigNumbers(struct Node* num1, struct Node* num2);
struct Node* multiplyBigNumbers(struct Node* num1, struct Node* num2);
struct Node* divideBigNumbers(struct Node* num1, struct Node* num2);
int isGreaterOrEqual(struct Node* num1, struct Node* num2);
void printBigNumber(struct Node* num);
struct Node* inputBigNumber();

#endif
