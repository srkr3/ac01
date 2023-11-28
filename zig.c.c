#include<stdio.h>
int main()
{
	int n,m,i,j,a[20][20];
	printf("enter n ");
	scanf("%d%d",&n,&m);
	printf("enter mat \n");
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&a[i][j]);
			
	for(i=0;i<n;i++)
	{
		if(i%2==0)
			for(j=0;j<m;j++)
				printf("%d ",a[i][j]);
		
		else
			for(j=m-1;j>=0;j--)
				printf("%d ",a[i][j]);
	}
}
