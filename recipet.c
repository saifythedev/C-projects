#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void Bill(const char*str,const char oldWord[20],const char NewWord[20],char*bill){
char * result= strstr(str,oldWord);
int oldWordindex=result-str;
int newwordIndex=0;
int newwordLength=strlen(NewWord);
int i=0;
int Billindex=0;
for(i=0 ;str[i] != '\0'; i++){
if(i == oldWordindex){
  int j=0;
  for(j=i ;j<oldWordindex+newwordLength;j++){
      bill[Billindex]=NewWord[j-i];
      Billindex++;
}
bill[Billindex]='\0';
i+=strlen(oldWord)-1;
continue;
}else{

bill[Billindex]=str[i];
Billindex++;

}

}

bill[i]='\0';

}


int main(){
    FILE * file=NULL;
    char * data=NULL;
    file = fopen("exampleRecipet.txt","r");
    if(file == NULL){
        printf("Error.");
        return 200;
    }
    fseek(file,0,SEEK_END);
    int length=ftell(file);
    data=(char *)malloc((length+1)*sizeof(char));
    if(data ==NULL){
        printf("Error in allocating memory");
        return 404;
    }
    fseek(file,0,SEEK_SET);
    int c;
    int index=0;
    while((c=fgetc(file)) != EOF){    
      *(data+index)=c;
    
       index++;
    }
  data[index]='\0';

  printf("Done reading file\n");

fclose(file);


char Name[20];
char TotalBill[10];
char paid[10];
char  Return[10];
printf("please Enter your Name : ");
fgets(Name,20,stdin);
printf(" your Total Bill : ");
fgets(TotalBill,10,stdin);
getchar();
printf("given amount : ");
fgets(paid,10,stdin);
getchar();

int return_value=atoi(paid)-atoi(TotalBill);
sprintf(Return,"%d",return_value);
printf("Return value=%s\n",Return);


char *newBill=NULL;
int n=(strlen(data));
newBill =(char *)calloc(strlen(data) , sizeof (char));

Bill(data,"{{name}}",Name,newBill);
Bill(newBill,"{{Total}}",TotalBill,newBill);
Bill(newBill,"{{paid}}",paid,newBill);
Bill(newBill,"{{return}}",Return,newBill);
Bill(newBill,"{{Date}}",__TIME__,newBill);


file=fopen("Bill.txt","a+");

fputs(newBill,file);
printf("Bill generated");
fclose(file);

free(data);
data=NULL;
free(newBill);
newBill=NULL;
return 0;
}
