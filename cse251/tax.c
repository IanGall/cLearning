#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
  float annualIncome, tax, stardardDeduction, totalDeductions;
  int taxOption, dependentsNum, childrenNum;
  printf("Please enter your annual income!\n");
  scanf(" %f", &annualIncome);

  if (annualIncome < 9350.0f)
  {
    tax = 0;
    printf("Your tax is %.2f!\n", tax);
    exit(0);
  }

  printf("Please specify filing status, either as: 1-single; 2-married, filing jointly; 3-married, filing separately.\n");
  scanf(" %d", &taxOption);

  if (1 == taxOption || 3 == taxOption)
  {
    dependentsNum = 1;
    stardardDeduction = 5700.0f;
  }
  else if (2 == taxOption)
  {
    stardardDeduction = 11400.0f;
    printf("Please enter the number of children!\n");
    scanf(" %d", &childrenNum);
    dependentsNum = 2 + childrenNum;
  }
  totalDeductions = dependentsNum * 3650 + stardardDeduction;
  annualIncome -= totalDeductions;

  float lv1 = 137300.0f, lv2 = 68000.0f, lv3 = 16750.0f;

  if (annualIncome > lv1)
  {
    tax = 26687.50f + (annualIncome - lv1) * 0.28;
  }
  else if (annualIncome > lv2)
  {
    tax = 9362.50 + (annualIncome - lv2) * 0.25;
  }
  else if (annualIncome > lv3)
  {
    tax = 1675 + (annualIncome - lv3) * 0.15;
  }
  else
  {
    tax = annualIncome * 0.1;
  }

  printf("Your amount of taxes is %.2f\n", tax);
  return 0;
}
