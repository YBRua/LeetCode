import heapq
from collections import defaultdict
from typing import List


class HqItem:
    def __init__(self, word: str, freq: int):
        self.word = word
        self.freq = freq

    def __lt__(self, other: "HqItem"):
        if self.freq == other.freq:
            return self.word > other.word
        return self.freq < other.freq


class Solution:
    # 692-top-k-frequent-words
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        counter = defaultdict(int)

        for word in words:
            counter[word] += 1

        hq = []
        for word, freq in counter.items():
            heapq.heappush(hq, HqItem(word, freq))
            if len(hq) > k:
                heapq.heappop(hq)

        res = []
        for _ in range(k):
            res.append(heapq.heappop(hq).word)

        res.reverse()
        return res


if __name__ == "__main__":
    words = ["i", "love", "leetcode", "i", "love", "coding"]
    print(Solution().topKFrequent(words, 3))

    tq = []
    for i in range(10):
        heapq.heappush(tq, i)
