#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

#define SIZEOFARRAY 10


struct Student{
    int id;
    char name[20];
    int grade;
};



struct Student arr[SIZEOFARRAY];



int main(){


    int i;
    for(i=0;i<10;++i){
        printf("enter your id ");
        scanf("%d",&arr[i].id);
        printf("enter your name ");
        scanf("%19s",arr[i].name);
        printf("enter your grades ");
        scanf("%d",&arr[i].grade);
    }
    bubbleSort(10);
    for(i=0;i<10;++i)printf("%d %s %d\n ",arr[i].id,arr[i].name,arr[i].grade);
    puts(" ");






return 0;
}


void bubbleSort(int size){

    int i,sorted=1;
    struct Student tmp;
    while(sorted){
        sorted=0;
        for(i=0;i<size-1;++i){
            int com=strcmp(arr[i].name,arr[i+1].name);
            if(com>0){
                tmp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=tmp;
                sorted=1;
            }
        }

    }


}
