#include <stdio.h>
#include <stdlib.h>
#include "linker.h"
#include "globals.h"

void pasindu();
void vinuthi();
void castVote();
void showResults();

int main(){
    //file headers
    /*FILE *candidate;
    candidate = fopen("Candidate.txt" , "a");
    if (candidate == NULL) {
        printf("Error : Could not open Voter.txt file to save data.\n");
    }
    fprintf(candidate,"Registered Candidate \n");
    fprintf(candidate,"%-20s %-20s %-20s\n", "Party Name" ,"candidateId" , "Candidate Name" );

    fclose(candidate);
    FILE *voter;
    voter = fopen("Voter.txt" , "a");
    if (voter == NULL) {
        printf("Error : Could not open Voter.txt file to save data.\n");
    }
    fprintf(voter,"Registered Voters \n");
    fprintf(voter, "%-15s %-20s %-50s %-5s %-10s\n", "VoterID", "Name", "Address", "Age", "District");
    fclose(voter);*/
    
    
    //Variable declaration
    int choice,offid,secondOfficer,authoid=1234, headId=12345;
    int Option;
    int officerLoop = 0,mainLoop;
    
    
    
    
    while (officerLoop<1) { //for repeating after entered invaild Officer ID
        printf("\t==== Election System ===\n\n");
        
        printf("Enter Officer ID: ");  //Enter Officer ID to start the system
        scanf("%d", &offid);
        while (getchar() != '\n');
        
        system("clear || cls"); // clear the screen after entered ID
        
        if(offid==authoid){// officer id verification
            officerLoop++;
            mainLoop=1;
            while(mainLoop){
                printf("1. Register [Save data]\n");
                printf("2. Login [Verify eligibility]\n");
                printf("3. Show Results\n");
                printf("0. Exit \n");
                printf("Enter your Option: ");
                scanf("%d", &Option);
                while (getchar() != '\n');
                
                switch (Option) {
                    case 1:
                        do{
                            printf("\t==== Election System ===\n\n");
                            
                            //print options ask choice
                            
                            printf("1. Candidate Registration\n");
                            printf("2. Voter Registration\n");
                            printf("0. Back \n\n");
                            
                            printf("Enter Your Choice: ");
                            scanf("%d",&choice);
                            while (getchar() != '\n');
                            
                            //system("clear || cls");  // clear the screen after select a option
                            
                            
                            //call to switch to function the choices
                            
                            switch(choice){
                                    
                                case 1:
                                    printf("In a C R\n\n"); //entering the candidate registration
                                    pasindu();
                                    
                                    break;
                                    
                                case 2:
                                    printf("In a V R\n\n");//entering the voter registration
                                    vinuthi();
                                    break;
                                    
                                case 0:
                                    printf("Returning to Main Menu...\n");
                                    //Exit in the program
                                    break;
                                    
                                default:
                                    printf("Invalid Number! \n");
                                    
                                    
                            }
                            
                            
                        }while(choice!=0);
                        break;
                    case 2:
                        castVote();
                        break;
                    case 3:
                        printf("Enter Officer ID: ");  //Enter Officer ID to start the system
                        scanf("%d", &secondOfficer);
                        
                        if(secondOfficer==headId){

                            showResults();
                        }
                        break;
                    case 0:
                        printf("Exiting....\nDone\n");
                        mainLoop=0;
                        break;
                        
                    default:
                        printf("Invalid Option!\n");

                        break;
                }


               
            }

            
            
        }
        else{
            printf("Error! Invalid Officer ID !!!\n\n");
            // If id is invalid, then go to start again
            
            
        }
    }
 
 

 return 0;
}
void showResults() {
    system("clear || cls"); // clear the screen after entered ID

    printf("\nElection Results:\n");
    printf("===================================\n");
    printf("%-20s %-15s %-5s\n", "Candidate Name", "Party", "Votes");

    int maxVotes = sC[0].voteCount; // start with first candidate's votes
    int winnerIndex = 0;

    // Print all candidates and find the one with max votes
    for (int i = 0; i < candidateCount; i++) {
        printf("%-20s %-15s %-5d\n",
               sC[i].savedCName, sC[i].savedParty, sC[i].voteCount);

        if (sC[i].voteCount > maxVotes) {
            maxVotes = sC[i].voteCount;
            winnerIndex = i;
        }
    }

    printf("===================================\n");
    
    FILE *file = fopen("Candidate.txt", "w");
    for (int i = 0; i < candidateCount; i++) {
        fprintf(file, "%s %s %d\n", sC[i].savedCName, sC[i].savedParty, sC[i].voteCount);
    }
    fclose(file);

    // Check if no votes at all
    if (maxVotes == 0) {
        printf("No votes have been cast yet!\n");
    } else {
        printf("Winner Party: %s\n", sC[winnerIndex].savedParty);
        printf("Winner Candidate: %s \n",
               sC[winnerIndex].savedCName);
    }
}


