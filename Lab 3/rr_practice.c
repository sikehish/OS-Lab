#include <stdio.h>
#include <stdlib.h>

typedef struct process
{
    int Id, AT, BT, CT, WT, TAT, flag;
} pro;

void main()
{

    pro p[15];
    int tempBT[15], n, quantum;

    printf("Enter the total number of processes\n");
    scanf("%d", &n);

    printf("Enter the quantum\n");
    scanf("%d", &quantum);

    printf("Enter the AT and BT\n");
    printf("AT BT\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &p[i].AT, &p[i].BT);
        p[i].flag = 0;
        tempBT[i] = p[i].BT;
        p[i].Id = i + 1;
    }

    // sorting
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].AT > p[j + 1].AT)
            {
                pro temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    int curTime = p[0].AT, curIndex = 0, completed = 0;
    int *waitQueue = (int *)malloc(sizeof(int) * n);
    int front = 0, rear = 0;
    p[0].flag = 1;
    waitQueue[rear] = 0;

    int total_TAT = 0, total_WT = 0;
    float avg_TAT = 0, avg_WT = 0;

    while (completed != n)
    {
        curIndex = waitQueue[front];
        front = (front + 1) % n;

        if (p[curIndex].BT > quantum)
        {
            curTime += quantum;
            p[curIndex].BT -= quantum;
            printf("| P%d(%d) %d", p[curIndex].Id, quantum, curTime);
        }
        else
        {
            curTime += p[curIndex].BT;
            printf("| P%d(%d) %d", p[curIndex].Id, p[curIndex].BT, curTime);
            p[curIndex].BT = 0;
            p[curIndex].CT = curTime;
            p[curIndex].TAT = p[curIndex].CT - p[curIndex].AT;
            total_TAT += p[curIndex].TAT;
            p[curIndex].WT = p[curIndex].TAT - tempBT[p[curIndex].Id - 1];
            total_WT += p[curIndex].WT;
            completed++;
        }

        for (int i = 0; i < n && p[i].AT <= curTime; i++)
        {
            if (p[i].flag == 1 || i == curIndex || p[i].BT == 0)
                continue;
            p[i].flag = 1;
            rear = (rear + 1) % n;
            waitQueue[rear] = i;
        }

        if (p[curIndex].BT > 0)
        {
            rear = (rear + 1) % n;
            waitQueue[rear] = curIndex;
        }
    }

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