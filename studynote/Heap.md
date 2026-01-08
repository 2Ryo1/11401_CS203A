# Heap
Heap is a complete binary tree that satisfies the heap-order property.
### The heap is a complete binary tree:
- Every level is completely filled, except possibly the last level.
- The last level‘s nodes are filled from left to right.

## Heap-Order Ordering
Heaps are commonly used to implement priority queues and for heap sort algorithms.
### Max heap
- Each parent node’s key is always greater than or equal to their children (parent ≥ children).
- The maximum element is always at the root.
```text
Array representation: [50, 30, 40, 10, 20]
         50
        /  \
      30    40
     /  \
   10    20
```
**Insertion (sift-up)**:
- **Step1.** Insert the new node at the leftmost empty position on the last level (to maintain the complete tree shape).
- **Step2.** Compare the new node with its parent; if the child is larger, swap them.
- **Step3.** Repeat Step 2 until the heap-order property is satisfied or the node reaches the root.

**Extract Max (sift-down)**:
- **Step1.** Remove and return the root (maximum element).
- **Step2.** Move the last leaf to the root position to maintain the complete binary tree property.
- **Step3.** Compare the new root with its larger child; if the child is larger, swap them.
- **Step4.** Repeat Step 3 until the heap-order property is satisfied or the node reaches a leaf.


### Min heap
- Each parent node’s key is always less than or equal to their children (parent ≤ children).
- The minimum element is always at the root.
  ```text
Array representation: [10, 15, 30, 40, 50]
         10
        /  \
      15    30
     /  \
   40    50
```

  
