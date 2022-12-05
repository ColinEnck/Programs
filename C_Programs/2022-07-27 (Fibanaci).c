#include <stdio.h>
#include <math.h>

int main(){
    int lengthOfSequence;
    double number1 = 1, number2 = 1, i = 1;

    printf("Length of sequence?\n");
    scanf("%d", &lengthOfSequence);
    lengthOfSequence = lengthOfSequence / 2;
    printf("\n1\n");

    do {
        printf("%.0lf\n", number1);
        number2 = number1 + number2;
        printf("%.0lf\n", number2);
        number1 = number2 + number1;
        i++;
    } while (i <= lengthOfSequence);

    return 0;
}
