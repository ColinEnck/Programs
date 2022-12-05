#include <stdio.h>

//creates the playing board
int board[3][3] = {
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0}
};

//prints example board
void printExampleBoard();
//prints the current board
void printBoard();
//lets player 1 make their move
void player1Move();
//lets player 2 make their move
void player2Move();
//checks if a player has won: returns 1 if p1 won; returns 2 if p2 won; returns 0 if neither
int winningPlayer();
//checks if the game ended in a tie
int isTie();

int main(){
  printExampleBoard();
  printBoard();
  while (winningPlayer() == 0){
    player1Move();
    printBoard();
    if (winningPlayer() == 1){
      printf("\n\n---------------\n|PLAYER 1 WINS|\n---------------\n\n");
      break;
    } else if (isTie() == 1){
      printf("\n\n----------\n|IT'S A TIE|\n----------\n\n");
    }
    player2Move();
    printBoard();
    if (winningPlayer() == 2){
      printf("\n\n---------------\n|PLAYER 2 WINS|\n---------------\n\n");
      break;
    } else if (isTie() == 1){
      printf("\n\n----------------\n|IT'S A TIE|\n----------------\n\n");
    }
  }
  return 0;
}

void printExampleBoard(){
  printf("Example of the board:\n");
  printf(" %d | %d | %d \n", 1, 2, 3);
  printf("---|---|---\n");
  printf(" %d | %d | %d \n", 4, 5, 6);
  printf("---|---|---\n");
  printf(" %d | %d | %d \n\n\n", 7, 8, 9);
}

void printBoard(){
  printf(" %d | %d | %d \n", board[1][1], board[1][2], board[1][3]);
  printf("---|---|---\n");
  printf(" %d | %d | %d \n", board[2][1], board[2][2], board[2][3]);
  printf("---|---|---\n");
  printf(" %d | %d | %d \n\n", board[3][1], board[3][2], board[3][3]);
}

void player1Move(){
  int p1Move;
  printf("P1: ");
  scanf("%d", &p1Move);
  switch(p1Move){
  case 1:
    if (board[1][1] == 1 || board[1][1] == 2){
      printf("Invalid\n");
      player1Move();
    } else {
      board[1][1] = 1;
    }
    break;
  case 2:
    if (board[1][2] == 1 || board[1][2] == 2){
      printf("Invalid\n");
      player1Move();
    } else {
      board[1][2] = 1;
    }
    break;
  case 3:
    if (board[1][3] == 1 || board[1][3] == 2){
      printf("Invalid\n");
      player1Move();
    } else {
      board[1][3] = 1;
    }
    break;
  case 4:
    if (board[2][1] == 1 || board[2][1] == 2){
      printf("Invalid\n");
      player1Move();
    } else {
      board[2][1] = 1;
    }
    break;
  case 5:
    if (board[2][2] == 1 || board[2][2] == 2){
      printf("Invalid\n");
      player1Move();
    } else {
      board[2][2] = 1;
    }
    break;
  case 6:
    if (board[2][3] == 1 || board[2][3] == 2){
      printf("Invalid\n");
      player1Move();
    } else {
      board[2][3] = 1;
    }
    break;
  case 7:
    if (board[3][1] == 1 || board[3][1] == 2){
      printf("Invalid\n");
      player1Move();
    } else {
      board[3][1] = 1;
    }
    break;
  case 8:
    if (board[3][2] == 1 || board[3][2] == 2){
      printf("Invalid\n");
      player1Move();
    } else {
      board[3][2] = 1;
    }
    break;
  case 9:
    if (board[3][3] == 1 || board[3][3] == 2){
      printf("Invalid\n");
      player1Move();
    } else {
      board[3][3] = 1;
    }
    break;
  default:
    printf("Invalid\n\n");
    player1Move();
  }
  printf("\n");
}

void player2Move(){
  int p2Move;
  printf("P2: ");
  scanf("%d", &p2Move);
  switch(p2Move){
  case 1:
    if (board[1][1] == 1 || board[1][1] == 2){
      printf("Invalid\n");
      player2Move();
    } else {
      board[1][1] = 2;
    }
    break;
  case 2:
    if (board[1][2] == 1 || board[1][2] == 2){
      printf("Invalid\n");
      player2Move();
    } else {
      board[1][2] = 2;
    }
    break;
  case 3:
    if (board[1][3] == 1 || board[1][3] == 2){
      printf("Invalid\n");
      player2Move();
    } else {
      board[1][3] = 2;
    }
    break;
  case 4:
    if (board[2][1] == 1 || board[2][1] == 2){
      printf("Invalid\n");
      player2Move();
    } else {
      board[2][1] = 2;
    }
    break;
  case 5:
    if (board[2][2] == 1 || board[2][2] == 2){
      printf("Invalid\n");
      player2Move();
    } else {
      board[2][2] = 2;
    }
    break;
  case 6:
    if (board[2][3] == 1 || board[2][3] == 2){
      printf("Invalid\n");
      player2Move();
    } else {
      board[2][3] = 2;
    }
    break;
  case 7:
    if (board[3][1] == 1 || board[3][1] == 2){
      printf("Invalid\n");
      player2Move();
    } else {
      board[3][1] = 2;
    }
    break;
  case 8:
    if (board[3][2] == 1 || board[3][2] == 2){
      printf("Invalid\n");
      player2Move();
    } else {
      board[3][2] = 2;
    }
    break;
  case 9:
    if (board[3][3] == 1 || board[3][3] == 2){
      printf("Invalid\n");
      player2Move();
    } else {
      board[3][3] = 2;
    }
    break;
  default:
    printf("Invalid\n\n");
    player2Move();
  }
  printf("\n");
}

int winningPlayer(){
  for (int i = 1; i <=3; i++){
    if (board[i][1] == 1 && board[i][2] == 1 && board[i][3] == 1){
      return 1;
    } else if (board[1][i] == 1 && board[2][i] == 1 && board[3][i] == 1){
      return 1;
    } else if (board[1][1] == 1 && board[2][2] == 1 && board[3][3] == 1){
      return 1;
    } else if (board[1][3] == 1 && board[2][2] == 1 && board[3][1] == 1) {
      return 1;
    }
    if (board[i][1] == 2 && board[i][2] == 2 && board[i][3] == 2){
      return 2;
    } else if (board[1][i] == 2 && board[2][i] == 2 && board[3][i] == 2){
      return 2;
    } else if (board[1][1] == 2 && board[2][2] == 2 && board[3][3] == 2){
      return 2;
    } else if (board[1][3] == 2 && board[2][2] == 2 && board[3][1] == 2) {
      return 2;
    }
  }
  return 0;
}

int isTie(){
  if (board[1][1] != 0 && board[1][2] != 0 && board[1][3] != 0 && board[2][1] != 0 &&
      board[2][2] != 0 && board[2][3] != 0 && board[3][1] != 0 && board[3][2] != 0 &&
      board[3][3] != 0 && winningPlayer() == 0){
        return 1;
      } else { return 0; }
}
