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

// 543-diameter-of-binary-tree
class Solution {
   private:
    int _ans;
    // diameter: max depth of left subtree + max depth of right subtree + 1
    int find_diameter(TreeNode* current) {
        if (!current) {
            return 0;
        }
        // left and right tree depth
        int left = find_diameter(current->left);
        int right = find_diameter(current->right);
        int depth = max(left, right) + 1;
        _ans = max(_ans, left + right + 1);

        return depth;
    }

   public:
    int diameterOfBinaryTree(TreeNode* root) {
        _ans = 0;
        find_diameter(root);
        return _ans - 1;
    }
};