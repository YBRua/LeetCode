// 2529-maximum-count-of-positive-integer-and-negative-integer
#include <vector>
using namespace std;

class Solution {
   public:
    int findGreaterEqThan(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int res = nums.size();

        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                // nums[mid] >= target
                res = mid;
                right = mid - 1;
            }
        }

        return res;
    }

    int maximumCount(vector<int>& nums) {
        int n_negs = findGreaterEqThan(nums, 0);
        int n_poss = nums.size() - findGreaterEqThan(nums, 1);

        return max(n_negs, n_poss);
    }
};
