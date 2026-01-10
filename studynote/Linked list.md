# Linked list
A linear data structure where elements (**nodes**) are stored in sequence, but not in contiguous memory locations. Each node has data and a reference (**pointer**) to the next node. **Linked lists can be changed during runtime**.
```text
Singly Linked List (basic form)
Head
  ↓
 _____  _____  _____
 | 2 |→ | 5 |→ | 3 | → NULL
 ￣￣￣  ￣￣   ￣￣￣
                 ↑
                Tail
Example:Start at head (2), then follow the next pointer to reach 5
```
## Operations
- **LinkedList Create():** <ins>return an empty linked list</ins>
- **Boolean IsEmpty(L):** <ins>return true if L has no nodes</ins> <ins>else return false</ins>
- **Integer Length(L):** <ins>return the number of nodes in L</ins>
- **LinkedList Insert(L, p, x):** <ins>if position p is valid, insert item x into list L at position p shift subsequent nodes if necessary return updated list</ins> <ins>else return error</ins>
- **LinkedList Delete(L, p):** <ins>if position p is valid, remove the node at position p return updated list</ins> <ins>else return error</ins>
- **LinkedList Update(L, p, x):** <ins>if position p is valid, replace the item at position p with x return updated list</ins> <ins>else return error</ins>
- **Position Search(L, x):** <ins>return position of first occurrence of x in L</ins> <ins>else return error</ins>


## Singly Linked List
Singly Linked List is a fundamental type of linked list in which each node points only to the next node, allowing traversal in one direction.
```C
//C
struct SNode {
  int data;
  struct SNode *next;
};

```

## Doubly Linked List
Doubly Linked List is a type of linked list in which each node contains two pointers. One pointing to the next node and one pointing to the previous node.
```text
       Head
         ↓
       _____   _____   _____
NULL ← | 2 | ⇄ | 5 | ⇄ | 3 | → NULL
       ￣￣￣   ￣￣    ￣￣￣  
                         ↑
                        Tail
←: Next
→: Prev
```
```text
//C
struct DNode {
  int data;
  struct DNode *prev;
  struct DNode *next;
};

```

## Circular Linked List
Circular Linked List is a variation of a linked list in which the last node points back to the first node, **forming a closed loop**.
This allows continuous traversal **without reaching a NULL pointer**.
- It may be singly-linked or doubly-linked.
- It dosen't have tail and NULL.
```text
Circular singly Linked List
       Head
         ↓
       _____   _____   _____
       | 2 | ⇄ | 5 | ⇄ | 3 | 
       ￣￣￣   ￣￣    ￣￣￣ 
         ↑______________|
```

```C
//C
class CNode {
public:
  int data;
  CNode* next;
  CNode(int val) : data(val), next(nullptr) {}
};

```

## MoveTo()
The MoveTo() function relocates a node (target) to a new position after the node specified by destination within a **singly linked list**. 
This requires pointer manipulation, **not data swapping**.

<ins>Doubly linked list or circular linked list</ins> can make the MoveTo operation more efficient since each 
node has direct access to its predecessor.
- prevTarget : Stores the node before the target to facilitate detachment
- destination: Marks the node after which the target will be reinserted
### Operation
- **Step1.**
```text
Find the node before the target (prevTarget)
Traverse the list until prevTarget->next == target.
```
- **Step2.**
```text
Detach the target node 
Skip it by re-linking: prevTarget->next = target->next
```
- **Step3.**
```text
Insert the target node after destination 
Link target into its new position: target->next = destination->next
destination->next = target
```
- **(Edge cases+Step4.)**
```text
If the target node is the head → use a dummy node before the head. 
If the target is next to the destination → handle pointer adjustment carefully. 
```


## Complexity Analysis
| Operation | Complexity | Notes |
|---|---|---|
| **Access** | **O(n)** | No direct index access; must traverse from head |
| **Update** | **O(n)<sub>(1)</sub>** | Requires locating the target node |
| **Insert(front)** | **O(n)** | Insert directly at head |
| **Insert(middle)** | **O(1)** | Position must be located by traversal |
| **Insert(end)** | **O(n)<sub>(2)</sub>O(1)<sub>(3)</sub>** | Depends on whether the last node is directly reachable |
| **Delete** | **O(1)<sub>(4)</sub>O(n)** | Target node must be found before removal |
| **Traverse** | **O(n)** | Each node must be visited sequentially. |
| **Search** | **O(n)** | Requires linear traversal to find the target node. |

- (1): If node pointer is known, Update is O(1)
- (2): O(n) unless tail pointer is used
- (3): With tail pointer and singly linked list
- (4): If node pointer is known, deletion is O(1)
## Insert(middle) Array vs Linked list
Give integers 2,3,4
Insert 5 between 2 and 3.
### Array
- When size is full.
```text
[2,3,4]
   ↓
recreate and redeclare
   ↓
[2,5,3,4]
```
- When size has a empty.
```text
[2,3,4, NULL]
    ↓
3,4 move to index 2,3.(e.g. Array[1] = 3 → Array[2] = 3 )
    ↓
[2,5,3,4]
```
### Linked List
https://github.com/2Ryo1/11401_CS203A/blob/main/studynote/Array.md#selection-sort
```text
[2]→[3]→[4]
   ↓
set [2]next→[5] and [5]next→[3]
   ↓
[2]→[5]→[3]→[4]
```
## Selection Sort(Linked list)
```C
#include <stdio.h>
#include <stdlib.h>
//C
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Selection Sort
void selectionSort(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* minNode = current;
        Node* next = current->next;
        while (next != NULL) {
            if (next->data < minNode->data) {
                minNode = next;
            }
            next = next->next;
        }
        int temp = current->data;
        current->data = minNode->data;
        minNode->data = temp;

        current = current->next;
    }
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    append(&head, 64);
    append(&head, 25);
    append(&head, 12);
    append(&head, 22);
    append(&head, 11);

    printf("Before sorting:\n");
    printList(head);

    selectionSort(head);

    printf("After sorting:\n");
    printList(head);

    return 0;
}
```
<ins>by Copilot</ins>
```C
Before sorting:
64 -> 25 -> 12 -> 22 -> 11 -> NULL
After sorting:
11 -> 12 -> 22 -> 25 -> 64 -> NULL
```
image:
```text
   Head                      minNode    
     ↓                          ↓
   [64] → [25] → [12] → [22] → [11] → NULL
     ↑
 current――――――――――――――――――――――→

```
### Bonus
https://github.com/2Ryo1/-11401_CS203A-Project
