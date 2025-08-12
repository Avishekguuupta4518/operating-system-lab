//  To write a c program to simulate the CPU scheduling priority algorithm.  

#include <stdio.h>
int main()
{
    int p[20], bt[20], pri[20], wt[20], tat[20], i, k, n, temp;
    float wtavg, tatavg;

    // clrscr();

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        p[i] = i; // Assign process ID
        printf("Enter the Burst Time & Priority of Process %d: ", i);
        scanf("%d %d", &bt[i], &pri[i]);
    }

    // Sorting processes by priority (lower priority value = higher priority)
    for (i = 0; i < n; i++)
    {
        for (k = i + 1; k < n; k++)
        {
            if (pri[i] > pri[k])
            {
                // Swap process ID
                temp = p[i];
                p[i] = p[k];
                p[k] = temp;

                // Swap burst time
                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;

                // Swap priority
                temp = pri[i];
                pri[i] = pri[k];
                pri[k] = temp;
            }
        }
    }

    wtavg = wt[0] = 0;
    tatavg = tat[0] = bt[0];

    // Calculate waiting time and turnaround time
    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }

    // Display results
    printf("\nPROCESS\t\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME");
    for (i = 0; i < n; i++)
    {
        printf("\n%d \t\t %d \t\t %d \t\t %d \t\t %d", p[i], pri[i], bt[i], wt[i], tat[i]);
    }
    printf("\nAverage Waiting Time is: %f", wtavg / n);
    printf("\nAverage Turnaround Time is: %f", tatavg / n);

    // getch();
    return 0;
}