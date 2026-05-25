#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct AdjListNode {
    int dest;
    struct AdjListNode *next;
} AdjListNode;

typedef struct {
    AdjListNode *head;
} AdjList;

typedef struct {
    int V;
    AdjList array[MAX_VERTICES];
} Graph;

typedef struct {
    int data[MAX_VERTICES];
    int front, rear;
} Queue;

void initQueue(Queue *q) { q->front = q->rear = -1; }
int isQueueEmpty(Queue *q) { return q->front == -1; }
void enqueue(Queue *q, int val) {
    if (q->rear == MAX_VERTICES - 1) return;
    if (q->front == -1) q->front = 0;
    q->data[++q->rear] = val;
}
int dequeue(Queue *q) {
    int val;
    if (isQueueEmpty(q)) return -1;
    val = q->data[q->front];
    if (q->front == q->rear) q->front = q->rear = -1;
    else q->front++;
    return val;
}

typedef struct {
    int data[MAX_VERTICES];
    int top;
} Stack;

void initStack(Stack *s) { s->top = -1; }
int isStackEmpty(Stack *s) { return s->top == -1; }
void pushStack(Stack *s, int val) { if (s->top < MAX_VERTICES - 1) s->data[++s->top] = val; }
int popStack(Stack *s) { return isStackEmpty(s) ? -1 : s->data[s->top--]; }

Graph *createGraph(int V) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    int i;
    graph->V = V;
    for (i = 0; i < V; i++) graph->array[i].head = NULL;
    return graph;
}

void addEdge(Graph *graph, int src, int dest) {
    AdjListNode *newNode = (AdjListNode *)malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

void BFS(Graph *graph, int start) {
    int visited[MAX_VERTICES];
    Queue q;
    int v, i;
    AdjListNode *curr;
    
    for (i = 0; i < graph->V; i++) visited[i] = 0;
    initQueue(&q);
    
    visited[start] = 1;
    enqueue(&q, start);
    
    while (!isQueueEmpty(&q)) {
        v = dequeue(&q);
        printf("%d ", v);
        
        curr = graph->array[v].head;
        while (curr) {
            if (!visited[curr->dest]) {
                visited[curr->dest] = 1;
                enqueue(&q, curr->dest);
            }
            curr = curr->next;
        }
    }
    printf("\n");
}

void DFS(Graph *graph, int start) {
    int visited[MAX_VERTICES];
    Stack s;
    int v, i, neighbors[MAX_VERTICES], count;
    AdjListNode *curr;
    
    for (i = 0; i < graph->V; i++) visited[i] = 0;
    initStack(&s);
    
    pushStack(&s, start);
    
    while (!isStackEmpty(&s)) {
        v = popStack(&s);
        if (!visited[v]) {
            printf("%d ", v);
            visited[v] = 1;
            
            curr = graph->array[v].head;
            count = 0;
            while (curr) {
                neighbors[count++] = curr->dest;
                curr = curr->next;
            }
            for (i = count - 1; i >= 0; i--) {
                if (!visited[neighbors[i]]) pushStack(&s, neighbors[i]);
            }
        }
    }
    printf("\n");
}

void freeGraph(Graph *graph) {
    int i;
    AdjListNode *curr, *temp;
    for (i = 0; i < graph->V; i++) {
        curr = graph->array[i].head;
        while (curr) {
            temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(graph);
}

int main() {
    Graph *g = createGraph(4);
    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 2);
    addEdge(g, 2, 0);
    addEdge(g, 2, 3);
    
    printf("BFS: ");
    BFS(g, 2);
    printf("DFS: ");
    DFS(g, 2);
    
    freeGraph(g);
    return 0;
}