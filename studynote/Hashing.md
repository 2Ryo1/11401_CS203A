# Hash Table
- structure: **Array(used for bucket storage) + Linked list(handles collisions)**
- Each bucket stores a linked list of items with same hash value
## Key
key is the unique identifier used in a hash table to locate a value. 
When provide a key, the hash function transforms it into an index, 
which points to where the corresponding value is stored.
(e.g. when access student's data,use **student's ID number**.)
### Key-Value Pair
<Value1, Value2> → Pair<Key, Value2>
- Value1 provides the source to derive or compute the key.
- Value2 represents the important information (the data we want to retrieve).
## Managing Hash Table
**Static:**
- Static Hashing means the **size of the hash table is fixed** when it is created.
**Dynamic:**
- Dynamic Hashing allows the hash table to **grow or shrink automatically** as the number of records changes.
- The hash function or table structure can **adapt dynamically** to maintain good performance.

| Aspect | Static Hashing | Dynamic Hashing |
|---|---|---|
| **Hash Function** | Constant | Adaptive (changes with size) |
| **Memory Usage** | Predictable | May expand dynamically |
| **Performance** | Degrades with high load | Remains efficient |
| **Rehashing** | Simple | Only local bucket splits |
| **Implementation** | Polynomial rolling hash | Complex (directory or pointer-based) |

## Load Factor (α)
measures how full the table is: **α = number of elements / table size**

## Hashing
A data structure that stores key-value pairs using a hash function to compute an index into an
array of buckets. **It is a mathematical formula that converts a key (data) into a table index**.


**A hash function tells you “where to store” and “where to find” data in the hash table.**
- This allows for average constant-time complexity for insertion, deletion, and lookup operations.
- Hash tables handle collisions through techniques like chaining or open addressing, making them
ideal for fast data retrieval (**average O(1) time**).
### Hash Function
Hash function (mapping function) converts a key into an integer index.
| Method | Formula/Idea | Example |
|---|---|---|
| **Division Method** | h(k) = k mod m | key = 123, m = 10 → index = 3 |
| **Multiplication Method** | h(k) = floor(m * (k*A mod 1)), 0 < A < 1 | A ≈ 0.618 |
| **Folding Method** | Split key into parts and add them | Key = 123456 → 12+34+56 = 102 |
| **String Hashing** | Polynomial rolling hash | h(s) = (Σ s[i] * p^i) mod m |

## Collision
A collision occurs in a hash table <ins>when two or more different keys are mapped by the hash
function to the same index (bucket) in the table</ins>. 

Collision = different keys, same hash address (index).
```text
Example
function: h(k)=key mod 3,
if use keys are 10 and 21.
 h(10)=1,h(21)=1
10 and 21 stores in index 1. This problem is collision
```
### Collision Handling
- **Chaining**:
  Maintain a list of <Value₁, Value₂> pairs under the same index.
  ```text
  h(15) = 3 → bucket[3] → [15]
  h(23) = 3 → bucket[3] → [15 -> 23]
  h(7) = 3 → bucket[3] → [15 -> 23 -> 7]
  ```
- **Open Addressing**:
  Probe another slot (linear, quadratic, or double hashing).Probing is a collision-resolution technique used in open addressing hash tables
  
| Method | Formula | Behavior | Pros / Cons |
|---|---|---|---|
| **Linear Probing** | (h(k) + i) mod m | Check next slot sequentially | Simple / Primary clustering |
| **Quadratic Probing** | (h(k) + c₁·i + c₂·i²) mod m | Gaps grow quadratically | Reduces clustering / May skip slots |
| **Double Hashing** | (h₁(k) + i·h₂(k)) mod m | Uses a 2nd hash for step size | Better spread / More computation |

i = probe sequence index (0, 1, 2, …),m: table size

- **Composite Key**:
  Combine multiple attributes (e.g., Key = f(Value₁, Value₂) or Key = f(Value₁ + timestamp)) to increase uniqueness.
- **Hash Refinement**:
  Redesign f() to use better bit-mixing or modulo a large prime number.
  
## Time Complexity(Chaining)
| Operation | Best | Average (α ≤ 0.7) | worst | Remarks |
|---|---|---|---|---|
| Search | O(1) | O(1+α) | O(n) | Average-case constant if α small |
| Insert | O(1) | O(1) | O(n) | Append to short chain |
| Delete | O(1) | O(1) | O(n) | Search + unlink node |

## Time Complexity(Open Addressing)
| Operation | Average (α ≤ 0.7) | worst | Notes |
|---|---|---|---|
| Search | O(1) | O(n) | At high load factor, probe chain length ↑ |
| Insert | O(1) | O(n) | May require several probes |
| Delete | O(1) | O(n) | Needs careful slot marking (“lazy delete”) |

## Try hashing
https://github.com/2Ryo1/11401_CS203A/blob/main/AssignmentIV/README_s1133352.md
