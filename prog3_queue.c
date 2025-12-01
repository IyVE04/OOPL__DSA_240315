#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;
void enqueue(int x) {
    if (rear == MAX - 1) {
        printf("Queue is Full\n");
    } else {
        if (front == -1) front = 0; 
        rear++;
        queue[rear] = x;
        printf("Inserted %d\n", x);
    }
}
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty\n");
    } else {
        printf("Deleted %d\n", queue[front]);
        front++;
    }
}
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
dequeue();
    display();
    enqueue(40);
    enqueue(50);
    enqueue(60); 
    display();
    return 0;
}