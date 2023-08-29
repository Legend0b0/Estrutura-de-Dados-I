#include <stdio.h>

int sumArray(int v[], int n)
  {
  int soma = 0;
  for(int i = 0; i < n; i++)
    {
    soma += v[i];
    }
  return(soma);
  }

int
main()
  {
  int n = 6;
  int v[6] = {31, 41, 59, 26, 41, 58};
  
  printf("Soma: %d\n", sumArray(v, n));

  return(0);
  }
