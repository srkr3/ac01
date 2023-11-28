#include<stdio.h>
int main()
{
    int n,m,a[20][20],b[20][20],i,j;
    printf("entre n ");
    scanf("%d%d",&n,&m);
    printf("entre matrix ");
    for ( i = 1; i <= n; i++)
    {
        for ( j = 1; j <=m; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(j=m;j>0;j--)
    {
        for(i=1;i<=n;i++)
        {
            b[n-j][i] = a[i][j];
        }
    }
    printf("matrix is clockwise 270 : \n");
    for(j=m;j>0;j--)
    {
        for(i=1;i<=n;i++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
