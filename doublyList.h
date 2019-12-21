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
void freeList(struct node *head);
void append(struct node **head, int data);
void removeNode(struct node **head, struct node *removeNode);
