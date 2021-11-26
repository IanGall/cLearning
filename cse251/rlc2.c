#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
  float L, C, w, f;
  bool valid = true; /* Until we know otherwise */

  printf("Input Inductance (microhenrys): ");
  scanf(" %f", &L);

  /* Test to see if the user entered an invalid value */
  if (L < 0)
  {
    printf("You moron, you entered a negative inductance!\n");
    valid = false;
  }
  else if (L == 0)
  {
    printf("You are really dumb, you entered zero.\n");
    valid = false;
  }
  else
  {
    printf("Okay, I guess that's reasonable\n");
  }

  /* Given a negative or zero inductance value will change the value
  to be a default value of 1 */
  if (L <= 0)
  {
    L = 1;
  }

  printf("Input Capacitance (microfarads): ");
  scanf(" %f", &C);

  if (C < 0)
  {
    printf("You moron, you entered a negative Capacitance!\n");
  }
  else if (C == 0)
  {
    printf("You are really dumb, you entered zero.\n");
  }
  else
  {
    printf("Okay, I guess that's reasonable\n");
  }

  if (C <= 0)
  {
    C = 1;
  }

  if (valid)
  {
    C /= 1000000;
    L /= 1000;

    w = 1 / sqrt(C * L);
    f = w / (2 * M_PI);

    printf("Resonant Frequency is %.3f\n", f);

    if (20 <= f && f <= 20000)
    {
      printf("This frequency is one I can hear!\n");
    }
  }

  return 0;
}
