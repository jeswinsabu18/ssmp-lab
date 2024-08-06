#include<stdio.h>
#include<stdlib.h>
void main(){
int ch=1,c;
while(ch==1){
   printf("enter the choice 1)FCFS 2)scan 3)cscan 4) exit\n");
   scanf("%d",&c);
   switch(c){
       case 1:{
               int n,head,i,dist,seektime=0;
  printf("emter the no of requests\n");
  scanf("%d",&n);
  int a[n];
  printf("enter the head position\n");
  scanf("%d",&head);
  a[0]=head;
  printf("enter the request sequence\n");
  for(i=1;i<=n;i++)
      scanf("%d",&a[i]);
  printf("FCFS:\n");
  for(i=0;i<n;i++){
     dist= abs(a[i+1]-a[i]);
    printf("head movement from %d to %d=%d\n",a[i],a[i+1],dist);
     seektime+=dist;
  }
  printf("total head movement=%d\n",seektime);
  break;
}
   case 2:{
         int n,head,i,dist,seektime=0,size,move,index=0;
  printf("emter the no of requests\n");
  scanf("%d",&n);
  int a[n];
  printf("enter the head position\n");
  scanf("%d",&head);
  printf("enter the size of disk\n");
  scanf("%d",&size);
  printf("enter the request sequence\n");
  for(i=0;i<n;i++)
      scanf("%d",&a[i]);
  printf("enetr the direction 1 for high and 0 for low\n");
  scanf("%d",&move);
  for(i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
          if(a[i]>a[j]){
          int temp=a[i];
          a[i]=a[j];
          a[j]=temp;
         }
      }
  }
  while(index<n && head>=a[index])
     index++;
  if(move==1){
    seektime+=size-head-1;
    if(a[0]<head)
        seektime+=size-1-a[0];
  }
  else{
  seektime+=head;
  if(a[n-1]>head)
     seektime+=a[n-1];
  }
 printf("total head movement=%d\n",seektime);
 break;
}
case 3:{ 
int n,head,i,dist,seektime=0,size,move,index=0;
  printf("emter the no of requests\n");
  scanf("%d",&n);
  int a[n];
  printf("enter the head position\n");
  scanf("%d",&head);
  printf("enter the size of disk\n");
  scanf("%d",&size);
  printf("enter the request sequence\n");
  for(i=0;i<n;i++)
      scanf("%d",&a[i]);
  printf("enetr the direction 1 for high and 0 for low\n");
  scanf("%d",&move);
  for(i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
          if(a[i]>a[j]){
          int temp=a[i];
          a[i]=a[j];
          a[j]=temp;
         }
      }
  }
  while(index<n && head>=a[index])
     index++;
  if(move==1){
     for(i=index;i<n;i++){
         seektime+=abs(a[i]-head);
         head=a[i];
     }
     seektime+=abs(size-a[n-1]-1);
     seektime+=size-1;
     head=0;
     for(i=0;i<index;i++){
          seektime+=abs(a[i]-head);
           head=a[i];
     }
    }
 else{
       for(i=index-1;i>=0;i--){
       seektime+=abs(a[i]-head);
         head=a[i];
       }
       seektime+=a[0]-0;
        seektime+=size-1;
        head=size-1;
        for(i=n-1;i>=index;i--){
            seektime+=abs(a[i]-head);
             head=a[i];
         }
     }
   printf("total head movement=%d\n",seektime);
   break;
 }
 case 4:{
 exit(0);
 }
 }
 }
 }
