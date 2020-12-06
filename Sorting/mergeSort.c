#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define SIZEOFARRAY 10


struct Student{
    int id;
    char name[20];
    int grade;
};
void mergeSort(int start,int end,int (*compare)(int,int));

void merge(int start,int mid,int end,int (*compare)(int,int));

int ascending(int a,int b);

int descending(int a,int b);
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
    mergeSort(0,9,descending);
    for(i=0;i<10;++i)printf("%d %s %d\n ",arr[i].id,arr[i].name,arr[i].grade);
    puts(" ");




return 0;
}

void mergeSort(int begin,int end,int (*compare)(int,int)){

if(begin<end){

    int mid = (begin+end)/2;
             mergeSort( begin, mid,compare);
           mergeSort( mid + 1, end,compare);
            merge( begin, mid, end,compare);
}

}
void merge(int start,int mid,int end,int (*compare)(int,int)){



       struct Student temp[SIZEOFARRAY];

       int i,left=start,right=mid+1;


    i=start;




while(left<=mid&&right<=end){
    if(compare(arr[left].id,arr[right].id))temp[i]=arr[left++];
    else temp[i]=arr[right++];
    ++i;
}

while(left<=mid){
    temp[i]=arr[left];
    ++i;
    ++left;
}

while(right<=end){
    temp[i]=arr[right];
    ++i;
    ++right;
}
for(i=start;i<=end;i++)arr[i]=temp[i];

}

int ascending(int a,int b){
    return a<=b;
}
int descending(int a,int b){
    return a>b;
}


