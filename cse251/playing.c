#include <stdio.h>

int main() {
//    int i = 1;
//    int sum = 0;
//
//    while(i < 5)
//    {
//        sum += i;
//        i++;
//    }
//
//    printf("sum=%d\n", sum); //sum=10

//    double q = 1;
//    int i;
//
//    for (i = 1; i <= 5; i++) {
//        q += i * i / 2.0;
//    }
//
//    printf("q=%f\n", q); //q=28.5

//    double q = 1;
//
//    do {
//        q = q * 2;
//    } while (q < 0);
//
//    printf("q=%f\n", q); //2

    int i;
    int j;

    for (i = 0; i < 11; i++) {
        if (i < 5) {
            for (j = 0; j <= i; j++)
                printf("+");
        } else {
            for (j = 0; j <= (10 - i); j++)
                printf("+");
        }

        printf("\n");
    }

    printf("---\n");
}