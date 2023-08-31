#include<stdio.h>
#include<string.h>
#include <stdlib.h>


//You have to give command like following in order to have accurate result and currently this code does not supports floating point integers

//add 10 20
//mul 50 60
int main(int argc,char*argv[]){
if(argc < 3){
    printf("Error in gettting aguments");
    return 404;
}

char *operation = argv[1];
int num1=atoi(argv[2]);
int num2=atoi(argv[3]);
int result;
if(strcmp(operation,"add") == 0){
result =num1 + num2;
printf("Result : %d ",result);
return 200;
}else if(strcmp(operation,"sub")==0){
result =num1 - num2;
printf("Result : %d ",result);
return 200;
}else if(strcmp(operation,"div") ==0){
    result = num1/num2;
    printf("Result : %d ",result);
    return 200;
}else if(strcmp(operation,"mul") == 0){
    result = num1*num2;
    printf("Result : %d ",result);
    return 200;
}else if(strcmp(operation,"mod") == 0){
    result = num1 % num2;
    printf("Result : %d ",result);
    return 200;

}else{
    printf("Unidentified  operation");
    return 0;
}
}