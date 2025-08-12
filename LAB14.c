//  To Write a program to implement deadlock prevention technique.

#include <stdio.h>
#include <conio.h>

void main()
{
    char job[10][10];             // Array to store job names
    int time[10];                 // Array to store time/resource requirements for each job
    int avail, tem[10], temp[10]; // temp arrays for sorting
    int safe[10];                 // Array to store the safe sequence of jobs
    int ind = 1, i, j, q, n, t;   // Variables for indexing and loop control
    // clrscr();  // Clear screen (for old compilers)

    // Input the number of jobs
    printf("Enter no of jobs: ");
    scanf("%d", &n);

    // Input job names and their time/resource requirements
    for (i = 0; i < n; i++)
    {
        printf("Enter name and time: ");
        scanf("%s %d", &job[i], &time[i]);
    }

    // Input the available resources
    printf("Enter the available resources: ");
    scanf("%d", &avail);

    // Copy time values to temp array for sorting
    for (i = 0; i < n; i++)
    {
        temp[i] = time[i];
        tem[i] = i;
    }

    // Sorting the jobs based on their resource requirement (time)
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (temp[i] > temp[j])
            {
                // Swap time values
                t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;

                // Swap the indices of jobs to keep track of the correct sequence
                t = tem[i];
                tem[i] = tem[j];
                tem[j] = t;
            }
        }
    }

    // Check if each job can be safely executed
    for (i = 0; i < n; i++)
    {
        q = tem[i];
        if (time[q] <= avail)
        {
            safe[ind] = tem[i];            // Add job to safe sequence
            avail = avail - time[q];       // Deduct the resources allocated to the job
            printf("%s ", job[safe[ind]]); // Print the job name
            ind++;
        }
        else
        {
            // If any job cannot be executed due to resource constraints, print an error
            printf("No safe sequence\n");
        }
    }

    // Output the safe sequence of jobs
    printf("Safe sequence is: ");
    for (i = 1; i < ind; i++)
    {
        printf("%s %d, ", job[safe[i]], time[safe[i]]);
    }

    // getch();  // Wait for user input before closing (for old compilers)
}