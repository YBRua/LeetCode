import heapq
from typing import List


# 373-find-k-pairs-with-smallest-sums
# - nums1 and nums2 are sorted, so the minimum value must be nums1[0] + nums2[0]
# - the second smallest must be one of a[0]+b[1] or a[1]+b[0]
# - so we can push (i, j) into a heapq, and push (i, j+1) and (i+1, j) whenever (i, j) is popped
# - however, this could lead to duplicates since both (1, 0) and (0, 1)
#   would result in (1, 1) being pushed into the queue
# - so we make an additional rule that only push (i, j) when (i, j-1) is popped
class Solution:
    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        len1 = len(nums1)
        len2 = len(nums2)
        ans = []
        # add all (i, 0) into hq or otherwise we would only have (0, 1), (0, 2), ...
        hq = [(nums1[i] + nums2[0], i, 0) for i in range(min(len1, k))]

        while len(ans) < k:
            _, i, j = heapq.heappop(hq)
            ans.append((nums1[i], nums2[j]))
            if j + 1 < len2:
                # push (i, j+1) into q
                heapq.heappush(hq, (nums1[i] + nums2[j + 1], i, j + 1))

        return ans
