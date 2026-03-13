#include <stdio.h>

struct Process {
    int pid;
    int at;
    int bt;
    int pr;
    int rt;
    int ct;
    int wt;
    int tat;
};

void nonPreemptive(struct Process p[], int n)
{
    int completed = 0, time = 0;
    int visited[20] = {0};

    while(completed < n)
    {
        int idx = -1;
        int best = 9999;

        for(int i=0;i<n;i++)
        {
            if(p[i].at <= time && !visited[i])
            {
                if(p[i].pr < best)
                {
                    best = p[i].pr;
                    idx = i;
                }
            }
        }

        if(idx != -1)
        {
            time += p[idx].bt;
            p[idx].ct = time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;

            visited[idx] = 1;
            completed++;
        }
        else
        time++;
    }

    float avgwt=0, avgtat=0;

    printf("\nPID\tAT\tBT\tPR\tCT\tWT\tTAT\n");

    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        p[i].pid,p[i].at,p[i].bt,p[i].pr,p[i].ct,p[i].wt,p[i].tat);

        avgwt += p[i].wt;
        avgtat += p[i].tat;
    }

    printf("\nAverage Waiting Time = %.2f", avgwt/n);
    printf("\nAverage Turnaround Time = %.2f\n", avgtat/n);
}

void preemptive(struct Process p[], int n)
{
    int completed = 0, time = 0;

    while(completed < n)
    {
        int idx = -1;
        int best = 9999;

        for(int i=0;i<n;i++)
        {
            if(p[i].at <= time && p[i].rt > 0)
            {
                if(p[i].pr < best)
                {
                    best = p[i].pr;
                    idx = i;
                }
            }
        }

        if(idx != -1)
        {
            p[idx].rt--;
            time++;

            if(p[idx].rt == 0)
            {
                completed++;
                p[idx].ct = time;
                p[idx].tat = p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tat - p[idx].bt;
            }
        }
        else
        time++;
    }

    float avgwt=0,avgtat=0;

    printf("\nPID\tAT\tBT\tPR\tCT\tWT\tTAT\n");

    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        p[i].pid,p[i].at,p[i].bt,p[i].pr,p[i].ct,p[i].wt,p[i].tat);

        avgwt += p[i].wt;
        avgtat += p[i].tat;
    }

    printf("\nAverage Waiting Time = %.2f", avgwt/n);
    printf("\nAverage Turnaround Time = %.2f\n", avgtat/n);
}

int main()
{
    int n, choice;

    struct Process p[20];

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        p[i].pid = i+1;

        printf("\nProcess %d\n",i+1);

        printf("Arrival Time: ");
        scanf("%d",&p[i].at);

        printf("Burst Time: ");
        scanf("%d",&p[i].bt);

        printf("Priority: ");
        scanf("%d",&p[i].pr);

        p[i].rt = p[i].bt;
    }

    printf("\n1. Non Preemptive Priority Scheduling");
    printf("\n2. Preemptive Priority Scheduling");

    printf("\nEnter choice: ");
    scanf("%d",&choice);

    if(choice == 1)
        nonPreemptive(p,n);
    else
        preemptive(p,n);

    return 0;
}
