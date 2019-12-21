#include "doublyList.h"

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
  if(*head)
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
