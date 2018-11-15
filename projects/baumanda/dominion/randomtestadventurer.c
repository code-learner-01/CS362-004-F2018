/*
Daniel Bauman
randomtestadventurer.c (adventurer)
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "adventurer"

int main() {
    int i, j;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 1000;
    int thisPlayer = 0;
		struct gameState G, testG;
		int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
									sea_hag, tribute, smithy, council_room};
		// int kcards_randomized[10];
		int numPlayers_randomized;
		int handCount_randomized;
		int deckCount_randomized;
		int discardCount_randomized;
		int failCount = 0;

		srand(time(0));
		int loopCount = 1000;

		for (i=0; i<loopCount; i++){			
			//Step 1: Set up initial variables (random and non-random)

			// Set a number of players between 2 and 4
			numPlayers_randomized = (rand() % (MAX_PLAYERS - 2 + 1) + 2);

			// Set a random handCount between 1 and 500
			handCount_randomized = (rand() % (MAX_HAND -1 + 1) + 1);

			// Set a random deckCount between 1 and 500
			deckCount_randomized = (rand() % (MAX_DECK -1 + 1) + 1);

			// Set a random discardCount between 0 and 1000
			discardCount_randomized = rand() % 1001;

			// Step 2: Initialize game state
			initializeGame(numPlayers_randomized, k, seed, &G);

			// Step 3: Set the game state variables for each player
			for (j=0; j<numPlayers_randomized; j++){
				G.handCount[j] = handCount_randomized;
				G.deckCount[j] = deckCount_randomized;
				G.discardCount[j] = discardCount_randomized;	
			}

			// Step 4: memcpy game state into a test state and call cardEffect()
			memcpy(&testG, &G, sizeof(struct gameState));
			cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

			// Step 5: Run tests

			// Test 1: Was hand count increased by 1 (+2 cards, and 1 card discarded)?
			if(testG.handCount[thisPlayer] != G.handCount[thisPlayer] + 1){
				failCount++;
			}

			// Test 2: Was deck count decreased by 2?
			if(testG.deckCount[thisPlayer] != G.deckCount[thisPlayer] - 2){
				failCount++;
			}

			// Test 3: Are the last two cards in the player's hand treasure cards?
			int card1 = testG.hand[thisPlayer][testG.handCount[thisPlayer]-1];
			int card2 = testG.hand[thisPlayer][testG.handCount[thisPlayer]-2];

			if (card1 != copper || card1 != silver || card1 != gold){
				failCount++;
			} else if (card2 != copper || card2 != silver || card2 != gold) {
				failCount++;
			}


		}

		

	printf("\n\n>>>>> Testing complete (%s) <<<<<\n", TESTCARD);
	printf(">>>>> Errors detected: %d in %d runs <<<<<\n\n", failCount, loopCount);
	return 0;
}

