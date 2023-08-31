#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void Bill(const char*str,const char oldWord[20],const char NewWord[20],char*bill){
char * result= strstr(str,oldWord);
int oldWordindex=result-str;
int newwordIndex=0;
int newwordLength=strlen(NewWord);
// printf("oldWordIndex : %d newwordLength : %d add: %d",oldWordindex,newwordLength,oldWordindex + newwordLength);
int i=0;
int Billindex=0;
for(i=0 ;str[i] != '\0'; i++){
if(i == oldWordindex){
  int j=0;
  for(j=i ;j<oldWordindex+newwordLength;j++){
      // bill[j]=NewWord[newwordIndex];
      bill[Billindex]=NewWord[j-i];
      Billindex++;

        // newwordIndex++;
}
// bill[i]='\n';
// bill[Billindex]='\n';
// printf("\n%d x",i);
bill[Billindex]='\0';
i+=strlen(oldWord)-1;
// printf("\n%d y",i);
// i+=strlen(oldWord)-1;
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
    //   printf("%c",data[index]);
       index++;
    }
  data[index]='\0';
  // printf("%s",data);
  printf("Done reading file\n");
// printf("%d\n",strlen(data));
fclose(file);


char Name[20];
char TotalBill[10];
char paid[10];
char  Return[10];
// char Date[30]=__DATE__;
// strcat(Date_time,__TIME__);
// printf("%s\n",Date);
printf("please Enter your Name : ");
// fgets(Name,20,stdin);
gets(Name);
// getchar();
printf(" your Total Bill : ");
scanf("%s",&TotalBill);
getchar();
printf("given amount : ");
scanf("%s",&paid);
getchar();
// char num[20];
// sprintf(num,"%s",TotalBill);
// TotalBill=atoi(num)

// printf("%s,%d,%s",Name,(int) TotalBill,paid);
// long long int x= 23425678235;
// char charArr[4];
// sprintf(charArr,"%d",x);
// printf("%s\n", charArr);
// int y=atoi(charArr);
// printf(" %d  ",x);
int return_value=atoi(paid)-atoi(TotalBill);
sprintf(Return,"%d",return_value);
printf("Return value=%s\n",Return);


char *newBill=NULL;
// int total =50;
// int paid=60;
// char name[10]="saifsatti";
// int Return = total - paid;
int n=(strlen(data));
newBill =(char *)calloc(strlen(data) , sizeof (char));

Bill(data,"{{name}}",Name,newBill);
Bill(newBill,"{{Total}}",TotalBill,newBill);
Bill(newBill,"{{paid}}",paid,newBill);
Bill(newBill,"{{return}}",Return,newBill);
Bill(newBill,"{{Date}}",__TIME__,newBill);

// printf("%s \n %d \n",newBill,strlen(newBill));

file=fopen("Bill.txt","a+");
// fprintf(file,"%s",newBill);
fputs(newBill,file);
printf("Bill generated");
fclose(file);

free(data);
data=NULL;
free(newBill);
newBill=NULL;
return 0;
}