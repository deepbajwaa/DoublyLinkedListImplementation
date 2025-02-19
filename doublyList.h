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
struct node *sortNode(struct node *a, struct node *b);
void insertAfter(struct node *prevNode, int data);
void removeAfter(struct node *prevNode);
int length(struct node *head);
struct node *search(struct node *head, int target);
struct node *searchList(struct node *head, int target);
struct node *copyList(struct node *start, struct node *end);
void removeRepeats(struct node *list);
