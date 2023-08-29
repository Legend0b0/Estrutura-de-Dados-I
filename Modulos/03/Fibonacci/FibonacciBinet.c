#include <stdio.h>
#include <math.h>

int FibonacciRetardado(int n)
  {
  return(((pow(((1+(sqrt(5))) / 2), n)) - (pow((1 - ((1+(sqrt(5))) / 2)), n))) / sqrt(5));
  }

int
main()
  {
  int n; 

  puts("Entre com o numero 'n'");
  scanf("%d", &n); 

  printf("%d\n", FibonacciRetardado(n));

  return(0);
  }
