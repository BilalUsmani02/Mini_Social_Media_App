#include <stdio.h>
#include <string.h>

//username length=20
int run=1,loggedIn=0;

void registeration();
void login();
void postMenu();
void createPost();
void viewPost();
void deletePost();


int main(void){
    int choice;

    while (run==1){
        if (loggedIn==1){
            postMenu();
        }else{
            printf("------------------------\n");
            printf("---Welcome to Tweet---");
            printf("\n------------------------\n\n");
            printf("-Login      = 1\n");
            printf("-Register   = 2\n");
            printf("\n\n-To exit    =0\n");
            printf("\nChoose an option:");
            scanf("%d",&choice);
            getchar();
            
            switch (choice){
            case 1:
                login();
                break;
            
            case 2:
                registeration();
                break;

            case 0:
                printf("Good Bye !");
                run=0;
                break;

            default:
                printf("Invalid option");
                break;
            }
        }
    }

}

void registeration(){
    char username[20],password[20],storedUsername[20];
    int error=1;
    
    FILE *file=fopen("users.txt","a+");
    
    printf("\n-------------------\n");
    printf("-Registration Page-");
	printf("\n-------------------\n");

    while(error==1){
        
        printf("\nEnter a username: ");
        fgets(username,sizeof(username),stdin);
        username[strcspn(username,"\n")]=0;

        error=0;
        rewind(file);
        
        while (fgets(storedUsername,sizeof(storedUsername),file) != NULL) {
            storedUsername[strcspn(storedUsername,"\n")]=0;

            if (strcmp(username,storedUsername)==0){
                printf("Username already taken, Try another one");
                error=1;
                break;
            }
            fgets(storedUsername,sizeof(storedUsername),file);
        }        
    }

    printf("Enter a password: ");
    fgets(password,sizeof(password),stdin);
    password[strcspn(password, "\n")] = 0;

    fprintf(file,"%s\n%s\n",username,password);

    fclose(file);
    
    printf("\n---User registered successfully!---\n\n\n");
}

void login(){
    char username[20],password[20],storedUsername[20],storedPassword[20];
    int found=0;
    
    FILE *file=fopen("users.txt","r");
    
    printf("\n-------------------\n");
    printf("-   Login Page    -");
	printf("\n-------------------\n");

    while(found==0){
        
        printf("\nEnter your username: ");
        fgets(username,sizeof(username),stdin);
        username[strcspn(username,"\n")]=0;

        printf("Enter your password: ");
        fgets(password,sizeof(password),stdin);
        password[strcspn(password,"\n")]=0;

        rewind(file);

        while (fgets(storedUsername,sizeof(storedUsername),file) != NULL) {
            storedUsername[strcspn(storedUsername, "\n")] = 0;

            fgets(storedPassword,sizeof(storedPassword),file);
            storedPassword[strcspn(storedPassword, "\n")] = 0;

            if(strcmp(username,storedUsername)==0 && strcmp(password,storedPassword)==0){
                printf("\n\n---Login Successful---\n\n\n");
                loggedIn=1;
                found=1;
                break;
            }

        }
        if (found==0){
            printf("Wrong password or username! ");
        }

    }
    fclose(file);
}

void postMenu(){
    int choice;

    while(run==1){
        printf("\n\n-------------------\n");
        printf("-  Post Menu  -");
        printf("\n-------------------\n\n");
        printf("- To Create a post = 1\n");
        printf("- To View posts    = 2\n");
        printf("- To Delete posts  = 3\n\n");
        printf("- To Logout        = 0");
        scanf("%d",&choice);
        getchar();

        switch (choice){
        case 1:
            createPost();
            break;

        case 2:
            viewPost();    
            break;

        case 3:
            deletePost();
            break;

        case 0:
            printf("\n\n-- Good Bye ! --\n\n");
            run=0;
            printf("\n\n--You have successfuly logged out!--\n\n");
            break;

        default:
            printf("Invalid choice selected");
            break;
        }
    }
}