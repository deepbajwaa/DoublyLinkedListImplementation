#include "doublyList.h"

int main()
{
	/*Declare a new pointer as the head of the list.*/
	struct node *head = NULL;

	append(&head, 1);
	append(&head, 2);
	printList(head);

	return 0;
}
