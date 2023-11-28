#include <stdio.h>

struct Job {
    int id;
    int deadline;
    int profit;
};

void jobScheduling(struct Job jobs[], int n) {
    int i, j;
    
    // Sort jobs based on deadlines in ascending order
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (jobs[j].deadline > jobs[j + 1].deadline) {
                struct Job temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }

    int result[n];
    int timeSlots[n];

    for (i = 0; i < n; i++) {
        timeSlots[i] = -1;
    }

    for (i = 0; i < n; i++) {
        for (j = jobs[i].deadline - 1; j >= 0; j--) {
            if (timeSlots[j] == -1) {
                result[j] = i;
                timeSlots[j] = 1;
                break;
            }
        }
    }

    int totalProfit = 0;
    printf("\nScheduled Jobs: \n");
    for (i = 0; i < n-1; i++) {
        printf("Job %d \n", jobs[result[i]].id);
        totalProfit += jobs[result[i]].profit;
    }
    printf("\nTotal Profit: %d\n", totalProfit);
}

int main() {
    int n, i;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    struct Job jobs[n];

    for (i = 0; i < n; i++) {
        jobs[i].id = i + 1;
        printf("Enter deadline for Job %d: ", jobs[i].id);
        scanf("%d", &jobs[i].deadline);
        printf("Enter profit for Job %d : ", jobs[i].id);
        scanf("%d", &jobs[i].profit);
    }
    jobScheduling(jobs, n);

    return 0;
}

