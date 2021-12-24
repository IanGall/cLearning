#include <stdio.h>
#include <math.h>

double fx(double x);

double delta(int n, int a, int b);

double compute(int n, double a, double b);

int main() {
    int n = 10;
    double a = 0.1;
    double b = 0.2;
    double pre = compute(n, a, b);
    printf("%d %.9lf\n", n, pre);
    for (n = 11; n <= 100000; n++) {
        double res = compute(n, a, b);
        double decrease = pre - res;
        printf("%d %.9lf %e\n", n, res, decrease);
        pre = res;
        if (decrease < 1e-10) {
            break;
        }
    }
}

double compute(int n, double a, double b) {
    int i;
    double d;
    double I = 0;
    d = delta(n, a, b);
    for (i = 1; i < n + 1; ++i) {
        double decrease = fx(a + (i - 0.5) * d) * d;
        I += decrease;
    }
    return I;
}

double delta(int n, int a, int b) {
    double d = (double) b - a;
    return d / n;
}

double fx(double x) {
    if (x == 0) {
        return 1;
    }
    double d = sin(M_PI * x);
    return d / (M_PI * x);
}
