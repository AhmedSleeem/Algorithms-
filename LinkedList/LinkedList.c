#include <stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

struct Emp{
int id;
char name[10];
int salary;
};

struct Node {
struct Emp emp;
struct Node * ptrPrev;
struct Node * ptrNext;
};

struct Node* ptrHead;
struct Node* ptrTail;

//for calc the number of nodes
int SizeOfList=0;

//prototype
struct Emp* fillEmp(void);
struct Node* createNode(struct Emp );
int AddNode(struct Emp data);
int InsertNode(struct Emp data,int loc);
struct Node* searchById(int Id);
struct Node* searchByName(char* name);
int CountList(void);
void freeList(void);
int deleteNode(int loc);
void printEmp(struct Emp);

void printListForwardEmployee(void);
void printListBackward(void);



int main(void){

	char name[10];
	char press;
	struct Emp* e;
	struct Node* cur;
	int tmp;

    printf("1- Add Node\n");
    printf("2- Insert Node\n");
    printf("3- Print List\n");
    printf("4- search by Id\n");
    printf("5- search by name\n");
    printf("6- delete Node\n");
    printf("7- count List\n");
    printf("8- Free List\n");
    printf("9- Exit\n");
    press=1;
    while(press!='9'){
            printf("enter a number ");
        press=getchar();
        switch(press){
            case '1':
              e=  fillEmp();
              if(e)AddNode(*e);
              break;

            case '2':
                e=  fillEmp();
              if(e){
                     printf("Enter node's location  ");
                scanf("%d",&tmp);
                    InsertNode(*e,tmp);

              }
              break;
            case '3':
                printListForwardEmployee();
                break;
            case '4':
                printf("Enter your Id ");
                scanf("%d",&tmp);
               cur= searchById(tmp);
               if(cur){
                    printEmp(cur->emp);
               }
                break;
            case '5':
                  printf("Enter your Name ");
                scanf("%s",name);
               cur = searchByName(name);
               if(cur){
                    printEmp(cur->emp);
               }
                break;
            case '6':
                  printf("Enter node's location  ");
                scanf("%d",&tmp);
                deleteNode(tmp);
                break;
            case '7':
                printf("%d\n",CountList());
                break;
            case '8':
                freeList();
                break;





        }

    }



return 0;
}

void printEmp(struct Emp ptr){
    printf("%d ",ptr.id);
		printf("%s ",ptr.name);
		printf("%d\n",ptr.salary);
}

struct Emp* fillEmp()
{
	struct Emp *e= (struct Emp*)malloc(sizeof(struct Emp));
	if(e){
            printf("enter your Id     name     salary ");

	scanf("%d",&(e->id));
	scanf("%s",e->name);
	scanf("%d",&(e->salary));

	}
	return e;
}
int CountList(){

    return SizeOfList;
}

struct Node* createNode(struct Emp data){

	struct Node* tmp=(struct Node*)malloc(sizeof(struct Node));

	if(tmp){

		SizeOfList++;
		tmp->emp=data;
		tmp->ptrPrev=tmp->ptrNext=NULL;

	}
	return tmp;
}

int AddNode(struct Emp emp){

	int ret=0;

	struct Node *ptr=createNode(emp);
	if(ptr){
		if(ptrHead==NULL){
			ptrHead=ptrTail=ptr;
		}else{
			ptrTail->ptrNext=ptr;
			ptr->ptrPrev=ptrTail;
			ptrTail=ptr;
		}
	ret=1;
	}
	return ret;
}


void freeList(void)
{
	struct Node* ptr;
	while(ptrHead)
	{
		ptr=ptrHead;
		ptrHead=ptrHead->ptrNext;
		free(ptr);
	}

	//Added
	SizeOfList=0;
}




 struct Node* searchById(int data){
	struct Node* ptr=ptrHead;
	while(ptr&&(ptr->emp).id != data)ptr=ptr->ptrNext;

	return ptr;
}



struct Node* searchByName(char* name){

    struct Node * ptr=ptrHead;
    while(ptr&&strcmp(name,(ptr->emp).name))ptr=ptr->ptrNext;

        return ptr;
}

int deleteNode(int loc){
	int ret=0,i;
	struct Node* ptr,*cur,*ppp;
	if(ptrHead){
		ret=1;
		if(loc==0){
			ptr=ptrHead;
			ptrHead=ptrHead->ptrNext;
			ptrHead->ptrPrev = NULL;
			free(ptr);
		}else{
			ptr=ptrHead;
			for(i=0;i<loc&&ptr;++i){
				ptr=ptr->ptrNext;
			}
			//delete last Node
			if(ptr==ptrTail){
				ptr=ptrTail;
				ptrTail=ptr->ptrPrev;
				ptrTail->ptrNext=NULL;

				free(ptr);

			}

			else if(ptr){//delete in middle
				cur=ptr;
				ppp=cur->ptrPrev;
				ptr=ptr->ptrNext;
				(ppp->ptrNext)=ptr;
				ptr->ptrPrev=ppp;
				free(cur);
			}

			else ret=0; //location is not exist


		}

	}
	if(ret)--SizeOfList;

	return ret;
}

void printListForwardEmployee(void){

	struct Node *ptr=ptrHead;
	while(ptr){
		printf("%d ",ptr->emp.id);
		printf("%s ",ptr->emp.name);
		printf("%d\n",ptr->emp.salary);
		ptr=ptr->ptrNext;
	}
	puts("");
}

void printListBackward(void){

	struct Node *ptr=ptrHead;
	while(ptr){
		printf("%d ",ptr->emp.id);
		printf("%s ",ptr->emp.name);
		printf("%d\n",ptr->emp.salary);
		ptr=ptr->ptrNext;
	}
	puts("");
}


int  InsertNode(struct Emp data,int loc){
    int ret=0,i;
    struct Node *ptr=createNode(data),*cur;
    if(ptr){
            ret=1;
            //add it in the beginning
        if(loc==0){
            ptr->ptrNext=ptrHead;
            ptrHead=ptr;
        }else{
            cur=ptrHead;
            for(i=0;i<loc-1&&cur;++i)cur=cur->ptrNext;

            //at the end
            if(cur==ptrTail||cur==NULL){
                (ptrTail->ptrNext)=ptr;
                ptr->ptrPrev=ptrTail;
                ptrTail=ptr;
            }
            else{
                //add to the middle
                (cur->ptrNext)->ptrPrev=ptr;
                (ptr->ptrNext)=(cur->ptrNext);
                cur->ptrNext=ptr;
                ptr->ptrPrev=cur;

            }
        }



    }

    return ret;

}

