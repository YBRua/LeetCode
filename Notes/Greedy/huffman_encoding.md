# Huffman Encoding

- Find the two symbols `i`, `j` with the smallest frequencies, make `i` and `j` children of a new node `k`, which has frequency `f[k] = f[i] + f[j]`
- $O(n\log n)$

```py
def huffman_encoding(freq: List):
    h = heapq()
    n = len(freq)
    for i in range(n):
        h.push((i, freq[i]))  # use freq[i] as keys
    for k in range(n, 2 * n):
        i = h.pop(), j = h.pop()
        f[k] = f[i] + f[j]
        parent[i] = parent[j] = k
        h.push((k, freq[k]))
```
