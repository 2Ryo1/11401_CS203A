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
| Operation | Complexity | Notes |
|---|---|---|
| Access | **O(1)** | Direct index lookup |
| Update | **O(1)** | Replace at index |
| Insert | **O(n)** | Requires shifting elements |
| Delete | **O(n)** | Requires shifting elements |
| Traverse | **O(n)** | Visit all elements |
| Search | **O(n)[O(log n)]** | Linear for unsorted, binary for sorted |
[If the array is sorted, we can use Binary Search, which runs in O(log n). ]
