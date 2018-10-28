/*
Daniel Bauman
CS362 - Assignment 3
unittest1.c
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTFUNC "numHandCards"

int main() {
    int i, j, m;
    int handpos = 0;
    int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G1, G2;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
	int failCount = 0;

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G1);

	// Make game states G1 and G2 identical
	memcpy(&G2, &G1, sizeof(struct gameState));

    printf("\nTesting Function: %s\n", TESTFUNC);

    // Make a change to test the function
    G2.handCount[thisPlayer] += 1;


    // Test 1: Function returns correct value
    if(numHandCards(&G2) == numHandCards(&G1) + 1){
        printf("Test 1 Passed (Return value)\n");
    } else {
        printf("Test 1 Failed (Return value)\n");
        failCount++;
    }





    printf("\n\n>>>>> Testing complete (%s) <<<<<\n", TESTFUNC);
    printf(">>>>> Errors detected: %d <<<<<\n\n", failCount);
    return 0;
}