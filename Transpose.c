#include<stdio.h>
void main()
{
    int m,n;
    printf("Enter rows and columns of a matrix\n");
    scanf("%d",&m);
    scanf("%d",&n);
    int A[m][n];
    printf("Enter the elements in the matrix\n");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    printf("The Original Matrix:\n");
     for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    printf("Transpose of the given matrix:\n");
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%d ",A[j][i]);
        }
        printf("\n");
    }
}