# Graph
A collection of vertices (nodes) connected by edges that can represent relationships between
entities. Unlike trees, **graphs can have cycles and edges can be directed or undirected**.

**Graphs are used to model networks like social connections, transportation systems, or web
pages with hyperlinks**.

**G = (V, E)**
- V: a set of vertices (also called nodes or points)
- E ⊆ { {x, y} ∈ V and x ≠ y}, a set of edges (also called
links or lines), which are unorder pairs of vertices
```text
Node(vertex): 〇        Node (vertex) with label: ➀
                                            2
Edge: ―――――             Edge with weight: ―――――
                                                                   2
Edge with direction: ―――――→　　　Edge with direction and weight: ―――――→
                    e1
Edge with label: ―――――――
```

```text
Connected Graph
　　     ➀
     /   |   \
    ➁―――+――――➂
      \  |  /
　　     ➃
Directed graph (digraph)
　　     ➀
     ↙   |   ↖
    ➁―――+―――→➂
      ↘  ↓  ↗
　　     ➃
```
## Classification
| Type | Description | Example |
|---|---|---|
| **Undirected Graph** | Edges have no direction | Friendship network |
| **Directed Graph (Digraph)** | Edges have direction | Instagram “following” |
| **Weighted Graph** | Each edge has a cost | Google Maps distance |
| **Unweighted Graph** | All edges equal | Board game map |
| **Cyclic Graph** | Has loops | City ring road |
| **Acyclic Graph** | No loops | Family tree |
| **Family tree** | Every node reachable | Road network |
| **Disconnected Graph** | Some nodes isolated | Islands without bridge |

## Operations
- **Graph Create():** return an empty graph
- **Graph InsertVertex(graph, v):** return a graph with v inserted. v has no incident edge
- **Graph InsertEdge(graph, v1, v2):** return a graph with new edge between v1 and v2
- **Graph DeleteVertex(graph, v):** return a graph in which v and all edges incident to it are removed
- **Graph DeleteEdge(graph, v1, v2):** return a graph in which the edge (v1, v2) is removed
- **List Adjacent(graph, v):** return a list of all vertices that are adjacent to v

## <ins>Adjacency Matrix</ins>
A **V × V** matrix that records whether an edge exists between two vertices.
### Pros
- **O(1)** edge lookup → **matrix[u][v]** is immediate
- Simple implementation → easy to code, easy to visualize
- Works well for **dense graphs (many edges)**
- Good for algorithms requiring **fast access**, e.g., Floyd–Warshall
- Natural fit for storing weights in weighted graphs
### Cons
- **O(V²)** space, even if there are very few edges
- Wasteful for **sparse graphs (most real-world graphs)**
- Getting neighbors requires scanning the whole row → **O(V)**
- Harder to dynamically insert/remove vertices
```text
Directed graph (digraph)
　　     ➀
         ↑   ↘
    ➁―――+―――→➂
      ↘  |  ↙
　　     ➃
```

| \ | 1 | 2 | 3 | 4 |
|---|---|---|---|---|
|1| 0 | 0 | 1 | 0 |
|2| 0 | 0 | 1 | 1 |
|3| 0 | 0 | 0 | 1 |
|4| 1 | 0 | 0 | 0 |

### <ins>Adjacency List</ins>
A list where each vertex stores only its neighbors.
### Pros
- **O(V + E) space** → excellent for sparse graphs
- Fast traversal: neighbors of a vertex can be accessed in **O(deg(v))**
- Very efficient for **BFS/DFS** → O(V + E)
- Easy to scale to large graphs (millions of nodes)
- Insert/delete edges is **O(1)**
### Cons
- Checking if edge (u, v) exists is **O(deg(u))**
- Slightly more complex implementation (nodes + pointers)
- Memory overhead if using many small linked-list nodes

```text
Directed graph (digraph)
　　     ➀
         ↑   ↘
    ➁―――+―――→➂
      ↘  |  ↙
　　     ➃
     Adjlists   data|link
　　 ______   _______
[0] ⎿    ⏌→⎿2 | 0⏌
[1] ⎿    ⏌→⎿2 | ・⏌→⎿3 | 0⏌
[2] ⎿    ⏌→⎿3 | 0⏌
[3] ⎿    ⏌→⎿0 | 0⏌
```

## Time Complexity
| Feature | Adjacency Matrix | Adjacency Matrix List |
|---|---|---|
| **Edge lookup** | O(1) | O(deg(v)) |
| **Add edge (u, v)** | O(1) | O(1) |
| **Remove edge (u, v)** | O(1) | O(deg(u)) |
| **Space** | O(V²) | O(V+E) |
| **Traversal BFS/DFS** | O(V²) | O(V+E)|
| **Best for** | Dense graphs | Sparse graphs |
| **Neighbor iteration** | O(V) | O(deg(v)) |
| **Implementation** | Simple | Moderate |
| **Dynamic graph** | Hard | Easy |

## Graph:DFS Algorithm
- **Step1.**
  Create an empty **stack** and an empty visited set
- **Step2.**
  Push the starting vertex to the stack
- **Step3.** 
**While the stack is not empty:** {<br>
 Pop a vertex v from the stack<br>
  If v is not visited:{<br>
　　　Mark v as visited and print v<br>
　　　Push all unvisited neighbors of v to the stack}<br>
}

## Graph:BFS Algorithm
- **Step1.**
  Create an empty **queue** and an empty visited set
- **Step2.**
  Enqueue the starting vertex
- **Step3.** 
**While the queue is not empty:** {<br>
 Dequeue a vertex v<br>
 If v is not visited:{<br>
　　Mark v as visited and print v<br>
　　Enqueue all unvisited neighbors of v}<br>
}

This is identical to tree level-order traversal, except:
Graphs may have cycles → must check visited

## Graph vs Tree
-  Graph: general structure, can have cycles, any shape
-  Tree: a connected acyclic graph
**Similar**
- A visited strategy
- A recursive depth-first approach (DFS)
- A queue-based breadth-first approach (BFS)
- Systematic exploration of nodes

| Traversal Type | Tree | Graph |
|---|---|---|
| **DFS** | Preorder, Inorder, Postorder | DFS (general) |
| **BFS** | Level-order | BFS (general) |
| **Basis** | Parent-child | Neighbor adjacency |
| **Need visited[]** | No | Yes |

<ins>Graph traversal = Tree traversal + visited[] to avoid cycles.</ins>

| Property | Tree | Graph |
|---|---|---|
| **Connectivity** | Always connected | May be disconnected |
| **Cycles** | No | Yes |
| **Direction** | Not directed | Directed or undirected |
| **Hierarchy** | Yes(rooted) | No inherent hierarchy |
