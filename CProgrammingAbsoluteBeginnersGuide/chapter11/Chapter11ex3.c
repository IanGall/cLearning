#include <stdio.h>

int main(int argc, char const *argv[])
{
  int perfer;
  printf("On a scale of 1 to 10, how happy are you?\n");
  scanf(" %d", &perfer);

  /* Once the user's level of happiness is entered, a series of if statements
  test the number against decreasing numbers. only one of the four will be executed */

  if (perfer >= 8)
  {
    printf("Great for you!\n");
    printf("Things are going well for you!\n");
  }
  else if (perfer >= 5)
  {
    printf("Better than average, right?\n");
    printf("Maybe things will get even better soon!\n");
  }
  else if (perfer>=3)
  {
    printf("Sorry you're feeling not so great.\n");
    printf("Hope things  turn around soon...\n");
  }
  else
  {
    printf("Hang in there--things have to improve, right?\n");
    printf("Always darkest before the dawn.\n");
  }
  
  

  return 0;
}
