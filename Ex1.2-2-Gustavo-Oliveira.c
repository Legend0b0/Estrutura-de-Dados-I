#include <stdio.h>
#include <math.h>

int
main()
  {
  float n = 2.0;
  float x = 1.0;

  while(x >= 0.0001)
    {
    while((8*(pow(n,2))) < (64*n*(log2(n))))
      {
      n += x;
      }
    n -= x;
    x /= 10;
    }

  printf("Insertion Sort é mais rapido que o Merge Sort para os valores abaixo de: %.3f\n", n);

  return(0);
  }
