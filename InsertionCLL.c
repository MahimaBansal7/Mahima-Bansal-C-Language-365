#include<stdio.h>
#include<stdlib.h>
struct node
{int data;
struct node *next;
};
struct node *head=NULL;
void create()
{
    struct node *new,*temp; int ch;
    do
    {
        new=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data part");
        scanf("%d",&new->data);
            new->next=NULL;
            if(head==NULL)
            {
            head=new;temp=new;}
            else
            {
            temp->next=new;
            temp=temp->next;
            temp->next=head;}
            printf("Do you want to continue(1/0)");
            scanf("%d",&ch);
    } while (ch==1);
    
    
}
void inbeg()
{
    struct node *p,*new;
    new=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data part");
    scanf("%d",&new->data);
    
    p=head;
    while(p->next!=head)
    {
        p=p->next;
    }
    p->next=new;
    new->next=head;
    head=new;
    
}
void inend()
{
    struct node *p,*new;
    new=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data part");
    scanf("%d",&new->data);
    
    p=head;
    while(p->next!=head)
    {
        p=p->next;
    }
    p->next=new;
    new->next=head;
}
void inbetween()
{
    struct node *new,*temp;;
    new=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data part");
    scanf("%d",&new->data);
    int data=new->data;
    temp=head;
    while(temp->next!=NULL && (temp->next->data)<(data))
    {
        temp=temp->next;
    }
    new->next=temp->next;
    temp->next=new;
}
    
void display()
{
    struct node *temp,*head;
    temp=head;
    if(head==NULL)
    {
        printf("List is empty");
    }
    else
    {
        do
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }while(temp!=head);
    }
}
void main()
{
    create();
    display();
    inbeg();
    display();
    inend();
    display(); 
    inbetween();
    display();
}