#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "linker.h"
struct savedvoter{
    char savedVoted[10];   // "0" for not voted, "1" for voted
    char savedId[20];
    char savedVName[100];
};
struct savedcandidate{
    char savedCName[50],savedParty[20],savedCandidateId[20];
    int savedNumber;

};

struct savedvoter sV[100];
struct savedcandidate sC[50];
void targetCandidateList(char *targetParty, char *voterId);
int voterCount = 0,i,candidateCount = 0,chosenCandidateNumber;

void castVote(){
    int choosenParty,choosenLoop;
    char line[256];
    char Id[20];
    char targetParty[20];
    int found = 0,votedLoop = 0;
    
    
    char partyWord1[20];
    char partyWord2[20];
    
    printf("Enter the your ID = ");
    scanf("%s",Id);
    while (getchar() != '\n');//remove the \n
    
    FILE *sVoter;
    sVoter = fopen("Voter.txt","r");
    
    if (sVoter == NULL) {
        printf("Error : Could not open Voter.txt file to save data.\n");
    }
    
    while (fscanf(sVoter, "%s %s %[^\n]", sV[voterCount].savedVoted, sV[voterCount].savedId, sV[voterCount].savedVName) != EOF) {
            voterCount++;
    }
    fclose(sVoter);
    
    
    FILE *sCandidate;
    sCandidate = fopen("Candidate.txt","r");
    
    if (sCandidate == NULL) {
        printf("Error : Could not open Voter.txt file to save data.\n");
    }
    
    while (fscanf(sCandidate,"%19s %19s %19s %d %[^\n]",partyWord1,partyWord2,sC[candidateCount].savedCandidateId,&sC[candidateCount].savedNumber,sC[candidateCount].savedCName) != EOF) {
            
            // Combine "Blue" and "Party" into "Blue Party" formatted output into a srting
            sprintf(sC[candidateCount].savedParty, "%s %s", partyWord1, partyWord2);
            
            candidateCount++;
        }
    fclose(sCandidate);
    
    
    for (i=0; i<voterCount; i++) {
        if (strcmp(sV[i].savedId,Id) == 0  ) {
            found = 1;
            choosenLoop = 0;
            while (choosenLoop<1) {
                printf("1. Blue Party\n");
                printf("2. Green Party\n");
                printf("3. Red Party\n");
                printf("4. Yellow Party\n");
                printf("5. Pink Party\n");
                
                printf("Enter your choosen party number :");
                scanf("%d",&choosenParty);
                
                switch (choosenParty) {
                    case 1:
                        //Blue
                        strcpy(targetParty, "Blue Party");
                        targetCandidateList(targetParty,Id);

                        choosenLoop = 1;
                        
                        break;
                    case 2:
                        //green
                        strcpy(targetParty, "Green Party");
                        targetCandidateList(targetParty,Id);

                        choosenLoop = 1;
                        break;
                    case 3:
                        //red
                        strcpy(targetParty, "Red Party");
                        targetCandidateList(targetParty,Id);

                        choosenLoop = 1;
                        break;
                    case 4:
                        //yellow
                        strcpy(targetParty, "Yellow Party");
                        targetCandidateList(targetParty,Id);

                        choosenLoop = 1;
                        break;
                    case 5:
                        //pink
                        strcpy(targetParty, "Pink Party");
                        targetCandidateList(targetParty,Id);

                        choosenLoop = 1;

                        break;

                        
                    default:
                        break;
                }
            }//while end

                            
            
            
            
            

            break;

        }
    }
    
    if (!found) {
        printf("Voter ID not found!\n");
    }
    
    
    
    
}

void targetCandidateList(char *targetParty, char *voterId){
    char Id[20];
    printf("\nCandidate Number    Candidate Name\n");
    printf("===================================\n");
    for (int i = 0; i < candidateCount; i++) {
        if (strcmp(sC[i].savedParty,targetParty) == 0) {
            printf("%-20d %s\n", sC[i].savedNumber, sC[i].savedCName);
        }

    }
    
    printf("\nEnter the candidate number you want to vote for: ");
    scanf("%d", &chosenCandidateNumber);
    
    for (int j = 0; j < candidateCount; j++) {
        if (sC[j].savedNumber == chosenCandidateNumber) {
            printf("You voted for: %s (%s)\n", sC[j].savedCName, sC[j].savedParty);
            break;
        }
    }
    printf(updateVoter, "%s %s %s\n", sV[j].savedVoted, sV[j].savedId, sV[j].savedVName);

    /*for (int j = 0; j < voterCount; j++) {
        if (strcmp(sV[j].savedId,voterId) == 0) {
            strcpy(sV[j].savedVoted, "1");
            break;
        }
    }
    
    
    FILE *updateVoter = fopen("Voter.txt", "w");
    if (updateVoter == NULL) {
        printf("Error: Could not update Voter.txt\n");
        return;
    }

    for (int j = 0; j < voterCount; j++) {
        fprintf(updateVoter, "%s %s %s\n", sV[j].savedVoted, sV[j].savedId, sV[j].savedVName);
    }
    fclose(updateVoter);*/
    printf("Vote recorded successfully! Updated voters saved in updateVoter.txt\n");
    
    
    
    
}



