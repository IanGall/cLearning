#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
* Program to determine combinations
*/

/**
 * Factorial Function
 * @param n
 * @return
 */
int getFactorial(int n);

int Binomial(int n, int k);

int main() {
    int n;
    int k;
    int b;
    printf("Input n: ");
    scanf("%d", &n);
    if (n < 1) {
        printf("Must be greater than zero\n");
        exit(1);
    }

    printf("Input k: ");
    scanf("%d", &k);

    if (k < 0 || k > n) {
        printf("Must be between 0 and %d inclusive\n", n);
        exit(1);
    }

    b = Binomial(n, k);
    printf("%d items taken %d ways is %d\n", n, k, b);
}

int Binomial(int n, int k) {
    int b;
    b = getFactorial(n) / (getFactorial(k) * getFactorial(n - k));
    return b;
}

int getFactorial(int n) {
    int f = 1;
    int i;
    for (i = 1; i <= n; ++i) {
        f *= i;
    }
    return f;
}
