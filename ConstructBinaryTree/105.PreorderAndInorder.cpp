#include <vector>
#include <unordered_map>
using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int _current_root_idx;
    unordered_map<int, int> _node2inidx;
public:
    TreeNode* _build_subtree(vector<int>& preorder, vector<int>& inorder, int left, int right) {
        if (left > right) return nullptr;
        int current_val = preorder[_current_root_idx++];
        int pivot = _node2inidx[current_val];
        TreeNode* node = new TreeNode(current_val);
        node->left = _build_subtree(preorder, inorder, left, pivot - 1);
        node->right = _build_subtree(preorder, inorder, pivot + 1, right);

        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i) _node2inidx[inorder[i]] = i;
        _current_root_idx = 0;
        return _build_subtree(preorder, inorder, 0, preorder.size() - 1);
    }
};
