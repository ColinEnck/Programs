#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char value;
	struct node* child;
} node_t;

void printList(node_t* head);
void add(node_t* head);
void delete(node_t* head);

int main() {
	node_t* head = (node_t*) malloc(sizeof(node_t));
	if (head == NULL) exit(1);
	head->value = 0;
	head->child = NULL;

	do {
		system("cls");
		printf("Here is the linked list:\n");
		printList(head);
	
		int response;
		printf("\nWould you like to add (1) or delete the last item (2)? ");
		printf("Anything else will exit the program: ");
		scanf("%d", &response);
		switch (response) {
		case 1:
			add(head);
			break;
		case 2:
			delete(head);
			break;
		default:
			return 0;
			break;
		}
	} while (1);
}

void printList(node_t* head) {
	node_t* currentPos = head;

	while (currentPos != NULL) {
		putchar(currentPos->value);
		currentPos = currentPos->child;
	}
	printf("\n");
}

void add(node_t* head) {
	node_t* current = head;
    while (current->child != NULL)
        current = current->child;

    current->child = (node_t*) malloc(sizeof(node_t));
    current->child->child = NULL;

    printf("Type the ASCII character you want to be added: ");
    getchar();
    current->child->value = getchar();
}

void delete(node_t* head) {
	node_t* current = head;
	while (current->child->child != NULL)
		current = current->child;

	char lastVal = current->child->value;
	free(current->child);
	current->child = NULL;
}
