#include <vector>
using namespace std;

class Solution {
   public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) sum += nums[i];
        int val = 0;
        int max_val = 0;
        for (int i = 0; i < nums.size(); ++i) val += i * nums[i];
        max_val = val;

        for (int i = nums.size() - 1; i > 0; --i) {
            val = val + sum - nums.size() * nums[i];
            max_val = max(val, max_val);
        }

        return max_val;
    }
};
