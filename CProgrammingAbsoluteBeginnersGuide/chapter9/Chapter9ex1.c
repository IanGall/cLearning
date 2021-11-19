#include <stdio.h>
int main(int argc, char const *argv[])
{
  // Two sets of equivalent variables, with one set
  // floating-point and other integer

  float a = 19.0;
  float b = 5.0;
  float floatAnswer;

  int x = 19;
  int y = 5;
  int intAnswer;

  // Using two float varia bles creates an answer of 3.8
  floatAnswer = a / b;
  printf("%.1f divided by %.1f equals %.1f\n", a, b, floatAnswer);

  floatAnswer = x / y; //Take 2 creates an answer of 3.0
  printf("%d divided by %d equals %.1f\n", x, y, floatAnswer);

  // This will also be 3, as it truncates and doesn't round up
  intAnswer = a / b;
  printf("%.1f divided by %.1f equals %d\n", a, b, intAnswer);

  intAnswer = x % y;
  printf("%d modulus (i.e. remainder of) %d equals %d", x, y, intAnswer);

  return 0;
}
