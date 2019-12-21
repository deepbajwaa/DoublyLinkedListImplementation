#include "doublyList.h"


void printList(struct node *head)
{
  /*traverse through the list whilst printing out the data*/
  while(head)
  {
    printf("Data: %d\n", head->data);
    head = head->next;
  }
}

void printListReverse(struct node *head)
{
  /*Declare a single pointer for the last node in the list*/
  struct node *last;

  /*traverse through the list to get the last node in the list.*/
  while(head)
  {
    last = head;
    head = head->next;
  }

  /*Traverse list backwards whilst printing out the data*/
  while(last)
  {
    printf("Data: %d\n", last->data);
    last = last->prev;
  }

}


void freeList(struct node *head)
{
  /*Create a temporary variable*/
  struct node *temp;

  /*Traverse through the list and free memory*/
  while(head)
  {
    temp = head;
    head = head->next;
    free(temp);
  }
}
void append(struct node **head, int data)
{
  /*Declare a single pointer in order to traverse through the list*/
  struct node *traverse = *head;

  /*Initialize a new node*/
  struct node *newNode = malloc(sizeof(struct node));

  /*Initialize with data*/
  newNode->data = data;
  newNode->next = NULL;
  newNode->prev = NULL;

  /*Check to see if head exists, if it does then append the new node as the head of the list*/
  if(*head == NULL)
  {
    *head = newNode;
    return;
  }
  else
  {
    /*Move to the end of the list*/
    while(traverse->next != NULL)
    {
      traverse = traverse->next;
    }

    /*Append the new node to the end of the list*/
    traverse->next = newNode;
    newNode->prev = traverse;
  }
}

void prepend(struct node **head, int data)
{
  /*Allocate a new node*/
  struct node *newNode = malloc(sizeof(struct node));

  /*Initialize with data*/
  newNode->data = data;

  /*Point the newNode to the current head, and point the newNode's prev to NULL*/
  newNode->next = *head;
  newNode->prev = NULL;

  /*If the head exits then point its prev to the newNode*/
  if(*head == NULL)
  {
    (*head)->prev = newNode;
  }

  /*Change the head to the newNode*/
  *head = newNode;
}

void removeNode(struct node **head, struct node *removeNode)
{
  /*Declare previous and successive nodees*/
  struct node *sucNode = removeNode->next;
  struct node *prevNode = removeNode->prev;

  /*If there is no list that exits then return*/
  if(*head == NULL || removeNode == NULL)
  {
    return;
  }

  /*If the head is to be removed.*/
  if(*head == removeNode)
  {
    *head = sucNode;
  }

  /*If the node to be removed is not the last node*/
  if(removeNode->next != NULL)
  {
    sucNode->prev = prevNode;
  }

  /*If the node to be removed is not the first node*/
  if(removeNode->prev != NULL)
  {
    prevNode->next = sucNode;
  }

  /*Free the node to be removed*/
  free(removeNode);
  return;

}

struct node *pop(struct node **head)
{
  /*Remove the head*/
  removeNode(head, *head);
  /*Return the head*/
  return *head;
}


void pushQueue(struct node **head, int data)
{
  /*Add to the end of the Queue*/
  append(head, data);
}

void pushStack(struct node **head, int data)
{
  /*Add to the top of the stack*/
  prepend(head, data);
}
