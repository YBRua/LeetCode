from typing import Dict, Optional


class DListNode:
    prev: "DListNode"
    next: "DListNode"

    def __init__(
        self,
        key: int,
        val: int,
        prev: Optional["DListNode"] = None,
        next: Optional["DListNode"] = None,
    ):
        self.key = key
        self.val = val
        self.prev = prev
        self.next = next


# 146-lru-cache
class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.size = 0

        self.actives: Dict[int, DListNode] = dict()

        self.head = DListNode(-1, -1)
        self.tail = DListNode(-1, -1)
        self.head.next = self.tail
        self.tail.prev = self.head

    def _remove_from_dlist(self, node: DListNode) -> DListNode:
        if node == self.head or node == self.tail:
            raise ValueError("cannot remove head or tail holders")

        prev = node.prev
        next = node.next
        node.prev.next = next
        node.next.prev = prev

        return node

    def _remove_dlist_front(self) -> DListNode:
        if self.size == 0:
            raise RuntimeError("cannot remove from empty DList")
        return self._remove_from_dlist(self.head.next)

    def _append_dlist_back(self, node: DListNode) -> DListNode:
        old_prev = self.tail.prev
        old_prev.next = node
        node.prev = old_prev
        node.next = self.tail
        self.tail.prev = node

        return node

    def _add_actives(self, key: int, node: DListNode):
        self.actives[key] = node

    def _remove_actives(self, key: int):
        self.actives.pop(key)

    def get(self, key: int) -> int:
        if key in self.actives:
            node = self.actives[key]
            self._remove_from_dlist(node)
            self._append_dlist_back(node)

            return node.val

        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.actives:
            node = self.actives[key]
            node.val = value
            self._remove_from_dlist(node)
            self._append_dlist_back(node)

        else:
            node = DListNode(key, value)
            self._append_dlist_back(node)
            self._add_actives(key, node)

            self.size += 1
            if self.size > self.capacity:
                front = self._remove_dlist_front()
                self._remove_actives(front.key)
                self.size -= 1
