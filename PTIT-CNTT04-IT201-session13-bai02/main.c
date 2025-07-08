#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int top;
    int capacity;
    int *arr;
}Stack;
Stack createStack(int capacity) {
    Stack stack;
    stack.capacity = capacity;
    stack.top = -1;

    stack.arr = (int *)malloc(stack.capacity * sizeof(int));
    if (stack.arr == NULL) {
        printf("error allocating memory\n");
        exit(1);

    }
    return stack;

}
void push(Stack *stack, int value) {
    if (stack->top == stack->capacity - 1) {
        printf("stack is full\n");
        return;
    }
    stack->top++;
    stack->arr[stack->top] = value;
    printf("stack top = %d\n", stack->top);
}
int main(void) {
    Stack stack = createStack(5);
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    push(&stack, number);
    int arrr [] = {1, 2, 3, 4};
    for (int i = 0; i < 4; i++) {
            push(&stack , arrr[i]);
    }
    printf("Stack top = %d\n", stack.top);
    printf("Stack cap = %d\n", stack.capacity);
    printf("element stack:");
    for (int i = 0; i <= stack.top; i++) {
        printf("%d ", stack.arr[i]);
    }
    printf("\n");
    free(stack.arr);

    return 0;
}