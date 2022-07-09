from collections import deque
from typing import Optional


# addop -> + | -
# multop -> * | /
# atom -> (expr) | nums
# pow -> atom | atom ^ pow
# mult -> pow | pow multop mult
# expr -> mult | mult addop expr
class TreeNode:
    def __init__(self, left=None, right=None, val: str = None):
        self.left: Optional[TreeNode] = left
        self.right: Optional[TreeNode] = right
        self.val: str = val

    def __str__(self) -> str:
        return self.val


class Calculator:
    def __init__(self):
        self._buffer: str = ""
        self._cursor: int = 0
        self._buffer_len: int = 0
        self._root: TreeNode = None

    def _init_buffer(self, buffer: str):
        self._buffer = buffer
        self._cursor = 0
        self._buffer_len = len(buffer)

    def _match(self, expected: str):
        if self._buffer[self._cursor] != expected:
            raise ValueError(f"Invalid expression at {self._cursor}")
        self._cursor += 1

    def _current(self):
        if self._cursor >= self._buffer_len:
            return ""
        return self._buffer[self._cursor]

    def _step(self) -> str:
        cur = self._buffer[self._cursor]
        self._cursor += 1
        return cur

    def _is_digit(self, ch: str):
        return '0' <= ch and ch <= '9'

    def _read_number(self) -> str:
        str_builder = []
        if self._current() == '-':
            str_builder.append(self._step())
        while self._is_digit(self._current()):
            str_builder.append(self._step())

        return ''.join(str_builder)

    def _parse_atom(self) -> TreeNode:
        temp: TreeNode = None
        if self._cursor >= self._buffer_len:
            return None

        if self._buffer[self._cursor] == '(':
            self._match('(')
            temp = self._parse_expr()
            self._match(')')
        else:
            temp = TreeNode(val=self._read_number())

        return temp

    def _parse_pow(self) -> TreeNode:
        left = self._parse_atom()

        if self._current() == '^':
            self._match('^')
            right = self._parse_pow()
            root = TreeNode(left, right, '^')
        else:
            root = left
        return root

    def _parse_mult(self) -> TreeNode:
        left = self._parse_pow()

        if self._current() == '*' or self._current() == '/':
            multop = self._step()
            right = self._parse_mult()
            root = TreeNode(left, right, multop)
        else:
            root = left
        return root

    def _parse_expr(self) -> TreeNode:
        left = self._parse_mult()

        if self._current() == '+' or self._current() == '-':
            addop = self._step()
            right = self._parse_expr()
            root = TreeNode(left, right, addop)
        else:
            root = left
        return root

    def _eval(self, root: TreeNode):
        if root.left is not None and root.right is not None:
            left = self._eval(root.left)
            right = self._eval(root.right)
            if root.val == "+":
                return left + right
            elif root.val == "-":
                return left - right
            elif root.val == "*":
                return left * right
            elif root.val == "/":
                return left // right
            elif root.val == "^":
                return left ** right
        else:
            return int(root.val)

    def _debug_level_traverse(self):
        q = deque()
        q.append(self._root)
        while len(q):
            node: TreeNode = q.popleft()
            print(node)
            if node is None:
                continue
            q.append(node.left)
            q.append(node.right)

    def eval(self, expr: str):
        self._init_buffer(expr)
        self._root = self._parse_expr()
        return self._eval(self._root)


if __name__ == "__main__":
    expression = "-1*-2+(16/(2+2*3))"
    calc = Calculator().eval(expression)
    res = eval(expression.replace('^', '**').replace('/', '//'))
    if calc != res:
        raise ValueError(f'{calc} != {res}')
    print(f"{calc}, {res}")
