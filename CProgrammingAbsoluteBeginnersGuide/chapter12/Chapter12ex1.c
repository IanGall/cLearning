#include <stdio.h>

int main(int argc, char const *argv[])
{
  // set up some sommon integers for the program
  int planets = 8;

  int friends = 6;
  int potterBooks = 7;
  int starWars = 6;
  int months = 12;
  int beatles = 4;
  int avengers = 6;
  int baseball = 5;
  int basketball = 5;
  int football = 11;

  /* This first logical statement uses the AND operator to test
  whether the cast of Friends and the Beatles would have
  enough people to make a baseball team AND the cast
  of Friends and the Avengers would have enough people
  to field a football team. If so, the statements will print. */

  if ((friends + beatles >= baseball) &&
      (friends + avengers >= football))
  {
    printf("The cast of friends and the Beatles ");
    printf("could make a baseball team, \n");
    printf("AND the cast of Friends plus the Avengers ");
    printf("could make a football team.\n");
  }
  else
  {
    printf("Either the Friends cannot make a ");
    printf("baseball team with the Fab Four, \n");
    printf("OR they cant't make a Gridiron Gang with the ");
    printf("Avengers (or both!\n)");
  }

  /* This second logical statement uses the OR operator to test
  whether the number of Star Wars movies is less than months
  in the year OR the number of Harry Potter books is less than
  the statements will print. */

  if ((starWars <= months) || (potterBooks <= months))
  {
    printf("\nYou could read one Harry Potter book a month, \n");
    printf("and finish them all in less than a year, \n");
    printf("OR you could see one Star Wars movie a month, \n");
    printf("and finish them all in less than a year. \n");
  }
  else
  {
    printf("Neither can happen--too many books or mives, \n");
    printf("Not enough time! \n");
  }

  /* This final logical statement uses the NOT operator to test
  whether the number of baseball players on a team added
  to the number of basketball plyers on a team is NOT
  greater than the number of football players on a team.
  If so, the statements will print. */

  if (!(baseball + basketball > football))
  {
    printf("\nThere are fewer baseball and basketball players\n");
    printf("combined than football players.");
  }
  else
  {
    printf("\nThere are more baseball and basketball players\n");
    printf("combined than football players.");
  }
  
  return 0;
}
