#include <stdio.h>
#include <stdlib.h>

int *Scanv(int n)
{
  int *a = (int*)malloc(n*sizeof(int));

  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }

  return(a);
}

void Printv(int *a, int n)
{
  for(int i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }
  printf("\n");
  
  return;
}

int partition(int *a, int low, int high)
{
  int pivot = a[high];
  
  low--;
  
  for(int i = low+1; i < high; i++)
  {
    if(a[i] <= pivot)
    {
      low++;
      
      int aux = a[low];
      a[low] = a[i];
      a[i] = aux;
    }
  }

  int aux = a[low + 1];
  a[low + 1] = a[high];
  a[high] = aux;

  return(low + 1);
}

void quicksort(int *a, int low, int high)
{
  if(low < high)
  {
    int p = partition(a, low, high);

    quicksort(a, low, p-1);
    quicksort(a, p+1, high);
  }
  else
  {
    return;
  }
}

int main()
{
  int n = 0;

  printf("Entre com o tamanho do vetor\n");
  scanf("%d", &n);

  int *array = Scanv(n);

  Printv(array, n);
  
  quicksort(array, 0, n-1);
  
  Printv(array, n);

  return 0;
}
