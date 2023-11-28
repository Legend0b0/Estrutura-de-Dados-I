#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>

#define X 22 // Após uma analise com media de 100000 elementos para cada valor de X de 1 a 100, conclui que o melhor valor é o 22
#define N 1000

int *Scanv(int n)
{
  int *a = (int*)malloc(n*sizeof(int));

  for(int i = 0; i < n; i++)
  {
    a[i] = rand() % 100;
  }

  return(a);
}

void Printv(int *a, int n)
{
  for(int i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }
  printf("\n\n");
  
  return;
}

void InsertionSort(int *a, int low, int high)
{
  for(int i = low+1; i <= high; i++)
  {
    int ind = a[i];
    for(int j = i-1;((j >= 0) && (ind < a[j])); j--)
    {
      a[j+1] = a[j];
      a[j] = ind;
    }
  }
}

int Partition(int *a, int low, int high)
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

int Randomized_Partition(int *a, int low, int high)
{
  int i = ((rand() % (high - low)) + low);

  int aux = a[i];
  a[i] = a[high];
  a[high] = a[i];
  
  return(Partition(a, low, high));
}

void Randomized_Quicksort(int *a, int low, int high)
{
  if(low < high)
  {
    if((high-low) > X)
    {
      int p = Randomized_Partition(a, low, high);

      Randomized_Quicksort(a, low, p-1);
      Randomized_Quicksort(a, p+1, high);
    }
    else
    {
      InsertionSort(a, low, high);
    } 
  }
  else
  {
    return;
  }
}

int main()
{
  srand(time(NULL));

  int *array = Scanv(N);

  std::chrono::time_point<std::chrono::system_clock> start, end;

  printf("Vetor Desordenado:\n");
  Printv(array, N);

  start = std::chrono::system_clock::now();

  Randomized_Quicksort(array, 0, N-1);

  end = std::chrono::system_clock::now();
 
  printf("Vetor Ordenado:\n");
  Printv(array, N);
  
  std::chrono::duration<double> elapsed_seconds = end - start;

  printf("%3.5lf us\n", ((elapsed_seconds.count())*1000000));

  free(array);

  return 0;
}
