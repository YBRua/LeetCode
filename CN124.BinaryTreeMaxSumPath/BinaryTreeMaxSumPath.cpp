#include <climits>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    int max_sum = INT_MIN; // max weight of all paths

    int _max_subtree_path(TreeNode *node) {
        // computes max weight of paths starting from subroot node
        if (!node) return 0;
        int left = _max_subtree_path(node->left);
        int right = _max_subtree_path(node->right);
        // only choose paths of subtrees if their weights are positive
        left = max(left, 0);
        right = max(right, 0);
        int max_path_sum = left + right + node->val;
        int max_subtree_path = max(left, right) + node->val;
        max_sum = max(max_sum, max_path_sum);

        return max_subtree_path;
    }
    
    int maxPathSum(TreeNode *root) {
        _max_subtree_path(root);
        return this->max_sum;
    }
};
