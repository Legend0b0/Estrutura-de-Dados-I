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

void Printv(int *v, int n)
  {
  for(int i = 0; i < n; i++)
    {
    printf("%d ", v[i]);
    }
  printf("\n");

  return;
  }

void SelectionSort(int v[], int n)
  {
  for(int i = 0; i < n-1; i++)
    {
    int imin = i;
    for(int j = i+1; j < n; j++)
      {
      if(v[imin] > v[j])
        {
        imin = j;
        }
      }
    if(imin != i)
      {
      int tmp = v[i];
      v[i] = v[imin];
      v[imin] = tmp;
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
  
  SelectionSort(v, n);

  Printv(v, n);

  return(0);
  }
