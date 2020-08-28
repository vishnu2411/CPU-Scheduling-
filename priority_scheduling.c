#include<stdio.h>
main()
{
    int n,i,j,temp,pos,temp1;
    float awt=0,att=0;
    printf("enter the number of processes to be executed\n");
    scanf("%d",&n);
    int p[n],bt[n],at[n],wt[n],st[n],tt[n],priority[n];
    for(i=0;i<n;i++){
       printf("Enter the burst time of P%d: ",i+1);
        scanf("%d",&bt[i]);
        printf("Enter the priority of P%d: ",i+1);
        scanf("%d",&priority[i]);
         p[i]=i+1;

    }
     for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(priority[j]<priority[pos])
                pos=j;
        }

        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;

        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;

        temp1=priority[i];
        priority[i]=priority[pos];
        priority[pos]=temp1;

    }
   wt[0]=0;
   tt[0]=att=bt[0];
    for(i=1;i<n;i++){
                 wt[i]=wt[i-1]+bt[i-1];
                 tt[i]=tt[i-1]+bt[i];

             }

       printf("Process\tBurst Time\tPriority\tWaiting Time\tTurn around Time \n");
    for(i=0;i<n;i++){
             tt[i]=bt[i]+wt[i];
            awt+=wt[i];
            att+=tt[i];
              printf("p%d\t%d\t\t%d\t\t%d\t\t%d\n",p[i],bt[i],priority[i],wt[i],tt[i]);
}
awt=(float)awt/n;
att=(float)att/n;
printf("Average Waiting Time : %f\nAverage Turn Around Time : %f\n",awt,att);

}
