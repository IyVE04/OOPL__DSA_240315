#include <stdio.h>

#define MAX 100

// Structure for each element
struct item {
    int value;
    int priority;
};

struct item pq[MAX];
int size = 0;

// Function to insert element
void insert(int value, int priority) {
    pq[size].value = value;
    pq[size].priority = priority;
    size++;
}

// Function to delete element with highest priority
int deleteHighest() {
    if (size == 0) {
        printf("Priority Queue is EMPTY\n");
        return -1;
    }

    int highest = 0;

    // Find index of highest priority element
    for (int i = 1; i < size; i++) {
        if (pq[i].priority > pq[highest].priority) {
            highest = i;
        }
    }

    int deletedValue = pq[highest].value;

    // Replace with last element
    pq[highest] = pq[size - 1];
    size--;

    return deletedValue;
}

// Function to display the priority queue contents
void display() {
    if (size == 0) {
        printf("Priority Queue is EMPTY\n");
        return;
    }

    printf("Value\tPriority\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%d\n", pq[i].value, pq[i].priority);
    }
}

int main() {
    insert(10, 2);
    insert(20, 5);
    insert(30, 1);
    insert(40, 4);

    printf("Priority Queue:\n");
    display();

    printf("\nDeleted highest priority element: %d\n", deleteHighest());

    printf("\nPriority Queue after deletion:\n");
    display();

    return 0;
}