/* clock example: countdown */
#include <stdio.h>
#include <time.h>
#include <windows.h>



int main ()
{
  int n;
  printf ("Starting countdown...\n");
  for (n=10; n>0; n--)
  {
    printf ("%d\n",n);
    Sleep(1000);
  }
  printf ("FIRE!!!\n");
  return 0;
}
