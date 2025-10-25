#include <stdio.h>
#include<string.h>
int main() 
{
    char name[50];
    int userID,g=0;
    char party;
    printf("<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>\n");
    printf("        PARTY SELECTION MENU         \n");
    printf("=====================================\n");
    printf(" B - Blue Party\n");
    printf(" G - Green Party\n");
    printf(" R - Red Party\n");
    printf(" Y - Yellow Party\n");
    printf(" P - Pink Party\n");
    printf("-------------------------------------\n");
    while(g<1)
    {
    printf("Enter your name:");
    scanf("%s",name);

    printf("Enter your user ID: ");
    scanf("%d",&userID);

    printf("Enter your party name first letter (B/G/R/Y/P): ");
    scanf(" %c", &party);
    switch (party)
    {
    case 'B':
    case 'b':
        printf("\nCandidate Name: %s\nUser ID: %d\nParty: Blue Party\n", name, userID);
        break;
        
    case 'G':
    case 'g':
        printf("\nCandidate Name: %s\nUser ID: %d\nParty: Green Party\n", name, userID);
        break;

    case 'R':
    case 'r':
        printf("\nCandidate Name: %s\nUser ID: %d\nParty: Red Party\n", name, userID);
        break;

    case 'Y':
    case 'y':
        printf("\nCandidate Name: %s\nUser ID: %d\nParty: Yellow Party\n", name, userID);
        break;


    case 'P':
    case 'p':
        printf("\nCandidate Name: %s\nUser ID: %d\nParty: Pink Party\n", name, userID);
        break;
    
    default:
        printf("Invalid party selection!\n");
        main();
        break;
    }
    }
}
