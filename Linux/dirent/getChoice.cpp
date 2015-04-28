#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *menu[]{
    "a - add new record",
    "d - delete record",
    "q - quit",
    NULL,
};
int getChoice(char *greet, char *choices[]){
    int chosen = 0;
    int selected;
    char **option;

    do{
        printf("Choose : %s\n", greet);
        option = choices;
        while(*option){
            printf("%s\n", *option);
            option ++;
        }
        selected = getchar();
        if(selected == "\n"){
            cout << "in" << endl;
            selected = getchar();
        }
        option = choices;
        while(*option){
            if(selected == *option[0]){
                chosen = 1;
                break;
            }
            option ++;
        }

        if(!chosen && chosen != "\n"){
            printf("Incorrect choose\n");
        }
    }while(!chosen);
    return selected;
}

int main(int argc, const char *argv[])
{
    int choice = 0;
    do{
        choice = getChoice("Please select an action", menu);
        printf("You have choosen : %c\n", choice);
    }while(choice != 'q' );
    return 0;
}
