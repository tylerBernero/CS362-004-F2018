#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

//GLobal Variables for the char* to work between functions
char randString[6];

char inputChar()
{
    // TODO: rewrite this function
    
    //Create pool of characters for randChar to "pool" from
    //Consists of all possible letters/symbols for all target statements
    char inputPool[14] = "[({ ax})]rest";
    
    //Find random value between 0-12
    int randValue = rand() % 13;
    
    //store the randValue's position from inputPool into randChar and return
    char randChar = inputPool[randValue];
    return randChar;
}

char *inputString()
{
    // TODO: rewrite this function
    
    //memset randString everytime to prevent anything bad from happening
    memset(randString, '\0', 6);
    
    int i;
    
    //iterate 5 times to ensure that the returned string can spell the targeted statement
    for(i = 0; i < 5; i++)
    {
      //Call get inputChar() because its pool contains the letters we need for targeted statement
      randString[i] = inputChar();
    }

    return randString;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
