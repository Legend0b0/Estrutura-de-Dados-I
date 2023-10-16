#include <stdio.h>

void printv(int v[], int n)
  {
  for(int i = 0; i < n; i++)
    {
    printf("%d ", v[i]);
    }
  printf("\n");
  }

void insertionsort(int v[], int n)
  {
  for(int i = 1; i < n; i++)
    {
    int ind = v[i];
    for(int j = i-1, count = 0;((j >= 0) && (ind < v[j])); j--)
      {
      v[j+1] = v[j];
      v[j] = ind;
      }
    }
  }

int
main()
  {
  int n = 10000;
  int v[n];

  insertionsort(v, n);

  printv(v, n);

  return(0);
  }
