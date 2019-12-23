#include "doublyList.h"

int main()
{
	/*Declare a new pointer as the head of the list.*/
	struct node *head = NULL;
	struct node *prev;
	struct node *temp;

	/*
	struct node *frontHalf;
	struct node *backHalf;
	*/

	append(&head, 2);
	append(&head, 2);
	append(&head, 1);
	append(&head, 7);
	append(&head, 5);
	append(&head, 7);
	append(&head, 10);
	append(&head, 10);
	append(&head, 10);
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

	/*
	printf("Append\n");
	prepend(&head, 4);
	prepend(&head, 5);
	prepend(&head, 6);
	printList(head);
	*/

	/*
	printf("Pop Test\n");
	struct node *returnNode1 = pop(&head);
	struct node *returnNode2 = pop(&head);
	struct node *returnNode3 = pop(&head);
	struct node *returnNode4 = pop(&head);
	struct node *returnNode5 = pop(&head);

	printf("Data from first pop: %d\n", returnNode1->data);
	printf("Data from second pop: %d\n", returnNode2->data);
	printf("Data from third pop: %d\n", returnNode3->data);

	if(returnNode4 == NULL)
	{
		printf("The fourth pop returned a NULL node.\n");
	}

	if(returnNode5 == NULL)
	{
		printf("The fifth pop returned a NULL node.\n");
	}

	printf("Print forewards: \n");
	printList(head);
	printf("Print backwards: \n");
	printListReverse(head);

	free(returnNode1);
	free(returnNode2);
	free(returnNode3);

	*/

	/*
	printf("Push onto stack\n");
	pushStack(&head, 12);
	pushStack(&head, 24);

	printList(head);

	printf("Push onto Queue\n");
	pushQueue(&head, 44);
	pushQueue(&head, 88);

	printList(head);
	*/

	/*
	split(head, &frontHalf, &backHalf);
	printf("The front half: \n");
	printList(frontHalf);
	printf("The front half (Backwards): \n");
	printListReverse(frontHalf);
	printf("The back half: \n");
	printList(backHalf);
	printf("The back half (Backwards): \n");
	printListReverse(backHalf);


	printf("The original list (should be list in half): \n");
	printList(head);

	freeList(head);
	freeList(backHalf);
	*/

	mergeSort(&head);
	printf("Sorted List\n");
	printList(head);

	printf("List Backwards\n");
	printListReverse(head);

	/*
	prev = head->next->next->next->next;
	insertAfter(prev, 8);

	printf("After insert\n");
	printList(head);

	printf("List Backwards\n");
	printListReverse(head);
	*/

	/*
	prev = head->next->next;
	if(prev == NULL)
  {
    printf("Invalid Node!\n");
  }
	removeAfter(prev);

	printf("After remove\n");
	printList(head);

	printf("List Backwards\n");
	printListReverse(head);

	printf("The list has %d elements.\n", length(head));
	*/

	/*
	temp = search(head, 50);

	if(temp != NULL)
	{
		printf("The value %d was found in the list.\n", temp->data);
	}
	else
	{
		printf("The value was not found in the list.\n");
	}*/

	/*
	temp = searchList(head, 7);

	printf("Search List:\n");
	printList(temp);
	printf("Search List backwards\n");
	printListReverse(temp);
	freeList(temp);
	*/

	/*
	temp = copyList(NULL, head->next->next);

	printf("Copied List:\n");
	printList(temp);
	printf("Search List backwards:\n");
	printListReverse(temp);
	freeList(temp);
	*/

	removeRepeats(head);
	printf("Removed Repeats List:\n");
	printList(head);
	printf("Removed Repeats List backwards:\n");
	printListReverse(head);

	freeList(head);

	return 0;
}
