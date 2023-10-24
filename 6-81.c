#include<stdio.h>
#include<stdlib.h>

int main(){
    int a =1,b=5;
    if((a+b)>3 && (a+b)<10){
        a=a+b;
    }
    printf("%d",a);
}