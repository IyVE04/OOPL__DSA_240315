#include <stdio.h>

#define CAPACITY 5

typedef struct {
    int arr[CAPACITY];
    int front;
    int rear;
    int size;
} CircularQueue;

void initQueue(CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
    q->size = 0;
}

int isFull(CircularQueue *q) { return q->size == CAPACITY; }
int isEmpty(CircularQueue *q) { return q->size == 0; }

void enqueue(CircularQueue *q, int x) {
    if (isFull(q)) {
        printf("Queue Full\n");
        return;
    }
    q->rear = (q->rear + 1) % CAPACITY;
    q->arr[q->rear] = x;
    if (q->front == -1) q->front = q->rear;
    q->size++;
}

int dequeue(CircularQueue *q) {
    int val;
    if (isEmpty(q)) {
        printf("Queue Empty\n");
        return -1;
    }
    val = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % CAPACITY;
    }
    q->size--;
    return val;
}

int getFront(CircularQueue *q) {
    return isEmpty(q) ? -1 : q->arr[q->front];
}

int main() {
    CircularQueue q;
    initQueue(&q);
    
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    
    printf("%d %d\n", dequeue(&q), getFront(&q));
    return 0;
}