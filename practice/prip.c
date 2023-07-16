#include <stdio.h>
#include <stdlib.h>

typedef struct process
{
    int AT, BT, CT, TAT, WT, Id, priority;
} pro;
pro p[15];

void main()
{
    int minIndex, minPri, curTime = 0, completed = 0, total_TAT = 0, total_WT = 0, n, tempBT[15];
    float avg_TAT = 0, avg_WT = 0;

    printf("Enter the number of processes\n");
    scanf("%d", &n);

    printf("Enter AT, BT and Priority of the processes\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &p[i].AT, &p[i].BT, &p[i].priority);
        p[i].Id = i + 1;
        tempBT[i] = p[i].BT;
    }

    printf("\nGantt Chart: \n");
    while (completed != n)
    {
        minIndex = -1;
        minPri = 999;
        for (int i = 0; i < n; i++)
        {
            if (p[i].AT <= curTime && p[i].BT > 0)
            {
                if (p[i].priority < minPri || (p[i].priority == minPri && p[i].AT < p[minIndex].AT))
                {
                    minIndex = i;
                    minPri = p[i].priority;
                }
            }
        }
        curTime++;
        if (minIndex != -1)
        {
            p[minIndex].BT--;
            printf("| P%d(1) %d", p[minIndex].Id, curTime);
            if (p[minIndex].BT == 0)
            {
                completed++;
                p[minIndex].CT = curTime;
                p[minIndex].TAT = curTime - p[minIndex].AT;
                p[minIndex].WT = p[minIndex].TAT - tempBT[minIndex];
                total_TAT += p[minIndex].TAT;
                total_WT += p[minIndex].WT;
            }
        }
    }
    printf("|\n");
    avg_TAT = (float)total_TAT / n;
    avg_WT = (float)total_WT / n;

    // Printing the table of processes with details
    printf("\nPID\tAT\tBT\tPriority\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].Id, p[i].AT, tempBT[i], p[i].priority, p[i].CT, p[i].TAT, p[i].WT);
    }
    printf("\nAverage TAT = %.2f\nAverage WT = %.2f\n", avg_TAT, avg_WT);
}
