#include <stdio.h>
#include <stdlib.h>
#define FILENAME "anotherlist.csv"
#define LENGTH 10

int isInOrder(int list[]);
void mergesort(int list[]);
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

    mergesort(list);
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

void mergesort(int list[]){
    

}

void printList(int list[]){
    for (int i = 0; i < LENGTH; i++)
        printf("%d\n", list[i]);
}