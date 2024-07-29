#include<stdio.h>
#include<stdlib.h>
void main(){
  int ch=1,c;
  while(ch==1){
    printf("\nenter the choice\n 1)FCFS 2)sjf 3)priority 4)Round Robin 5)exit \n");
    scanf("%d",&c);
    switch(c){
       case 1:{
        int i,n;
  float avgwt=0,avgtat=0;
  printf("enter the number of process\n");
  scanf("%d",&n);
  int pid[n],bt[n],wt[n],tat[n];
     printf("enter the process id amd burst time of process\n");
  for(i=0;i<n;i++){
     scanf("%d%d",&pid[i],&bt[i]);
  }
  wt[0]=0;
  tat[0]=bt[0];
 
   for(i=1;i<n;i++){
       wt[i]=wt[i-1]+bt[i-1];
       tat[i]=tat[i-1]+bt[i];
       avgwt=avgwt+wt[i];
       avgtat=avgtat+tat[i];
   }
    avgtat=avgtat+tat[0];
    printf("GANT CHART:\n");
    for(i=0;i<n;i++)
       printf("\tP%d",pid[i]);
    printf("\n");
     for(i=0;i<n;i++)
        printf("     %d\t",wt[i]);
     printf("   %d",tat[n-1]);
     printf("\n");
   printf("PID\tBT\tWT\tTAT\n");
    for(i=0;i<n;i++){
    printf("%d\t%d\t%d\t%d\n",pid[i],bt[i],wt[i],tat[i]);
    }
    printf("total waiting time=%f\n",avgwt);
    printf("total turn around time=%f\n",avgtat);
    printf("Average waiting time=%f\n",avgwt/n);
    printf("Average turn around time=%f\n",avgtat/n);
    break;
 }
        case 2:{
        int i,n,j,temp;
  float avgwt=0,avgtat=0;
  printf("enter the number of process\n");
  scanf("%d",&n);
  int pid[n],bt[n],wt[n],tat[n];
  printf("enter the process id amd burst time of process\n");
  for(i=0;i<n;i++){
     scanf("%d%d",&pid[i],&bt[i]);
  }
   for(i=0;i<n;i++){
     for(j=i+1;j<n;j++){
       if(bt[i]>bt[j]){
          temp=bt[i];
          bt[i]=bt[j];
          bt[j]=temp;
           temp=pid[i];
          pid[i]=pid[j];
          pid[j]=temp;
          }
        }
    }
  wt[0]=0;
  tat[0]=bt[0];
 
   for(i=1;i<n;i++){
       wt[i]=wt[i-1]+bt[i-1];
       tat[i]=tat[i-1]+bt[i];
       avgwt=avgwt+wt[i];
       avgtat=avgtat+tat[i];
   }
    avgtat=avgtat+tat[0];
    printf("GANT CHART:\n");
    for(i=0;i<n;i++)
       printf("\tP%d",pid[i]);
    printf("\n");
     for(i=0;i<n;i++)
        printf("     %d\t",wt[i]);
     printf("   %d",tat[n-1]);
     printf("\n");
     
   printf("PID\tBT\tWT\tTAT\n");
    for(i=0;i<n;i++){
    printf("%d\t%d\t%d\t%d\n",pid[i],bt[i],wt[i],tat[i]);
    }
    printf("total waiting time=%f\n",avgwt);
    printf("total turn around time=%f\n",avgtat);
    printf("Average waiting time=%f\n",avgwt/n);
    printf("Average turn around time=%f\n",avgtat/n);
    break;
 }
    case 3:{
        int i,n,j,temp;
  float avgwt=0,avgtat=0;
  printf("enter the number of process\n");
  scanf("%d",&n);
  int pid[n],bt[n],wt[n],tat[n],pri[n];
     printf("enter the process id ,burst time and priority of process\n");
  for(i=0;i<n;i++){
     scanf("%d%d%d",&pid[i],&bt[i],&pri[i]);
  }
   for(i=0;i<n;i++){
     for(j=i+1;j<n;j++){
       if(pri[i]>pri[j]){
          temp=bt[i];
          bt[i]=bt[j];
          bt[j]=temp;
          temp=pri[i];
          pri[i]=pri[j];
          pri[j]=temp;
          temp=pid[i];
          pid[i]=pid[j];
          pid[j]=temp;
          }
        }
    }
  wt[0]=0;
  tat[0]=bt[0];
 
   for(i=1;i<n;i++){
       wt[i]=wt[i-1]+bt[i-1];
       tat[i]=tat[i-1]+bt[i];
       avgwt=avgwt+wt[i];
       avgtat=avgtat+tat[i];
   }
    avgtat=avgtat+tat[0];
    printf("GANT CHART:\n");
    for(i=0;i<n;i++)
       printf("\tP%d",pid[i]);
    printf("\n");
     for(i=0;i<n;i++)
        printf("     %d\t",wt[i]);
     printf("   %d",tat[n-1]);
     printf("\n");
     
   printf("PID\tBT\tWT\tTAT\tpriority\n");
    for(i=0;i<n;i++){
    printf("%d\t%d\t%d\t%d\t%d\n",pid[i],bt[i],wt[i],tat[i],pri[i]);
    }
    printf("total waiting time=%f\n",avgwt);
    printf("total turn around time=%f\n",avgtat);
    printf("Average waiting time=%f\n",avgwt/n);
    printf("Average turn around time=%f\n",avgtat/n);
    break;
 }
 case 4:{
      int i,limit,tq,total=0,flag=0;
float avgwt=0,avgtat=0;
printf("enter the no of process\n");
scanf("%d",&limit);
int pid[limit],bt[limit],wt[limit],tat[limit],rt[limit],prt[30],f=1;
printf("enter the process id and burst time  of process \n");
for(i=0;i<limit;i++){
  scanf("%d%d",&pid[i],&bt[i]);
  rt[i]=bt[i];
}
printf("enter the time quantum\n");
scanf("%d",&tq);
printf("Gant chart:\n");
while(flag!=limit){
 for(i=0;i<limit;i++){
   if(rt[i]>tq){
     total+=tq;
     printf("\tP%d",pid[i]);
     prt[f]=total;
     f++;
     rt[i]=rt[i]-tq;
    }
    else if(rt[i]==0){
    continue;
    }
    else{
     total+=rt[i];
     rt[i]=0;
     printf("\tP%d",pid[i]);
    prt[f]=total;
     f++;
     tat[i]=total;
     wt[i]=total-bt[i];
      flag++;
    }
  }
}
printf("\n");
prt[0]=0;
for(i=0;i<f;i++)
printf("    %d\t",prt[i]);

printf("\n\n");
printf("pid\tBT\tWT\tTAT\t\n");
for(i=0;i<limit;i++){
  printf("%d\t%d\t%d\t%d\t\n",pid[i],bt[i],wt[i],tat[i]);
  avgwt+=wt[i];
  avgtat+=tat[i];
  }
printf("total waiting time=%f\n",avgwt);
printf("total turn around time=%f\n",avgtat);
printf("Average WT=%f\n",avgwt/limit);
printf("Average TAT=%f\n",avgtat/limit);
break;
}

 case 5:
        exit(0);     
  }
}
}
