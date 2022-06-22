#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class FindElements {
public:
    TreeNode* root_;
    FindElements(TreeNode* root) {
        root_ = root;
        _recover(root, 0);
    }

    void _recover(TreeNode* node, int val) {
        if (!node) {
            return;
        }
        node->val = val;
        _recover(node->left, 2 * val + 1);
        _recover(node->right, 2 * val + 2);
        return;
    }

    bool _find(TreeNode* node, stack<int>& trace) {
        if (!node) {
            return false;
        }
        if (trace.empty()) {
            return true;
        }
        int next = trace.top(); trace.pop();
        if (next % 2 == 0) {
            return _find(node->right, trace);
        } else {
            return _find(node->left, trace);
        }
    }
    
    bool find(int target) {
        stack<int> path;
        while (target > 0) {
            path.push(target);
            target = (target - 1) / 2;
        }
        return _find(root_, path);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
