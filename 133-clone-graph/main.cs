// 133-clone-graph

// Definition for a Node.
using System.Collections.Generic;


public class Node {
    public int val;
    public IList<Node> neighbors;

    public Node() {
        val = 0;
        neighbors = new List<Node>();
    }

    public Node(int _val) {
        val = _val;
        neighbors = new List<Node>();
    }

    public Node(int _val, List<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}

public class Solution133 {
    public Node DfsNodeClone(Node oldNode, Dictionary<int, Node> visited) {
        if (oldNode == null) {
            return oldNode;
        }

        if (visited.ContainsKey(oldNode.val)) {
            return visited[oldNode.val];
        }

        Node newNode = new Node(oldNode.val);
        visited.Add(oldNode.val, newNode);

        foreach (var nbr in oldNode.neighbors) {
            newNode.neighbors.Add(DfsNodeClone(nbr, visited));
        }

        return newNode;
    }

    public Node CloneGraph(Node node) {
        return DfsNodeClone(node, new Dictionary<int, Node>());
    }
}
