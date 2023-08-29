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

void Printv(int *v, int n)
  {
  for(int i = 0; i < n; i++)
    {
    printf("%d ", v[i]);
    }
  printf("\n");
  
  return;
  }

int iterative_binary_search(int v[], int n, int k)
  {
  int begin = 0;
  int end = n-1;

 while(begin <= end)
    {
    int i = (begin + end) / 2;

    if(v[i] == k)
      {
      return i;
      }
    if(v[i] < k)
      {
      begin = i+1;
      }
    else
      {
      end = i-1;
      }
    }
  return(-1);
  }

int
main()
  {
  int n;

  puts("Entre com o tamanho do vetor");
  scanf("%d", &n);

  puts("Entre com os valores do vetor");
  int *v = Scanv(n);

  int k;
  
  puts("Entre com o indice 'k'");
  scanf("%d", &k);

  printf("Indice: %d\n", iterative_binary_search(v, n, k));

  return 0;
  }
