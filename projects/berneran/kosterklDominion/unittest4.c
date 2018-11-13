//compare()

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

#define NUM_TESTS 15

int main()
{
    //Variables
    const void* x;
    const void* y;
    int numTestsPassed = 0;
    
    //TEST COMPARE()
    //Valid unit tests because covers cases of positive/negative/boundary values
    //Note: Testing return values because compare does not change the state of the game
    printf("TESTING compare()\n");
    
    //TEST 1: x = y where no boundary cases are used
    x = (int*)1;
    y = (int*)1;
    if(compare(&x, &y) == 0)
    {
        printf("TEST 1: PASSED when x = y where no boundary cases are used\n");
        numTestsPassed++;
    }
    else
    {
        printf("TEST 1: FAILED when x = y where no boundary cases are used\n");
    }
    
    //TEST 2: x > y where no boundary cases are used
    x = (int*)1;
    y = (int*)-1;
    if(compare(&x, &y) == 1)
    {
        printf("TEST 2: PASSED when x > y where no boundary cases are used\n");
        numTestsPassed++;
    }
    else
    {
        printf("TEST 2: FAILED when x > y where no boundary cases are used\n");
    }
    
    //TEST 3: x > y where y is boundary 0
    x = (int*)1;
    y = (int*)0;
    if(compare(&x, &y) == 1)
    {
        printf("TEST 3: PASSED when x > y where y is boundary 0\n");
        numTestsPassed++;
    }
    else
    {
        printf("TEST 3: FAILED when x > y where y is boundary 0\n");
    }
    
    //TEST 4: x > y where y is boundary INT_MIN
    x = (int*)1;
    y = (int*)INT_MIN;
    if(compare(&x, &y) == 1)
    {
        printf("TEST 4: PASSED when x > y where y is boundary INT_MIN\n");
        numTestsPassed++;
    }
    else
    {
        printf("TEST 4: FAILED when x > y where y is boundary INT_MIN\n");
    }
    
    //TEST 5: x > y where y is boundary INT_MAX
    x = (int*)1;
    y = (int*)INT_MAX;
    if(compare(&x, &y) == -1)
    {
        printf("TEST 5: PASSED when x > y where y is boundary INT_MAX\n");
        numTestsPassed++;
    }
    else
    {
        printf("TEST 5: FAILED when x > y where y is boundary INT_MAX\n");
    }
    
    //TEST 6: x < y where no boundary cases are used
    x = (int*)-1;
    y = (int*)1;
    if(compare(&x, &y) == -1)
    {
        printf("TEST 6: PASSED when x < y where no boundary cases are used\n");
        numTestsPassed++;
    }
    else
    {
        printf("TEST 6: FAILED when x < y where no boundary cases are used\n");
    }
    
    //TEST 7: x < y where y is boundary 0
    x = (int*)-1;
    y = (int*)0;
    if(compare(&x, &y) == -1)
    {
        printf("TEST 7: PASSED when x < y where y is boundary 0\n");
        numTestsPassed++;
    }
    else
    {
        printf("TEST 7: FAILED when x < y where y is boundary 0\n");
    }
    
    //TEST 8: x < y where y is boundary INT_MAX
    x = (int*)-1;
    y = (int*)INT_MAX;
    if(compare(&x, &y) == -1)
    {
        printf("TEST 8: PASSED when x < y where y is boundary INT_MAX\n");
        numTestsPassed++;
    }
    else
    {
        printf("TEST 8: FAILED when x < y where y is boundary INT_MAX\n");
    }
    
    //TEST 9: x < y where x is boundary 0
    x = (int*)0;
    y = (int*)1;
    if(compare(&x, &y) == -1)
    {
        printf("TEST 9: PASSED when x < y where x is boundary 0\n");
        numTestsPassed++;
    }
    else
    {
        printf("TEST 9: FAILED when x < y where x is boundary 0\n");
    }
    
    //TEST 10: x > y where x is boundary 0
    x = (int*)0;
    y = (int*)-1;
    if(compare(&x, &y) == 1)
    {
        printf("TEST 10: PASSED when x > y where x is boundary 0\n");
        numTestsPassed++;
    }
    else
    {
        printf("TEST 10: FAILED when x > y where x is boundary 0\n");
    }
    
    //TEST 11: x > y where x is boundary 0 and y is boundary INT_MIN
    x = (int*)0;
    y = (int*)INT_MIN;
    if(compare(&x, &y) == 1)
    {
        printf("TEST 11: PASSED when x > y where x is boundary 0 and y is boundary INT_MIN\n");
        numTestsPassed++;
    }
    else
    {
        printf("TEST 11: FAILED when x > y where x is boundary 0 and y is boundary INT_MIN\n");
    }
    
    //TEST 12: x < y where x is boundary INT_MIN and y is boundary INT_MAX
    x = (int*)INT_MIN;
    y = (int*)INT_MAX;
    if(compare(&x, &y) == -1)
    {
        printf("TEST 12: PASSED when x < y where x is boundary INT_MIN and y is boundary INT_MAX\n");
        numTestsPassed++;
    }
    else
    {
        printf("TEST 12: FAILED when x < y where x is boundary INT_MIN and y is boundary INT_MAX\n");
    }
    
    //TEST 13: x < y where x is boundary INT_MIN and y is boundary 0
    x = (int*)INT_MIN;
    y = (int*)0;
    if(compare(&x, &y) == -1)
    {
        printf("TEST 13: PASSED when x < y where x is boundary INT_MIN and y is boundary 0\n");
        numTestsPassed++;
    }
    else
    {
        printf("TEST 13: FAILED when x < y where x is boundary INT_MIN and y is boundary 0\n");
    }
    
    //TEST 14: x > y where x is boundary INT_MAX and y is boundary 0
    x = (int*)INT_MAX;
    y = (int*)0;
    if(compare(&x, &y) == 1)
    {
        printf("TEST 14: PASSED when  x > y where x is boundary INT_MAX and y is boundary 0\n");
        numTestsPassed++;
    }
    else
    {
        printf("TEST 14: FAILED when  x > y where x is boundary INT_MAX and y is boundary 0\n");
    }
    
    //TEST 15: x = y where x,y are boundary INT_MAX
    x = (int*)INT_MAX;
    y = (int*)INT_MAX;
    if(compare(&x, &y) == 0)
    {
        printf("TEST 15: PASSED when  x = y where x,y are boundary INT_MAX\n");
        numTestsPassed++;
    }
    else
    {
        printf("TEST 15: FAILED when  x = y where x,y are boundary INT_MAX\n");
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