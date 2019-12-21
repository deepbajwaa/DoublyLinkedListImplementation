#include "doublyList.h"

int main()
{
	/*Declare a new pointer as the head of the list.*/
	struct node *head = NULL;

	append(&head, 1);
	append(&head, 2);
	append(&head, 3);
	printList(head);
	removeNode(&head, head->next);
	printList(head);
	removeNode(&head, head);
	printList(head);

	freeList(head);

	return 0;
}
