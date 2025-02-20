#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    void permuteRunner(vector<vector<int>>& res,
                       const vector<int>& nums,
                       vector<int>& current,
                       unordered_set<int>& used) {
        if (current.size() == nums.size()) {
            res.emplace_back(vector<int>{current.begin(), current.end()});
            return;
        }
        for (int num : nums) {
            if (used.count(num)) {
                continue;
            }

            used.insert(num);
            current.push_back(num);
            permuteRunner(res, nums, current, used);
            current.pop_back();
            used.erase(num);
        }
        return;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> current;
        unordered_set<int> used;

        permuteRunner(res, nums, current, used);

        return res;
    }
};
