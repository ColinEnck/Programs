#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#define X_LENGTH 30
#define Y_LENGTH 20

/* creates a type called point, which holds int values
of its x position, y position, and direction 
when dir = '0', it is not moving; this is for the start.
for dir values w, a, s, d, it moves accordingly */
typedef struct point {
    int xpos, ypos;
    char dir;
} coordinates;

void updateBoard(coordinates snake[], coordinates fruit, int lengthOfSnake);
int isTheSnakeHere(coordinates snake[], int lengthOfSnake, int x, int y);
void changeDirection(coordinates snake[], int lengthOfSnake);
void updateSnakeDirection(coordinates snake[], int lengthOfSnake);
void makeSnakeLonger(coordinates snake[], int *lengthOfSnake);
void shiftSnake(coordinates snake[], int lengthOfSnake, int newx, int newy, int newdir);
coordinates setFruitxy();
int isTheFruitHere(coordinates fruit, int x, int y);

int main(){
    /* allocates an array of type coordinates 
    to hold first point of the snake; will reallocate 
    memory as needed to make the snake longer; the first element 
    represents the head of the snake, and the elements will shift
    up with every new drawing of the board*/
    coordinates *snake = (coordinates*) malloc(1 * sizeof(coordinates));
    // error handling
    if (!snake){
        printf("malloc failed\n");
        exit(1);
    }

    coordinates fruit = setFruitxy();

    int lengthOfSnake = 1;
    // starts snake at the middle of the board
    snake[0].xpos = X_LENGTH / 2;
    snake[0].ypos = Y_LENGTH / 2;
    snake[0].dir = 0;

    /* code I copied from an online forum:
    it makes the cursor in Windows Console invisible */
    HANDLE hStdOut = NULL;
    CONSOLE_CURSOR_INFO curInfo;
    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(hStdOut, &curInfo);
    curInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hStdOut, &curInfo);

    for (;;) {
        updateBoard(snake, fruit, lengthOfSnake);
        changeDirection(snake, lengthOfSnake);
    }

    free(snake);
}

/* prints the outline of the board and the positions of the points on the board
according to their x and y values, with the origin being the top-left 
corner */
void updateBoard(coordinates snake[], coordinates fruit, int lengthOfSnake){
    system("cls"); // clears the screen

    for (int i = 0; i < X_LENGTH + 2; i++)
        printf("#"); // prints the top horizontal line
    printf("\n");

    for (int i = 0; i < Y_LENGTH; i++){
        printf("#");
        for (int j = 0; j < X_LENGTH; j++){
            if (isTheSnakeHere(snake, lengthOfSnake, j, i))
                printf("0");
            else if (isTheFruitHere(fruit, j, i))
                printf("*"); 
            else printf(" ");
        }
        printf("#\n");
    }

    for (int i = 0; i < X_LENGTH + 2; i++)
        printf("#"); // prints the bottom horizontal line
}

/* returns 1 if that point is present in the array snake[], 
otherwise returns 0 */
int isTheSnakeHere(coordinates snake[], int lengthOfSnake, int x, int y){
    for (int i = 0; i < lengthOfSnake; i++)
        if (snake[i].xpos == x && snake[i].ypos == y)
            return 1;
    return 0;
}

void changeDirection(coordinates snake[], int lengthOfSnake){
    if (kbhit()){
        snake[0].dir = getch();
    }
    updateSnakeDirection(snake, lengthOfSnake);
}

void updateSnakeDirection(coordinates snake[], int lengthOfSnake){
    for (int i = 0; i < lengthOfSnake; i++){
        switch (snake[i].dir){
            case 'w':
                snake[i].ypos--;
                break;
            case 'a':
                snake[i].xpos--;
                break;
            case 's':
                snake[i].ypos++;
                break;
            case 'd':
                snake[i].xpos++;
                break;
            default:
                break;
        }
    }
}

// makes the snake array longer by 1 unit; lengthOfSnake++ and returns that
void makeSnakeLonger(coordinates snake[], int *lengthOfSnake){
    coordinates *updatedSnake = realloc(snake, 1 * sizeof(coordinates));
    if (!updatedSnake){
        printf("realloc failed\n");
        exit(1);
    }
    snake = updatedSnake;
    *lengthOfSnake++;
    snake[*lengthOfSnake - 1].xpos = snake[*lengthOfSnake - 2].xpos;
    snake[*lengthOfSnake - 1].ypos = snake[*lengthOfSnake - 2].ypos;
    snake[*lengthOfSnake - 1].dir = snake[*lengthOfSnake - 2].dir;
}

void shiftSnake(coordinates snake[], int lengthOfSnake, int newx, int newy, int newdir){
    snake[0].xpos = newx;
    snake[0].ypos = newy;
    snake[0].dir = newdir;
    for (int i = lengthOfSnake; i > 0; i--){
        snake[i].xpos = snake[i - 1].xpos;
        snake[i].ypos = snake[i-1].ypos;
        snake[i].dir = snake[i-1].dir;
    }
}

coordinates setFruitxy(){
    time_t t;
    srand(time(&t));
    coordinates fruit;
    fruit.xpos = rand() % X_LENGTH;
    fruit.ypos = rand() % Y_LENGTH;
    fruit.dir = 0;
}

/* returns 1 if that point is present in the coordinates fruit, 
otherwise returns 0 */
int isTheFruitHere(coordinates fruit, int x, int y){
    if (fruit.xpos == x && fruit.ypos == y)
        return 1;
    return 0;
}