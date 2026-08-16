#include<stdio.h>
void main()
{
    int key;
    printf("Enter the number of elements in the array\n");
    int n;scanf("%d",&n);
    int A[n];
    printf("Enter the elements of the array\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    printf("Enter the element to be searched\n");
    scanf("%d",&key);
    int f=0;int pos;
    for(int i=0;i<n;i++)
    {
        if(A[i]==key)
        {
            f=1;pos=i+1;break;
        }
    }
    if(f==1)
    printf("Element found at %d\n",pos);
    else
    printf("Element not found\n");
}