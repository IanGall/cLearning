#include <stdio.h>

void half(int *i);

main(){
    int  i;
    printf("Please enter an integer..");
    scanf(" %d", &i);

    //Now call teh half function, passing the address of i

    half(&i);
    //Shows that the function didi alter i's value
    printf("In main(), i is now %d.\n", i);
}

void half(int *i) { //Receives the address of i
    *i /= 2;
    printf("Your value halved is %d.\n", *i);
}
