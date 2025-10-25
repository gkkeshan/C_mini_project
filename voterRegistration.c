#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "linker.h"

struct voter{
    char voterId[20];
    char voterName[50];
    char voterDistrict[10];
    char voterAddress[100];
    int voted;
    int voterAge;
};
struct voter v[100];
int k = 0;
void vinuthi() {
    
    char voterId[20];
    char voterName[50];
    char voterDistrict[10];
    char voterAddress[100];
    int voterAge,idLenght,i,valid = 1,idLoop = 0;

    // Loop for Get voter ID
    while (idLoop<1) {
        valid = 1;
        printf("=== Voter Registration System ===\n");

        // Get voter ID
        printf("Enter Voter ID (12 characters): ");
        scanf("%s", voterId);

        // Check voter ID length
        idLenght = strlen(voterId);
        // Check for old NIC format (9 digits + 1 letter)
        if (idLenght == 10) {
            for (i=0; i<9; i++) {
                if (!isdigit(voterId[i])) {
                    valid = 0;
                    break;
                }
                // Last character should be V or X (uppercase or lowercase)
                else if (!(voterId[9] == 'V' || voterId[9] == 'v' || voterId[9] == 'X' || voterId[9] == 'x')){
                    valid = 0;
                }
            }
        }
        // Check for new NIC format (12 digits)
        else if (idLenght == 12) {
            for (i=0; i<12; i++) {
                if (!isdigit(voterId[i])) {
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
            idLoop++;
        }
        else{
            system("clear || cls");
            printf("Invalid NIC number.\n");
        }
    }
    
    
    
    
    

    // Get name
    printf("Enter Name: ");
    getchar();
    fgets(voterName, sizeof(voterName), stdin);
    voterName[strcspn(voterName, "\n")] = '\0';
    v[k].voted = 0;


    // Get district
    printf("Are you from Colombo district (yes / no): ");
    fgets(voterDistrict, sizeof(voterDistrict), stdin);
    voterDistrict[strcspn(voterDistrict, "\n")] = '\0';

    // check if the answer is "yes" or "YES"
    if (strcmp(voterDistrict, "yes") != 0 && strcmp(voterDistrict, "YES") != 0) {
        printf("Error: Only voters from Colombo district can register.\n");
    }

    // Get address
    printf("Enter Address: ");
    fgets(voterAddress, sizeof(voterAddress), stdin);
    voterAddress[strcspn(voterAddress, "\n")] = '\0';

    // Get age
    printf("Enter Age: ");
    scanf("%d", &voterAge);

    //Check age
    if (voterAge < 18) {
        printf("Error: Voter must be 18 or older to register.\n");
    }
    k++;
    v[k].voterAge = voterAge ;
    strcpy(v[k].voterId,voterId);
    strcpy(v[k].voterName,voterName);
    strcpy(v[k].voterAddress,voterAddress);
    strcpy(v[k].voterDistrict,voterDistrict);
    
    //save the data voter.txt
    FILE *voter;
    voter = fopen("Voter.txt" , "a");
    if (voter == NULL) {
        printf("Error : Could not open Voter.txt file to save data.\n");
    }
    fprintf(voter, "%-1d %-20s %-30s\n", v[k].voted, v[k].voterId, v[k].voterName);
    fclose(voter);
    
    FILE *voterall;
    voterall = fopen("Voter_Alldetails","a");
    if (voterall == NULL) {
        printf("Error : Could not open Voter.txt file to save data.\n");
    }
    fprintf(voterall,"%-20s %-30s %-50s %-10d %-20s\n",v[k].voterId,v[k].voterName,v[k].voterAddress,v[k].voterAge,v[k].voterDistrict);
    fclose(voterall);

    //If all conditions are valid
    printf("\nVoter Registered Successfully!\n");
    printf("Data saved to voters.txt\n");

}
