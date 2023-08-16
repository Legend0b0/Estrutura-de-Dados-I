#include <stdio.h>

int iterative_binary_search(int v[], int n, int k)
  {
  int begin = 0;
  int end = n-1;

 while(begin <= end)
    {
    int i = (begin + end) / 2;

    if(v[i] == k)
      {
      return i+1;
      }
    if(v[i] < k)
      {
      begin = i + 1;
      }
    else
      {
      end = i;
      }
    }
  return(-1);
  }

int
main()
  {
  int v[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int k;
  
  puts("Entre com o indice 'k'");
  scanf("%d", &k);

  printf("%d\n", iterative_binary_search(v, 10, k));

  return 0;
  }
