#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
FILE  *file1,*file2,*file3,*file4;
char opcode[20],operand[20],code[20],mnemonic[20],label[20];
int locctr,start,length;
file1=fopen("input.dat","r");
file2=fopen("optab.dat","r");
file3=fopen("symtab.dat","w");
file4=fopen("output.dat","w");
fscanf(file1,"%s\t%s\t%s",label,opcode,operand);
if(strcmp(opcode,"START")==0)
{
start=atoi(operand);
locctr=start;
fprintf(file4,"\t%s\t%s\t%s\n",label,opcode,operand);
fscanf(file1,"\t%s\t%s\t%s",label,opcode,operand);
}
else
locctr=0;
while(strcmp(opcode,"END")!=0)
{
fprintf(file4,"%d\t",locctr); 
if(strcmp(label,"**")!=0)
{
fprintf(file3,"%s\t%d\n",label,locctr);
}
fscanf(file2,"%s\t%s",code,mnemonic);
while(strcmp(code,"END")!=0)
{if(strcmp(opcode,code)==0)
{
locctr+=3;
break;
}
fscanf(file2,"%s\t%s",code,mnemonic);
}
if(strcmp(opcode,"WORD")==0)
{
locctr+=3;
}
else if(strcmp(opcode,"RESW")==0)
locctr=locctr+(3*atoi(operand));
else if(strcmp(opcode,"RESB")==0)
locctr=locctr+atoi(operand);
else if(strcmp(opcode,"BYTE")==0)
{
++locctr;
}
fprintf(file4,"\t%s\t%s\t%s\n",label,opcode,operand);
fscanf(file1,"\t%s\t%s\t%s",label,opcode,operand);
}
fprintf(file4,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
length=locctr-start;
printf("LENGTH OF THE CODE:%d\n",length);
 fclose(file1);
 fclose(file2);
 fclose(file3);
 fclose(file4);
 }
