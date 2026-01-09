# Array
A collection of elements stored in contiguous memory locations.
Each element can be accessed directly using an index.
Array's **size is fixed**. **if the size needs to change, need to recreate array**.
```text
Array[4] → The Array has four elements
     _______________
    | 2 | 1 | 5 | 3 |
     ￣￣￣￣￣￣￣￣
      ↑   ↑   ↑   ↑ 
index:0,  1,  2,  3
Array[0]=2
```
## Use Case
- Programming Language Foundations
  Example: Python’s list is dynamic, but underneath it relies on arrays that expand when needed.
- Image Processing
  Images are represented as collections of pixels, stored in 2D arrays (matrices).
- Audio and Video Data
  Example: MP3 decoding uses arrays to store and process audio samples.
## Size
### Static array
- Length is **fixed**.
- The number of elements is **determined** at runtime.
### Dynamic array
- Length **can be changed**.
- The number of elements can be **allocated** or resized at runtime.
- **When using malloc or realloc to increase the array size, most to free the allocated memory, after use to avoid memory leaks**.
## Complexity Analysis
| Operation | Complexity | Notes |
|---|---|---|
| Access | **O(1)** | Direct index lookup |
| Update | **O(1)** | Replace at index |
| Insert | **O(n)** | Requires shifting elements |
| Delete | **O(n)** | Requires shifting elements |
| Traverse | **O(n)** | Visit all elements |
| Search | **O(n)/[O(log n)]** | Linear for unsorted, binary for sorted |

[If the array is sorted, we can use Binary Search, which runs in O(log n).]
## Sort the Integer
### Bubble Sort
Bubble Sort is simple and mainly used for teaching, but inefficient for large datasets.
- Typical Use Cases: Teaching basics, demos on microcontrollers, algorithm animations
```text
procedure bubbleSort(A[1..n]):
  for i from 1 to n-1:
     for j from 1 to n-i:
        if A[j] > A[j+1]:
           swap A[j] and A[j+1]
```
### Selection Sort
Selection Sort minimizes swaps, making it useful when data movement is costly.
- Typical Use Cases: Embedded systems with costly writes, small datasets, teaching minimum selection
```text
procedure selectionSort(A[1..n]):
  for i from 1 to n-1:
     minIndex = i
     for j from 1+i to n:
        if A[j] < A[minIndex]:
           minIndex =j
           swap A[j] and A[minIndex]
```
### Insertion Sort
Insertion Sort is efficient for small or nearly sorted datasets, and often used in practice as a helper algorithm.
- Typical Use Cases: Nearly sorted data, incremental updates (e.g. inbox), helper in advanced sorts
```text
procedure insertionSort(A[1..n]):
  for i from 2 to n:
     key= A[i]
     j = i-1
     while j > 0 and A[j] > key:
        A[j+1] = A[j]
        j = j - 1
     A[j+1] = key
```
