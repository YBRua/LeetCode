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
    TreeNode* buildTree(deque<int>& preorder, deque<int>& postorder, unordered_set<int>& visited) {
        if (!preorder.size()) {
            return nullptr;
        }

        int current_val = preorder.front();
        if (visited.count(postorder.front()) && current_val != postorder.front()) {
            return nullptr;
        }
        visited.insert(current_val);

        TreeNode* current = new TreeNode(current_val);
        if (current_val == postorder.front()) {
            preorder.pop_front();
            postorder.pop_front();
            return current;
        }

        preorder.pop_front();
        current->left = buildTree(preorder, postorder, visited);
        current->right = buildTree(preorder, postorder, visited);
        postorder.pop_front();

        return current;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        auto preorder_deque = deque<int>(preorder.begin(), preorder.end());
        auto postorder_deque = deque<int>(postorder.begin(), postorder.end());
        unordered_set<int> visited;
        return buildTree(preorder_deque, postorder_deque, visited);
    }
};