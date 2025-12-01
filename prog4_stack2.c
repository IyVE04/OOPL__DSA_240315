#include <stdio.h>
#define MAX 100
int main() {
    char exp[MAX], stack[MAX];
    int top = -1;
    int i;
    
    printf("Enter expression: ");
    scanf("%s", exp);
    for (i = 0; exp[i] != '\0'; i++)
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            stack[++top] = exp[i];
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (top == -1) {
                printf("Not Balanced\n");
                return 0;
            }
            
            char last = stack[top--];   
            if ((exp[i] == ')' && last != '(') ||
                (exp[i] == '}' && last != '{') ||
                (exp[i] == ']' && last != '[')) {
                printf("Not Balanced\n");
                return 0;
            }
        }
    
   
    if (top == -1)
   printf("Balanced\n");
    else
        printf("Not Balanced\n");
    return 0;

}