#include<stdio.h>
#define MAX 9999
main()
{
     int n,i,j,t,pos,min,min_pos,c;
    float awt=0,att=0;
    printf("enter the number of processes to be executed\n");
    scanf("%d",&n);
    int p[n],bt[n],at[n],wt[n],tt[n],ct[n],temp[n],rt[n],priority[n];
    for(i=0;i<n;i++){
       printf("Enter the burst time of P%d: ",i+1);
        scanf("%d",&bt[i]);
        rt[i]=bt[i];
          printf("Enter the arrival time of P%d: ",i+1);
        scanf("%d",&at[i]);
        printf("Enter the priority of P%d: ",i+1);
        scanf("%d",&priority[i]);
        temp[i]=priority[i];
         p[i]=i+1;
}
int remaining=n;
 for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(at[j]<at[pos])
                pos=j;
        }
        t=at[i];
        at[i]=at[pos];
        at[pos]=t;

        t=bt[i];
        bt[i]=bt[pos];
        bt[pos]=t;

        t=p[i];
        p[i]=p[pos];
        p[pos]=t;

        t=priority[i];
        priority[i]=priority[pos];
        priority[pos]=t;

    }
    int rem=n;
    min=temp[0];min_pos=0;
    for(j=0;j<n&&at[j]<at[0];j++)
    {
        if(temp[j]<min)
        {
            min=temp[j];
            min_pos=j;
        }
    }
    i=min_pos;
    c=ct[i]=at[i]+1;
    rt[i]--;
    if(rt[i]==0)
    {
        temp[i]=MAX;
        remaining--;
    }
    while(remaining>0)
    {
        min=temp[0];
        min_pos=0;
        for(j=0;j<n&&at[j]<=c;j++)
            if(temp[j]<min)
        {
            min=temp[j];
            min_pos=j;
        }
        i=min_pos;
        ct[i]=c=c+1;
        rt[i]--;
        if(rt[i]==0)
        {
            temp[i]=MAX;
            remaining--;
        }
    }
     printf("Process\tBurst Time\tArrival Time\tPriority\tWaiting Time\tTurn around Time \n");
      for(i=0;i<n;i++){
                 tt[i]=ct[i]-at[i];
                 att+=tt[i];
                 wt[i]=tt[i]-bt[i];
                 awt+=wt[i];
                         printf("p%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i],bt[i],at[i],priority[i],wt[i],tt[i]);
      }
      awt=(float)awt/n;
att=(float)att/n;
printf("Average Waiting Time : %f\nAverage Turn Around Time : %f\n",awt,att);

}
