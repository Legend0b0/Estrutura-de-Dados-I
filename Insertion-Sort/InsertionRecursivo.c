#include <stdio.h>

void printv(int v[], int n)
  {
  for(int i = 0; i < n; i++)
    {
    printf("%d ", v[i]);
    }
  printf("\n");
  }

void insertion(int v[], int n)
  {
  int ind = v[n-1];
  for(int i = n-2; ((i >= 0) && (ind < v[i])); i--)
    {
    v[i+1] = v[i];
    v[i] = ind;
    }
  }

void insertionsort(int v[], int n)
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
  int n = 100000;
  int v[n];
  
  insertionsort(v, n); 
  printv(v, n);

  return(0);
  }
