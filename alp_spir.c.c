#include<stdio.h>
int main()
{
	int c=0,n,i,j,a[20][20];
	int top,lef,rig,bot;
	printf("enter the size of matrix : ");
	scanf("%d",&n);
	printf("matrix is : \n");
	for ( i = 0; i < n; i++)
    {
        for ( j = 0; j <n; j++)
        {
            a[i][j]=c;
            c++;
            printf("%c ",65+a[i][j]);
        }
        printf("\n");
    }
    
	top = lef = 0;
	bot = rig = n-1;
	
	while(top<=bot && lef<=rig)
	{
		i=top;
		for(j=lef ;j<=rig;j++)
			printf("%c -> ",65+a[i][j]);
		j=rig;
		top++;
		
		for(i=top ;i<=bot ;i++)
			printf("%c -> ",65+a[i][j]);
		i=bot;
		rig--;
		
		for(j=rig ;j>=lef ;j--)
			printf("%c -> ",65+a[i][j]);
		j=lef;
		bot--;
		
		for(i=bot ;i>=top ;i--)
			printf("%c -> ",65+a[i][j]);
		lef++;
	}
}
