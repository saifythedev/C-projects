#include<stdio.h>
#include <string.h>
#include<stdlib.h>
int palindrome(int number,int n){
  int temp=number;
  int *arr=(int *)calloc(n,sizeof(int));
  int *oldarr=(int *)calloc(n,sizeof(int));

  int index=0;
  int index2=n-1;
  int comparison=0;  
  
  while (temp > 0)
  {
    int x= temp % 10;
     *(arr+index) = x;
     *(oldarr+index2)=x; 
     temp = temp/10;
     index++;
     index2--;
  }

  for(int i=0;i<n;i++){
    printf("oldar: %d , new : %d\n",*(oldarr+i),*(arr+i));
     if(*(oldarr+i) == *(arr+i)){
      comparison = 1;
     } 
     else if(oldarr[i]!=arr[i]){
      comparison = 0;
     }  
  }

  free(arr);
  arr=NULL;
  free(oldarr);
  oldarr=NULL;

  return comparison;
}
int main(){
printf("Palindrome Checker\n");

int number;
int n;
printf("How many digit do you have in you number : ");
scanf("%d",&n);
getchar();
printf("Enter number : ");
scanf("%d",&number);
int result=palindrome(number,n);
if(result != 0){
    printf("its a palidrome ");
}else{
    printf("Its not a palindrome");
}
return 0;
}
