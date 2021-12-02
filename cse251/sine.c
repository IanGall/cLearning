#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

int main() {
    double angle, sinVal;
    int numSteps = 40;
    double maxAngle = M_PI * 2;
    int i, j;
    char c = '*', falling = '/', rising = '\\';

    do {
        printf("Input the number of steps: ");
        scanf("%d", &numSteps);
        if (numSteps < 2) {
            continue;
        }

        int sinPre = 0;

        for (i = 0; i <= numSteps; ++i) {
            angle = (double) i / (double) numSteps * maxAngle;
            sinVal = sin(angle);
            printf("%3d: %5.2f ", i, angle);
            for (j = 0; j < sinVal * 30 + 30; ++j) {
                printf(" ");
            }
            double derivative = cos(angle);
            if (fabs(derivative) < 0.1) {
                printf("%c\n", c);
            } else if (derivative > 0) {
                printf("%c\n", rising);
            } else {
                printf("%c\n", falling);
            }
        }
    } while (true);

}
