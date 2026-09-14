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
    int c=0;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        c++;
        temp=temp->next;
    }
    printf("\n");
    printf("Length of LL= %d",c);
}
void main()
{
    create();
    display();
}