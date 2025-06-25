#include <stdio.h>
#include "bignum.h"

int main() {
    char num1[51], num2[51];
    char op;
    Node *list1, *list2, *result = NULL;

    printf("Enter first number: ");
    scanf("%50s", num1);

    printf("Enter second number: ");
    scanf("%50s", num2);

    printf("Enter operation (+, -, *, /, %%): ");
    scanf(" %c", &op);  // note space before %c to skip whitespace

    list1 = stringToList(num1);
    list2 = stringToList(num2);

    switch (op) {
        case '+':
            result = add(list1, list2);
            break;
        case '-':
            // For subtract, you may want to check which is bigger and subtract accordingly
            if (compare(list1, list2) >= 0) {
                result = subtract(list1, list2);
            } else {
                printf("Negative result not supported or handle accordingly.\n");
                // or result = subtract(list2, list1); and indicate negative
            }
            break;
        case '*':
            result = multiply(list1, list2);
            break;
        case '/':
            result = divide(list1, list2);
            break;
        case '%':
            result = modulo(list1, list2);
            break;
        default:
            printf("Invalid operation!\n");
            break;
    }

    if (result) {
        printf("Result: ");
        printList(result);
        freeList(result);
    }

    freeList(list1);
    freeList(list2);

    return 0;
}
