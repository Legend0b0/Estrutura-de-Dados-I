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

void Merge(int *v, int pL, int pR, int n)
  {
  int nL = pR - pL;
  int nR = n - pR;

  int vL[nL];
  for(int i = 0; i < nL; i++)
    {
    vL[i] = v[pL+i];
    }
  
  int vR[nR];
  for(int i = 0; i < nR; i++)
    {
    vR[i] = v[pR+i];
    }

  int i = 0, j = 0, k = pL;
  while((i < nL) && (j < nR))
    {
    if(vL[i] <= vR[j])
      {
      v[k] = vL[i];
      i++;
      }
    else
      {
      v[k] = vR[j];
      j++;
      }
    k++;
    }
  
  while(i < nL)
    {
    v[k] = vL[i];
    i++;
    k++;
    }

  while(j < nR)
    {
    v[k] = vR[j];
    j++;
    k++;
    }
  }

void MergeSort(int *v, int pL, int n)
  {
  if(pL >= n-1)
    {
    return;
    }
  int q = (pL + n) / 2;
  MergeSort(v, pL, q);
  MergeSort(v, q, n);

  Merge(v, pL, q, n);
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
      begin = i + 1;
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
  int n, x;

  puts("Entre com o tamanho do vetor");
  scanf("%d", &n);

  int *v = Scanv(n);
  
  puts("Entre com o valor X");
  scanf("%d", &x);

  MergeSort(v, 0, n);
  
  for(int i = 0; i < n; i++)
    {
    int aux = iterative_binary_search(v, n, x-v[i]);

    if(aux != -1)
      {
      printf("True - %d + %d = %d\n", v[i], v[aux], x);
      }
    }

  free(v);

  return(0);
  }
