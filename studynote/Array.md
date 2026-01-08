### Array
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
```
## Size
# Static array
- Length is fixed.
- The number of elements is determined at compile time.
# Dynamic array
- Length can be changed.
- The number of elements can be allocated or resized at runtime.
- When using malloc or realloc to increase the array size, most to free the allocated memory, after use to avoid memory leaks.
