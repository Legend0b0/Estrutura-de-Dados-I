#include <stdio.h>
#include <stdlib.h>

struct Heap
{
  int *a;
  int capacity;
  int size;
};

struct Heap *Create_Heap()
{
  struct Heap *heap = (struct Heap*)malloc(sizeof(struct Heap));
 
  if(heap != NULL)
  {
    heap->capacity = 0;
    heap->size = -1;

    puts("Entre com o tamanho da arvore heap");
    scanf("%d", &heap->capacity);
    
    heap->a = (int *)malloc(heap->capacity * sizeof(int));

    if(heap->a != NULL)
    {
      return(heap);
    }
    else
    {
      puts("Error Malloc Array");
      free(heap->a);
      free(heap);

      return(NULL);
    }
  }
  else
  {
    puts("Error Malloc Heap");
    free(heap);

    return(NULL);
  }
}

int Parent(int i)
{
  return((i-1)/2);
}

int Left(int i)
{
  return((i*2)+1);
}

int Right(int i)
{
  return((i*2)+2);
}

void Max_Heapify(struct Heap *heap, int i)
{
  int l = Left(i);
  int r = Right(i);
  int higher = i;

  if((l <= heap->size) && (heap->a[l] > heap->a[higher]))
  {
    higher = l;
  }

  if((r <= heap->size) && (heap->a[r] > heap->a[higher]))
  {
    higher = r;
  }
  
  if(higher != i)
  {
    int aux = heap->a[higher];
    heap->a[higher] = heap->a[i];
    heap->a[i] = aux;

    Max_Heapify(heap, higher);
  }
}

void Build_Max_Heap(struct Heap *heap)
{
  for(int i = Parent(heap->size); i >= 0; i--)
  {
    Max_Heapify(heap, i);
  }
}

void Min_Heapify(struct Heap *heap, int i)
{
  int l = Left(i);
  int r = Right(i);
  int smaller = i;

  if((l <= heap->size) && (heap->a[l] < heap->a[smaller]))
  {
    smaller = l;
  }

  if((r <= heap->size) && (heap->a[r] < heap->a[smaller]))
  {
    smaller = r;
  }
  
  if(smaller != i)
  {
    int aux = heap->a[smaller];
    heap->a[smaller] = heap->a[i];
    heap->a[i] = aux;

    Min_Heapify(heap, smaller);
  }
}

void Build_Min_Heap(struct Heap *heap)
{
  for(int i = Parent(heap->size); i >= 0; i--)
  {
    Min_Heapify(heap, i);
  }
}

void HeapSort(struct Heap *heap)
{
  int n = heap->size;
  Build_Max_Heap(heap);

  for(int i = n; i > 0; i--)
  {
    int aux = heap->a[0];
    heap->a[0] = heap->a[i];
    heap->a[i] = aux;

    heap->size--;

    Max_Heapify(heap, 0);
  } 

  heap->size = n;
}

void Insert(struct Heap *heap, int value)
{
  if((heap->size + 1) != heap->capacity)
  {
    heap->size++;
    heap->a[heap->size] = value;
  }
  else
  {
    printf("\nArvore Heap Cheia\n");
  }
}

void Print_Node(int value, int b)
{
  for(int i = 0; i < b; i++)
  {
    printf("\t");
  }
  printf("%d\n", value);
}

void Print_Heap(struct Heap *heap, int i, int b)
{
  if(i > heap->size)
  {
    return;
  }

  Print_Heap(heap, Right(i), b+1);
  Print_Node(heap->a[i], b);
  Print_Heap(heap, Left(i), b+1);
}

void Free_Heap(struct Heap *heap)
{
  free(heap->a);
  free(heap);
}

int main()
{
  struct Heap *heap = Create_Heap();

  int option = 0;

  while(option != 6)
  {
    printf("Escolha uma opcao:\n\n1 - Insert\n2 - Max-Heapify\n3 - Min-Heapify\n4 - Heapsort\n5 - Printar arvore Heap\n6 - Sair\n\n");
    scanf("%d", &option);
    printf("\n");

    switch(option)
    {
      case 1:
      {
        int value = 0;

        printf("Entre com o valor a ser inserido\n");
        scanf("%d", &value);

        Insert(heap, value);

        break;
      }
      case 2:
      {
        Build_Max_Heap(heap);
        
        break;
      }
      case 3:
      {
        Build_Min_Heap(heap);

        break;
      }
      case 4:
      {
        HeapSort(heap);

        break;
      }
      case 5:
      {
        printf("\n");
        if(heap->size >= 0)
        {
          Print_Heap(heap, 0, 0);
        }
        else
        {
          printf("Arvore Heap Vazia\n");
        }
        printf("\n");

        break;
      }
      case 6:
      {
        break;
      }
      default:
      {
        printf("Opcao invalida\n");
        break;
      }
    }
  }

  Free_Heap(heap);

  return(0);
}
