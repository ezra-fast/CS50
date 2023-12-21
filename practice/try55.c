#include <stdio.h>

 int main(void)
 {
  int val1, val2, val3, val4, c1, c2, c3, c4;


  int cube16 = 4096;

  printf("Please enter a 4-digit hex number: ");
  scanf("%lc%lc%lc%lc", &val1, &val2, &val3, &val4);

  c1 = val1;
  c2 = val2;
  c3 = val3;
  c4 = val4;

  // printf("%d %d %d %d \n", val1, val2, val3, val4); -- This line was used to monitor variable values at this point in the execution

  if (val1 >= 65 && val1 <= 70)
  {
     val1 = val1 - 7;
  }
  if (val2 >= 65 && val2 <= 70)
  {
     val2 = val2 - 7;
  }
  if (val3 >= 65 && val3 <= 70)
  {
     val3 = val3 - 7;
  }
  if (val4 >= 65 && val4 <= 70)
  {
     val4 = val4 - 7;
  }

  val1 = val1 - 48;
  val2 = val2 - 48;
  val3 = val3 - 48;
  val4 = val4 - 48;

  // printf("%d %d %d %d \n", val1, val2, val3, val4); -- This line was used to monitor variable values at this point in the execution

  // Process of conversion begins here

  val1 = val1 * cube16;

  cube16 = cube16 >> 4;

  val2 = val2 * cube16;

  cube16 = cube16 >> 4;

  val3 = val3 * cube16;

  cube16 = cube16 >> 4;

  val4 = val4 * cube16;

   int result = val1 + val2 + val3 + val4;

   printf("\t%i is the decimal equivalent of %c%c%c%c\n", result, c1, c2, c3, c4);

   return 0;


 }