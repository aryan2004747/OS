#include <stdio.h>

int main(){
    int PID[5] = {0, 1, 2, 3, 4};
    int AT[5] = {0, 0, 0, 0, 0};
    int BT1[5] = {5, 7, 6, 8, 5};
    int IO[5] = {2, 2, 3, 1, 2};
    int BT2[5] = {3, 2, 4, 2, 5};
    int PCT[5];
    int TAT[5];
    int CT[5];
    int n=sizeof(PID)/sizeof(int);
    PCT[0] = AT[0] + BT1[0] + IO[0];
    for(int i=1; i<5; i++) {
    PCT[i] = PCT[i-1] + BT1[i] + IO[i];  
    }
    CT[0] = PCT[4] + BT2[0];
    for(int i=1; i<5; i++) {
    CT[i]= CT[i-1] + BT2[i]; 
    }
    // for TAT.....
    int SumTAT=0;
    printf("TAT all....");
    for(int i=0; i<5; i++){
    TAT[i] = CT[i]-AT[i];
    SumTAT=SumTAT+TAT[i];
    }
    printf("%d", SumTAT);
    // for Average TAT
    int ATAT;
     printf("Average TAT:");
     ATAT=SumTAT/n;
     printf("%d", ATAT);

    //  For Wt....
    int Wt[5];
    int AWT;
    int SumWt=0;
    for(int i=0; i<5; i++){
    Wt[i]=TAT[i] - (BT1[i]+BT2[i]);
    SumWt=SumWt+Wt[i];    
    }

    // for Average Wt....
    printf("\n Average waiting time:");
    AWT=SumWt/n;
    printf("%d", AWT);

    printf("PID\tAt\tBt1\tIO\tCt\tTAT\tWt\n");
    for(int i=0; i<5; i++){
    printf("p%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",i,AT[i],BT1[i],IO[i],BT2[i],CT[i],TAT[i],Wt[i]);
    }

    printf("sum of all TAT %d\n", SumTAT);
    printf("sum of all Wt %d\n", SumWt);
}
