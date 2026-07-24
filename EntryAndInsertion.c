#include<stdio.h>
int main()
{
    printf("Enter the number of elements in the array\n");
    int n;scanf("%d",&n);
    int A[n];
    printf("Enter the elements in the array\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    printf("Enter the element to be inserted\n");
    int ele;scanf("%d",&ele);
    printf("Enter the desired position\n");
    int pos;scanf("%d",&pos);
    for(int i=n;i>=pos;i--)
    {
        A[i]=A[i-1];
    }
    A[pos-1]=ele;
    n++;
    printf("Array after insertion\n");
    for (int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
    
}