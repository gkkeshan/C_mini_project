#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//#include "linker.h"
//#include "globals.h"

struct candidate{
    char name[50],candidateId[20],party[20];
    int number;
};
void deatils(char *partyName);

char candidateId[20];
char name[50];
char party,x[20];
int ch,n=0;
struct candidate c[50];

void pasindu(){
    int partyLoop = 0;
    while (partyLoop<1) {
        printf("<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>\n");
        printf("        PARTY SELECTION MENU         \n");
        printf("=====================================\n");
        printf(" B - Blue Party\n");
        printf(" G - Green Party\n");
        printf(" R - Red Party\n");
        printf(" Y - Yellow Party\n");
        printf(" P - Pink Party\n");
        printf("-------------------------------------\n");
        
        
        printf("Enter your party name first letter (B/G/R/Y/P): ");
        scanf(" %c", &party);
        while ((ch = getchar()) != '\n' && ch != EOF);
        switch (party){
            case 'B':
            case 'b':
                strcpy(x, "Blue_Party");
                deatils(x);
                partyLoop++;
                break;
                
            case 'G':
            case 'g':
                strcpy(x, "Green_Party");
                deatils(x);
                partyLoop++;
                break;
                
            case 'R':
            case 'r':
                strcpy(x, "Red_Party");
                deatils(x);
                partyLoop++;
                break;
                
            case 'Y':
            case 'y':
                strcpy(x, "Yellow_Party");
                deatils(x);
                partyLoop++;
                break;
                
                
            case 'P':
            case 'p':
                strcpy(x, "Green_Party");
                deatils(x);
                partyLoop++;
                break;
                
            default:
                printf("Invalid party selection!\n");
                break;
        }
    }
}
void deatils(char *partyName){
    int idLenght,i,valid = 1,idLoop = 0;
    srand(time(0));
    n++;
    
    printf("Enter your name:");
    fgets(name,sizeof(name),stdin);
    name[strcspn(name, "\n")] = 0;
    idLoop = 0;
    while (idLoop<1) {
        valid = 1;
        printf("Enter your ID: ");
        scanf("%s",candidateId);
        

        // Check voter ID length
        idLenght = strlen(candidateId);
        // Check for old NIC format (9 digits + 1 letter)
        if (idLenght == 10) {
            for (i=0; i<9; i++) {
                if (!isdigit(candidateId[i])) {
                    valid = 0;
                    break;
                }
                // Last character should be V or X (uppercase or lowercase)
                else if (!(candidateId[9] == 'V' || candidateId[9] == 'v' || candidateId[9] == 'X' || candidateId[9] == 'x')){
                    valid = 0;
                }
            }
        }
        // Check for new NIC format (12 digits)
        else if (idLenght == 12) {
            for (i=0; i<12; i++) {
                if (!isdigit(candidateId[i])) {
                    valid = 0;
                    break;
                }
            }
        }
        else{
            valid = 0;
        }
        
        if (valid == 1) {
            //vaild
            int randomNumber = rand() % 100 + 1;// Random number between 1–100
            //sprintf(randomStr, "%d", randomNumber);
            n++;
            idLoop++;
            c[n].number = randomNumber;
            strcpy(c[n].party,partyName);
            strcpy(c[n].name,name);
            strcpy(c[n].candidateId,candidateId);            

            FILE *candidate;
            candidate = fopen("Candidate.txt","a");
            
            if (candidate == NULL) {
                printf("Error : Could not open Voter.txt file to save data.\n");
            }

            fprintf(candidate, "%-20s %-20s %-10d %-20s\n",c[n].party, c[n].candidateId, c[n].number, c[n].name);
            fclose(candidate);
            system("clear || cls");
            printf("Your number will be : %d", c[n].number);
            printf("\nCandidate data saved ....!!\n\n");


        }
        else {
            //system("clear || cls");
            printf("Invalid NIC number.\n");

        }
        
    }
    
    
}

