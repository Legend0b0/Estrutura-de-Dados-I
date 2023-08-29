#include <stdio.h>

int FibonacciIterativo(int n)
  {
  int fiboA = 0;
  int fiboB = 1;
  
  for(int i = 1; i < n; i++)
    {
    int aux = fiboB;
    fiboB += fiboA;
    fiboA = aux;
    }
  
  return(fiboB);
  }

int
main()
  {
  int n; 

  puts("Entre com o numero 'n'");
  scanf("%d", &n); 

  printf("%d\n", FibonacciIterativo(n));

  return(0);
  }
