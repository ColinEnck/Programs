/*
This sorting algorithm works by comparing the first two elements
and swapping them if they are out of oder. It moves onto the next two 
elements and does likewise. It repeats this throughout the array until it is at
the end, where it starts back at the beginning. It does this until the array is sorted.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LENGTH 100000

int isInOrder(int list[]);
void bubble(int list[]);
void printList(int list[]);
void switchNum(int* px, int* py);

int main(){
    int list[LENGTH];
    srand(time(NULL));
    for (int i = 0; i < LENGTH; i++) list[i] = rand();

    if (isInOrder(list)){
        printf("It is already in order.");
        return 0;
    }

    bubble(list);
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

void switchNum(int* px, int* py){
    int temp = *px;
    *px = *py;
    *py = temp;
}