#include<stdio.h>
 int main()
{
    int i,j,n,total=0,pos,temp;
    float awt=0,att=0;
    printf("Enter number of process:");
    scanf("%d",&n);
    int bt[n],p[n],wt[n],tt[n];
    printf("\nEnter Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;
    }
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }

        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;

        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }

    wt[0]=0;


    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];

        total+=wt[i];
    }

    awt=(float)total/n;
    total=0;

    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tt[i]=bt[i]+wt[i];
        total+=tt[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tt[i]);
    }

    att=(float)total/n;
    printf("\nAverage Waiting Time=%f",awt);
    printf("\nAverage Turnaround Time=%f\n",att);
}
