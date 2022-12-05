#include <stdio.h>
#include <stdlib.h>
#define FILENAME "anotherlist.csv"
#define LENGTH 10

int isInOrder(int list[]);
void heapsort(int list[]);
void shift(int list[], int length);
void printList(int list[]);

struct node {
    int value;
    struct node *leftChild;
    struct node *rightChild;
};

struct point {
    int value;
    int element;
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

    heapsort(list);
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

void heapsort(int list[]){
    struct point maxPoint;
    maxPoint.element = 0;
    maxPoint.value = list[0];
    for (int i = 0; i < LENGTH; ++i)
        if (list[i] > maxPoint.value){
            maxPoint.value = list[i];
            maxPoint.element = i;
        }
    shift(list, maxPoint.element);
}

void shift(int list[], int length){
    int temp = list[length];
    for (int i = length; i >= 0; --i)
        list[i] = list[i-1];
    list[0] = temp;
}

void printList(int list[]){
    for (int i = 0; i < LENGTH; i++)
        printf("%d\n", list[i]);
}