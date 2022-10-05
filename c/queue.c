#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define QUEUE_EMPTY INT_MIN

typedef struct {
    int * values;
    int head, tail, size, entries;
} Queue;

Queue * createQueue(int size) {
    Queue * q = (Queue *) malloc(sizeof(Queue));
    
    q->size = size;
    q->values = (int*) malloc(sizeof(int) * q->size);
    q->head = q->tail = 0;
    q->entries = 0;
    
    return q;
}

bool queueEmpty(Queue * q) {
    return q->entries == 0;
}

bool queueFull(Queue * q) {
    return q->entries == q->size;
}

bool enqueue(Queue * q, int value) {
    if (queueFull(q)) {
        return false;
    }

    q->values[q->tail] = value;
    q->tail = (q->tail + 1) % q->size;
    q->entries++;
    
    return true;
}

int dequeue(Queue * q) {
    if (queueEmpty(q)) {
        return QUEUE_EMPTY;
    }

    int result = q->values[q->head];
    q->head = (q->head + 1) % q->size;
    q->entries--;

    return result;
}

void destroyQueue(Queue * q) {
    free(q->values);
    free(q);
}


void printQueue(Queue * q) {
    printf("----------------\n");
    printf("Queue->head: %d\n", q->head);
    printf("Queue->tail: %d\n", q->tail);
    printf("Queue->size: %d\n", q->size);
    printf("Queue->num_entries: %d\n", q->entries);
    printf("Queue->values: [ ");
    for (int i = 0; i < q->entries; i++) {
        printf("%d ", q->values[i]);
    }
    printf("]\n");
}

int main() {
    Queue * q1;

    q1 = createQueue(4);

    enqueue(q1, 76);
    enqueue(q1, 100);
    enqueue(q1, 12);
    enqueue(q1, 12);

    dequeue(q1);
    dequeue(q1);
    dequeue(q1);
    dequeue(q1);

    printQueue(q1);

    destroyQueue(q1);

    return 0;
}