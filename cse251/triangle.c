#include <stdio.h>
#include <math.h>

/*Declaration*/
double getLength(double x1, double y1, double x2, double y2);

int main(){
    double x1 = 0, y1 = 0;
    double x2 = 17, y2 = 10.3;
    double x3 = -5.2, y3 = 5.1;

    double a, b, c; /*Triangle side lengths*/
    double p; /*For Heron's formula*/
    double area;

    a = getLength(x1, y1, x2, y2);
//    b = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
    b = getLength(x1, y1, x3, y3);
//    c = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
    c = getLength(x2, y2, x3, y3);

    p = (a + b + c) / 2;
    area = sqrt(p * (p - a) * (p - b) * (p - c));

    printf("%f\n", area);
}

/*Definition*/
double getLength(double x1, double y1, double x2, double y2) {
    double a;
    a = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    return a;
}
