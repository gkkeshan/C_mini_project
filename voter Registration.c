#include <stdio.h>
#include <string.h>

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
    if (strlen(voterID) != 12) {
        printf("Error: Voter ID must be 12 characters long.\n");
        return 0;
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
