#include <stdio.h>

int main()
{
    int nb, np;

    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);

    int block[nb];

    printf("Enter block sizes:\n");
    for(int i = 0; i < nb; i++)
        scanf("%d", &block[i]);

    printf("Enter number of processes: ");
    scanf("%d", &np);

    int process[np];

    printf("Enter process sizes:\n");
    for(int i = 0; i < np; i++)
        scanf("%d", &process[i]);

    int choice;

    printf("\n1. First Fit");
    printf("\n2. Best Fit");
    printf("\n3. Worst Fit");
    printf("\nEnter choice: ");
    scanf("%d", &choice);

    int allocation[np];

    for(int i = 0; i < np; i++)
        allocation[i] = -1;

    int tempBlock[nb];

    for(int i = 0; i < nb; i++)
        tempBlock[i] = block[i];

    if(choice == 1)
    {
        for(int i = 0; i < np; i++)
        {
            for(int j = 0; j < nb; j++)
            {
                if(tempBlock[j] >= process[i])
                {
                    allocation[i] = j;
                    tempBlock[j] -= process[i];
                    break;
                }
            }
        }

        printf("\nFirst Fit Allocation\n");
    }
    else if(choice == 2)
    {
        for(int i = 0; i < np; i++)
        {
            int best = -1;

            for(int j = 0; j < nb; j++)
            {
                if(tempBlock[j] >= process[i])
                {
                    if(best == -1 || tempBlock[j] < tempBlock[best])
                        best = j;
                }
            }

            if(best != -1)
            {
                allocation[i] = best;
                tempBlock[best] -= process[i];
            }
        }

        printf("\nBest Fit Allocation\n");
    }
    else if(choice == 3)
    {
        for(int i = 0; i < np; i++)
        {
            int worst = -1;

            for(int j = 0; j < nb; j++)
            {
                if(tempBlock[j] >= process[i])
                {
                    if(worst == -1 || tempBlock[j] > tempBlock[worst])
                        worst = j;
                }
            }

            if(worst != -1)
            {
                allocation[i] = worst;
                tempBlock[worst] -= process[i];
            }
        }

        printf("\nWorst Fit Allocation\n");
    }
    else
    {
        printf("Invalid Choice\n");
        return 0;
    }

    printf("\nProcess\tSize\tBlock\n");

    for(int i = 0; i < np; i++)
    {
        printf("P%d\t%d\t", i + 1, process[i]);

        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}