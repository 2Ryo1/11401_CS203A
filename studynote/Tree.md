# Tree
Tree is <ins>a non-linear hierarchical data structure consisting of nodes connected by edges.</ins>
- Each node can have zero or more child nodes, forming parent-child relationships.
- Trees have no cycles and are commonly used for representing hierarchical relationships like file
systems or organizational structures.
## Terminology
<img width="774" height="201" alt="image" src="https://github.com/user-attachments/assets/6449f08c-fe5c-4d77-b4e8-21e7c8efaa44" />
<img width="808" height="214" alt="image" src="https://github.com/user-attachments/assets/b178fc94-7593-4d84-ad95-bd85a8c2b26e" />

image: images of (https://github.com/yfhuang) data strctuure PDF

| Term | Definition |
|---|---|
| **Root** | The topmost node of the tree |
| **Parent / Child** | A node that has branches leading to other nodes |
| **Leaf** | A node with no children |
| **Sibling** | Nodes that share the same parent |
| **Edge** | A connection between two nodes |
| **Depth / Height** | Depth = distance from root; Height = longest path to leaf |
| **Fan-out (Degree)** | The number of children a node can have |

## Tree Family
### Tree
-  General hierarchical structure
-  No fixed number of children
### Binary Tree
- Specification of tree
- Invariants: each node has at most two children (left, right) (shape rule)
- Input integers: 52, 18, 82, 7, 69, 36, 95, 3, 11, 23, 27, 41, 60, 64, 78, 31, 45, 56, 73, 89(Binary Tree Visualization: https://treeconverter.com/)
<img width="1760" height="488" alt="image" src="https://github.com/user-attachments/assets/8f576e4a-59b1-4363-a138-5d7f9501923d" />

### Binary Search Tree
- Specification of binary tree
- **Left subtree < root < right subtree (ordering rule), Recursively holds all subtrees**
- Enables efficient search (**O(log n)** when reasonably balanced)
- Find the position: **O(h)**
- Insert the new node: **O(1)**
- Input integers: 52, 18, 82, 7, 69, 36, 95, 3, 11, 23, 27, 41, 60, 64, 78, 31, 45, 56, 73, 89(Visualization: https://treeconverter.com/)
<img width="1470" height="464" alt="image" src="https://github.com/user-attachments/assets/c11df34c-d7b6-4f20-aca4-8141d873689a" />

- **Binary Search Tree: Delete**
When delete a node of Binary Search Tree, replase the node with [max of the left subtree] or [min of the right subtree] from ordering property (left < parent < right)

Example:When delete 18 of  Tree, replase the node with 11 or 23 from ordering property (left < parent < right)
```text
     　            52
      　   ________|____________=
          |
    ――――――18――――――――
    7               36
 ___|___        _____|_____
3       11     23         45
                |__
                  27
                   ↓

     　            52
      　   ________|____________=
          |
    ――――――×―――――――――
    7    ↑     ↖    36
 ___|___ ↑ OR  ↑____|_____
3       11    23         45
               |__
                  27
```

### Balanced BST (AVL / Red-Black)
-  Specialization of BST
-  Extra invariant: height kept close to log n
-  Guarantees predictable performance
-  **AVL**: BST + Height-balanced
-  **Red-Black Tree**: BST + Color-balanced
- Input integers: 52, 18, 82, 7, 69, 36, 95, 3, 11, 23, 27, 41, 60, 64, 78, 31, 45, 56, 73, 89(Visualization: (https://www.cs.usfca.edu/~galles/visualization/AVLtree.html)
<img width="808" height="380" alt="image" src="https://github.com/user-attachments/assets/55d76cd5-da40-4e5b-a0d1-ed2cf15e0cfb" />

## Balanced
A balanced tree ensures that the **height difference between subtrees** is minimized.
If the tree becomes too “deep” on one side (degenerate), search and insertion operations
degrade from **O(log n)** to **O(n)** — as bad as a linked list.

## Tree Traversal
### DFT (Depth-First Traversal)
| Order |Visit Sequence | Description |
|---|---|---|
| **Preorder (Root–Left–Right)** | Root first, then children | Used for copying trees |
| **Inorder (Left–Root–Right)** | Sorted order for BST | Used in binary search tree |
| **Postorder (Left–Right–Root)** | Children first, root last | Used for deletion or freeing memory |

<img width="502" height="400" alt="image" src="https://github.com/user-attachments/assets/cb6ce0ca-0db9-4f3f-9f20-6420814d1ebd" />

imge URL: https://www.linkedin.com/pulse/binary-trees-representation-traversals-implementation-riya-pandey-1kgff/

### BFT (Breadth-First Traversal)
Level-Order Traversal, visiting nodes level by level using a queue
<img width="1111" height="588" alt="image" src="https://github.com/user-attachments/assets/90ca8d80-3d08-4357-936c-a9900e8e63ee" />
image URL: https://www.guru99.com/breadth-first-search-bfs-graph-example.html

