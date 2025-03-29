# 20-valid-parentheses
class Solution:
    def isValid(self, s: str) -> bool:
        stack = list()
        matcher = {"(": ")", "{": "}", "[": "]"}

        for ch in s:
            if ch in matcher:
                stack.append(ch)
            else:
                if len(stack) == 0 or matcher[stack[-1]] != ch:
                    return False
                stack.pop()

        if len(stack):
            return False

        return True
