#include<stdio.h>
#include<stdlib.h>
#include<conio.h>



struct Node{
int data;

struct Node* prev;
};

int push(int data);
int pop(void);
struct Node* tos;
struct Node * createNode(int data);
void printStack();



int main(){

    char press;
    int tmp;

    printf("1- Push\n");
    printf("2- Pop\n");
    printf("3- Print stack\n");
    printf("3- Exit\n");

    press=1;
    while(press!='4'){
            printf("enter a number  ");
        press=getch();
       switch(press){
    case '1':
        printf("enter data  ");
        scanf("%d",&tmp);
        push(tmp);
        break;
        case '2':
            pop();
            break;
        case '3':
            printStack();
            break;
       }

    }


return 0;
}

struct Node * createNode(int data){

        struct Node * ptr=(struct Node*)malloc(sizeof(struct Node));
        if(ptr){
            ptr->data=data;
            ptr->prev=NULL;
        }
        return ptr;

}

int push(int data){
    int ret=0;
    struct Node * cur=createNode(data);

    if(cur){
        ret=1;
        if(!tos){
            tos=cur;
        }else{
            cur->prev=tos;
            tos=cur;
        }
    }

    return ret;
}

int pop(){
    int ret=-1;
    struct Node * tmp;
    if(tos){
            tmp=tos;
        ret=tos->data;
        tos=tos->prev;
        free(tmp);
    }
    return ret;
}
void printStack(){
    struct Node*ptr=tos;
    while(ptr){
        printf("%d ",ptr->data);
        ptr=ptr->prev;
    }
    puts("");
}



