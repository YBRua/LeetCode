using System;
using System.Collections.Generic;

namespace Hot100SU2025 {

    public class Solution138 {
        public class Node {
            public int val;
            public Node next;
            public Node random;

            public Node(int _val) {
                val = _val;
                next = null;
                random = null;
            }
        }

        // 138-copy-list-with-random-pointer
        public Dictionary<Node, Node> createdNodes;
        public Node CopyRandomList(Node head) {
            createdNodes = new();
            return CopyRandomListImpl(head);
        }

        public Node CopyRandomListImpl(Node node) {
            if (node == null) {
                return null;
            }

            if (createdNodes.ContainsKey(node)) {
                return createdNodes[node];
            }

            Node newNode = new(node.val);
            createdNodes[node] = newNode;

            newNode.random = CopyRandomListImpl(node.random);
            newNode.next = CopyRandomListImpl(node.next);

            return newNode;
        }
    }
}
