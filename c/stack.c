#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int top;
    unsigned capacity;
    int * array;
} Stack;

Stack * createStack(unsigned capacity) {
    Stack * stack = (Stack *) malloc(sizeof(Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int *) malloc(capacity * sizeof(int));
}

int isEmpty(Stack * stack) {
    return stack->top == -1;
}

int isFull(Stack * stack) {
    return stack->top == stack->capacity - 1;
}

void push(Stack * stack, int value) {
    if (isFull(stack)) {
        printf("The stack is full.\n");
        return;
    } stack->array[++stack->top] = value;
}

int pop(Stack * stack) {
    if (isEmpty(stack)) {
        printf("The stack is empty.\n");
        return 0;
    } stack->top--;
    return stack->top+1;
}

void printStack(Stack * stack) {
    printf("--------------\n");
    printf("Stack->top: %d\n", stack->top);
    printf("Stack->array: [ ");
    for (int i = 0; i <= stack->top; i++) {
        printf((i < stack->top) ? "%d, ": "%d ", stack->array[i]);
    }
    printf("]\n");
}

void main() {
    Stack * s1;
    s1 = createStack(4);
    push(s1, 2);
    push(s1, 3);
    push(s1, 0);
    push(s1, 5);

    printStack(s1);
}