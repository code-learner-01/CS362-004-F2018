/*
Daniel Bauman
CS362 - Assignment 3
unittest2.c
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTFUNC "whoseTurn"

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

       
    // Test 1: Function returns same value for both G1 and G2
    if(whoseTurn(&G2) == whoseTurn(&G1)) {
        printf("Test 1 Passed (Returns same value)\n");
    } else {
        printf("Test 1 Failed (Returns same value)\n");
        failCount++;
    }

    // Test 2: Change G2's turn, then compare again to G1
    G2.whoseTurn ++;

    if(whoseTurn(&G2) != whoseTurn(&G1)) {
        printf("Test 2 Passed (Returns same value)\n");
    } else {
        printf("Test 2 Failed (Value correctly changed)\n");
        failCount++;
    }






    printf("\n\n>>>>> Testing complete (%s) <<<<<\n", TESTFUNC);
    printf(">>>>> Errors detected: %d <<<<<\n\n", failCount);
    return 0;
}