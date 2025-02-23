#include <deque>
#include <unordered_set>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    TreeNode* buildTree(deque<int>& preorder, deque<int>& postorder) {
        TreeNode* current = new TreeNode(preorder.front());
        preorder.pop_front();

        if (current->val != postorder.front()) {
            current->left = buildTree(preorder, postorder);
        }
        if (current->val != postorder.front()) {
            current->right = buildTree(preorder, postorder);
        }

        postorder.pop_front();

        return current;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        auto preorder_deque = deque<int>(preorder.begin(), preorder.end());
        auto postorder_deque = deque<int>(postorder.begin(), postorder.end());
        return buildTree(preorder_deque, postorder_deque);
    }
};
