#include <stdio.h>
#include <stdlib.h>

typedef struct process
{
    int Id, AT, BT, CT, WT, TAT;
} pro;

void main()
{

    pro p[15];
    int tempBT[15], n, minBT, minIndex, curTime = 0, completed = 0, total_WT = 0, total_TAT = 0;
    float avg_WT = 0, avg_TAT = 0;

    printf("Enter the number of processes\n");
    scanf("%d", &n);

    printf("\nEnter the arrival time and burst time of the process:\n");
    printf("AT BT\n");
    for (int i = 0; i < n; i++)
    {
        p[i].Id = i + 1;
        scanf("%d%d", &p[i].AT, &p[i].BT);
        tempBT[i] = p[i].BT;
    }

    printf("\nGantt Chart:\n");
    while (completed != n)
    {
        minIndex = -1;
        minBT = 999;
        for (int i = 0; i < n; i++)
        {
            if (p[i].AT <= curTime && p[i].BT > 0)
                if (p[i].BT < minBT || (p[i].BT == minBT && p[i].AT < p[minIndex].AT))
                {
                    minIndex = i;
                    minBT = p[i].BT;
                }
        }

        curTime++;
        if (minIndex != -1)
        {
            p[minIndex].BT--;
            printf("| P%d(1) %d ", p[minIndex].Id, curTime);
            if (p[minIndex].BT == 0)
            {
                p[minIndex].CT = curTime;
                p[minIndex].TAT = curTime - p[minIndex].AT;
                p[minIndex].WT = p[minIndex].TAT - tempBT[minIndex];
                total_TAT += p[minIndex].TAT;
                total_WT += p[minIndex].WT;
                completed++;
            }
        }
        else
        {
            printf("| Idle (1) ");
        }
    }

    printf("|\n");
    avg_TAT = (float)total_TAT / n;
    avg_WT = (float)total_WT / n;

    // Printing the table of processes with details
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].Id, p[i].AT, tempBT[i], p[i].CT, p[i].TAT, p[i].WT);
    }
    printf("\nAverage TAT = %.2f\nAverage WT = %.2f\n", avg_TAT, avg_WT);
}