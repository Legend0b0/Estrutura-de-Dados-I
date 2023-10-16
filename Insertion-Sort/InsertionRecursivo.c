#include <stdio.h>
#include <stdlib.h>

int *Scanv(int n)
  {
  int *v = (int*)malloc(n*sizeof(int));

  for(int i = 0; i < n; i++)
    {
    scanf("%d", &v[i]);
    }

  return(v);
  }

void printv(int *v, int n)
  {
  for(int i = 0; i < n; i++)
    {
    printf("%d ", v[i]);
    }
  printf("\n");
  }

void insertion(int *v, int n)
  {
  int ind = v[n-1];
  for(int i = n-2; ((i >= 0) && (ind < v[i])); i--)
    {
    v[i+1] = v[i];
    v[i] = ind;
    }
  }

void insertionsort(int *v, int n)
  {
  if(n == 1)
    {
    return;
    }
  insertionsort(v, n-1);
  insertion(v, n);
  }

int
main()
  {
  int n;
  
  puts("Entre com o tamanho do vetor");
  scanf("%d", &n);

  puts("Entre com os valores do vetor");
  int *v = Scanv(n);

  insertionsort(v, n); 
  printv(v, n);

  free(v);

  return(0);
  }
