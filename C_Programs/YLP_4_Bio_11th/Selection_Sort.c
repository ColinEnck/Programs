/*
Selection sort works by finding the highest value in the list and
placing it at the beginning, then finding the next highest value 
and placing it second, and so on.
*/

#include <stdio.h>
#include <stdlib.h>
#define LENGTH 1000
#define FILENAME "list.csv"

int isInOrder(int list[]);
void selection(int list[]);
void printList(int list[]);

struct point {
    int element;
    int value;
};

int main(){
    FILE *fPtr;
    fPtr = fopen(FILENAME, "r");
    int list[LENGTH];    
    for (int i = 0; i < LENGTH; i++) fscanf(fPtr, "%d\n", &list[i]);
    
    if (isInOrder(list)){
        printf("It is already in order.");
        return 0;
    }

    selection(list);
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

void selection(int list[]){
    struct point point;
    int temp;

    for (int i = 0; i < LENGTH; ++i){
        point.value = list[i];
        for (int j = i; j < LENGTH; ++j){
            if (list[j] > point.value){
                point.value = list[j];
                point.element = j;
            }
        }
        temp = list[i];
        list[i] = point.value;
        list[point.element] = temp;
    }
}

void printList(int list[]){
    for (int i = 0; i < LENGTH; i++)
        printf("%d\n", list[i]);
}