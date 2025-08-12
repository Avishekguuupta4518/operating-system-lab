//  To Write a C program to implement CSCAN Disk Scheduling Algorithm.
#include <stdio.h>

int main()
{
    int t[20], atr[20], d[20], h, tot, n, i, j, temp, p, sum = 0;
    float avg;

    printf("Enter the number of tracks to be traversed: ");
    scanf("%d", &n);

    printf("Enter the position of the head: ");
    scanf("%d", &h);

    printf("Enter the total number of tracks: ");
    scanf("%d", &tot);

    // Including head position and the extreme ends (0 and tot-1)
    t[0] = 0;
    t[1] = h;
    t[2] = tot - 1;

    printf("Enter the track requests: ");
    for (i = 3; i < n + 3; i++)
    {
        scanf("%d", &t[i]);
    }

    // Sort the track requests in ascending order
    for (i = 0; i < n + 3; i++)
    {
        for (j = 0; j < (n + 3) - i - 1; j++)
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
    int k = 0;
    for (i = 0; i < n + 3; i++)
    {
        if (t[i] == h)
        {
            k = i;
            break;
        }
    }

    // Traverse from the head towards the highest track, then wrap around to the lowest track
    p = 0;
    for (i = k; i < n + 3; i++)
    {
        atr[p++] = t[i];
    }
    for (i = 0; i < k; i++)
    {
        atr[p++] = t[i];
    }

    // Calculate the header movements
    for (i = 0; i < p - 1; i++)
    {
        d[i] = atr[i + 1] - atr[i];
        if (d[i] < 0)
        {
            d[i] = -d[i];
        }
        sum += d[i];
    }

    avg = (float)sum / n;

    // Output the results
    printf("\nTracks traversed in C-SCAN order:\n");
    for (i = 0; i < p; i++)
    {
        printf("%d ", atr[i]);
    }

    printf("\nTotal header movements: %d", sum);
    printf("\nAverage header movements: %.2f\n", avg);

    return 0;
}