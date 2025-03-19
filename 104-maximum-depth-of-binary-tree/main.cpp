#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// 104-maximum-depth-of-binary-tree
class Solution {
   private:
    int findMaxDepth(TreeNode* current) {
        if (!current) {
            return 0;
        }
        int left_depth = findMaxDepth(current->left);
        int right_depth = findMaxDepth(current->right);

        int max_depth = max(left_depth, right_depth) + 1;
        return max_depth;
    }

   public:
    int maxDepth(TreeNode* root) {
        return findMaxDepth(root);
    }
};