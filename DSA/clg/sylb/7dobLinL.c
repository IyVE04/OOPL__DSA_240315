#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
} DoublyLinkedList;

void initList(DoublyLinkedList *list) { list->head = NULL; }

Node *createNode(int val) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) return NULL;
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insert(DoublyLinkedList *list, int val) {
    Node *newNode, *curr;
    newNode = createNode(val);
    if (!newNode) return;
    
    if (!list->head) {
        list->head = newNode;
    } else {
        curr = list->head;
        while (curr->next) curr = curr->next;
        curr->next = newNode;
        newNode->prev = curr;
    }
}

void printList(DoublyLinkedList *list) {
    Node *curr = list->head;
    while (curr) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void freeList(DoublyLinkedList *list) {
    Node *curr = list->head;
    Node *temp;
    while (curr) {
        temp = curr;
        curr = curr->next;
        free(temp);
    }
    list->head = NULL;
}

int main() {
    DoublyLinkedList list;
    initList(&list);
    
    insert(&list, 10);
    insert(&list, 20);
    insert(&list, 30);
    
    printList(&list);
    freeList(&list);
    return 0;
}