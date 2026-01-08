# Graph
A collection of vertices (nodes) connected by edges that can represent relationships between
entities. Unlike trees, graphs can have cycles and edges can be directed or undirected.

Graphs are used to model networks like social connections, transportation systems, or web
pages with hyperlinks.

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
    ➁――――――――➂
      \  |  /
         ➃
Directed graph (digraph)
        ➀
     ↙   |   ↖
    ➁―――――――→➂
      ↘  ↓  ↗
         ➃
```
## Classification
| Type | Description | Example |
|---|---|---|
| Undirected Graph | Edges have no direction | Friendship network |
| Directed Graph (Digraph) | Edges have direction | Instagram “following” |
| Weighted Graph | Each edge has a cost | Google Maps distance |
| Unweighted Graph | All edges equal | Board game map |
| Cyclic Graph | Has loops | City ring road |
| Acyclic Graph | No loops | Family tree |
| Family tree | Every node reachable | Road network |
| Disconnected Graph | Some nodes isolated | Islands without bridge |

## Adjacency Matrix
A **V × V** matrix that records whether an edge exists between two vertices.
### Pros
- O(1) edge lookup → matrix[u][v] is immediate
- Simple implementation → easy to code, easy to visualize
- Works well for dense graphs (many edges)
- Good for algorithms requiring fast access, e.g., Floyd–Warshall
- Natural fit for storing weights in weighted graphs
### Cons
- O(V²) space, even if there are very few edges
- Wasteful for sparse graphs (most real-world graphs)
- Getting neighbors requires scanning the whole row → O(V)
- Harder to dynamically insert/remove vertices
```text
Directed graph (digraph)
        ➀
         ↑   ↘
    ➁―――――――→➂
      ↘  |  ↙
         ➃
```

| \ | 0 | 1 | 2 | 3 |
|---|---|---|---|---|
|0| 0 | 0 | 1 | 0 |
|1| 0 | 0 | 1 | 1 |
|2| 0 | 0 | 0 | 1 |
|3| 1 | 0 | 0 | 0 |

