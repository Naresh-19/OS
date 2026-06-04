#include <stdio.h>

struct Process
{
    int pid;
    int bt;
    int type;
};

void fcfs(struct Process p[], int n)
{
    int wt[n], tat[n];

    wt[0] = 0;

    for(int i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + p[i - 1].bt;
    }

    for(int i = 0; i < n; i++)
    {
        tat[i] = wt[i] + p[i].bt;
    }

    printf("\nPID\tBT\tWT\tTAT\n");

    for(int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].bt,
               wt[i],
               tat[i]);
    }
}

int main()
{
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process system[n], user[n];

    int sysCount = 0;
    int userCount = 0;

    for(int i = 0; i < n; i++)
    {
        struct Process temp;

        temp.pid = i + 1;

        printf("\nEnter burst time for P%d: ", temp.pid);
        scanf("%d", &temp.bt);

        printf("Enter type (0-System, 1-User): ");
        scanf("%d", &temp.type);

        if(temp.type == 0)
        {
            system[sysCount++] = temp;
        }
        else
        {
            user[userCount++] = temp;
        }
    }

    if(sysCount > 0)
    {
        printf("\nSystem Queue:\n");
        fcfs(system, sysCount);
    }

    if(userCount > 0)
    {
        printf("\nUser Queue:\n");
        fcfs(user, userCount);
    }

    return 0;
}