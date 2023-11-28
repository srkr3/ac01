#include <stdio.h>

int main() {
    int n,j,i,k,count = 0;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    
    if(n%2 == 0)
    	n=n+1;
    
    for(i=n/2,j=n/2 ; count<n/2 ; i--,j++)
    {
    	for(k=0;k<=j;k++)
    	{
    		if(k==i || k==j)
    			printf("*");
    		else
    			printf(" ");
		}
		printf("\n");
        count++;
	}
    
    for(i=0;i<n;i++)
    	printf("*");
}

