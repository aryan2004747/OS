#include <stdio.h>

int main(){
    int n = 5;
    int at[] = {0, 1, 2, 3, 4};
    int bt[] = {5, 7, 6, 2, 4};
    int ct[5], tat[5], wt[5];
    float avg_tat = 0, avg_wt = 0;

    // Completion Time (FCFS)
    ct[0] = at[0] + bt[0];

    for(int i = 1; i < 5; i++) {
        if(ct[i-1] <= at[i])
            ct[i] = at[i-1] + bt[i];
        else
            ct[i] = ct[i-1] + bt[i];
    }

    // TAT and WT calculation
    for(int i = 0; i < 5; i++){
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        avg_tat += tat[i];
        avg_wt += wt[i];
    }
    printf("PID\tAt\tBt\tCt\tTAT\tWt\n");
    for(int i=0; i<n; i++){
    printf("p%d\t%d\t%d\t%d\t%d\t%d\n", at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("\nAverage TAT=%.2f", avg_tat);
    printf("\nAverage WT=%.2f", avg_wt);

    return 0;
    
}


