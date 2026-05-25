#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

// Simple stack implementation for characters
typedef struct {
    char data[MAX_SIZE];
    int top;
} CharStack;

void initStack(CharStack* s) { s->top = -1; }
int isEmpty(CharStack* s) { return s->top == -1; }
void push(CharStack* s, char c) { if (s->top < MAX_SIZE - 1) s->data[++s->top] = c; }
char pop(CharStack* s) { return isEmpty(s) ? '\0' : s->data[s->top--]; }
char peek(CharStack* s) { return isEmpty(s) ? '\0' : s->data[s->top]; }

int isBalanced(const char* expr) {
    CharStack s;
    initStack(&s);
    
    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];
        if (c == '(' || c == '{' || c == '[') {
            push(&s, c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (isEmpty(&s)) return 0;
            char top = pop(&s);
            if ((c == ')' && top != '(') || 
                (c == '}' && top != '{') || 
                (c == ']' && top != '[')) {
                return 0;
            }
        }
    }
    return isEmpty(&s);
}

int main() {
    char expr[256];
    printf("Enter expression: ");
    fgets(expr, sizeof(expr), stdin);
    // Remove trailing newline
    expr[strcspn(expr, "\n")] = '\0';
    
    printf("%s\n", isBalanced(expr) ? "Balanced" : "Not Balanced");
    return 0;
}