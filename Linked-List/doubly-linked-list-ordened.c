#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
  struct Node *next;
  struct Node *prev;
  int data;
};

struct List
{
  struct Node *head;
};

struct List* create_list()
{
  struct List *list = (struct List*)malloc(sizeof(struct List));
  if(list != NULL)
  {
    list->head = NULL;
    return(list);
  }
  else
  {
    printf("\nError Create List\n");
    free(list);
    return(NULL);
  }
}

struct Node* create_node()
{
  struct Node *node = (struct Node*)malloc(sizeof(struct Node));

  if(node != NULL)
  {
    node->next = NULL;
    node->prev = NULL;
    return(node);
  }
  else
  {
    printf("\nError Create Node\n");
    free(node);
    return(NULL);
  }
}

int is_empty(struct List *list)
{
  return(list->head == NULL);
}

void insert_begin(struct List *list, int value)
{
  struct Node *aux = create_node(); 

  aux->data = value;

  aux->next = list->head;
  
  if(!is_empty(list))
  {
    list->head->prev = aux;
  }

  list->head = aux;
}

void insert_end(struct List *list, int value)
{ 
  if(is_empty(list))
  {
    insert_begin(list, value);
  }
  else
  {
    struct Node *aux = list->head;
    while(aux->next != NULL)
      {
        aux = aux->next;
      }

    aux->next = create_node();

    aux->next->data = value;

    aux->next->prev = aux;
  }
}

void insert_mid(struct Node *x, struct Node *y)
{
  y->data = value;

  y->next = x;

  y->prev = x->prev;

  x->prev = y;
}

void insertion_sort(struct List *list)
{
  if(!is_empty(list))
  {
    struct Node *aux = list->head;

    while(aux->next != NULL)
    {
    
    }
  }
}

void insert_ordened(struct List *list, int value)
{
  if(!is_empty(list))
  {
    struct Node *aux = list->head;

    while((aux->data > value) && (aux->next != NULL))
    {
      aux = aux->next;
    }

    if(aux->next != NULL)
    {
      struct Node *novo = create_note();

      novo->data = value;

      insert_mid(aux, novo);
    }
    else
    {
      insert_end(list, value);
    }
  }
  else
  {
    insert_begin(list, value);
  }
}

void print_list(struct List *list)
{
  if(!is_empty(list))
  {
    struct Node *aux = list->head;

    printf("\n");
    do
    {
      printf("%d <-> ", aux->data);
      aux = aux->next;
    } while(aux != NULL);
    
    printf("\n");
  }
  else
  {
    printf("\nLista Vazia\n");
  }
}

void delete_begin(struct List *list)
{
  if(!is_empty(list))
  {
    struct Node *aux = list->head;
    list->head = aux->next;
    memset(aux, 0, sizeof(struct Node));
    free(aux);
    list->head->prev = NULL;
  }
  else
  {
    printf("\nLista Vazia\n");
  }
}

void delete_end(struct List *list)
{
  if(!is_empty(list))
  {
    struct Node *aux = list->head;
    
    if(aux->next != NULL)
    {
      while(aux->next != NULL)
      {
        aux = aux->next;
      }
      aux->prev->next = NULL;
      memset(aux, 0, sizeof(struct Node));
      free(aux);
    }
    else
    {
      memset(aux, 0, sizeof(struct Node));
      free(aux);
      list->head = NULL;
    }
  }
  else
  {
    printf("\nLista Vazia\n");
    return;
  }

}

void search(struct List *list)
{
  if(!is_empty(list))
  {
    int value = 0, count = 0;
    int i = 0;

    struct Node *aux = list->head;
    
    printf("\nEntre com o valor a ser buscado\n");
    scanf("%d", &value);

    printf("\n");
   
    do
    { 
      if(aux->data == value)
      {
        printf("%d ", i);
        count++;
      }

      aux = aux->next;
      i++;
    } while(aux != NULL);

    if(count == 0)
    {
      printf("-1");
    }
    printf("\n");
  }
  else
  {
    printf("\n-1\n");
  }
}

void delete_search(struct List *list)
{
  if(!is_empty(list))
  {
    int value = 0;

    struct Node *aux = list->head;
    
    printf("Entre com o valor a ser deletado\n");
    scanf("%d", &value);
    
    while(aux->data == value)
    {
      delete_begin(list);
      aux = list->head;
    }

    while(aux->next != NULL)
    {
      if(aux->next->data == value)
      {
        struct Node *aux2 = aux->next->next;
        memset(aux->next, 0, sizeof(struct Node));
        free(aux->next);
        aux->next = aux2;
        aux->next->prev = aux;
      }
      else
      {
        aux = aux->next;
      }
    }
  }
  else
  {
    printf("\nLista Vazia\n");
  }
}


void destroy_node(struct Node *head)
{
  if(head->next != NULL)
  {
    destroy_node(head->next);
  }
  else
  {
    return;
  }
  
  memset(head->next, 0, sizeof(struct Node));
  free(head->next);

  return;
}

void destroy_list(struct List *list)
{
  if(!is_empty(list))
  {
    destroy_node(list->head);
  }

  memset(list->head, 0, sizeof(struct Node));
  free(list->head);

  memset(list, 0, sizeof(struct Node));
  free(list);
}

int
main()
{
  struct List *list = create_list();
 
  int option = 0;

  do
  {
    printf("\n\nEscolha uma acao a fazer com a lista:\n1 - Inserir ordenado\n2 - Insertion Sort\n3 - Printar a lista\n4 - Deletar no começo\n5 - Deletar no final\n6 - Deletar por procura\n7 - Procurar valor\n8 - Sair\n\n");
    scanf("%d", &option);

    switch(option)
    {
      case 1:
      {
        int value = 0;

        printf("\nEntre com o numero a ser inserido\n");
        scanf("%d", &value);

        insert_ordened(list, value);
        break;
      }
      case 2:
      {
        insertion_sort(list);
        break;
      }
      case 3:
      {
        print_list(list);
        break;
      }
      case 4:
      {
        delete_begin(list);
        break;
      }
      case 5:
      {
        delete_end(list);
        break;
      }
      case 6:
      {
        delete_search(list);
        break;
      }
      case 7:
      {
        search(list);
        break;
      }
      case 8:
      {
        break;
      }
      default:
      {
        printf("\nOpcao Invalida!\n");
        break;
      }
    }
  } while(option != 8);  

  destroy_list(list);
  
  return(0);
}
