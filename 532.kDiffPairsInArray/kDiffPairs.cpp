#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> res;
        unordered_set<int> seen;
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            res.emplace(nums[i] - k, i);
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (res.count(nums[i]) && res[nums[i]] != i && seen.count(nums[i]) == 0) {
                count ++;
                seen.emplace(nums[i]);
            }
        }
        return count;
    }
};
