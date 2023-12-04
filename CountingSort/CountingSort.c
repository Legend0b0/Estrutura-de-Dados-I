#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 101

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

void CountingSort(int *v, int n)
{
  int *countArray = (int*)calloc(MAX, sizeof(int));

  for(int i = 0; i < n; i++)
  {
    countArray[v[i]]++;
  }

  for(int i = 0, j = 0; j < MAX; j++)
  {
    for(int k = countArray[j]; k > 0; k--)
    {
      v[i] = j;
      i++;
    }
  }
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

  CountingSort(v, n);

  puts("Vetor Desordenado:");
  Printv(v, n);

  free(v);

  return(0);
}
