//numHandCards()

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
    
    int numTestsPassed = 0;
    
    //Initialize the game
    initializeGame(numPlayers, kingdomCards, randSeed, &GState);
    
    //TESTING NUMHANDCARDS()
    //Valid unit tests because it tests positive, negative, and zero number of cards in hand
    //Note: Testing return values because numHandsCards() does not directly change the state of the game
    printf("TESTING numHandCards()\n");
    
    //TEST 1: numHandCards() returns positive number in players hand
    GState.handCount[player1] = 25;                 //Manually set player hand to 25 cards
    if(numHandCards(&GState) == 25)
    {
        printf("TEST 1: PASSED when 25 cards in hand\n");
        numTestsPassed++;
    }
    else
    {
        printf("TEST 1: FAILED when 25 cards in hand\n");
    }
    
    //TEST 2: numHandCards() returns 0 in players hand
    GState.handCount[player1] = 0;
    if(numHandCards(&GState) == 0)
    {
        printf("TEST 2: PASSED when 0 cards in hand\n");
        numTestsPassed++;
    }
    else
    {
        printf("TEST 2: FAILED when 0 cards in hand\n");
    }
    
    //TEST 3: numHandCards() returns negative number in players hand
    GState.handCount[player1] = -5;
    if(numHandCards(&GState) == -5)
    {
        printf("TEST 3: PASSED when -5 cards in hand\n");
        numTestsPassed++;
    }
    else
    {
        printf("TEST 3: FAILED when -5 cards in hand\n");
    }
    
    //TEST 4: numHandCards() returns another positive number in players hand
    GState.handCount[player1] = 500;
    if(numHandCards(&GState) == 500)
    {
        printf("TEST 4: PASSED when 500 cards in hand\n");
        numTestsPassed++;
    }
    else
    {
        printf("TEST 4: FAILED when 500 cards in hand\n");
    }
    
    //TEST 5: numHandCards() returns another negative number in players hand
    GState.handCount[player1] = -250;
    if(numHandCards(&GState) == -250)
    {
        printf("TEST 5: PASSED when -250 cards in hand\n");
        numTestsPassed++;
    }
    else
    {
        printf("TEST 5: FAILED when -250 cards in hand\n");
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