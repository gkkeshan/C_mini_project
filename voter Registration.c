#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
    char voterID[13];
    char voterName[50];
    char voterDistrict[10];
    char voterAddress[100];
    int voterAge;

    printf("=== Voter Registration System ===\n");

    // Get voter ID
    printf("Enter Voter ID (12 characters): ");
    scanf("%s", voterID);

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

    // Get district
    printf("Are you from Kaluthara district (yes / no): ");
    fgets(voterDistrict, sizeof(voterDistrict), stdin);
    voterDistrict[strcspn(voterDistrict, "\n")] = '\0'; 

    // check if the answer is "yes" or "YES"
    if (strcmp(voterDistrict, "yes") != 0 && strcmp(voterDistrict, "YES") != 0) {
        printf("Error: Only voters from Kaluthara district can register.\n");
        return 0;
    }

    // Get address
    printf("Enter Address: ");
    fgets(voterAddress, sizeof(voterAddress), stdin);
    voterAddress[strcspn(voterAddress, "\n")] = '\0'; 

    // Get age
    printf("Enter Age: ");
    scanf("%d", &voterAge);

    // Check age
    if (voterAge < 18) {
        printf("Error: Voter must be 18 or older to register.\n");
        return 0;
    }

    // If all conditions are valid
    printf("\nVoter Registered Successfully!\n");

    return 0;
