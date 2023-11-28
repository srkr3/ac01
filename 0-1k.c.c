#include <stdio.h>
int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int knapsack(int capacity, int weights[], int values[], int n) {
    int dp[n + 1][capacity + 1];
    int i,j;
    for ( i = 0; i <= n; i++) {
        for ( j = 0; j <= capacity; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0; 
            else if (weights[i - 1] <= j)
                dp[i][j] = max(values[i - 1] + dp[i - 1][j - weights[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    
	printf("The maximum value that can be obtained is: %d\n", dp[n][capacity]);
}

int main() {
    int n, capacity,i;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int weights[n], values[n];

    printf("Enter the weights of the items:\n");
    for ( i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    printf("Enter the values of the items:\n");
    for ( i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }

    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    knapsack(capacity, weights, values, n);
    return 0;
}

