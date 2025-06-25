// bignum.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bignum.h"

Node* createNode(int digit) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->digit = digit;
    node->next = NULL;
    return node;
}

void append(Node** head, int digit) {
    Node* node = createNode(digit);
    if (!*head) *head = node;
    else {
        Node* temp = *head;
        while (temp->next) temp = temp->next;
        temp->next = node;
    }
}

// Reverse linked list
Node* reverse(Node* head) {
    Node* prev = NULL, *curr = head, *next;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Convert string to reversed list (least significant digit first)
Node* stringToList(const char* str) {
    Node* head = NULL;
    int len = strlen(str);
    for (int i = len - 1; i >= 0; i--)
        append(&head, str[i] - '0');
    return head;
}

// Compare two lists (digits normal order, so reverse to compare)
int compare(Node* a, Node* b) {
    a = reverse(a);
    b = reverse(b);

    int lenA = 0, lenB = 0;
    Node *p = a, *q = b;
    while (p) { lenA++; p = p->next; }
    while (q) { lenB++; q = q->next; }

    if (lenA != lenB) {
        freeList(a);
        freeList(b);
        return lenA > lenB ? 1 : -1;
    }

    while (a && b) {
        if (a->digit != b->digit) {
            int res = (a->digit > b->digit) ? 1 : -1;
            freeList(a);
            freeList(b);
            return res;
        }
        a = a->next;
        b = b->next;
    }

    freeList(a);
    freeList(b);
    return 0;
}

Node* add(Node* a, Node* b) {
    // a, b are reversed lists
    Node* result = NULL;
    int carry = 0;
    while (a || b || carry) {
        int sum = carry;
        if (a) { sum += a->digit; a = a->next; }
        if (b) { sum += b->digit; b = b->next; }
        append(&result, sum % 10);
        carry = sum / 10;
    }
    return result;
}

Node* subtract(Node* a, Node* b) {
    // a >= b, reversed lists
    Node* result = NULL;
    int borrow = 0;
    while (a) {
        int sub = a->digit - borrow - (b ? b->digit : 0);
        if (sub < 0) {
            sub += 10;
            borrow = 1;
        } else borrow = 0;
        append(&result, sub);
        a = a->next;
        if (b) b = b->next;
    }
    // Remove trailing zeros
    while (result && result->digit == 0 && result->next) {
        Node* temp = result;
        result = result->next;
        free(temp);
    }
    return result;
}

// Multiply helper: multiply list by single digit and shift (add zeros)
Node* multiplyByDigit(Node* head, int digit, int shift) {
    Node* result = NULL;
    for (int i = 0; i < shift; i++)
        append(&result, 0);

    int carry = 0;
    for (Node* cur = head; cur != NULL; cur = cur->next) {
        int prod = cur->digit * digit + carry;
        append(&result, prod % 10);
        carry = prod / 10;
    }
    if (carry > 0)
        append(&result, carry);
    return result;
}

// Add two reversed lists
Node* addLists(Node* a, Node* b) {
    Node* result = NULL;
    int carry = 0;
    while (a || b || carry) {
        int sum = carry;
        if (a) { sum += a->digit; a = a->next; }
        if (b) { sum += b->digit; b = b->next; }
        append(&result, sum % 10);
        carry = sum / 10;
    }
    return result;
}

// Multiply two reversed lists
Node* multiply(Node* a, Node* b) {
    Node* result = NULL;
    int shift = 0;

    for (Node* cur = b; cur != NULL; cur = cur->next) {
        Node* partial = multiplyByDigit(a, cur->digit, shift);
        Node* newResult = addLists(result, partial);
        freeList(result);
        freeList(partial);
        result = newResult;
        shift++;
    }
    return result;
}

// Division (placeholder)
Node* divide(Node* dividend, Node* divisor) {
    printf("Division is not implemented yet.\n");
    return NULL;
}

// Modulo (placeholder)
Node* modulo(Node* dividend, Node* divisor) {
    printf("Modulo is not implemented yet.\n");
    return NULL;
}

// Print number (reverse list to print MSD first)
void printList(Node* head) {
    head = reverse(head);
    while (head) {
        printf("%d", head->digit);
        head = head->next;
    }
    printf("\n");
}

// Free list memory
void freeList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

// Try to convert string to long long, return success flag
int tryLongLong(const char* str, long long* out) {
    if (strlen(str) > 18) return 0;
    *out = atoll(str);
    return 1;
}
