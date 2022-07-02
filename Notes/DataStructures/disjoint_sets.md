# Disjoint Set

## Basic Ops

- `makeset(x)`: Create a singleton set containing just `x`
- `find(x)`: Find the set to which element `x` belong
- `union(x, y)`: Merge the sets containing `x` and `y`

## Data Structure

- A forest of **directed trees**
  - Node of the trees are elements in the set
  - Each node has parent pointers
  - Root nodes are the representative (or name) for the sets, their parent pointers are self-loops

```py
def makeset(x):
    parent[x] = x
    rank[x] = 0  # for the time being, rank is the height of the subtree hanging from x

def find(x):
    while x != parent[x]:
        x = parent[x]
    return x
```

### Merge by Rank

- A good strategy for merging is to *make the root of the shorter tree point to the root of the taller tree*.
- In this way, only when the two trees are of the same height will the height of the merged tree increase (by 1)

```py
def union(x, y):
    rx, ry = find(x), find(y)
    if rx == ry:
        return
    if rank[rx] > rank[ry]:
        parent[ry] = rx
    else:
        parent[rx] = ry
        if rank[rx] == rank[ry]:
            rank[ry] += 1
```

### Path Compression

- Keep the trees short
- During each `find`, change all the parent pointers along the root to directly point to the root

```py
def find_path_compression(x):
    if parent[x] != x:
        parent[x] = find_path_compression(x)
    return parent[x]
```
