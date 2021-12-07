/*The program demonstrates passing a variable to a function by value*/
#include <stdio.h>

void half(int i);

main(){
    int i;

    printf("Please enter an integer...");
    scanf(" %d", &i);

    // Now call the half function, passing the value of i
    half(i);

    //Shows that the function did not alter i's value
    printf("In main(), i is still %d.\n", i);
}
/**
 * Sometimes putting dividers like the one above is a nice break
 * between your different functions.
 * @param i
 */
void half(int i) {
    i /= 2;
    printf("Your value halved is %d.\n", i);
    return; //Returns to main
}
