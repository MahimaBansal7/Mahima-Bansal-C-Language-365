#include<stdio.h>
int main()
{
    int m,n;
    printf("Enter the size of the first array\n");
    scanf("%d",&m);
    printf("Enter the size of the second array\n");
    scanf("%d",&n);
    int A[m];int B[n];
    printf("Enter the elements in the first array\n");
    for(int i=0;i<m;i++)
    {
        scanf("%d",&A[i]);
    }
    printf("First Array\n");
    for(int i=0;i<m;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
     printf("Enter the elements in the second array\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&B[i]);
    }
    printf("Second Array\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",B[i]);
    }
    printf("\n");
    
    int C[m+n];
    for(int i=0;i<m;i++)
    {
        C[i]=A[i];
    }
    for(int i=m;i<(m+n);i++)
    {
        C[i]=B[i-m];
    }
    printf("Merged Array\n");
    for(int i=0;i<(m+n);i++)
    {
        printf("%d ",C[i]);
    }
    printf("\n");
}