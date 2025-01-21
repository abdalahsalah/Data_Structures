#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];
    int front, rear;
} Queue;

void init(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}


int is_full(Queue *queue) {
    return queue->rear == MAX_SIZE - 1;
}

void enqueue(Queue *queue, int item) {
    if (is_full(queue)) {
        printf("Queue Overflow\n");
        return;
    }
    if (is_empty(queue)) {
        queue->front = 0;
    }
    queue->arr[++queue->rear] = item;
}

int dequeue(Queue *queue) {
    if (is_empty(queue)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int item = queue->arr[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front++;
    }
    return item;
}

int front(Queue *queue) {
    if (is_empty(queue)) {
        printf("Queue is Empty\n");
        return -1;
    }
    return queue->arr[queue->front];
}

int size(Queue *queue) {
    if (is_empty(queue)) {
        return 0;
    }
    return queue->rear - queue->front + 1;
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