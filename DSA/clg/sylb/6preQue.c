#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int heap[MAX_SIZE];
    int size;
} PriorityQueue;

void initPQ(PriorityQueue *pq) { pq->size = 0; }
int isEmptyPQ(PriorityQueue *pq) { return pq->size == 0; }

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(PriorityQueue *pq, int idx) {
    int parent;
    while (idx > 0) {
        parent = (idx - 1) / 2;
        if (pq->heap[parent] <= pq->heap[idx]) break;
        swap(&pq->heap[parent], &pq->heap[idx]);
        idx = parent;
    }
}

void heapifyDown(PriorityQueue *pq, int idx) {
    int smallest, left, right;
    while (1) {
        smallest = idx;
        left = 2 * idx + 1;
        right = 2 * idx + 2;
        
        if (left < pq->size && pq->heap[left] < pq->heap[smallest]) smallest = left;
        if (right < pq->size && pq->heap[right] < pq->heap[smallest]) smallest = right;
        
        if (smallest == idx) break;
        swap(&pq->heap[idx], &pq->heap[smallest]);
        idx = smallest;
    }
}

void pushPQ(PriorityQueue *pq, int val) {
    if (pq->size >= MAX_SIZE) return;
    pq->heap[pq->size] = val;
    heapifyUp(pq, pq->size);
    pq->size++;
}

int popPQ(PriorityQueue *pq) {
    int val;
    if (isEmptyPQ(pq)) return -1;
    val = pq->heap[0];
    pq->heap[0] = pq->heap[--pq->size];
    heapifyDown(pq, 0);
    return val;
}

int topPQ(PriorityQueue *pq) {
    return isEmptyPQ(pq) ? -1 : pq->heap[0];
}

int main() {
    PriorityQueue pq;
    initPQ(&pq);
    
    pushPQ(&pq, 10);
    pushPQ(&pq, 20);
    pushPQ(&pq, 5);
    
    printf("%d %d\n", popPQ(&pq), topPQ(&pq));
    return 0;
}