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

int
main()
  {
  int n;

  puts("Entre com o tamanho do vetor");
  scanf("%d", &n);

  int *v = Scanv(n);
  
  MergeSort(v, 0, n);
  
  Printv(v, n);

  free(v);

  return(0);
  }
