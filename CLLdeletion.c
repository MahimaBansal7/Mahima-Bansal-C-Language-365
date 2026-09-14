#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
void create()
{
    struct node *temp, *new;
    int ch;
    do
    {
        new = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data: \n");
        scanf("%d", &new->data);
        new->next = NULL;
        if (head == NULL)
        {
            head = new;
            temp = new;
            new->next = head;
        }
        else
        {
            temp->next = new;
            temp = new;
            temp->next = head;
        }
        printf("Do you want to continue? (0/1)");
        scanf("%d", &ch);
    } while (ch == 1);
}
void display()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
void atbeg()
{
    struct node *temp, *last;
    if (head == NULL)
        printf("The list is empty\n");
    else if (head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        last = head;
        while (last->next != head)
            last = last->next;
        temp = head;
        head = head->next;
        last->next = head;
        free(temp);
    }
}
void atlast()
{
    struct node *temp, *q;
    if (head == NULL)
        printf("The list is empty\n");
    else if (head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        temp = head;
        while (temp->next->next != head)
            temp = temp->next;
        q = temp->next;
        temp->next = head;
        free(q);
    }
}
void inbetween()
{
    struct node *temp, *q;
    int ele;
    if (head == NULL)
    {
        printf("The list is empty\n");
        return;
    }
    printf("Enter the element to be deleted\n");
    scanf("%d", &ele);
    if (head->data == ele)
    {
        atbeg();
        return;
    }
    temp = head;
    while (temp->next != head && temp->next->data != ele)
        temp = temp->next;
    if (temp->next == head)
        printf("Element not found\n");
    else
    {
        q = temp->next;
        temp->next = q->next;
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