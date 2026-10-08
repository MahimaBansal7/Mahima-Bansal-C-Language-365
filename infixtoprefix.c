#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char c) {
    if (top >= MAX - 1) {
        return;
    }
    stack[++top] = c;
}
char pop() {
    if (top == -1) {
        return '\0';
    }
    return stack[top--];
}
char peek() {
    if (top == -1) {
        return '\0';
    }
    return stack[top];
}
int getPrecedence(char c) {
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
void reverseAndSwap(char* exp) {
    int len = strlen(exp);
    for (int i = 0; i < len / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[len - 1 - i];
        exp[len - 1 - i] = temp;
    }

    for (int i = 0; i < len; i++) {
        if (exp[i] == '(') {
            exp[i] = ')';
        } else if (exp[i] == ')') {
            exp[i] = '(';
        }
    }
}
void reverseString(char* exp) {
    int len = strlen(exp);
    for (int i = 0; i < len / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[len - 1 - i];
        exp[len - 1 - i] = temp;
    }
}
void infixToPostfix(char* infix, char* postfix) {
    int i = 0, j = 0;
    char c;
    while (infix[i] != '\0') {
        c = infix[i];
        if (isalnum(c)) {
            postfix[j++] = c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            pop();
        }
        else if (isOperator(c)) {
            while (top != -1 && getPrecedence(peek()) > getPrecedence(c)) {
                postfix[j++] = pop();
            }
            push(c);
        }
        i++;
    }
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}
void infixToPrefix(char* infix, char* prefix) {
    reverseAndSwap(infix);
    char tempPostfix[MAX];
    infixToPostfix(infix, tempPostfix);
    reverseString(tempPostfix);
    strcpy(prefix, tempPostfix);
}
int main() {
    char infix[MAX], prefix[MAX];
    printf("Enter an infix expression : ");
    scanf("%s", infix);
    infixToPrefix(infix, prefix);
    printf("Equivalent Prefix Expression: %s\n", prefix);
    return 0;
}
