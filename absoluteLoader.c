#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main (){
    FILE *fp;
    int i,j,length;
    char line[50],arr[10];
    fp =fopen("objectcode.txt","r");
    fscanf(fp,"%s",line);
    printf("program name is : ");
    for(int i=2;i<8;i++){
        printf("%c", line[i]);
    }
    printf("\n");
    do{
        fscanf(fp,"%s",line);
        if(line[0]=='T'){
           for(i=0;i<6;i++){
              arr[i]=line[i+2];
           }
           arr[i]='\0';
           length=atoi(arr);
           i=12;
           while(line[i] != '\0'){
              if(line[i] != '^'){
                 printf("%d : \t %c%c\n",length,line[i],line[i+1]);
                    length++;
                    i=i+2;
              }
              else{
                  i++;
              }
          }
       }
       else if(line[0]=='E'){
          break;
       }
     }
     while(!feof(fp));
     fclose(fp);
  }           
       
