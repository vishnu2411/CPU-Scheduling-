 #include<stdio.h>
 main(){
     printf("\t\t\t***********Shortest Job First with Arrival Time***********\t\t\t\n");
       int n,i,j,temp=0,temp1=0,pos=0,total=0;
    float awt=0,att=0;
    printf("enter number of processes:\n");
    scanf("%d",&n);
    int bt[n],at[n],st[n],wt[n],tt[n],p[n];
    printf("enter the burst time and arrival time of processes\n");
    for(i=0;i<n;i++){
        printf("Enter the burst time of P%d: ",i+1);
        scanf("%d",&bt[i]);
        printf("Enter the arrival time of P%d: ",i+1);
        scanf("%d",&at[i]);
         p[i]=i+1;
    }
      for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(at[j]<at[pos])
                pos=j;
        }

        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;

        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;

        temp1=at[i];
        at[i]=at[pos];
        at[pos]=temp1;

    }

      for(i=1;i<n;i++)
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

        temp1=at[i];
        at[i]=at[pos];
        at[pos]=temp1;

    }
     st[0]=0;
    for(i=1;i<n;i++)
    {
        st[i]=0;
        for(j=0;j<i;j++){
            st[i]+=bt[j];
        }
    }

    for(i=0;i<n;i++)
    {
        wt[i]=st[i]-at[i];
    }

    printf("Process\tBurst Time\tArrival Time\tWaiting Time\tService Time \tTurn around Time \n");
    for(i=0;i<n;i++){
            tt[i]=bt[i]+wt[i];
            awt+=wt[i];
            att+=tt[i];
        printf("p%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i],bt[i],at[i],wt[i],st[i],tt[i]);
    }
    awt/=n;
    att/=n;
    printf("Average Waiting Time : %f\nAverage Turn Around Time : %f\n",awt,att);


  }
