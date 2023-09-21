#include <stdio.h>
#include <stdlib.h>

struct _queue
{
  int *v;
  int size;
  int start;
  int end;
  int full;
};

void start_queue(struct _queue *queue)
{
  printf("Entre com o tamanho da fila\n");
  scanf("%d", &queue->size);

  queue->v = (int*)malloc(queue->size*sizeof(int));
  
  queue->start = 0;
  queue->end = 0;
  queue->full = 0;
}

int is_empty(struct _queue *queue)
{
  return((queue->start == queue->end) && (queue->full == 0));
}

int is_full(struct _queue *queue)
{
  return((queue->start == queue->end) && (queue->full == 1));
}

void enqueue(struct _queue *queue, int value)
{
  if(!is_full(queue))
  {
    queue->v[queue->end] = value;
    queue->end++;
    
    if(queue->end == queue->size)
    {
      queue->end = 0;
    }

    if(queue->end == queue->start)
    {
      queue->full = 1;
    }
  }
  else
  {
    printf("\nFila Cheia\n");
  }
}

void dequeue(struct _queue *queue)
{
  if(!is_empty(queue))
  {
    queue->start++;

    if(queue->start == queue->size)
    {
      queue->start = 0;
    }

    if(queue->full == 1)
    {
      queue->full = 0;  
    }
  }
  else
  {
    printf("\nFila Vazia\n");
  }
}

void print_queue(struct _queue *queue)
{ 
  printf("\n");

  if(queue->start < queue->end)
  {
    for(int i = queue->start; i < queue->end; i++)
    {
      printf("%d ", queue->v[i]);
    }
    printf("\n");
  }
  if((queue->start > queue->end) || (is_full(queue)))
  {
    for(int i = queue->start; i < queue->size; i++)
    {
      printf("%d ", queue->v[i]);
    }
    for(int i = 0; i < queue->end; i++)
    {
      printf("%d ", queue->v[i]);
    }
    printf("\n");
  }
  if(is_empty(queue))
  {
    printf("Fila Vazia\n");
  }
}

void search_queue(struct _queue *queue, int value)
{  
  int index = 1;
  int count = 0;

  printf("\n");

  if(!is_empty(queue))
  {
    if(queue->start < queue->end)
    {
      for(int i = queue->start; i < queue->end; i++)
      {
        if(queue->v[i] == value)
        {
          printf("%d ", index);
          count++;
        }
        index++;
      }
      printf("\n");
    }
    if((queue->start > queue->end) || (is_full(queue)))
    {
      for(int i = queue->start; i < queue->size; i++)
      {
        if(queue->v[i] == value)
        {
          printf("%d  ", index);
          count++;
        }
        index++;
      }
      for(int i = 0; i < queue->end; i++)
      {
        if(queue->v[i] == value)
        {
          printf("%d ", index);
          count++;
        }
        index++;
      }
      printf("\n");
    }
  }
  if(count == 0)
  {
    printf("-1\n");
  }
}

int
main()
{
  struct _queue queue;

  start_queue(&queue);

  int option;
  do
  {
    printf("\n\nSelecione uma opcao\n1 - Enfileirar\n2 - Desenfileirar\n3 - Procurar um valor\n4 - Printar Fila\n5 - Sair\n\n");
    scanf("%d", &option);

    switch(option)
    {
      case 1:
      {
        int value;
        
        printf("\nEntre com o valor a ser enfileirado\n");
        scanf("%d", &value);

        enqueue(&queue, value);

        break;
      }
      case 2:
      {
        dequeue(&queue);

        break;
      }
      case 3:
      {
        int value;
        
        printf("\nEntre com o valor a ser enfileirado\n");
        scanf("%d", &value);

        search_queue(&queue, value);
      
        break;
      }
      case 4:
      {
        print_queue(&queue);

        break;
      }
      case 5:
      {
        break;
      }
      default:
      {
        printf("\nOpção Invalida!\n");
        break;
      }
    }
  } while(option != 5);

  queue.v = NULL;
  free(queue.v);

  return(0);
}
