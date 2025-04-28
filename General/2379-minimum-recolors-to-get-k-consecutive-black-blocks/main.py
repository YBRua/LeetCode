# 2379-minimum-recolors-to-get-k-consecutive-black-blocks


class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        min_counts = k
        counts = 0

        for right, tile in enumerate(blocks):
            if tile == "W":
                counts += 1

            if right < k - 1:
                continue

            min_counts = min(min_counts, counts)

            if blocks[right - k] == "W":
                counts -= 1

        return min_counts
