//  To Write a  program to implement bankers algorithm for deadlock avoidance.

#include <stdio.h>
#include <conio.h>
#include <string.h>
void main()
{
    int alloc[10][10], max[10][10];
    int avail[10], work[10], total[10];
    int i, j, k, n, m, need[10][10];
    int count = 0, c = 0;
    char finish[10];
    // clrscr();  // Clear screen (for old compilers)
    // Input number of processes and resources
    printf("Enter the number of processes and resources: ");
    scanf("%d%d", &n, &m);

    // Initialize finish array to 'n' (not finished)
    for (i = 0; i < n; i++)
        finish[i] = 'n';

    // Input the claim matrix (Max matrix)
    printf("Enter the claim matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    // Input the allocation matrix
    printf("Enter the allocation matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    // Input the resource vector
    printf("Resource vector: ");
    for (i = 0; i < m; i++)
        scanf("%d", &total[i]);

    // Initialize avail array (available resources)
    for (i = 0; i < m; i++)
        avail[i] = total[i];

    // Calculate the available resources by subtracting allocated resources
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            avail[j] -= alloc[i][j];

    // Initialize work array with available resources
    for (i = 0; i < m; i++)
        work[i] = avail[i];

    // Calculate the need matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

// Process execution loop
A:
    for (i = 0; i < n; i++)
    {
        c = 0;
        // Check if all the needs can be satisfied with available resources
        for (j = 0; j < m; j++)
        {
            if ((need[i][j] <= work[j]) && (finish[i] == 'n'))
                c++;
        }

        // If all needs are met, allocate resources to the process
        if (c == m)
        {
            printf("All the resources can be allocated to Process %d\n", i + 1);
            printf("\nAvailable resources are: ");
            for (k = 0; k < m; k++)
            {
                work[k] += alloc[i][k]; // Add allocated resources to work
                printf("%4d", work[k]);
            }
            printf("\n");

            finish[i] = 'y'; // Mark the process as finished
            printf("Process %d executed? %c \n", i + 1, finish[i]);
            count++;
        }
    }

    // If not all processes are finished, continue checking
    if (count != n)
        goto A; // Repeat the process for unfinished ones
    else
        printf("\nSystem is in safe mode");

    printf("\nThe given state is safe state");
    // getch();  // Wait for user input before closing (for old compilers)
}
