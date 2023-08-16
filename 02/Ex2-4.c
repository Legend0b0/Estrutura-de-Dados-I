//Inicialização: Antes da primeira iteração do loop, i=0, isso é consistente com a inicialização no laço i<n.
//Manutenção: O corpo do laço se move até o valor do v[i] ser igual a x, quando for, printar o indice.
//Terminação: O laço termina quando i é igual a n, e a no terminal mostra o indice quando encontrado ou NULL quando não encontrado,
//oque mostra que o algoritmo esta certo.

#include <stdio.h>

int
main()
  {
  int n;
  int x;

  puts("Entre com o tamanho do vetor");
  scanf("%d", &n);

  int v[n];
  puts("Entre com os valores do vetor");
  for(int i = 0; i < n; i++)
    {
    scanf("%d", &v[i]);
    }

  puts("Entre com o elemento a ser buscado");
  scanf("%d", &x);

  int count = 0;
  printf("Indice: ");
  
  for(int i = 0; i < n; i++)
    {
    if(v[i] == x)
      {
      if(count > 0)
        {
        printf(", ");
        }
      
      printf("%d", i+1);
      count++;
      }
    }

    if(count == 0)
      {
      printf("NULL");
      }
    printf("\n");

  return(0);
  }
