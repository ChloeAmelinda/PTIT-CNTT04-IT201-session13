#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack {
    int top;
    int capacity;
    char *elements;
}Stack;
Stack createStack(int capacity) {
    Stack stack;
    stack.capacity = capacity;
    stack.top = -1;
    stack.elements = malloc(sizeof(int) * stack.capacity);
    if (stack.elements == NULL) {
        printf("error allocating memory\n");
        exit(1);
    }
    return stack;
}
void push(Stack *stack, char value) {
    if (stack->top == stack->capacity - 1) {
        printf("stack is full\n");
        return;
    }
    stack->top++;
    stack->elements[stack->top] = value;
}
char pop(Stack *stack) {
    if (stack->top == -1) {
        printf("stack is empty\n");
        return '\0';
    }
    char value = stack->elements[stack->top];
    stack->top--;
    return value;
}
bool IsPalindrome(char *str) {
    int len = strlen(str);
    Stack stack = createStack(len/2 +1);
    for (int i = 0; i < len/2; i++) {
        push(&stack, str[i]);
    }
    int start ;
    if (len %2 == 0) {
        start = len/2;
    }else {
        start = len/2+1;
    }
    for (int i = start; i< len ; i++) {
        char stackChar = pop(&stack);
        if (stackChar != str[i]) {
            return false;
        }
    }
    return true;
}
int main(void) {
    char *str = (char *)malloc(sizeof(char) * 100);
    if (str == NULL) {
        printf("error allocating memory\n");
        return 1;
    }
    printf("Enter string: ");
    fgets(str, 100, stdin);
    printf("Entered string: %s\n", str);
    if (IsPalindrome(str)) {
        printf("Is a palindrome\n");
    }else {
        printf("Is not a palindrome\n");
    }
    free(str);
    return 0;
}