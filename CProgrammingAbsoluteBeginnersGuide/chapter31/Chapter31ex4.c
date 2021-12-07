#include <stdio.h>

void changeSome(int i, float *newX, int pInt[5]);

main(){
    int i=10;
    int ctr;
    float x = 20.5;

    int iAry[] = {10, 20, 30, 40, 50};

    puts("Here are main()'s variables before the function:");
    printf("i is %d\n", i);
    printf("x is %.1f\n", x);

    for ( ctr = 0; ctr < 5; ++ctr) {
        printf("iAry[%d] is %d\n", ctr, iAry[ctr]);
    }

    //Now call the changeSome function, passing the value of i
    //and the address of x (hence, the &)

    changeSome(i, &x, iAry);

    puts("\n\nHere are main()'s variables after the function: ");
    printf("i is %d\n", i);
    printf("x is %.1f\n", x);
    for ( ctr = 0; ctr < 5; ++ctr) {
        printf("iAry[%d] is %d\n", ctr, iAry[ctr]);
    }
}

void changeSome(int i, float *newX, int pInt[5]) {
    /*All variables are changes, but only the float and array
     * remain changed when the program returns to main()*/

    //changed when the program returns to main()
    int j;

    i = 47;
    *newX = 97.6;

    for ( j = 0; j < 5; ++j) {
        pInt[j] = 100 + 100 * j;
    }
}
