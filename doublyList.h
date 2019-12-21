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
void append(struct node **head, int data);
