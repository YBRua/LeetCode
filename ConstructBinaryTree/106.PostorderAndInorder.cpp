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
    TreeNode* _build_subtree(vector<int>& postorder, vector<int>& inorder, int left, int right) {
        if (left > right) return nullptr;
        int current_val = postorder[_current_root_idx--];
        int pivot = _node2inidx[current_val];
        TreeNode* node = new TreeNode(current_val);
        node->right = _build_subtree(postorder, inorder, pivot + 1, right);
        node->left = _build_subtree(postorder, inorder, left, pivot - 1);

        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); ++i) _node2inidx[inorder[i]] = i;
        _current_root_idx = postorder.size() - 1;
        return _build_subtree(postorder, inorder, 0, postorder.size() - 1);
    }
};
