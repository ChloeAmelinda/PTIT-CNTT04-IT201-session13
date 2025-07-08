#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int top;
    int capacity;
    int *elements;
}Stack;
Stack createStack(int capacity) {
    Stack stack;
    stack.top = -1;
    stack.capacity = capacity;
    stack.elements = malloc(sizeof(int) * stack.capacity);
    if (stack.elements == NULL) {
        printf("error allocating memory\n");
        exit(1);

    }
    return stack;

}

void push (Stack *stack, int element) {
    if (stack->top == stack->capacity - 1) {
        printf("stack is full\n");
        return ;
    }
    stack->top++;
    stack->elements[stack->top] = element;


}
int pop (Stack *stack) {
    if (stack->top == -1) {
        printf("stack is empty\n");
        return -1;
    }
    int value = stack->elements[stack->top];
    stack->top--;
    return value;
}
void printStack(Stack stack) {
    if (stack.top == -1) {
        printf("stack is empty\n");
        return;
    }
    for (int i = stack.top; i >= 0; i--) {
        printf("%d\t, ", stack.elements[i]);

    }
}
void reverse(int array[] , int n) {
    Stack newStack = createStack(n);
    for (int i = 0; i < n; i++) {
        push(&newStack, array[i]);
    }
    for (int i = 0; i < n; i++) {
        array[i] = newStack.elements[i];
    }

}
int main(void) {
    int n = 0;
    while (n<=0) {
        printf("Please enter the number of elements: ");
        scanf("%d", &n);
        if (n<=0) {
            printf("Please enter a number that less than zero\n");
        }
        int *arr = (int *)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++) {
            printf("arr[%d] = ", i+1);
            scanf("%d", &arr[i]);
        }
        printf("array :\n");
        for (int i = 0; i < n; i++) {
            printf("arr[%d] = %d\n", i+1, arr[i]);
        }
        //reverse(arr, n);
        printf("reversed array:\n");
        for (int i = n-1; i >= 0; i--) {
            printf("arr[%d] = %d\n", i+1, arr[i]);
        }
    }
    return 0;
}