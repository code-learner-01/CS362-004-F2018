/*
Daniel Bauman
CS362 - Assignment 3
unittest4.c
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTFUNC "getCost"

int main() {
    int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G1, G2;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
	int failCount = 0;

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G1);

	// Make game states G and testG identical
	memcpy(&G2, &G1, sizeof(struct gameState));

    printf("\nTesting Function: %s\n", TESTFUNC);

       
    // Test 1: Returns correct value for province (cardNumber 3, value 8)
     if(getCost(3) == 8) {
        printf("Test 1 Passed (Return province cost)\n");
    } else {
        printf("Test 1 Failed (Return province cost)\n");
        failCount++;
    }

    // Test 2: Returns correct value for duchy (cardNumber 2, value 5)
     if(getCost(2) == 5) {
        printf("Test 2 Passed (Return duchy cost)\n");
    } else {
        printf("Test 2 Failed (Return duchy cost)\n");
        failCount++;
    }

        // Test 2: Returns correct value for estate (cardNumber 1, value 2)
     if(getCost(1) == 2) {
        printf("Test 3 Passed (Return estate cost)\n");
    } else {
        printf("Test 3 Failed (Return estate cost)\n");
        failCount++;
    }






    printf("\n\n>>>>> Testing complete (%s) <<<<<\n", TESTFUNC);
    printf(">>>>> Errors detected: %d <<<<<\n\n", failCount);
    return 0;
}