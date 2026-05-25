#include <stdio.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} IntStack;

void initStack(IntStack *s) { s->top = -1; }
int isEmpty(IntStack *s) { return s->top == -1; }
void push(IntStack *s, int val) { if (s->top < MAX_SIZE - 1) s->data[++s->top] = val; }
int pop(IntStack *s) { return isEmpty(s) ? 0 : s->data[s->top--]; }

int evaluatePostfix(const char *expr) {
    IntStack s;
    int i, op1, op2;
    char c;
    initStack(&s);
    
    for (i = 0; expr[i] != '\0'; i++) {
        c = expr[i];
        if (isdigit(c)) {
            push(&s, c - '0');
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            op2 = pop(&s);
            op1 = pop(&s);
            switch (c) {
                case '+': push(&s, op1 + op2); break;
                case '-': push(&s, op1 - op2); break;
                case '*': push(&s, op1 * op2); break;
                case '/': push(&s, op1 / op2); break;
            }
        }
    }
    return pop(&s);
}

int main() {
    char expr[256];
    printf("Enter postfix expression (e.g., 23+5*): ");
    scanf("%s", expr);
    printf("Result: %d\n", evaluatePostfix(expr));
    return 0;
}