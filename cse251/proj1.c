#include <stdio.h>
#include <math.h>

double fx(double x);

double delta(int n, int a, int b);

int main() {
    int x;
    int n = 1883;
    int i;
    int a = -1;
    int b = 1;
    double d;
    double I = 0;
    d = delta(n, a, b);
    for (i = 1; i < n + 1; ++i) {
        I += fx(a + (i - 0.5) * d) * d;
    }
    printf("%.9lf", I);
}

double delta(int n, int a, int b) {
    double d = (double) b - a;
    return d / n;
}

double fx(double x) {
    double d = sin(M_PI * x);
    return d / (M_PI * x);
}
