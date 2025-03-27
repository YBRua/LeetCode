from typing import List


# 57-insert-interval
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        if len(intervals) == 0:
            return [newInterval]

        res = []
        inserted = False
        i = 0
        cnt = 0
        while cnt <= len(intervals):
            if inserted or (i < len(intervals) and intervals[i][0] < newInterval[0]):
                next_interval = intervals[i]
                i += 1
            else:
                next_interval = newInterval
                inserted = True

            cnt += 1

            if not res:
                res.append(next_interval)
                continue

            if next_interval[0] <= res[-1][1]:
                res[-1][1] = max(res[-1][1], next_interval[1])
            else:
                res.append(next_interval)

        return res
