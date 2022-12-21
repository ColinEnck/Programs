#include <stdio.h>
#include <stdlib.h>
#define LEN num/2

// returns an array of the factors of num
int* factors(int num);

int main(int argc, char const *argv[]) {
	if (argc != 2) exit(0);
	int num = atoi(argv[1]);

	int* factorsArray = factors(num);
	for (int i = 0; factorsArray[i] != 0; ++i)
		printf("%d\n", factorsArray[i]);

	return 0;
}

int* factors(int num) {
	int* array = (int*) malloc(sizeof(int) * LEN);
	if (array == NULL) exit(0);
	for (int i = 0; i < (LEN); ++i) 
		array[i] = 0;

	int element = 0;
	for (int i = 2; i <= (LEN); ++i) 
		if (num % i == 0) {
			array[element] = i;
			++element;
		}

	return array;
}