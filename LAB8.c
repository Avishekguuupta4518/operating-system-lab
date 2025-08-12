//  To Write a C program to implement FCFS Disk scheduling algorithm. 

#include <stdio.h>

int main()
{
    int t[20], n, i, toh[20], tot = 0;
    float avh;

    printf("Enter the number of tracks: ");
    scanf("%d", &n);

    printf("Enter the tracks to be traversed: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &t[i]);
    }

    // Calculate differences between tracks
    for (i = 0; i < n - 1; i++)
    {
        toh[i] = t[i + 1] - t[i];
        if (toh[i] < 0)
        {
            toh[i] = -toh[i]; // Make it positive
        }
        tot += toh[i];
    }

    avh = (float)tot / (n - 1);

    printf("\nTracks traversed\tDifference between tracks\n");
    for (i = 0; i < n - 1; i++)
    {
        printf("%d -> %d\t\t%d\n", t[i], t[i + 1], toh[i]);
    }

    printf("\nTotal header movements: %d", tot);
    printf("\nAverage header movements: %.2f\n", avh);

    return 0;
}
