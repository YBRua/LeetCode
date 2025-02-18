# Shortest Paths

## Breadth-First Search

- $O(|V| + |E|)$

```py
def bfs_for_shortest_path(graph: Graph, start: Node):
    bfs_queue = deque()
    dist = [INF] * graph.n_nodes

    dist[start] = 0
    bfs_queue.push(start)

    while not bfs_queue.empty():
        u = bfs_queue.pop()
        for v in graph.neighbours(u):
            if dist[v] == INF:
                bfs_queue.push(v)
                dist[v] = dist[u] + 1
```

## Dijkstra's Algorithm

- "BFS with dummy nodes and alarm clocks to speed up traversing dummy nodes"
- `dist[v] = min({dist[v], dist[u] + weight[u, v]} for (u, v) in E)`
- Requires a priority queue that uses *the distance from source to current node* as keys
- $O((|V| + |E|)\log(|E|))$ for a binary priority queue implementation

```py
def dijkstra(graph: Graph, src: Node, dst: Node):
    dist = [INF for _ in graph.n_nodes]
    prev = [None for _ in graph.n_nodes]  # for retrieving shortest path

    q = heapq()
    dist[src] = 0
    q.push((src, 0))
    while q.size():
        u = q.pop()
        for v in graph.outgoing_neighbors(u):
            if dist[v] > dist[u] + weight[u, v]:
                dist[v] = dist[u] + weight[u, v]
                prev[v] = u
                q.push((v, dist[v]))
```

## Bellman-Ford Algorithm

- For handling edges with negative weights, or for detecting negative cycles
- Note that in the presence of negative edges, the update is still correct if we update all nodes in a correct order
- So we update all edges for $|V| - 1$ times
- $O(|V|\cdot|E|)$

```py
def bellman_ford(graph: Graph, src: Node, dst: Node):
    dist = [INF for _ in graph.n_nodes]
    prev = [None for _ in graph.n_nodes]

    dist[src] = 0
    for i in range(graph.n_nodes - 1):
        for u, v in graph.edges:
            if dist[v] > dist[u] + weight[u, v]:
                dist[v] = dist[u] + weight[u, v]
                prev[v] = u
```

### Detecting Negative Cycles

- Run one extra iteration after the $|V| - 1$ iterations, if an update still occurs in this extra iteration, then a negative cycle must exist

## Shortest Path in DAGs

- Linearize the DAG (Topological sorting, can directly use DFS for topo-sorting if the graph is ensured to be a DAG)
- Update the distances of each node in the linearized order

## Floyd-Warshall Algorithm

- For computing all pair-wise shortest distances
- Based on dynamic programming
  - Subproblem: `d[i, j, k]` is the shortest paths from `i` to `j` using only nodes `[1, 2, ..., k]`
  - Initialization: `d[i, j, 0]` is the weight of the edge between `i` and `j`, if it exists
  - Note: the `k` dimension can be optimized in the for-loop

```py
def floyd_warshall(graph: Graph):
    dist = [
        [INF for _ in range(graph.n_nodes)]
        for _ in range(graph.n_nodes)]
    for u, v, w in graph.edges:
        dist[u, v] = w
    
    for k in range(grpah.n_nodes):
        for i in range(graph.n_nodes):
            for j in range(graph.n_nodes):
                if dist[i, j] > dist[i, k] + dist[k, j]:
                    dist[i, j] = dist[i, k] + dist[k, j]
```

## Shortest Paths Using At Most k Edges

- Dynamic Programming
  - Subproblem: Let `d[v, k]` be the shortest path from source node to dst node `v` using at most `k` edges
  - Initialization: `d[src, 0] = 0`, all others are INF

```py
def shortest_path_k_edges(grpah: Graph, src: Node, dst: Node, k: int):
    dist = [
        [INF for n in range(graph.n_nodes)]
        for k_ in range(k)
    ]  # |V|, k
    dist[src][0] = 0

    for k_ in range(1, k+1):
        for u, v, w in graph.edges:
            dist[v][k_] = min(dist[v][k_ - 1], dist[v][k_], dist[u][k_ - 1] + w)

    return dist[dst][k_]
```
