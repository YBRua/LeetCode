#include <iostream>
#include <vector>

using namespace std;

// 3191-minimum-operations-to-make-binary-array-elements-equal-to-one-i
class Solution {
   public:
    int minOperations(vector<int>& nums) {
        int num_ops = 0;
        // if the first element is 0, the only way to change it is to change the first three elements
        // the same applies to the remaining elements
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (nums[i] == 0) {
                nums[i] = 1 - nums[i];
                nums[i + 1] = 1 - nums[i + 1];
                nums[i + 2] = 1 - nums[i + 2];
                num_ops += 1;
            }
        }

        for (int i = nums.size() - 3; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                return -1;
            }
        }

        return num_ops;
    }
};