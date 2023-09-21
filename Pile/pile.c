#include <stdio.h>
#include <stdlib.h>

struct _pile
{
  int *v;
  int size;
  int top;
};

void start_pile(struct _pile *pile)
{
  pile->top = -1;

  puts("Entre com o tamanho da pilha");
  scanf("%d", &pile->size);

  pile->v = (int*)malloc(pile->size*sizeof(int));
}

int is_empty(struct _pile *pile)
{
  return(pile->top == -1);
}

int is_full(struct _pile *pile)
{
  return((pile->top) == (pile->size - 1));
}

void stack(struct _pile *pile, int value)
{
  if(!(pile->top == (pile->size - 1)))
  {
    pile->top++;
    pile->v[pile->top] = value;
  }
  else
  {
    printf("\nPilha Cheia\n");
  }
}

void unstack(struct _pile *pile)
{
  if(!is_empty(pile))
  {
    pile->top--;
  }
  else
  {
    printf("\nPilha Vazia\n");
  }
}

void search_pile(struct _pile *pile, int value)
{
  int count = 0;

  printf("\n");

  if(!is_empty(pile))
  {
    for(int i = 0; i <= pile->top; i++)
    {
      if(pile->v[i] == value)
      {
        printf("%d  ", i+1);
        count++;
      }
    }
    printf("\n");
  }
  
  if(count == 0)
  {
    printf("-1\n");
  }
}

void print_pile(struct _pile *pile)
{
  printf("\n");
  if(!is_empty(pile))
  {
    for(int i = 0; i <= pile->top; i++)
    {
      printf("%d ", pile->v[i]);
    }
    printf("\n");
  }
  else
  {
    printf("Pilha Vazia\n");
  }
}

void resize_pile(struct _pile *pile, int nsize)
{
  pile->v = (int*)realloc(pile->v, nsize*sizeof(int));
  pile->size = nsize;
}

int
main()
{
  struct _pile pile;
  start_pile(&pile);

  int option;

  do
  {
    printf("\nSelecione uma opcao\n1 - Empilhar\n2 - Desempilhar\n3 - Procurar valor\n4 - Printar Pilha\n5 - Redimencionar pilha\n6 - Sair\n\n");
    scanf("%d", &option);

    switch(option)
    {
      case 1:
      {
        int value;
        printf("\nEntre com o valor a ser empilhado\n");
        scanf("%d", &value);
        stack(&pile, value);
        break;
      }
      case 2:
      {
        unstack(&pile);
        break;
      }
      case 3:
      {
        int value;
        printf("\nEntre com o valor que quer buscar\n");
        scanf("%d", &value);
        search_pile(&pile, value);
        break;
      }
      case 4:
      {
        print_pile(&pile);
        break;
      }
      case 5:
      {
        int nsize;
        printf("\nEntre com o novo tamanho da pilha\n");
        scanf("%d", &nsize);
        resize_pile(&pile, nsize);
        break;
      }
      case 6:
      {
        break;
      }
      default:
      {
        printf("\nOpcao Invalida!\n");
      }
    }
  } while(option != 6);

  pile.v = NULL;
  free(pile.v);

  return(0);
}
