#ifndef GLOBALS_H
#define GLOBALS_H

// Voter struct
struct savedvoter {
    char savedVoted[10];   // "0" = not voted, "1" = voted
    char savedId[20];
    char savedVName[100];
};

// Candidate struct
struct savedcandidate {
    char savedParty[50];
    char savedCandidateId[20];
    int savedNumber;
    char savedCName[100];
    int voteCount;   // vote counter
};

// Shared globals
extern struct savedvoter sV[100];
extern struct savedcandidate sC[100];
extern int voterCount;
extern int candidateCount;

#endif
