#include <stdio.h>
#define MAX_PROCESSES 10

struct Process
{
    int id;
    int burst_time;
    float remaining_time;
};

void roundRobinScheduling(struct Process processes[], int n, float quantum)
{
    int i, total_time = 0;
    for (i = 0; i < n; i++)
    {
        total_time += processes[i].burst_time;
        processes[i].remaining_time = (float)processes[i].burst_time;
    }
    printf("\nRound Robin Scheduling:\n");
    int time = 0;
    while (time < total_time)
    {
        for (i = 0; i < n; i++)
        {
            if (processes[i].remaining_time > 0)
            {
                float execute_time = (processes[i].remaining_time < quantum) ? processes[i].remaining_time : quantum;
                processes[i].remaining_time -= execute_time;
                time += execute_time;
                printf("Time %d: Process %d executes for %f units\n", time, processes[i].id, execute_time);
            }
        }
    }
    printf("\nRound Robin Scheduling completed.\n");
}

int main()
{
    int i, n;
    float quantum = 0.02;

    // Predefined burst times
    int burst_times[] = {2, 6, 8, 1, 9};
    n = sizeof(burst_times) / sizeof(burst_times[0]);

    // Input quantum time
    /*
        printf("Enter the time quantum: ");
        scanf("%f", &quantum);
    */

    // Input details of each process
    struct Process processes[MAX_PROCESSES];

    for (i = 0; i < n; i++)
    {
        processes[i].id = i + 1;
        processes[i].burst_time = burst_times[i];
    }

    if (quantum > 0 && quantum < 1)
        roundRobinScheduling(processes, n, quantum * 10);
    else
        roundRobinScheduling(processes, n, quantum);

    return 0;
}
