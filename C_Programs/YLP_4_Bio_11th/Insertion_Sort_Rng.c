/*
This sorting algorithm works by creating a new sorted
list element by element, inserting each new element in its correct place
in the new list
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LENGTH 100000

int isInOrder(int list[]);
void insertion(int list[]);
void printList(int list[]);

int main(){
    int list[LENGTH];
    srand(time(NULL));
    for (int i = 0; i < LENGTH; i++) list[i] = rand();

    if (isInOrder(list)){
        printf("It is already in order.");
        return 0;
    }

    insertion(list);
    printList(list);

    return 0;
}

int isInOrder(int list[]){
    int isInOrder = 0;
    for (int i = 0; i < LENGTH; i++){
        if (list[i] >= list[i+1]) 
            isInOrder = 1;
        else return 0;
    }
    return isInOrder;
}

void insertion(int list[]){
    int i, j, temp;

    for (i = 1; i < LENGTH; ++i){
        temp = list[i];
        for (j = i - 1; j >= 0 && list[j] < temp; --j)
            list[j+1] = list[j];
        list[j+1] = temp;
    }
}

void printList(int list[]){
    for (int i = 0; i < LENGTH; i++)
        printf("%d\n", list[i]);
}
