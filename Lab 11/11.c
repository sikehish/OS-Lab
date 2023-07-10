#include <stdio.h>

struct process {
        int ID, AT, BT, WT, TT, RT, CT;
        float ntt;
}

p[10];
int n;
int q[10]; // queue
int front = -1, rear = -1;

void enqueue(int i) {
        if (rear == 10)
                printf("overflow");
        rear++;
        q[rear] = i;
        if (front == -1)
                front = 0;
}

int dequeue() {
        if (front == -1)
                printf("underflow");
        int temp = q[front];
        if (front == rear)
                front = rear = -1;
        else
                front++;
        return temp;
}
int isInQueue(int i) {
        int k;
        for (k = front; k <= rear; k++) {
                if (q[k] == i)
                        return 1;
        }
        return 0;
}
void soRTByArrival() {
        struct process temp;
        int i, j;
        for (i = 0; i < n - 1; i++)
                for (j = i + 1; j < n; j++) {
                        if (p[i].AT > p[j].AT) {
                                temp = p[i];
                                p[i] = p[j];
                                p[j] = temp;
                        }
                }
}

void main() {
        int i, j, time = 0, sum_BT = 0, tq;
        char c;
        float avgWT = 0;
        printf("Enter no of processes:");
        scanf("%d", & n);
        for (i = 0; i < n; i++) {
                p[i].ID = i + 1;
                printf("\nEnter the arrival time and burst time of process %d: ", p[i].ID);
                scanf("%d%d", & p[i].AT, & p[i].BT);
                p[i].RT = p[i].BT;
                p[i].CT = 0;
                sum_BT += p[i].BT;
        }

        printf("\nEnter the time quantum:");
        scanf("%d", & tq);

        soRTByArrival();
        enqueue(0);
        printf("Process execution order: ");
        for (time = p[0].AT; time < sum_BT;) {
                i = dequeue();

                if (p[i].RT <= tq) {

                        time += p[i].RT;
                        p[i].RT = 0;
                        p[i].CT = 1;
                        printf(" P%d ", p[i].ID);
                        p[i].WT = time - p[i].AT - p[i].BT;
                        p[i].TT = time - p[i].AT;
                        p[i].ntt = ((float) p[i].TT / p[i].BT);
                        for (j = 0; j < n; j++) {
                                if (p[j].AT <= time && p[j].CT != 1 && isInQueue(j) != 1) {
                                        enqueue(j);
                                }
                        }
                } else {
                        time += tq;
                        p[i].RT -= tq;
                        printf(" P%d ", p[i].ID);
                        for (j = 0; j < n; j++) {
                                if (p[j].AT <= time && p[j].CT != 1 && i != j && isInQueue(j) != 1) {
                                        enqueue(j);
                                }
                        }
                        enqueue(i);
                }
        }

        printf("\nID\tArrival Time\tBurst Time\tWaiting Time\tTurnAround Time\t Normalized TT");
        for (i = 0; i < n; i++) {
                avgWT += p[i].WT;
                printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%f", p[i].ID, p[i].AT, p[i].BT, p[i].WT, p[i].TT, p[i].ntt);
        }
        printf("\nAverage waiting time:%f\n", avgWT / n);
}
