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

  /*If the head doesn't exist then exit*/
  if(head == NULL)
  {
    return;
  }

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
  /*Get the popped node*/
  struct node *poppedNode = *head;

  if(*head != NULL)
  {
    *head = (*head)->next;
  }

  /*Return the head*/
  return poppedNode;
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

void mergeSort(struct node **headRef)
{
  /*Declare and initialize pointers*/
  struct node *head = *headRef;
  struct node *frontHalf;
  struct node *backHalf;

  /*Check the base case, if the list consists of only 0 or 1 nodes*/
  if(*headRef == NULL || (*headRef)->next == NULL)
  {
    return;
  }

  /*Split the list into 2 halfs*/
  split(head, &frontHalf, &backHalf);

  /*Keep breaking the list into halfs to sort the list*/
  mergeSort(&frontHalf);
  mergeSort(&backHalf);

  /*Merge the two lists together*/
  *headRef = sortNode(frontHalf, backHalf);
}

void split(struct node *list, struct node **frontHalf, struct node **backHalf)
{
  /*Declare and initialize pointers*/
  struct node *fast = list->next;
  struct node *slow = list;

  /*Fast and Slow are two pointers that are going to traverse through the list, where fast will be traversing
  the list twice as fast as the slow pointer.*/
  while(fast != NULL)
  {
    fast = fast->next;

    if(fast != NULL)
    {
      slow = slow->next;
      fast = fast->next;
    }
  }

  /*Since slow ends up before the midpoint the backHalf starts from slow's next*/
  /*slow->prev = NULL;*/
  *frontHalf = list;
  *backHalf = slow->next;
  (*backHalf)->prev = NULL;
  slow->next = NULL;
}

struct node *sortNode(struct node *a, struct node *b)
{
  /*Create a variable for the comparison needed to be made
  struct node *list = NULL;*/

  /*Base case: if either a or b are null*/
  if(a == NULL)
  {
    return b;
  }
  else if(b == NULL)
  {
    return a;
  }

  /*Check to see which node's data value is smaller*/
  if(a->data <= b->data)
  {
    /*Sort the remaining nodes in both lists*/
    a->next = sortNode(a->next, b);
    a->next->prev = a;
    a->prev = NULL;
    return a;

  }
  else
  {
    b->next = sortNode(a, b->next);
    b->next->prev = b;
    b->prev = NULL;
    return b;
  }
}

void insertAfter(struct node *prevNode, int data)
{
  /*Declare variables*/
  struct node *newNode;

  /*Make sure that the node passed to the function exists*/
  if(prevNode == NULL)
  {
    printf("Invalid Node!\n");
    return;
  }

  /*Allocate a new node & insert data*/
  newNode = malloc(sizeof(struct node));
  newNode->data = data;

  /*Reassign the prevNode and the newNode's pointers accordingly*/
  newNode->next = prevNode->next;
  newNode->prev = prevNode;

  /*Reassign prevNode and the next node*/
  prevNode->next = newNode;

  /*If the user wants to add after the last node in the list*/
  if(newNode->next != NULL)
  {
    newNode->next->prev = newNode;
  }

}

void removeAfter(struct node *prevNode)
{
  /*Declare pointers and variables*/
  struct node *temp;
  struct node *sucNode;

  /*Check to see if valid node was passed*/
  if(prevNode == NULL || prevNode->next == NULL)
  {
    printf("Invalid Node!\n");
    return;
  }

  /*Initialize pointers*/
  temp = prevNode->next;
  sucNode = temp->next;

  /*Reassign pointers*/
  prevNode->next = sucNode;

  if(sucNode != NULL)
  {
    sucNode->prev = prevNode;
  }

  /*Free the temp pointer*/
  free(temp);
}

int length(struct node *head)
{
  /*Declare and initialize variables*/
  int numOfElements = 0;

  /*traverse through the list to get the length*/
  while(head)
  {
    numOfElements++;
    head = head->next;
  }

  /*Return length*/
  return numOfElements;
}
