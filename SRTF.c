#include<stdio.h>
#define MAX 9999
//int bt[ ],at[ ],rt[ ],wt[ ],tt[ ],p[ ],completed[ ],end_time[ ];
int shortest(int n,int at[],int rt[],int time,int completed[])
{
    int index=-1;
    int least=MAX;
    for(int i=0;i<n;i++)
    {
        if(!completed[i]&&at[i]<=time&&rt[i]<least)
        {
            least=rt[i];
            index=i;
        }
    }
    return index;
}
 main(){
      printf("\t\t\t***********Shortest Remaining Time First Scheduling***********\t\t\t\n");
       int n,i,j,pos=0,total=0;
    float awt=0,att=0;
    printf("enter number of processes:\n");
    scanf("%d",&n);
    int bt[n],at[n],rt[n],wt[n],tt[n],p[n],completed[n],end_time[n];
    printf("enter the burst time and arrival time of processes\n");
    for(i=0;i<n;i++){
        printf("Enter the burst time of P%d: ",i+1);
        scanf("%d",&bt[i]);
        rt[i]=bt[i];
        printf("Enter the arrival time of P%d: ",i+1);
        scanf("%d",&at[i]);
         p[i]=i+1;
         completed[i]=0;
    }
    int job=-1;
    i=0;
    while(!completed[i])
    {
        job=shortest(n,at,rt,total,completed);
        if(job==-1)
        {
            total++;
            continue;
        }
        total++;
        rt[job]-=1;

        if(rt[job]==0)
        {
            end_time[job]=total;
            tt[job]=end_time[job]-at[job];
            wt[job]=tt[job]-bt[job];
            completed[job]=1;
        }
    }
     printf("Process\tBurst Time\tArrival Time\tWaiting Time\tService Time \tTurn around Time \n");
    for(i=0;i<n;i++){
             tt[i]=bt[i]+wt[i];
            awt+=wt[i];
            att+=tt[i];
             printf("p%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i],bt[i],at[i],wt[i],end_time[i],tt[i]);
    }
     awt/=n;
    att/=n;
    printf("Average Waiting Time : %f\nAverage Turn Around Time : %f\n",awt,att);


 }
