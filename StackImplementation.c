#include<stdio.h>
#define size 5
int stack[size],top=-1;
int isEmpty()
{
    if(top==-1)
    {
        
        return 1;
    }
    else
    {
        
        return 0;
    }
}

int isFull()
{
    if(top==size-1)
    {
        
        return 1;
    }
    else
    {
        
        return 0;
    }
}
void push(int x)
{
    if(isFull())
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
    if(isEmpty())
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