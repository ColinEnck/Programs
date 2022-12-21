#include <stdio.h>
#include <stdlib.h>

// type for a node on a linked list
typedef struct node {
	int value;
	struct node* child;
} node_t;

// returns an array of the factors of num
int* factors(int num);
// adds value to the linked list
void addToList(node_t* head, int value);
// takes the head of a linked list and returns an identitcal array
int* listToArray(node_t* head);

int main(int argc, char const *argv[]) {
	if (argc != 2) exit(0);
	int num = atoi(argv[1]);

	int* factorsArray = factors(num);
		
	// TODO figure out how to access length of the array

	return 0;
}

int* factors(int num) {
	node_t* head = malloc(sizeof(node_t));
	head->value = 0;
	head->child = NULL;
	for (int i = 2; i <= (num / 2); ++i) {
		if (num % i == 0) {
			addToList(head, i);
		}
	}
	// DO NOT REMOVE THIS LINE, IT NEEDS IT TO WORK FOR SOME REASON
	printf("Here are the factors:\n");
	int* array = listToArray(head);
	return array;
}

void addToList(node_t* head, int value) {
	node_t* current = head;
    while (current->child != NULL)
        current = current->child;

    current->child = (node_t*) malloc(sizeof(node_t));
    current->child->child = NULL;
    current->child->value = value;
}

int* listToArray(node_t* head) {
	int len;
	node_t* current = head;
	// counts the length of the linked list
	for (len = 0; current->child->child != NULL;\
		current = current->child, len++);

	int* array = (int*) malloc(sizeof(int) * len);
	if (array != NULL) exit(0);

	current = head;
	for (int i = 0; current != NULL; ++i) {
		array[i] = current->value;
		current = current->child;
	}

	return array;
}