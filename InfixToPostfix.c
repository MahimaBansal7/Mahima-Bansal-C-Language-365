#include <stdio.h>
char stack[100];
int top = -1;
void push(char c) 
{
    stack[++top] = c;
}
char pop() 
{
    return stack[top--];
}
int priority(char c) {
    if(c=='^') 
    return 3;
    else if(c=='*' || c=='/') 
    return 2;
    else if(c=='+' || c=='-')
    return 1;
    else 
    return 0;
}
int main() 
{
    char infix[100];
    int i;char ch;
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    for(i=0; infix[i]!='\0'; i++) 
    {
        ch=infix[i];
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')) 
        {
            printf("%c", ch);
        } 
        else if(ch=='(') 
        {
            push(ch);
        } 
        else if(ch==')') 
        {
            while(stack[top]!='(') 
             printf("%c", pop());
            
            pop();
        }
        
        else 
        {
            while(top!=-1 && priority(stack[top])>=priority(ch)) 
            {
                printf("%c", pop());
            }
            push(ch);
        }

    }
    while(top!=-1) 
    {
        printf("%c", pop());
    }
    return 0;
}