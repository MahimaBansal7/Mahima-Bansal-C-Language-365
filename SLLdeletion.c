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
    printf("\n");
}
void atbeg()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        temp=head;
        head=head->next;
        free(temp);
    }
}
void atlast()
{
    struct node *temp,*q;
    temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    q=temp->next;
    temp->next=NULL;
    free(q);

}
void inbetween()
{
    struct node *temp,*q;
    int ele;
    printf("Enter the element to be deleted\n");
    scanf("%d",&ele);
    temp=head;
    while(temp->next!=NULL && temp->next->data!=ele)
    {
        temp=temp->next;
    }
    if(temp->next==NULL)
    {printf("Element not found");}
    else{
    q=temp->next;
    temp->next=q->next;
    free(q);
    }
}
void main()
{
    create();
    display();
    atbeg();
    printf("Delete the first element\n");
    display();
    atlast();
    printf("Delete the last element\n");
    display();
    inbetween();
    printf("Delete the given element\n");
    display();
}