#include <stdio.h>
#include <stdlib.h>

typedef struct process
{
    int Id, AT, BT, CT, WT, TAT, isCompl;
} pro;

void main()
{
    pro p[15];
    int n, idleTime = 0, minIndex, minBT, completed = 0, curTime = 0;
    int total_TAT = 0, total_WT = 0;
    float avg_TAT = 0, avg_WT = 0;

    printf("Enter the number of processes\n");
    scanf("%d", &n);
    printf("Enter AT and BT of all the processes\n");
    printf("AT BT\n");
    for (int i = 0; i < n; i++)
    {
        p[i].Id = i + 1;
        scanf("%d%d", &p[i].AT, &p[i].BT);
        p[i].isCompl = 0;
    }

    while (completed != n)
    {
        minBT = 999;
        minIndex = -1;
        for (int i = 0; i < n; i++)
        {
            if (p[i].AT <= curTime && p[i].isCompl == 0)
                if (p[i].BT < minBT || (p[i].BT == minBT && p[i].AT < p[minIndex].AT))
                {
                    minIndex = i;
                    minBT = p[i].BT;
                }
        }

        if (minIndex == -1)
        {
            idleTime++;
            curTime++;
        }
        else
        {
            if (idleTime > 0)
            {
                printf("| Idle till %d ", p[minIndex].AT);
                idleTime = 0;
            }
            curTime += p[minIndex].BT;
            p[minIndex].isCompl = 1;
            completed++;
            p[minIndex].CT = curTime;
            p[minIndex].TAT = p[minIndex].CT - p[minIndex].AT;
            p[minIndex].WT = p[minIndex].TAT - p[minIndex].BT;
            total_TAT += p[minIndex].TAT;
            total_WT += p[minIndex].WT;
            printf("| P%d (%d) %d ", p[minIndex].Id, p[minIndex].BT, p[minIndex].CT);
        }
    }
    printf("|\n");
    avg_TAT = (float)total_TAT / n;
    avg_WT = (float)total_WT / n;

    // Printing the table of processes with details
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].Id, p[i].AT, p[i].BT, p[i].CT, p[i].TAT, p[i].WT);
    }
    printf("\nAverage TAT = %.2f\nAverage WT = %.2f\n", avg_TAT, avg_WT);
}