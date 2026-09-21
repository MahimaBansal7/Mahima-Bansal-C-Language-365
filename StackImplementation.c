#include<stdio.h>
#define size 5
int stack[size],top=-1;
void push(int x)
{
    if(top==size-1)
    {
        printf("Stack Overflow");
    }
    else
    {
        top++;
        stack[top]=x;
    }
}
void pop()
{
    int x;
    if(top==-1)
    printf("Stack Underflow");
    else
    {
        printf("Popped element: %d\n", stack[top]);
        top--;
    }
}
void main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    pop();
    pop();
    push(15);
    pop();
    pop();
    pop();
    pop();

}