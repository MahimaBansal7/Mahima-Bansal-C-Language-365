#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    int A[n];
    printf("Enter the elements in the array\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
    int pos;
    printf("Enter the position of the element to be deleted\n");
    scanf("%d",&pos);
    for(int i=pos-1;i<n-1;i++)
    {
        A[i]=A[i+1];
    }
    n--;
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}