#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

class Node {
   public:
    unordered_map<string, Node*> nexts;
    string terminal = "";
    Node(string terminal = "") { this->terminal = terminal; }
};

class Solution {
   public:
    vector<string> _tokenize(string path) {
        vector<string> res;
        path = path.substr(1);
        int start = 0, end = path.find('/');
        while (end != -1) {
            res.push_back(path.substr(start, end - start));
            path = path.substr(end + 1);
            end = path.find('/');
        }
        res.push_back(path);

        return res;
    }

    void _add_trie_nodes(Node* root, const vector<string>& nodes, string terminal) {
        Node* current = root;
        for (int i = 0; i < nodes.size(); ++i) {
            if (!current->nexts.count(nodes[i])) {
                current->nexts[nodes[i]] = new Node();
            }
            current = current->nexts[nodes[i]];
        }
        current->terminal = terminal;

        return;
    }

    void _trie_bfs(vector<string>& res, Node* root) {
        queue<Node*> q;
        q.push(root);
        while (q.size()) {
            Node* current = q.front();
            q.pop();
            if (!current->terminal.empty()) {
                res.push_back(current->terminal);
                continue;
            }
            for (auto entry = current->nexts.begin(); entry != current->nexts.end(); ++entry) {
                q.push(entry->second);
            }
        }
    }

    vector<string> removeSubfolders(vector<string>& folder) {
        Node* root = new Node();
        vector<string> res;
        for (int i = 0; i < folder.size(); ++i) {
            vector<string> tokens = _tokenize(folder[i]);

            _add_trie_nodes(root, tokens, folder[i]);
        }
        _trie_bfs(res, root);

        return res;
    }
};

int main() {
    vector<string> inputs = {"/a","/a/b","/c/d","/c/d/e","/c/f"};
    vector<string> res = Solution().removeSubfolders(inputs);

    for (auto& s: res) {
        cout << s << endl;
    }
}
