#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node *new, *top = NULL,*t,*head;
void pop()
{
    if(top==NULL)
    printf("Stack Underflow\n");
    else
    {
        t=top;
        top=top->next;
        free(t);
    }
}
void push(int x)
{
    new=(struct Node*)malloc(sizeof(struct Node));
    new->data=x;
    new->next=top;
    top=new;
}

void display()
{
    t=top;
    while(t!=NULL)
    {
        printf("%d\n",t->data);
        t=t->next;
    }
}
void create()
{
    int n,i,val;
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the data\n");
        scanf("%d",&val);
        push(val);
    }
    printf("\n");
}
void main()
{
    create();
    display();
    push(10);
    push(20);
    push(30);
    push(40);
    display();
    pop();
    display();
    pop();
    display();
}