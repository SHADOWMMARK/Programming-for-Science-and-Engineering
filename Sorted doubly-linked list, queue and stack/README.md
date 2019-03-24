# Sorted doubly-linked list, queue and stack

We will develop three common linked data structures, a sorted doubly-linked list, a simple queue, and a simple stack. 

## Introduction for some basic classes
- The primary data structure will be a doubly-linked list that is always maintained in a sorted order, along with a simple node class that will be able to be used by the sorted list. Keep in mind that, while the list will fully utilize the node class, the node class really shouldn’t know anything about a list – it is just a node, and it might be used in other data structures (like the others being developed for this project!).

- LinkedNodeClass: this class will be used to store individual nodes of a doubly-linked data structure. This class should end up being quite short and simple – no significant complexity is needed, desired, or allowed.
 
- SortedListClass: this class will be used to store a doubly-linked list in an always-sorted way, such that the user does not specify where in the list a value should be inserted, but rather the new value is inserted in the correct place to maintain a sorted order.

## Additional Data Structures

After implementing and fully testing the above classes, move on to implementing these additional data structures, which should be able to be completed very quickly due to their restricted functionality.

- FIFOQueueClass: this will be a “first-in-first-out queue” data structure. You should be able to use the LinkedNodeClass you developed above to very quickly develop and test this data structure. If written correctly, this class should be very short and simple, and should not require a significant chunk of the time to implement. Since the FIFO queue has such restricted functionality, it is quite straight forward to develop, especially since the bidirectional LinkedNodeClass is already available and can be used to make this a very short and simple data structure to implement. This class will be used to store a simple first-in-first-out queue data structure.

- LIFOStackClass: this will be a “last-in-first-out stack” data structure. You should be able to use the LinkedNodeClass you developed above to very quickly develop and test this data structure. If written correctly, this class should be very short and simple, and should not require a significant chunk of the time to implement. Since the LIFO stack has such restricted functionality, it is quite straight forward to develop, especially since the bidirectional LinkedNodeClass is already available and can be used to make this a very short and simple data structure to implement. This class will be used to store a simple last-in-first-out stack data structure. 
