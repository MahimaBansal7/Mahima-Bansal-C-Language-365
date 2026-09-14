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
void main()
{
    create();
    display();
}