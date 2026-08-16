#include<stdio.h>
void main()
{
    int n;
    printf("Enter the number of elements in the array\n");
    scanf("%d",&n);int A[n];
    printf("Enter the elements in the array\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    int ele;
    printf("Enter the element to be searched\n");
    scanf("%d",&ele);
    int mid;int end=n-1;int beg=0;int f=0;
    
    while(beg<=end)
    {
        mid=(beg+end)/2;
        if(A[mid]==ele)
        {printf("Element found at %d\n",mid+1);f=1;break;}
        else if(ele>A[mid])
        beg=mid+1;
        else if(ele<A[mid])
        end=mid-1;
    }
    if(f==0)
    printf("Element not found\n");
}