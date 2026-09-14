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
    struct node *new,*temp;int ch;
    do
    {
        new=(struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
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
        printf("Enter 1 to continue: ");
        scanf("%d",&ch);
    } while (ch==1);  
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
void search()
{
    struct node *temp;
    temp=head;int pos=1,ele;
    printf("Enter the element to be searched: \n");
    scanf("%d",&ele);
    while(temp!=NULL && temp->data!=ele)
    {
        pos++;
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("Element not found\n");
    }
    else
    {
        printf("Element %d found at position %d",ele,pos);
    }
}
void main()
{
    create();
    display();
    search();
}