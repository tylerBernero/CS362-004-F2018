//isGameOver()

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>

#define NUM_TESTS 3

int main()
{
    //Variables needed to initialize a game
    int numPlayers = 2;
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
    int i;
    
    
    //Initialize the game
    initializeGame(numPlayers, kingdomCards, randSeed, &GState);
    
    //TESTING ISGAMEOVER()
    //Valid unit tests because it tests all cases of return statements
    //Note: Testing return values because isGameOver() does not directly change the state of the game
    printf("TESTING isGameOver()\n");
    
    //TEST 1: Empty stack of province cards returns 1
    GState.supplyCount[province] = 0;       //Set suuplyCount[province] to 0 to test case in isGameOver
    if( isGameOver(&GState) == 1)
    {
        printf("TEST 1: PASSED when province cards are empty\n");
        numTestsPassed++;
    }
    else
    {
        printf("TEST 1: FAILED when province cards are empty\n");
    }
    
    //TEST 2: 2 supplyCounts are 0 returns 0
    for(i = 0; i < 2; i++)                  //Set 2 supplycounts to 0
    {
        GState.supplyCount[i] = 0;
    }
    
    if(isGameOver(&GState) == 1)            //Game is not over if 2 supplyCounts are empty
     {
        printf("TEST 2: PASSED when 2 supplyCounts are empty\n");
        numTestsPassed++;
    }
    else
    {
        printf("TEST 2: FAILED when 2 supplyCounts are empty\n");
    }
    
    
    //Test3: 4 supplyCounts are 0 returns 1
        for(i = 0; i < 4; i++)                  //Set 4 supplycounts to 0
    {
        GState.supplyCount[i] = 0;
    }
    
    if(isGameOver(&GState) == 1)            //Game is not over if 4 supplyCounts are empty
     {
        printf("TEST 3: PASSED when 4 supplyCounts are empty\n");
        numTestsPassed++;
    }
    else
    {
        printf("TEST 3: FAILED when 4 supplyCounts are empty\n");
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