#include <stdio.h>
#include <stdlib.h>

// prints the factors of num
void printFactors(int num);
// returns an array of the factors of num
int* factors(int num);

int main(int argc, char const *argv[]) {
	if (argc != 2) exit(0);
	int num = atoi(argv[1]);

	return 0;
}

void printFactors(int num) {
	for (int i = 2; i <= (num / 2); ++i) {
		if (num % i == 0){
			printf("%d\n", i);
			printFactors(num / i);
		}
	}
}

int* factors(int num) {

}