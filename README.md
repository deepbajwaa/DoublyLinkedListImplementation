# DoublyLinkedListImplementation
I wanted to practice implementing a double linked list, and wanted to learn about how they work to make me a better programmer.
This library was designed to make the implementation of a doubly linked list easier. If you want to divert from this base library go ahead by making your desired changes in the doublyList.h and .c files respectively. 

To Run:
1. Clone the repository and copy paste the doublyList.h and doublyList.c files into your project.
2. You can now either use your own makefile, or the makefile to compile together the .c file with your main.
3. Run accordingly to how you have your makefile structure setup.

List of Functions(with descriptions):

1. printList - This will print the list in order.

  -@param head this is a pointer to the start of the list.
  
2. printListReverse - This will print the list backwards.

  -@param head this is a pointer to the start of the list.
  
3. freeList - This will free the memory allocated by the list.

  -@param head this is a pointer to the start of the list.
  
4. append - This will add a node to the end of the list.

  -@param head the memory address of the head of the list should be passed to this function.
  
   -@param data this is any integer you want to add to the list.
   
5. prepend - This will add a node to the beggining of the list.

  -@param head the memory address of the head of the list should be passed to this function.
  
   -@param data this is any integer you want to add to the list.
   
6. removeNode - This function is used to remove a specific node.

  -@param head the memory address of the head of the list should be passed to this function.
  
  -@param removeNode is a pointer to the specified node.
  
7. pop - This is used to pop a node off the list.

  -@param head the memory address of the head of the list should be passed to this function.
  
  -@returns the popped node.
  
8. pushQueue - This function will push a node onto the list treating the list as a Queue.

  -@param head the memory address of the head of the list should be passed to this function.
  
  -@param data this is any integer you want to add to the list.
  
9. pushStack - This function will push a node onto the list treating the list as a Stack.
  
  -@param head the memory address of the head of the list should be passed to this function.
  
  -@param data this is any integer you want to add to the list
  
10. mergeSort - This function sorts the list using the mergesort algorithm.

  -@param head the memory address of the head of the list should be passed to this function.
  
11. split - This function splits a list into half.

  -@param list is a pointer to the head of the list.
  
  -@param frontHalf is the memory address of the pointer that points to the head of the front half of the list.
  
  -@param backHalf is the memory address of the pointer that points to the head of the back half of the list.
  
12. sortNode - This function is used to sort two halfs of a list into one sorted list.

  -@param a is a pointer to the first list.
  
  -@param b is a pointer to the second list.
  
  -@returns a pointer to the head of the list.
  
13. insertAfter - This function is used to insert a node after a specified node.

  -@param prevNode is a pointer to the node that the new node is to be inserted after.
  
  -@param data is an integer you want to add to the list.
  
14. removeAfter - This function is used to remove a node after a specified node.

  -@param prevNode is a pointer to the node that comes before the node that is to be removed.
  
15. length - This function returns the length of the list (# of nodes in the list).
  -@param head the memory address of the head of the list should be passed to this function.
  
16. search - This function searches a list for a certain 
17. searchList -
18. copyList - 
19. removeRepeats - 
  
   -@param data this is the node you want to remove from the list.
