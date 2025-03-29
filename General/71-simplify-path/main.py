# 71-simplify-path
class Solution:
    def simplifyPath(self, path: str) -> str:
        stack = list()
        dir_names = path.split("/")

        for name in dir_names:
            if name == "..":
                if len(stack):
                    stack.pop()
            elif name == "" or name == ".":
                continue
            else:
                stack.append(name)

        return "/" + "/".join(stack)
