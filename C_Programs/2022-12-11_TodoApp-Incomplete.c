#include <stdio.h>
#include <stdlib.h>
#define BUFFSIZE 25

typedef struct node {
	char* text;
	struct node* child; 
} node_t;

void printList(node_t* head);
int add(node_t* head);
int del(node_t* head);

int main() {
	node_t* head = (node_t*) malloc(sizeof(node_t));
	if (head == NULL) exit(1);
	head->text = "";
	head->child = NULL;
	do {
		printList(head);
		printf("Would you like to (1) add to the todo list or (2) remove an item? ");
		char option = getchar();
		switch(option){
			case '1':
				add(head);
				break;
			case '2':
				del(head);
				break;
			default:
				return 0;
				break;
		}
	} while (1);
}

void printList(node_t* head) {
	node_t* currentPos = head;
	
	while (currentPos != NULL){
		printf("%s", currentPos->text);
		currentPos = currentPos->child;
	}
}

int add(node_t* head) {
	// this sets a pointer and then counts it down to the last valid element
	node_t* last = head;
	while (last->child != NULL)
		last = last->child;

	last->child = (node_t*) malloc(sizeof(node_t));
	last->child->child = NULL;
	last->child->text = malloc(100);
	
	printf("Enter the words you want to add to the list: ");
	getchar();
	fgets(last->child->text, BUFFSIZE, stdin);

	return 0;
}

int del(node_t* head) {
	printf("hi there 2");
	return 0;
}
