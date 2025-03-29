# 155-min-stack
class MinStack:

    def __init__(self):
        self.stack = list()
        self.min_stack = list()

    def push(self, val: int) -> None:
        self.stack.append(val)

        if len(self.min_stack) == 0 or val <= self.min_stack[-1]:
            self.min_stack.append(val)

    def pop(self) -> None:
        if len(self.stack) == 0:
            raise Exception("Empty stack")

        val = self.stack.pop()
        if len(self.min_stack) and val == self.min_stack[-1]:
            self.min_stack.pop()

    def top(self) -> int:
        if len(self.stack) == 0:
            raise Exception("Empty stack")

        return self.stack[-1]

    def getMin(self) -> int:
        if len(self.min_stack) == 0:
            raise Exception("Empty stack")

        return self.min_stack[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
