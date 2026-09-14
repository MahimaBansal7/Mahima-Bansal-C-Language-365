#include<stdio.h>
#include<stdlib.h>
struct node
{int data;
struct node *next;
};
void create()
{
    struct node *new,*head,*temp; int ch;
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
int main()
{
    create();
    return 0;
}