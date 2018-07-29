#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void hotel();

int rooms[100];
int prices[100];
int type[100];
int available[100];
int inc=0;

int add(int i,int r[i],int p[i],int t[i],int a[i])
{
    int ri,pi,ti;

    printf("Enter Room Number :");
    scanf("%d",&ri);
    printf("Enter price :");
    scanf("%d",&pi);
    printf("Enter type :");
    scanf("%d",&ti);

    r[i]=ri;
    p[i]=pi;
    t[i]=ti;
    a[i]=1;

    i++;

    printf("\n\n\t\tRoom SUCCESFULLY added.");

    return i;

}

void ava(int size,int r[size],int a[size])
{
    int c=0;

        if(size==0)
    {
        printf("Please add a room\n\n");
    }

    for(int i=0;i<size;i++)
    {
        if(a[i]==1)
        {
            printf("Room Number : %d\n",r[i]);
            c++;
        }
    }
    (c==0)?(printf("No rooms available\nPRESS ANY KEY TO CONTINUE")):(printf("\nPRESS ANY KEY TO CONTINUE"));
    getch();
}

void book(int size,int r[size],int a[size])
{
    int rn;

    printf("Enter Room Number :");
    scanf("%d",&rn);

    for(int i=0;i<size;i++)
    {
        if(r[i]==rn&&a[i]==1)
        {
            a[i]=0;
            printf("Booking successful\n\nPRESS ANY KEY TO CONTINUE");
            getch();
        }
        else{
            printf("Room not available\n\nPRESS ANY KEY TO CONTINUE");
            getch();
        }
    }

}

void checkout(int size,int r[size],int a[size],int p[size])
{
    int rn;

    printf("Enter Room Number :");
    scanf("%d",&rn);

    for(int i=0;i<size;i++)
    {
        if(r[i]==rn)
        {
            a[i]=1;
            printf("Checkout successful\n\nThe bill is Rs.%d\n\nPRESS ANY KEY TO CONTINUE",p[0]);
            getch();
        }
    }

}

int main()
{
    int c;

    hotel();
    Sleep(3000);
    system("cls");

        mainmenu:


    printf("\n\nMenu :\n\n1.All rooms.\n\n2.Available rooms\n\n3.Book room\n\n4.Checkout\n\n5.Add rooms\n\n\n\nEnter your choice :");
    scanf("%d",&c);

    switch(c)
    {
case 1:
    if(inc==0)
    {
        printf("Please add a room");
    }
    for(int i=0;i<inc;i++)
    {
        printf("Room Number : %d\n",rooms[i]);
        printf((type[i]==0)?(" : Non-A/C"):(" : A/C"));
        printf(" : %d",prices[i]);
        printf((available[i]==1)?(" : Available\n\n"):(" : Booked\n\n"));
    }
    printf("\n\nPRESS ANY KEY to continue");
    getch();
    system("cls");
    goto mainmenu;
    break;
case 2:
    ava(inc,rooms,available);
    //system("cls");
    getch();
    system("cls");
    goto mainmenu;
    break;
case 3:
    book(inc,rooms,available);
    system("cls");
    goto mainmenu;
    break;
case 4:
    checkout(inc,rooms,available,prices);
    system("cls");
    goto mainmenu;
    break;
case 5:
    inc=add(inc,rooms,prices,type,available);
    printf("\n\nPRESS ANY KEY to continue");
    getch();
    system("cls");
    goto mainmenu;

default:
    system("cls");
    goto mainmenu;

    }
}


void hotel()
{
    printf("\t\t\t  _____ _           _         \n");
    printf("\t\t\t / ____| |         | |        \n");
    printf("\t\t\t| |    | |__   ___ | |_ _   _ \n");
    printf("\t\t\t| |    | '_ \\ / _ \\| __| | | |\n");
    printf("\t\t\t| |____| | | | (_) | |_| |_| |\n");
    printf("\t\t\t \\_____|_| |_|\\___/ \\__|\\__,_|\n");
    printf("\t\t\n\n");
    printf("\t\t\t _    _       _       _ \n");
    printf("\t\t\t| |  | |     | |     | |\n");
    printf("\t\t\t| |__| | ___ | |_ ___| |\n");
    printf("\t\t\t|  __  |/ _ \\| __/ _ \\ |\n");
    printf("\t\t\t| |  | | (_) | ||  __/ |\n");
    printf("\t\t\t|_|  |_|\\___/ \\__\\___|_|\n");

}
