#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}
char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return -1;
}
char peek() {
    if (top >= 0) {
        return stack[top];
    }
    return -1;
}
int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/' || c == '%') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}
int isOperand(char c) {
    return (c >= 'a' && c <= 'z') || 
           (c >= 'A' && c <= 'Z') || 
           (c >= '0' && c <= '9');
}
void reverse(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}
void infixToPrefix(char *infix, char *prefix) {
    int len = strlen(infix);
    char temp[MAX];
    strcpy(temp, infix);
    reverse(temp);
    for (int i = 0; i < len; i++) {
        if (temp[i] == '(') {
            temp[i] = ')';
        } else if (temp[i] == ')') {
            temp[i] = '(';
        }
    }
    char postfix[MAX];
    int k = 0;
    top = -1; 
    for (int i = 0; i < len; i++) {
        char c = temp[i];

        if (isOperand(c)) {
            postfix[k++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top != -1 && peek() != '(') {
                postfix[k++] = pop();
            }
            if (top != -1 && peek() == '(') {
                pop(); // discard '('
            }
        } else { // Operator
            while (top != -1 && precedence(peek()) > precedence(c)) {
                postfix[k++] = pop();
            }
            push(c);
        }
    }
    while (top != -1) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
    reverse(postfix);
    strcpy(prefix, postfix);
}
int main() {
    char infix[MAX], prefix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);
    return 0;
}
