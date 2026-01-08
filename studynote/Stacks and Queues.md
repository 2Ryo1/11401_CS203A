# Stack
A linear data structure that follows the **Last-In-First-Out (LIFO)** principle. 
- LIFO: Elements are added and removed from the same end, called the “top”.
- (Array: top → integer index of the current top element (initially -1))
- (Linked list: Node* top → pointer to the head node (stack top))
## operations
### push: add element(from end)
- Array: check top < MAX_SIZE-1, then stack[++top] = value
- Linked list: create new node, set newNode->next = top
### pop:  remove element(from end)
- Array: check top >= 0, then value = stack[top--]
- Linked check if top != NULL, set top = top->next
# Queue
A linear data structure that follows the **First-In-First-Out (FIFO)** principle. 
- FIFO: Elements are added at one end (rear) and removed from the other end (front).
- (Array: rear → index of the last element)
- (Array: front → index of the first element)
- (Linked list: Node* rear → pointer to last node)
- (Linked list: Node* front → pointer to first node)
