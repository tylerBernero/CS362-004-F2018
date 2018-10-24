CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

unittestresults: unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c dominion.o rngs.o
	gcc -o ut1 -g unittest1.c dominion.o rngs.o $(CFLAGS)
	echo "unittest1.c:" > unittestresults.out
	./ut1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	gcc -o ut2 -g unittest2.c dominion.o rngs.o $(CFLAGS)
	echo "unittest2.c:" >> unittestresults.out
	./ut2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	gcc -o ut3 -g unittest3.c dominion.o rngs.o $(CFLAGS)
	echo "unittest3.c:" >> unittestresults.out
	./ut3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	gcc -o ut4 -g unittest4.c dominion.o rngs.o $(CFLAGS)
	echo "unittest4.c:" >> unittestresults.out
	./ut4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	gcc -o ct1 -g cardtest1.c dominion.o rngs.o $(CFLAGS)
	echo "cardtest1.c:" >> unittestresults.out
	./ct1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	gcc -o ct2 -g cardtest2.c dominion.o rngs.o $(CFLAGS)
	echo "cardtest2.c:" >> unittestresults.out
	./ct2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	gcc -o ct3 -g cardtest3.c dominion.o rngs.o $(CFLAGS)
	echo "cardtest3.c:" >> unittestresults.out
	./ct3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	gcc -o ct4 -g cardtest4.c dominion.o rngs.o $(CFLAGS)
	echo "cardtest4.c:" >> unittestresults.out
	./ct4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
unit1: unittest1.c dominion.o rngs.o
	gcc -o ut1 unittest1.c dominion.o rngs.o $(CFLAGS)
	./ut1
	
unit2: unittest2.c dominion.o rngs.o
	gcc -o ut2 unittest2.c dominion.o rngs.o $(CFLAGS)
	./ut2
	
unit3: unittest3.c dominion.o rngs.o
	gcc -o ut3 unittest3.c dominion.o rngs.o $(CFLAGS)
	./ut3
	
unit4: unittest4.c dominion.o rngs.o
	gcc -o ut4 unittest4.c dominion.o rngs.o $(CFLAGS)
	./ut4

card1: cardtest1.c dominion.o rngs.o
	gcc -o ct1 cardtest1.c dominion.o rngs.o $(CFLAGS)
	./ct1
	
card2: cardtest2.c dominion.o rngs.o
	gcc -o ct2 cardtest2.c dominion.o rngs.o $(CFLAGS)
	./ct2
	
card3: cardtest3.c dominion.o rngs.o
	gcc -o ct3 cardtest3.c dominion.o rngs.o $(CFLAGS)
	./ct3
	
card4: cardtest4.c dominion.o rngs.o
	gcc -o ct4 cardtest4.c dominion.o rngs.o $(CFLAGS)
	./ct4
	
clean:
	rm -f *.o ut1 ut2 ut3 ut4 ct1 ct2 ct3 ct4 playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
