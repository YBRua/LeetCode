# Minimum Spanning Trees

## Kruskal's Algorithm

- Iteratively add the next lightest edge that does not produce a cycle
- Requires a sorting algorithm and a [disjoint set](./../DataStructures/disjoint_sets.md)

```py
def mst_kruskal(edges: List[Edge], nodes: List[Node]):
    mst = set()
    for node in nodes:
        makeset(node)
    
    for src, dst in sorted(edges):  # in increasing order
        if find(src) != find(dst):
            mst.add((src, dst))
            union(src, dst)

    return mst
```

## Prim's Algorithm

- The intermediate set of edges always forms a subtree
- Somewhat similary to Dijkskra's shortest path algorithm

```py
def mst_prim(edges: List[Edge], nodes: List[Node]):
    for node in nodes:
        cost[node] = INF
        prev[node] = None
    init_node = nodes[0]  # pick any initial node
    cost[init_node] = 0

    hq = heapify(nodes)  # build priority queue by cost-values
    while not hq.empty():
        v = hq.pop()
        for (v, z) in edges:
            if cost[z] > w[v, z]:
                cost[z] = w[v, z]
                prev[z] = v
                decrease_key(hq, v)

    return prev
```
