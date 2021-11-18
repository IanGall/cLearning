#include <stdio.h>
int main(int argc, char const *argv[])
{
  // Set up the variables that scanf will fill
  char firstInitial;
  char lastInitial;
  int age;
  int favourite_number;
  printf("What letter does your first name begin with?\n");
  scanf(" %c", &firstInitial);

  printf("What letter does your last name begin with?\n");
  scanf(" %c", &lastInitial);

  printf("How old are you?\n");
  scanf("%d", &age);

  printf("What is your favorite number (Integer only)?\n");
  scanf(" %d", &favourite_number);

  printf("\nYour initials are %c.%c. and your are %d years old", firstInitial, lastInitial, age);
  printf("\nYour favorite number is %d.\n\n", favourite_number);
  return 0;
}
