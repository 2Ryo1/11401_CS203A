# Heap
Heap is a <ins>complete binary tree that satisfies the heap-order property.</ins>
### The heap is a complete binary tree:
- Every level is completely filled, except possibly the last level.
- The last level‘s nodes are filled from left to right.

## Priority in a Heap
Priority = Importance or Urgency

| Example | Priority Interpretation |
|---|---|
| Emergency patient with triage level 5 | High priority |
| OS process with small remaining time | High priority (shortest job first) |
| Network packet with high QoS level | High priority |


## Heap-Order Ordering
Heaps are commonly used to implement <ins>priority queues and for heap sort algorithms.</ins>
### Max heap
- Each parent node’s key is always greater than or equal to their children **(parent ≥ children)**.
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
- Each parent node’s key is always less than or equal to their children **(parent ≤ children)**.
- The minimum element is always at the root.

```text
Array representation: [10, 15, 30, 40, 50]
         10
        /  \
      15    30
     /  \
   40    50
```

## Time Complexity
| Operation | Time Complexity | Why |
|---|---|---|
| **peek-max / peek-min** | O(1) | Root stored at index 0 |
| **insert (sift-up)** | O(log n) | Moves from leaf → root along tree height |
| **extract-max / extract-min (sift-down)** | O(log n)| Moves from root → leaf along tree height |
| **increase-key (max-heap)** | O(log n) | Uses sift-up |
| **decrease-key (max-heap)** | O(log n) | Uses sift-down |
| **build-heap (bottom-up heapify)** | O(n)| Floyd’s algorithm (more efficient than n insertions) |
| **heapsort** | O(n log n) | n extract-max operations |

