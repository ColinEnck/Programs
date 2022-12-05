/*
Selection sort works by finding the highest value in the list and
placing it at the beginning, then finding the next highest value 
and placing it second, and so on.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LENGTH 100000

int isInOrder(int list[]);
void selection(int list[]);
void printList(int list[]);

struct maxPoint {
    int element;
    int value;
};


int main(){
    int list[LENGTH];
    srand(time(NULL));
    for (int i = 0; i < LENGTH; i++) list[i] = rand();
    
    if (isInOrder(list)){
        printf("It is already in order.");
        return 0;
    }

    selection(list);
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

void selection(int list[]){
    struct maxPoint point;
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