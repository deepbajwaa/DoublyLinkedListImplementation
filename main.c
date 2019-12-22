#include "doublyList.h"

int main()
{
	/*Declare a new pointer as the head of the list.*/
	struct node *head = NULL;

	append(&head, 1);
	append(&head, 2);
	append(&head, 3);
	printf("Print forewards: \n");
	printList(head);
	printf("Print backwards: \n");
	printListReverse(head);

	/*
	printf("Removing: \n");
	removeNode(&head, head->next);
	printList(head);
	removeNode(&head, head);
	printList(head);
	*/

	printf("Append\n");
	prepend(&head, 4);
	prepend(&head, 5);
	prepend(&head, 6);
	printList(head);


	printf("Pop Test\n");
	struct node *returnNode1 = pop(&head);
	struct node *returnNode2 = pop(&head);
	struct node *returnNode3 = pop(&head);

	printf("Data from first pop: %d\n", returnNode1->data);
	printf("Data from second pop: %d\n", returnNode2->data);
	printf("Data from third pop: %d\n", returnNode3->data);


	printf("Print forewards: \n");
	printList(head);
	printf("Print backwards: \n");
	printListReverse(head);

	freeList(head);
	free(returnNode1);
	free(returnNode2);
	free(returnNode3);

	return 0;
}
