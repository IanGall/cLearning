#include <stdio.h>
#include <math.h>

/*
 * Name : IanQian
 * 
 * This is my first CSE 251 C program!!!
 */
int main(int argc, char const *argv[])
{
  /* code */
  double radius = 7.88;
  double height = 12.231;

  printf("My first C program a\n");
  printf("Are't you impressed?\n");

  printf("The cylinder has a radius of %f and a height of %f\n", radius, height);
  printf("The cylinder has a radius of %+8.3f and a height of %f\n", radius, height);
  printf("The cylinder has a radius of %5.2f and a height of %8.1f\n", radius, height);

  int wins = 11, losses = 2;
  printf("MSU had an %d-%d season in 2010!\n", wins, losses);

  /* 3. Expressions */
  double volume, dismeter, hypot;
  int games;

  volume = radius * radius * M_PI * height;

  games = wins + losses;

  double near = 10;
  double far = 22.5;

  hypot = sqrt(near * near + far * far);

  double bottleVolume = 1700;
  double cupVolume = 350;
  int numCups;

  // numCups = bottleVolume / cupVolume;
  numCups = (int)(bottleVolume / cupVolume);
  printf("Number of cups: %d\n", numCups);

  return 0;
}
