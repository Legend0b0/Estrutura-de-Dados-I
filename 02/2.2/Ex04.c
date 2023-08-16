#include <stdio.h>
#include <stdlib.h>

int *Scanv(int n)
  {
  int *v = (int*)malloc(n*sizeof(int));

  puts("Entre com os valores do vetor");
  for(int i = 0; i < n; i++)
    {
    scanf("%d", &v[i]);
    }
  
  return(v);
  }

int ConfOrdem(int *v, int n)
  {
  for(int i = 0; i < n-1; i++)
    {
    if(v[i] > v[i+1])
      {
      return(0);
      }
    }
  return(1);
  }

int
main()
  {
  int n;

  puts("Entre com o tamanho do vetor");
  scanf("%d", &n);

  int *v = Scanv(n);
 
  if(ConfOrdem(v, n))
    {
    printf("Esta ordenado\n");
    }
  else
    {
    printf("Esta desordenado\n");
    }

  return(0);
  }
