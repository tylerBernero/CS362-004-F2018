//Village

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>

#define NUM_TESTS 6
#define NUM_ITERATIONS 500
#define MAX_TESTS NUM_TESTS * NUM_ITERATIONS

int main()
{
    //get random number seed
    srand(time(NULL));                          
    
    //Keep track of number of Random Tests passes
    int numRandomTestsPassed = 0;
    
    printf("TESTING Village\n");
    
    //Loop number of NUM_ITERATIONS and get a different seed everytime in order to initiate a randomized game each run
    int j;
    for(j = 0; j < NUM_ITERATIONS; j++)
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
        
        int randSeed = rand();
        struct gameState GState;
        struct gameState oldGState;
        
        //Variables for cardEffect
        int choice1 = 0;
        int choice2 = 0;
        int choice3 = 0;
        int handPos = 0;
        int bonus = 0;
        
        //bools for changes in the game
        //0 = no differences
        //1 = differences
        int victoryChanges = 0;
        int kingdomChanges = 0;
        
        int i;
        
        
        //Initialize the game
        initializeGame(numPlayers, kingdomCards, randSeed, &GState);
        
        //TESTING Village
        //Valid unit tests because it tests:
        //1. Current player should receive exact 1 card then discard.
        //2. Cards should come from own draw pile
        //3. No state change should occur to the victory card piles 
        //4. No state change should occur to the kingdom card piles.
        //5. No state change should occur for other players.
        //6. Current player should receive exact 1 action.
        //printf("TESTING Village\n");
        
        //TEST 1: Ensure Current player receives 1 card then discards
        
        // copy the game state to a test case
    	memcpy(&oldGState, &GState, sizeof(struct gameState));
    	
    	//Note: Village is refactored into it's own function that is called from within cardEffect
    	cardEffect(village, choice1, choice2, choice3, &GState, handPos, &bonus);
    	if(GState.handCount[player1] == oldGState.handCount[player1] + 1 - 1)       //1 card from draw then -1 discard
    	{
    	    //printf("TEST 1: PASSED with correct number of cards in hand\n");
    	    numRandomTestsPassed++;
    	}
    	else
    	{
    	    //printf("TEST 1: FAILED with correct number of cards not in hand\n");
    	}
    	
    	//TEST 2: 1 card should be removed from player's own pile
    	
    	//Initialize new game
        initializeGame(numPlayers, kingdomCards, randSeed, &GState);
    	
    	// copy the game state to a test case
    	memcpy(&oldGState, &GState, sizeof(struct gameState));
    	
    	cardEffect(village, choice1, choice2, choice3, &GState, handPos, &bonus);
    	if(GState.deckCount[player1] == oldGState.deckCount[player1] - 1)
    	{
    	    //printf("TEST 2: PASSED with -1 card in deck\n");
    	    numRandomTestsPassed++;
    	}
    	else
    	{
    	    //printf("TEST 2: FAILED with -1 card not in deck\n");
    	}
    
        
        
        //TEST 3: No state change should occur to the victory card piles
        
        //Initialize new game
        initializeGame(numPlayers, kingdomCards, randSeed, &GState);
    	
    	// copy the game state to a test case
    	memcpy(&oldGState, &GState, sizeof(struct gameState));
    	
    	cardEffect(village, choice1, choice2, choice3, &GState, handPos, &bonus);
    
    	
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
    	    //printf("TEST 3: PASSED with no change in the victory cards\n");
    	    numRandomTestsPassed++;
    	}
    	else
    	{
    	    //printf("TEST 3: FAILED with change in the victory cards");
    	}
    	
    	//TEST 4: No state change should occur to the kingdom card piles.
    	
    	//Initialize new game
        initializeGame(numPlayers, kingdomCards, randSeed, &GState);
    	
    	// copy the game state to a test case
    	memcpy(&oldGState, &GState, sizeof(struct gameState));
    	
    	cardEffect(village, choice1, choice2, choice3, &GState, handPos, &bonus);
    	
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
    	    //printf("TEST 4: PASSED with no change in the kingdom cards\n");
    	    numRandomTestsPassed++;
    	}
    	else
    	{
    	    //printf("TEST 4: FAILED with change in the kingdom cards");
    	}
    	
    	//TEST 5: Ensure no state change for other players
    	
    	//Initialize new game
        initializeGame(numPlayers, kingdomCards, randSeed, &GState);
    	
    	// copy the game state to a test case
    	memcpy(&oldGState, &GState, sizeof(struct gameState));
    	
    	cardEffect(village, choice1, choice2, choice3, &GState, handPos, &bonus);
    	
    	//Check player 2's deck and hand to make sure no change was made between states
    	if(GState.handCount[player2] == oldGState.handCount[player2] && GState.deckCount[player2] == oldGState.deckCount[player2])
    	{
    	    //printf("TEST 5: PASSED with no change in other players\n");
    	    numRandomTestsPassed++;
    	}
    	else
    	{
    	    //printf("TEST 5: FAILED with change in other players\n");
    	}
    	
    	//TEST 6: Ensure current player gets +1 action
    	
    	//Initialize new game
        initializeGame(numPlayers, kingdomCards, randSeed, &GState);
    	
    	// copy the game state to a test case
    	memcpy(&oldGState, &GState, sizeof(struct gameState));
    	
    	cardEffect(village, choice1, choice2, choice3, &GState, handPos, &bonus);
    	
    	//Check player 1 gets +2 action
    	if(GState.numActions == oldGState.numActions + 2)   
    	{
    	    //printf("TEST 6: PASSED with +2 actions\n");
    	    numRandomTestsPassed++;
    	}
    	else
    	{
    	    //printf("TEST 6: FAILED with not +2 actions\n");
    	}
    	
    }
    
    printf("\n\nTESTING COMPLETE.\n%d RANDOM TESTS PASSED OUT OF %d TOTAL RANDOM TESTS\n\n\n", numRandomTestsPassed, MAX_TESTS);

    
    return 0;
}