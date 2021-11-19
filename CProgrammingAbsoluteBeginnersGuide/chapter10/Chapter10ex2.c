#include <stdio.h>

int main(int argc, char const *argv[])
{
  int ctr = 0;

  ctr += 1;
  printf("Counter is at %d.\n", ctr);
  ctr += 1;
  printf("Counter is at %d.\n", ctr);

  printf("Counter is at %d.\n", ctr += 1);
  ctr += 1;
  printf("Counter is at %d.\n", ctr);

  printf("Counter is at %d.\n", ctr += 1);
  ctr -= 1;
  printf("Counter is at %d.\n", ctr);
  printf("Counter is at %d.\n", ctr -= 1);
  printf("Counter is at %d.\n", ctr -= 1);
  printf("Counter is at %d.\n", ctr -= 1);
  return 0;
}
