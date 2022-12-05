#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#define BOARDLEN 8

void addQueen(int queensy[], int n);
int isThisSpotValid(int queensy[], int x, int y);
void printBoard(int queensy[]);

int main(){
	// starts in top left corner, on an 8x8 grid, values being from 0-7; each value represents the y value
	int queensy[BOARDLEN];

	// sets all queens way off of the board; except the first, that goes in the top left
	for (int i = 1; i < BOARDLEN; i++)
		queensy[i] = BOARDLEN*1000;
	queensy[0] = 0;

	system("cls");
	addQueen(queensy, 1);
	printBoard(queensy);
}

void addQueen(int queensy[], int x){
	if (x == BOARDLEN)
		return;
	else {
		for (int y = 1; y < BOARDLEN; y++){
			if (isThisSpotValid(queensy, x, y)){
				queensy[x] = y;
				addQueen(queensy, x + 1);
			}
		}
	}
}

int isThisSpotValid(int queensy[], int x, int y){
	int queenRatio, ratio;

	// check to see if any share y value (ie. horizontal similarity)
	for (int i = 0; i < BOARDLEN; i++)
		if (queensy[i] == y) return 0;

	// checks diagonal similarities like "/"
	ratio = y + x;
	for (int i = 0; i < BOARDLEN; i++){
		queenRatio = queensy[i] + i;
		if (ratio == queenRatio) return 0;
	}

	// checks diagonal similarities like "\"
	ratio = y - x;
	for (int i = 0; i < BOARDLEN; i++){
		queenRatio = queensy[i] - i;
		if (ratio == queenRatio) return 0;
	}

	return 1;
}

void printBoard(int queensy[]){
	for (int i = 0; i < BOARDLEN; i++){
		for (int j = 0; j < BOARDLEN; j++){
			if (queensy[j] == i)
				printf("X "); 
			else printf("0 ");
		}
		printf("\n");
	}
}