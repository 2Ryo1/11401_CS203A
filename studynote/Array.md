# Array
A collection of elements stored in contiguous memory locations.
- Each element can be accessed directly using an index.
- Array's **size is fixed**. **if the size needs to change, need to recreate array**.
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
```text
//C
// declaration
int array[5];

//initialization
int array[5] = {10, 20, 30, 40, 50};

```
### Dynamic array
- Length **can be changed**.
- The number of elements can be **allocated** or resized at runtime.
- **When using malloc or realloc to increase the array size, most to free the allocated memory, after use to avoid memory leaks**.
```text
//C
int *array;
int n = 10;
// declaration
array = (int *) malloc(n * sizeof(int));

//initialization
for(int i = 0; i < n; i++) {
    array[i] = i + 1;
}

//resize 10 to 20
n = n*2;
array = (int *)realloc(array, n * sizeof(int));
for (int i = n/2; i < n; i++) {
 array[i] = i + 1; 
}

```

## Complexity Analysis
| Operation | Complexity | Notes |
|---|---|---|
| Access | **O(1)** | Direct index lookup |
| Update | **O(1)** | Replace at index |
| Insert | **O(n)** | Requires shifting elements |
| Delete | **O(n)** | Requires shifting elements |
| Traverse | **O(n)** | Visit all elements |
| Search | **O(n)/O(log n)<sin>(1)</sin>** | Linear for unsorted, binary for sorted |

(1): If the array is sorted, we can use Binary Search, which runs in O(log n).
## Sort the Integer
### Bubble Sort
<ins>Bubble Sort is simple and mainly used for teaching, but inefficient for large datasets.</ins>
- Typical Use Cases: Teaching basics, demos on microcontrollers, algorithm animations
```text
procedure bubbleSort(A[1..n]):
  for i from 1 to n-1:
     for j from 1 to n-i:
        if A[j] > A[j+1]:
           swap A[j] and A[j+1]
```

```text
Array[8] =[64,34,25,12,22,11,90,8]
i=1; swap(64,34) → swap(64,25) → swap(64,12) → swap(64,22) → swap(64,11) → swap(64,8)
                     ↓
 ↓        [34,25,12,22,11,64,8,90]
i=2; swap(34,25) → swap(34,12) → swap(34,22) → swap(34,11) → swap(64,8)
                     ↓
 ↓        [25,12,22,11,34,8,64,90]
i=3; swap(25,12) → swap(25,22) → swap(25,11) → swap(34,8)
                     ↓
 ↓        [12,22,11,25,8,34,64,90]
i=4; swap(22,11) → swap(25,8)
                     ↓
 ↓        [12,11,22,8,25,34,64,90]
i=5; swap(12,11) → swap(22,8)
                     ↓
 ↓        [11,12,8,22,25,34,64,90]
i=6; swap(12,8)
           ↓
 ↓        [11,8,12,22,25,34,64,90]
i=7; swap(11,8)
           ↓
          [8,11,12,22,25,34,64,90]
```
### Selection Sort
<ins>Selection Sort minimizes swaps, making it useful when data movement is costly.</ins>
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

```text
Array[8] =[64,34,25,12,22,11,90,8]
i=1; minIndex=1, min(64,34,25,12,22,11,90,8)=8 swap(index1,min) → swap(64,8)
                     ↓
 ↓        [8,34,25,12,22,11,90,64]
i=2; minIndex=2, min(34,25,12,22,11,90,64)=11 swap(index2,min) → swap(34,11)
                     ↓
 ↓        [8,11,25,12,22,34,90,64]
i=3; minIndex=3, min(25,12,22,34,90,64)=12 swap(index3,min) → swap(25,12)
                     ↓
 ↓        [8,11,12,25,22,34,90,64]
i=4; minIndex=4, min(25,22,34,90,64)=22 swap(index4,min) → swap(25,22)
                     ↓
 ↓        [8,11,12,22,25,34,90,64]
i=5; minIndex=5, min(25,34,90,64)=25
                     ↓
 ↓        [8,11,12,22,25,34,90,64]
i=6; minIndex=6, min(34,90,64)=34
           ↓
 ↓        [8,11,12,22,25,34,90,64]
i=7; minIndex=7, min(90,64)=22 swap(index7,min) → swap(90,64)
           ↓
          [8,11,12,22,25,34,64,90]
```
### Insertion Sort
<ins>Insertion Sort is efficient for small or nearly sorted datasets, and often used in practice as a helper algorithm.</ins>
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

```text
Array[8] =[64,34,25,12,22,11,90,8]

i=2; key=34, 64>34,  shift(64) → insert(34)
                     ↓
 ↓        [34,64,25,12,22,11,90,8]
i=3; key=25, [64>25, shift(64)] → [34>25, shift(34)]→ insert 25
                     ↓
 ↓        [25,34,64,12,22,11,90,8]
i=4; key=12, [64>12, shift(64)] → [34>12, shift(34)] → [25>12, shift(25)] → insert(12)
                     ↓
 ↓        [12,25,34,64,22,11,90,8]
i=5; key=22, [64>22, shift(64)] → [34>22, shift(34)] → [25>22, shift(25)] → insert(22)
                     ↓
 ↓        [12,22,25,34,64,11,90,8]
i=6; key=11, [64>11, shift(64)] → [34>11, shift(34)] → [25>11, shift(25)] → [22>11, shift(22)]
     → [12>11, shift(12)] → insert(11)                                                       ↩
                   ↓
 ↓        [11,12,22,25,34,64,90,8]
i=7; key=90, 64<90 → keep
                   ↓
 ↓         [11,12,22,25,34,64,90,8]
i=8; key=8, [90>8, shift(90)] → [64>8, shift(64)] → [34>8, shift(34)] → [25>8, shift(25)]
     → [22>8, shift(22)] → [12>8, shift(12)] →[11>8, shift(11)] → insert(8)             ↩
                      ↓
           [8,11,12,22,25,34,64,90]
```
