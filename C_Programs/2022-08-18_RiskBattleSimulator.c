#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void reorderThree(int dice[]);
void reorderTwo(int dice[]);
void printDice(int dice[], int num);
void calculator(int attackDice[], int defendDice[],
                int attackNum, int defendNum, int losses[]);
void diceRoll(int attackNum, int defendNum, int losses[]);

int main(){
    int attackNum, defendNum;
    int losses[2] = {0, 0};
    srand(time(NULL));

    do {
        printf("How many attacking?\n");
        scanf("%d", &attackNum);
        if (attackNum > 3 || attackNum < 1)
            printf("Invalid input\n");
    } while (attackNum > 3 || attackNum < 1);

    do {
        printf("How many defending?\n");
        scanf("%d", &defendNum);
        if (defendNum > 2 || defendNum < 1)
            printf("Invalid input\n");
    } while (defendNum > 2 || defendNum < 1);

    do {
        losses[0] = 0;
        losses[1] = 0;

        diceRoll(attackNum, defendNum, losses);

        printf("Attacking losses: %d\nDefending losses: %d\n____________________\n",
            losses[0], losses[1]);

        attackNum += losses[0];
        defendNum += losses[1];
        if (attackNum < 1){
            printf("\nDEFENCE WINS!");
            break;
        } else if (defendNum < 1){
            printf("\nATTACKING SIDE WINS!");
            break;
        }

    } while (1);

    return 0;
}

void reorderThree(int dice[]){
    int temp[3];

    if (dice[0] >= dice[1] && dice[0] >= dice[2])
        temp[0] = dice[0];
    else if (dice[1] >= dice[0] && dice[1] >= dice[2])
        temp[0] = dice[1];
    else temp[0] = dice[2];

    if ((dice[0] >= dice[1] && dice[0] <= dice[2]) ||
        (dice[0] <= dice[1] && dice[0] >= dice[2]))
        temp[1] = dice[0];
    else if ((dice[1] >= dice[1] && dice[1] <= dice[2]) ||
        (dice[1] <= dice[1] && dice[1] >= dice[2]))
        temp[1] = dice[1];
    else if ((dice[2] >= dice[1] && dice[2] <= dice[2]) ||
        (dice[2] <= dice[1] && dice[2] >= dice[2]))
        temp[1] = dice[2];

    if (dice[0] <= dice[1] && dice[0] <= dice[2])
        temp[2] = dice[0];
    else if (dice[1] <= dice[0] && dice[1] <= dice[2])
        temp[2] = dice[1];
    else temp[2] = dice[2];

    for (int i = 0; i < 3; i++)
        dice[i] = temp[i];
}

void reorderTwo(int dice[]){
    int temp[2];
    temp[0] = (dice[0] >= dice[1]) ? dice[0] : dice[1];
    temp[1] = (dice[0] <= dice[1]) ? dice[0] : dice[1];

    for (int i = 0; i < 2; i++)
        dice[i] = temp[i];

}

void printDice(int dice[], int num){
    printf("\nDice 1: %d\n", dice[0]);
    if (num < 2){
        printf("__________\n\n");
        return;
    }
    printf("Dice 2: %d\n", dice[1]);
    if (num < 3){
        printf("__________\n\n");
        return;
    }
    printf("Dice 3: %d\n__________\n", dice[2]);
}

void calculator(int attackDice[], int defendDice[],
                int attackNum, int defendNum, int losses[]){

    if (defendNum <= attackNum){
        for (int i = 0; i < defendNum; i++){
            if (defendDice[i] >= attackDice[i])
                --losses[0];
            else --losses[1];
        }
    } else if (attackNum < defendNum){
        if (defendDice[0] >= attackDice[0])
            --losses[0];
        else --losses[1];
    }

}

void diceRoll(int attackNum, int defendNum, int losses[]){
    int attackDice[attackNum];
    int defendDice[defendNum];

    for (int i = 0; i < attackNum; i++)
        attackDice[i] = (rand() % 6) + 1;
    for (int i = 0; i < defendNum; i++)
        defendDice[i] = (rand() % 6) + 1;

    switch (attackNum){
    case 3:
        reorderThree(&attackDice);
        break;
    case 2:
        reorderTwo(&attackDice);
        break;
    default:
        break;
    }

    switch (defendNum){
    case 3:
        reorderThree(&defendDice);
        break;
    case 2:
        reorderTwo(&defendDice);
        break;
    default:
        break;
    }

    printf("\nAttacking dice:");
    printDice(attackDice, attackNum);
    printf("\nDefending dice:");
    printDice(defendDice, defendNum);

    calculator(attackDice, defendDice,
               attackNum, defendNum, losses);
}
