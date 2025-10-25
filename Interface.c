#include <stdio.h>
#include <stdlib.h>
#include "linker.h"
void voterRegistration();
void candidateRegistration();

int main(){
    //Variable declaration
    int choice,offid, authoid=1234,g=0;
    while (g<1) { //for repeating after entered invaild Officer ID
        printf("\t==== Election System ===\n\n");
        
        printf("Enter Officer ID: ");  //Enter Officer ID to start the system
        scanf("%d", &offid);
        
        system("clear || cls"); // clear the screen after entered ID

        
        
        if(offid==authoid){     // officer id verification
            
            do{
                printf("\t==== Election System ===\n\n");
                
                //print options ask choice
                
                printf("1. Candidate Registration\n");
                printf("2. Voter Registration\n");
                printf("0. Exit \n\n");
                
                printf("Enter Your Choice: ");
                scanf("%d",&choice);
                
                system("clear || cls");  // clear the screen after select a option
                
                
                //call to switch to function the choices
                
                switch(choice){
                        
                    case 1:
                        printf("In a C R\n\n"); //entering the candidate registration
                        
                        break;
                        
                    case 2:
                        //entering the voter registration
                        break;
                        
                    case 0:
                        printf("Exiting... \nDone\n");
                        g++;//need to end this after entered 0
                        //Exit in the program
                        break;
                        
                    default:
                        printf("Invalid Number! \n");
                        
                        
                }
                
                
            }while(choice!=0);
            
        } 
		else{
            printf("Error! Invalid Officer ID !!!\n\n");
			// If id is invalid, then go to start again
            
            
        }
    }
 
 

 return 0;
}




