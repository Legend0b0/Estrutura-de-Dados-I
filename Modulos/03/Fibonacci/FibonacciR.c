#include <stdio.h>

int FibonacciRecursivo(int n)
  {
  if(n <= 1)
    {
    return(n);
    }
  return(FibonacciRecursivo(n-1) + FibonacciRecursivo(n-2));
  }

int
main()
  {
  int n; 

  puts("Entre com o numero 'n'");
  scanf("%d", &n); 

  printf("%d\n", FibonacciRecursivo(n));

  return(0);
  }
