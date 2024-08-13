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
  printf("enter the direction 1 for high and 0 for low\n");
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
         dist=abs(a[i]-head);
         printf("Head movement from %d to %d=%d\n",head,a[i],dist);
       seektime+=dist;
         head=a[i];
     }
     dist=abs(size-a[n-1]-1);
     seektime+=dist;
     printf("Head movement from %d to %d=%d\n",a[n-1],size-1,dist);
     if(a[0]<head){
         dist=abs(size-a[index-1]-1);
         seektime+=dist;
         printf("Head movement from %d to %d=%d\n",size-1,a[index-1],dist);
         head=a[index-1];
         for(i=index-2;i>=0;i--){
         dist=abs(a[i]-head);
         printf("Head movement from %d to %d=%d\n",head,a[i],dist);
         seektime+=dist;
         head=a[i];
       }
     }
    }
 else{
       for(i=index-1;i>=0;i--){
       dist=abs(a[i]-head);
         printf("Head movement from %d to %d=%d\n",head,a[i],dist);
       seektime+=dist;
         head=a[i];
       }
       seektime+=a[0]-0;
        printf("Head movement from %d to %d=%d\n",a[0],0,a[0]);
        head=0;
        if(a[n-1]>a[index]){
          dist=abs(a[index]-head);
          seektime+=dist;
          printf("Head movement from %d to %d=%d\n",head,a[index],dist);
          head=a[index];
          for(i=index+1;i<n;i++){
              dist=abs(a[i]-head);
              printf("Head movement from %d to %d=%d\n",head,a[i],dist);
              seektime+=dist;
              head=a[i];
           }
         }
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
         dist=abs(a[i]-head);
         printf("Head movement from %d to %d=%d\n",head,a[i],dist);
       seektime+=dist;
         head=a[i];
     }
     dist=abs(size-a[n-1]-1);
     seektime+=dist;
     printf("Head movement from %d to %d=%d\n",a[n-1],size-1,dist);
     seektime+=size-1;
      printf("Head movement from %d to %d=%d\n",size-1,0,size-1);
     head=0;
     for(i=0;i<index;i++){
         dist=abs(a[i]-head);
         printf("Head movement from %d to %d=%d\n",head,a[i],dist);
       seektime+=dist;
         head=a[i];
     }
    }
 else{
       for(i=index-1;i>=0;i--){
       dist=abs(a[i]-head);
         printf("Head movement from %d to %d=%d\n",head,a[i],dist);
       seektime+=dist;
         head=a[i];
       }
       seektime+=a[0]-0;
        printf("Head movement from %d to %d=%d\n",a[0],0,a[0]);
        seektime+=size-1;
        printf("Head movement from %d to %d=%d\n",0,size-1,size-1);
        head=size-1;
        for(i=n-1;i>=index;i--){
            dist=abs(a[i]-head);
         printf("Head movement from %d to %d=%d\n",head,a[i],dist);
       seektime+=dist;
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
