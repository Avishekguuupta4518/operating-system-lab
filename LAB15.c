#include <stdio.h>
#include <conio.h>
int main()
{
    int ms, bs, nob, ef, n, mp[10], tif = 0, i, p = 0; // Variables for memory size, block size, number of processes, etc.

    // Input total memory size (in Bytes)
    printf("Enter the total memory available (in Bytes) -- ");
    scanf("%d", &ms);

    // Input block size (in Bytes)
    printf("Enter the block size (in Bytes) -- ");
    scanf("%d", &bs);

    // Calculate the number of blocks available in memory
    nob = ms / bs;

    // Calculate external fragmentation (remaining memory after dividing into blocks)
    ef = ms - nob * bs;

    // Input number of processes
    printf("\nEnter the number of processes -- ");
    scanf("%d", &n);

    // Input memory requirements for each process
    for (i = 0; i < n; i++)
    {
        printf("Enter memory required for process %d (in Bytes)-- ", i + 1);
        scanf("%d", &mp[i]);
    }

    // Output the number of blocks available
    printf("\nNo. of Blocks available in memory--%d", nob);
    printf("\n\nPROCESS\tMEMORY REQUIRED\tALLOCATED\tINTERNAL FRAGMENTATION"); 
     
    // Try allocating memory for each process 
    for(i = 0; i < n && p < nob; i++)   
    {
        printf("\n %d\t\t%d", i + 1, mp[i]); // Print process number and memory requirement

        // If process memory exceeds block size, allocation is not possible
        if (mp[i] > bs)
            printf("\t\tNO\t\t---");
        else
        {
            // If memory can be allocated, mark it as YES and calculate internal fragmentation
            printf("\t\tYES\t%d", bs - mp[i]);
            tif = tif + bs - mp[i]; // Add internal fragmentation to the total
            p++;                    // Increment the number of allocated processes
        }   
    }   
    // If not all processes could be allocated memory, print a message 
    if(i < n)   
        printf("\nMemory is Full, Remaining Processes cannot be accommodated");   
     
    // Output the total internal and external fragmentation 
    printf("\n\nTotal Internal Fragmentation is %d", tif);  
    printf("\nTotal External Fragmentation is %d", ef);

    // getch();  // Wait for user input (for old compilers)
}
