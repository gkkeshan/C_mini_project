#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>


//main functions
void pasindu();
void vinuthi();
void castVote();
void showResults();


//semi functions
void deatils(char *partyName);

//structures
struct candidate{
    char name[50],candidateId[20],party[20];
    int number;
};
struct voter{
    char voterId[20];
    char voterName[50];
    char voterDistrict[10];
    char voterAddress[100];
    int voted;
    int voterAge;
};
struct savedVoter{
    char savedVoted[10];
    char savedId[20];
    char savedName[100];
    
};

struct savedcandidate{
    char savedCName[50],savedParty[200],savedCandidateId[20];
    int savedNumber;
};

struct savedVoter sV[100];
struct candidate c[50];
struct voter v[100];
void targetCandidateList(char *targetParty, char *voterId);
struct savedcandidate sC[50];



//local veriable
char candidateId[20];
char name[50];
char party,x[20];
int ch,n = 0;
int k = 0;
int voterCount = 0,i,j,candidateCount = 0,chosenCandidateNumber;




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
				printf("\t==== Election System ===\n\n");
                printf("1. Voters & Candidates Registration \n");
                printf("2. For Voting \n");
				printf("3. Show Election Results\n"); 

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
                            
                           
                      
                            
                            //call to switch to function the choices
                            
                            switch(choice){
                                    
                                case 1:
                                    //entering the candidate registration
                                    pasindu();
                                    
                                    break;
                                    
                                case 2:
                                    //entering the voter registration
                                    vinuthi();
                                    break;
									
                                    
                                case 0:
                                    printf("Returning to Main Menu...\n\n");
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
						showResults();
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



//candidate registration fun
void pasindu(){
	system("clear || cls");
    int partyLoop = 0;
    while (partyLoop<1) {
		
		printf("\t==== Election System ===\n\n");
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
                strcpy(x, "Blue Party");
                deatils(x);
                partyLoop++;
                break;
                
            case 'G':
            case 'g':
                strcpy(x, "Green Party");
                deatils(x);
                partyLoop++;
                break;
                
            case 'R':
            case 'r':
                strcpy(x, "Red Party");
                deatils(x);
                partyLoop++;
                break;
                
            case 'Y':
            case 'y':
                strcpy(x, "Yellow Party");
                deatils(x);
                partyLoop++;
                break;
                
                
            case 'P':
            case 'p':
                strcpy(x, "Pink Party");
                deatils(x);
                partyLoop++;
                break;
                
            default:
                printf("Invalid party selection!\n");
                break;
        }
    }
}

//Id loop and get the deatils from candidate
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
        printf("Enter your NIC: ");
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
                // Last character should be V  (uppercase or lowercase)
                else if (!(candidateId[9] == 'V' || candidateId[9] == 'v')){
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
			system("clear || cls");
            printf("Invalid NIC number.\n");

        }
        
    }
    
    
}


//voter registration fun
void vinuthi() {
    
    char voterId[20];
    char voterName[50];
    char voterDistrict[10];
    char voterAddress[100];
    int voterAge,idLenght,i,valid = 1,idLoop = 0;
	system("clear || cls");
	
    // Loop for Get voter ID
    while (idLoop<1) {
        valid = 1;
		
        printf("=== Voter Registration ===\n\n");

        // Get voter ID
        printf("Enter Voter NIC (12 characters): ");
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
                else if (!(voterId[9] == 'V' || voterId[9] == 'v')){
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
            printf("Invalid NIC number! \n\n");
        }
    }
    
	
// Check if voter is already registered
for (int t = 0; t < k; t++) {
    if (strcmp(v[t].voterId, voterId) == 0) {
        printf("Error: This voter is already registered!\n");
        return; // Stop registration
    }
}

 //check in file to prevent duplicates 
FILE *voterFile = fopen("Voter.txt", "r");
if (voterFile != NULL) {
    char tempVoted[10], tempId[20], tempName[100];
    while (fscanf(voterFile, "%9s %19s %99[^\n]", tempVoted, tempId, tempName) == 3) {
        if (strcmp(tempId, voterId) == 0) {
            printf("Error: This voter is already registered!\n");
            fclose(voterFile);
            return;
        }
    }
    fclose(voterFile);
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
		return;
    }

    // Get address
    printf("Enter Address: ");
    fgets(voterAddress, sizeof(voterAddress), stdin);
    voterAddress[strcspn(voterAddress, "\n")] = '\0';

    // Get age
    printf("Enter Age: ");
    scanf("%d", &voterAge);
	printf("%d", voterAge);
	
    //Check age
    if (voterAge >= 18) {
		
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
		
		fprintf(voter, "%-5d %-20s %-30s\n", v[k].voted, v[k].voterId, v[k].voterName);
		fclose(voter);
    
		FILE *voterall;
		voterall = fopen("Voter_Alldetails.txt","a");
		if (voterall == NULL) {
			printf("Error : Could not open Voter.txt file to save data.\n");
		}
		
		fprintf(voterall,"%-20s %-30s %-50s %-10d %-20s\n",v[k].voterId,v[k].voterName,v[k].voterAddress,v[k].voterAge,v[k].voterDistrict);
		fclose(voterall);

		//If all conditions are valid
		system("clear || cls");
		system("clear || cls");
		printf("\nVoter Registered Successfully!\n");
		printf("\n");
		
	}
	
	
	else{
		
		system("clear || cls");
		printf("Error: Voter must be 18 or older to register! \n");
	}

	
}




//get the vote fun
void castVote(){
    int choosenParty, choosenLoop;
    char Id[64];
    int found = 0;
    char targetParty[64];

    // temp buffers for reading candidate file
    char partyWord1[64];
    char partyWord2[64];

    // reset counts before loading to avoid duplicates in memory
    voterCount = 0;
    candidateCount = 0;

    // --- read voters into sV[] ---
    FILE *sVoter = fopen("Voter.txt","r");
    if (sVoter == NULL) {
        printf("Error : Could not open Voter.txt file to read data.\n");
        return;
    }
    while (fscanf(sVoter, "%9s %19s %99[^\n]", sV[voterCount].savedVoted, sV[voterCount].savedId, sV[voterCount].savedName) == 3) {
        voterCount++;
    }
    fclose(sVoter);

    // --- read candidates into sC[] ---
    FILE *sCandidate = fopen("Candidate.txt","r");
    if (sCandidate == NULL) {
        printf("Error : Could not open Candidate.txt file to read data.\n");
        // still can proceed if you want, but usually return
        return;
    }
    while (fscanf(sCandidate,"%63s %63s %19s %d %49[^\n]",
                  partyWord1, partyWord2,
                  sC[candidateCount].savedCandidateId,
                  &sC[candidateCount].savedNumber,
                  sC[candidateCount].savedCName) == 5) {

        // safe combine into savedParty (use snprintf)
        snprintf(sC[candidateCount].savedParty, sizeof(sC[candidateCount].savedParty), "%s %s", partyWord1, partyWord2);

        candidateCount++;
    }
    fclose(sCandidate);
	system("clear || cls");
	printf("\t==== Election System ===\n\n");
    // --- ask for voter ID ---
    printf("\nEnter your ID: ");
    if (scanf("%63s", Id) != 1) {
        while (getchar() != '\n');
        printf("Input error.\n");
        return;
    }
    while (getchar() != '\n');

    // --- find voter and check voted flag ---
    int voterIndex = -1;
    for (int t = 0; t < voterCount; t++) {
        if (strcmp(sV[t].savedId, Id) == 0) {
            voterIndex = t;
            break;
        }
    }

    if (voterIndex == -1) {
        printf("Voter ID not found!\n");
        return;
    }

    // if they've already voted, refuse
    if (strcmp(sV[voterIndex].savedVoted, "1") == 0) {
		system("clear || cls");
        printf("\n >>> You have already voted. Multiple voting is not allowed <<< \n\n");
        return;
    }

    // check age of voter: if you stored age, you should load and check it.
    // (Your current Voter.txt format has no age field in the savedV array; add if needed.)
    // Proceed to party selection
    choosenLoop = 0;
    while (choosenLoop < 1) {
		printf("\n\t Choose a Party \n");
		printf("=====================================\n");
        printf("1. Blue Party\n");
        printf("2. Green Party\n");
        printf("3. Red Party\n");
        printf("4. Yellow Party\n");
        printf("5. Pink Party\n");

        printf("Enter your chosen party number: ");
        if (scanf("%d", &choosenParty) != 1) {
            while (getchar() != '\n');
            printf("Invalid input.\n");
            return;
        }
        while (getchar() != '\n');

        switch (choosenParty) {
            case 1: strcpy(targetParty, "Blue Party"); choosenLoop = 1; break;
            case 2: strcpy(targetParty, "Green Party"); choosenLoop = 1; break;
            case 3: strcpy(targetParty, "Red Party"); choosenLoop = 1; break;
            case 4: strcpy(targetParty, "Yellow Party"); choosenLoop = 1; break;
            case 5: strcpy(targetParty, "Pink Party"); choosenLoop = 1; break;
            default: printf("Invalid choice! Try again.\n"); break;
        }
    }

    // Show only candidates for the chosen party
    targetCandidateList(targetParty, Id);

    // After targetCandidateList returns, chosenCandidateNumber should be set (you already do that)
    // Find the candidate and record the vote (append to a votes file)
    int candIdx = -1;
    for (int j = 0; j < candidateCount; j++) {
        if (sC[j].savedNumber == chosenCandidateNumber && strcmp(sC[j].savedParty, targetParty) == 0) {
            candIdx = j;
            break;
        }
    }

    if (candIdx == -1) {
        printf("Invalid candidate number selected.\n");
        return;
    }



    // Append the vote (voterID, party, candidateName) to votes.txt
   /* FILE *fv = fopen("votes.txt", "a");
    if (fv == NULL) {
        printf("Error: cannot open votes.txt to record vote.\n");
        return;
    }
    fprintf(fv, "%s %s %s %d\n", sV[voterIndex].savedId, sC[candIdx].savedParty, sC[candIdx].savedCName, sC[candIdx].savedNumber);
    fclose(fv);  */
	
	
	

    // Mark voter as voted in memory
    strncpy(sV[voterIndex].savedVoted, "1", sizeof(sV[voterIndex].savedVoted)-1);
    sV[voterIndex].savedVoted[sizeof(sV[voterIndex].savedVoted)-1] = '\0';

    // Write BACK the updated voter list to a temporary file, then replace Voter.txt
    FILE *tmp = fopen("Voter.tmp", "w");
    if (tmp == NULL) {
        printf("Error: could not create temporary voter file.\n");
        return;
    }
    for (int t = 0; t < voterCount; t++) {
        fprintf(tmp, "%s %s %s\n", sV[t].savedVoted, sV[t].savedId, sV[t].savedName);
    }
    fclose(tmp);

    // Replace original file (remove old and rename)
    if (remove("Voter.txt") != 0) {
        // non-fatal: print warning and continue to rename (may fail)
        // printf("Warning: unable to remove original Voter.txt\n");
    }
    if (rename("Voter.tmp", "Voter.txt") != 0) {
        printf("Warning: could not rename temp voter file to Voter.txt\n");
    }

    printf(">>> Vote recorded successfully! You cannot vote again <<<\n\n");
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
    //printf(updateVoter, "%s %s %s\n", sV[j].savedVoted, sV[j].savedId, sV[j].savedVName);

    for (int j = 0; j < voterCount; j++) {
        if (strcmp(sV[j].savedId, voterId) == 0) {
            strcpy(sV[j].savedVoted, "1");
            break;
        }
    }

    FILE *updateVoter = fopen("updateVoter.txt", "w");
    if (updateVoter == NULL) {
        printf("Error: Could not create updateVoter.txt\n");
        return;
    }

    for (int j = 0; j < voterCount; j++) {
        fprintf(updateVoter, "%s %s %s\n", sV[j].savedVoted, sV[j].savedId, sV[j].savedName);
    }
    fclose(updateVoter);

    
}



void showResults() {
    FILE *fv = fopen("votes.txt", "r");
    if (fv == NULL) {
        printf("No votes have been cast yet or file not found.\n");
        return;
    }

    char voterId[50], partyWord1[50], partyWord2[50], party[100], candidateName[100];
    int candidateNumber;
    int voteCount[100] = {0};
    char candidateList[100][100];
    char partyList[100][100];
    int candidateNumList[100];
    int totalCandidates = 0;

    // Read votes with two-word party names
    while (fscanf(fv, "%49s %49s %49s %99s %d", voterId, partyWord1, partyWord2, candidateName, &candidateNumber) == 5) {
        snprintf(party, sizeof(party), "%s %s", partyWord1, partyWord2);

        int found = 0;
        for (int i = 0; i < totalCandidates; i++) {
            if (candidateNumList[i] == candidateNumber && strcmp(candidateList[i], candidateName) == 0) {
                voteCount[i]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(candidateList[totalCandidates], candidateName);
            strcpy(partyList[totalCandidates], party);
            candidateNumList[totalCandidates] = candidateNumber;
            voteCount[totalCandidates] = 1;
            totalCandidates++;
        }
    }
    fclose(fv);

    if (totalCandidates == 0) {
        printf("No votes found.\n");
        return;
    }

    int maxVotes = 0, winnerIndex = 0;
    for (int i = 0; i < totalCandidates; i++) {
        if (voteCount[i] > maxVotes) {
            maxVotes = voteCount[i];
            winnerIndex = i;
        }
    }

    system("clear || cls");
    printf("\n========== Election Results ==========\n");
    for (int i = 0; i < totalCandidates; i++) {
        printf("%-20s (%-15s) - %d votes\n", candidateList[i], partyList[i], voteCount[i]);
    }
    printf("\n-------------------------------------\n");
    printf("Winner: %s from %s with %d votes!\n", candidateList[winnerIndex], partyList[winnerIndex], maxVotes);

    FILE *result = fopen("Results.txt", "w");
    fprintf(result, "========== Election Results ==========\n");
    for (int i = 0; i < totalCandidates; i++) {
        fprintf(result, "%-20s (%-15s) - %d votes\n", candidateList[i], partyList[i], voteCount[i]);
    }
    fprintf(result, "\n-------------------------------------\n");
    fprintf(result, "WINNER is:- %s from %s with %d votes! \n Congratulations!!! \n", candidateList[winnerIndex], partyList[winnerIndex], maxVotes);
    fclose(result);
	exit(0);
}



