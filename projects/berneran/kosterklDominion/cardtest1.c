//Smithy

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>

#define NUM_TESTS 5

int main()
{
    //Variables needed to initialize a game
    int numPlayers = 2;
    int player1 = 0;
    int player2 = 1;
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
    
    //Variables for cardEffect
    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0;
    int handPos = 0;
    int bonus = 0;
    
    int numTestsPassed = 0;
    int i;
    
    //bools for changes in the victory or kingdom piles
    //0 = no differences
    //1 = differences
    int victoryChanges = 0;
    int kingdomChanges = 0;
    
    
    //Initialize the game
    initializeGame(numPlayers, kingdomCards, randSeed, &GState);
    
    //TESTING SMITHY
    //Valid unit tests because it tests:
    //1. Current player should receive exact 3 cards then discard.
    //2. Cards should come from own draw pile
    //3. No state change should occur for other players.
    //4. No state change should occur to the victory card piles 
    //5. No state change should occur to the kingdom card piles.
    //Note: Test cases provided by professor
    printf("TESTING Smithy\n");
    
    //TEST 1: Ensure Current player receives 3 cards then discards
    
    // copy the game state to a test case
	memcpy(&oldGState, &GState, sizeof(struct gameState));
	
	//Note: Smithy is refactored into it's own function that is called from within cardEffect
	//Note: Assignment 2 a bug was placed here that gave the player 5 cards instead of 3, so this test should fail
	cardEffect(smithy, choice1, choice2, choice3, &GState, handPos, &bonus);
	if(GState.handCount[player1] == oldGState.handCount[player1] + 3 - 1)   //+3 cards from draw then -1 discard
	{
	    printf("TEST 1: PASSED with correct number of cards in hand\n");
	    numTestsPassed++;
	}
	else
	{
	    printf("TEST 1: FAILED with correct number of cards not in hand\n");
	}
	
	//TEST 2: 3 cards should be removed from player's own pile
	
	// copy the game state to a test case
	memcpy(&oldGState, &GState, sizeof(struct gameState));
	
	//Note: Assignment 2 a bug was placed here that gave the player 5 cards instead of 3, so this test should fail
	cardEffect(smithy, choice1, choice2, choice3, &GState, handPos, &bonus);
	if(GState.deckCount[player1] == oldGState.deckCount[player1] - 3)
	{
	    printf("TEST 2: PASSED with -3 cards in deck\n");
	    numTestsPassed++;
	}
	else
	{
	    printf("TEST 2: FAILED with -3 cards not in deck\n");
	}
	
	//TEST 3: Ensure no state change for other players
	
	// copy the game state to a test case
	memcpy(&oldGState, &GState, sizeof(struct gameState));
	
	cardEffect(smithy, choice1, choice2, choice3, &GState, handPos, &bonus);
	
	//Check player 2's deck and hand to make sure no change was made between states
	if(GState.handCount[player2] == oldGState.handCount[player2] && GState.deckCount[player2] == oldGState.deckCount[player2])
	{
	    printf("TEST 3: PASSED with no change in other players\n");
	    numTestsPassed++;
	}
	else
	{
	    printf("TEST 3: FAILED with change in other players\n");
	}
	    
	    
	//TEST 4: No state change should occur to the victory card piles
	
	// copy the game state to a test case
	memcpy(&oldGState, &GState, sizeof(struct gameState));
	
	cardEffect(smithy, choice1, choice2, choice3, &GState, handPos, &bonus);

	
	//Check state of victory cards (1-3 in the supply count)
	for(i = 1; i < 4; i++)
	{
	    if(GState.supplyCount[i] != oldGState.supplyCount[i])
	    {
	        //indicate changes in victory pile if states do not match
	        victoryChanges = 1;
	    }
	}
	
	if(victoryChanges == 0)
	{
	    printf("TEST 4: PASSED with no change in the victory cards\n");
	    numTestsPassed++;
	}
	else
	{
	    printf("TEST 4: FAILED with change in the victory cards");
	}
	
	//TEST 5: No state change should occur to the kingdom card piles.
	
	// copy the game state to a test case
	memcpy(&oldGState, &GState, sizeof(struct gameState));
	
	cardEffect(smithy, choice1, choice2, choice3, &GState, handPos, &bonus);
	
	//Check state of kingdom cards (7-27 in the supply count)
	for(i = 7; i < 27; i++)
	{
	    if(GState.supplyCount[i] != oldGState.supplyCount[i])
	    {
	        //indicate changes in victory pile if states do not match
	        kingdomChanges = 1;
	    }
	}
	
	if(kingdomChanges == 0)
	{
	    printf("TEST 5: PASSED with no change in the kingdom cards\n");
	    numTestsPassed++;
	}
	else
	{
	    printf("TEST 5: FAILED with change in the kingdom cards");
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