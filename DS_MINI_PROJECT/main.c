#include <stdio.h>
#include <stdlib.h>
#include "C:\Users\Sagar Mahesh Bagwe\Desktop\DS_PROJECT_6699\DS_MINI_PROJECT\intro6699.c"

int bs,fs,es;

typedef struct passenger{
char name[20];
int age;
int priority;
int cls;
int custom_id;
int seat_no;
}passenger;

typedef struct seatInfo{
    int sn;
    int cls;
    int isFull;
    struct passenger pass;
    struct seatInfo *next;
}seat;

seat *headBC,*headFC,*headEC,*pnode;

/*
************************************************************************************************
                                CREATE
************************************************************************************************
*/
seat *create(int cls,int num,int initialSn){
    int i;
    seat *temp;
    pnode=(seat*)malloc(sizeof(seat));
    pnode->sn=initialSn;
    if(cls==0){
        pnode->cls=0;
    }
    else if(cls==1){
        pnode->cls=1;
    }
    else if(cls==2){
        pnode->cls=2;
    }

    pnode->isFull=0;
    if(cls==0){
        bs=num;
        headBC=pnode;
        temp=headBC;
    }
    else if(cls==1){
        fs=num;
        headFC=pnode;
        temp=headFC;
    }
    else if(cls==2){
        es=num;
        headEC=pnode;
        temp=headEC;
    }
    else{
        printf("\nError:Invalid class\n");
    }
    for(i=0;i<num-1;i++){
        pnode=(seat*)malloc(sizeof(seat));
        pnode->sn=initialSn+i+1;
        if(cls==0){
        pnode->cls=0;
        }
        else if(cls==1){
            pnode->cls=1;
        }
        else if(cls==2){
            pnode->cls=2;
        }
        pnode->isFull=0;
        //These lines will be executed only once
        if(cls==0&&headBC->next==NULL){
            headBC->next=pnode;
            temp=pnode;
            continue;
        }
        else if(cls==1&&headFC->next==NULL){
            headFC->next=pnode;
            temp=pnode;
            continue;
        }
        else if(cls==2&&headEC->next==NULL){
            headEC->next=pnode;
            temp=pnode;
            continue;
        }
        //till here
        temp->next=pnode;
        temp=pnode;
    }
    if(cls==0){
        temp->next=headBC;
        return headBC;
    }
    else if(cls==1){
        temp->next=headFC;
        return headFC;
    }
    else if(cls==2){
        temp->next=headEC;
        return headEC;
    }
}

/*
************************************************************************************************
                                ADDPASSENGGER
************************************************************************************************
*/

struct passenger addPassenger()
{
    passenger p;
    int debug;
    printf("\t\tEnter your name: ");
    gets(p.name);
    gets(p.name);
    printf("\t\tEnter your age: ");
    scanf("%d",&p.age);
   // printf("Enter your priority: ");
   // scanf("%d",&p.priority);
   /* Print 5 random numbers from 0 to 99 */
    p.priority=(rand() % 100);
    printf("\t\tEnter \n\t\t 1)BUSINESS CLASS\t(1-3)\n\t\t 2)FIRST CLASS\t\t(1-2)\n\t\t 3)ECONOMY CLASS\t(1-5)\n\t\tEnter your choice: ");
    scanf("%d",&debug);
    debug=debug-1;
    p.cls=debug;
    printf("\t\tEnter your seat number: ");
    scanf("%d",&p.seat_no);
    return p;
}

/*
************************************************************************************************
                                DISPLAY
************************************************************************************************
*/


void display(seat *l){
    int i,j,z;
    int x;
    printf("\n\n\t\tSeats display:\n\n");
    if(l->cls==0){
        x=bs;
    }
    else if(l->cls==1){
        x=fs;
    }
    else{
        x=es;
    }
    for(i=1;i<=x;i++){
            if(l->isFull==1){
                if(l->cls==0){
                    printf("\t%c",219);
                    printf(" B%d\t",l->sn);
                }
                else if(l->cls==1){
                    printf("\t%c",219);
                    printf(" F%d\t",l->sn);
                }
                else if(l->cls==2){
                    printf("\t%c",219);
                    printf(" E%d\t",l->sn);
                }
            }

            else{
                    if(l->cls==0){
                    printf("\t%c",176);
                    printf(" B%d\t",l->sn);
                }
                else if(l->cls==1){
                    printf("\t%c",176);
                    printf(" F%d\t",l->sn);
                }
                else if(l->cls==2){
                    printf("\t%c",176);
                    printf(" E%d\t",l->sn);
                }
            }
        i%3==0?printf("\n\n"):printf("");
    l=l->next;
    }
}

/*
************************************************************************************************
                                CHECK
************************************************************************************************
*/

int countEC=0,countFC=0,countBC=0;
void check(struct passenger ps){
    seat *temp;
    int i;
    if(ps.cls==2){
            temp=headEC;
            for(i=0;i<es;i++){
                if(ps.seat_no==temp->sn){
                    if(temp->isFull==0){
                        temp->pass=ps;
                        temp->isFull=1;
                        display(headEC);
                        printf("\n");
                        countEC++;


                    }
                    else if(countEC<5){
                        printf("\n The seat is full\n");
                        display(headEC);
                        printf("\nEnter another seat number :");
                        scanf("%d",&ps.seat_no);

                        display(headEC);
                        printf("\n");

                    }
                    else if(countEC>=5){
                        enqueue(ps);
                        printf("\n\t\tWAIT FOR YOUR CONFIRMATION.\n");
                        printf("\nPress any key to continue");
                        getch();
                        return;
                    }
                }
                temp=temp->next;
            }
    }

    else if(ps.cls==1){
            temp=headFC;
            for(i=0;i<fs;i++){
                if(ps.seat_no==temp->sn){
                    if(temp->isFull==0){
                        temp->pass=ps;
                        temp->isFull=1;
                        display(headFC);
                        printf("\n");
                        countFC++;


                    }
                    else if(countFC<2){
                        printf("\n The seat is full\n");
                        display(headFC);
                        printf("\nEnter another seat number :");
                        scanf("%d",&ps.seat_no);
                        //check(ps);
                        display(headFC);
                        printf("\n");

                    }
                    else if(countFC>=2){
                        enqueue(ps);
                        printf("\n\t\tWAIT FOR YOUR CONFIRMATION.\n");
                        printf("\nPress any key to continue");
                        getch();
                        return;
                    }
                }
                temp=temp->next;
            }
    }

    else if(ps.cls==0){
            temp=headBC;
            for(i=0;i<bs;i++){
                if(ps.seat_no==temp->sn){
                   if(temp->isFull==0){
                        temp->pass=ps;
                        temp->isFull=1;
                        display(headBC);
                        printf("\n");
                        countBC++;


                    }
                    else if(countBC<3){
                        printf("\n The seat is full\n");
                        display(headBC);
                        printf("\nEnter another seat number :");
                        scanf("%d",&ps.seat_no);
                        //check(ps);
                        display(headBC);
                        printf("\n");

                    }
                    else if(countBC>=3){
                        enqueue(ps);
                        printf("\n\t\tWAIT FOR YOUR CONFIRMATION.\n");
                        printf("\nPress any key to continue");
                        getch();
                        return;
                    }
                }
                temp=temp->next;
            }

    }

    printf("Press any key to continue");
    getch();


}

/*
************************************************************************************************
                                ENQUEUE
************************************************************************************************
*/

struct queue{
    struct passenger p;
    struct queue* next;
}*front,*rear,*temp;



void enqueue(struct passenger pass)
{
    if(front==NULL && rear==NULL)
    {
        temp=(struct queue*)malloc(sizeof(struct queue));
        temp->p=pass;
        front=rear=temp;
    }
    else
    {

        temp=(struct queue*)malloc(sizeof(struct queue));
        temp->p=pass;
        rear->next=temp;
        rear=temp;
    }
}

/*
************************************************************************************************
                                COMPARE
************************************************************************************************
*/

struct passenger compare()
{
 struct queue *ptr;
 struct passenger greater;
 ptr=front;
 greater=front->p;
 while(ptr->next!=NULL)
 {
     if(ptr->p.priority>greater.priority)
     {
         greater=ptr->p;
     }
     ptr=ptr->next;
 }
 return greater;
}
struct seatInfo* newSeat(struct seat* head){
    struct seatInfo *temp;
    temp=head;
    do{
        if(temp->isFull==1){
            temp=temp->next;
        }
        else if(temp->isFull==0){
            return temp;
        }
    }while(temp!=head);
    temp=NULL;
    return temp;
}

/*
************************************************************************************************
                                UPGRADE
************************************************************************************************
*/

void upgrade(){
    struct seatInfo* mySeat;
    struct passenger greatest=compare();
    if(greatest.cls==2){
        mySeat=newSeat(headBC);
        if(mySeat==NULL){
            printf("\n NO SEATS AVAILABLE!!\n");
        }
        mySeat->pass=greatest;
        mySeat->isFull=1;
        display(headBC);
    }
    else if(greatest.cls==0){
        mySeat=newSeat(headFC);
        if(mySeat==NULL){
            printf("\n NO SEATS AVAILABLE!!\n");
        }
        mySeat->pass=greatest;
        mySeat->isFull=1;
        display(headFC);
    }
}

/*
************************************************************************************************
                                MAIN
************************************************************************************************
*/

int main(){
    intro();
    seat* head;
    int ch;
    headEC=create(2,5,1);
    headFC=create(1,2,1);
    headBC=create(0,3,1);
    do{
            system("cls");
       dispMenu();
       printf("\n\t\tEnter \n\t\t******************\n\n\t\t1)Check-in\n\t\t2)Upgrade\n\t\t3)Display of seats\n\t\t");
       scanf("%d",&ch);
       switch(ch){
    case 1:
        check(addPassenger());
        break;
    case 2:
        if(front==NULL && rear==NULL){
            printf("\nUpgradation Queue is empty\n");
            printf("Press any key to continue");
            getch();
            break;
        }
        upgrade();
        printf("Press any key to continue");
        getch();
        break;
    case 3:
        display(headFC);
        printf("\n");
        printf("\n");
        display(headBC);
        printf("\n");
        printf("\n");
        display(headEC);
        printf("\n");
        printf("\n");
        printf("Press any key to continue");
        getch();
        break;
       }
    }while(ch<=3);

}
