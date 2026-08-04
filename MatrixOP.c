#include<stdio.h>
void main()
{
    int m,n,r,c;
    printf("Enter the number of rows and columns in the first matrix\n");
    scanf("%d%d",&m,&n);
    
    int A[m][n];
    printf("Enter the elements in the matrix\n");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    printf("The first Matrix:\n");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    printf("Enter the number of rows and columns in the second matrix\n");
    scanf("%d",&r);
    scanf("%d",&c);
    int B[r][c];
    printf("Enter the elements in the matrix\n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",&B[i][j]);
        }
    }
    printf("The second Matrix:\n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%d ",B[i][j]);
        }
        printf("\n");
    }
    int Add[m][n],Sub[m][n],Mul[m][c];
    if(m!=r || n!=c)
    printf("Addition and Subtraction not possible\n");
    else
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                Add[i][j]=A[i][j]+B[i][j];
                Sub[i][j]=A[i][j]-B[i][j];
            }
        }
    printf("The Addition Matrix:\n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%d ",Add[i][j]);
        }
        printf("\n");
    }
    printf("The Subtraction Matrix:\n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%d ",Sub[i][j]);
        }
        printf("\n");
    }
    }
    //Multiplication of the matrix
    if(n!=r)
    printf("Multiplication not possible\n");
    else{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<c;j++)
        {
            Mul[i][j]=0;
            for(int k=0;k<n;k++)
            {
                Mul[i][j]=Mul[i][j]+A[i][k]*B[k][j];
            }
        }
    }
    printf("The Multiplication Matrix:\n");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%d ",Mul[i][j]);
        }
        printf("\n");
    }
}
}