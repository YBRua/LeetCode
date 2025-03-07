// 199-binary-tree-right-side-view
#include <queue>
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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }

        vector<int> res;

        queue<TreeNode*> q;
        q.push(root);

        while (q.size()) {
            int level_size = q.size();

            for (int i = 0; i < level_size; ++i) {
                TreeNode* curr = q.front();
                q.pop();

                if (i == level_size - 1) {
                    res.push_back(curr->val);
                }

                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
            }
        }

        return res;
    }
};