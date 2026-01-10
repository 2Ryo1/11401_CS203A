# Stack
A linear data structure that follows the **Last-In-First-Out (LIFO)** principle. 
- **LIFO:** Elements are added and removed from the same end, called the **top**.
- (Array: top → integer index of the current top element (initially -1))
- (Linked list: Node* top → pointer to the head node (stack top))
## operations
- **Stack CreateS(maxStackSize):** <ins>create an empty stack whose maximum size is maxStackSize</ins>
- **Boolean IsFull(stack, maxStackSize):** <ins>if (number of elements in stack == maxStackSize) return TRUE</ins> <ins>else return FALSE</ins>
- **Boolean IsEmpty(stack):** <ins>if (stack == CreateS(maxStackSize)) return TRUE</ins> <ins>else return FALSE</ins>
### push: add element(from end)
- **Array:** check top < MAX_SIZE-1, then stack[++top] = value
- **Linked list:** create new node, set newNode->next = top
### pop: remove element(from end)
- **Array:** check top >= 0, then value = stack[top--]
- **Linked list:** check if top != NULL, set top = top->next
## image
```text
Last-In (push)   First-Out(pop)
         ____   __=→
             ↓ |  
            L 2 」
            L 4 」
            L 3 」
            L 5 」
Last-In: 2
First-Out: 2
```
# Queue
A linear data structure that follows the **First-In-First-Out (FIFO)** principle. 
- **FIFO:** Elements are added at one end (rear) and removed from the other end (front).
- (Array: rear → index of the last element)
- (Array: front → index of the first element)
- (Linked list: Node* rear → pointer to last node)
- (Linked list: Node* front → pointer to first node)
## operations
- Queue CreateQ(j, list): <ins>create an empty queue whose maximum size is maxQueueSize</ins>
- Boolean IsFullQ(queue, maxQueueSize): <ins>if (number of elements in queue == maxQueueSize) return TRUE</ins> <ins>else return FALSE</ins>
- Boolean IsEmptyQ(queue): <ins>if (stack == CreateS(maxQueueSize)) return TRUE</ins> <ins>else return FALSE</ins>
### enqueue: add element(from front)
- **Array:** rear = (rear + 1) % MAX_SIZE; queue[rear] = value
- **Linked list:** create new node, set rear->next = newNode, update rear = newNode
### dequeue: remove element(from end)
- **Array:** front = (front + 1) % MAX_SIZE; value = queue[front]
- **Linked list:** check if front != NULL, set front = front->next
## image
```text
          First-In(enqueue)
            ↓
  [2][4][3][5]
   ↓
 First-out(dequeue)
First-In: 5
First-Out: 2
```
## Array vs Linked List Implementation
| Structure | Array Implementation | Linked List Implementation |
|---|---|---|
| **Stack** | top, MAX_SIZE, array storage | top pointer |
| **Queue** | front, rear, MAX_SIZE, array storage, sometimes count  | front and rear pointers |
| **Memory Management** | Pre-allocated, may waste unused space; resizing cost | Dynamic allocation per node, pointer overhead |
| **Overflow/Underflow** | Must check indices; circular logic for queue | Only “overflow” if heap memory is exhausted |
| **Performance** | <ins>O(1)</ins> push/pop/enqueue/dequeue (except resizing) | <ins>O(1) push/pop/enqueue/dequeue</ins> |


## Comparison of Stacks and Queues 
| Feature | Stack | Queue |
|---|---|---|
| **Direction of I/O**  | Both operations happen at the **top**  | Input at **rear**, output at **front**|
| **Array Implementation** | Easy to implement with a fixed-size array, and **overflow** if capacity exceeded| Usually implemented as **circular array** to reuse space |
| **Linked List Implementation** |  No fixed size (dynamic memory) | Needs pointers for both front and rear |
| **Memory Management**  | Array may waste unused slots if not full  | Linked list uses extra memory for pointers |
| **Performance(Array)** | **O(1)** push/pop (if no resize) | **O(1)** enqueue/dequeue with circular buffer |
| **Performance(Linked list)** | **O(1)** push/pop at head | **O(1)** enqueue (at tail) and dequeue (at head) |
| **Overflow Handling** | Fixed-size array may overflow Dynamic array requires resizing | Circular array may overflow Linked list has no overflow unless memory exhausted |
| **Use Cases** |<ins>Undo functionality, function calls, expression evaluation</ins> |<ins>ask scheduling, resource sharing, buffering</ins> (e.g., I/O queues, printer queues)|
