import heapq
from collections import defaultdict
from typing import List


class DijkNode:
    def __init__(self, node_id: int, dist: int):
        self.node_id = node_id
        self.dist = dist

    def __lt__(self, other: "DijkNode"):
        return self.dist < other.dist


# 1976-number-of-ways-to-arrive-at-destination
class Solution:
    def countPaths(self, n: int, roads: List[List[int]]) -> int:
        # process edges
        adj_list = defaultdict(list)
        for src, dst, edge_weight in roads:
            adj_list[src].append((dst, edge_weight))
            adj_list[dst].append((src, edge_weight))

        MOD = 10**9 + 7

        dists = [float("inf")] * n
        dists[0] = 0

        path_counts = [0] * n
        path_counts[0] = 1

        dijkq: List[DijkNode] = []
        heapq.heappush(dijkq, DijkNode(0, 0))
        while len(dijkq):
            cur = heapq.heappop(dijkq)

            if cur.dist > dists[cur.node_id]:
                continue

            for nxt_id, edge_weight in adj_list[cur.node_id]:
                if dists[nxt_id] > dists[cur.node_id] + edge_weight:
                    dists[nxt_id] = dists[cur.node_id] + edge_weight
                    path_counts[nxt_id] = path_counts[cur.node_id]
                    heapq.heappush(dijkq, DijkNode(nxt_id, dists[nxt_id]))

                elif dists[nxt_id] == dists[cur.node_id] + edge_weight:
                    path_counts[nxt_id] = (path_counts[cur.node_id] + path_counts[nxt_id]) % MOD

        return path_counts[n - 1]
