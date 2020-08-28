#include<stdio.h>
main ()
{
    int n,i,j;
    float awt=0,att=0;
    printf("enter number of processes:\n");
    scanf("%d",&n);
    int bt[n],wt[n],tt[n];
    printf("enter the burst time of processes\n");
    for(i=0;i<n;i++){
        printf("P%d: ",i+1);
        scanf("%d",&bt[i]);
    }
       wt[0]=0;
    for(i=1;i<n;i++){
             wt[i]=0;
             for(j=0;j<i;j++){
                 wt[i]+=bt[j];
             }
             }

    printf("Process\tBurst Time\tWaiting Time\tTurn around Time \n");
    for(i=0;i<n;i++){
            tt[i]=bt[i]+wt[i];
            awt+=wt[i];
            att+=tt[i];
        printf("p%d\t%d\t\t%d\t\t%d\n",i,bt[i],wt[i],tt[i]);
    }
    awt/=n;
    att/=n;
    printf("Average Waiting Time : %f\nAverage Turn Around Time : %f\n",awt,att);
}
