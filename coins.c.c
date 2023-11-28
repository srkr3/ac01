#include<stdio.h>
int main()
{
	int c,amount,i;
	int a[10] = {1,2,5,10,20,50,100,200,500,2000};
	printf("enter amount : ");
	scanf("%d",&amount);
	
	for(i=9 ;i>=0;i--)
	{
		c=0;
		while(amount>=a[i])
		{
			amount-=a[i];
			c++;
		}
		if(c>0)
			printf("%d * %d\n",a[i],c);
	}
}
