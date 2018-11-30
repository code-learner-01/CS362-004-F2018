/*
Daniel Bauman
cardtest3.c
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "village"

int main() {
    int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
		struct gameState G, testG;
		int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
									sea_hag, tribute, smithy, council_room};
		int failCount = 0;

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	// Make game states G and testG identical
	memcpy(&testG, &G, sizeof(struct gameState));

	printf("\nTesting Card: %s\n", TESTCARD);

	// Implement card effect
	cardEffect(village, choice1, choice2, choice3, &testG, handpos, &bonus);


	// Test 1: Was hand count increased by 0 (1 Card drawn, Village card discarded)?
	if(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + 0){
		printf("Test 1 Passed (Hand count)\n");
	} else {
		printf("Test 1 Failed (Hand count)\n");
		failCount++;
	}

	// Test 2: Was deck count decreased by 1?
	if(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - 1){
		printf("Test 2 Passed (Deck count)\n");
	} else {
		printf("Test 2 Failed (Deck count)\n");
		failCount++;
	}

	// Test 3: Was number of actions increased by 2?
	if(testG.numActions == G.numActions + 2){
		printf("Test 3 Passed (Number of actions)\n");
	} else {
		printf("Test 3 Failed (Number of actions)\n");
		failCount++;
	}

	// Test 4: Was discard count increased by 1?
	if(testG.discardCount == G.discardCount + 1){
		printf("Test 4 Passed (Discard count)\n");
	} else {
		printf("Test 4 Failed (Discard count)\n");
		failCount++;
	}



	printf("\n\n>>>>> Testing complete (%s) <<<<<\n", TESTCARD);
	printf(">>>>> Errors detected: %d <<<<<\n\n", failCount);
	return 0;
}

