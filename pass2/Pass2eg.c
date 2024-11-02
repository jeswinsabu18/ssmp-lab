#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main(){
FILE *intermediate,*optab,*symtab,*output,*prgmlength,*objectcode;
char opcode[20],operand[20],label[20],mnemonic[20],code[20],value[20],textRecord[70];
int locctr,start,prgmLength,length=0,textstartAddr;
optab=fopen("optab.txt","r");
intermediate=fopen("intermediate.txt","r");
symtab=fopen("symtab.txt","r");
prgmlength=fopen("prgmlength.txt","r");
objectcode=fopen("objectcode.txt","w");
output=fopen("output.txt","w");
fscanf(intermediate,"%s%s%s",label,opcode,operand);
fprintf(output,"    %-7s%-7s%-7s\n",label,opcode,operand);
if(strcmp(opcode,"START")==0){
   fscanf(prgmlength,"%d",&prgmLength);
   start=atoi(operand);
   fprintf(objectcode,"H^%s^%06d^%06d\n",label,start,prgmLength);}
 fscanf(intermediate,"%d%s%s%s",&locctr,label,opcode,operand);
 textstartAddr=locctr;
 strcpy(textRecord,"");
 while(strcmp(opcode,"END")!=0){
   char objectCode[10]="";
   fprintf(output,"%d%-7s%-7s%-7s ",locctr,label,opcode,operand);
   if(strcmp(opcode,"BYTE")==0){
     if(operand[0]=='C'&& operand[1]=='\''){
        if(strcmp(operand,"C'EOF'")==0){
            strcpy(objectCode,"454F46");
            }
        else{
            for(int i=2;i<strlen(operand)-1;i++){
                sprintf(objectCode+strlen(objectCode),"%02X",operand[i]);
                }}}

}
else if(strcmp(opcode,"WORD")==0){
  sprintf(objectCode,"%06d",atoi(operand));
  }else if(strcmp(opcode,"RESB")==0){
  }
  else if(strcmp(opcode,"RESW")==0){
  }else{
  rewind(optab);
while(fscanf(optab,"%s%s",mnemonic,code)!=EOF){
  if(strcmp(opcode,mnemonic)==0){
     strcpy(objectCode,code);
     break;}}
    rewind(symtab);
while(fscanf(symtab,"%s%s",label,value)!=EOF){
  if(strcmp(operand,label)==0){
     sprintf(objectCode+strlen(objectCode),"%04d",atoi(value));
     break;}}}
    fprintf(output,"%s\n",objectCode);
  if(length + strlen(objectCode)>60){
    fprintf(objectcode,"T^%06d^%02X^%s\n",textstartAddr,length/2,textRecord);
   strcpy(textRecord,"");
   textstartAddr=locctr;
   length=0;
   }
 if(strlen(objectCode)>0){
    strcat(textRecord,objectCode);
    strcat(textRecord,"^");
    length+=strlen(objectCode);
    }
 fscanf(intermediate,"%d%s%s%s",&locctr,label,opcode,operand);}
 if(length>0){
    textRecord[strlen(textRecord)-1]='\0';
    fprintf(objectcode,"T^%06d^%02X^%s\n",textstartAddr,length/2,textRecord);}
  fprintf(objectcode,"E^%06d\n",start);
  fclose(intermediate);
  fclose(symtab);
  fclose(optab);
  fclose(output);
  fclose(prgmlength);
  printf("FINISHED EXECUTION!!");
}
