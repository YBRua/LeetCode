using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// 101-symmetric-tree
class Solution {
   private:
    bool isSymmetric(TreeNode* left, TreeNode* right) {
        if (left == nullptr || right == nullptr) {
            return left == right;
        }

        bool is_left_symmetric = isSymmetric(left->left, right->right);
        bool is_right_symmetric = isSymmetric(left->right, right->left);

        return is_left_symmetric && is_right_symmetric && left->val == right->val;
    }

   public:
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }

        return isSymmetric(root->left, root->right);
    }
};