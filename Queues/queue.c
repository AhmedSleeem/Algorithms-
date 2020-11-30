#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


int head;
int arr[20];
int add(int data);
int retrieve(void);

void printQueue(void);
int main(){


char press;
    int tmp;

    printf("1- add\n");
    printf("2- retrieve\n");
    printf("3- Print queue\n");
    printf("3- Exit\n");

    press=1;
    while(press!='4'){
            printf("enter a num  ");
        press=getch();
       switch(press){
    case '1':
        printf("enter data  ");
        scanf("%d",&tmp);
        add(tmp);
        break;
        case '2':
            retrieve();
            break;
        case '3':
            printQueue();
            break;
       }

    }







return 0;
}

int add(int data)
{

  int ret=0,i,tmp;
  if(head<20){
    for(i=head;i>0;--i){
        tmp=arr[i];
        arr[i]=arr[i-1];
        arr[i-1]=tmp;
    }
    arr[0]=data;
    ++head;
  }
  return ret;
}

int retrieve(){

    int ret=-1;
    if(head>0){
        ret=arr[head-1];
        arr[head]=0;
        --head;
    }
    return ret;
}
void printQueue(){
int i;
for(i=0;i<head;++i)printf("%d ",arr[i]);
puts(" ");
}
