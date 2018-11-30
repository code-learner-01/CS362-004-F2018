/*
Daniel Bauman
CS362 - Assignment 3
unittest3.c
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTFUNC "scoreFor"

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


    // Test 1: Function returns same value for both states
    if(scoreFor(0, &G2) == scoreFor(0, &G1)){
        printf("Test 1 Passed (Returns score of %d)\n", scoreFor(0, &G2));
    } else {
        printf("Test 1 Failed (Return same score)\n");
        failCount++;
    }

    // Test 2: Add a province card to G2's hand, then compare score to G1 again
    G2.handCount[0]++;
    G2.hand[0][G2.handCount[0]] = province;

    if(scoreFor(0, &G2) != scoreFor(0, &G1)){
        printf("Test 2 Passed (Score changed)");
    } else {
        printf("Test 2 Failed (Score changed)\n");
        failCount++;
    }







    printf("\n\n>>>>> Testing complete (%s) <<<<<\n", TESTFUNC);
    printf(">>>>> Errors detected: %d <<<<<\n\n", failCount);
    return 0;
}