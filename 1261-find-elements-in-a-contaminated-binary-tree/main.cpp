
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class FindElements {
   public:
    TreeNode* root;
    FindElements(TreeNode* root) {
        sanitizeTree(root, 0);
        this->root = root;
    }

    void sanitizeTree(TreeNode* current, int value) {
        current->val = value;
        if (current->left) {
            sanitizeTree(current->left, 2 * value + 1);
        }
        if (current->right) {
            sanitizeTree(current->right, 2 * value + 2);
        }
    }

    bool _find(TreeNode* current, int target) {
        if (current->val == target) {
            return true;
        }
        return (current->left && _find(current->left, target) || (current->right && _find(current->right, target)));
    }

    bool find(int target) { return _find(root, target); }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */