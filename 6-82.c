#include<stdio.h>
#include<stdlib.h>

int main(){
    int a =1,b=5;
    int tmp=a+b;
    if(tmp>3 && tmp<10){
        a=tmp;
    }
    printf("%d",a);
}