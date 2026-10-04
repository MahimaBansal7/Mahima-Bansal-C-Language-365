#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
void create()
{
    struct node *new,*temp;
    int ch;
    do{
    new=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data:\n");
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
    printf("Do you want to continue adding?(0/1)\n");
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
    printf("\n");
}
void count()
{
    struct node *temp;
    int c=0;
    temp=head;
    while(temp!=NULL)
    {
        c++;
        temp=temp->next;
    }
    printf("Number of nodes = %d\n",c);
}
void insertbeg()
{
    struct node *new,*temp;
    new=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data to insert at the beginning\n");
    scanf("%d",&new->data);
    new->next=NULL;
    if(head==NULL)
    {
        head=new;
        temp=new;
    }
    else{
        new->next=head;
        head=new;
    }
}
void insertlast()
{
    struct node *new,*temp;
    new=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data to be inserted at the last\n");
    scanf("%d",&new->data);
    new->next=NULL;
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new;
}
void insertmid()
{
    struct node *new,*temp;int pos;
    new=(struct node *)malloc(sizeof(struct node));
    printf("Enter the element to be inserted and its position\n");
    scanf("%d %d",&new->data,&pos);
    new->next=NULL;
    temp=head;
    for(int i=1;i<pos-1;i++)
    {
        if(temp->next!=NULL)
        {
            temp=temp->next;
        }
    }
    new->next=temp->next;
    temp->next=new;
}
void dellast()
{
    printf("Deleting the Last element\n");
    struct node *temp,*q;
    temp=head;
    q=head;
    while(temp->next!=NULL)
    {
        q=temp;
        temp=temp->next;
    }
    q->next=NULL;
    free(temp);
}
void delbeg()
{
    printf("Deleting the First element\n");
    struct node *temp;
    temp=head;
    head=head->next;
    free(temp);
}
void delpos()
{
    struct node *temp,*prev;
    temp=head;prev=head;
    int pos;
    printf("Enter the position of the element to be deleted\n");
    scanf("%d",&pos);
    for(int i=1;i<pos && temp->next!=NULL;i++)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    free(temp);
}
void reverselist()
{
    printf("Reversing the list\n");
    struct node *prev,*curr,*nxt;
    prev=NULL;curr=head;nxt=NULL;
        while(curr!=NULL)
        {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        head=prev;
}
void search()
{
    struct node *temp;
    int ele;
    printf("Enter the element to be searched\n");
    scanf("%d",&ele);
    temp=head;
    int f=0;
    while(temp!=NULL)
    {
        if(temp->data==ele)
        {
            printf("Element found\n");
            f=1;
            break;
        }
        temp=temp->next;
    }
    if(f==0)
    printf("Element not found\n");
}
void main()
{
    create();
    display();
    insertbeg();
    display();
    insertlast();
    display();
    insertmid();
    display();
    count();
    delbeg();
    display();
    dellast();
    display();
    delpos();
    display();
    search();
    reverselist();
    display();
}