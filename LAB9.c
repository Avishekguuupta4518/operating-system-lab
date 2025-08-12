//  To Write a C program to implement SCAN Disk Scheduling Algorithm.

#include <stdio.h>

int main()
{
    int t[20], atr[20], h, n, i, j, temp, k, p, sum = 0;
    int d[20]; // Difference array
    float avg;

    printf("Enter the number of tracks to be traversed: ");
    scanf("%d", &n);

    printf("Enter the position of the head: ");
    scanf("%d", &h);

    // Include the start (0) and the head position
    t[0] = 0;
    t[1] = h;

    printf("Enter the tracks: ");
    for (i = 2; i < n + 2; i++)
    {
        scanf("%d", &t[i]);
    }

    // Sort the track requests in ascending order
    for (i = 0; i < n + 2; i++)
    {
        for (j = 0; j < (n + 2) - i - 1; j++)
        {
            if (t[j] > t[j + 1])
            {
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }

    // Find the position of the head in the sorted array
    for (i = 0; i < n + 2; i++)
    {
        if (t[i] == h)
        {
            k = i; // Index of the head
            break;
        }
    }

    // Moving towards 0 (lower tracks)
    p = 0;
    for (j = k; j >= 0; j--)
    {
        atr[p++] = t[j];
    }

    // Moving towards higher tracks
    for (j = k + 1; j < n + 2; j++)
    {
        atr[p++] = t[j];
    }

    // Calculate the differences between adjacent tracks
    for (i = 0; i < p - 1; i++)
    {
        d[i] = atr[i + 1] - atr[i];
        if (d[i] < 0)
        {
            d[i] = -d[i]; // Absolute value
        }
        sum += d[i];
    }

    avg = (float)sum / n;

    // Output the results
    printf("\nTracks traversed in SCAN order:\n");
    for (i = 0; i < p; i++)
    {
        printf("%d ", atr[i]);
    }

    printf("\nTotal header movements: %d", sum);
    printf("\nAverage header movements: %.2f\n", avg);

    return 0;
}