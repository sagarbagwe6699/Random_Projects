#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

int intro()
{
    system("color 3f");
    printf("\t\t\t     ___       __  .______       __       __  .__   __.  _______     _______.\n");
    printf("\t\t\t    /   \\     |  | |   _  \\     |  |     |  | |  \\ |  | |   ____|   /       |\n");
    printf("\t\t\t   /  ^  \\    |  | |  |_)  |    |  |     |  | |   \\|  | |  |__     |   (----`\n");
    printf("\t\t\t  /  /_\\  \\   |  | |      /     |  |     |  | |  . `  | |   __|     \\   \\    \n");
    printf("\t\t\t /  _____  \\  |  | |  |\\  \\----.|  `----.|  | |  |\\   | |  |____.----)   |   \n");
    printf("\t\t\t/__/     \\__\\ |__| | _| `._____||_______||__| |__| \\__| |_______|_______/    \n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\t");
    int i;
    printf("\n\t\t\t\t\t\t\tLoading\n\n\t");
    for(i=0;i<100;i++){
        printf("%c",219);
        Sleep(15);
    }
    printf("\n\n\t\t\t\t\t\t\tCompleted\n\n\n\n");
    system("color 2f");
    Sleep(600);
    system("color 3f");
    system("cls");
}

void dispMenu(){
    printf("\t\t\t        __  __       _         __  __                  \n");
    printf("\t\t\t       |  \\/  |     (_)       |  \\/  |                 \n");
    printf("\t\t\t       | \\  / | __ _ _ _ __   | \\  / | ___ _ __  _   _ \n");
    printf("\t\t\t       | |\\/| |/ _` | | '_ \\  | |\\/| |/ _ \\ '_ \\| | | |\n");
    printf("\t\t\t       | |  | | (_| | | | | | | |  | |  __/ | | | |_| |\n");
    printf("\t\t\t       |_|  |_|\\__,_|_|_| |_| |_|  |_|\\___|_| |_|\\__,_|\n");
    printf("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n");
    printf("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n\n\n");
    //printf("**********************************************************************************************************************\n");
    //printf("----------------------------------------------------------------------------------------------------------------------\n");
}
