#include <stdio.h>
#include <stdlib.h>


/*Node structure definition*/
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};

/*Functions*/
void printList(struct node *head);
void printListReverse(struct node *head);
void freeList(struct node *head);
void append(struct node **head, int data);
void prepend(struct node **head, int data);
void removeNode(struct node **head, struct node *removeNode);
struct node *pop(struct node **head);
void pushQueue(struct node **head, int data);
void pushStack(struct node **head, int data);
void mergeSort(struct node **headRef);
void split(struct node *list, struct node **frontHalf, struct node **backHalf);
