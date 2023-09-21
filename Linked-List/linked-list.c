#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next; 
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

void insert_begin(struct List *list)
{
  struct Node *aux = create_node(); 

  if(aux != NULL)
  {
    printf("\nEntre com o valor a ser inserido\n");
    scanf("%d", &aux->data);

    aux->next = list->head;
    list->head = aux;
  }
  else
  {
    free(aux);
  }
}

void insert_end(struct List *list)
{ 
  if(is_empty(list))
  {
    list->head = create_node();

    struct Node *aux = list->head;
    printf("\nEntre com o valor a ser inserido\n");
    scanf("%d", &aux->data);
  }
  else
  {
    struct Node *aux = list->head;
    while(aux->next != NULL)
      {
        aux = aux->next;
      }

    aux->next = create_node();

    if(aux->next != NULL)
      {
        aux = aux->next;

        printf("\nEntre com o valor a ser inserido\n");
        scanf("%d", &aux->data);

        aux->next = NULL;
      }
    else
    {
      printf("\nError Malloc\n");
    }
  }
}

void print_list(struct List *list)
{
  if(!is_empty(list))
  {
    struct Node *aux = list->head;

    do
    {
      printf("%d -> ", aux->data);
      aux = aux->next;
    } while(aux != NULL);
    
    printf("\n");
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
  
  head->next = NULL;
  free(head->next);

  return;
}

void destroy_list(struct List *list)
{
  if(!is_empty(list))
  {
    destroy_node(list->head);
  }

  list->head = NULL;
  free(list->head);

  list = NULL;
  free(list);
}

int
main()
{
  struct List *list = create_list();
 
  int option;

  do
  {
    printf("\n\nEscolha uma acao a fazer com a lista:\n1 - Inserir no comeco\n2 - Inserir no final\n3 - Printar a lista\n4 - Sair\n\n");
    scanf("%d", &option);

    switch(option)
    {
      case 1:
      {
        insert_begin(list);
        break;
      }
      case 2:
      {
        insert_end(list);
        break;
      }
      case 3:
      {
        print_list(list);
        break;
      }
      case 4:
      {
        break;
      }
      default:
      {
        printf("\nOpcao Invalida!\n");
        break;
      }
    }
  } while(option != 4);  

  destroy_list(list);
  
  return(0);
}
