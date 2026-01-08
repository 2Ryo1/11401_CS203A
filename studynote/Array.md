# Array
A collection of elements stored in contiguous memory locations.
Each element can be accessed directly using an index.
Array's size is fixed. if the size needs to change, need to recreate array.
```text
Array
   -----------------
   | 2 | 1 | 5 | 3 |
   -----------------
      ↑  ↑   ↑   ↑ 
index:0, 1,  2,  3
Array[0]=2
```
## Size
### Static array
- Length is fixed.
- The number of elements is determined at compile time.
### Dynamic array
- Length can be changed.
- The number of elements can be allocated or resized at runtime.
- When using malloc or realloc to increase the array size, most to free the allocated memory, after use to avoid memory leaks.
## Complexity Analysis
| Aspect | Array | Linked List |
|---|---|---|
| Memory layout | Contiguous | Non-contiguous (nodes) |
| Random access | **O(1)** index access | **O(n)** traversal |
| Insert/Delete (middle) | **O(n)** due to shifting | **O(1)** if you already have the node (otherwise **O(n)** to find) |
| Insert/Delete (front) | **O(n)** (shift) | **O(1)** (with head pointer) |
| Insert/Delete (end) | Amortized **O(1)** append (dynamic array), but may resize | **O(1)** with tail pointer; otherwise **O(n)** to reach end |
| Memory overhead | Low | Higher (pointers + allocator overhead) |
| Cache friendliness | **High** | Lower (pointer chasing) |
| Resize | Requires reallocation/copy (dynamic arrays) | Grows node-by-node without moving existing elements |
