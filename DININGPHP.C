#include <stdio.h>

int state[5];

void takeFork(int p)
{
    if(state[p] == 0)
    {
        state[p] = 1;
        printf("Philosopher %d is Eating\n", p + 1);
    }
    else
    {
        printf("Philosopher %d is already Eating\n", p + 1);
    }
}

void putFork(int p)
{
    if(state[p] == 1)
    {
        state[p] = 0;
        printf("Philosopher %d is Thinking\n", p + 1);
    }
    else
    {
        printf("Philosopher %d is already Thinking\n", p + 1);
    }
}

int main()
{
    int choice, p;

    while(1)
    {
        printf("\n1. Take Fork");
        printf("\n2. Put Fork");
        printf("\n3. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:

                printf("Enter Philosopher Number (1-5): ");
                scanf("%d", &p);

                takeFork(p - 1);

                break;

            case 2:

                printf("Enter Philosopher Number (1-5): ");
                scanf("%d", &p);

                putFork(p - 1);

                break;

            case 3:

                return 0;

            default:

                printf("Invalid Choice\n");
        }
    }
}