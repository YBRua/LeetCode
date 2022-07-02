# Dynamic Programming Basics

## Longest Increasing Subsequences

```txt
>>> 5, 2, 8, 6, 3, 6, 9, 7
<<< 2, 3, 6, 9
```

- Subproblem
  - `lis[i]`: Length of longest increasing subsequence ending at position `i`
  - Induction: $i = \max_{arr[j] < arr[i]} (lis[j] + 1)$
- $O(n^2)$

```py
def longest_increasing_subseq(arr: List[int]):
    res = [1] * len(arr)
    for i in range(len(arr)):
        for j in range(i):
            if arr[j] < arr[i]:
                res[i] = max(res[i], res[j] + 1)
    
    return max(res)
```

## Longest Common Subsequence (LCS)

Given two sequences `s1`, `s2`, find the longest common subsequence of `s1` and `s2`

- Subproblem
  - `LCS[i,j]`: Length of the LCS between `s1[:i]` and `s2[:j]`
  - Initialization: `LCS[i, 0] = 0`, `LCS[0, j] = 0`

```py
# Updating LCS
LCS[i, j] = LCS[i-1, j-1] + 1 if s1[i] == s2[j] else max(LCS[i-1, j], LCS[i, j-1])
```

## Largest Interval Sum

- Subproblem
  - `sum[i]`: Largest sum of a consequent interval ending at `i`
  - Initialization: `sum[0] = arr[0]`
  - Update: `sum[i] = max(sum[i-1] + arr[i], arr[i])`

## Edit Distance

- Subproblem
  - `E[i, j]`: Edit distance between two prefices `s1[:i+1]` and `s2[:j+1]`
  - `E[i, j] = max(1 + E[i-1, j], 1 + E[i, j-1], diff(i, j) + E[i-1, j-1])`
  - Initialization: `E[i, 0] = i`, `E[0, j] = j`
- $O(mn)$

```py
def edit_distance(
        s1: str, s2: str,
        c_del: int = 1,
        c_ins: int = 1,
        c_rep: int = 1):
    l1, l2 = len(s1), len(s2)
    dists = [[0] * (l2 + 1) for _ in range(len(l1 + 1))]  # l1 + 1, l2 + 1
    
    for i in range(l1 + 1):
        dists[i][0] = i
    for j in range(l2 + 1):
        dists[0][j] = j
    
    for i in range(1, l1 + 1):
        for j in range(1, l2 + 1):
            if s1[i] == s2[j]:
                replace = dists[i-1][j-1]
            else:
                replace = dists[i-1][j-1] + c_rep
            dists[i][j] = max(
                dists[i][j-1] + c_del,
                dists[i-1][j] + c_ins,
                replace
            )

    return dists[l1][l2]
```

## KnapSack

### With Repetition

- Subproblem
  - `K[w]`: Max value available with a knapsack of capacity `w`
  - $K[w] = \max_{i:w_i \le w} (K[w-w_i] + v_i) $
- $O(nW)$ (Note this algorithm is pseudo-polynomial)

```cpp
long long complete_knapsack(
        vector<long long>& weights,
        vector<long long>& values,
        long long capacity) {
    long long n_items = weights.size();
    vector<long long> dp(capacity + 1, 0);

    for (long long i = 0; i <= capacity; ++i) {
        for (long long k = 0; k < n_items; ++k) {
            if (i - weights[k] >= 0) {
                dp[i] = max(dp[i - weights[k]] + values[k], dp[i]);
            }
        }
    }

    return dp[capacity];
}
```

### 0-1 Knapsack

- Subproblem
  - `K[w, j]`: Max value available with a knapsack of capacity `w`, using the first `j` items
  - $K[w, j] = \max(K(w - w_j, j-1) + v_j, K(w, j-1))$
    - Either the $j$-th value is needed to achieve the optimal value, or it is not required

### Multi-Cost 0-1 Knapsack

> A simple extension of the 0-1 Knapsack

- Subproblem
  - `K[i, w, u]`: Max value available using the first `i` items, with capacity1 of `w` and capacity2 of `u`
  - $K[i,w,u] = \max(K[i-1, w,u], K[i-1, w-w_i, u-u_i] + v_i)$
- Space optimization
  - Original space cost would be `n_items * capacity1 * capacity2`
  - Note that as the dimension of cost grows, the memory cost also increases. To save space, it is better to drop the first dimension (the dimension of `i`-th items)
    - The space cost would be `capacity1 * capacity2`
  - This can be achieved because we will only use values from the `i-1`-th pass when computing the values during the `i`-th pass
  - However, since we need the results from `i-1`-th pass when updating, the original values in the `dp` array must not be changed, unless they will never be used
    - Therefore, instead of iterating from `0` to `capacity`, we iterate in the reversed order, from `capacity` to `0`, so that earlier values will not be changed when they are used for updating later values.

```cpp
// Template
int knapsack_2d(vector<int>& cost1, vector<int>& cost2, vector<int>& values,
                int capacity1, int capacity2) {
    int n_items = cost1.size();
    // dp: [c1, c2]
    vector<vector<int>> dp(capacity1 + 1, vector<int>(capacity2 + 1, 0));

    // original dp should be of shape [n_items, c1, c2]
    // but since the update at k-th pass only uses results from (k-1)-th pass
    // the outer n_items dim can be optimized
    //// NOTE: In this case we must update dp in the reversed order
    //// or otherwise we may overwrite values from (k-1)-th iteration
    for (int k = 0; k < n_items; ++k) {
        for (int i = capacity1; i >= cost1[k]; --i) {
            for (int j = capacity2; j >= cost2[k]; --j) {
                dp[i][j] =
                    max(dp[i][j], dp[i - cost1[k]][j - cost2[k]] + values[k]);
            }
        }
    }
    return dp[capacity1][capacity2];
}
```

### Grouped Knapsack

- [洛谷 P1757](https://www.luogu.com.cn/problem/P1757)
- The basic 0-1 knapsack is the case where each item is an individual group

```cpp
// Template
int grouped_knapsack(unordered_map<int, vector<pair<int, int>>> &groups,
                     int capacity) {
    vector<int> dp(capacity + 1, 0);
    for (auto item = groups.begin(); item != groups.end(); ++item) {
        auto g_items = item->second;
        for (int w = capacity; w >= 0; --w) {
            for (int i = 0; i < g_items.size(); ++i) {
                int wi = g_items[i].first;
                int vi = g_items[i].second;
                if (w >= wi) {
                    dp[w] = max(dp[w - wi] + vi, dp[w]);
                }
            }
        }
    }
    return dp[capacity];
}

int main() {
    // group_id -> [weight, value]
    unordered_map<int, vector<pair<int, int>>> groups;
    int capacity;
    int n_items;
    scanf("%d %d", &capacity, &n_items);
    for (int i = 0; i < n_items; ++i) {
        int weight, value, gid;
        scanf("%d %d %d", &weight, &value, &gid);
        groups[gid].push_back(make_pair(weight, value));
    }
    printf("%d\n", grouped_knapsack(groups, capacity));
}
```

## Travelling Salesman Problem

- Subproblem
  - `C[S, j]`: Length of the shortest path visiting each node in `S` exactly once, starting from `1` and ending at `j`
  - $C[S, j] = \max_{i \in S, i \neq j} (C(S - \{j\}, i) + d_{ij})$
  - Initialization: `C[S, j] = INF` for $|S| > 1$, $C(\{1\}, 1) = 0$
- $O(n^2\cdot 2^n)$

```py
def tsp(cities: List[int], dists: List[List[int]]):
    n = len(cities)
    C[{1}, 1] = 0
    for s in range(2, n+1):
        for S in subsets(cities, s):  # subsets of size s
            C[S, 1] = INF
            for j in S:
                if j != 1:
                    C[S, j] = min(
                        C[S-{j}, i] + dists[i][j]
                        for i in S if i != j)
```
