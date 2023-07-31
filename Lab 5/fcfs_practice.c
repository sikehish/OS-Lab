#include <stdio.h>

typedef struct process
{
    int Id, AT, BT, CT, WT, TAT;
} pro;

void main()
{

    pro p[15];
    int temp1, n;
    int total_TAT = 0, total_WT = 0;
    float avg_TAT = 0, avg_WT = 0;

    printf("Enter the number of processes\n");
    scanf("%d", &n);

    printf("Enter AT and BT\n");
    printf("AT BT\n");
    for (int i = 0; i < n; i++)
    {
        p[i].Id = i + 1;
        scanf("%d%d", &p[i].AT, &p[i].BT);
    }

    // Sorting
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

    printf("\nGantt Chart:\n");

    p[0].CT = p[0].AT + p[0].BT;
    int ct = p[0].CT;
    if (p[0].AT > 0)
        printf("| Idle till %d", p[0].AT);
    printf("| P%d(%d) %d", p[0].Id, p[0].BT, p[0].CT);
    temp1 = 0;
    for (int i = 1; i < n; i++)
    {
        if (p[i].AT > p[temp1].CT)
        {
            printf("| Idle till %d", p[i].AT);
            ct = p[i].AT + p[i].BT;
        }
        else
            ct += p[i].BT;

        p[i].CT = ct;
        temp1 = i;
        printf("| P%d(%d) %d", p[i].Id, p[i].BT, ct);
    }
    for (int i = 0; i < n; i++)
    {
        p[i].TAT = p[i].CT - p[i].AT;
        p[i].WT = p[i].TAT - p[i].BT;
        total_TAT += p[i].TAT;
        total_WT += p[i].WT;
    }
    avg_TAT = (float)total_TAT / n;
    avg_WT = (float)total_WT / n;
    printf("\n\nID\tAT\tBT\tCT\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].Id, p[i].AT, p[i].BT, p[i].CT, p[i].WT, p[i].TAT);
    }
    printf("AVG TAT : %.3f\n", avg_TAT);
    printf("AVG WT : %.3f\n", avg_WT);
}
