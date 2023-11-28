#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    if (a > b)
    	return a;
 	else 
    	return b;
}

void seq(char X[], char Y[]) {
    int n = strlen(X);
    int m = strlen(Y);
	int i,j;
    int dp[n + 1][m + 1];

    // Build the dp table
    for ( i = 0; i <= n; i++) {
        for ( j = 0; j <= m; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    printf("max seq %d ",dp[n][m]) ;
}

int main() {
    char X[] = "ABCBDAB";
    char Y[] = "BDAB";

    seq(X, Y);
}

