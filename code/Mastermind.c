/* MASTERMIND 
1) Si deve definire un codice segreto composto da 5 numeri code[5] dove ogni numero dev'essere compreso tra 1-6
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DMAX 5
#define MAXTURNS 9

int main() {
	int i,j;
	int turnback=0;
	int arrayCode[DMAX];
	int arrayPlayer[DMAX];
	int turn;
	int truePosition;
	int trueNumber;
	int numGames=0;
	int gamesWon=0;
	int gamesLost;
	time_t t;
	
	
	do {
		printf("Hello! This is a Mastermind game. The computer will generate %d numbers.\n", DMAX);
		printf("You have to make your suggestions and if you insert the correct numbers on their correct place, you are the winner!.\n");
		printf("You have only %d turns. Good luck!\n", MAXTURNS);
		printf("You can choose only numbers between 1 and 6.\n");
		numGames=numGames+1;
		srand(time(&t));
	  for (i=0; i<DMAX; i=i+1) {
	  	arrayCode[i]=rand()%6;
	  }
	  
	  /*
	  printf("Coded Array:\n");
	  for (i=0; i<DMAX; i=i+1) {
	  	printf("%d ", arrayCode[i]);
	  } */
	  
	  for (turn=0; turn<MAXTURNS; turn=turn+1) {
	  	printf("\n__________________________________________________________________________\n");
	  	printf("It's your %d turn. You have %d turns left.\n", turn+1, MAXTURNS-(turn+1));
	  	printf("Insert the %d numbers of your array.\n", DMAX);
	  	truePosition=0;
	  	trueNumber=0;
	  	for (i=0; i<DMAX; i=i+1) {
	  		printf("Insert number %d: ", i+1);
	  		scanf("%d", &arrayPlayer[i]);
		  }
		for (i=0; i<DMAX; i=i+1) {
			if (arrayCode[i]==arrayPlayer[i]) {
				truePosition=truePosition+1;
			} else {
			}
		}
		for (i=0; i<DMAX; i=i+1) {
			for (j=0; j<DMAX; j=j+1) {
				if (arrayPlayer[i]==arrayCode[j]) {
					trueNumber=trueNumber+1;
					j=DMAX;
				} else {
				}
			}
		}
		if (truePosition==DMAX) {
			printf("\n__________________________________________________________________________\n");
			printf("You WON!\n");
			printf("You found %d numbers on their correct position.\n", truePosition);
			gamesWon=gamesWon+1;
			turn=MAXTURNS;
		} else {
			printf("\n__________________________________________________________________________\n");
			printf("You found %d numbers on the correct place.\n", truePosition);
			printf("You found %d numbers, but not on their correct place.\n", trueNumber);
		}
	  }
		printf("\n__________________________________________________________________________\n");
		printf("If you want to play another game press 0.\n");
		printf("If you want to exit press any other key.\n");
		printf("Option: ");
		scanf("%d", &turnback);	
	} while (turnback==0);
	printf("\n__________________________________________________________________________\n");
	printf("You played %d games.\n", numGames);
	printf("I won %d games.\n", gamesWon);
	gamesLost=numGames-gamesWon;
	printf("I lost %d games.\n", gamesLost);
	getch();
	return 0;
}
