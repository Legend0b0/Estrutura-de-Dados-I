/*
Com base em uma média de 100000 valores para cada valor de X de 1 a 100 presentes no arquivo "Results.txt", conclui que o melhor valor para X
usando o metodo do Randomized QuickSort junto do InsertionSort é de 22, e nesses resultados é possivel concluir que quando X é um valor baixo,
o tempo de execução é alto, pela alta constante no metodo do QuickSort, e quando o valor de X é muito alto, como o InsertionSort é uma função
N quadratica, torna o tempo alto tambem, e como analizado nos resultados o valor para X que mais se assemelha ao vertice dessa parabula, é o 22.
(No código-fonte está sendo realizado uma média de 1000 elementos para ter uma resposta um pouco mais precisa, não deixei 100000 como nos testes
por conta do alto tempo para execução do código).

_______________________
|   X   |    T(us)    |
|    1  |   85.29089  |
|    2  |   82.58819  |
|    3  |   79.52185  |
|    4  |   76.33294  |
|    5  |   73.28030  |
|    6  |   70.36216  |
|    7  |   67.75039  |
|    8  |   65.42411  |
|    9  |   63.51678  |
|   10  |   61.86991  |
|   11  |   60.73948  |
|   12  |   60.06502  |
|   13  |   59.41638  |
|   14  |   58.90489  |
|   15  |   58.55970  |
|   16  |   58.34780  |
|   17  |   58.21306  |
|   18  |   58.09864  |
|   19  |   58.03913  |
|   20  |   57.98270  |
|   21  |   57.94971  |
|   22  |   57.89863  |
|   23  |   57.91919  |
|   24  |   57.94992  |
|   25  |   58.01836  |
|   26  |   58.07627  |
|   27  |   58.15002  |
|   28  |   58.25112  |
|   29  |   58.40475  |
|   30  |   58.47930  |
|   31  |   58.58503  |
|   32  |   58.78353  |
|   33  |   58.91682  |
|   34  |   59.03938  |
|   35  |   59.13893  |
|   36  |   59.35104  |
|   37  |   59.45148  |
|   38  |   59.60358  |
|   39  |   59.75744  |
|   40  |   59.83482  |
|   41  |   60.05203  |
|   42  |   60.32766  |
|   43  |   60.54669  |
|   44  |   60.63099  |
|   45  |   60.75045  |
|   46  |   60.91169  |
|   47  |   61.14616  |
|   48  |   61.39566  |
|   49  |   61.66053  |
|   50  |   61.88255  |
|   51  |   62.12960  |
|   52  |   62.24790  |
|   53  |   62.47496  |
|   54  |   62.57722  |
|   55  |   62.77763  |
|   56  |   62.94739  |
|   57  |   63.19096  |
|   58  |   63.42863  |
|   59  |   63.68106  |
|   60  |   63.89642  |
|   61  |   64.21642  |
|   62  |   64.57428  |
|   63  |   64.89800  |
|   64  |   65.07536  |
|   65  |   65.39129  |
|   66  |   65.57963  |
|   67  |   65.69738  |
|   68  |   65.90999  |
|   69  |   66.04812  |
|   70  |   66.33665  |
|   71  |   66.60778  |
|   72  |   66.93667  |
|   73  |   67.22830  |
|   74  |   67.56199  |
|   75  |   67.70549  |
|   76  |   67.90795  |
|   77  |   68.29991  |
|   78  |   68.49440  |
|   79  |   68.73979  |
|   80  |   68.91450  |
|   81  |   69.33945  |
|   82  |   69.68715  |
|   83  |   69.98356  |
|   84  |   70.20534  |
|   85  |   70.59327  |
|   86  |   70.79265  |
|   87  |   70.96820  |
|   88  |   71.29296  |
|   89  |   71.61526  |
|   90  |   71.87936  |
|   91  |   72.14522  |
|   92  |   72.46400  |
|   93  |   72.88547  |
|   94  |   73.15276  |
|   95  |   73.33426  |
|   96  |   73.55717  |
|   97  |   73.75418  |
|   98  |   74.19948  |
|   99  |   74.52842  |
|  100  |   74.88118  |
|_______|_____________|
|     Melhor Tempo    |
|   22  |   57.89863  |
|_______|_____________|
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>

#define N 1000
#define repit 1000

int *Scanv(int n)
{
  FILE *file;
  file = fopen("Entrada.txt", "r");

  if(file != NULL)
  {
    int *a = (int*)malloc(n*sizeof(int));

    for(int i = 0; i < n; i++)
    {
      fscanf(file, "%d", &a[i]);
    }

    fclose(file);

    return(a);
  }
  else
  {
    printf("Error File\n");
    return(NULL);
  }
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

void OpenFile(int n)
{
  FILE *file;
  file = fopen("Entrada.txt", "w");
 
  if(file != NULL)
  {
    for(int i = 0; i < n; i++)
    {
      fprintf(file, "%d\n", rand() % 100);
    }
    
    fclose(file);
  }
  else
  {
    printf("Error File\n");
  }
  return;
}

void InsertionSort(int *a, int low, int high)
{
  for(int i = low+1; i <= high; i++)
  {
    int ind = a[i];
    int j = i-1;
    for(;((j >= low) && (ind < a[j])); j--)
    {
      a[j+1] = a[j];
    }
    a[j] = ind;
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
  int i = ((rand() % (high - low + 1)) + low);

  int aux = a[i];
  a[i] = a[high];
  a[high] = aux;
  
  return(Partition(a, low, high));
}

void Randomized_Quicksort(int *a, int low, int high, int x)
{
  if(low < high)
  {
    if((high-low) > x)
    {
      int p = Randomized_Partition(a, low, high);

      Randomized_Quicksort(a, low, p-1, x);
      Randomized_Quicksort(a, p+1, high, x);
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

  OpenFile(N);

  double result[100];

  printf("_______________________\n");
  printf("|   X   |    T(us)    |\n");

  for(int X = 1; X <= 100; X++)
  {
    result[X-1] = 0.0;

    for(int i = 0; i < repit; i++)
    {
      int *array = Scanv(N);

      auto start = std::chrono::high_resolution_clock::now();
        
      Randomized_Quicksort(array, 0, N-1, X);
      
      auto end = std::chrono::high_resolution_clock::now();
 
      std::chrono::duration<double> time = end - start;
      
      result[X-1] += time.count() * 1000000;
  
      free(array);

    }
   
    result[X-1] /= repit;
    
    printf("|  %3d  |  %9.5lf  |\n", X, result[X-1]);
  }
  
  printf("|_______|_____________|\n");

  int ind = 0;

  for(int i = 2; i <= 100; i++)
  {
    if(result[ind] > result[i-1])
    {
      ind = i-1;
    }
  }

  printf("|     Melhor Tempo    |\n");
  printf("|  %3d  |  %9.5lf  |\n", ind+1, result[ind]);
  printf("|_______|_____________|\n");

  remove("Entrada.txt");

  return 0;
}
