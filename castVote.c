#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linker.h"
#include "globals.h"

/*this part should be orginal fille

struct savedvoter {
    char savedVoted[10];   // "0" = not voted, "1" = voted
    char savedId[20];
    char savedVName[100];
};

struct savedcandidate {
    char savedParty[50];
    char savedCandidateId[20];
    int savedNumber;
    char savedCName[100];
    int voteCount;
};*/

// Global arrays
struct savedvoter sV[100];
struct savedcandidate sC[100];
int voterCount = 0, candidateCount = 0;

void targetCandidateList(char *targetParty, char *voterId);

void castVote() {
    char Id[20], targetParty[50];
    int found = 0, choosenParty;

    printf("Enter your ID = ");
    scanf("%s", Id);
    while (getchar() != '\n'); // clear buffer

    //Load voters
    FILE *sVoter = fopen("Voter.txt", "r");
    if (!sVoter) {
        printf("Error: Could not open Voter.txt\n");
        return;
    }
    voterCount = 0;
    while (fscanf(sVoter, "%s %s %[^\n]",
                  sV[voterCount].savedVoted,
                  sV[voterCount].savedId,
                  sV[voterCount].savedVName) == 3) {
        voterCount++;
    }
    fclose(sVoter);

    //Load candidates
    FILE *sCandidate = fopen("Candidate.txt", "r");
    if (!sCandidate) {
        printf("Error: Could not open Candidate.txt\n");
        return;
    }

    candidateCount = 0;
    while (fscanf(sCandidate, "%49s %19s %d %[^\n]",
                  sC[candidateCount].savedParty,
                  sC[candidateCount].savedCandidateId,
                  &sC[candidateCount].savedNumber,
                  sC[candidateCount].savedCName) == 4) {
        candidateCount++;
    }    fclose(sCandidate);

    //Check voter
    for (int i = 0; i < voterCount; i++) {
        if (strcmp(sV[i].savedId, Id) == 0) {
            found = 1;
            
            
            //Check if already voted
            if (strcmp(sV[i].savedVoted, "1") == 0) {
                printf("You have already voted! You cannot vote again.\n");
                return;
            }

                        
            printf("1. Blue Party\n");
            printf("2. Green Party\n");
            printf("3. Red Party\n");
            printf("4. Yellow Party\n");
            printf("5. Pink Party\n");
            printf("Enter your chosen party number: ");
            scanf("%d", &choosenParty);

            switch (choosenParty) {
                case 1: strcpy(targetParty, "Blue_Party"); break;
                case 2: strcpy(targetParty, "Green_Party"); break;
                case 3: strcpy(targetParty, "Red_Party"); break;
                case 4: strcpy(targetParty, "Yellow_Party"); break;
                case 5: strcpy(targetParty, "Pink_Party"); break;
                default:
                    printf("Invalid party number!\n");
                    return;
            }

            targetCandidateList(targetParty, Id);
            break;
        }
    }

    if (!found)
        printf("Voter ID not found!\n");
}

void targetCandidateList(char *targetParty, char *voterId) {
    printf("\nCandidate Number    Candidate Name\n");
    printf("===================================\n");

    for (int i = 0; i < candidateCount; i++) {
        if (strcmp(sC[i].savedParty, targetParty) == 0) {
            printf("%-20d %s\n", sC[i].savedNumber, sC[i].savedCName);
        }
    }

    int chosenCandidateNumber;
    printf("\nEnter the candidate number you want to vote for: ");
    scanf("%d", &chosenCandidateNumber);

    for (int j = 0; j < candidateCount; j++) {
        if (sC[j].savedNumber == chosenCandidateNumber) {
            printf("You voted for: %s (%s)\n",
                   sC[j].savedCName, sC[j].savedParty);
            sC[j].voteCount++;
            break;
        }
    }

    // Mark voter as voted
    for (int j = 0; j < voterCount; j++) {
        if (strcmp(sV[j].savedId, voterId) == 0) {
            strcpy(sV[j].savedVoted, "1");
            break;
        }
    }

    //Update voter file
    FILE *updateVoterFile = fopen("Voter.txt", "w");
    if (!updateVoterFile) {
        printf("Error: Could not open Voter.txt for updating.\n");
        return;
    }

    for (int j = 0; j < voterCount; j++) {
        fprintf(updateVoterFile, "%s %s %s\n",
                sV[j].savedVoted, sV[j].savedId, sV[j].savedVName);
    }
    system("clear || cls"); // clear the screen after entered ID


    fclose(updateVoterFile);
    printf("Vote recorded successfully!\n");
}
