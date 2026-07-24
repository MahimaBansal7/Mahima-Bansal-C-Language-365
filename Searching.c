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
    int ele;
    printf("Enter the value to be searched\n");
    scanf("%d",&ele);
    int f=0;
    for(int i=0;i<n;i++)
    {
        if(ele==A[i])
        {
            f=1;
            break;
        }
    }
    if(f==1)
    printf("Element found!\n");
    else
    printf("Element not found\n");
}