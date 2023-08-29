#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void ReadBin(int *X, int n)
  {
  int val;
  do
    {
    val = 0;
    int bin;

    scanf("%d", &bin);
    
    for(int i = n-1; i >= 0; i--)
      {
      X[i] = bin % 10;
      bin /= 10;

      if(X[i] != 0 && X[i] != 1)
        {
        puts("Numero invalido, digite novamente");
        val = 1;
        break;
        }
      }
    } while(val);
  }
    
int* addBinaryIntegers(int *A, int *B, int *C, int n)
  {
  int vai1 = 0;
  
  for(int i = n; i > 0; i--)
    {
    if(A[i-1] && B[i-1])
      {
      if(vai1)
        {
        C[i] = 1;
        }
      else
        {
        C[i] = 0;
        }
      vai1 = 1;
      }
    else
      {
      if(A[i-1] || B[i-1])
        {
        if(vai1)
          {
          C[i] = 0;
          }
        else
          {
          C[i] = 1;
          }
        }
      else
        {
        if(vai1)
          {
          C[i] = 1;
          vai1 = 0;
          }
        else
          {
          C[i] = 0;
          }
        }
      }
    }
    if(vai1)
      {
      C[0] = 1;
      }
    else
      {
      C[0] = 0;
      }

  return(C);
  }

int
main()
  {
  int n;

  puts("Entre com a quantidade de bits");
  scanf("%d", &n);

  int *A = (int*)malloc(n*sizeof(int));
  puts("Entre com o binario A");
  ReadBin(A, n);

  int *B = (int*)malloc(n*sizeof(int));
  puts("Entre com o binario B");
  ReadBin(B, n);

  int *C = (int*)malloc((n+1)*sizeof(int));  
  C = addBinaryIntegers(A, B, C, n);

  for(int i = 0; i <= n; i++)
    {
    printf("%d", C[i]);
    }
  printf("\n");

  return(0);
  }
