#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> num_lookup;
        for (int i = 0; i < nums.size(); ++i) num_lookup[nums[i]] = 0;

        int max_len = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (num_lookup[nums[i]] == 0) {
                _dfs(num_lookup, nums[i]);
            }
            max_len = max(max_len, num_lookup[nums[i]]);
        }
        return max_len;
    }

    int _dfs(unordered_map<int, int>& num_lookup, int current) {
        if (!num_lookup.count(current)) {
            return 0;
        } else if (num_lookup[current] == 0) {
            num_lookup[current] = 1 + _dfs(num_lookup, current + 1);
            return num_lookup[current];
        } else {
            return num_lookup[current];
        }
    }
};
