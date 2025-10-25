#include <stdio.h>
#include <stdlib.h>
#include "linker.h"
void voterRegistration();
void candidateRegistration();
void castVote();
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
    int choice,offid, authoid=1234;
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




