# Linked list
A linear data structure where elements (nodes) are stored in sequence, but not in contiguous memory locations. Each node has data and a reference (pointer) to the next node. Linked lists can be changed during runtime.
```text
Singly Linked List (basic form)
Head
  ↓
 -----  -----  -----
 | 2 |→ | 5 |→ | 3 | → NULL
 -----  -----  -----
                 ↑
                Tail
Example:Start at head (2), then follow the next pointer to reach 5
```
## Singly Linked List
Singly Linked List is a fundamental type of linked list in which each node points only to the next node, allowing traversal in one direction.
## Doubly Linked List
Doubly Linked List is a type of linked list in which each node contains two pointers. One pointing to the next node and one pointing to the previous node.
```text
       Head
         ↓
       -----  -----  -----
NULL ← | 2 |⇄ | 5 |⇄ | 3 | → NULL
       -----  -----  -----
                       ↑
                     Tail
←: Next
→: Prev
```
