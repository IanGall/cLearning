#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
  float L, C, w, f;

  printf("Input Capacitance (microfarads): ");
  scanf(" %f", &C);

  printf("Input Inductance (microhenrys): ");
  scanf(" %f", &L);

  C /= 1000000;
  L /= 1000;

  w = 1 / sqrt(C * L);
  f = w / (2 * M_PI);

  printf("Resonant Frequency is %.3f\n", f);
  return 0;
}
