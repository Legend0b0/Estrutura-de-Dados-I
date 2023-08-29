#include <stdio.h>
#include <math.h>

int
main()
  {
  float n = 1.0;
  float x = 1.0;

  while(x >= 0.0001)
    {
    while((100*(pow(n,2))) > (pow(2,n)))
      {
      n += x;
      }
    n -= x;
    x /= 10;
    }

  printf("Ele passa a ser mais rapido apartir de: %.3f\n", n);

  return(0);
  }
