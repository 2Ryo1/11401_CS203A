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
## Circular Linked List
Circular Linked List is a variation of a linked list in which the last node points back to the first node, forming a closed loop.
This allows continuous traversal without reaching a NULL pointer.
- It may be singly-linked or doubly-linked.
- It dosen't have tail and NULL.
```text
Circular singly Linked List
       Head
         ↓
       -----  -----  -----
       | 2 |→ | 5 |→ | 3 | 
       -----  -----  -----
        ↑______________|
```
## Complexity Analysis
| Operation | Complexity | Notes |
|---|---|---|
| Access | **O(n)** | No direct index access; must traverse from head |
| Update | **(1)O[n]** | Requires locating the target node |
| Insert(front) | **O(n)** | Insert directly at head |
| Insert(middle) | **O(1)** | Position must be located by traversal |
| Insert(end) | **[(2)O(n)][(3)O(1)]** | Depends on whether the last node is directly reachable |
| Delete | **O(n)[(4)O(1)]** | Target node must be found before removal |
| Traverse | **O(n)** | Each node must be visited sequentially. |
| Search | **O(n)** | Requires linear traversal to find the target node. |

- (1): If node pointer is known, Update is O(1)
- (2): O(n) unless tail pointer is used
- (3): With tail pointer and singly linked list
- (4): If node pointer is known, deletion is O(1)
## Insert(middle)
Give integers 2,3,4
Insert 5 between 2 and 3.
# Array
If size is full.
```text
[2,3,4]
   ↓
recreate and redeclare
   ↓
[2,5,3,4]
```
If size has a empty.
```text
[2,3,4, NULL]
    ↓
3,4 move to index 2,3.(e.g.Array[1] =3 → Array[2] =3)
    ↓
[2,5,3,4]
```
# Linked List
```text
[2]→[3]→[4]
   ↓
set [2]next→[5]and [5]next→[3]
   ↓
[2]→[5]→[3]→[4]
```
