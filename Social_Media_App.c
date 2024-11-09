#include <stdio.h>

int main(void){
    int choice;
    
    printf("-Login      = 1\n");
    printf("-Register   = 2\n");
    printf("Choose an option: \n");
    
    switch (choice)
    {
    case 1:
        login();
        break;
    
    case 2:
        reg();
        break;

    default:
        printf("Choose a correct option")
        break;
    }

}