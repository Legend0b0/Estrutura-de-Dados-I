#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

int *Scanv(int n)
{
  int *v = (int*)malloc(n*sizeof(int));

  for(int i = 0; i < n; i++)
  {
    v[i] = rand() % MAX;
  }

  return(v);
}

void Printv(int *v, int n)
{
  for(int i = 0; i < n; i++)
  {
    printf("%d ", v[i]);
  }
  printf("\n\n");
}

void RadixSort(int *v, int n)
{
  
}

int
main()
{
  int n;
  
  puts("Entre com o tamanho do vetor");
  scanf("%d", &n);

  int *v = Scanv(n);

  puts("Vetor Desordenado:");
  Printv(v, n);

  RadixSort(v, n);

  puts("Vetor Desordenado:");
  Printv(v, n);

  free(v);

  return(0);
}
