#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int top;
} CharStack;

void initStack(CharStack *s) { s->top = -1; }
int isEmpty(CharStack *s) { return s->top == -1; }
void push(CharStack *s, char c) { if (s->top < MAX_SIZE - 1) s->data[++s->top] = c; }
char pop(CharStack *s) { return isEmpty(s) ? '\0' : s->data[s->top--]; }
char peek(CharStack *s) { return isEmpty(s) ? '\0' : s->data[s->top]; }

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void infixToPostfix(const char *infix, char *postfix) {
    CharStack s;
    int i, j = 0;
    char c;
    initStack(&s);
    
    for (i = 0; infix[i] != '\0'; i++) {
        c = infix[i];
        if (isalnum(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            push(&s, c);
        } else if (c == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s);
        } else {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(c)) {
                postfix[j++] = pop(&s);
            }
            push(&s, c);
        }
    }
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}

void reverseString(char *str) {
    int len, i;
    char temp;
    len = strlen(str);
    for (i = 0; i < len / 2; i++) {
        temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

void infixToPrefix(const char *infix, char *prefix) {
    char reversed[MAX_SIZE];
    int i, len;
    char tempPostfix[MAX_SIZE];
    
    len = strlen(infix);
    for (i = 0; i < len; i++) {
        if (infix[len - 1 - i] == '(') reversed[i] = ')';
        else if (infix[len - 1 - i] == ')') reversed[i] = '(';
        else reversed[i] = infix[len - 1 - i];
    }
    reversed[len] = '\0';
    
    infixToPostfix(reversed, tempPostfix);
    strcpy(prefix, tempPostfix);
    reverseString(prefix);
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE], prefix[MAX_SIZE];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    
    infixToPostfix(infix, postfix);
    infixToPrefix(infix, prefix);
    
    printf("Postfix: %s\n", postfix);
    printf("Prefix: %s\n", prefix);
    return 0;
}