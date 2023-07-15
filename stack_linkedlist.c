#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

void init(Stack *stack) {
    stack->top = NULL;
}

int is_empty(Stack *stack) {
    return stack->top == NULL;
}

void push(Stack *stack, int item) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = item;
    new_node->next = stack->top;
    stack->top = new_node;
}

int pop(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    Node *temp = stack->top;
    int item = temp->data;
    stack->top = temp->next;
    free(temp);
    return item;
}

int top(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack is Empty\n");
        return -1;
    }
    return stack->top->data;
}

int size(Stack *stack) {
    int count = 0;
    Node *current = stack->top;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int main() {
    Stack stack;
    init(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    printf("%d\n", top(&stack));   // Output: 3

    pop(&stack);
    pop(&stack);

    printf("%d\n", size(&stack));  // Output: 1

    return 0;
}