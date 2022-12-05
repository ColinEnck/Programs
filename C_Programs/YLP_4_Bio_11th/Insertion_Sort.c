/*
This sorting algorithm works by creating a new sorted
list element by element, inserting each new element in its correct place
in the new list
*/

#include <stdio.h>
#include <stdlib.h>
#define LENGTH 1000
#define FILENAME "list.csv"

int isInOrder(int list[]);
void insertion(int list[]);
void printList(int list[]);

int main(){
    FILE *fPtr;
    fPtr = fopen(FILENAME, "r");
    int list[LENGTH];
    for (int i = 0; i < LENGTH; i++) fscanf(fPtr, "%d\n", &list[i]);

    if (isInOrder(list)){
        printf("It is already in order.");
        return 0;
    }

    insertion(list);
    printList(list);

    fclose(fPtr);
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
