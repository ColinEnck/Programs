/*
This sorting algorithm works by comparing the first two elements
and swapping them if they are out of oder. It moves onto the next two 
elements and does likewise. It repeats this throughout the array until it is at
the end, where it starts back at the beginning. It does this until the array is sorted.
*/

#include <stdio.h>
#include <stdlib.h>
#define LENGTH 1000
#define FILENAME "list.csv"

int isInOrder(int list[]);
void bubble(int list[]);
void printList(int list[]);
void switchNum(int *px, int *py);

int main(){
    FILE *fPtr;
    fPtr = fopen(FILENAME, "r");

    //assumes file has 1000 integers; leave it for now
    int list[LENGTH];

    //it works!!!
    for (int i = 0; i < LENGTH; i++) fscanf(fPtr, "%d\n", &list[i]);
    //^^leave it^^

    if (isInOrder(list)){
        printf("It is already in order.");
        return 0;
    }
    
    //sorts the array
    bubble(list);
    //outputs the array after sorting
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

void bubble(int list[]){
    for (int i = 0; i < LENGTH; i++)
        for (int j = 0; j < LENGTH - 1; j++)
            if (list[j] < list[j + 1])
                switchNum(&list[j], &list[j + 1]);
}

void printList(int list[]){
    for (int i = 0; i < LENGTH; i++)
        printf("%d\n", list[i]);
}

void switchNum(int *px, int *py){
    int temp = *px;
    *px = *py;
    *py = temp;
}
