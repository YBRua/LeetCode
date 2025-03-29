from typing import List


# 3169-count-days-without-meetings
class Solution:
    def countDays(self, days: int, meetings: List[List[int]]) -> int:
        meetings.sort(key=lambda x: x[0])
        merged = [meetings[0]]

        for i in range(1, len(meetings)):
            if meetings[i][0] <= merged[-1][1]:
                merged[-1][1] = max(merged[-1][1], meetings[i][1])
            else:
                merged.append(meetings[i])

        n_available_days = days
        for segment in merged:
            n_available_days -= segment[1] - segment[0] + 1

        return n_available_days
