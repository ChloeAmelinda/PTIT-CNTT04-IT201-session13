#include <stdio.h>
#include <stdlib.h>
typedef struct Stack {
    int top;
    int capacity;
    int *elements;
}Stack;
Stack createStack(int capacity) {
    Stack stack;
    stack.capacity = capacity;
    stack.top = -1;
    stack.elements= (int *)malloc(stack.capacity * sizeof(int));
    if (stack.elements == NULL) {
        printf("error allocating memory\n");
        exit(1);
    }
    return stack;
}
int pop(Stack *stack) {
    if (stack->top == -1) {
        printf("stack is empty\n");
        return -1;
    }
    int val = stack->elements[stack->top];
    stack->top--;
    return val;
}
int main(void) {
    Stack stack = createStack(5);
    int array[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        stack.top++;
        stack.elements[stack.top] = array[i];

    }
    printf("top : %d\n" , pop(&stack));

    return 0;
}