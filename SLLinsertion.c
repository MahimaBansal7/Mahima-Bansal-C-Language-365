#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
void create()
{
    struct node *temp,*new;
    int ch;
    do
    {
        new=(struct node *)malloc(sizeof(struct node));
        printf("Enter the data: \n");
        scanf("%d",&new->data);
        new->next=NULL;
        if(head==NULL)
        {
            head=new;
            temp=new;
        }
        else
        {
            temp->next=new;
            temp=temp->next;
        }
        printf("Do you want to continue? (0/1)");
        scanf("%d",&ch);
        
    }while(ch==1);
    
}
void display()
{
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
void atbeg()
{
    struct node *new;
    new=(struct node *)malloc(sizeof(struct node));
    printf("Enter the element to be inserted at the beginning\n");
    scanf("%d",&new->data);
    new->next=NULL;
    if(head==NULL)
    {
        head=new;
    }
    else
    {
        new->next=head;
        head=new;
    }
}
void atlast()
{
    struct node *new,*temp;
    new=(struct node *)malloc(sizeof(struct node));
    printf("Enter the element to be inserted at the last\n");
    scanf("%d",&new->data);
    new->next=NULL;
    temp=head;
    if(head==NULL)
    {
        head=new;
    }
    else{
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new;
    temp=new;}
}
void inbetween()
{
    struct node *temp,*new;
    new=(struct node *)malloc(sizeof(struct node));
    printf("Enter the element to be inserted in between\n");
    scanf("%d",&new->data);
    new->next=NULL;
    temp=head;
    while(temp->next!=NULL && temp->next->data <new->data)
    {
        temp=temp->next;
    }
    new->next=temp->next;
    temp->next=new;

}
void main()
{
    create();
    display();
    atbeg();
    display();
    atlast();
    display();
    inbetween();
    display();
}