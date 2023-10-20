// main.c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "big_number_operations.h"
struct Node* inputBigNumber() {
    struct Node* num = NULL;
    char ch;

    printf("Enter a big number (terminate with Enter or a non-digit character):\n");

    while (1) {
        ch = getchar();
        if (ch == '\n' || !isdigit(ch)) {
            break;
        }

        int digit = ch - '0';
        struct Node* newNode = createNode(digit);

        if (num == NULL) {
            num = newNode;
        } else {
            newNode->next = num;
            num = newNode;
        }
    }

    return num;
}


int main() {
    struct Node* num1 = inputBigNumber();
    struct Node* num2 = inputBigNumber();

    struct Node* sum = addBigNumbers(num1, num2);
    struct Node* difference = subtractBigNumbers(num1, num2);
    struct Node* product = multiplyBigNumbers(num1, num2);
    struct Node* division = divideBigNumbers(num1, num2);

    printf("Number 1: ");
    printBigNumber(num1);
    printf("Number 2: ");
    printBigNumber(num2);
    printf("Sum: ");
    printBigNumber(sum);
    printf("Difference: ");
    printBigNumber(difference);
    printf("Product: ");
    printBigNumber(product);
    printf("Division: ");
    printBigNumber(division);

    free(num1);
    free(num2);
    free(sum);
    free(difference);
    free(product);
    free(division);

    return 0;
}
