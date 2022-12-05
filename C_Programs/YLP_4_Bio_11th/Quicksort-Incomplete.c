/*
This algorithm works by first placing the last element in its final place in the 
sorted array, then, using that as the point of division, put all elements
greater than it before it and all elements less than it after it. it then 
recursively applies this method to the sub-arrays split by the point of divisions.
*/

#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10
#define FILENAME "anotherlist.csv"

int isInOrder(int list[]);
int quicksort(int list[], int start, int end);
void shift(int list[], int start, int end);
void switchNum(int *px, int *py);
void printList(int list[]);
FILE *fptr;

int main(){
    fptr = fopen(FILENAME, "r");
    int list[LENGTH];
    for (int i = 0; i < LENGTH; ++i) fscanf(fptr, "%d\n", &list[i]);

    if (isInOrder(list)){
        printf("It is already in order.");
        return 0;
    }

    quicksort(list, 0, LENGTH);
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

int quicksort(int list[], int start, int end){
    switch (end - start) {
    case 3:
        for (int i = start; i < start + 3; i++)
            for (int j = start; j < start + 2; j++)
                if (list[j] < list[j + 1])
                    switchNum(&list[j], &list[j + 1]);
        return 3;
    case 2:
        if (list[start] < list[start + 1]) 
            switchNum(&list[start], &list[start + 1]);
        return 2;
    }
    // moves the pivot to its final place in the array

    int pivot = end - 1;
    int greaterThan;
    for (int i = start; i < end; ++i){
        if (i == pivot) continue;
        if (list[i] > list[pivot]) ++greaterThan;
    }
    int pod = start + greaterThan;
    shift(list, pod, pivot);

    // the value of the point of division 
    int podVal = list[start + greaterThan];

    // puts every value greather than the POD before it,
    // and every value less than the POD after it

    int lpoint = start;
    int rpoint = end - 1;
    while (lpoint < greaterThan && rpoint > greaterThan){
        if (list[lpoint] < podVal && list[rpoint] > podVal){
            switchNum(&list[lpoint], &list[rpoint]);
            ++lpoint;
            --rpoint;
        } else if (list[lpoint] < pod) 
            --rpoint;
        else if (list[rpoint] > pod)
            ++lpoint;
        else {
            ++lpoint;
            --rpoint;
        }
    }
    quicksort(list, 0, pod);    

}

// shifts an array up one element with starting element "start" and ending element "end", inclusively, and moves the ending value to the beginning. 
void shift(int list[], int start, int end){
    int temp = list[end];
    for (int i = end; i >= start; --i)
        list[i] = list[i-1];
    list[start] = temp;
}

void switchNum(int *px, int *py){
    int temp = *px;
    *px = *py;
    *py = temp;
}

void printList(int list[]){
    for (int i = 0; i < LENGTH; i++)
        printf("%d\n", list[i]);
}