#include <stdio.h>

int main() {
    int n,i,j,k;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (n % 2 == 0) {
        n = n + 1;
    }

	for(i=1,j=n/2;j>=0;i=i+2,j--)
	{
		for(k=0;k<j;k++)
			printf(" ");
		for(k=0;k<i;k++)
			printf("*");
		printf("\n");	
	}
	
	for(i=n-2,j=1;i>=0;i=i-2,j++)
	{
		for(k=0;k<j;k++)
			printf(" ");
		for(k=0;k<i;k++)
			printf("*");
		printf("\n");
	}
}

