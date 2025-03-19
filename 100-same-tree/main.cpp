using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// 100-same-tree
class Solution {
   public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr || q == nullptr) {
            return p == q;
        }

        bool is_left_same = isSameTree(p->left, q->left);
        bool is_right_same = isSameTree(p->right, q->right);

        return is_left_same && is_right_same && p->val == q->val;
    }
};