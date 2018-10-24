//drawCards()

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>

#define NUM_TESTS 4

int main()
{
    //Variables needed to initialize a game
    int numPlayers = 2;
    int player1 = 0;
    int kingdomCards[10] = {                               //kingdom cards the game can choose from
        adventurer, 
        gardens, 
        embargo, 
        village, 
        minion, 
        mine, 
        cutpurse,
        sea_hag, 
        tribute, 
        smithy
    };
    srand(time(NULL));                          //get random number seed
    int randSeed = rand();
    struct gameState GState;
    struct gameState oldGState;
    
    int numTestsPassed = 0;
    
    //Initialize the game
    initializeGame(numPlayers, kingdomCards, randSeed, &GState);
    
    //TESTING DRAWCARDS()
    //Valid unit tests because covers cases of cards being added to hand and removed from deck
    //It also tests for instances where the player has 0 cards left in their deck and thus has to call shuffle
    printf("TESTING drawCards()\n");
    
    //TEST 1: Ensure 1 card is added to player hand
    
    // copy the game state to a test case
	memcpy(&oldGState, &GState, sizeof(struct gameState));
	drawCard(player1, &GState);
	if(GState.handCount[player1] == oldGState.handCount[player1] + 1)
	{
	    printf("TEST 1: PASSED with +1 card in hand\n");
	    numTestsPassed++;
	}
	else
	{
	    printf("TEST 1: FAILED with +1 card not in hand\n");
	}
	
	//TEST 2: Ensure 1 card is subtracted from player deck
    
    // copy the game state to a test case
	memcpy(&oldGState, &GState, sizeof(struct gameState));
	drawCard(player1, &GState);
	if(GState.deckCount[player1] == oldGState.deckCount[player1] - 1)
	{
	    printf("TEST 2: PASSED with -1 card in deck\n");
	    numTestsPassed++;
	}
	else
	{
	    printf("TEST 2: FAILED with -1 card not in deck\n");
	}
	
	//TEST 3: Ensure 1 card is added to player hand when deck is 0 which causes player to shuffle
	//Manually set player deck to 0 to force drawCard() to shuffle
	GState.deckCount[player1] = 0;
    
    // copy the game state to a test case
	memcpy(&oldGState, &GState, sizeof(struct gameState));
	
	drawCard(player1, &GState);
	if(GState.handCount[player1] == oldGState.handCount[player1] + 1)
	{
	    printf("TEST 3: PASSED with +1 card in hand when deckCount is 0\n");
	    numTestsPassed++;
	}
	else
	{
	    printf("TEST 3: FAILED with +1 card not in hand when deckCount is 0\n");
	}
	
	//TEST 4: Ensure 1 card is subtracted from player deck when deck is 0 which causes player to shuffle
	//Manually set player deck to 0 to force drawCard() to shuffle
	GState.deckCount[player1] = 0;
    
    // copy the game state to a test case
	memcpy(&oldGState, &GState, sizeof(struct gameState));
	
	drawCard(player1, &GState);
	if(GState.deckCount[player1] == oldGState.deckCount[player1] - 1)
	{
	    printf("TEST 4: PASSED with +1 card in deck when deckCount is 0\n");
	    numTestsPassed++;
	}
	else
	{
	    printf("TEST 4: FAILED with +1 card not in deck when deckCount is 0\n");
	}
	
	
	//ALL TESTS PASSED OR NO?
    if(numTestsPassed == NUM_TESTS)
    {
        printf("ALL TESTS PASSED!\n");
    }
    else
    {
        printf("AT LEAST ONE TEST FAILED!\n");
    }
    
    
    return 0;
}