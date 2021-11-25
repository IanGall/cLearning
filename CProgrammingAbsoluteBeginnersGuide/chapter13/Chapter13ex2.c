#include <stdio.h>

int main(int argc, char const *argv[])
{
  int ctr = 0;

  printf("Counter is at %d.\n", ++ctr);
  printf("Counter is at %d.\n", ++ctr);
  printf("Counter is at %d.\n", ++ctr);
  printf("Counter is at %d.\n", ++ctr);
  printf("Counter is at %d.\n", ++ctr);

  printf("Counter is at %d.\n", --ctr);
  printf("Counter is at %d.\n", --ctr);
  printf("Counter is at %d.\n", --ctr);
  printf("Counter is at %d.\n", --ctr);
  return 0;
}
