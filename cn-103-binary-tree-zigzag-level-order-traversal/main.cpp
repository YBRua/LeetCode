#include <deque>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;

        if (root == nullptr) {
            return res;
        }

        queue<TreeNode*> q;
        q.push(root);

        bool should_reverse = false;
        while (q.size()) {
            vector<int> level_res;
            int size = q.size();

            for (int i = 0; i < size; ++i) {
                auto curr = q.front();
                q.pop();

                level_res.push_back(curr->val);

                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
            }

            if (should_reverse) {
                res.emplace_back(vector<int>{level_res.rbegin(), level_res.rend()});
            } else {
                res.emplace_back(vector<int>{level_res.begin(), level_res.end()});
            }

            should_reverse = !should_reverse;
        }

        return res;
    }
};
