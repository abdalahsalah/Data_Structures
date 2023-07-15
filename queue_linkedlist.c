#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} Queue;

void init(Queue *queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

int is_empty(Queue *queue) {
    return queue->front == NULL;
}

void enqueue(Queue *queue, int item) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = item;
    new_node->next = NULL;
    if (is_empty(queue)) {
        queue->front = new_node;
        queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
}

int dequeue(Queue *queue) {
    if (is_empty(queue)) {
        printf("Queue Underflow\n");
        return -1;
    }
    Node *temp = queue->front;
    int item = temp->data;
    queue->front = temp->next;
    free(temp);
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    return item;
}

int front(Queue *queue) {
    if (is_empty(queue)) {
        printf("Queue is Empty\n");
        return -1;
    }
    return queue->front->data;
}

int size(Queue *queue) {
    int count = 0;
    Node *current = queue->front;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int main() {
    Queue queue;
    init(&queue);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);

    printf("%d\n", front(&queue));   // Output: 1

    dequeue(&queue);
    dequeue(&queue);

    printf("%d\n", size(&queue));    // Output: 1

    return 0;
}