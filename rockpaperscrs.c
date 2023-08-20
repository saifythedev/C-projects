#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>
int randomNumberGenerator(){
    int i=3;
    int num=rand() % i;
    // printf("Generaed %d\n",num);
    return num;
}

void userInputTolower(char * string){
    // printf("%s",string);
int index=0;
char *modifiedString;
modifiedString=(char *)calloc(strlen(string)+1,sizeof(char));
if (modifiedString == NULL){
    printf("Memory Allocation failed....");
    return;
};
for(int i=0; i<strlen(string);i++){
modifiedString[i]=tolower(*(string + i));
}
// printf("%s",modifiedString);
for(int i = 0; i<strlen(string) ; i++){
string[i]=modifiedString[i];
index++;
}
string[strlen(string)]='\0';
free(modifiedString);
// return modifiedString;
}

int main(){

srand(time(NULL));
// int arr[3]={0,1,2};

// int *array[3]={&arr[0],&arr[1],&arr[2]};
int n;
int i=0;
int UserScore = 0;
int computerScore = 0;





printf("*** Welcome to the game ***\n");
printf("Enter how many time do you want to play this game : ");
scanf("%d",&n);
getchar();
char *userInput;
char *computer;


do{
char *arr[]={"rock","paper","scissor"};
userInput=(char *)malloc(7*sizeof(char));
if(userInput == NULL){
    printf("memory allocation ailed please try again....");
    return 0;
}
printf("Enter your Choice\ni.e rock,paper,scissor\n");
scanf("%s", userInput);
getchar();

// printf("User choice: %s",userInput)
userInputTolower(userInput);
// char *str = userInput;
// printf("%s",str);


int x=randomNumberGenerator();

// printf("Genz : %d - %d -%d",x1,x2,x3);
int y=strlen(arr[x]);

// printf("%d length\n",y);
computer =(char *)malloc(y*sizeof(char));
if(computer == NULL){
    printf("Memory Allocation failed...");
    return 0;
}


for(int i=0; i<=y+1; i++){
computer[i] = *(arr[x]+i);
};
// printf("%d \n",strcmp(str,"rock"));


if (strcmp(userInput,"rock") == 0  && strcmp(computer,"paper") == 0  ){
printf("computer wins\n");
computerScore += 1;

}else if (strcmp(userInput,"paper") == 0  && strcmp(computer,"scissor") == 0){
printf("computer wins\n");
computerScore += 1;

} else if (strcmp(userInput,"scissor") == 0  && strcmp(computer,"rock") == 0){
printf("computer wins\n");
computerScore += 1;


}else if (strcmp(userInput,"rock") == 0  && strcmp(computer,"scissor") == 0){
printf("you  win\n");
UserScore += 1;

}
else if (strcmp(userInput,"paper") == 0  && strcmp(computer,"rock") == 0){
printf("you  win\n");
UserScore += 1;


}else if (strcmp(userInput,"scissor") == 0  && strcmp(computer,"paper") == 0){
printf("you  win\n");
UserScore += 1;


}else if (strcmp(userInput,"rock") == 0  && strcmp(computer,"scissor") == 0){
printf("you  win\n");
UserScore += 1;


}else if(strcmp(userInput,computer) == 0){

    printf("Draw\n");
    
}


free(userInput);
// free(str);
free(computer);

i++;
}

while (i < n);

printf("Your score: %d  |  computes score : %d",UserScore,computerScore);


//------------------------------------------------//
// int result = strcmp(str,computer);
// printf("result : %d",result);




// printf("%s",str);
// userInputTolower(userInput);
// for(int i =0; i<3;i++){
// int randNum=randomNumberGenerator();


// // printf("%d",*(array[i]));
// // printf("%d\n",randNum);

// // printf("%s\n",arr[i]);
// }


return 0;
}