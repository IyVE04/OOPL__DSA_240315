#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE][MAX_SIZE];
    int top;
} StringStack;

void initStack(StringStack *s) { s->top = -1; }
int isEmpty(StringStack *s) { return s->top == -1; }
void push(StringStack *s, const char *str) { 
    if (s->top < MAX_SIZE - 1) strcpy(s->data[++s->top], str); 
}
void pop(StringStack *s, char *result) { 
    if (!isEmpty(s)) strcpy(result, s->data[s->top--]); 
}

void prefixToPostfix(const char *prefix, char *postfix) {
    StringStack s;
    int i, len;
    char c, operand[2], op1[MAX_SIZE], op2[MAX_SIZE], combined[MAX_SIZE];
    
    initStack(&s);
    len = strlen(prefix);
    
    for (i = len - 1; i >= 0; i--) {
        c = prefix[i];
        if (isalnum(c)) {
            operand[0] = c;
            operand[1] = '\0';
            push(&s, operand);
        } else {
            pop(&s, op1);
            pop(&s, op2);
            sprintf(combined, "%s%s%c", op1, op2, c);
            push(&s, combined);
        }
    }
    pop(&s, postfix);
}

int main() {
    char prefix[MAX_SIZE], postfix[MAX_SIZE];
    printf("Enter prefix expression: ");
    scanf("%s", prefix);
    
    prefixToPostfix(prefix, postfix);
    printf("Postfix: %s\n", postfix);
    return 0;
}