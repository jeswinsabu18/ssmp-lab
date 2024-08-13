#include<stdio.h>
#include<stdlib.h>
void main(){
  int n,i,j,r,exec,c=0,k=0;
  printf("enter the number of process\n");
  scanf("%d",&n);
  printf("enter the number of resource\n");
  scanf("%d",&r);
  int avail[r],alloc[n][r],max[n][r],need[n][r],vis[n],a[n];
  printf("enter the available resource\n");
  for(i=0;i<r;i++)
     scanf("%d",&avail[i]);
  for(i=0;i<n;i++){
      vis[i]=0;
      printf("enter the max of process %d\n",i);
      for(j=0;j<r;j++)
          scanf("%d",&max[i][j]);
      printf("enter the allocation of process %d\n",i);
      for(j=0;j<r;j++)
          scanf("%d",&alloc[i][j]);  
     for(j=0;j<r;j++)
         need[i][j]=max[i][j]-alloc[i][j];
  }
  printf("  MAX\t\tALLOCATION\t NEED\n");
  for(i=0;i<n;i++){
      for(j=0;j<r;j++)
          printf("%d  ",max[i][j]);
      printf("\t");
      for(j=0;j<r;j++)
          printf("%d  ",alloc[i][j]); 
       printf("\t");
       for(j=0;j<r;j++)
           printf("%d  ",need[i][j]); 
       printf("\n");
  }
  while(c<n){
    int flag=0;
    for(i=0;i<n;i++){
      exec=0;
      for(j=0;j<r;j++){
         if(need[i][j]<=avail[j])
            exec++;
       }
       if(exec==r&&vis[i]==0){
          for(j=0;j<r;j++)
             avail[j]+=alloc[i][j];
          c++;
          vis[i]=1;
          flag=1;
          a[k++]=i;
       }
     }
     if(flag==0){
       printf("no safe sequence\n");
       exit(0);
     }
  }
  printf("safe sequence:\n");
  printf("<");
  for(i=0;i<n;i++)
     printf("p%d  ",a[i]);
  printf(">\n");
}
  
          
          
  
  
  
  
  
  
  
  
  
  
  
  
  
