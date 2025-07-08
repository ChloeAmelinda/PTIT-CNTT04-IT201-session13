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
int main(void) {
    Stack stack = createStack(5);
    printf("Max : %d\n", stack.capacity);
    printf("phan tu tren cung : %d\n",stack.top);

    return 0;
}