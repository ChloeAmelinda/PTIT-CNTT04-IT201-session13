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
    stack.elements = malloc(sizeof(int) * capacity);
    stack.top = -1;
    stack.elements = (int *)malloc(sizeof(int) * capacity);
    if (stack.elements == NULL) {
        printf("error allocating memory\n");

        exit(1);
    }

    return stack;

}
void printStack(Stack *stack) {
    if (stack->top == -1) {
        printf("stack is empty\n");
        return;
    }
    for (int i = stack->top; i >= 0; i--) {
        printf("%d \n", stack->elements[i]);

    }
    printf("\n");
}
int main(void) {
    Stack stack = createStack(5);
    int arr[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        stack.top++;
        stack.elements[stack.top] = arr[i];
    }
    printStack(&stack);
    return 0;
}