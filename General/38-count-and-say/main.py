class Solution:
    # 38-count-and-say
    def countAndSay(self, n: int) -> str:
        cur = "1"
        for _ in range(1, n):
            nxt = ""
            left = 0
            right = 0
            while right < len(cur):

                while right < len(cur) and cur[right] == cur[left]:
                    right += 1

                nxt += str(right - left) + cur[left]
                left = right

            cur = nxt

        return cur
