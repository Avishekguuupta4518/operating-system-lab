//  To write a program to stimulate the CPU scheduling algorithm Shortest job first (Non- Preemption)  

#include <stdio.h>
#include <conio.h>
int main()
{
    int p[20], bt[20], wt[20], tat[20], i, k, n, temp;
    float wtavg, tatavg;
    // clrscr();
    printf("\nEnter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        p[i] = i; // Assign process ID
        printf("Enter Burst Time for Process %d: ", i);
        scanf("%d", &bt[i]);
    }
    // Sorting the processes by burst time
    for (i = 0; i < n; i++)
    {
        for (k = i + 1; k < n; k++)
        {
            if (bt[i] > bt[k])
            {
                // Swap burst times
                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;
                // Swap process IDs
                temp = p[i];
                p[i] = p[k];
                p[k] = temp;
            }
        }
    }
    wt[0] = 0;
    wtavg = 0;
    tat[0] = bt[0];
    tatavg = bt[0];
    // Calculate waiting time and turnaround time
    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }
    // Display results
    printf("\n\tPROCESS\t\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for (i = 0; i < n; i++)
    {
        printf("\tP%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }
    printf("\nAverage Waiting Time: %f", wtavg / n);
    printf("\nAverage Turnaround Time: %f", tatavg / n);
    // getch();
    return 0;
}