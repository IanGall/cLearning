#include <stdio.h>
double CtoF(double paramCel);

int main(){
    double c, f;
    printf("Enter the degree (in Celsius):");
    scanf("%lf", &c);

    f = CtoF(c);
    printf("Temperature (in Fahrenheit) is %lf\n", f);
}

double CtoF(double paramCel){
    return paramCel * 1.8 + 32;
}